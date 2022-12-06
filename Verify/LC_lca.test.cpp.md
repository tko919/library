---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Verify/LC_lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Graph/hld.hpp\"\n\r\nstruct\
    \ HLD{\r\n    using P=pair<int,int>;\r\n    vector<vector<int>> g; vector<int>\
    \ sz,in,out,rev,hs,par,dist;\r\n    void dfs(int v,int p){\r\n        par[v]=p;\
    \ sz[v]=1; dist[v]=dist[p]+1;\r\n        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\
    \n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\n        }\r\n    }\r\n\
    \    void dfs2(int v,int p,int& k){\r\n        in[v]=k++; rev[in[v]]=v;\r\n  \
    \      for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
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
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\n */\n#line\
    \ 5 \"Verify/LC_lca.test.cpp\"\n\r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\
    \n    HLD hld(n);\r\n    rep(i,1,n){\r\n        int p;\r\n        cin>>p;\r\n\
    \        hld.add_edge(i,p);\r\n    }\r\n    hld.run();\r\n    while(q--){\r\n\
    \        int x,y;\r\n        cin>>x>>y;\r\n        cout<<hld.lca(x,y)<<'\\n';\r\
    \n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    Template/template.hpp\"\r\n#include \"Graph/hld.hpp\"\r\n\r\nint main(){\r\n \
    \   int n,q;\r\n    cin>>n>>q;\r\n    HLD hld(n);\r\n    rep(i,1,n){\r\n     \
    \   int p;\r\n        cin>>p;\r\n        hld.add_edge(i,p);\r\n    }\r\n    hld.run();\r\
    \n    while(q--){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        cout<<hld.lca(x,y)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/hld.hpp
  isVerificationFile: true
  path: Verify/LC_lca.test.cpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_lca.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_lca.test.cpp
- /verify/Verify/LC_lca.test.cpp.html
title: Verify/LC_lca.test.cpp
---