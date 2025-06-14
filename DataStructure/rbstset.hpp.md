---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/pointsetrangefreq.hpp
    title: Point Set Range Frequency
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_predecessor_problem.test.cpp
    title: Verify/LC_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Randomized Binary Search Tree (set)
    links: []
  bundledCode: "#line 2 \"DataStructure/rbstset.hpp\"\n\r\ntemplate <typename T> class\
    \ RBSTset {\r\n    // \u518D\u5E30\u7684\u306B subtree \u3092 delete \u3059\u308B\
    \r\n    struct Node {\r\n        Node *lp = nullptr, *rp = nullptr;\r\n      \
    \  int size = 1;\r\n        T key;\r\n        Node(T _k = 0) : key(_k) {}\r\n\
    \        void apply() {\r\n            size = 1;\r\n            if (lp)\r\n  \
    \              size += lp->size;\r\n            if (rp)\r\n                size\
    \ += rp->size;\r\n        }\r\n    };\r\n    void clear(Node *x) {\r\n       \
    \ if (!x)\r\n            return;\r\n        clear(x->lp);\r\n        clear(x->rp);\r\
    \n        delete x;\r\n    }\r\n    int size(Node *x) {\r\n        return x ?\
    \ x->size : 0;\r\n    }\r\n    Node *merge(Node *L, Node *R) {\r\n        if (!L)\r\
    \n            return R;\r\n        if (!R)\r\n            return L;\r\n      \
    \  if ((int)Random::get(size(L) + size(R) - 1) < size(L)) {\r\n            L->rp\
    \ = merge(L->rp, R);\r\n            L->apply();\r\n            return L;\r\n \
    \       } else {\r\n            R->lp = merge(L, R->lp);\r\n            R->apply();\r\
    \n            return R;\r\n        }\r\n    }\r\n    array<Node *, 2> split(Node\
    \ *x, int k) {\r\n        if (!x)\r\n            return {nullptr, nullptr};\r\n\
    \        if (k == size(x))\r\n            return {x, nullptr};\r\n        if (k\
    \ <= size(x->lp)) {\r\n            auto [lb, rb] = split(x->lp, k);\r\n      \
    \      Node *L = lb, *R = x;\r\n            x->lp = rb;\r\n            x->apply();\r\
    \n            return {L, R};\r\n        } else {\r\n            auto [lb, rb]\
    \ = split(x->rp, k - size(x->lp) - 1);\r\n            Node *L = x, *R = rb;\r\n\
    \            x->rp = lb;\r\n            x->apply();\r\n            return {L,\
    \ R};\r\n        }\r\n    }\r\n    int lower_bound(Node *x, T v) {\r\n       \
    \ if (!x)\r\n            return 0;\r\n        if (x->key >= v)\r\n           \
    \ return lower_bound(x->lp, v);\r\n        else\r\n            return size(x->lp)\
    \ + 1 + lower_bound(x->rp, v);\r\n    }\r\n    int upper_bound(Node *x, T v) {\r\
    \n        if (!x)\r\n            return 0;\r\n        if (x->key > v)\r\n    \
    \        return upper_bound(x->lp, v);\r\n        else\r\n            return size(x->lp)\
    \ + 1 + upper_bound(x->rp, v);\r\n    }\r\n    void _dump(Node *cur, int depth)\
    \ {\r\n        if (!cur)\r\n            return;\r\n        _dump(cur->lp, depth\
    \ + 1);\r\n        rep(_, 0, depth) cerr << ' ';\r\n        cerr << cur->key <<\
    \ '\\n';\r\n        _dump(cur->rp, depth + 1);\r\n    }\r\n\r\n  public:\r\n \
    \   Node *root;\r\n    RBSTset() : root(nullptr) {}\r\n    RBSTset(const RBSTset\
    \ &) = delete;\r\n    RBSTset &operator=(const RBSTset &) = delete;\r\n\r\n  \
    \  RBSTset(RBSTset &&other) noexcept : root(other.root) {\r\n        other.root\
    \ = nullptr;\r\n    }\r\n    RBSTset &operator=(RBSTset &&other) noexcept {\r\n\
    \        if (this != &other) {\r\n            clear(root);\r\n            root\
    \ = other.root;\r\n            other.root = nullptr;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    ~RBSTset() {\r\n        clear(root);\r\n        root\
    \ = nullptr;\r\n    }\r\n\r\n    int size() {\r\n        return size(root);\r\n\
    \    }\r\n    void merge(RBSTset &a) {\r\n        root = merge(root, a.root);\r\
    \n    }\r\n    RBSTset split(int k) {\r\n        auto [L, R] = split(root, k);\r\
    \n        root = L;\r\n        return RBSTset(R);\r\n    }\r\n    bool find(T\
    \ x) {\r\n        Node *cur = root;\r\n        for (;;) {\r\n            if (!cur)\r\
    \n                break;\r\n            if (cur->key == x)\r\n               \
    \ return true;\r\n            else if (x < cur->key)\r\n                cur =\
    \ cur->lp;\r\n            else\r\n                cur = cur->rp;\r\n        }\r\
    \n        return false;\r\n    }\r\n    void insert(T x, int k = -1) {\r\n   \
    \     if (k == -1)\r\n            k = lower_bound(root, x);\r\n        auto [L,\
    \ R] = split(root, k);\r\n        root = merge(merge(L, new Node(x)), R);\r\n\
    \    }\r\n    void erase(T x) {\r\n        assert(find(x));\r\n        int k =\
    \ lower_bound(root, x);\r\n        auto [L, t] = split(root, k);\r\n        auto\
    \ [tmp, R] = split(t, 1);\r\n        delete tmp;\r\n        root = merge(L, R);\r\
    \n    }\r\n    T kth_element(int k) {\r\n        if (k >= size(root) or k < 0)\r\
    \n            return -1;\r\n        auto [L, R] = split(root, k);\r\n        Node\
    \ *cur = R;\r\n        while (cur->lp)\r\n            cur = cur->lp;\r\n     \
    \   root = merge(L, R);\r\n        return cur->key;\r\n    }\r\n    int lower_bound(T\
    \ v) {\r\n        return lower_bound(root, v);\r\n    }\r\n    int upper_bound(T\
    \ v) {\r\n        return upper_bound(root, v);\r\n    }\r\n    void dump() {\r\
    \n        _dump(root, 1);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
    \ Search Tree (set)\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> class RBSTset {\r\n    // \u518D\
    \u5E30\u7684\u306B subtree \u3092 delete \u3059\u308B\r\n    struct Node {\r\n\
    \        Node *lp = nullptr, *rp = nullptr;\r\n        int size = 1;\r\n     \
    \   T key;\r\n        Node(T _k = 0) : key(_k) {}\r\n        void apply() {\r\n\
    \            size = 1;\r\n            if (lp)\r\n                size += lp->size;\r\
    \n            if (rp)\r\n                size += rp->size;\r\n        }\r\n  \
    \  };\r\n    void clear(Node *x) {\r\n        if (!x)\r\n            return;\r\
    \n        clear(x->lp);\r\n        clear(x->rp);\r\n        delete x;\r\n    }\r\
    \n    int size(Node *x) {\r\n        return x ? x->size : 0;\r\n    }\r\n    Node\
    \ *merge(Node *L, Node *R) {\r\n        if (!L)\r\n            return R;\r\n \
    \       if (!R)\r\n            return L;\r\n        if ((int)Random::get(size(L)\
    \ + size(R) - 1) < size(L)) {\r\n            L->rp = merge(L->rp, R);\r\n    \
    \        L->apply();\r\n            return L;\r\n        } else {\r\n        \
    \    R->lp = merge(L, R->lp);\r\n            R->apply();\r\n            return\
    \ R;\r\n        }\r\n    }\r\n    array<Node *, 2> split(Node *x, int k) {\r\n\
    \        if (!x)\r\n            return {nullptr, nullptr};\r\n        if (k ==\
    \ size(x))\r\n            return {x, nullptr};\r\n        if (k <= size(x->lp))\
    \ {\r\n            auto [lb, rb] = split(x->lp, k);\r\n            Node *L = lb,\
    \ *R = x;\r\n            x->lp = rb;\r\n            x->apply();\r\n          \
    \  return {L, R};\r\n        } else {\r\n            auto [lb, rb] = split(x->rp,\
    \ k - size(x->lp) - 1);\r\n            Node *L = x, *R = rb;\r\n            x->rp\
    \ = lb;\r\n            x->apply();\r\n            return {L, R};\r\n        }\r\
    \n    }\r\n    int lower_bound(Node *x, T v) {\r\n        if (!x)\r\n        \
    \    return 0;\r\n        if (x->key >= v)\r\n            return lower_bound(x->lp,\
    \ v);\r\n        else\r\n            return size(x->lp) + 1 + lower_bound(x->rp,\
    \ v);\r\n    }\r\n    int upper_bound(Node *x, T v) {\r\n        if (!x)\r\n \
    \           return 0;\r\n        if (x->key > v)\r\n            return upper_bound(x->lp,\
    \ v);\r\n        else\r\n            return size(x->lp) + 1 + upper_bound(x->rp,\
    \ v);\r\n    }\r\n    void _dump(Node *cur, int depth) {\r\n        if (!cur)\r\
    \n            return;\r\n        _dump(cur->lp, depth + 1);\r\n        rep(_,\
    \ 0, depth) cerr << ' ';\r\n        cerr << cur->key << '\\n';\r\n        _dump(cur->rp,\
    \ depth + 1);\r\n    }\r\n\r\n  public:\r\n    Node *root;\r\n    RBSTset() :\
    \ root(nullptr) {}\r\n    RBSTset(const RBSTset &) = delete;\r\n    RBSTset &operator=(const\
    \ RBSTset &) = delete;\r\n\r\n    RBSTset(RBSTset &&other) noexcept : root(other.root)\
    \ {\r\n        other.root = nullptr;\r\n    }\r\n    RBSTset &operator=(RBSTset\
    \ &&other) noexcept {\r\n        if (this != &other) {\r\n            clear(root);\r\
    \n            root = other.root;\r\n            other.root = nullptr;\r\n    \
    \    }\r\n        return *this;\r\n    }\r\n\r\n    ~RBSTset() {\r\n        clear(root);\r\
    \n        root = nullptr;\r\n    }\r\n\r\n    int size() {\r\n        return size(root);\r\
    \n    }\r\n    void merge(RBSTset &a) {\r\n        root = merge(root, a.root);\r\
    \n    }\r\n    RBSTset split(int k) {\r\n        auto [L, R] = split(root, k);\r\
    \n        root = L;\r\n        return RBSTset(R);\r\n    }\r\n    bool find(T\
    \ x) {\r\n        Node *cur = root;\r\n        for (;;) {\r\n            if (!cur)\r\
    \n                break;\r\n            if (cur->key == x)\r\n               \
    \ return true;\r\n            else if (x < cur->key)\r\n                cur =\
    \ cur->lp;\r\n            else\r\n                cur = cur->rp;\r\n        }\r\
    \n        return false;\r\n    }\r\n    void insert(T x, int k = -1) {\r\n   \
    \     if (k == -1)\r\n            k = lower_bound(root, x);\r\n        auto [L,\
    \ R] = split(root, k);\r\n        root = merge(merge(L, new Node(x)), R);\r\n\
    \    }\r\n    void erase(T x) {\r\n        assert(find(x));\r\n        int k =\
    \ lower_bound(root, x);\r\n        auto [L, t] = split(root, k);\r\n        auto\
    \ [tmp, R] = split(t, 1);\r\n        delete tmp;\r\n        root = merge(L, R);\r\
    \n    }\r\n    T kth_element(int k) {\r\n        if (k >= size(root) or k < 0)\r\
    \n            return -1;\r\n        auto [L, R] = split(root, k);\r\n        Node\
    \ *cur = R;\r\n        while (cur->lp)\r\n            cur = cur->lp;\r\n     \
    \   root = merge(L, R);\r\n        return cur->key;\r\n    }\r\n    int lower_bound(T\
    \ v) {\r\n        return lower_bound(root, v);\r\n    }\r\n    int upper_bound(T\
    \ v) {\r\n        return upper_bound(root, v);\r\n    }\r\n    void dump() {\r\
    \n        _dump(root, 1);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
    \ Search Tree (set)\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/rbstset.hpp
  requiredBy:
  - DataStructure/pointsetrangefreq.hpp
  timestamp: '2025-06-15 03:24:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_predecessor_problem.test.cpp
documentation_of: DataStructure/rbstset.hpp
layout: document
redirect_from:
- /library/DataStructure/rbstset.hpp
- /library/DataStructure/rbstset.hpp.html
title: Randomized Binary Search Tree (set)
---
