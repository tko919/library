---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':x:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':x:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':question:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':x:'
    path: Math/stirlingquery.hpp
    title: Stirling Number for query
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_binomial_coefficient.test.cpp
    title: Verify/LC_binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Fast Division
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv {\n    using u64 =\
    \ unsigned ll;\n    using u128 = __uint128_t;\n    u128 mod, mh, ml;\n    explicit\
    \ FastDiv(u64 mod = 1) : mod(mod) {\n        u128 m = u128(-1) / mod;\n      \
    \  if (m * mod + mod == u128(0))\n            ++m;\n        mh = m >> 64;\n  \
    \      ml = m & u64(-1);\n    }\n    u64 umod() const {\n        return mod;\n\
    \    }\n    u64 modulo(u128 x) {\n        u128 z = (x & u64(-1)) * ml;\n     \
    \   z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n        z = (x >> 64)\
    \ * mh + (z >> 64);\n        x -= z * mod;\n        return x < mod ? x : x - mod;\n\
    \    }\n    u64 mul(u64 a, u64 b) {\n        return modulo(u128(a) * b);\n   \
    \ }\n};\n\n/**\n * @brief Fast Division\n */\n"
  code: "#pragma once\n\nstruct FastDiv {\n    using u64 = unsigned ll;\n    using\
    \ u128 = __uint128_t;\n    u128 mod, mh, ml;\n    explicit FastDiv(u64 mod = 1)\
    \ : mod(mod) {\n        u128 m = u128(-1) / mod;\n        if (m * mod + mod ==\
    \ u128(0))\n            ++m;\n        mh = m >> 64;\n        ml = m & u64(-1);\n\
    \    }\n    u64 umod() const {\n        return mod;\n    }\n    u64 modulo(u128\
    \ x) {\n        u128 z = (x & u64(-1)) * ml;\n        z = (x & u64(-1)) * mh +\
    \ (x >> 64) * ml + (z >> 64);\n        z = (x >> 64) * mh + (z >> 64);\n     \
    \   x -= z * mod;\n        return x < mod ? x : x - mod;\n    }\n    u64 mul(u64\
    \ a, u64 b) {\n        return modulo(u128(a) * b);\n    }\n};\n\n/**\n * @brief\
    \ Fast Division\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/fastdiv.hpp
  requiredBy:
  - Convolution/multivariatecyclic.hpp
  - Math/dynamic.hpp
  - Math/stirlingquery.hpp
  - Math/primitive.hpp
  - Math/binomquery.hpp
  timestamp: '2024-12-24 03:24:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
documentation_of: Math/fastdiv.hpp
layout: document
redirect_from:
- /library/Math/fastdiv.hpp
- /library/Math/fastdiv.hpp.html
title: Fast Division
---
