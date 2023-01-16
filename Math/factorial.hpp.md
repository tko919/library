---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/relax.hpp
    title: Relaxed Convolution
  - icon: ':question:'
    path: FPS/famous.hpp
    title: FPS/famous.hpp
  - icon: ':heavy_check_mark:'
    path: FPS/interpolate.hpp
    title: interpolate (one point)
  - icon: ':warning:'
    path: FPS/p-recursive.hpp
    title: P-recursive
  - icon: ':warning:'
    path: FPS/prefixsumofpowers.hpp
    title: FPS/prefixsumofpowers.hpp
  - icon: ':heavy_check_mark:'
    path: FPS/samplepointshift.hpp
    title: Shift of Sampling Points of Polynomial
  - icon: ':heavy_check_mark:'
    path: FPS/sumofpolyexp.hpp
    title: $\sum_{k} r^k\cdot poly(k)$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1080.test.cpp
    title: Verify/YUKI_1080.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Factorial
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
    \ Factorial\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>struct factorial {\n    vector<T> Fact,Finv,Inv;\n\
    \    factorial(int maxx){\n        Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);\n\
    \        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;}\
    \ Finv[maxx-1]=T(1)/Fact[maxx-1];\n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i;\
    \ Inv[i]=Finv[i]*Fact[i-1];}\n    }\n    T fact(int n,bool inv=0){if(n<0)return\
    \ 0; return (inv?Finv[n]:Fact[n]);}\n    T inv(int n){if(n<0)return 0; return\
    \ Inv[n];}\n    T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return\
    \ fact(n,inv)*fact(n-r,inv^1);}\n    T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return\
    \ 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\n    T nHr(int n,int r,bool\
    \ inv=0){return nCr(n+r-1,r,inv);}\n};\n\n/**\n * @brief Factorial\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/factorial.hpp
  requiredBy:
  - FPS/famous.hpp
  - FPS/sumofpolyexp.hpp
  - FPS/interpolate.hpp
  - FPS/samplepointshift.hpp
  - FPS/p-recursive.hpp
  - FPS/prefixsumofpowers.hpp
  - Convolution/relax.hpp
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - Verify/YUKI_1080.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - Verify/LC_convolution_mod_2.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
documentation_of: Math/factorial.hpp
layout: document
redirect_from:
- /library/Math/factorial.hpp
- /library/Math/factorial.hpp.html
title: Factorial
---
