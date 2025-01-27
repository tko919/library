---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Persistent Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/persistentlazysegtree.hpp\"\n\ntemplate <typename\
    \ M, typename N, M (*f)(M, M), M (*g)(M, N), N (*h)(N, N),\n          M (*m1)(),\
    \ N (*n1)(), int LIM = 10101010>\nstruct PersistentLazySegmentTree {\n    struct\
    \ Node {\n        Node *lp, *rp;\n        M data;\n        N lazy;\n        Node()\
    \ {}\n    };\n    using np = Node *;\n    Node buf[LIM];\n    int pos, sz;\n \
    \   np newleaf(M v) {\n        np ret = &buf[pos++];\n        ret->data = v;\n\
    \        ret->lazy = n1();\n        return ret;\n    }\n    np newpar(np lp, np\
    \ rp) {\n        np ret = &buf[pos++];\n        ret->lp = lp;\n        ret->rp\
    \ = rp;\n        ret->data = f(lp->data, rp->data);\n        ret->lazy = n1();\n\
    \        return ret;\n    }\n    np newlazy(np root, N x) {\n        np ret =\
    \ &buf[pos++];\n        ret->lp = root->lp;\n        ret->rp = root->rp;\n   \
    \     ret->lazy = h(root->lazy, x);\n        ret->data = g(root->data, x);\n \
    \       return ret;\n    }\n\n    PersistentLazySegmentTree() {}\n    PersistentLazySegmentTree(int\
    \ sz) : pos(0), sz(sz) {}\n    np run(vector<M> &a) {\n        assert(SZ(a) ==\
    \ sz);\n        auto dfs = [&](auto &dfs, int L, int R) -> np {\n            if\
    \ (R - L == 1) {\n                return newleaf(a[L]);\n            }\n     \
    \       int mid = (L + R) >> 1;\n            auto lp = dfs(dfs, L, mid);\n   \
    \         auto rp = dfs(dfs, mid, R);\n            auto ret = newpar(lp, rp);\n\
    \            return ret;\n        };\n        return dfs(dfs, 0, sz);\n    }\n\
    \    void eval(np root) {\n        if (root->lazy != n1()) {\n            if (root->lp)\
    \ {\n                root->lp = newlazy(root->lp, root->lazy);\n            }\n\
    \            if (root->rp) {\n                root->rp = newlazy(root->rp, root->lazy);\n\
    \            }\n            root->lazy = n1();\n        }\n    }\n    np update(int\
    \ L, int R, N x, np root, int lb = 0, int rb = -1) {\n        if (rb == -1)\n\
    \            rb = sz;\n        if (R <= lb or rb <= L)\n            return root;\n\
    \        if (L <= lb and rb <= R) {\n            np ret = newlazy(root, x);\n\
    \            return ret;\n        }\n        eval(root);\n        int mid = (lb\
    \ + rb) >> 1;\n        np lp = update(L, R, x, root->lp, lb, mid);\n        np\
    \ rp = update(L, R, x, root->rp, mid, rb);\n        np ret = newpar(lp, rp);\n\
    \        return ret;\n    }\n    np copy(int L, int R, np other, np root, int\
    \ lb = 0, int rb = -1) {\n        if (rb == -1)\n            rb = sz;\n      \
    \  if (R <= lb or rb <= L)\n            return root;\n        if (L <= lb and\
    \ rb <= R)\n            return other;\n        eval(root);\n        eval(other);\n\
    \        int mid = (lb + rb) >> 1;\n        np lp = copy(L, R, other->lp, root->lp,\
    \ lb, mid);\n        np rp = copy(L, R, other->rp, root->rp, mid, rb);\n     \
    \   np ret = newpar(lp, rp);\n        return ret;\n    }\n    M query(int L, int\
    \ R, np root, int lb = 0, int rb = -1) {\n        if (rb == -1)\n            rb\
    \ = sz;\n        if (R <= lb or rb <= L)\n            return m1();\n        eval(root);\n\
    \        if (L <= lb and rb <= R)\n            return root->data;\n        int\
    \ mid = (lb + rb) >> 1;\n        M lx = query(L, R, root->lp, lb, mid);\n    \
    \    M rx = query(L, R, root->rp, mid, rb);\n        return f(lx, rx);\n    }\n\
    \    vector<M> dump(np root) {\n        vector<M> ret;\n        auto dfs = [&](auto\
    \ &dfs, np v, int L, int R) -> void {\n            eval(v);\n            int mid\
    \ = (L + R) >> 1;\n            bool leaf = 1;\n            if (v->lp)\n      \
    \          dfs(dfs, v->lp, L, mid), leaf = 0;\n            if (v->rp)\n      \
    \          dfs(dfs, v->rp, mid, R), leaf = 0;\n            if (leaf) {\n     \
    \           ret.push_back(v->data);\n            }\n        };\n        dfs(dfs,\
    \ root, 0, sz);\n        return ret;\n    }\n};\n\n/**\n * @brief Persistent Lazy\
    \ Segment Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename M, typename N, M (*f)(M, M), M (*g)(M,\
    \ N), N (*h)(N, N),\n          M (*m1)(), N (*n1)(), int LIM = 10101010>\nstruct\
    \ PersistentLazySegmentTree {\n    struct Node {\n        Node *lp, *rp;\n   \
    \     M data;\n        N lazy;\n        Node() {}\n    };\n    using np = Node\
    \ *;\n    Node buf[LIM];\n    int pos, sz;\n    np newleaf(M v) {\n        np\
    \ ret = &buf[pos++];\n        ret->data = v;\n        ret->lazy = n1();\n    \
    \    return ret;\n    }\n    np newpar(np lp, np rp) {\n        np ret = &buf[pos++];\n\
    \        ret->lp = lp;\n        ret->rp = rp;\n        ret->data = f(lp->data,\
    \ rp->data);\n        ret->lazy = n1();\n        return ret;\n    }\n    np newlazy(np\
    \ root, N x) {\n        np ret = &buf[pos++];\n        ret->lp = root->lp;\n \
    \       ret->rp = root->rp;\n        ret->lazy = h(root->lazy, x);\n        ret->data\
    \ = g(root->data, x);\n        return ret;\n    }\n\n    PersistentLazySegmentTree()\
    \ {}\n    PersistentLazySegmentTree(int sz) : pos(0), sz(sz) {}\n    np run(vector<M>\
    \ &a) {\n        assert(SZ(a) == sz);\n        auto dfs = [&](auto &dfs, int L,\
    \ int R) -> np {\n            if (R - L == 1) {\n                return newleaf(a[L]);\n\
    \            }\n            int mid = (L + R) >> 1;\n            auto lp = dfs(dfs,\
    \ L, mid);\n            auto rp = dfs(dfs, mid, R);\n            auto ret = newpar(lp,\
    \ rp);\n            return ret;\n        };\n        return dfs(dfs, 0, sz);\n\
    \    }\n    void eval(np root) {\n        if (root->lazy != n1()) {\n        \
    \    if (root->lp) {\n                root->lp = newlazy(root->lp, root->lazy);\n\
    \            }\n            if (root->rp) {\n                root->rp = newlazy(root->rp,\
    \ root->lazy);\n            }\n            root->lazy = n1();\n        }\n   \
    \ }\n    np update(int L, int R, N x, np root, int lb = 0, int rb = -1) {\n  \
    \      if (rb == -1)\n            rb = sz;\n        if (R <= lb or rb <= L)\n\
    \            return root;\n        if (L <= lb and rb <= R) {\n            np\
    \ ret = newlazy(root, x);\n            return ret;\n        }\n        eval(root);\n\
    \        int mid = (lb + rb) >> 1;\n        np lp = update(L, R, x, root->lp,\
    \ lb, mid);\n        np rp = update(L, R, x, root->rp, mid, rb);\n        np ret\
    \ = newpar(lp, rp);\n        return ret;\n    }\n    np copy(int L, int R, np\
    \ other, np root, int lb = 0, int rb = -1) {\n        if (rb == -1)\n        \
    \    rb = sz;\n        if (R <= lb or rb <= L)\n            return root;\n   \
    \     if (L <= lb and rb <= R)\n            return other;\n        eval(root);\n\
    \        eval(other);\n        int mid = (lb + rb) >> 1;\n        np lp = copy(L,\
    \ R, other->lp, root->lp, lb, mid);\n        np rp = copy(L, R, other->rp, root->rp,\
    \ mid, rb);\n        np ret = newpar(lp, rp);\n        return ret;\n    }\n  \
    \  M query(int L, int R, np root, int lb = 0, int rb = -1) {\n        if (rb ==\
    \ -1)\n            rb = sz;\n        if (R <= lb or rb <= L)\n            return\
    \ m1();\n        eval(root);\n        if (L <= lb and rb <= R)\n            return\
    \ root->data;\n        int mid = (lb + rb) >> 1;\n        M lx = query(L, R, root->lp,\
    \ lb, mid);\n        M rx = query(L, R, root->rp, mid, rb);\n        return f(lx,\
    \ rx);\n    }\n    vector<M> dump(np root) {\n        vector<M> ret;\n       \
    \ auto dfs = [&](auto &dfs, np v, int L, int R) -> void {\n            eval(v);\n\
    \            int mid = (L + R) >> 1;\n            bool leaf = 1;\n           \
    \ if (v->lp)\n                dfs(dfs, v->lp, L, mid), leaf = 0;\n           \
    \ if (v->rp)\n                dfs(dfs, v->rp, mid, R), leaf = 0;\n           \
    \ if (leaf) {\n                ret.push_back(v->data);\n            }\n      \
    \  };\n        dfs(dfs, root, 0, sz);\n        return ret;\n    }\n};\n\n/**\n\
    \ * @brief Persistent Lazy Segment Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/persistentlazysegtree.hpp
  requiredBy: []
  timestamp: '2025-01-28 06:32:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/persistentlazysegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/persistentlazysegtree.hpp
- /library/DataStructure/persistentlazysegtree.hpp.html
title: Persistent Lazy Segment Tree
---
