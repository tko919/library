#pragma once

template <typename T> class RBSTset {
    struct Node {
        Node *lp = nullptr, *rp = nullptr;
        int size = 1;
        T key;
        Node(T _k) : key(_k) {}
        void apply() {
            size = 1;
            if (lp)
                size += lp->size;
            if (rp)
                size += rp->size;
        }
    };

    Node *root = nullptr;

    // subtree のサイズ取得
    int size(Node *x) const {
        return x ? x->size : 0;
    }

    // 再帰的に subtree を delete する
    void clear(Node *x) {
        if (!x)
            return;
        clear(x->lp);
        clear(x->rp);
        delete x;
    }

    // マージ (ランダム化木のマージ)。L, R は木で、全てのキー(L) < 全てのキー(R)
    // とは限らないが
    // 本実装では「順序付き集合」でなく「順序付きシーケンス」的扱いなので、merge
    // / split はサイズベース。
    Node *mergeNode(Node *L, Node *R) {
        if (!L)
            return R;
        if (!R)
            return L;
        // ランダム選択: L 側の根にするか R 側の根にするか
        // L の要素数 + R の要素数 - 1 を上限として乱択。元実装に合わせる。
        unsigned total = size(L) + size(R) - 1;
        if (Random::get(total) < (unsigned)size(L)) {
            L->rp = mergeNode(L->rp, R);
            L->apply();
            return L;
        } else {
            R->lp = mergeNode(L, R->lp);
            R->apply();
            return R;
        }
    }

    // split by size: 先頭 k 要素を L、残りを R に分割
    std::array<Node *, 2> splitNode(Node *x, int k) {
        if (!x)
            return {nullptr, nullptr};
        if (k == size(x)) {
            return {x, nullptr};
        }
        if (k <= size(x->lp)) {
            // 全部左側に行くか、左部分木で完結
            auto sp = splitNode(x->lp, k);
            Node *L = sp[0], *R = x;
            x->lp = sp[1];
            x->apply();
            return {L, R};
        } else {
            // ルート要素は左側に入り、右部分木も分割
            auto sp = splitNode(x->rp, k - size(x->lp) - 1);
            Node *L = x, *R = sp[1];
            x->rp = sp[0];
            x->apply();
            return {L, R};
        }
    }

    // key 未満の要素数 (lower_bound の内部)
    int lower_boundNode(Node *x, T v) const {
        if (!x)
            return 0;
        if (x->key >= v) {
            return lower_boundNode(x->lp, v);
        } else {
            return size(x->lp) + 1 + lower_boundNode(x->rp, v);
        }
    }

    // key より大きい要素数? ではなく、upper_bound: key <= v
    // の個数を返すインデックス
    int upper_boundNode(Node *x, T v) const {
        if (!x)
            return 0;
        if (x->key > v) {
            return upper_boundNode(x->lp, v);
        } else {
            return size(x->lp) + 1 + upper_boundNode(x->rp, v);
        }
    }

    // 中間走査で要素を列挙
    void _dump(Node *cur, std::vector<T> &a) const {
        if (!cur)
            return;
        _dump(cur->lp, a);
        a.push_back(cur->key);
        _dump(cur->rp, a);
    }

  public:
    RBSTset() : root(nullptr) {}
    // 禁止: 浅いコピーによる二重開放を避ける
    RBSTset(const RBSTset &) = delete;
    RBSTset &operator=(const RBSTset &) = delete;

    // ムーブコンストラクタ
    RBSTset(RBSTset &&other) noexcept : root(other.root) {
        other.root = nullptr;
    }
    RBSTset &operator=(RBSTset &&other) noexcept {
        if (this != &other) {
            clear(root);
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    ~RBSTset() {
        clear(root);
        root = nullptr;
    }

    int size() const {
        return size(root);
    }

    // merge: this と a を結合。a の所有権を受け取り、a は空になる。
    void merge(RBSTset &a) {
        root = mergeNode(root, a.root);
        // a はもうノードを持たない
        a.root = nullptr;
    }

    // split: 先頭 k 要素を this に残し、残りを新しい RBSTset として返す
    RBSTset split(int k) {
        auto sp = splitNode(root, k);
        root = sp[0];
        RBSTset other;
        other.root = sp[1];
        return other;
    }

    bool find(T x) const {
        Node *cur = root;
        while (cur) {
            if (cur->key == x)
                return true;
            else if (x < cur->key)
                cur = cur->lp;
            else
                cur = cur->rp;
        }
        return false;
    }

    void insert(T x) {
        int k = lower_boundNode(root, x);
        auto sp = splitNode(root, k);
        Node *newNode = new Node(x);
        // merge順: (左側) + newNode + (右側)
        Node *m = mergeNode(sp[0], newNode);
        root = mergeNode(m, sp[1]);
    }

    void erase(T x) {
        // 存在前提なら assert か if-check
        assert(find(x));
        int k = lower_boundNode(root, x);
        // 先頭 k 要素を L, 残りを t
        auto sp1 = splitNode(root, k);
        // t の先頭 1 要素を tmp（削除対象ノード）、残りを R
        auto sp2 = splitNode(sp1[1], 1);
        Node *tmp = sp2[0]; // isolated node
        Node *R = sp2[1];
        // tmp の子は splitNode 内で外されて、tmp->lp=tmp->rp=nullptr
        // になっているはず
        delete tmp;
        // L と R を再結合
        root = mergeNode(sp1[0], R);
    }

    // k-th element: 0-based index
    T kth_element(int k) {
        if (k < 0 || k >= size(root)) {
            // エラー指示なら例外や特別値。ここでは例として T() を返すか
            // assert。 assert(false && "kth_element: index out of range");
            return T(); // or throw
        }
        // split して k 番目を先頭に持ってくる
        auto sp = splitNode(root, k);
        Node *R = sp[1];
        Node *cur = R;
        // R の最小（中間走査の先頭）を探す
        while (cur->lp)
            cur = cur->lp;
        T res = cur->key;
        // 元に戻す
        root = mergeNode(sp[0], sp[1]);
        return res;
    }

    int lower_bound(T v) const {
        return lower_boundNode(root, v);
    }
    int upper_bound(T v) const {
        return upper_boundNode(root, v);
    }

    std::vector<T> dump() const {
        std::vector<T> ret;
        _dump(root, ret);
        return ret;
    }
};

/**
 * @brief Randomized Binary Search Tree (set)
 */