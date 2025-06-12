---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: FPS/interpolate.hpp
    title: interpolate (one point)
  - icon: ':question:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: $\sum_{k} r^k\cdot poly(k)$
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
    \ \"FPS/interpolate.hpp\"\n\n// f(0),..,f(d) -> f(t)\ntemplate <typename T> T\
    \ Interpolate(vector<T> &ys, ll t) {\n    int d = ys.size() - 1;\n    if (t <=\
    \ d)\n        return ys[t];\n    vector<T> L(d + 1, 1), R(d + 1, 1);\n    rep(i,\
    \ 0, d) L[i + 1] = L[i] * (t - i);\n    for (int i = d; i; i--)\n        R[i -\
    \ 1] = R[i] * (t - i);\n    T ret;\n    rep(i, 0, d + 1) {\n        T add = ys[i]\
    \ * L[i] * R[i] * Fact<T>(i, 1) * Fact<T>(d - i, 1);\n        if ((d - i) & 1)\n\
    \            ret -= add;\n        else\n            ret += add;\n    }\n    return\
    \ ret;\n}\n\n/**\n * @brief interpolate (one point)\n */\n#line 4 \"FPS/sumofpolyexp.hpp\"\
    \n\ntemplate <typename T>\nT LimitSumOfPolyExp(vector<T> &f, T r) { // sum_{k=0}^inf\
    \ r^k*f(k)\n    assert(r != 1);\n    int d = f.size() - 1;\n    vector<T> rs(d\
    \ + 1);\n    rs[0] = 1;\n    rep(i, 0, d) rs[i + 1] = rs[i] * r;\n    T c, add;\n\
    \    rep(i, 0, d + 1) {\n        add += rs[i] * f[i];\n        if ((d - i) & 1)\n\
    \            c -= nCr<T>(d + 1, i + 1) * rs[d - i] * add;\n        else\n    \
    \        c += nCr<T>(d + 1, i + 1) * rs[d - i] * add;\n    }\n    c /= (-r + 1).pow(d\
    \ + 1);\n    return c;\n}\n\ntemplate <typename T>\nT SumOfPolyExp(vector<T> &f,\
    \ T r, ll n) { // sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if (n < 0)\n       \
    \ return 0;\n    int d = f.size() - 1;\n    vector<T> rs(d + 1), rui(d + 1);\n\
    \    rs[0] = 1;\n    rep(i, 0, d) rs[i + 1] = rs[i] * r;\n    rep(i, 0, d + 1)\
    \ rui[i] = rs[i] * f[i];\n    rep(i, 0, d) rui[i + 1] += rui[i];\n    if (r ==\
    \ 0)\n        return f[0];\n    else if (r == 1)\n        return Interpolate(rui,\
    \ n);\n    else {\n        T c;\n        rep(i, 0, d + 1) c +=\n            nCr<T>(d\
    \ + 1, i + 1) * rs[d - i] * rui[i] * ((d - i) & 1 ? -1 : 1);\n        c /= T(-r\
    \ + 1).pow(d + 1);\n        vector<T> ys(d + 1);\n        T pwr = 1, invr = T(r).inv();\n\
    \        rep(i, 0, d + 1) ys[i] = (rui[i] - c) * pwr, pwr *= invr;\n        return\
    \ T(r).pow(n) * Interpolate(ys, n) + c;\n    }\n}\n\n/**\n * @brief $\\sum_{k}\
    \ r^k\\cdot poly(k)$\n */\n"
  code: "#pragma once\n#include \"FPS/interpolate.hpp\"\n#include \"Math/comb.hpp\"\
    \n\ntemplate <typename T>\nT LimitSumOfPolyExp(vector<T> &f, T r) { // sum_{k=0}^inf\
    \ r^k*f(k)\n    assert(r != 1);\n    int d = f.size() - 1;\n    vector<T> rs(d\
    \ + 1);\n    rs[0] = 1;\n    rep(i, 0, d) rs[i + 1] = rs[i] * r;\n    T c, add;\n\
    \    rep(i, 0, d + 1) {\n        add += rs[i] * f[i];\n        if ((d - i) & 1)\n\
    \            c -= nCr<T>(d + 1, i + 1) * rs[d - i] * add;\n        else\n    \
    \        c += nCr<T>(d + 1, i + 1) * rs[d - i] * add;\n    }\n    c /= (-r + 1).pow(d\
    \ + 1);\n    return c;\n}\n\ntemplate <typename T>\nT SumOfPolyExp(vector<T> &f,\
    \ T r, ll n) { // sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if (n < 0)\n       \
    \ return 0;\n    int d = f.size() - 1;\n    vector<T> rs(d + 1), rui(d + 1);\n\
    \    rs[0] = 1;\n    rep(i, 0, d) rs[i + 1] = rs[i] * r;\n    rep(i, 0, d + 1)\
    \ rui[i] = rs[i] * f[i];\n    rep(i, 0, d) rui[i + 1] += rui[i];\n    if (r ==\
    \ 0)\n        return f[0];\n    else if (r == 1)\n        return Interpolate(rui,\
    \ n);\n    else {\n        T c;\n        rep(i, 0, d + 1) c +=\n            nCr<T>(d\
    \ + 1, i + 1) * rs[d - i] * rui[i] * ((d - i) & 1 ? -1 : 1);\n        c /= T(-r\
    \ + 1).pow(d + 1);\n        vector<T> ys(d + 1);\n        T pwr = 1, invr = T(r).inv();\n\
    \        rep(i, 0, d + 1) ys[i] = (rui[i] - c) * pwr, pwr *= invr;\n        return\
    \ T(r).pow(n) * Interpolate(ys, n) + c;\n    }\n}\n\n/**\n * @brief $\\sum_{k}\
    \ r^k\\cdot poly(k)$\n */"
  dependsOn:
  - FPS/interpolate.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/sumofpolyexp.hpp
  requiredBy: []
  timestamp: '2025-05-11 13:37:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
documentation_of: FPS/sumofpolyexp.hpp
layout: document
redirect_from:
- /library/FPS/sumofpolyexp.hpp
- /library/FPS/sumofpolyexp.hpp.html
title: $\sum_{k} r^k\cdot poly(k)$
---
