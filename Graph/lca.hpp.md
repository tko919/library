---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "#line 2 \"Graph/lca.hpp\"\n\r\nstruct LCA{\r\n    LCA(int _n=0):n(_n),g(_n),depth(_n+1,inf),start(_n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    void run(int root=0){\r\n        depth[root]=0;\r\n        dfs(root,-1);\r\
    \n        N=1;\r\n        while(N<int(euler.size()))N<<=1;\r\n        tree.resize(N*2,n);\r\
    \n        rep(i,0,euler.size())tree[N+i]=euler[i];\r\n        for(int i=N-1;i>0;i--)tree[i]=op(tree[i*2],tree[i*2+1]);\r\
    \n    }\r\n    int lca(int u,int v){\r\n        int a=start[u],b=start[v];\r\n\
    \        if(a>b)swap(a,b);\r\n        b++;\r\n        int res=n;\r\n        for(int\
    \ T=b-a;T>=1;T=b-a){\r\n            int x=a|((1U<<31)>>__builtin_clz(T));\r\n\
    \            int y=x&-x,k=__builtin_ctz(x);\r\n            res=op(res,tree[(N|a)>>k]);\r\
    \n            a+=y;\r\n        }\r\n        return res;\r\n    }\r\nprivate:\r\
    \n    int n,N;\r\n    vector<vector<int>> g;\r\n    vector<int> depth,start,euler,tree;\r\
    \n    void dfs(int v,int p){\r\n        start[v]=euler.size();\r\n        euler.push_back(v);\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n            depth[to]=depth[v]+1;\r\n\
    \            dfs(to,v);\r\n            euler.push_back(v);\r\n        }\r\n  \
    \  }\r\n    int op(int u,int v){\r\n        if(depth[u]<depth[v])return u;\r\n\
    \        else return v;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Lowest Common Ancestor\r\
    \n */\n"
  code: "#pragma once\r\n\r\nstruct LCA{\r\n    LCA(int _n=0):n(_n),g(_n),depth(_n+1,inf),start(_n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    void run(int root=0){\r\n        depth[root]=0;\r\n        dfs(root,-1);\r\
    \n        N=1;\r\n        while(N<int(euler.size()))N<<=1;\r\n        tree.resize(N*2,n);\r\
    \n        rep(i,0,euler.size())tree[N+i]=euler[i];\r\n        for(int i=N-1;i>0;i--)tree[i]=op(tree[i*2],tree[i*2+1]);\r\
    \n    }\r\n    int lca(int u,int v){\r\n        int a=start[u],b=start[v];\r\n\
    \        if(a>b)swap(a,b);\r\n        b++;\r\n        int res=n;\r\n        for(int\
    \ T=b-a;T>=1;T=b-a){\r\n            int x=a|((1U<<31)>>__builtin_clz(T));\r\n\
    \            int y=x&-x,k=__builtin_ctz(x);\r\n            res=op(res,tree[(N|a)>>k]);\r\
    \n            a+=y;\r\n        }\r\n        return res;\r\n    }\r\nprivate:\r\
    \n    int n,N;\r\n    vector<vector<int>> g;\r\n    vector<int> depth,start,euler,tree;\r\
    \n    void dfs(int v,int p){\r\n        start[v]=euler.size();\r\n        euler.push_back(v);\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n            depth[to]=depth[v]+1;\r\n\
    \            dfs(to,v);\r\n            euler.push_back(v);\r\n        }\r\n  \
    \  }\r\n    int op(int u,int v){\r\n        if(depth[u]<depth[v])return u;\r\n\
    \        else return v;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Lowest Common Ancestor\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lca.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/lca.hpp
layout: document
redirect_from:
- /library/Graph/lca.hpp
- /library/Graph/lca.hpp.html
title: Lowest Common Ancestor
---
