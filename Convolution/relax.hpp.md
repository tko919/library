---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/factorial.hpp
    title: Factorial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Relaxed Convolution
    links: []
  bundledCode: "#line 2 \"Math/factorial.hpp\"\n\ntemplate<typename T>struct factorial\
    \ {\n    vector<T> Fact,Finv,Inv;\n    factorial(int maxx){\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\n\
    \        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=T(1)/Fact[maxx-1];\n\
    \        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\n\
    \    }\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\n\
    \    T inv(int n){if(n<0)return 0; return Inv[n];}\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\n   \
    \ T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\n\
    \    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\n};\n\n/**\n * @brief\
    \ Factorial\n*/\n#line 3 \"Convolution/relax.hpp\"\n\r\ntemplate<typename T>class\
    \ RelaxedConvolution{\r\n    using P=array<int,2>;\r\n    using Q=array<P,2>;\r\
    \n    int N,pos;\r\n    Poly<T> f,g,buf;\r\n    vector<vector<Q>> event;\r\n \
    \   void dfs1(int L,int R){\r\n        if(R-L==1){\r\n            event[L].push_back({P{L,L+1},P{0,1}});\r\
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
    \  }\r\npublic:\r\n    RelaxedConvolution(int n){\r\n        N=1,pos=0;\r\n  \
    \      while(N<n)N<<=1;\r\n        f.resize(N);\r\n        g.resize(N);\r\n  \
    \      buf.resize(N);\r\n        event.resize(N+1);\r\n        dfs(N);\r\n   \
    \ }\r\n    T next(T x,T y){\r\n        f[pos]=x,g[pos]=y;\r\n        for(auto&\
    \ [ft,gt]:event[pos]){\r\n            auto [fL,fR]=ft;\r\n            auto [gL,gR]=gt;\r\
    \n            Poly<T> _f({f.begin()+fL,f.begin()+fR});\r\n            Poly<T>\
    \ _g({g.begin()+gL,g.begin()+gR});\r\n            auto add=_f*_g;\r\n        \
    \    rep(i,0,add.size()){\r\n                if(i+fL+gL>=N)break;\r\n        \
    \        buf[i+fL+gL]+=add[i];\r\n            }\r\n        }\r\n        return\
    \ buf[pos++];\r\n    }\r\n};\r\n\r\ntemplate<typename T>struct RelaxedInv{\r\n\
    \    RelaxedInv(){}\r\n    RelaxedInv(int _n):n(_n),pos(0),g(n),buf(n){}\r\n \
    \   T next(T x){\r\n        if(pos==0){\r\n            assert(x!=0);\r\n     \
    \       g[pos]=x.inv();\r\n        }\r\n        else{\r\n            g[pos]=-g[0]*buf.next(x,g[pos-1]);\r\
    \n        }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i)const{return\
    \ g[i];}\r\nprivate:\r\n    int n,pos;\r\n    vector<T> g;\r\n    RelaxedConvolution<T>\
    \ buf;\r\n};\r\n\r\ntemplate<typename T>struct RelaxedExp{\r\n    RelaxedExp(){}\r\
    \n    RelaxedExp(int _n):n(_n),pos(0),g(n),fact(n),buf(n){}\r\n    T next(T x){\r\
    \n        if(pos==0){\r\n            assert(x==0);\r\n            g[pos]=1;\r\n\
    \        }\r\n        else{\r\n            g[pos]=buf.next(x*pos,g[pos-1])*fact.inv(pos);\r\
    \n        }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i)const{return\
    \ g[i];}\r\nprivate:\r\n    int n,pos;\r\n    vector<T> g;\r\n    factorial<T>\
    \ fact;\r\n    RelaxedConvolution<T> buf;\r\n};\r\n\r\ntemplate<typename T>struct\
    \ RelaxedLog{\r\n    RelaxedLog(){}\r\n    RelaxedLog(int _n):n(_n),pos(0),g(n),fact(n),buf(n),invf(n){}\r\
    \n    T next(T x){\r\n        invf.next(x);\r\n        if(pos==0){\r\n       \
    \     assert(x==1);\r\n            g[pos]=0;\r\n        }\r\n        else{\r\n\
    \            g[pos]=buf.next(x*pos,invf[pos-1])*fact.inv(pos);\r\n        }\r\n\
    \        return g[pos++];\r\n    }\r\n    T operator[](int i)const{return g[i];}\r\
    \nprivate:\r\n    int n,pos;\r\n    vector<T> g;\r\n    factorial<T> fact;\r\n\
    \    RelaxedConvolution<T> buf;\r\n    RelaxedInv<T> invf;\r\n};\r\n\r\n/**\r\n\
    \ * @brief Relaxed Convolution\r\n */\n"
  code: "#pragma once\r\n#include \"Math/factorial.hpp\"\r\n\r\ntemplate<typename\
    \ T>class RelaxedConvolution{\r\n    using P=array<int,2>;\r\n    using Q=array<P,2>;\r\
    \n    int N,pos;\r\n    Poly<T> f,g,buf;\r\n    vector<vector<Q>> event;\r\n \
    \   void dfs1(int L,int R){\r\n        if(R-L==1){\r\n            event[L].push_back({P{L,L+1},P{0,1}});\r\
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
    \  }\r\npublic:\r\n    RelaxedConvolution(int n){\r\n        N=1,pos=0;\r\n  \
    \      while(N<n)N<<=1;\r\n        f.resize(N);\r\n        g.resize(N);\r\n  \
    \      buf.resize(N);\r\n        event.resize(N+1);\r\n        dfs(N);\r\n   \
    \ }\r\n    T next(T x,T y){\r\n        f[pos]=x,g[pos]=y;\r\n        for(auto&\
    \ [ft,gt]:event[pos]){\r\n            auto [fL,fR]=ft;\r\n            auto [gL,gR]=gt;\r\
    \n            Poly<T> _f({f.begin()+fL,f.begin()+fR});\r\n            Poly<T>\
    \ _g({g.begin()+gL,g.begin()+gR});\r\n            auto add=_f*_g;\r\n        \
    \    rep(i,0,add.size()){\r\n                if(i+fL+gL>=N)break;\r\n        \
    \        buf[i+fL+gL]+=add[i];\r\n            }\r\n        }\r\n        return\
    \ buf[pos++];\r\n    }\r\n};\r\n\r\ntemplate<typename T>struct RelaxedInv{\r\n\
    \    RelaxedInv(){}\r\n    RelaxedInv(int _n):n(_n),pos(0),g(n),buf(n){}\r\n \
    \   T next(T x){\r\n        if(pos==0){\r\n            assert(x!=0);\r\n     \
    \       g[pos]=x.inv();\r\n        }\r\n        else{\r\n            g[pos]=-g[0]*buf.next(x,g[pos-1]);\r\
    \n        }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i)const{return\
    \ g[i];}\r\nprivate:\r\n    int n,pos;\r\n    vector<T> g;\r\n    RelaxedConvolution<T>\
    \ buf;\r\n};\r\n\r\ntemplate<typename T>struct RelaxedExp{\r\n    RelaxedExp(){}\r\
    \n    RelaxedExp(int _n):n(_n),pos(0),g(n),fact(n),buf(n){}\r\n    T next(T x){\r\
    \n        if(pos==0){\r\n            assert(x==0);\r\n            g[pos]=1;\r\n\
    \        }\r\n        else{\r\n            g[pos]=buf.next(x*pos,g[pos-1])*fact.inv(pos);\r\
    \n        }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i)const{return\
    \ g[i];}\r\nprivate:\r\n    int n,pos;\r\n    vector<T> g;\r\n    factorial<T>\
    \ fact;\r\n    RelaxedConvolution<T> buf;\r\n};\r\n\r\ntemplate<typename T>struct\
    \ RelaxedLog{\r\n    RelaxedLog(){}\r\n    RelaxedLog(int _n):n(_n),pos(0),g(n),fact(n),buf(n),invf(n){}\r\
    \n    T next(T x){\r\n        invf.next(x);\r\n        if(pos==0){\r\n       \
    \     assert(x==1);\r\n            g[pos]=0;\r\n        }\r\n        else{\r\n\
    \            g[pos]=buf.next(x*pos,invf[pos-1])*fact.inv(pos);\r\n        }\r\n\
    \        return g[pos++];\r\n    }\r\n    T operator[](int i)const{return g[i];}\r\
    \nprivate:\r\n    int n,pos;\r\n    vector<T> g;\r\n    factorial<T> fact;\r\n\
    \    RelaxedConvolution<T> buf;\r\n    RelaxedInv<T> invf;\r\n};\r\n\r\n/**\r\n\
    \ * @brief Relaxed Convolution\r\n */"
  dependsOn:
  - Math/factorial.hpp
  isVerificationFile: false
  path: Convolution/relax.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_convolution_mod_2.test.cpp
documentation_of: Convolution/relax.hpp
layout: document
redirect_from:
- /library/Convolution/relax.hpp
- /library/Convolution/relax.hpp.html
title: Relaxed Convolution
---
