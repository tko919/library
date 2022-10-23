---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/bc.hpp
    title: Biconnected Components
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_biconnected_components.test.cpp
    title: Verify/LC_biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_two_edge_connected_components.test.cpp
    title: Verify/LC_two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Lowlink
    links: []
  bundledCode: "#line 2 \"Graph/lowlink.hpp\"\n\r\nstruct LowLink{\r\n    const int\
    \ n; vector<vector<int>> g;\r\n    vector<int> used,ord,low,id;\r\n    LowLink(const\
    \ int& _n=0):n(_n),g(n),\r\n        used(n,0),ord(n,0),low(n,0),id(n,-1){\r\n\
    \    }\r\n    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n     }\r\n    void dfs(int v,int p,int& k){\r\n        used[v]=1; low[v]=ord[v]=k++;\r\
    \n        int cnt=0,sub=0;\r\n        for(auto& to:g[v]){\r\n            if(to==p\
    \ and (++sub)<=1)continue;\r\n            if(!used[to]){\r\n                cnt++;\
    \ dfs(to,v,k);\r\n                chmin(low[v],low[to]);\r\n            }\r\n\
    \            else chmin(low[v],ord[to]);\r\n        }\r\n    }\r\n    void dfs2(int\
    \ v,int p,int& k){\r\n        if(p!=-1 and ord[p]>=low[v])id[v]=id[p];\r\n   \
    \     else id[v]=k++;\r\n        for(auto& to:g[v])if(id[to]==-1)dfs2(to,v,k);\r\
    \n    }\r\n    int run(){\r\n        int k=0; rep(i,0,n)if(!used[i])dfs(i,-1,k);\r\
    \n        k=0; rep(i,0,n)if(id[i]==-1)dfs2(i,-1,k);\r\n        return k;\r\n \
    \   }\r\n};\r\n\r\n/**\r\n * @brief Lowlink\r\n */\n"
  code: "#pragma once\r\n\r\nstruct LowLink{\r\n    const int n; vector<vector<int>>\
    \ g;\r\n    vector<int> used,ord,low,id;\r\n    LowLink(const int& _n=0):n(_n),g(n),\r\
    \n        used(n,0),ord(n,0),low(n,0),id(n,-1){\r\n    }\r\n    void add_edge(int\
    \ u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\n     }\r\
    \n    void dfs(int v,int p,int& k){\r\n        used[v]=1; low[v]=ord[v]=k++;\r\
    \n        int cnt=0,sub=0;\r\n        for(auto& to:g[v]){\r\n            if(to==p\
    \ and (++sub)<=1)continue;\r\n            if(!used[to]){\r\n                cnt++;\
    \ dfs(to,v,k);\r\n                chmin(low[v],low[to]);\r\n            }\r\n\
    \            else chmin(low[v],ord[to]);\r\n        }\r\n    }\r\n    void dfs2(int\
    \ v,int p,int& k){\r\n        if(p!=-1 and ord[p]>=low[v])id[v]=id[p];\r\n   \
    \     else id[v]=k++;\r\n        for(auto& to:g[v])if(id[to]==-1)dfs2(to,v,k);\r\
    \n    }\r\n    int run(){\r\n        int k=0; rep(i,0,n)if(!used[i])dfs(i,-1,k);\r\
    \n        k=0; rep(i,0,n)if(id[i]==-1)dfs2(i,-1,k);\r\n        return k;\r\n \
    \   }\r\n};\r\n\r\n/**\r\n * @brief Lowlink\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lowlink.hpp
  requiredBy:
  - Graph/bc.hpp
  timestamp: '2022-02-06 21:52:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_two_edge_connected_components.test.cpp
  - Verify/LC_biconnected_components.test.cpp
documentation_of: Graph/lowlink.hpp
layout: document
redirect_from:
- /library/Graph/lowlink.hpp
- /library/Graph/lowlink.hpp.html
title: Lowlink
---
