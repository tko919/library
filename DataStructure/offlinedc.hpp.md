---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/rollbackunionfind.hpp
    title: Rollback Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/rollbackunionfind.hpp\"\n\nstruct RollbackUnionFind{\n\
    \    vector<int> par;\n    stack<pair<int,int>> history;\n    int snap;\n    RollbackUnionFind(){}\n\
    \    RollbackUnionFind(int _n):par(_n,-1),snap(0){}\n    int root(int x){return\
    \ par[x]<0?x:par[x]=root(par[x]);}\n    bool same(int x,int y){return root(x)==root(y);}\n\
    \    int size(int x){return -par[root(x)];}\n    bool unite(int x,int y){\n  \
    \      x=root(x),y=root(y);\n        history.push({x,par[x]});\n        history.push({y,par[y]});\n\
    \        if(x==y)return false;\n        if(size(x)>size(y))swap(x,y);\n      \
    \  par[y]+=par[x]; par[x]=y;\n        return true;\n    }\n    void undo(){\n\
    \        par[history.top().first]=history.top().second;\n        history.pop();\n\
    \        par[history.top().first]=history.top().second;\n        history.pop();\n\
    \    }\n    void snapshot(){snap=int(history.size()>>1);}\n    int get(){return\
    \ int(history.size()>>1);}\n    void rollback(int state=-1){\n        if(state==-1)state=snap;\n\
    \        state<<=1;\n        while(state<history.size())undo();\n    }\n};\n\n\
    /**\n * @brief Rollback Union Find\n */\n#line 3 \"DataStructure/offlinedc.hpp\"\
    \n\nstruct DynamicConnectivity{\n    using edge=pair<int,int>;\n    RollbackUnionFind\
    \ uni; int n,q,sz;\n    vector<vector<edge>> seg;\n    vector<pair<pair<int,int>,edge>>\
    \ keep;\n    map<edge,int> appear;\n    DynamicConnectivity(int n,int q):uni(n),n(n),q(q){\n\
    \        sz=1; while(sz<q)sz<<=1;\n        seg.resize(2*sz-1);\n    }\n    void\
    \ insert(int t,int u,int v){\n        auto e=minmax(u,v); appear[e]=t;\n    }\n\
    \    void erase(int t,int u,int v){\n        auto e=minmax(u,v);\n        keep.push_back({{appear[e],t},e});\
    \ appear.erase(e);\n    }\n    void add(int a,int b,const edge& e,int k=0,int\
    \ l=0,int r=-1){\n        if(r<0)r=sz; if(r<=a||b<=l)return;\n        if(a<=l&&r<=b){seg[k].push_back(e);\
    \ return;}\n        add(a,b,e,2*k+1,l,(l+r)/2); add(a,b,e,2*k+2,(l+r)/2,r);\n\
    \    }\n    void build(){\n        for(auto& p:appear)add(p.second,q,p.first);\n\
    \        for(auto& s:keep)add(s.first.first,s.first.second,s.second);\n    }\n\
    \    template<void (*f)(int)>void run(int k=0){\n        for(auto e:seg[k]){\n\
    \            if(e.first<0)uni.push(-e.first-1,e.second);\n            else uni.merge(e.first,e.second);\n\
    \        }\n        if(k<sz-1){run(f,2*k+1); run(f,2*k+2);}\n        else if(k-(sz-1)<q)f(k-(sz-1));\n\
    \        for(auto& e:seg[k])uni.undo();\n    }\n};\n\n/**\n * Offline Dynamic\
    \ Connectivity\n*/\n"
  code: "#pragma once\n#include \"DataStructure/rollbackunionfind.hpp\"\n\nstruct\
    \ DynamicConnectivity{\n    using edge=pair<int,int>;\n    RollbackUnionFind uni;\
    \ int n,q,sz;\n    vector<vector<edge>> seg;\n    vector<pair<pair<int,int>,edge>>\
    \ keep;\n    map<edge,int> appear;\n    DynamicConnectivity(int n,int q):uni(n),n(n),q(q){\n\
    \        sz=1; while(sz<q)sz<<=1;\n        seg.resize(2*sz-1);\n    }\n    void\
    \ insert(int t,int u,int v){\n        auto e=minmax(u,v); appear[e]=t;\n    }\n\
    \    void erase(int t,int u,int v){\n        auto e=minmax(u,v);\n        keep.push_back({{appear[e],t},e});\
    \ appear.erase(e);\n    }\n    void add(int a,int b,const edge& e,int k=0,int\
    \ l=0,int r=-1){\n        if(r<0)r=sz; if(r<=a||b<=l)return;\n        if(a<=l&&r<=b){seg[k].push_back(e);\
    \ return;}\n        add(a,b,e,2*k+1,l,(l+r)/2); add(a,b,e,2*k+2,(l+r)/2,r);\n\
    \    }\n    void build(){\n        for(auto& p:appear)add(p.second,q,p.first);\n\
    \        for(auto& s:keep)add(s.first.first,s.first.second,s.second);\n    }\n\
    \    template<void (*f)(int)>void run(int k=0){\n        for(auto e:seg[k]){\n\
    \            if(e.first<0)uni.push(-e.first-1,e.second);\n            else uni.merge(e.first,e.second);\n\
    \        }\n        if(k<sz-1){run(f,2*k+1); run(f,2*k+2);}\n        else if(k-(sz-1)<q)f(k-(sz-1));\n\
    \        for(auto& e:seg[k])uni.undo();\n    }\n};\n\n/**\n * Offline Dynamic\
    \ Connectivity\n*/"
  dependsOn:
  - DataStructure/rollbackunionfind.hpp
  isVerificationFile: false
  path: DataStructure/offlinedc.hpp
  requiredBy: []
  timestamp: '2022-12-26 23:10:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/offlinedc.hpp
layout: document
redirect_from:
- /library/DataStructure/offlinedc.hpp
- /library/DataStructure/offlinedc.hpp.html
title: DataStructure/offlinedc.hpp
---
