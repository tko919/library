---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':warning:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':x:'
    path: Math/floorsum.hpp
    title: Floor Sum
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':heavy_check_mark:'
    path: Math/stirlingquery.hpp
    title: Stirling Number for query
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - icon: ':x:'
    path: Verify/LC_sum_of_floor_of_linear.test.cpp
    title: Verify/LC_sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - Math/floorsum.hpp
  - Math/stirlingquery.hpp
  - Math/primitive.hpp
  - Math/binomquery.hpp
  - Math/dynamic.hpp
  timestamp: '2022-12-28 03:34:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - Verify/LC_sum_of_floor_of_linear.test.cpp
documentation_of: Math/fastdiv.hpp
layout: document
redirect_from:
- /library/Math/fastdiv.hpp
- /library/Math/fastdiv.hpp.html
title: Math/fastdiv.hpp
---