---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/matroid.hpp
    title: Matroid
  - icon: ':warning:'
    path: Graph/dmdecomp.hpp
    title: DM decomposition
  - icon: ':heavy_check_mark:'
    path: Math/twosat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_scc.test.cpp
    title: Verify/LC_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_two_sat.test.cpp
    title: Verify/LC_two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Strongly Connected Components
    links: []
  bundledCode: "#line 2 \"Graph/scc.hpp\"\n\r\nstruct SCC{\r\n    int n,m,cur;\r\n\
    \    vector<vector<int>> g;\r\n    vector<int> low,ord,id;\r\n    SCC(int _n=0):n(_n),m(0),cur(0),g(_n),low(_n),ord(_n,-1),id(_n){}\r\
    \n    void resize(int _n){\r\n        n=_n;\r\n        g.resize(n);\r\n      \
    \  low.resize(n);\r\n        ord.resize(n,-1);\r\n        id.resize(n);\r\n  \
    \  }\r\n    void add_edge(int u,int v){g[u].emplace_back(v);}\r\n    void dfs(int\
    \ v,vector<int>& used){\r\n        ord[v]=low[v]=cur++;\r\n        used.emplace_back(v);\r\
    \n        for(auto& nxt:g[v]){\r\n            if(ord[nxt]==-1){\r\n          \
    \      dfs(nxt,used); chmin(low[v],low[nxt]);\r\n            }\r\n           \
    \ else{\r\n                chmin(low[v],ord[nxt]);\r\n            }\r\n      \
    \  }\r\n        if(ord[v]==low[v]){\r\n            while(1){\r\n             \
    \   int add=used.back(); used.pop_back();\r\n                ord[add]=n; id[add]=m;\r\
    \n                if(v==add)break;\r\n            }\r\n            m++;\r\n  \
    \      }\r\n    }\r\n    void run(){\r\n        vector<int> used;\r\n        rep(v,0,n)if(ord[v]==-1)dfs(v,used);\r\
    \n        for(auto& x:id)x=m-1-x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Strongly\
    \ Connected Components\r\n */\n"
  code: "#pragma once\r\n\r\nstruct SCC{\r\n    int n,m,cur;\r\n    vector<vector<int>>\
    \ g;\r\n    vector<int> low,ord,id;\r\n    SCC(int _n=0):n(_n),m(0),cur(0),g(_n),low(_n),ord(_n,-1),id(_n){}\r\
    \n    void resize(int _n){\r\n        n=_n;\r\n        g.resize(n);\r\n      \
    \  low.resize(n);\r\n        ord.resize(n,-1);\r\n        id.resize(n);\r\n  \
    \  }\r\n    void add_edge(int u,int v){g[u].emplace_back(v);}\r\n    void dfs(int\
    \ v,vector<int>& used){\r\n        ord[v]=low[v]=cur++;\r\n        used.emplace_back(v);\r\
    \n        for(auto& nxt:g[v]){\r\n            if(ord[nxt]==-1){\r\n          \
    \      dfs(nxt,used); chmin(low[v],low[nxt]);\r\n            }\r\n           \
    \ else{\r\n                chmin(low[v],ord[nxt]);\r\n            }\r\n      \
    \  }\r\n        if(ord[v]==low[v]){\r\n            while(1){\r\n             \
    \   int add=used.back(); used.pop_back();\r\n                ord[add]=n; id[add]=m;\r\
    \n                if(v==add)break;\r\n            }\r\n            m++;\r\n  \
    \      }\r\n    }\r\n    void run(){\r\n        vector<int> used;\r\n        rep(v,0,n)if(ord[v]==-1)dfs(v,used);\r\
    \n        for(auto& x:id)x=m-1-x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Strongly\
    \ Connected Components\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/scc.hpp
  requiredBy:
  - Graph/dmdecomp.hpp
  - Algorithm/matroid.hpp
  - Math/twosat.hpp
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_two_sat.test.cpp
  - Verify/LC_scc.test.cpp
documentation_of: Graph/scc.hpp
layout: document
redirect_from:
- /library/Graph/scc.hpp
- /library/Graph/scc.hpp.html
title: Strongly Connected Components
---
