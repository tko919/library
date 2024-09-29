---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FPS/prefixsumofpoly.hpp
    title: Prefix Sum of Polynomial
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Famous Sequence
    links: []
  bundledCode: "#line 2 \"FPS/famous.hpp\"\n\ntemplate<typename T>vector<T> Bernoulli(int\
    \ n){\n    Poly<T> f(n+1);\n    rep(i,0,n+1)f[i]=Fact<T>(i+1,1);\n    f=f.inv();\n\
    \    rep(i,0,n+1)f[i]*=Fact<T>(i);\n    return f;\n}\n\ntemplate<typename T>vector<T>\
    \ Partition(int n){\n    Poly<T> f(n+1);\n    f[0]=1;\n    rep(k,1,n+1){\n   \
    \     if(1LL*k*(3*k+1)/2<=n)f[1LL*k*(3*k+1)/2]+=(k&1?-1:1);\n        if(1LL*k*(3*k-1)/2<=n)f[1LL*k*(3*k-1)/2]+=(k&1?-1:1);\n\
    \    }\n    return f.inv();\n}\n\ntemplate<typename T>vector<T> StirlingNumber1st(int\
    \ n){\n    if(n==0)return Poly<T>({T(1)});\n    Poly<T> f({T(0),T(1)});\n    for(int\
    \ LG=topbit(n)-1;LG>=0;LG--){\n        int m=n>>LG;\n        f*=f.shift(m>>1);\n\
    \        if(m&1)f=(f<<1)+f*T(m-1);\n    }\n    rep(i,0,n+1)if((n-i)&1)f[i]=-f[i];\n\
    \    return f;\n}\n\ntemplate<typename T>vector<T> StirlingNumber2nd(int n){\n\
    \    if(n==0)return Poly<T>({T(1)});\n    Poly<T> f(n+1),g(n+1);\n    rep(i,0,n+1){\n\
    \        f[i]=Fp(i).pow(n)*Fact<T>(i,1);\n        g[i]=Fact<T>(i,1);\n       \
    \ if(i&1)g[i]=-g[i];\n    }\n    f*=g;\n    f.resize(n+1);\n    return f;\n}\n\
    \ntemplate<typename T>vector<T> Bell(int n){\n    Poly<T> f(n+1);\n    if(n)f[1]=1;\n\
    \    rep(i,2,n+1)f[i]=f[i-1]/i;\n    f=f.exp();\n    T fac=1;\n    rep(i,2,n+1)fac*=i,f[i]*=fac;\n\
    \    return f;\n}\n\n/**\n * @brief Famous Sequence\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>vector<T> Bernoulli(int n){\n    Poly<T>\
    \ f(n+1);\n    rep(i,0,n+1)f[i]=Fact<T>(i+1,1);\n    f=f.inv();\n    rep(i,0,n+1)f[i]*=Fact<T>(i);\n\
    \    return f;\n}\n\ntemplate<typename T>vector<T> Partition(int n){\n    Poly<T>\
    \ f(n+1);\n    f[0]=1;\n    rep(k,1,n+1){\n        if(1LL*k*(3*k+1)/2<=n)f[1LL*k*(3*k+1)/2]+=(k&1?-1:1);\n\
    \        if(1LL*k*(3*k-1)/2<=n)f[1LL*k*(3*k-1)/2]+=(k&1?-1:1);\n    }\n    return\
    \ f.inv();\n}\n\ntemplate<typename T>vector<T> StirlingNumber1st(int n){\n   \
    \ if(n==0)return Poly<T>({T(1)});\n    Poly<T> f({T(0),T(1)});\n    for(int LG=topbit(n)-1;LG>=0;LG--){\n\
    \        int m=n>>LG;\n        f*=f.shift(m>>1);\n        if(m&1)f=(f<<1)+f*T(m-1);\n\
    \    }\n    rep(i,0,n+1)if((n-i)&1)f[i]=-f[i];\n    return f;\n}\n\ntemplate<typename\
    \ T>vector<T> StirlingNumber2nd(int n){\n    if(n==0)return Poly<T>({T(1)});\n\
    \    Poly<T> f(n+1),g(n+1);\n    rep(i,0,n+1){\n        f[i]=Fp(i).pow(n)*Fact<T>(i,1);\n\
    \        g[i]=Fact<T>(i,1);\n        if(i&1)g[i]=-g[i];\n    }\n    f*=g;\n  \
    \  f.resize(n+1);\n    return f;\n}\n\ntemplate<typename T>vector<T> Bell(int\
    \ n){\n    Poly<T> f(n+1);\n    if(n)f[1]=1;\n    rep(i,2,n+1)f[i]=f[i-1]/i;\n\
    \    f=f.exp();\n    T fac=1;\n    rep(i,2,n+1)fac*=i,f[i]*=fac;\n    return f;\n\
    }\n\n/**\n * @brief Famous Sequence\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/famous.hpp
  requiredBy:
  - FPS/prefixsumofpoly.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_bernoulli_number.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
documentation_of: FPS/famous.hpp
layout: document
redirect_from:
- /library/FPS/famous.hpp
- /library/FPS/famous.hpp.html
title: Famous Sequence
---
