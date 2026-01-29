---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/wildcardpatternmatching.hpp
    title: Wildcard Pattern Matching
  - icon: ':question:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariate.hpp
    title: Multivariate Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':warning:'
    path: Math/bigint.hpp
    title: Big Integer(Float)
  - icon: ':heavy_check_mark:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':heavy_check_mark:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':warning:'
    path: Math/pisano.hpp
    title: Pisano Period
  - icon: ':question:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':heavy_check_mark:'
    path: Math/stirlingquery.hpp
    title: Stirling Number for query
  - icon: ':warning:'
    path: Math/twosquare.hpp
    title: Represent A Number As Two Square Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_binomial_coefficient.test.cpp
    title: Verify/LC_binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod.test.cpp
    title: Verify/LC_convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_1000000007.test.cpp
    title: Verify/LC_convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_exp_of_formal_power_series.test.cpp
    title: Verify/LC_exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_inv_of_formal_power_series.test.cpp
    title: Verify/LC_inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_log_of_formal_power_series.test.cpp
    title: Verify/LC_log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_many_factorials.test.cpp
    title: Verify/LC_many_factorials.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multipoint_evaluation.test.cpp
    title: Verify/LC_multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution.test.cpp
    title: Verify/LC_multivariate_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_polynomial_interpolation.test.cpp
    title: Verify/LC_polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_polynomial_taylor_shift.test.cpp
    title: Verify/LC_polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: Verify/LC_pow_of_formal_power_series.test.cpp
    title: Verify/LC_pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: Verify/LC_product_of_polynomial_sequence.test.cpp
    title: Verify/LC_product_of_polynomial_sequence.test.cpp
  - icon: ':x:'
    path: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: Verify/LC_sparse_matrix_det.test.cpp
    title: Verify/LC_sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1080.test.cpp
    title: Verify/YUKI_1080.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_2097.test.cpp
    title: Verify/YUKI_2097.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - Convolution/arbitrary.hpp
  - Convolution/ntt.hpp
  - Convolution/multivariatecyclic.hpp
  - Convolution/multivariate.hpp
  - Algorithm/wildcardpatternmatching.hpp
  - Math/stirlingquery.hpp
  - Math/primitive.hpp
  - Math/bigint.hpp
  - Math/pisano.hpp
  - Math/dynamic.hpp
  - Math/binomquery.hpp
  - Math/twosquare.hpp
  timestamp: '2024-12-26 05:48:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - Verify/LC_multivariate_convolution.test.cpp
  - Verify/LC_product_of_polynomial_sequence.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_convolution_mod_1000000007.test.cpp
  - Verify/YUKI_1080.test.cpp
  - Verify/LC_log_of_formal_power_series.test.cpp
  - Verify/LC_sparse_matrix_det.test.cpp
  - Verify/LC_convolution_mod_2.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/LC_polynomial_taylor_shift.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/LC_polynomial_interpolation.test.cpp
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - Verify/LC_exp_of_formal_power_series.test.cpp
  - Verify/LC_multipoint_evaluation.test.cpp
  - Verify/YUKI_2097.test.cpp
  - Verify/LC_convolution_mod.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - Verify/LC_pow_of_formal_power_series.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_inv_of_formal_power_series.test.cpp
  - Verify/LC_many_factorials.test.cpp
documentation_of: Math/fastdiv.hpp
layout: document
redirect_from:
- /library/Math/fastdiv.hpp
- /library/Math/fastdiv.hpp.html
title: Fast Division
---
