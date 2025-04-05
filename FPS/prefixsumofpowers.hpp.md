---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate $\sum_{k=0}^{N-1} k^i$
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
    \ \"FPS/prefixsumofpowers.hpp\"\n\ntemplate <typename T>\nvector<T> PrefixSumOfPowers(ll\
    \ n, int k) { // 0<=i<=k,sum_n=0^{N-1} n^i\n    Poly<T> num(k + 1), den(k + 1);\n\
    \    num[0] = n, den[0] = 1;\n    rep(i, 0, k) num[i + 1] = num[i] * n;\n    rep(i,\
    \ 0, k + 1) {\n        num[i] *= Fact<T>(i + 1, 1);\n        den[i] = Fact<T>(i\
    \ + 1, 1);\n    }\n    num *= den.inv();\n    num.resize(k + 1);\n    rep(i, 0,\
    \ k + 1) num[i] *= Fact<T>(i);\n    return num;\n}\n\n/**\n * @brief Enumerate\
    \ $\\sum_{k=0}^{N-1} k^i$\n */\n"
  code: "#pragma once\n#include \"Math/comb.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ PrefixSumOfPowers(ll n, int k) { // 0<=i<=k,sum_n=0^{N-1} n^i\n    Poly<T> num(k\
    \ + 1), den(k + 1);\n    num[0] = n, den[0] = 1;\n    rep(i, 0, k) num[i + 1]\
    \ = num[i] * n;\n    rep(i, 0, k + 1) {\n        num[i] *= Fact<T>(i + 1, 1);\n\
    \        den[i] = Fact<T>(i + 1, 1);\n    }\n    num *= den.inv();\n    num.resize(k\
    \ + 1);\n    rep(i, 0, k + 1) num[i] *= Fact<T>(i);\n    return num;\n}\n\n/**\n\
    \ * @brief Enumerate $\\sum_{k=0}^{N-1} k^i$\n */"
  dependsOn:
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/prefixsumofpowers.hpp
  requiredBy: []
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/prefixsumofpowers.hpp
layout: document
redirect_from:
- /library/FPS/prefixsumofpowers.hpp
- /library/FPS/prefixsumofpowers.hpp.html
title: Enumerate $\sum_{k=0}^{N-1} k^i$
---
