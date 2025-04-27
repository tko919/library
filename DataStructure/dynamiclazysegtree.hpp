#pragma once

template <typename M, typename N, M (*f)(M, M), M (*g)(M, N), N (*h)(N, N),
          M (*m1)(int), N (*n1)()>
struct DynamicLazySegmentTree {
    struct Node {
        Node *lp, *rp;
        M val, dat;
        N lazy;
        Node(int len = 0)
            : val(m1(len)), dat(m1(len)), lazy(n1()), lp(nullptr), rp(nullptr) {
        }
        Node(M v) : val(v), dat(v), lazy(n1()), lp(nullptr), rp(nullptr) {}
        void upd() {
            dat = f(lp ? lp->dat : m1(0), rp ? rp->dat : m1(0));
        }
    };
    using np = Node *;
    int n;
    np root;
    DynamicLazySegmentTree() {}
    DynamicLazySegmentTree(int n) : n(n), root(nullptr) {}
    void set(int i, M x) {
        set(i, x, root, 0, n);
    }
    M get(int i) {
        return get(i, root, 0, n);
    }
    void update(int L, int R, N x) {
        update(L, R, x, root, 0, n);
    }
    M query(int L, int R) {
        return query(L, R, root, 0, n);
    }

  private:
    void eval(np &node, int a, int b) {
        assert(node);
        if (node->lazy != n1()) {
            node->dat = g(node->dat, node->lazy);
            if (b - a != 1) {
                int mid = (a + b) >> 1;
                if (!node->lp)
                    node->lp = new Node(mid - a);
                node->lp->lazy = h(node->lp->lazy, node->lazy);
                if (!node->rp)
                    node->rp = new Node(b - mid);
                node->rp->lazy = h(node->rp->lazy, node->lazy);
            }
            node->lazy = n1();
        }
    }
    void set(int i, M x, np &node, int a, int b) {
        if (!node) {
            node = new Node(x);
        }
        if (b - a == 1)
            return;
        int mid = (a + b) >> 1;
        if (i < mid) {
            set(i, x, node->lp, a, mid);
        } else {
            set(i, x, node->rp, mid, b);
        }
        node->upd();
    }
    M get(int i, np &node, int a, int b) {
        if (!node) {
            return m1(1);
        }
        if (b - a == 1) {
            assert(a == i);
            return node->val;
        }
        int mid = (a + b) >> 1;
        if (i < mid) {
            return get(i, node->lp, a, mid);
        } else {
            return get(i, node->rp, mid, b);
        }
    }
    void update(int L, int R, N x, np &node, int a, int b) {
        if (!node) {
            node = new Node(b - a);
        }
        eval(node, a, b);
        if (R <= a or b <= L) {
            show(a, b, node->dat, '!');
            return;
        }
        if (L <= a and b <= R) {
            node->lazy = h(node->lazy, x);
            eval(node, a, b);
            show(a, b, x, node->dat);
        } else {
            int mid = (a + b) >> 1;
            update(L, R, x, node->lp, a, mid);
            update(L, R, x, node->rp, mid, b);
            node->upd();
            show(a, b, node->dat);
        }
    }
    M query(int L, int R, np &node, int a, int b) {
        if (!node) {
            node = new Node(b - a);
        }
        if (R <= a or b <= L)
            return m1(0);
        eval(node, a, b);
        if (L <= a and b <= R) {
            return node->dat;
        }
        int mid = (a + b) >> 1;
        M lb = query(L, R, node->lp, a, mid);
        M rb = query(L, R, node->rp, mid, b);
        show(L, R, a, b, lb, rb);
        return f(lb, rb);
    }
};

/**
 * @brief Dynamic Lazy Segment Tree
 */