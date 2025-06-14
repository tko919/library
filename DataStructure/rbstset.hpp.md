---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/pointsetrangefreq.hpp
    title: Point Set Range Frequency
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_predecessor_problem.test.cpp
    title: Verify/LC_predecessor_problem.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Randomized Binary Search Tree (set)
    links: []
  bundledCode: "#line 2 \"DataStructure/rbstset.hpp\"\n\r\ntemplate <typename T> class\
    \ RBSTset {\r\n    struct Node {\r\n        Node *lp = nullptr, *rp = nullptr;\r\
    \n        int size = 1;\r\n        T key;\r\n        Node(T _k) : key(_k) {}\r\
    \n        void apply() {\r\n            size = 1;\r\n            if (lp)\r\n \
    \               size += lp->size;\r\n            if (rp)\r\n                size\
    \ += rp->size;\r\n        }\r\n    };\r\n\r\n    Node *root = nullptr;\r\n\r\n\
    \    // subtree \u306E\u30B5\u30A4\u30BA\u53D6\u5F97\r\n    int size(Node *x)\
    \ const {\r\n        return x ? x->size : 0;\r\n    }\r\n\r\n    // \u518D\u5E30\
    \u7684\u306B subtree \u3092 delete \u3059\u308B\r\n    void clear(Node *x) {\r\
    \n        if (!x)\r\n            return;\r\n        clear(x->lp);\r\n        clear(x->rp);\r\
    \n        delete x;\r\n    }\r\n\r\n    // \u30DE\u30FC\u30B8 (\u30E9\u30F3\u30C0\
    \u30E0\u5316\u6728\u306E\u30DE\u30FC\u30B8)\u3002L, R \u306F\u6728\u3067\u3001\
    \u5168\u3066\u306E\u30AD\u30FC(L) < \u5168\u3066\u306E\u30AD\u30FC(R)\r\n    //\
    \ \u3068\u306F\u9650\u3089\u306A\u3044\u304C\r\n    // \u672C\u5B9F\u88C5\u3067\
    \u306F\u300C\u9806\u5E8F\u4ED8\u304D\u96C6\u5408\u300D\u3067\u306A\u304F\u300C\
    \u9806\u5E8F\u4ED8\u304D\u30B7\u30FC\u30B1\u30F3\u30B9\u300D\u7684\u6271\u3044\
    \u306A\u306E\u3067\u3001merge\r\n    // / split \u306F\u30B5\u30A4\u30BA\u30D9\
    \u30FC\u30B9\u3002\r\n    Node *mergeNode(Node *L, Node *R) {\r\n        if (!L)\r\
    \n            return R;\r\n        if (!R)\r\n            return L;\r\n      \
    \  // \u30E9\u30F3\u30C0\u30E0\u9078\u629E: L \u5074\u306E\u6839\u306B\u3059\u308B\
    \u304B R \u5074\u306E\u6839\u306B\u3059\u308B\u304B\r\n        // L \u306E\u8981\
    \u7D20\u6570 + R \u306E\u8981\u7D20\u6570 - 1 \u3092\u4E0A\u9650\u3068\u3057\u3066\
    \u4E71\u629E\u3002\u5143\u5B9F\u88C5\u306B\u5408\u308F\u305B\u308B\u3002\r\n \
    \       unsigned total = size(L) + size(R) - 1;\r\n        if (Random::get(total)\
    \ < (unsigned)size(L)) {\r\n            L->rp = mergeNode(L->rp, R);\r\n     \
    \       L->apply();\r\n            return L;\r\n        } else {\r\n         \
    \   R->lp = mergeNode(L, R->lp);\r\n            R->apply();\r\n            return\
    \ R;\r\n        }\r\n    }\r\n\r\n    // split by size: \u5148\u982D k \u8981\u7D20\
    \u3092 L\u3001\u6B8B\u308A\u3092 R \u306B\u5206\u5272\r\n    std::array<Node *,\
    \ 2> splitNode(Node *x, int k) {\r\n        if (!x)\r\n            return {nullptr,\
    \ nullptr};\r\n        if (k == size(x)) {\r\n            return {x, nullptr};\r\
    \n        }\r\n        if (k <= size(x->lp)) {\r\n            // \u5168\u90E8\u5DE6\
    \u5074\u306B\u884C\u304F\u304B\u3001\u5DE6\u90E8\u5206\u6728\u3067\u5B8C\u7D50\
    \r\n            auto sp = splitNode(x->lp, k);\r\n            Node *L = sp[0],\
    \ *R = x;\r\n            x->lp = sp[1];\r\n            x->apply();\r\n       \
    \     return {L, R};\r\n        } else {\r\n            // \u30EB\u30FC\u30C8\u8981\
    \u7D20\u306F\u5DE6\u5074\u306B\u5165\u308A\u3001\u53F3\u90E8\u5206\u6728\u3082\
    \u5206\u5272\r\n            auto sp = splitNode(x->rp, k - size(x->lp) - 1);\r\
    \n            Node *L = x, *R = sp[1];\r\n            x->rp = sp[0];\r\n     \
    \       x->apply();\r\n            return {L, R};\r\n        }\r\n    }\r\n\r\n\
    \    // key \u672A\u6E80\u306E\u8981\u7D20\u6570 (lower_bound \u306E\u5185\u90E8\
    )\r\n    int lower_boundNode(Node *x, T v) const {\r\n        if (!x)\r\n    \
    \        return 0;\r\n        if (x->key >= v) {\r\n            return lower_boundNode(x->lp,\
    \ v);\r\n        } else {\r\n            return size(x->lp) + 1 + lower_boundNode(x->rp,\
    \ v);\r\n        }\r\n    }\r\n\r\n    // key \u3088\u308A\u5927\u304D\u3044\u8981\
    \u7D20\u6570? \u3067\u306F\u306A\u304F\u3001upper_bound: key <= v\r\n    // \u306E\
    \u500B\u6570\u3092\u8FD4\u3059\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\r\n    int\
    \ upper_boundNode(Node *x, T v) const {\r\n        if (!x)\r\n            return\
    \ 0;\r\n        if (x->key > v) {\r\n            return upper_boundNode(x->lp,\
    \ v);\r\n        } else {\r\n            return size(x->lp) + 1 + upper_boundNode(x->rp,\
    \ v);\r\n        }\r\n    }\r\n\r\n    // \u4E2D\u9593\u8D70\u67FB\u3067\u8981\
    \u7D20\u3092\u5217\u6319\r\n    void _dump(Node *cur, std::vector<T> &a) const\
    \ {\r\n        if (!cur)\r\n            return;\r\n        _dump(cur->lp, a);\r\
    \n        a.push_back(cur->key);\r\n        _dump(cur->rp, a);\r\n    }\r\n\r\n\
    \  public:\r\n    RBSTset() : root(nullptr) {}\r\n    // \u7981\u6B62: \u6D45\u3044\
    \u30B3\u30D4\u30FC\u306B\u3088\u308B\u4E8C\u91CD\u958B\u653E\u3092\u907F\u3051\
    \u308B\r\n    RBSTset(const RBSTset &) = delete;\r\n    RBSTset &operator=(const\
    \ RBSTset &) = delete;\r\n\r\n    // \u30E0\u30FC\u30D6\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\r\n    RBSTset(RBSTset &&other) noexcept : root(other.root)\
    \ {\r\n        other.root = nullptr;\r\n    }\r\n    RBSTset &operator=(RBSTset\
    \ &&other) noexcept {\r\n        if (this != &other) {\r\n            clear(root);\r\
    \n            root = other.root;\r\n            other.root = nullptr;\r\n    \
    \    }\r\n        return *this;\r\n    }\r\n\r\n    ~RBSTset() {\r\n        clear(root);\r\
    \n        root = nullptr;\r\n    }\r\n\r\n    int size() const {\r\n        return\
    \ size(root);\r\n    }\r\n\r\n    // merge: this \u3068 a \u3092\u7D50\u5408\u3002\
    a \u306E\u6240\u6709\u6A29\u3092\u53D7\u3051\u53D6\u308A\u3001a \u306F\u7A7A\u306B\
    \u306A\u308B\u3002\r\n    void merge(RBSTset &a) {\r\n        root = mergeNode(root,\
    \ a.root);\r\n        // a \u306F\u3082\u3046\u30CE\u30FC\u30C9\u3092\u6301\u305F\
    \u306A\u3044\r\n        a.root = nullptr;\r\n    }\r\n\r\n    // split: \u5148\
    \u982D k \u8981\u7D20\u3092 this \u306B\u6B8B\u3057\u3001\u6B8B\u308A\u3092\u65B0\
    \u3057\u3044 RBSTset \u3068\u3057\u3066\u8FD4\u3059\r\n    RBSTset split(int k)\
    \ {\r\n        auto sp = splitNode(root, k);\r\n        root = sp[0];\r\n    \
    \    RBSTset other;\r\n        other.root = sp[1];\r\n        return other;\r\n\
    \    }\r\n\r\n    bool find(T x) const {\r\n        Node *cur = root;\r\n    \
    \    while (cur) {\r\n            if (cur->key == x)\r\n                return\
    \ true;\r\n            else if (x < cur->key)\r\n                cur = cur->lp;\r\
    \n            else\r\n                cur = cur->rp;\r\n        }\r\n        return\
    \ false;\r\n    }\r\n\r\n    void insert(T x) {\r\n        int k = lower_boundNode(root,\
    \ x);\r\n        auto sp = splitNode(root, k);\r\n        Node *newNode = new\
    \ Node(x);\r\n        // merge\u9806: (\u5DE6\u5074) + newNode + (\u53F3\u5074\
    )\r\n        Node *m = mergeNode(sp[0], newNode);\r\n        root = mergeNode(m,\
    \ sp[1]);\r\n    }\r\n\r\n    void erase(T x) {\r\n        // \u5B58\u5728\u524D\
    \u63D0\u306A\u3089 assert \u304B if-check\r\n        assert(find(x));\r\n    \
    \    int k = lower_boundNode(root, x);\r\n        // \u5148\u982D k \u8981\u7D20\
    \u3092 L, \u6B8B\u308A\u3092 t\r\n        auto sp1 = splitNode(root, k);\r\n \
    \       // t \u306E\u5148\u982D 1 \u8981\u7D20\u3092 tmp\uFF08\u524A\u9664\u5BFE\
    \u8C61\u30CE\u30FC\u30C9\uFF09\u3001\u6B8B\u308A\u3092 R\r\n        auto sp2 =\
    \ splitNode(sp1[1], 1);\r\n        Node *tmp = sp2[0]; // isolated node\r\n  \
    \      Node *R = sp2[1];\r\n        // tmp \u306E\u5B50\u306F splitNode \u5185\
    \u3067\u5916\u3055\u308C\u3066\u3001tmp->lp=tmp->rp=nullptr\r\n        // \u306B\
    \u306A\u3063\u3066\u3044\u308B\u306F\u305A\r\n        delete tmp;\r\n        //\
    \ L \u3068 R \u3092\u518D\u7D50\u5408\r\n        root = mergeNode(sp1[0], R);\r\
    \n    }\r\n\r\n    // k-th element: 0-based index\r\n    T kth_element(int k)\
    \ {\r\n        if (k < 0 || k >= size(root)) {\r\n            // \u30A8\u30E9\u30FC\
    \u6307\u793A\u306A\u3089\u4F8B\u5916\u3084\u7279\u5225\u5024\u3002\u3053\u3053\
    \u3067\u306F\u4F8B\u3068\u3057\u3066 T() \u3092\u8FD4\u3059\u304B\r\n        \
    \    // assert\u3002 assert(false && \"kth_element: index out of range\");\r\n\
    \            return T(); // or throw\r\n        }\r\n        // split \u3057\u3066\
    \ k \u756A\u76EE\u3092\u5148\u982D\u306B\u6301\u3063\u3066\u304F\u308B\r\n   \
    \     auto sp = splitNode(root, k);\r\n        Node *R = sp[1];\r\n        Node\
    \ *cur = R;\r\n        // R \u306E\u6700\u5C0F\uFF08\u4E2D\u9593\u8D70\u67FB\u306E\
    \u5148\u982D\uFF09\u3092\u63A2\u3059\r\n        while (cur->lp)\r\n          \
    \  cur = cur->lp;\r\n        T res = cur->key;\r\n        // \u5143\u306B\u623B\
    \u3059\r\n        root = mergeNode(sp[0], sp[1]);\r\n        return res;\r\n \
    \   }\r\n\r\n    int lower_bound(T v) const {\r\n        return lower_boundNode(root,\
    \ v);\r\n    }\r\n    int upper_bound(T v) const {\r\n        return upper_boundNode(root,\
    \ v);\r\n    }\r\n\r\n    std::vector<T> dump() const {\r\n        std::vector<T>\
    \ ret;\r\n        _dump(root, ret);\r\n        return ret;\r\n    }\r\n};\r\n\r\
    \n/**\r\n * @brief Randomized Binary Search Tree (set)\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> class RBSTset {\r\n    struct Node\
    \ {\r\n        Node *lp = nullptr, *rp = nullptr;\r\n        int size = 1;\r\n\
    \        T key;\r\n        Node(T _k) : key(_k) {}\r\n        void apply() {\r\
    \n            size = 1;\r\n            if (lp)\r\n                size += lp->size;\r\
    \n            if (rp)\r\n                size += rp->size;\r\n        }\r\n  \
    \  };\r\n\r\n    Node *root = nullptr;\r\n\r\n    // subtree \u306E\u30B5\u30A4\
    \u30BA\u53D6\u5F97\r\n    int size(Node *x) const {\r\n        return x ? x->size\
    \ : 0;\r\n    }\r\n\r\n    // \u518D\u5E30\u7684\u306B subtree \u3092 delete \u3059\
    \u308B\r\n    void clear(Node *x) {\r\n        if (!x)\r\n            return;\r\
    \n        clear(x->lp);\r\n        clear(x->rp);\r\n        delete x;\r\n    }\r\
    \n\r\n    // \u30DE\u30FC\u30B8 (\u30E9\u30F3\u30C0\u30E0\u5316\u6728\u306E\u30DE\
    \u30FC\u30B8)\u3002L, R \u306F\u6728\u3067\u3001\u5168\u3066\u306E\u30AD\u30FC\
    (L) < \u5168\u3066\u306E\u30AD\u30FC(R)\r\n    // \u3068\u306F\u9650\u3089\u306A\
    \u3044\u304C\r\n    // \u672C\u5B9F\u88C5\u3067\u306F\u300C\u9806\u5E8F\u4ED8\u304D\
    \u96C6\u5408\u300D\u3067\u306A\u304F\u300C\u9806\u5E8F\u4ED8\u304D\u30B7\u30FC\
    \u30B1\u30F3\u30B9\u300D\u7684\u6271\u3044\u306A\u306E\u3067\u3001merge\r\n  \
    \  // / split \u306F\u30B5\u30A4\u30BA\u30D9\u30FC\u30B9\u3002\r\n    Node *mergeNode(Node\
    \ *L, Node *R) {\r\n        if (!L)\r\n            return R;\r\n        if (!R)\r\
    \n            return L;\r\n        // \u30E9\u30F3\u30C0\u30E0\u9078\u629E: L\
    \ \u5074\u306E\u6839\u306B\u3059\u308B\u304B R \u5074\u306E\u6839\u306B\u3059\u308B\
    \u304B\r\n        // L \u306E\u8981\u7D20\u6570 + R \u306E\u8981\u7D20\u6570 -\
    \ 1 \u3092\u4E0A\u9650\u3068\u3057\u3066\u4E71\u629E\u3002\u5143\u5B9F\u88C5\u306B\
    \u5408\u308F\u305B\u308B\u3002\r\n        unsigned total = size(L) + size(R) -\
    \ 1;\r\n        if (Random::get(total) < (unsigned)size(L)) {\r\n            L->rp\
    \ = mergeNode(L->rp, R);\r\n            L->apply();\r\n            return L;\r\
    \n        } else {\r\n            R->lp = mergeNode(L, R->lp);\r\n           \
    \ R->apply();\r\n            return R;\r\n        }\r\n    }\r\n\r\n    // split\
    \ by size: \u5148\u982D k \u8981\u7D20\u3092 L\u3001\u6B8B\u308A\u3092 R \u306B\
    \u5206\u5272\r\n    std::array<Node *, 2> splitNode(Node *x, int k) {\r\n    \
    \    if (!x)\r\n            return {nullptr, nullptr};\r\n        if (k == size(x))\
    \ {\r\n            return {x, nullptr};\r\n        }\r\n        if (k <= size(x->lp))\
    \ {\r\n            // \u5168\u90E8\u5DE6\u5074\u306B\u884C\u304F\u304B\u3001\u5DE6\
    \u90E8\u5206\u6728\u3067\u5B8C\u7D50\r\n            auto sp = splitNode(x->lp,\
    \ k);\r\n            Node *L = sp[0], *R = x;\r\n            x->lp = sp[1];\r\n\
    \            x->apply();\r\n            return {L, R};\r\n        } else {\r\n\
    \            // \u30EB\u30FC\u30C8\u8981\u7D20\u306F\u5DE6\u5074\u306B\u5165\u308A\
    \u3001\u53F3\u90E8\u5206\u6728\u3082\u5206\u5272\r\n            auto sp = splitNode(x->rp,\
    \ k - size(x->lp) - 1);\r\n            Node *L = x, *R = sp[1];\r\n          \
    \  x->rp = sp[0];\r\n            x->apply();\r\n            return {L, R};\r\n\
    \        }\r\n    }\r\n\r\n    // key \u672A\u6E80\u306E\u8981\u7D20\u6570 (lower_bound\
    \ \u306E\u5185\u90E8)\r\n    int lower_boundNode(Node *x, T v) const {\r\n   \
    \     if (!x)\r\n            return 0;\r\n        if (x->key >= v) {\r\n     \
    \       return lower_boundNode(x->lp, v);\r\n        } else {\r\n            return\
    \ size(x->lp) + 1 + lower_boundNode(x->rp, v);\r\n        }\r\n    }\r\n\r\n \
    \   // key \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u6570? \u3067\u306F\u306A\
    \u304F\u3001upper_bound: key <= v\r\n    // \u306E\u500B\u6570\u3092\u8FD4\u3059\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\r\n    int upper_boundNode(Node *x, T v)\
    \ const {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key >\
    \ v) {\r\n            return upper_boundNode(x->lp, v);\r\n        } else {\r\n\
    \            return size(x->lp) + 1 + upper_boundNode(x->rp, v);\r\n        }\r\
    \n    }\r\n\r\n    // \u4E2D\u9593\u8D70\u67FB\u3067\u8981\u7D20\u3092\u5217\u6319\
    \r\n    void _dump(Node *cur, std::vector<T> &a) const {\r\n        if (!cur)\r\
    \n            return;\r\n        _dump(cur->lp, a);\r\n        a.push_back(cur->key);\r\
    \n        _dump(cur->rp, a);\r\n    }\r\n\r\n  public:\r\n    RBSTset() : root(nullptr)\
    \ {}\r\n    // \u7981\u6B62: \u6D45\u3044\u30B3\u30D4\u30FC\u306B\u3088\u308B\u4E8C\
    \u91CD\u958B\u653E\u3092\u907F\u3051\u308B\r\n    RBSTset(const RBSTset &) = delete;\r\
    \n    RBSTset &operator=(const RBSTset &) = delete;\r\n\r\n    // \u30E0\u30FC\
    \u30D6\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n    RBSTset(RBSTset &&other)\
    \ noexcept : root(other.root) {\r\n        other.root = nullptr;\r\n    }\r\n\
    \    RBSTset &operator=(RBSTset &&other) noexcept {\r\n        if (this != &other)\
    \ {\r\n            clear(root);\r\n            root = other.root;\r\n        \
    \    other.root = nullptr;\r\n        }\r\n        return *this;\r\n    }\r\n\r\
    \n    ~RBSTset() {\r\n        clear(root);\r\n        root = nullptr;\r\n    }\r\
    \n\r\n    int size() const {\r\n        return size(root);\r\n    }\r\n\r\n  \
    \  // merge: this \u3068 a \u3092\u7D50\u5408\u3002a \u306E\u6240\u6709\u6A29\u3092\
    \u53D7\u3051\u53D6\u308A\u3001a \u306F\u7A7A\u306B\u306A\u308B\u3002\r\n    void\
    \ merge(RBSTset &a) {\r\n        root = mergeNode(root, a.root);\r\n        //\
    \ a \u306F\u3082\u3046\u30CE\u30FC\u30C9\u3092\u6301\u305F\u306A\u3044\r\n   \
    \     a.root = nullptr;\r\n    }\r\n\r\n    // split: \u5148\u982D k \u8981\u7D20\
    \u3092 this \u306B\u6B8B\u3057\u3001\u6B8B\u308A\u3092\u65B0\u3057\u3044 RBSTset\
    \ \u3068\u3057\u3066\u8FD4\u3059\r\n    RBSTset split(int k) {\r\n        auto\
    \ sp = splitNode(root, k);\r\n        root = sp[0];\r\n        RBSTset other;\r\
    \n        other.root = sp[1];\r\n        return other;\r\n    }\r\n\r\n    bool\
    \ find(T x) const {\r\n        Node *cur = root;\r\n        while (cur) {\r\n\
    \            if (cur->key == x)\r\n                return true;\r\n          \
    \  else if (x < cur->key)\r\n                cur = cur->lp;\r\n            else\r\
    \n                cur = cur->rp;\r\n        }\r\n        return false;\r\n   \
    \ }\r\n\r\n    void insert(T x) {\r\n        int k = lower_boundNode(root, x);\r\
    \n        auto sp = splitNode(root, k);\r\n        Node *newNode = new Node(x);\r\
    \n        // merge\u9806: (\u5DE6\u5074) + newNode + (\u53F3\u5074)\r\n      \
    \  Node *m = mergeNode(sp[0], newNode);\r\n        root = mergeNode(m, sp[1]);\r\
    \n    }\r\n\r\n    void erase(T x) {\r\n        // \u5B58\u5728\u524D\u63D0\u306A\
    \u3089 assert \u304B if-check\r\n        assert(find(x));\r\n        int k = lower_boundNode(root,\
    \ x);\r\n        // \u5148\u982D k \u8981\u7D20\u3092 L, \u6B8B\u308A\u3092 t\r\
    \n        auto sp1 = splitNode(root, k);\r\n        // t \u306E\u5148\u982D 1\
    \ \u8981\u7D20\u3092 tmp\uFF08\u524A\u9664\u5BFE\u8C61\u30CE\u30FC\u30C9\uFF09\
    \u3001\u6B8B\u308A\u3092 R\r\n        auto sp2 = splitNode(sp1[1], 1);\r\n   \
    \     Node *tmp = sp2[0]; // isolated node\r\n        Node *R = sp2[1];\r\n  \
    \      // tmp \u306E\u5B50\u306F splitNode \u5185\u3067\u5916\u3055\u308C\u3066\
    \u3001tmp->lp=tmp->rp=nullptr\r\n        // \u306B\u306A\u3063\u3066\u3044\u308B\
    \u306F\u305A\r\n        delete tmp;\r\n        // L \u3068 R \u3092\u518D\u7D50\
    \u5408\r\n        root = mergeNode(sp1[0], R);\r\n    }\r\n\r\n    // k-th element:\
    \ 0-based index\r\n    T kth_element(int k) {\r\n        if (k < 0 || k >= size(root))\
    \ {\r\n            // \u30A8\u30E9\u30FC\u6307\u793A\u306A\u3089\u4F8B\u5916\u3084\
    \u7279\u5225\u5024\u3002\u3053\u3053\u3067\u306F\u4F8B\u3068\u3057\u3066 T() \u3092\
    \u8FD4\u3059\u304B\r\n            // assert\u3002 assert(false && \"kth_element:\
    \ index out of range\");\r\n            return T(); // or throw\r\n        }\r\
    \n        // split \u3057\u3066 k \u756A\u76EE\u3092\u5148\u982D\u306B\u6301\u3063\
    \u3066\u304F\u308B\r\n        auto sp = splitNode(root, k);\r\n        Node *R\
    \ = sp[1];\r\n        Node *cur = R;\r\n        // R \u306E\u6700\u5C0F\uFF08\u4E2D\
    \u9593\u8D70\u67FB\u306E\u5148\u982D\uFF09\u3092\u63A2\u3059\r\n        while\
    \ (cur->lp)\r\n            cur = cur->lp;\r\n        T res = cur->key;\r\n   \
    \     // \u5143\u306B\u623B\u3059\r\n        root = mergeNode(sp[0], sp[1]);\r\
    \n        return res;\r\n    }\r\n\r\n    int lower_bound(T v) const {\r\n   \
    \     return lower_boundNode(root, v);\r\n    }\r\n    int upper_bound(T v) const\
    \ {\r\n        return upper_boundNode(root, v);\r\n    }\r\n\r\n    std::vector<T>\
    \ dump() const {\r\n        std::vector<T> ret;\r\n        _dump(root, ret);\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
    \ Search Tree (set)\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/rbstset.hpp
  requiredBy:
  - DataStructure/pointsetrangefreq.hpp
  timestamp: '2025-06-14 21:49:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_predecessor_problem.test.cpp
documentation_of: DataStructure/rbstset.hpp
layout: document
redirect_from:
- /library/DataStructure/rbstset.hpp
- /library/DataStructure/rbstset.hpp.html
title: Randomized Binary Search Tree (set)
---
