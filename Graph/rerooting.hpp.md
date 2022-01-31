---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/AOJ_1595.test.cpp
    title: Verify/AOJ_1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Rerooting
    links: []
  bundledCode: "#line 2 \"Graph/rerooting.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,N),M (*g)(M,int),M (*h)(M,M),M (*e)()>struct Rerooting{\r\n    using\
    \ P=pair<int,N>;\r\n    vector<vector<P>> G;\r\n    vector<M> buf,ret;\r\n   \
    \ Rerooting(int n):G(n),buf(n,e()),ret(n){}\r\n    void add_edge(int u,int v,N\
    \ w){\r\n        G[u].push_back({v,w});\r\n        G[v].push_back({u,w});\r\n\
    \    }\r\n    void dfs1(int v,int p){\r\n        for(auto& [to,w]:G[v])if(to!=p){\r\
    \n            dfs1(to,v);\r\n            buf[v]=h(buf[v],f(buf[to],w));\r\n  \
    \     }\r\n       buf[v]=g(buf[v],v);\r\n    }\r\n    void dfs2(int v,int p,M\
    \ pc){\r\n        buf[v]=e();\r\n        vector<M> cs;\r\n        for(auto& [to,w]:G[v])if(to!=p){\r\
    \n            cs.push_back(f(buf[to],w));\r\n            buf[v]=h(buf[v],f(buf[to],w));\r\
    \n        }\r\n        buf[v]=g(h(buf[v],pc),v);\r\n        ret[v]=buf[v];\r\n\
    \        cs.push_back(pc);\r\n        int m=cs.size();\r\n        vector<M> L(m),R(m);\r\
    \n        rep(i,0,m){\r\n            L[i]=cs[i];\r\n            if(i)L[i]=h(L[i],L[i-1]);\r\
    \n        }\r\n        for(int i=m-1;i>=0;i--){\r\n            R[i]=cs[i];\r\n\
    \            if(i!=m-1)R[i]=h(R[i],R[i+1]);\r\n        }\r\n        int id=0;\r\
    \n        for(auto& [to,w]:G[v])if(to!=p){\r\n            M nxt=e();\r\n     \
    \       if(id!=0)nxt=h(nxt,L[id-1]);\r\n            if(id!=m-1)nxt=h(nxt,R[id+1]);\r\
    \n            M buf_v=buf[v],buf_to=buf[to];\r\n            buf[v]=g(nxt,v);\r\
    \n            M add=f(buf[v],w);\r\n            dfs2(to,v,add);\r\n          \
    \  buf[v]=buf_v,buf[to]=buf_to;\r\n            id++;\r\n        }\r\n    }\r\n\
    \    vector<M> run(){\r\n        dfs1(0,-1);\r\n        dfs2(0,-1,e());\r\n  \
    \      return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Rerooting\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,typename N,M (*f)(M,N),M (*g)(M,int),M\
    \ (*h)(M,M),M (*e)()>struct Rerooting{\r\n    using P=pair<int,N>;\r\n    vector<vector<P>>\
    \ G;\r\n    vector<M> buf,ret;\r\n    Rerooting(int n):G(n),buf(n,e()),ret(n){}\r\
    \n    void add_edge(int u,int v,N w){\r\n        G[u].push_back({v,w});\r\n  \
    \      G[v].push_back({u,w});\r\n    }\r\n    void dfs1(int v,int p){\r\n    \
    \    for(auto& [to,w]:G[v])if(to!=p){\r\n            dfs1(to,v);\r\n         \
    \   buf[v]=h(buf[v],f(buf[to],w));\r\n       }\r\n       buf[v]=g(buf[v],v);\r\
    \n    }\r\n    void dfs2(int v,int p,M pc){\r\n        buf[v]=e();\r\n       \
    \ vector<M> cs;\r\n        for(auto& [to,w]:G[v])if(to!=p){\r\n            cs.push_back(f(buf[to],w));\r\
    \n            buf[v]=h(buf[v],f(buf[to],w));\r\n        }\r\n        buf[v]=g(h(buf[v],pc),v);\r\
    \n        ret[v]=buf[v];\r\n        cs.push_back(pc);\r\n        int m=cs.size();\r\
    \n        vector<M> L(m),R(m);\r\n        rep(i,0,m){\r\n            L[i]=cs[i];\r\
    \n            if(i)L[i]=h(L[i],L[i-1]);\r\n        }\r\n        for(int i=m-1;i>=0;i--){\r\
    \n            R[i]=cs[i];\r\n            if(i!=m-1)R[i]=h(R[i],R[i+1]);\r\n  \
    \      }\r\n        int id=0;\r\n        for(auto& [to,w]:G[v])if(to!=p){\r\n\
    \            M nxt=e();\r\n            if(id!=0)nxt=h(nxt,L[id-1]);\r\n      \
    \      if(id!=m-1)nxt=h(nxt,R[id+1]);\r\n            M buf_v=buf[v],buf_to=buf[to];\r\
    \n            buf[v]=g(nxt,v);\r\n            M add=f(buf[v],w);\r\n         \
    \   dfs2(to,v,add);\r\n            buf[v]=buf_v,buf[to]=buf_to;\r\n          \
    \  id++;\r\n        }\r\n    }\r\n    vector<M> run(){\r\n        dfs1(0,-1);\r\
    \n        dfs2(0,-1,e());\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Rerooting\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/rerooting.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/AOJ_1595.test.cpp
documentation_of: Graph/rerooting.hpp
layout: document
redirect_from:
- /library/Graph/rerooting.hpp
- /library/Graph/rerooting.hpp.html
title: Rerooting
---
