---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/scc.hpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 2-SAT
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
    \ Connected Components\r\n */\n#line 3 \"Math/twosat.hpp\"\n\r\nstruct TwoSat{\r\
    \n    int n;\r\n    vector<bool> res;\r\n    SCC graph;\r\n    TwoSat(int _n):n(_n),res(n),graph(n*2){}\r\
    \n    void add(int x){\r\n        n+=x;\r\n        res.resize(n);\r\n        graph.resize(n*2);\r\
    \n    }\r\n    void either(int i,bool f,int j,bool g){\r\n        graph.add_edge(2*i+(f^1),2*j+g);\r\
    \n        graph.add_edge(2*j+(g^1),2*i+f);\r\n    }\r\n    void AtMostOne(vector<int>&\
    \ a){\r\n        int offset=n;\r\n        add(a.size());\r\n        rep(i,0,a.size())either(a[i],0,offset+i,1);\r\
    \n        rep(i,1,a.size())either(offset+i-1,0,offset+i,1);\r\n        rep(i,1,a.size())either(a[i],0,offset+i-1,0);\r\
    \n    }\r\n    bool satisfiable(){\r\n        graph.run();\r\n        auto id=graph.id;\r\
    \n        rep(i,0,n){\r\n            if(id[i*2]==id[i*2+1])return false;\r\n \
    \           res[i]=id[i*2]<id[i*2+1];\r\n        }\r\n        return true;\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief 2-SAT\r\n */\n"
  code: "#pragma once\r\n#include \"Graph/scc.hpp\"\r\n\r\nstruct TwoSat{\r\n    int\
    \ n;\r\n    vector<bool> res;\r\n    SCC graph;\r\n    TwoSat(int _n):n(_n),res(n),graph(n*2){}\r\
    \n    void add(int x){\r\n        n+=x;\r\n        res.resize(n);\r\n        graph.resize(n*2);\r\
    \n    }\r\n    void either(int i,bool f,int j,bool g){\r\n        graph.add_edge(2*i+(f^1),2*j+g);\r\
    \n        graph.add_edge(2*j+(g^1),2*i+f);\r\n    }\r\n    void AtMostOne(vector<int>&\
    \ a){\r\n        int offset=n;\r\n        add(a.size());\r\n        rep(i,0,a.size())either(a[i],0,offset+i,1);\r\
    \n        rep(i,1,a.size())either(offset+i-1,0,offset+i,1);\r\n        rep(i,1,a.size())either(a[i],0,offset+i-1,0);\r\
    \n    }\r\n    bool satisfiable(){\r\n        graph.run();\r\n        auto id=graph.id;\r\
    \n        rep(i,0,n){\r\n            if(id[i*2]==id[i*2+1])return false;\r\n \
    \           res[i]=id[i*2]<id[i*2+1];\r\n        }\r\n        return true;\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief 2-SAT\r\n */"
  dependsOn:
  - Graph/scc.hpp
  isVerificationFile: false
  path: Math/twosat.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/twosat.hpp
layout: document
redirect_from:
- /library/Math/twosat.hpp
- /library/Math/twosat.hpp.html
title: 2-SAT
---
