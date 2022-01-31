---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Relaxed Convolution
    links: []
  bundledCode: "#line 2 \"FPS/relax.hpp\"\n\r\ntemplate<typename T,typename poly>class\
    \ RelaxedConvolution{\r\n    using P=array<int,2>;\r\n    using Q=array<P,2>;\r\
    \n    int N,pos=0;\r\n    vector<vector<Q>> event;\r\n    void dfs1(int L,int\
    \ R){\r\n        if(R-L==1){\r\n            event[L].push_back({P{L,L+1},P{0,1}});\r\
    \n            return;\r\n        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{L,mid},P{mid-L,R-L}});\r\
    \n        event[R].push_back({P{mid,R},P{mid-L,R-L}});\r\n        dfs1(L,mid);\r\
    \n        dfs1(mid,R);\r\n    }\r\n    void dfs2(int L,int R){\r\n        if(R-L==1){\r\
    \n            event[L].push_back({P{0,1},P{L,L+1}});\r\n            return;\r\n\
    \        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{mid-L,R-L},P{L,mid}});\r\
    \n        event[R].push_back({P{mid-L,R-L},P{mid,R}});\r\n        dfs2(L,mid);\r\
    \n        dfs2(mid,R);\r\n    }\r\n    void dfs(int len){\r\n        if(len==1){\r\
    \n            event[0].push_back({P{0,1},P{0,1}});\r\n            return;\r\n\
    \        }\r\n        int mid=len>>1;\r\n        event[len].push_back({P{mid,len},P{mid,len}});\r\
    \n        dfs(mid);\r\n        dfs1(mid,len);\r\n        dfs2(mid,len);\r\n  \
    \  }\r\npublic:\r\n    poly f,g,buf;\r\n    RelaxedConvolution(int n){\r\n   \
    \     N=1;\r\n        while(N<n)N<<=1;\r\n        f.resize(N);\r\n        g.resize(N);\r\
    \n        buf.resize(N);\r\n        event.resize(N+1);\r\n        dfs(N);\r\n\
    \    }\r\n    T next(){\r\n        for(auto& [ft,gt]:event[pos]){\r\n        \
    \    auto [fL,fR]=ft;\r\n            auto [gL,gR]=gt;\r\n            poly _f({f.begin()+fL,f.begin()+fR});\r\
    \n            poly _g({g.begin()+gL,g.begin()+gR});\r\n            auto add=_f*_g;\r\
    \n            rep(i,0,add.size()){\r\n                if(i+fL+gL>=N)break;\r\n\
    \                buf[i+fL+gL]+=add[i];\r\n            }\r\n        }\r\n     \
    \   return buf[pos++];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Relaxed Convolution\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,typename poly>class RelaxedConvolution{\r\
    \n    using P=array<int,2>;\r\n    using Q=array<P,2>;\r\n    int N,pos=0;\r\n\
    \    vector<vector<Q>> event;\r\n    void dfs1(int L,int R){\r\n        if(R-L==1){\r\
    \n            event[L].push_back({P{L,L+1},P{0,1}});\r\n            return;\r\n\
    \        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{L,mid},P{mid-L,R-L}});\r\
    \n        event[R].push_back({P{mid,R},P{mid-L,R-L}});\r\n        dfs1(L,mid);\r\
    \n        dfs1(mid,R);\r\n    }\r\n    void dfs2(int L,int R){\r\n        if(R-L==1){\r\
    \n            event[L].push_back({P{0,1},P{L,L+1}});\r\n            return;\r\n\
    \        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{mid-L,R-L},P{L,mid}});\r\
    \n        event[R].push_back({P{mid-L,R-L},P{mid,R}});\r\n        dfs2(L,mid);\r\
    \n        dfs2(mid,R);\r\n    }\r\n    void dfs(int len){\r\n        if(len==1){\r\
    \n            event[0].push_back({P{0,1},P{0,1}});\r\n            return;\r\n\
    \        }\r\n        int mid=len>>1;\r\n        event[len].push_back({P{mid,len},P{mid,len}});\r\
    \n        dfs(mid);\r\n        dfs1(mid,len);\r\n        dfs2(mid,len);\r\n  \
    \  }\r\npublic:\r\n    poly f,g,buf;\r\n    RelaxedConvolution(int n){\r\n   \
    \     N=1;\r\n        while(N<n)N<<=1;\r\n        f.resize(N);\r\n        g.resize(N);\r\
    \n        buf.resize(N);\r\n        event.resize(N+1);\r\n        dfs(N);\r\n\
    \    }\r\n    T next(){\r\n        for(auto& [ft,gt]:event[pos]){\r\n        \
    \    auto [fL,fR]=ft;\r\n            auto [gL,gR]=gt;\r\n            poly _f({f.begin()+fL,f.begin()+fR});\r\
    \n            poly _g({g.begin()+gL,g.begin()+gR});\r\n            auto add=_f*_g;\r\
    \n            rep(i,0,add.size()){\r\n                if(i+fL+gL>=N)break;\r\n\
    \                buf[i+fL+gL]+=add[i];\r\n            }\r\n        }\r\n     \
    \   return buf[pos++];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Relaxed Convolution\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/relax.hpp
  requiredBy: []
  timestamp: '2022-01-31 01:12:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_convolution_mod_2.test.cpp
documentation_of: FPS/relax.hpp
layout: document
redirect_from:
- /library/FPS/relax.hpp
- /library/FPS/relax.hpp.html
title: Relaxed Convolution
---
