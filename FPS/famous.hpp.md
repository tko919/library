---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FPS/prefixsumofpoly.hpp
    title: Prefix Sum of Polynomial
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Famous Sequence
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
    \ \"FPS/famous.hpp\"\n\ntemplate <typename T> vector<T> Bernoulli(int n) {\n \
    \   Poly<T> f(n + 1);\n    rep(i, 0, n + 1) f[i] = Fact<T>(i + 1, 1);\n    f =\
    \ f.inv();\n    rep(i, 0, n + 1) f[i] *= Fact<T>(i);\n    return f;\n}\n\ntemplate\
    \ <typename T> vector<T> Partition(int n) {\n    Poly<T> f(n + 1);\n    f[0] =\
    \ 1;\n    rep(k, 1, n + 1) {\n        if (1LL * k * (3 * k + 1) / 2 <= n)\n  \
    \          f[1LL * k * (3 * k + 1) / 2] += (k & 1 ? -1 : 1);\n        if (1LL\
    \ * k * (3 * k - 1) / 2 <= n)\n            f[1LL * k * (3 * k - 1) / 2] += (k\
    \ & 1 ? -1 : 1);\n    }\n    return f.inv();\n}\n\ntemplate <typename T> vector<T>\
    \ StirlingNumber1st(int n) {\n    if (n == 0)\n        return Poly<T>({T(1)});\n\
    \    Poly<T> f({T(0), T(1)});\n    for (int LG = topbit(n) - 1; LG >= 0; LG--)\
    \ {\n        int m = n >> LG;\n        f *= f.shift(m >> 1);\n        if (m &\
    \ 1)\n            f = (f << 1) + f * T(m - 1);\n    }\n    rep(i, 0, n + 1) if\
    \ ((n - i) & 1) f[i] = -f[i];\n    return f;\n}\n\ntemplate <typename T> vector<T>\
    \ StirlingNumber2nd(int n) {\n    if (n == 0)\n        return Poly<T>({T(1)});\n\
    \    Poly<T> f(n + 1), g(n + 1);\n    rep(i, 0, n + 1) {\n        f[i] = Fp(i).pow(n)\
    \ * Fact<T>(i, 1);\n        g[i] = Fact<T>(i, 1);\n        if (i & 1)\n      \
    \      g[i] = -g[i];\n    }\n    f *= g;\n    f.resize(n + 1);\n    return f;\n\
    }\n\ntemplate <typename T> vector<T> Bell(int n) {\n    Poly<T> f(n + 1);\n  \
    \  if (n)\n        f[1] = 1;\n    rep(i, 2, n + 1) f[i] = f[i - 1] / i;\n    f\
    \ = f.exp();\n    T fac = 1;\n    rep(i, 2, n + 1) fac *= i, f[i] *= fac;\n  \
    \  return f;\n}\n\n/**\n * @brief Famous Sequence\n */\n"
  code: "#pragma once\n#include \"Math/comb.hpp\"\n\ntemplate <typename T> vector<T>\
    \ Bernoulli(int n) {\n    Poly<T> f(n + 1);\n    rep(i, 0, n + 1) f[i] = Fact<T>(i\
    \ + 1, 1);\n    f = f.inv();\n    rep(i, 0, n + 1) f[i] *= Fact<T>(i);\n    return\
    \ f;\n}\n\ntemplate <typename T> vector<T> Partition(int n) {\n    Poly<T> f(n\
    \ + 1);\n    f[0] = 1;\n    rep(k, 1, n + 1) {\n        if (1LL * k * (3 * k +\
    \ 1) / 2 <= n)\n            f[1LL * k * (3 * k + 1) / 2] += (k & 1 ? -1 : 1);\n\
    \        if (1LL * k * (3 * k - 1) / 2 <= n)\n            f[1LL * k * (3 * k -\
    \ 1) / 2] += (k & 1 ? -1 : 1);\n    }\n    return f.inv();\n}\n\ntemplate <typename\
    \ T> vector<T> StirlingNumber1st(int n) {\n    if (n == 0)\n        return Poly<T>({T(1)});\n\
    \    Poly<T> f({T(0), T(1)});\n    for (int LG = topbit(n) - 1; LG >= 0; LG--)\
    \ {\n        int m = n >> LG;\n        f *= f.shift(m >> 1);\n        if (m &\
    \ 1)\n            f = (f << 1) + f * T(m - 1);\n    }\n    rep(i, 0, n + 1) if\
    \ ((n - i) & 1) f[i] = -f[i];\n    return f;\n}\n\ntemplate <typename T> vector<T>\
    \ StirlingNumber2nd(int n) {\n    if (n == 0)\n        return Poly<T>({T(1)});\n\
    \    Poly<T> f(n + 1), g(n + 1);\n    rep(i, 0, n + 1) {\n        f[i] = Fp(i).pow(n)\
    \ * Fact<T>(i, 1);\n        g[i] = Fact<T>(i, 1);\n        if (i & 1)\n      \
    \      g[i] = -g[i];\n    }\n    f *= g;\n    f.resize(n + 1);\n    return f;\n\
    }\n\ntemplate <typename T> vector<T> Bell(int n) {\n    Poly<T> f(n + 1);\n  \
    \  if (n)\n        f[1] = 1;\n    rep(i, 2, n + 1) f[i] = f[i - 1] / i;\n    f\
    \ = f.exp();\n    T fac = 1;\n    rep(i, 2, n + 1) fac *= i, f[i] *= fac;\n  \
    \  return f;\n}\n\n/**\n * @brief Famous Sequence\n */"
  dependsOn:
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/famous.hpp
  requiredBy:
  - FPS/prefixsumofpoly.hpp
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
documentation_of: FPS/famous.hpp
layout: document
redirect_from:
- /library/FPS/famous.hpp
- /library/FPS/famous.hpp.html
title: Famous Sequence
---
