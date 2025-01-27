---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/relax.hpp
    title: Relaxed Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/subset.hpp
    title: Subset Convolution
  - icon: ':warning:'
    path: FPS/compexp.hpp
    title: $f(\exp(x))$
  - icon: ':warning:'
    path: FPS/compinv.hpp
    title: Compositional Inverse
  - icon: ':heavy_check_mark:'
    path: FPS/factlarge.hpp
    title: Factorial (Large)
  - icon: ':heavy_check_mark:'
    path: FPS/famous.hpp
    title: Famous Sequence
  - icon: ':warning:'
    path: FPS/incseqcount.hpp
    title: Number of Increasing Sequences Between Two Sequences
  - icon: ':heavy_check_mark:'
    path: FPS/interpolate.hpp
    title: interpolate (one point)
  - icon: ':warning:'
    path: FPS/mobius.hpp
    title: Mobius Transform
  - icon: ':warning:'
    path: FPS/p-recursive.hpp
    title: P-recursive
  - icon: ':warning:'
    path: FPS/prefixsumofpoly.hpp
    title: Prefix Sum of Polynomial
  - icon: ':warning:'
    path: FPS/prefixsumofpowers.hpp
    title: Enumerate $\sum_{k=0}^{N-1} k^i$
  - icon: ':heavy_check_mark:'
    path: FPS/samplepointshift.hpp
    title: Shift of Sampling Points of Polynomial
  - icon: ':heavy_check_mark:'
    path: FPS/sumofpolyexp.hpp
    title: $\sum_{k} r^k\cdot poly(k)$
  - icon: ':warning:'
    path: Graph/chromaticpoly.hpp
    title: Chromatic Number
  - icon: ':heavy_check_mark:'
    path: Math/hafnian.hpp
    title: Hafnian of matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_hafnian_of_matrix.test.cpp
    title: Verify/LC_hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_many_factorials.test.cpp
    title: Verify/LC_many_factorials.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_subset_convolution.test.cpp
    title: Verify/LC_subset_convolution.test.cpp
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
    path: Verify/YUKI_2097.test.cpp
    title: Verify/YUKI_2097.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Combination
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
    \ nCr<T>(n + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n"
  code: "#pragma once\n\ntemplate <typename T> T Inv(ll n) {\n    static int md;\n\
    \    static vector<T> buf({0, 1});\n    if (md != T::get_mod()) {\n        md\
    \ = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n    assert(n > 0);\n\
    \    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf), q = (md +\
    \ k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n    return\
    \ buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n    static\
    \ int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md != T::get_mod())\
    \ {\n        md = T::get_mod();\n        buf = ibuf = vector<T>({1, 1});\n   \
    \ }\n    assert(n >= 0 and n < md);\n    while (SZ(buf) <= n) {\n        buf.push_back(buf.back()\
    \ * SZ(buf));\n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\n    }\n\
    \    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate <typename T> T nPr(int n, int\
    \ r, bool inv = 0) {\n    if (n < 0 || n < r || r < 0)\n        return 0;\n  \
    \  return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\n}\ntemplate <typename T>\
    \ T nCr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r || r < 0)\n    \
    \    return 0;\n    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n -\
    \ r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename T> T nHr(int n, int\
    \ r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1, inv);\n}\n// sum = n,\
    \ a nonzero tuples and b tuples\ntemplate <typename T> T choose(int n, int a,\
    \ int b) {\n    if (n == 0)\n        return !a;\n    return nCr<T>(n + b - 1,\
    \ a + b - 1);\n}\n\n/**\n * @brief Combination\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/comb.hpp
  requiredBy:
  - Math/hafnian.hpp
  - FPS/incseqcount.hpp
  - FPS/compinv.hpp
  - FPS/mobius.hpp
  - FPS/factlarge.hpp
  - FPS/prefixsumofpowers.hpp
  - FPS/compexp.hpp
  - FPS/prefixsumofpoly.hpp
  - FPS/samplepointshift.hpp
  - FPS/p-recursive.hpp
  - FPS/famous.hpp
  - FPS/interpolate.hpp
  - FPS/sumofpolyexp.hpp
  - Graph/chromaticpoly.hpp
  - Convolution/subset.hpp
  - Convolution/relax.hpp
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_subset_convolution.test.cpp
  - Verify/LC_hafnian_of_matrix.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - Verify/LC_many_factorials.test.cpp
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/YUKI_2097.test.cpp
  - Verify/LC_convolution_mod_2.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/YUKI_1080.test.cpp
documentation_of: Math/comb.hpp
layout: document
redirect_from:
- /library/Math/comb.hpp
- /library/Math/comb.hpp.html
title: Combination
---
