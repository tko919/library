---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':heavy_check_mark:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':heavy_check_mark:'
    path: Math/stirlingquery.hpp
    title: Stirling Number for query
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_binomial_coefficient.test.cpp
    title: Verify/LC_binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * Fast Division\n\
    */\n"
  code: "#pragma once\n\nstruct FastDiv{\n    using u64=uint64_t;\n    using u128=__uint128_t;\n\
    \    constexpr FastDiv():m(),s(),x(){}\n    constexpr FastDiv(int _m)\n      \
    \  :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n    constexpr int get(){return\
    \ m;}\n    constexpr friend u64 operator/(u64 n,const FastDiv& d){\n        return\
    \ (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend int operator%(u64 n,const\
    \ FastDiv& d){\n        return n-n/d*d.m;\n    }\n    constexpr pair<u64,int>\
    \ divmod(u64 n)const{\n        u64 q=n/(*this);\n        return {q,n-q*m};\n \
    \   }\n    int m,s; u64 x;\n};\n\n/**\n * Fast Division\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/fastdiv.hpp
  requiredBy:
  - Convolution/multivariatecyclic.hpp
  - Math/stirlingquery.hpp
  - Math/dynamic.hpp
  - Math/binomquery.hpp
  - Math/primitive.hpp
  timestamp: '2022-12-28 03:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
documentation_of: Math/fastdiv.hpp
layout: document
redirect_from:
- /library/Math/fastdiv.hpp
- /library/Math/fastdiv.hpp.html
title: Math/fastdiv.hpp
---
