---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/matroid.hpp
    title: Matroid
  - icon: ':warning:'
    path: Graph/dmdecomp.hpp
    title: DM decomposition
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bipartitematching.test.cpp
    title: Verify/LC_bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bipartite Matching
    links: []
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random {\r\nmt19937_64\
    \ randgen(chrono::steady_clock::now().time_since_epoch().count());\r\nusing u64\
    \ = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n}\r\ntemplate\
    \ <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\n}\r\ntemplate\
    \ <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R - L) + L;\r\n}\r\
    \ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\n}\r\
    \nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a', 'z');\r\
    \n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter first, Iter\
    \ last) {\r\n    if (first == last)\r\n        return;\r\n    int len = 1;\r\n\
    \    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\n     \
    \   int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n            iter_swap(it,\
    \ first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T> select(int n, T\
    \ L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n        vector<T> ret(R\
    \ - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\n  \
    \      ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool simple> vector<pair<int,\
    \ int>> genGraph(int n) {\r\n    vector<pair<int, int>> cand, es;\r\n    rep(u,\
    \ 0, n) rep(v, 0, n) {\r\n        if (simple and u == v)\r\n            continue;\r\
    \n        if (!directed and u > v)\r\n            continue;\r\n        cand.push_back({u,\
    \ v});\r\n    }\r\n    int m = get(SZ(cand));\r\n    vector<int> ord;\r\n    if\
    \ (simple)\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    else {\r\n    \
    \    rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n    }\r\n    for (auto\
    \ &i : ord)\r\n        es.push_back(cand[i]);\r\n    relabel(n, es);\r\n    return\
    \ es;\r\n}\r\nvector<pair<int, int>> genTree(int n) {\r\n    vector<pair<int,\
    \ int>> es;\r\n    rep(i, 1, n) es.push_back({get(i - 1), i});\r\n    relabel(n,\
    \ es);\r\n    return es;\r\n}\r\n}; // namespace Random\r\n\r\n/**\r\n * @brief\
    \ Random\r\n */\n#line 3 \"Graph/bimatching.hpp\"\n\r\nvector<int> BiMatching(int\
    \ n, int m, vector<vector<int>> &g) {\r\n    rep(v, 0, n) Random::shuffle(ALL(g[v]));\r\
    \n    vector<int> L(n, -1), R(m, -1);\r\n    for (;;) {\r\n        vector<int>\
    \ par(n, -1), root(n, -1);\r\n        queue<int> que;\r\n        rep(i, 0, n)\
    \ if (L[i] == -1) {\r\n            que.push(i);\r\n            root[i] = i;\r\n\
    \        }\r\n        bool upd = 0;\r\n        while (!que.empty()) {\r\n    \
    \        int v = que.front();\r\n            que.pop();\r\n            if (L[root[v]]\
    \ != -1)\r\n                continue;\r\n            for (auto u : g[v]) {\r\n\
    \                if (R[u] == -1) {\r\n                    while (u != -1) {\r\n\
    \                        R[u] = v;\r\n                        swap(L[v], u);\r\
    \n                        v = par[v];\r\n                    }\r\n           \
    \         upd = 1;\r\n                    break;\r\n                }\r\n    \
    \            int to = R[u];\r\n                if (par[to] == -1) {\r\n      \
    \              root[to] = root[v];\r\n                    par[to] = v;\r\n   \
    \                 que.push(to);\r\n                }\r\n            }\r\n    \
    \    }\r\n        if (!upd)\r\n            break;\r\n    }\r\n    return L;\r\n\
    }\r\n\r\n/**\r\n * @brief Bipartite Matching\r\n */\n"
  code: "#pragma once\r\n#include \"Utility/random.hpp\"\r\n\r\nvector<int> BiMatching(int\
    \ n, int m, vector<vector<int>> &g) {\r\n    rep(v, 0, n) Random::shuffle(ALL(g[v]));\r\
    \n    vector<int> L(n, -1), R(m, -1);\r\n    for (;;) {\r\n        vector<int>\
    \ par(n, -1), root(n, -1);\r\n        queue<int> que;\r\n        rep(i, 0, n)\
    \ if (L[i] == -1) {\r\n            que.push(i);\r\n            root[i] = i;\r\n\
    \        }\r\n        bool upd = 0;\r\n        while (!que.empty()) {\r\n    \
    \        int v = que.front();\r\n            que.pop();\r\n            if (L[root[v]]\
    \ != -1)\r\n                continue;\r\n            for (auto u : g[v]) {\r\n\
    \                if (R[u] == -1) {\r\n                    while (u != -1) {\r\n\
    \                        R[u] = v;\r\n                        swap(L[v], u);\r\
    \n                        v = par[v];\r\n                    }\r\n           \
    \         upd = 1;\r\n                    break;\r\n                }\r\n    \
    \            int to = R[u];\r\n                if (par[to] == -1) {\r\n      \
    \              root[to] = root[v];\r\n                    par[to] = v;\r\n   \
    \                 que.push(to);\r\n                }\r\n            }\r\n    \
    \    }\r\n        if (!upd)\r\n            break;\r\n    }\r\n    return L;\r\n\
    }\r\n\r\n/**\r\n * @brief Bipartite Matching\r\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: Graph/bimatching.hpp
  requiredBy:
  - Algorithm/matroid.hpp
  - Graph/dmdecomp.hpp
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_bipartitematching.test.cpp
documentation_of: Graph/bimatching.hpp
layout: document
redirect_from:
- /library/Graph/bimatching.hpp
- /library/Graph/bimatching.hpp.html
title: Bipartite Matching
---
