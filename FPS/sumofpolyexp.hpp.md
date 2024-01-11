---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: FPS/interpolate.hpp
    title: interpolate (one point)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: $\sum_{k} r^k\cdot poly(k)$
    links: []
  bundledCode: "#line 2 \"FPS/interpolate.hpp\"\n\ntemplate<typename T>T Interpolate(vector<T>&\
    \ ys,ll t){ // f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return\
    \ ys[t];\n    vector<T> L(d+1,1),R(d+1,1);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n\
    \    for(int i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n   \
    \     T add=ys[i]*L[i]*R[i]*Fact<T>(i,1)*Fact<T>(d-i,1);\n        if((d-i)&1)ret-=add;\n\
    \        else ret+=add;\n    }\n    return ret;\n}\n\n/**\n * @brief interpolate\
    \ (one point)\n*/\n#line 3 \"FPS/sumofpolyexp.hpp\"\n\ntemplate<typename T>T LimitSumOfPolyExp(vector<T>&\
    \ f,T r){ //sum_{k=0}^inf r^k*f(k)\n    assert(r!=1);\n    int d=f.size()-1;\n\
    \    vector<T> rs(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n    T c,add;\n\
    \    rep(i,0,d+1){\n        add+=rs[i]*f[i];\n        if((d-i)&1)c-=nCr<T>(d+1,i+1)*rs[d-i]*add;\n\
    \        else c+=nCr<T>(d+1,i+1)*rs[d-i]*add;\n    }\n    c/=(-r+1).pow(d+1);\n\
    \    return c;\n}\n\ntemplate<typename T>T SumOfPolyExp(vector<T>& f,T r,ll n){\
    \ //sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if(n<0)return 0;\n    int d=f.size()-1;\n\
    \    vector<T> rs(d+1),rui(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n\
    \    rep(i,0,d+1)rui[i]=rs[i]*f[i];\n    rep(i,0,d)rui[i+1]+=rui[i];\n    if(r==1)return\
    \ Interpolate(rui,n);\n    else{\n        T c;\n        rep(i,0,d+1)c+=nCr(d+1,i+1)*rs[d-i]*rui[i]*((d-i)&1?-1:1);\n\
    \        c/=T(-r+1).pow(d+1);\n        vector<T> ys(d+1);\n        T pwr=1,invr=T(r).inv();\n\
    \        rep(i,0,d+1)ys[i]=(rui[i]-c)*pwr,pwr*=invr;\n        return T(r).pow(n)*Interpolate(ys,n)+c;\n\
    \    }\n}\n\n/**\n * @brief $\\sum_{k} r^k\\cdot poly(k)$\n*/\n"
  code: "#pragma once\n#include \"FPS/interpolate.hpp\"\n\ntemplate<typename T>T LimitSumOfPolyExp(vector<T>&\
    \ f,T r){ //sum_{k=0}^inf r^k*f(k)\n    assert(r!=1);\n    int d=f.size()-1;\n\
    \    vector<T> rs(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n    T c,add;\n\
    \    rep(i,0,d+1){\n        add+=rs[i]*f[i];\n        if((d-i)&1)c-=nCr<T>(d+1,i+1)*rs[d-i]*add;\n\
    \        else c+=nCr<T>(d+1,i+1)*rs[d-i]*add;\n    }\n    c/=(-r+1).pow(d+1);\n\
    \    return c;\n}\n\ntemplate<typename T>T SumOfPolyExp(vector<T>& f,T r,ll n){\
    \ //sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if(n<0)return 0;\n    int d=f.size()-1;\n\
    \    vector<T> rs(d+1),rui(d+1);\n    rs[0]=1;\n    rep(i,0,d)rs[i+1]=rs[i]*r;\n\
    \    rep(i,0,d+1)rui[i]=rs[i]*f[i];\n    rep(i,0,d)rui[i+1]+=rui[i];\n    if(r==1)return\
    \ Interpolate(rui,n);\n    else{\n        T c;\n        rep(i,0,d+1)c+=nCr(d+1,i+1)*rs[d-i]*rui[i]*((d-i)&1?-1:1);\n\
    \        c/=T(-r+1).pow(d+1);\n        vector<T> ys(d+1);\n        T pwr=1,invr=T(r).inv();\n\
    \        rep(i,0,d+1)ys[i]=(rui[i]-c)*pwr,pwr*=invr;\n        return T(r).pow(n)*Interpolate(ys,n)+c;\n\
    \    }\n}\n\n/**\n * @brief $\\sum_{k} r^k\\cdot poly(k)$\n*/"
  dependsOn:
  - FPS/interpolate.hpp
  isVerificationFile: false
  path: FPS/sumofpolyexp.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
documentation_of: FPS/sumofpolyexp.hpp
layout: document
redirect_from:
- /library/FPS/sumofpolyexp.hpp
- /library/FPS/sumofpolyexp.hpp.html
title: $\sum_{k} r^k\cdot poly(k)$
---
