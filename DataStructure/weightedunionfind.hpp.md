---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/AOJ_DSL_1_B.test.cpp
    title: Verify/AOJ_DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Weighted Union Find
    links: []
  bundledCode: "#line 2 \"DataStructure/weightedunionfind.hpp\"\n\r\ntemplate <typename\
    \ T> struct WeightedUnionFind {\r\n    int n;\r\n    vector<int> par;\r\n    vector<T>\
    \ pot;\r\n    WeightedUnionFind(int _n = 0) : n(_n), par(n, -1), pot(n) {}\r\n\
    \    int root(int x) {\r\n        if (par[x] < 0)\r\n            return x;\r\n\
    \        else {\r\n            int r = root(par[x]);\r\n            pot[x] = pot[par[x]]\
    \ + pot[x];\r\n            return par[x] = r;\r\n        }\r\n    }\r\n    bool\
    \ same(int x, int y) {\r\n        return root(x) == root(y);\r\n    }\r\n    int\
    \ size(int x) {\r\n        return -par[root(x)];\r\n    }\r\n    T diff(int x,\
    \ int y) {\r\n        root(x);\r\n        root(y);\r\n        return -pot[y] +\
    \ pot[x];\r\n    }\r\n    bool unite(int x, int y, T w) {\r\n        int rx =\
    \ root(x), ry = root(y);\r\n        if (rx == ry)\r\n            return false;\r\
    \n        if (par[rx] < par[ry])\r\n            swap(x, y), swap(rx, ry), w =\
    \ -w;\r\n        par[ry] += par[rx];\r\n        par[rx] = ry;\r\n        pot[rx]\
    \ = pot[y] + w - pot[x];\r\n        n--;\r\n        return true;\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Weighted Union Find\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> struct WeightedUnionFind {\r\n\
    \    int n;\r\n    vector<int> par;\r\n    vector<T> pot;\r\n    WeightedUnionFind(int\
    \ _n = 0) : n(_n), par(n, -1), pot(n) {}\r\n    int root(int x) {\r\n        if\
    \ (par[x] < 0)\r\n            return x;\r\n        else {\r\n            int r\
    \ = root(par[x]);\r\n            pot[x] = pot[par[x]] + pot[x];\r\n          \
    \  return par[x] = r;\r\n        }\r\n    }\r\n    bool same(int x, int y) {\r\
    \n        return root(x) == root(y);\r\n    }\r\n    int size(int x) {\r\n   \
    \     return -par[root(x)];\r\n    }\r\n    T diff(int x, int y) {\r\n       \
    \ root(x);\r\n        root(y);\r\n        return -pot[y] + pot[x];\r\n    }\r\n\
    \    bool unite(int x, int y, T w) {\r\n        int rx = root(x), ry = root(y);\r\
    \n        if (rx == ry)\r\n            return false;\r\n        if (par[rx] <\
    \ par[ry])\r\n            swap(x, y), swap(rx, ry), w = -w;\r\n        par[ry]\
    \ += par[rx];\r\n        par[rx] = ry;\r\n        pot[rx] = pot[y] + w - pot[x];\r\
    \n        n--;\r\n        return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Weighted Union Find\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/weightedunionfind.hpp
  requiredBy: []
  timestamp: '2024-07-20 01:49:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/AOJ_DSL_1_B.test.cpp
documentation_of: DataStructure/weightedunionfind.hpp
layout: document
redirect_from:
- /library/DataStructure/weightedunionfind.hpp
- /library/DataStructure/weightedunionfind.hpp.html
title: Weighted Union Find
---
