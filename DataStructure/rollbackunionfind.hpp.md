---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Rollback Union Find
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
    /**\n * @brief Rollback Union Find\n */\n"
  code: "#pragma once\n\nstruct RollbackUnionFind{\n    vector<int> par;\n    stack<pair<int,int>>\
    \ history;\n    int snap;\n    RollbackUnionFind(){}\n    RollbackUnionFind(int\
    \ _n):par(_n,-1),snap(0){}\n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\n\
    \    bool same(int x,int y){return root(x)==root(y);}\n    int size(int x){return\
    \ -par[root(x)];}\n    bool unite(int x,int y){\n        x=root(x),y=root(y);\n\
    \        history.push({x,par[x]});\n        history.push({y,par[y]});\n      \
    \  if(x==y)return false;\n        if(size(x)>size(y))swap(x,y);\n        par[y]+=par[x];\
    \ par[x]=y;\n        return true;\n    }\n    void undo(){\n        par[history.top().first]=history.top().second;\n\
    \        history.pop();\n        par[history.top().first]=history.top().second;\n\
    \        history.pop();\n    }\n    void snapshot(){snap=int(history.size()>>1);}\n\
    \    int get(){return int(history.size()>>1);}\n    void rollback(int state=-1){\n\
    \        if(state==-1)state=snap;\n        state<<=1;\n        while(state<history.size())undo();\n\
    \    }\n};\n\n/**\n * @brief Rollback Union Find\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/rollbackunionfind.hpp
  requiredBy: []
  timestamp: '2022-12-26 23:10:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/rollbackunionfind.hpp
layout: document
redirect_from:
- /library/DataStructure/rollbackunionfind.hpp
- /library/DataStructure/rollbackunionfind.hpp.html
title: Rollback Union Find
---
