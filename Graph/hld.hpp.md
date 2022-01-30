---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_lca.test.cpp
    title: Verify/LC_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_add_path_sum.test.cpp
    title: Verify/LC_vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_vertex_set_path_composite.test.cpp
    title: Verify/LC_vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Heavy Light Decomposition
    links: []
  bundledCode: "#line 2 \"Graph/hld.hpp\"\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\
    \n    vector<vector<int>> g; vector<int> sz,in,out,hs,par;\r\n    void dfs(int\
    \ v,int p){\r\n        par[v]=p; sz[v]=1;\r\n        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\
    \n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\n        }\r\n    }\r\n\
    \    void dfs2(int v,int p,int& k){\r\n        in[v]=k++;\r\n        for(auto&\
    \ to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\n       \
    \     dfs2(to,v,k);\r\n        }\r\n        out[v]=k;\r\n    }\r\n    HLD(int\
    \ _n):g(_n),sz(_n),in(_n),out(_n),hs(_n),par(_n){}\r\n    void add_edge(int u,int\
    \ v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\n    }\r\n    void\
    \ run(int rt=0){dfs(rt,-1); int k=0; dfs2(rt,-1,k);}\r\n    int lca(int u,int\
    \ v){\r\n        for(;;v=par[hs[v]]){\r\n            if(in[u]>in[v])swap(u,v);\r\
    \n            if(hs[u]==hs[v])return u;\r\n        }\r\n    }\r\n    vector<P>\
    \ get(int u,int p,bool es=0){\r\n        assert(in[p]<=in[u] and out[u]<=out[p]);\r\
    \n        vector<P> res;\r\n        while(hs[u]!=hs[p]){\r\n            res.push_back({in[hs[u]],in[u]+1});\r\
    \n            u=par[hs[u]];\r\n        }\r\n        res.push_back({in[p]+es,in[u]+1});\r\
    \n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\
    \n */\n"
  code: "#pragma once\r\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\n    vector<vector<int>>\
    \ g; vector<int> sz,in,out,hs,par;\r\n    void dfs(int v,int p){\r\n        par[v]=p;\
    \ sz[v]=1;\r\n        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\
    \n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\n        }\r\n    }\r\n\
    \    void dfs2(int v,int p,int& k){\r\n        in[v]=k++;\r\n        for(auto&\
    \ to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\n       \
    \     dfs2(to,v,k);\r\n        }\r\n        out[v]=k;\r\n    }\r\n    HLD(int\
    \ _n):g(_n),sz(_n),in(_n),out(_n),hs(_n),par(_n){}\r\n    void add_edge(int u,int\
    \ v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\n    }\r\n    void\
    \ run(int rt=0){dfs(rt,-1); int k=0; dfs2(rt,-1,k);}\r\n    int lca(int u,int\
    \ v){\r\n        for(;;v=par[hs[v]]){\r\n            if(in[u]>in[v])swap(u,v);\r\
    \n            if(hs[u]==hs[v])return u;\r\n        }\r\n    }\r\n    vector<P>\
    \ get(int u,int p,bool es=0){\r\n        assert(in[p]<=in[u] and out[u]<=out[p]);\r\
    \n        vector<P> res;\r\n        while(hs[u]!=hs[p]){\r\n            res.push_back({in[hs[u]],in[u]+1});\r\
    \n            u=par[hs[u]];\r\n        }\r\n        res.push_back({in[p]+es,in[u]+1});\r\
    \n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/hld.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_lca.test.cpp
  - Verify/LC_vertex_set_path_composite.test.cpp
  - Verify/LC_vertex_add_path_sum.test.cpp
documentation_of: Graph/hld.hpp
layout: document
redirect_from:
- /library/Graph/hld.hpp
- /library/Graph/hld.hpp.html
title: Heavy Light Decomposition
---
