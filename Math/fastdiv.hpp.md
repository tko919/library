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
    document_title: Fast Division
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv {\n    using u64 =\
    \ uint64_t;\n    using u128 = __uint128_t;\n    constexpr FastDiv() : m(), s(),\
    \ x() {}\n    constexpr FastDiv(int _m)\n        : m(_m), s(__lg(m - 1)), x(((u128(1)\
    \ << (s + 64)) + m - 1) / m) {}\n    constexpr int get() {\n        return m;\n\
    \    }\n    constexpr friend u64 operator/(u64 n, const FastDiv &d) {\n      \
    \  return (u128(n) * d.x >> d.s) >> 64;\n    }\n    constexpr friend int operator%(u64\
    \ n, const FastDiv &d) {\n        return n - n / d * d.m;\n    }\n    constexpr\
    \ pair<u64, int> divmod(u64 n) const {\n        u64 q = n / (*this);\n       \
    \ return {q, n - q * m};\n    }\n    int m, s;\n    u64 x;\n};\n\nstruct FastDiv64\
    \ {\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n    u128 mod, mh,\
    \ ml;\n    explicit FastDiv64(u64 mod = 1) : mod(mod) {\n        u128 m = u128(-1)\
    \ / mod;\n        if (m * mod + mod == u128(0))\n            ++m;\n        mh\
    \ = m >> 64;\n        ml = m & u64(-1);\n    }\n    u64 umod() const {\n     \
    \   return mod;\n    }\n    u64 modulo(u128 x) {\n        u128 z = (x & u64(-1))\
    \ * ml;\n        z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n      \
    \  z = (x >> 64) * mh + (z >> 64);\n        x -= z * mod;\n        return x <\
    \ mod ? x : x - mod;\n    }\n    u64 mul(u64 a, u64 b) {\n        return modulo(u128(a)\
    \ * b);\n    }\n};\n\n/**\n * @brief Fast Division\n */\n"
  code: "#pragma once\n\nstruct FastDiv {\n    using u64 = uint64_t;\n    using u128\
    \ = __uint128_t;\n    constexpr FastDiv() : m(), s(), x() {}\n    constexpr FastDiv(int\
    \ _m)\n        : m(_m), s(__lg(m - 1)), x(((u128(1) << (s + 64)) + m - 1) / m)\
    \ {}\n    constexpr int get() {\n        return m;\n    }\n    constexpr friend\
    \ u64 operator/(u64 n, const FastDiv &d) {\n        return (u128(n) * d.x >> d.s)\
    \ >> 64;\n    }\n    constexpr friend int operator%(u64 n, const FastDiv &d) {\n\
    \        return n - n / d * d.m;\n    }\n    constexpr pair<u64, int> divmod(u64\
    \ n) const {\n        u64 q = n / (*this);\n        return {q, n - q * m};\n \
    \   }\n    int m, s;\n    u64 x;\n};\n\nstruct FastDiv64 {\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n    u128 mod, mh, ml;\n    explicit FastDiv64(u64\
    \ mod = 1) : mod(mod) {\n        u128 m = u128(-1) / mod;\n        if (m * mod\
    \ + mod == u128(0))\n            ++m;\n        mh = m >> 64;\n        ml = m &\
    \ u64(-1);\n    }\n    u64 umod() const {\n        return mod;\n    }\n    u64\
    \ modulo(u128 x) {\n        u128 z = (x & u64(-1)) * ml;\n        z = (x & u64(-1))\
    \ * mh + (x >> 64) * ml + (z >> 64);\n        z = (x >> 64) * mh + (z >> 64);\n\
    \        x -= z * mod;\n        return x < mod ? x : x - mod;\n    }\n    u64\
    \ mul(u64 a, u64 b) {\n        return modulo(u128(a) * b);\n    }\n};\n\n/**\n\
    \ * @brief Fast Division\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/fastdiv.hpp
  requiredBy:
  - Math/stirlingquery.hpp
  - Math/binomquery.hpp
  - Math/dynamic.hpp
  - Math/primitive.hpp
  - Convolution/multivariatecyclic.hpp
  timestamp: '2024-12-26 05:48:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - Verify/LC_discrete_logarithm_mod.test.cpp
documentation_of: Math/fastdiv.hpp
layout: document
redirect_from:
- /library/Math/fastdiv.hpp
- /library/Math/fastdiv.hpp.html
title: Fast Division
---
