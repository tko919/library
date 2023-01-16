---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/factorial.hpp
    title: Factorial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ Factorial\n*/\n#line 3 \"FPS/famous.hpp\"\n\ntemplate<typename T>vector<T> Bernoulli(int\
    \ n){\n    factorial<T> fact(n+2);\n    Poly<T> f(n+1);\n    rep(i,0,n+1)f[i]=fact.fact(i+1,1);\n\
    \    f=f.inv();\n    rep(i,0,n+1)f[i]*=fact.fact(i);\n    return f;\n}\n\ntemplate<typename\
    \ T>vector<T> Partition(int n){\n    Poly<T> f(n+1);\n    f[0]=1;\n    rep(k,1,n+1){\n\
    \        if(1LL*k*(3*k+1)/2<=n)f[1LL*k*(3*k+1)/2]+=(k&1?-1:1);\n        if(1LL*k*(3*k-1)/2<=n)f[1LL*k*(3*k-1)/2]+=(k&1?-1:1);\n\
    \    }\n    return f.inv();\n}\n\ntemplate<typename T>vector<T> StirlingNumber1st(int\
    \ n){\n    if(n==0)return Poly<T>({T(1)});\n    Poly<T> f({T(0),T(1)});\n    for(int\
    \ LG=topbit(n)-1;LG>=0;LG--){\n        int m=n>>LG;\n        f*=f.shift(m>>1);\n\
    \        if(m&1)f=(f<<1)+f*T(m-1);\n    }\n    rep(i,0,n+1)if((n-i)&1)f[i]=-f[i];\n\
    \    return f;\n}\n\ntemplate<typename T>vector<T> StirlingNumber2nd(int n){\n\
    \    if(n==0)return Poly<T>({T(1)});\n    factorial<T> fact(n+1);\n    Poly<T>\
    \ f(n+1),g(n+1);\n    rep(i,0,n+1){\n        f[i]=Fp(i).pow(n)*fact.fact(i,1);\n\
    \        g[i]=fact.fact(i,1);\n        if(i&1)g[i]=-g[i];\n    }\n    f*=g;\n\
    \    f.resize(n+1);\n    return f;\n}\n\ntemplate<typename T>vector<T> Bell(int\
    \ n){\n    Poly<T> f(n+1);\n    if(n)f[1]=1;\n    rep(i,2,n+1)f[i]=f[i-1]/i;\n\
    \    f=f.exp();\n    T fac=1;\n    rep(i,2,n+1)fac*=i,f[i]*=fac;\n    return f;\n\
    }\n\n/**\n * Famous Sequence\n*/\n"
  code: "#pragma once\n#include \"Math/factorial.hpp\"\n\ntemplate<typename T>vector<T>\
    \ Bernoulli(int n){\n    factorial<T> fact(n+2);\n    Poly<T> f(n+1);\n    rep(i,0,n+1)f[i]=fact.fact(i+1,1);\n\
    \    f=f.inv();\n    rep(i,0,n+1)f[i]*=fact.fact(i);\n    return f;\n}\n\ntemplate<typename\
    \ T>vector<T> Partition(int n){\n    Poly<T> f(n+1);\n    f[0]=1;\n    rep(k,1,n+1){\n\
    \        if(1LL*k*(3*k+1)/2<=n)f[1LL*k*(3*k+1)/2]+=(k&1?-1:1);\n        if(1LL*k*(3*k-1)/2<=n)f[1LL*k*(3*k-1)/2]+=(k&1?-1:1);\n\
    \    }\n    return f.inv();\n}\n\ntemplate<typename T>vector<T> StirlingNumber1st(int\
    \ n){\n    if(n==0)return Poly<T>({T(1)});\n    Poly<T> f({T(0),T(1)});\n    for(int\
    \ LG=topbit(n)-1;LG>=0;LG--){\n        int m=n>>LG;\n        f*=f.shift(m>>1);\n\
    \        if(m&1)f=(f<<1)+f*T(m-1);\n    }\n    rep(i,0,n+1)if((n-i)&1)f[i]=-f[i];\n\
    \    return f;\n}\n\ntemplate<typename T>vector<T> StirlingNumber2nd(int n){\n\
    \    if(n==0)return Poly<T>({T(1)});\n    factorial<T> fact(n+1);\n    Poly<T>\
    \ f(n+1),g(n+1);\n    rep(i,0,n+1){\n        f[i]=Fp(i).pow(n)*fact.fact(i,1);\n\
    \        g[i]=fact.fact(i,1);\n        if(i&1)g[i]=-g[i];\n    }\n    f*=g;\n\
    \    f.resize(n+1);\n    return f;\n}\n\ntemplate<typename T>vector<T> Bell(int\
    \ n){\n    Poly<T> f(n+1);\n    if(n)f[1]=1;\n    rep(i,2,n+1)f[i]=f[i-1]/i;\n\
    \    f=f.exp();\n    T fac=1;\n    rep(i,2,n+1)fac*=i,f[i]*=fac;\n    return f;\n\
    }\n\n/**\n * Famous Sequence\n*/"
  dependsOn:
  - Math/factorial.hpp
  isVerificationFile: false
  path: FPS/famous.hpp
  requiredBy: []
  timestamp: '2023-01-17 00:59:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
documentation_of: FPS/famous.hpp
layout: document
redirect_from:
- /library/FPS/famous.hpp
- /library/FPS/famous.hpp.html
title: FPS/famous.hpp
---
