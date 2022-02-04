---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_unionfind.test.cpp
    title: Verify/LC_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_unionfind.test.cpp
documentation_of: DataStructure/unionfind.hpp
layout: document
redirect_from:
- /library/DataStructure/unionfind.hpp
- /library/DataStructure/unionfind.hpp.html
title: Union Find
---