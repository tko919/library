---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/factorial.hpp
    title: Factorial
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FPS/p-recursive.hpp
    title: P-recursive
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Shift of Sampling Points of Polynomial
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
    \ Factorial\n*/\n#line 3 \"FPS/samplepointshift.hpp\"\n\ntemplate<typename T>Poly<T>\
    \ SamplePointsShift(vector<T>& ys,T c,int m=-1){\n    ll n=ys.size()-1,C=c.v%T::get_mod();\n\
    \    if(m==-1)m=n+1;\n    factorial<T> fact(ys.size());\n    if(C<=n){\n     \
    \   Poly<T> res;\n        rep(i,C,n+1)res.push_back(ys[i]);\n        if(int(res.size())>=m){\n\
    \            res.resize(m);\n            return res;\n        }\n        auto\
    \ add=SamplePointsShift<T>(ys,n+1,m-res.size());\n        for(int i=0;int(res.size())<m;i++){\n\
    \            res.push_back(add[i]);\n        }\n        return res;\n    }\n \
    \   if(C+m>T::get_mod()){\n        auto res=SamplePointsShift<T>(ys,c,T::get_mod()-c.v);\n\
    \        auto add=SamplePointsShift<T>(ys,0,m-res.size());\n        rep(i,0,add.size())res.push_back(add[i]);\n\
    \        return res;\n    }\n\n    Poly<T> A(n+1),B(m+n);\n    rep(i,0,n+1){\n\
    \        A[i]=ys[i]*fact.fact(i,1)*fact.fact(n-i,1);\n        if((n-i)&1)A[i]=-A[i];\n\
    \    }\n    rep(i,0,m+n)B[i]=Fp(1)/(c-n+i);\n    auto AB=A*B;\n    vector<Fp>\
    \ res(m);\n    Fp base=1;\n    rep(x,0,n+1)base*=(c-x);\n    rep(i,0,m){\n   \
    \     res[i]=AB[n+i]*base;\n        base*=(c+i+1);\n        base*=B[i];\n    }\n\
    \    return res;\n}\n\n/**\n * @brief Shift of Sampling Points of Polynomial\n\
    */\n"
  code: "#pragma once\n#include \"Math/factorial.hpp\"\n\ntemplate<typename T>Poly<T>\
    \ SamplePointsShift(vector<T>& ys,T c,int m=-1){\n    ll n=ys.size()-1,C=c.v%T::get_mod();\n\
    \    if(m==-1)m=n+1;\n    factorial<T> fact(ys.size());\n    if(C<=n){\n     \
    \   Poly<T> res;\n        rep(i,C,n+1)res.push_back(ys[i]);\n        if(int(res.size())>=m){\n\
    \            res.resize(m);\n            return res;\n        }\n        auto\
    \ add=SamplePointsShift<T>(ys,n+1,m-res.size());\n        for(int i=0;int(res.size())<m;i++){\n\
    \            res.push_back(add[i]);\n        }\n        return res;\n    }\n \
    \   if(C+m>T::get_mod()){\n        auto res=SamplePointsShift<T>(ys,c,T::get_mod()-c.v);\n\
    \        auto add=SamplePointsShift<T>(ys,0,m-res.size());\n        rep(i,0,add.size())res.push_back(add[i]);\n\
    \        return res;\n    }\n\n    Poly<T> A(n+1),B(m+n);\n    rep(i,0,n+1){\n\
    \        A[i]=ys[i]*fact.fact(i,1)*fact.fact(n-i,1);\n        if((n-i)&1)A[i]=-A[i];\n\
    \    }\n    rep(i,0,m+n)B[i]=Fp(1)/(c-n+i);\n    auto AB=A*B;\n    vector<Fp>\
    \ res(m);\n    Fp base=1;\n    rep(x,0,n+1)base*=(c-x);\n    rep(i,0,m){\n   \
    \     res[i]=AB[n+i]*base;\n        base*=(c+i+1);\n        base*=B[i];\n    }\n\
    \    return res;\n}\n\n/**\n * @brief Shift of Sampling Points of Polynomial\n\
    */"
  dependsOn:
  - Math/factorial.hpp
  isVerificationFile: false
  path: FPS/samplepointshift.hpp
  requiredBy:
  - FPS/p-recursive.hpp
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: FPS/samplepointshift.hpp
layout: document
redirect_from:
- /library/FPS/samplepointshift.hpp
- /library/FPS/samplepointshift.hpp.html
title: Shift of Sampling Points of Polynomial
---
