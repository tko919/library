---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/contour.hpp
    title: Contour Sum Query
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_frequency_table_of_tree_distance.test.cpp
    title: Verify/LC_frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
    title: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Centroid Decomposition
    links: []
  bundledCode: "#line 2 \"Graph/centroid.hpp\"\n\r\nclass CentroidDecomposition {\r\
    \n    void get(int v, int p) {\r\n        sz[v] = 1;\r\n        for (auto &to\
    \ : g[v])\r\n            if (to != p and !used[to]) {\r\n                get(to,\
    \ v);\r\n                sz[v] += sz[to];\r\n            }\r\n    }\r\n    int\
    \ dfs(int v, int p, int rt) {\r\n        for (auto &to : g[v])\r\n           \
    \ if (to != p and !used[to]) {\r\n                if (sz[to] > (sz[rt] >> 1))\r\
    \n                    return dfs(to, v, rt);\r\n            }\r\n        return\
    \ v;\r\n    }\r\n\r\n  public:\r\n    int n, all;\r\n    vector<vector<int>> g;\r\
    \n    vector<int> sz, used;\r\n    CentroidDecomposition(int n_) : n(n_), g(n),\
    \ sz(n), used(n) {}\r\n    void add_edge(int u, int v) {\r\n        g[u].push_back(v);\r\
    \n        g[v].push_back(u);\r\n    }\r\n    int size(int rt) {\r\n        get(rt,\
    \ -1);\r\n        return sz[rt];\r\n    }\r\n    int find(int rt) {\r\n      \
    \  get(rt, -1);\r\n        all = sz[rt];\r\n        int res = dfs(rt, -1, rt);\r\
    \n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Centroid Decomposition\r\
    \n */\n"
  code: "#pragma once\r\n\r\nclass CentroidDecomposition {\r\n    void get(int v,\
    \ int p) {\r\n        sz[v] = 1;\r\n        for (auto &to : g[v])\r\n        \
    \    if (to != p and !used[to]) {\r\n                get(to, v);\r\n         \
    \       sz[v] += sz[to];\r\n            }\r\n    }\r\n    int dfs(int v, int p,\
    \ int rt) {\r\n        for (auto &to : g[v])\r\n            if (to != p and !used[to])\
    \ {\r\n                if (sz[to] > (sz[rt] >> 1))\r\n                    return\
    \ dfs(to, v, rt);\r\n            }\r\n        return v;\r\n    }\r\n\r\n  public:\r\
    \n    int n, all;\r\n    vector<vector<int>> g;\r\n    vector<int> sz, used;\r\
    \n    CentroidDecomposition(int n_) : n(n_), g(n), sz(n), used(n) {}\r\n    void\
    \ add_edge(int u, int v) {\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    int size(int rt) {\r\n        get(rt, -1);\r\n        return sz[rt];\r\
    \n    }\r\n    int find(int rt) {\r\n        get(rt, -1);\r\n        all = sz[rt];\r\
    \n        int res = dfs(rt, -1, rt);\r\n        return res;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Centroid Decomposition\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/centroid.hpp
  requiredBy:
  - Graph/contour.hpp
  timestamp: '2024-11-30 06:30:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_frequency_table_of_tree_distance.test.cpp
  - Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
documentation_of: Graph/centroid.hpp
layout: document
redirect_from:
- /library/Graph/centroid.hpp
- /library/Graph/centroid.hpp.html
title: Centroid Decomposition
---
