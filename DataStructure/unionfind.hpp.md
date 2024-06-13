---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: DataStructure/manhattanmst.hpp
    title: Manhattan MST
  - icon: ':warning:'
    path: DataStructure/rangeparalleluf.hpp
    title: Range Parallel UnionFind
  - icon: ':warning:'
    path: Graph/euler.hpp
    title: Eulerian Trail
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_manhattanmst.test.cpp
    title: Verify/LC_manhattanmst.test.cpp
  - icon: ':x:'
    path: Verify/LC_unionfind.test.cpp
    title: Verify/LC_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"DataStructure/unionfind.hpp\"\n\r\nstruct UnionFind{\r\n\
    \    vector<int> par; int n;\r\n    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\
    \n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    bool unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return\
    \ false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y;\
    \ n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */\n"
  code: "#pragma once\r\n\r\nstruct UnionFind{\r\n    vector<int> par; int n;\r\n\
    \    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\n    int root(int\
    \ x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int x,int y){return\
    \ root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\n    bool\
    \ unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return false;\r\n\
    \        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y; n--;\
    \ return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/unionfind.hpp
  requiredBy:
  - DataStructure/rangeparalleluf.hpp
  - DataStructure/manhattanmst.hpp
  - Graph/euler.hpp
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_unionfind.test.cpp
  - Verify/LC_manhattanmst.test.cpp
documentation_of: DataStructure/unionfind.hpp
layout: document
redirect_from:
- /library/DataStructure/unionfind.hpp
- /library/DataStructure/unionfind.hpp.html
title: Union Find
---
