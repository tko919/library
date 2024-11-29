---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Static TopTree
    links: []
  bundledCode: "#line 2 \"Graph/statictoptree.hpp\"\n\nstruct StaticTopTree {\n  \
    \  using T = array<int, 4>;\n    vector<vector<int>> g;\n    vector<T> tree; //\
    \ {par,L,R,type 0:rake,1:compress,2:vertex}\n    int n, rt;\n    StaticTopTree()\
    \ {}\n    StaticTopTree(int n) : n(n), g(n), tree(n) {}\n    void add_edge(int\
    \ u, int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\
    \    void run(int base = 0) {\n        dfs(base, -1);\n        rt = build(base).first;\n\
    \    }\n    void dump() {\n        rep(v, 0, SZ(tree)) {\n            auto [par,\
    \ L, R, type] = tree[v];\n            show(v, par, L, R, type);\n        }\n \
    \   }\n\n  private:\n    int dfs(int v, int p) {\n        rep(i, 0, SZ(g[v]))\
    \ if (g[v][i] == p) {\n            g[v].erase(g[v].begin() + i);\n           \
    \ break;\n        }\n        int sz = 1, best = 0;\n        for (auto &to : g[v])\
    \ {\n            int add = dfs(to, v);\n            sz += add;\n            if\
    \ (chmax(best, add))\n                swap(to, g[v].front());\n        }\n   \
    \     return sz;\n    }\n    using P = pair<int, int>; // {ID,size}\n    int make(int\
    \ v, int L, int R, int type) {\n        if (v == -1) {\n            v = SZ(tree);\n\
    \            tree.push_back({-1, L, R, type});\n        } else {\n           \
    \ tree[v] = {-1, L, R, type};\n        }\n        if (L != -1)\n            tree[L][0]\
    \ = v;\n        if (R != -1)\n            tree[R][0] = v;\n        return v;\n\
    \    }\n    P merge(vector<P> a, int type) {\n        if (SZ(a) == 1)\n      \
    \      return a[0];\n        int sum = 0;\n        for (auto &[_, sz] : a)\n \
    \           sum += sz;\n        vector<P> L, R;\n        for (auto &[v, sz] :\
    \ a) {\n            if (sum > sz)\n                L.push_back({v, sz});\n   \
    \         else\n                R.push_back({v, sz});\n            sum -= sz *\
    \ 2;\n        }\n        auto [lb, ls] = merge(L, type);\n        auto [rb, rs]\
    \ = merge(R, type);\n        return P{make(-1, lb, rb, type), ls + rs};\n    }\n\
    \    P build(int v) {\n        int cur = v, pre = -1;\n        vector<P> a;\n\
    \        for (;;) {\n            // rake\n            vector<P> b;\n         \
    \   b.push_back({make(cur, -1, -1, 2), 1});\n            if (pre != -1) {\n  \
    \              assert(g[pre][0] == cur);\n                for (auto &to : g[pre])\n\
    \                    if (to != cur) {\n                        b.push_back(build(to));\n\
    \                    }\n            }\n            a.push_back(merge(b, 0));\n\
    \            if (SZ(g[cur]) == 0)\n                break;\n            pre = cur,\
    \ cur = g[cur][0];\n        }\n        return merge(a, 1);\n    }\n};\n\n/**\n\
    \ * rake: (a<-b], (a<-c] -> (a<-b].\n * compress: (a<-b], (b<-c] -> (a<-c].\n\
    \ */\ntemplate <typename M, M (*rake)(M, M), M (*compress)(M, M)>\nstruct DynamicTreeDP\
    \ {\n    int n, sz;\n    StaticTopTree stt;\n    vector<M> dat;\n    DynamicTreeDP()\
    \ {}\n    template <typename F>\n    DynamicTreeDP(int n, StaticTopTree _stt,\
    \ F vertex)\n        : n(n), sz(SZ(_stt.tree)), stt(_stt), dat(sz) {\n       \
    \ rep(i, 0, n) dat[i] = vertex(i);\n        rep(i, n, sz) update(i);\n    }\n\
    \    void set(int v, M x) {\n        dat[v] = x;\n        for (int p = stt.tree[v][0];\
    \ p != -1; p = stt.tree[p][0])\n            update(p);\n    }\n    M get() {\n\
    \        return dat.back();\n    }\n\n  private:\n    void update(int v) {\n \
    \       auto L = dat[stt.tree[v][1]];\n        auto R = dat[stt.tree[v][2]];\n\
    \        if (stt.tree[v][3]) {\n            dat[v] = compress(L, R);\n       \
    \ } else {\n            dat[v] = rake(L, R);\n        }\n    }\n};\n\n/**\n *\
    \ rake1: (a<-b], (a<-c] -> (a<-b].\n * rake2: (a->b], (a<-c] -> (a->b].\n * compress:\
    \ (a<-b], (b<-c] -> (a<-c].\n */\ntemplate <typename M, M (*rake1)(M, M), M (*rake2)(M,\
    \ M), M (*compress)(M, M),\n          M (*e)()>\nstruct DynamicRerootingDP {\n\
    \    int n, sz;\n    StaticTopTree stt;\n    using P = pair<M, M>;\n    vector<P>\
    \ dat; // {ord,rev}\n    DynamicRerootingDP() {}\n    template <typename F>\n\
    \    DynamicRerootingDP(int n, StaticTopTree _stt, F vertex)\n        : n(n),\
    \ sz(SZ(_stt.tree)), stt(_stt), dat(sz) {\n        dat[0] = {e(), e()};\n    \
    \    rep(i, 1, n) dat[i] = vertex(i);\n        rep(i, n, sz) update(i);\n    }\n\
    \    void set(int v, P x) {\n        dat[v] = x;\n        for (int p = stt.tree[v][0];\
    \ p != -1; p = stt.tree[p][0])\n            update(p);\n    }\n    M get(int v)\
    \ {\n        // a: expose cur to v (down)\n        // b: expose from cur (down)\n\
    \        // c: expose to cur (up)\n        int cur = v;\n        M a = dat[cur].second,\
    \ b = e(), c = e();\n        for (;;) {\n            int p = stt.tree[cur][0];\n\
    \            if (p == -1)\n                break;\n            int L = stt.tree[p][1],\
    \ R = stt.tree[p][2];\n            if (stt.tree[p][3]) {\n                if (L\
    \ == cur)\n                    b = compress(b, dat[R].first);\n              \
    \  else\n                    a = compress(a, dat[L].second);\n            } else\
    \ {\n                if (L == cur) {\n                    a = rake2(a, dat[R].first);\n\
    \                } else {\n                    c = compress(c, rake1(a, b));\n\
    \                    a = e();\n                    b = dat[L].first;\n       \
    \         }\n            }\n            cur = p;\n        }\n        return compress(c,\
    \ rake1(a, b));\n    }\n\n  private:\n    void update(int v) {\n        auto [L,\
    \ Lre] = dat[stt.tree[v][1]];\n        auto [R, Rre] = dat[stt.tree[v][2]];\n\
    \        if (stt.tree[v][3]) {\n            dat[v] = P{compress(L, R), compress(Rre,\
    \ Lre)};\n        } else {\n            dat[v] = P{rake1(L, R), rake2(Lre, R)};\n\
    \        }\n    }\n};\n\n/**\n * @brief Static TopTree\n */\n"
  code: "#pragma once\n\nstruct StaticTopTree {\n    using T = array<int, 4>;\n  \
    \  vector<vector<int>> g;\n    vector<T> tree; // {par,L,R,type 0:rake,1:compress,2:vertex}\n\
    \    int n, rt;\n    StaticTopTree() {}\n    StaticTopTree(int n) : n(n), g(n),\
    \ tree(n) {}\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    void run(int base = 0) {\n        dfs(base,\
    \ -1);\n        rt = build(base).first;\n    }\n    void dump() {\n        rep(v,\
    \ 0, SZ(tree)) {\n            auto [par, L, R, type] = tree[v];\n            show(v,\
    \ par, L, R, type);\n        }\n    }\n\n  private:\n    int dfs(int v, int p)\
    \ {\n        rep(i, 0, SZ(g[v])) if (g[v][i] == p) {\n            g[v].erase(g[v].begin()\
    \ + i);\n            break;\n        }\n        int sz = 1, best = 0;\n      \
    \  for (auto &to : g[v]) {\n            int add = dfs(to, v);\n            sz\
    \ += add;\n            if (chmax(best, add))\n                swap(to, g[v].front());\n\
    \        }\n        return sz;\n    }\n    using P = pair<int, int>; // {ID,size}\n\
    \    int make(int v, int L, int R, int type) {\n        if (v == -1) {\n     \
    \       v = SZ(tree);\n            tree.push_back({-1, L, R, type});\n       \
    \ } else {\n            tree[v] = {-1, L, R, type};\n        }\n        if (L\
    \ != -1)\n            tree[L][0] = v;\n        if (R != -1)\n            tree[R][0]\
    \ = v;\n        return v;\n    }\n    P merge(vector<P> a, int type) {\n     \
    \   if (SZ(a) == 1)\n            return a[0];\n        int sum = 0;\n        for\
    \ (auto &[_, sz] : a)\n            sum += sz;\n        vector<P> L, R;\n     \
    \   for (auto &[v, sz] : a) {\n            if (sum > sz)\n                L.push_back({v,\
    \ sz});\n            else\n                R.push_back({v, sz});\n           \
    \ sum -= sz * 2;\n        }\n        auto [lb, ls] = merge(L, type);\n       \
    \ auto [rb, rs] = merge(R, type);\n        return P{make(-1, lb, rb, type), ls\
    \ + rs};\n    }\n    P build(int v) {\n        int cur = v, pre = -1;\n      \
    \  vector<P> a;\n        for (;;) {\n            // rake\n            vector<P>\
    \ b;\n            b.push_back({make(cur, -1, -1, 2), 1});\n            if (pre\
    \ != -1) {\n                assert(g[pre][0] == cur);\n                for (auto\
    \ &to : g[pre])\n                    if (to != cur) {\n                      \
    \  b.push_back(build(to));\n                    }\n            }\n           \
    \ a.push_back(merge(b, 0));\n            if (SZ(g[cur]) == 0)\n              \
    \  break;\n            pre = cur, cur = g[cur][0];\n        }\n        return\
    \ merge(a, 1);\n    }\n};\n\n/**\n * rake: (a<-b], (a<-c] -> (a<-b].\n * compress:\
    \ (a<-b], (b<-c] -> (a<-c].\n */\ntemplate <typename M, M (*rake)(M, M), M (*compress)(M,\
    \ M)>\nstruct DynamicTreeDP {\n    int n, sz;\n    StaticTopTree stt;\n    vector<M>\
    \ dat;\n    DynamicTreeDP() {}\n    template <typename F>\n    DynamicTreeDP(int\
    \ n, StaticTopTree _stt, F vertex)\n        : n(n), sz(SZ(_stt.tree)), stt(_stt),\
    \ dat(sz) {\n        rep(i, 0, n) dat[i] = vertex(i);\n        rep(i, n, sz) update(i);\n\
    \    }\n    void set(int v, M x) {\n        dat[v] = x;\n        for (int p =\
    \ stt.tree[v][0]; p != -1; p = stt.tree[p][0])\n            update(p);\n    }\n\
    \    M get() {\n        return dat.back();\n    }\n\n  private:\n    void update(int\
    \ v) {\n        auto L = dat[stt.tree[v][1]];\n        auto R = dat[stt.tree[v][2]];\n\
    \        if (stt.tree[v][3]) {\n            dat[v] = compress(L, R);\n       \
    \ } else {\n            dat[v] = rake(L, R);\n        }\n    }\n};\n\n/**\n *\
    \ rake1: (a<-b], (a<-c] -> (a<-b].\n * rake2: (a->b], (a<-c] -> (a->b].\n * compress:\
    \ (a<-b], (b<-c] -> (a<-c].\n */\ntemplate <typename M, M (*rake1)(M, M), M (*rake2)(M,\
    \ M), M (*compress)(M, M),\n          M (*e)()>\nstruct DynamicRerootingDP {\n\
    \    int n, sz;\n    StaticTopTree stt;\n    using P = pair<M, M>;\n    vector<P>\
    \ dat; // {ord,rev}\n    DynamicRerootingDP() {}\n    template <typename F>\n\
    \    DynamicRerootingDP(int n, StaticTopTree _stt, F vertex)\n        : n(n),\
    \ sz(SZ(_stt.tree)), stt(_stt), dat(sz) {\n        dat[0] = {e(), e()};\n    \
    \    rep(i, 1, n) dat[i] = vertex(i);\n        rep(i, n, sz) update(i);\n    }\n\
    \    void set(int v, P x) {\n        dat[v] = x;\n        for (int p = stt.tree[v][0];\
    \ p != -1; p = stt.tree[p][0])\n            update(p);\n    }\n    M get(int v)\
    \ {\n        // a: expose cur to v (down)\n        // b: expose from cur (down)\n\
    \        // c: expose to cur (up)\n        int cur = v;\n        M a = dat[cur].second,\
    \ b = e(), c = e();\n        for (;;) {\n            int p = stt.tree[cur][0];\n\
    \            if (p == -1)\n                break;\n            int L = stt.tree[p][1],\
    \ R = stt.tree[p][2];\n            if (stt.tree[p][3]) {\n                if (L\
    \ == cur)\n                    b = compress(b, dat[R].first);\n              \
    \  else\n                    a = compress(a, dat[L].second);\n            } else\
    \ {\n                if (L == cur) {\n                    a = rake2(a, dat[R].first);\n\
    \                } else {\n                    c = compress(c, rake1(a, b));\n\
    \                    a = e();\n                    b = dat[L].first;\n       \
    \         }\n            }\n            cur = p;\n        }\n        return compress(c,\
    \ rake1(a, b));\n    }\n\n  private:\n    void update(int v) {\n        auto [L,\
    \ Lre] = dat[stt.tree[v][1]];\n        auto [R, Rre] = dat[stt.tree[v][2]];\n\
    \        if (stt.tree[v][3]) {\n            dat[v] = P{compress(L, R), compress(Rre,\
    \ Lre)};\n        } else {\n            dat[v] = P{rake1(L, R), rake2(Lre, R)};\n\
    \        }\n    }\n};\n\n/**\n * @brief Static TopTree\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/statictoptree.hpp
  requiredBy: []
  timestamp: '2024-11-30 06:30:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/statictoptree.hpp
layout: document
redirect_from:
- /library/Graph/statictoptree.hpp
- /library/Graph/statictoptree.hpp.html
title: Static TopTree
---
