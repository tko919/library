---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: FPS/sumofpolyexp.hpp
    title: $\sum_{k} r^k\cdot poly(k)$
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
    document_title: interpolate (one point)
    links: []
  bundledCode: "#line 2 \"FPS/interpolate.hpp\"\n\ntemplate<typename T>T Interpolate(vector<T>&\
    \ ys,ll t){ // f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return\
    \ ys[t];\n    vector<T> L(d+1,1),R(d+1,1);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n\
    \    for(int i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n   \
    \     T add=ys[i]*L[i]*R[i]*Fact<T>(i,1)*Fact<T>(d-i,1);\n        if((d-i)&1)ret-=add;\n\
    \        else ret+=add;\n    }\n    return ret;\n}\n\n/**\n * @brief interpolate\
    \ (one point)\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>T Interpolate(vector<T>& ys,ll t){ //\
    \ f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return ys[t];\n  \
    \  vector<T> L(d+1,1),R(d+1,1);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n    for(int\
    \ i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n        T add=ys[i]*L[i]*R[i]*Fact<T>(i,1)*Fact<T>(d-i,1);\n\
    \        if((d-i)&1)ret-=add;\n        else ret+=add;\n    }\n    return ret;\n\
    }\n\n/**\n * @brief interpolate (one point)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/interpolate.hpp
  requiredBy:
  - FPS/sumofpolyexp.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: FPS/interpolate.hpp
layout: document
redirect_from:
- /library/FPS/interpolate.hpp
- /library/FPS/interpolate.hpp.html
title: interpolate (one point)
---
