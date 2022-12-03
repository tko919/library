---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/contour.hpp
    title: Contour Sum Query
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_lca.test.cpp
    title: Verify/LC_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_add_path_sum.test.cpp
    title: Verify/LC_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
    title: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_set_path_composite.test.cpp
    title: Verify/LC_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Heavy Light Decomposition
    links: []
  bundledCode: "#line 2 \"Graph/hld.hpp\"\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\
    \n    vector<vector<int>> g; vector<int> sz,in,out,rev,hs,par,dist;\r\n    void\
    \ dfs(int v,int p){\r\n        par[v]=p; sz[v]=1; dist[v]=dist[p]+1;\r\n     \
    \   if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\n        for(auto&\
    \ to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\
    \n        }\r\n    }\r\n    void dfs2(int v,int p,int& k){\r\n        in[v]=k++;\
    \ rev[in[v]]=v;\r\n        for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
    \n            dfs2(to,v,k);\r\n        }\r\n        out[v]=k;\r\n    }\r\n   \
    \ HLD(int _n):g(_n),sz(_n),in(_n),out(_n),rev(_n),hs(_n),par(_n),dist(_n){}\r\n\
    \    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n    }\r\n    void run(int rt=0){dfs(rt,-1); hs[rt]=rt; int k=0; dfs2(rt,-1,k);}\r\
    \n    int lca(int u,int v){\r\n        for(;;v=par[hs[v]]){\r\n            if(in[u]>in[v])swap(u,v);\r\
    \n            if(hs[u]==hs[v])return u;\r\n        }\r\n    }\r\n    vector<P>\
    \ get(int u,int p,bool es=0){\r\n        assert(in[p]<=in[u] and out[u]<=out[p]);\r\
    \n        vector<P> res;\r\n        while(hs[u]!=hs[p]){\r\n            res.push_back({in[hs[u]],in[u]+1});\r\
    \n            u=par[hs[u]];\r\n        }\r\n        res.push_back({in[p]+es,in[u]+1});\r\
    \n        return res;\r\n    }\r\n    int jump(int u,int v,int k){\r\n       \
    \ if(k<0)return -1;\r\n        int g=lca(u,v);\r\n        int d0=dist[u]+dist[v]-dist[g]*2;\r\
    \n        if(d0<k)return -1;\r\n        int st=u;\r\n        if(dist[u]-dist[g]<k)st=v,k=d0-k;\r\
    \n        for(;;){\r\n            int to=hs[st];\r\n            if(in[st]-k>=in[to])return\
    \ rev[in[st]-k];\r\n            k-=in[st]-in[to]+1; st=par[to];\r\n        }\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\n */\n"
  code: "#pragma once\r\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\n    vector<vector<int>>\
    \ g; vector<int> sz,in,out,rev,hs,par,dist;\r\n    void dfs(int v,int p){\r\n\
    \        par[v]=p; sz[v]=1; dist[v]=dist[p]+1;\r\n        if(!g[v].empty() and\
    \ g[v][0]==p)swap(g[v][0],g[v].back());\r\n        for(auto& to:g[v])if(to!=p){\r\
    \n           dfs(to,v); sz[v]+=sz[to];\r\n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\
    \n        }\r\n    }\r\n    void dfs2(int v,int p,int& k){\r\n        in[v]=k++;\
    \ rev[in[v]]=v;\r\n        for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
    \n            dfs2(to,v,k);\r\n        }\r\n        out[v]=k;\r\n    }\r\n   \
    \ HLD(int _n):g(_n),sz(_n),in(_n),out(_n),rev(_n),hs(_n),par(_n),dist(_n){}\r\n\
    \    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n    }\r\n    void run(int rt=0){dfs(rt,-1); hs[rt]=rt; int k=0; dfs2(rt,-1,k);}\r\
    \n    int lca(int u,int v){\r\n        for(;;v=par[hs[v]]){\r\n            if(in[u]>in[v])swap(u,v);\r\
    \n            if(hs[u]==hs[v])return u;\r\n        }\r\n    }\r\n    vector<P>\
    \ get(int u,int p,bool es=0){\r\n        assert(in[p]<=in[u] and out[u]<=out[p]);\r\
    \n        vector<P> res;\r\n        while(hs[u]!=hs[p]){\r\n            res.push_back({in[hs[u]],in[u]+1});\r\
    \n            u=par[hs[u]];\r\n        }\r\n        res.push_back({in[p]+es,in[u]+1});\r\
    \n        return res;\r\n    }\r\n    int jump(int u,int v,int k){\r\n       \
    \ if(k<0)return -1;\r\n        int g=lca(u,v);\r\n        int d0=dist[u]+dist[v]-dist[g]*2;\r\
    \n        if(d0<k)return -1;\r\n        int st=u;\r\n        if(dist[u]-dist[g]<k)st=v,k=d0-k;\r\
    \n        for(;;){\r\n            int to=hs[st];\r\n            if(in[st]-k>=in[to])return\
    \ rev[in[st]-k];\r\n            k-=in[st]-in[to]+1; st=par[to];\r\n        }\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/hld.hpp
  requiredBy:
  - Graph/contour.hpp
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_vertex_set_path_composite.test.cpp
  - Verify/LC_vertex_add_path_sum.test.cpp
  - Verify/LC_lca.test.cpp
  - Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
documentation_of: Graph/hld.hpp
layout: document
redirect_from:
- /library/Graph/hld.hpp
- /library/Graph/hld.hpp.html
title: Heavy Light Decomposition
---
