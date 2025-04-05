---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/lca.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/YUKI_901.test.cpp
    title: Verify/YUKI_901.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Auxiliary Tree(Virtual Tree)
    links: []
  bundledCode: "#line 2 \"Graph/auxiliarytree.hpp\"\n\r\n#line 2 \"Graph/lca.hpp\"\
    \n\r\nstruct LCA{\r\n    LCA(int _n=0):n(_n),g(_n),depth(_n+1,inf),start(_n){}\r\
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
    \n */\n#line 4 \"Graph/auxiliarytree.hpp\"\nstruct AuxiliaryTree{\r\n    int n,pos;\r\
    \n    LCA lca;\r\n    vector<int> in,dep;\r\n    vector<vector<int>> _g,g;\r\n\
    \    AuxiliaryTree(int _n):n(_n),pos(0),lca(n),in(n),dep(n),_g(n),g(n){}\r\n \
    \   void add_edge(int u,int v){\r\n        lca.add_edge(u,v);\r\n        _g[u].push_back(v);\r\
    \n        _g[v].push_back(u);\r\n    }\r\n    void run(int root=0){\r\n      \
    \  lca.run(root);\r\n        dfs(root,-1);\r\n    }\r\n    void query(vector<int>&\
    \ vs){\r\n        sort(ALL(vs),[&](int u,int v){return in[u]<in[v];});\r\n   \
    \     vs.erase(unique(ALL(vs)),vs.end());\r\n        int m=vs.size();\r\n    \
    \    stack<int> st;\r\n        st.push(vs[0]);\r\n        rep(i,0,m-1){\r\n  \
    \          int w=lca.lca(vs[i],vs[i+1]);\r\n            if(w!=vs[i]){\r\n    \
    \            int cur=st.top();\r\n                st.pop();\r\n              \
    \  while(!st.empty() and dep[w]<dep[st.top()]){\r\n                    add(st.top(),cur);\r\
    \n                    cur=st.top();\r\n                    st.pop();\r\n     \
    \           }\r\n                if(st.empty() or st.top()!=w){\r\n          \
    \          st.push(w);\r\n                    vs.push_back(w);\r\n           \
    \     }\r\n                add(w,cur);\r\n            }\r\n            st.push(vs[i+1]);\r\
    \n        }\r\n        while(st.size()>1){\r\n            int c=st.top();\r\n\
    \            st.pop();\r\n            add(st.top(),c);\r\n        }\r\n    }\r\
    \n    void clear(vector<int>& vs){\r\n        for(auto& w:vs)g[w].clear();\r\n\
    \    }\r\nprivate:\r\n    void dfs(int v,int p){\r\n        in[v]=pos++;\r\n \
    \       for(auto& to:_g[v])if(to!=p){\r\n            dep[to]=dep[v]+1;\r\n   \
    \         dfs(to,v);\r\n        }\r\n    }\r\n    void add(int u,int v){\r\n \
    \       g[u].push_back(v);\r\n        g[v].push_back(u);\r\n    }\r\n};\r\n\r\n\
    /**\r\n * @brief Auxiliary Tree(Virtual Tree)\r\n */\n"
  code: "#pragma once\r\n\r\n#include \"Graph/lca.hpp\"\r\nstruct AuxiliaryTree{\r\
    \n    int n,pos;\r\n    LCA lca;\r\n    vector<int> in,dep;\r\n    vector<vector<int>>\
    \ _g,g;\r\n    AuxiliaryTree(int _n):n(_n),pos(0),lca(n),in(n),dep(n),_g(n),g(n){}\r\
    \n    void add_edge(int u,int v){\r\n        lca.add_edge(u,v);\r\n        _g[u].push_back(v);\r\
    \n        _g[v].push_back(u);\r\n    }\r\n    void run(int root=0){\r\n      \
    \  lca.run(root);\r\n        dfs(root,-1);\r\n    }\r\n    void query(vector<int>&\
    \ vs){\r\n        sort(ALL(vs),[&](int u,int v){return in[u]<in[v];});\r\n   \
    \     vs.erase(unique(ALL(vs)),vs.end());\r\n        int m=vs.size();\r\n    \
    \    stack<int> st;\r\n        st.push(vs[0]);\r\n        rep(i,0,m-1){\r\n  \
    \          int w=lca.lca(vs[i],vs[i+1]);\r\n            if(w!=vs[i]){\r\n    \
    \            int cur=st.top();\r\n                st.pop();\r\n              \
    \  while(!st.empty() and dep[w]<dep[st.top()]){\r\n                    add(st.top(),cur);\r\
    \n                    cur=st.top();\r\n                    st.pop();\r\n     \
    \           }\r\n                if(st.empty() or st.top()!=w){\r\n          \
    \          st.push(w);\r\n                    vs.push_back(w);\r\n           \
    \     }\r\n                add(w,cur);\r\n            }\r\n            st.push(vs[i+1]);\r\
    \n        }\r\n        while(st.size()>1){\r\n            int c=st.top();\r\n\
    \            st.pop();\r\n            add(st.top(),c);\r\n        }\r\n    }\r\
    \n    void clear(vector<int>& vs){\r\n        for(auto& w:vs)g[w].clear();\r\n\
    \    }\r\nprivate:\r\n    void dfs(int v,int p){\r\n        in[v]=pos++;\r\n \
    \       for(auto& to:_g[v])if(to!=p){\r\n            dep[to]=dep[v]+1;\r\n   \
    \         dfs(to,v);\r\n        }\r\n    }\r\n    void add(int u,int v){\r\n \
    \       g[u].push_back(v);\r\n        g[v].push_back(u);\r\n    }\r\n};\r\n\r\n\
    /**\r\n * @brief Auxiliary Tree(Virtual Tree)\r\n */"
  dependsOn:
  - Graph/lca.hpp
  isVerificationFile: false
  path: Graph/auxiliarytree.hpp
  requiredBy: []
  timestamp: '2022-10-17 02:55:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/YUKI_901.test.cpp
documentation_of: Graph/auxiliarytree.hpp
layout: document
redirect_from:
- /library/Graph/auxiliarytree.hpp
- /library/Graph/auxiliarytree.hpp.html
title: Auxiliary Tree(Virtual Tree)
---
