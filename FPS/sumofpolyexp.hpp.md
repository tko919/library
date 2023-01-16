---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/interpolate.hpp
    title: interpolate (one point)
  - icon: ':heavy_check_mark:'
    path: Math/factorial.hpp
    title: Factorial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: $\sum_{k} r^k\cdot poly(k)$
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
    \ Factorial\n*/\n#line 3 \"FPS/interpolate.hpp\"\n\ntemplate<typename T>T Interpolate(vector<T>&\
    \ ys,ll t){ // f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return\
    \ ys[t];\n    vector<T> L(d+1,1),R(d+1,1);\n    factorial<T> fact(d+2);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n\
    \    for(int i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n   \
    \     T add=ys[i]*L[i]*R[i]*fact.fact(i,1)*fact.fact(d-i,1);\n        if((d-i)&1)ret-=add;\n\
    \        else ret+=add;\n    }\n    return ret;\n}\n\n/**\n * @brief interpolate\
    \ (one point)\n*/\n#line 4 \"FPS/sumofpolyexp.hpp\"\n\ntemplate<typename T>T LimitSumOfPolyExp(vector<T>&\
    \ f,T r){ //sum_{k=0}^inf r^k*f(k)\n    assert(r!=1);\n    int d=f.size()-1;\n\
    \    factorial<T> fact(d+5);\n    vector<T> rs(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n\
    \    T c,add;\n    rep(i,0,d+1){\n        add+=rs[i]*f[i];\n        if((d-i)&1)c-=fact.nCr(d+1,i+1)*rs[d-i]*add;\n\
    \        else c+=fact.nCr(d+1,i+1)*rs[d-i]*add;\n    }\n    c/=(-r+1).pow(d+1);\n\
    \    return c;\n}\n\ntemplate<typename T>T SumOfPolyExp(vector<T>& f,T r,ll n){\
    \ //sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if(n<0)return 0;\n    int d=f.size()-1;\n\
    \    vector<T> rs(d+1),rui(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n\
    \    rep(i,0,d+1)rui[i]=rs[i]*f[i];\n    rep(i,0,d)rui[i+1]+=rui[i];\n    if(r==1)return\
    \ Interpolate(rui,n);\n    else{\n        factorial<T> fact(d+2);\n        T c;\n\
    \        rep(i,0,d+1)c+=fact.nCr(d+1,i+1)*rs[d-i]*rui[i]*((d-i)&1?-1:1);\n   \
    \     c/=T(-r+1).pow(d+1);\n        vector<T> ys(d+1);\n        T pwr=1,invr=T(r).inv();\n\
    \        rep(i,0,d+1)ys[i]=(rui[i]-c)*pwr,pwr*=invr;\n        return T(r).pow(n)*Interpolate(ys,n)+c;\n\
    \    }\n}\n\n/**\n * @brief $\\sum_{k} r^k\\cdot poly(k)$\n*/\n"
  code: "#pragma once\n#include \"Math/factorial.hpp\"\n#include \"FPS/interpolate.hpp\"\
    \n\ntemplate<typename T>T LimitSumOfPolyExp(vector<T>& f,T r){ //sum_{k=0}^inf\
    \ r^k*f(k)\n    assert(r!=1);\n    int d=f.size()-1;\n    factorial<T> fact(d+5);\n\
    \    vector<T> rs(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n    T c,add;\n\
    \    rep(i,0,d+1){\n        add+=rs[i]*f[i];\n        if((d-i)&1)c-=fact.nCr(d+1,i+1)*rs[d-i]*add;\n\
    \        else c+=fact.nCr(d+1,i+1)*rs[d-i]*add;\n    }\n    c/=(-r+1).pow(d+1);\n\
    \    return c;\n}\n\ntemplate<typename T>T SumOfPolyExp(vector<T>& f,T r,ll n){\
    \ //sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if(n<0)return 0;\n    int d=f.size()-1;\n\
    \    vector<T> rs(d+1),rui(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n\
    \    rep(i,0,d+1)rui[i]=rs[i]*f[i];\n    rep(i,0,d)rui[i+1]+=rui[i];\n    if(r==1)return\
    \ Interpolate(rui,n);\n    else{\n        factorial<T> fact(d+2);\n        T c;\n\
    \        rep(i,0,d+1)c+=fact.nCr(d+1,i+1)*rs[d-i]*rui[i]*((d-i)&1?-1:1);\n   \
    \     c/=T(-r+1).pow(d+1);\n        vector<T> ys(d+1);\n        T pwr=1,invr=T(r).inv();\n\
    \        rep(i,0,d+1)ys[i]=(rui[i]-c)*pwr,pwr*=invr;\n        return T(r).pow(n)*Interpolate(ys,n)+c;\n\
    \    }\n}\n\n/**\n * @brief $\\sum_{k} r^k\\cdot poly(k)$\n*/"
  dependsOn:
  - Math/factorial.hpp
  - FPS/interpolate.hpp
  isVerificationFile: false
  path: FPS/sumofpolyexp.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: FPS/sumofpolyexp.hpp
layout: document
redirect_from:
- /library/FPS/sumofpolyexp.hpp
- /library/FPS/sumofpolyexp.hpp.html
title: $\sum_{k} r^k\cdot poly(k)$
---
