---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/factorial.hpp
    title: Factorial
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Prefix Sum of Powers
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
    \ Factorial\n*/\n#line 3 \"FPS/prefixsumofpowers.hpp\"\n\ntemplate<typename T>vector<T>\
    \ PrefixSumOfPowers(ll n,int k){ // 0<=i<=k,sum_n=0^{N-1} n^i\n    factorial<T>\
    \ fact(k+2);\n    Poly<T> num(k+1),den(k+1);\n    num[0]=n,den[0]=1;\n    rep(i,0,k)num[i+1]=num[i]*n;\n\
    \    rep(i,0,k+1){\n        num[i]*=fact.fact(i+1,1);\n        den[i]=fact.fact(i+1,1);\n\
    \    }\n    num*=den.inv();\n    num.resize(k+1);\n    rep(i,0,k+1)num[i]*=fact.fact(i);\n\
    \    return num;\n}\n\n/**\n * @brief Prefix Sum of Powers\n*/\n"
  code: "#pragma once\n#include \"Math/factorial.hpp\"\n\ntemplate<typename T>vector<T>\
    \ PrefixSumOfPowers(ll n,int k){ // 0<=i<=k,sum_n=0^{N-1} n^i\n    factorial<T>\
    \ fact(k+2);\n    Poly<T> num(k+1),den(k+1);\n    num[0]=n,den[0]=1;\n    rep(i,0,k)num[i+1]=num[i]*n;\n\
    \    rep(i,0,k+1){\n        num[i]*=fact.fact(i+1,1);\n        den[i]=fact.fact(i+1,1);\n\
    \    }\n    num*=den.inv();\n    num.resize(k+1);\n    rep(i,0,k+1)num[i]*=fact.fact(i);\n\
    \    return num;\n}\n\n/**\n * @brief Prefix Sum of Powers\n*/"
  dependsOn:
  - Math/factorial.hpp
  isVerificationFile: false
  path: FPS/prefixsumofpowers.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/prefixsumofpowers.hpp
layout: document
redirect_from:
- /library/FPS/prefixsumofpowers.hpp
- /library/FPS/prefixsumofpowers.hpp.html
title: Prefix Sum of Powers
---
