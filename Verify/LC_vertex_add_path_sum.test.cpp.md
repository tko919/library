---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"Verify/LC_vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Graph/hld.hpp\"\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\
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
    \n */\n#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct BIT{\r\
    \n    int n; T all=0; vector<T> val;\r\n    BIT(int _n):n(_n),val(_n+10){}\r\n\
    \    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\n\
    \        for(i++;i<=n;i+=(i&-i))val[i]+=x;\r\n        all+=x;\r\n    }\r\n   \
    \ T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 6 \"Verify/LC_vertex_add_path_sum.test.cpp\"\
    \n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<int> a(N);\r\
    \n    rep(i,0,N)cin>>a[i];\r\n    HLD hld(N);\r\n    BIT<ll> bit(N);\r\n    rep(i,0,N-1){\r\
    \n        int x,y;\r\n        cin>>x>>y;\r\n        hld.add_edge(x,y);\r\n   \
    \ }\r\n    hld.run();\r\n    rep(i,0,N)bit.add(hld.in[i],a[i]);\r\n    while(Q--){\r\
    \n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n            int p,x;\r\
    \n            cin>>p>>x;\r\n            bit.add(hld.in[p],x);\r\n        }\r\n\
    \        else{\r\n            int u,v;\r\n            cin>>u>>v;\r\n         \
    \   int lca=hld.lca(u,v);\r\n            auto ps=hld.get(u,lca);\r\n         \
    \   ll ret=0;\r\n            for(auto& [L,R]:ps)ret+=bit.sum(L,R);\r\n       \
    \     ps=hld.get(v,lca,1);\r\n            for(auto& [L,R]:ps)ret+=bit.sum(L,R);\r\
    \n            cout<<ret<<'\\n';\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\
    \n\r\n#include \"Template/template.hpp\"\r\n#include \"Graph/hld.hpp\"\r\n#include\
    \ \"DataStructure/bit.hpp\"\r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\
    \n    vector<int> a(N);\r\n    rep(i,0,N)cin>>a[i];\r\n    HLD hld(N);\r\n   \
    \ BIT<ll> bit(N);\r\n    rep(i,0,N-1){\r\n        int x,y;\r\n        cin>>x>>y;\r\
    \n        hld.add_edge(x,y);\r\n    }\r\n    hld.run();\r\n    rep(i,0,N)bit.add(hld.in[i],a[i]);\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int p,x;\r\n            cin>>p>>x;\r\n            bit.add(hld.in[p],x);\r\
    \n        }\r\n        else{\r\n            int u,v;\r\n            cin>>u>>v;\r\
    \n            int lca=hld.lca(u,v);\r\n            auto ps=hld.get(u,lca);\r\n\
    \            ll ret=0;\r\n            for(auto& [L,R]:ps)ret+=bit.sum(L,R);\r\n\
    \            ps=hld.get(v,lca,1);\r\n            for(auto& [L,R]:ps)ret+=bit.sum(L,R);\r\
    \n            cout<<ret<<'\\n';\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/hld.hpp
  - DataStructure/bit.hpp
  isVerificationFile: true
  path: Verify/LC_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_vertex_add_path_sum.test.cpp
- /verify/Verify/LC_vertex_add_path_sum.test.cpp.html
title: Verify/LC_vertex_add_path_sum.test.cpp
---
