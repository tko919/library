---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/AOJ_DSL_1_B.test.cpp
    title: Verify/AOJ_DSL_1_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Weighted Union Find
    links: []
  bundledCode: "#line 2 \"DataStructure/weightedunionfind.hpp\"\n\r\ntemplate<typename\
    \ T>struct WeightedUnionFind{\r\n    int n;\r\n    vector<int> par;\r\n    vector<T>\
    \ pot;\r\n    WeightedUnionFind(int _n=0):n(_n),par(n,-1),pot(n){}\r\n    int\
    \ root(int x){\r\n        if(par[x]<0)return x;\r\n        else{\r\n         \
    \   int r=root(par[x]);\r\n            pot[x]+=pot[par[x]];\r\n            return\
    \ par[x]=r;\r\n        }\r\n    }\r\n    bool same(int x,int y){return root(x)==root(y);}\r\
    \n    int size(int x){return -par[root(x)];}\r\n    T diff(int x,int y){return\
    \ pot[x]-pot[y];}\r\n    bool unite(int x,int y,T w){\r\n        int rx=root(x),ry=root(y);\r\
    \n        if(rx==ry)return false;\r\n        if(size(x)<size(y))swap(x,y),swap(rx,ry),w=-w;\r\
    \n        par[rx]+=par[ry];\r\n        par[ry]=rx;\r\n        pot[ry]=diff(x,y)-w;\r\
    \n        n--;\r\n        return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Weighted Union Find\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct WeightedUnionFind{\r\n   \
    \ int n;\r\n    vector<int> par;\r\n    vector<T> pot;\r\n    WeightedUnionFind(int\
    \ _n=0):n(_n),par(n,-1),pot(n){}\r\n    int root(int x){\r\n        if(par[x]<0)return\
    \ x;\r\n        else{\r\n            int r=root(par[x]);\r\n            pot[x]+=pot[par[x]];\r\
    \n            return par[x]=r;\r\n        }\r\n    }\r\n    bool same(int x,int\
    \ y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    T diff(int x,int y){return pot[x]-pot[y];}\r\n    bool unite(int x,int y,T\
    \ w){\r\n        int rx=root(x),ry=root(y);\r\n        if(rx==ry)return false;\r\
    \n        if(size(x)<size(y))swap(x,y),swap(rx,ry),w=-w;\r\n        par[rx]+=par[ry];\r\
    \n        par[ry]=rx;\r\n        pot[ry]=diff(x,y)-w;\r\n        n--;\r\n    \
    \    return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Weighted Union Find\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/weightedunionfind.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/AOJ_DSL_1_B.test.cpp
documentation_of: DataStructure/weightedunionfind.hpp
layout: document
redirect_from:
- /library/DataStructure/weightedunionfind.hpp
- /library/DataStructure/weightedunionfind.hpp.html
title: Weighted Union Find
---
