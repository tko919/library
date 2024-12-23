---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: FPS/sumofpolyexp.hpp
    title: $\sum_{k} r^k\cdot poly(k)$
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
    document_title: interpolate (one point)
    links: []
  bundledCode: "#line 2 \"Math/comb.hpp\"\n\ntemplate <typename T> T Inv(ll n) {\n\
    \    static int md;\n    static vector<T> buf({0, 1});\n    if (md != T::get_mod())\
    \ {\n        md = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n   \
    \ assert(n > 0);\n    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf),\
    \ q = (md + k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n\
    \    return buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n\
    \    static int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md\
    \ != T::get_mod()) {\n        md = T::get_mod();\n        buf = ibuf = vector<T>({1,\
    \ 1});\n    }\n    assert(n >= 0 and n < md);\n    while (SZ(buf) <= n) {\n  \
    \      buf.push_back(buf.back() * SZ(buf));\n        ibuf.push_back(ibuf.back()\
    \ * Inv<T>(SZ(ibuf)));\n    }\n    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate\
    \ <typename T> T nPr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r ||\
    \ r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^\
    \ 1);\n}\ntemplate <typename T> T nCr(int n, int r, bool inv = 0) {\n    if (n\
    \ < 0 || n < r || r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(r,\
    \ inv ^ 1) * Fact<T>(n - r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename\
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1,\
    \ inv);\n}\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T\
    \ choose(int n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return\
    \ nCr<T>(n + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3\
    \ \"FPS/interpolate.hpp\"\n\ntemplate<typename T>T Interpolate(vector<T>& ys,ll\
    \ t){ // f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return ys[t];\n\
    \    vector<T> L(d+1,1),R(d+1,1);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n    for(int\
    \ i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n        T add=ys[i]*L[i]*R[i]*Fact<T>(i,1)*Fact<T>(d-i,1);\n\
    \        if((d-i)&1)ret-=add;\n        else ret+=add;\n    }\n    return ret;\n\
    }\n\n/**\n * @brief interpolate (one point)\n*/\n"
  code: "#pragma once\n#include \"Math/comb.hpp\"\n\ntemplate<typename T>T Interpolate(vector<T>&\
    \ ys,ll t){ // f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return\
    \ ys[t];\n    vector<T> L(d+1,1),R(d+1,1);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n\
    \    for(int i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n   \
    \     T add=ys[i]*L[i]*R[i]*Fact<T>(i,1)*Fact<T>(d-i,1);\n        if((d-i)&1)ret-=add;\n\
    \        else ret+=add;\n    }\n    return ret;\n}\n\n/**\n * @brief interpolate\
    \ (one point)\n*/"
  dependsOn:
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/interpolate.hpp
  requiredBy:
  - FPS/sumofpolyexp.hpp
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
