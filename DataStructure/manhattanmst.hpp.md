---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/unionfind.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_manhattanmst.test.cpp
    title: Verify/LC_manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Manhattan MST
    links: []
  bundledCode: "#line 2 \"DataStructure/unionfind.hpp\"\n\r\nstruct UnionFind{\r\n\
    \    vector<int> par; int n;\r\n    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\
    \n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    bool unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return\
    \ false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y;\
    \ n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */\n\
    #line 3 \"DataStructure/manhattanmst.hpp\"\n\ntemplate<typename T>pair<T,vector<pair<int,int>>>\
    \ ManhattanMST(vector<T>& X,vector<T>& Y){\n    using Q=pair<T,pair<int,int>>;\n\
    \    int n=X.size();\n    vector<int> ord(n);\n    iota(ALL(ord),0);\n    vector<Q>\
    \ cand;\n    rep(_,0,2){\n        rep(__,0,2){\n            sort(ALL(ord),[&](int\
    \ i,int j){return X[i]+Y[i]<X[j]+Y[j];});\n            map<T,int> sweep;\n   \
    \         for(auto& i:ord){\n                for(auto it=sweep.lower_bound(-Y[i]);it!=sweep.end();it=sweep.erase(it)){\n\
    \                    int j=it->second;\n                    if(X[i]-X[j]<Y[i]-Y[j])break;\n\
    \                    cand.push_back({abs(X[i]-X[j])+abs(Y[i]-Y[j]),{i,j}});\n\
    \                }\n                sweep[-Y[i]]=i;\n            }\n         \
    \   swap(X,Y);\n        }\n        for(auto& x:X)x=-x;\n    }\n    sort(ALL(cand));\n\
    \    UnionFind uni(n);\n    T ret=0;\n    vector<pair<int,int>> es;\n    for(auto&\
    \ [cost,uv]:cand){\n        auto [u,v]=uv;\n        if(uni.unite(u,v)){\n    \
    \        ret+=cost;\n            es.push_back(uv);\n        }\n    }\n    return\
    \ {ret,es};\n}\n\n/**\n * @brief Manhattan MST\n*/\n"
  code: "#pragma once\n#include \"DataStructure/unionfind.hpp\"\n\ntemplate<typename\
    \ T>pair<T,vector<pair<int,int>>> ManhattanMST(vector<T>& X,vector<T>& Y){\n \
    \   using Q=pair<T,pair<int,int>>;\n    int n=X.size();\n    vector<int> ord(n);\n\
    \    iota(ALL(ord),0);\n    vector<Q> cand;\n    rep(_,0,2){\n        rep(__,0,2){\n\
    \            sort(ALL(ord),[&](int i,int j){return X[i]+Y[i]<X[j]+Y[j];});\n \
    \           map<T,int> sweep;\n            for(auto& i:ord){\n               \
    \ for(auto it=sweep.lower_bound(-Y[i]);it!=sweep.end();it=sweep.erase(it)){\n\
    \                    int j=it->second;\n                    if(X[i]-X[j]<Y[i]-Y[j])break;\n\
    \                    cand.push_back({abs(X[i]-X[j])+abs(Y[i]-Y[j]),{i,j}});\n\
    \                }\n                sweep[-Y[i]]=i;\n            }\n         \
    \   swap(X,Y);\n        }\n        for(auto& x:X)x=-x;\n    }\n    sort(ALL(cand));\n\
    \    UnionFind uni(n);\n    T ret=0;\n    vector<pair<int,int>> es;\n    for(auto&\
    \ [cost,uv]:cand){\n        auto [u,v]=uv;\n        if(uni.unite(u,v)){\n    \
    \        ret+=cost;\n            es.push_back(uv);\n        }\n    }\n    return\
    \ {ret,es};\n}\n\n/**\n * @brief Manhattan MST\n*/"
  dependsOn:
  - DataStructure/unionfind.hpp
  isVerificationFile: false
  path: DataStructure/manhattanmst.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:31:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_manhattanmst.test.cpp
documentation_of: DataStructure/manhattanmst.hpp
layout: document
redirect_from:
- /library/DataStructure/manhattanmst.hpp
- /library/DataStructure/manhattanmst.hpp.html
title: Manhattan MST
---
