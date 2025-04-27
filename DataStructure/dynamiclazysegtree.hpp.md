---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dynamic Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/dynamiclazysegtree.hpp\"\n\ntemplate <typename\
    \ M, typename N, M (*f)(M, M), M (*g)(M, N), N (*h)(N, N),\n          M (*m1)(int),\
    \ N (*n1)()>\nstruct DynamicLazySegmentTree {\n    struct Node {\n        Node\
    \ *lp, *rp;\n        M val, dat;\n        N lazy;\n        Node(int len = 0)\n\
    \            : val(m1(len)), dat(m1(len)), lazy(n1()), lp(nullptr), rp(nullptr)\
    \ {\n        }\n        Node(M v) : val(v), dat(v), lazy(n1()), lp(nullptr), rp(nullptr)\
    \ {}\n        void upd() {\n            dat = f(lp ? lp->dat : m1(0), rp ? rp->dat\
    \ : m1(0));\n        }\n    };\n    using np = Node *;\n    int n;\n    np root;\n\
    \    DynamicLazySegmentTree() {}\n    DynamicLazySegmentTree(int n) : n(n), root(nullptr)\
    \ {}\n    void set(int i, M x) {\n        set(i, x, root, 0, n);\n    }\n    M\
    \ get(int i) {\n        return get(i, root, 0, n);\n    }\n    void update(int\
    \ L, int R, N x) {\n        update(L, R, x, root, 0, n);\n    }\n    M query(int\
    \ L, int R) {\n        return query(L, R, root, 0, n);\n    }\n\n  private:\n\
    \    void eval(np &node, int a, int b) {\n        assert(node);\n        if (node->lazy\
    \ != n1()) {\n            node->dat = g(node->dat, node->lazy);\n            if\
    \ (b - a != 1) {\n                int mid = (a + b) >> 1;\n                if\
    \ (!node->lp)\n                    node->lp = new Node(mid - a);\n           \
    \     node->lp->lazy = h(node->lp->lazy, node->lazy);\n                if (!node->rp)\n\
    \                    node->rp = new Node(b - mid);\n                node->rp->lazy\
    \ = h(node->rp->lazy, node->lazy);\n            }\n            node->lazy = n1();\n\
    \        }\n    }\n    void set(int i, M x, np &node, int a, int b) {\n      \
    \  if (!node) {\n            node = new Node(x);\n        }\n        if (b - a\
    \ == 1)\n            return;\n        int mid = (a + b) >> 1;\n        if (i <\
    \ mid) {\n            set(i, x, node->lp, a, mid);\n        } else {\n       \
    \     set(i, x, node->rp, mid, b);\n        }\n        node->upd();\n    }\n \
    \   M get(int i, np &node, int a, int b) {\n        if (!node) {\n           \
    \ return m1(1);\n        }\n        if (b - a == 1) {\n            assert(a ==\
    \ i);\n            return node->val;\n        }\n        int mid = (a + b) >>\
    \ 1;\n        if (i < mid) {\n            return get(i, node->lp, a, mid);\n \
    \       } else {\n            return get(i, node->rp, mid, b);\n        }\n  \
    \  }\n    void update(int L, int R, N x, np &node, int a, int b) {\n        if\
    \ (!node) {\n            node = new Node(b - a);\n        }\n        eval(node,\
    \ a, b);\n        if (R <= a or b <= L) {\n            show(a, b, node->dat, '!');\n\
    \            return;\n        }\n        if (L <= a and b <= R) {\n          \
    \  node->lazy = h(node->lazy, x);\n            eval(node, a, b);\n           \
    \ show(a, b, x, node->dat);\n        } else {\n            int mid = (a + b) >>\
    \ 1;\n            update(L, R, x, node->lp, a, mid);\n            update(L, R,\
    \ x, node->rp, mid, b);\n            node->upd();\n            show(a, b, node->dat);\n\
    \        }\n    }\n    M query(int L, int R, np &node, int a, int b) {\n     \
    \   if (!node) {\n            node = new Node(b - a);\n        }\n        if (R\
    \ <= a or b <= L)\n            return m1(0);\n        eval(node, a, b);\n    \
    \    if (L <= a and b <= R) {\n            return node->dat;\n        }\n    \
    \    int mid = (a + b) >> 1;\n        M lb = query(L, R, node->lp, a, mid);\n\
    \        M rb = query(L, R, node->rp, mid, b);\n        show(L, R, a, b, lb, rb);\n\
    \        return f(lb, rb);\n    }\n};\n\n/**\n * @brief Dynamic Lazy Segment Tree\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename M, typename N, M (*f)(M, M), M (*g)(M,\
    \ N), N (*h)(N, N),\n          M (*m1)(int), N (*n1)()>\nstruct DynamicLazySegmentTree\
    \ {\n    struct Node {\n        Node *lp, *rp;\n        M val, dat;\n        N\
    \ lazy;\n        Node(int len = 0)\n            : val(m1(len)), dat(m1(len)),\
    \ lazy(n1()), lp(nullptr), rp(nullptr) {\n        }\n        Node(M v) : val(v),\
    \ dat(v), lazy(n1()), lp(nullptr), rp(nullptr) {}\n        void upd() {\n    \
    \        dat = f(lp ? lp->dat : m1(0), rp ? rp->dat : m1(0));\n        }\n   \
    \ };\n    using np = Node *;\n    int n;\n    np root;\n    DynamicLazySegmentTree()\
    \ {}\n    DynamicLazySegmentTree(int n) : n(n), root(nullptr) {}\n    void set(int\
    \ i, M x) {\n        set(i, x, root, 0, n);\n    }\n    M get(int i) {\n     \
    \   return get(i, root, 0, n);\n    }\n    void update(int L, int R, N x) {\n\
    \        update(L, R, x, root, 0, n);\n    }\n    M query(int L, int R) {\n  \
    \      return query(L, R, root, 0, n);\n    }\n\n  private:\n    void eval(np\
    \ &node, int a, int b) {\n        assert(node);\n        if (node->lazy != n1())\
    \ {\n            node->dat = g(node->dat, node->lazy);\n            if (b - a\
    \ != 1) {\n                int mid = (a + b) >> 1;\n                if (!node->lp)\n\
    \                    node->lp = new Node(mid - a);\n                node->lp->lazy\
    \ = h(node->lp->lazy, node->lazy);\n                if (!node->rp)\n         \
    \           node->rp = new Node(b - mid);\n                node->rp->lazy = h(node->rp->lazy,\
    \ node->lazy);\n            }\n            node->lazy = n1();\n        }\n   \
    \ }\n    void set(int i, M x, np &node, int a, int b) {\n        if (!node) {\n\
    \            node = new Node(x);\n        }\n        if (b - a == 1)\n       \
    \     return;\n        int mid = (a + b) >> 1;\n        if (i < mid) {\n     \
    \       set(i, x, node->lp, a, mid);\n        } else {\n            set(i, x,\
    \ node->rp, mid, b);\n        }\n        node->upd();\n    }\n    M get(int i,\
    \ np &node, int a, int b) {\n        if (!node) {\n            return m1(1);\n\
    \        }\n        if (b - a == 1) {\n            assert(a == i);\n         \
    \   return node->val;\n        }\n        int mid = (a + b) >> 1;\n        if\
    \ (i < mid) {\n            return get(i, node->lp, a, mid);\n        } else {\n\
    \            return get(i, node->rp, mid, b);\n        }\n    }\n    void update(int\
    \ L, int R, N x, np &node, int a, int b) {\n        if (!node) {\n           \
    \ node = new Node(b - a);\n        }\n        eval(node, a, b);\n        if (R\
    \ <= a or b <= L) {\n            show(a, b, node->dat, '!');\n            return;\n\
    \        }\n        if (L <= a and b <= R) {\n            node->lazy = h(node->lazy,\
    \ x);\n            eval(node, a, b);\n            show(a, b, x, node->dat);\n\
    \        } else {\n            int mid = (a + b) >> 1;\n            update(L,\
    \ R, x, node->lp, a, mid);\n            update(L, R, x, node->rp, mid, b);\n \
    \           node->upd();\n            show(a, b, node->dat);\n        }\n    }\n\
    \    M query(int L, int R, np &node, int a, int b) {\n        if (!node) {\n \
    \           node = new Node(b - a);\n        }\n        if (R <= a or b <= L)\n\
    \            return m1(0);\n        eval(node, a, b);\n        if (L <= a and\
    \ b <= R) {\n            return node->dat;\n        }\n        int mid = (a +\
    \ b) >> 1;\n        M lb = query(L, R, node->lp, a, mid);\n        M rb = query(L,\
    \ R, node->rp, mid, b);\n        show(L, R, a, b, lb, rb);\n        return f(lb,\
    \ rb);\n    }\n};\n\n/**\n * @brief Dynamic Lazy Segment Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/dynamiclazysegtree.hpp
  requiredBy: []
  timestamp: '2025-04-27 22:54:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/dynamiclazysegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/dynamiclazysegtree.hpp
- /library/DataStructure/dynamiclazysegtree.hpp.html
title: Dynamic Lazy Segment Tree
---
