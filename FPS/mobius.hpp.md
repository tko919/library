---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mobius Transform
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
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r, inv);\n\
    }\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T choose(int\
    \ n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return nCr<T>(n\
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"FPS/mobius.hpp\"\
    \n\ntemplate <typename T> Poly<T> comp_ApBx(const Poly<T> &f, T a, T b) { // f(a+bx)\n\
    \    auto g = f.shift(a.v);\n    T pw = 1;\n    for (auto &x : g) {\n        x\
    \ *= pw;\n        pw *= b;\n    }\n    return g;\n}\n\ntemplate <typename T>\n\
    Poly<T> Mobius(const Poly<T> &f, T a, T b, T c, T d) { // f((a+bx)/(c+dx))\n \
    \   assert(c != 0 or d != 0);\n    if (d == 0) {\n        T a_c = a / c, b_c =\
    \ b / c;\n        return comp_ApBx(f, a_c, b_c);\n    }\n    T p = b / d, q =\
    \ a - b * c / d;\n    auto g = comp_ApBx(f, p, q);\n    reverse(ALL(g));\n   \
    \ g = comp_ApBx(g, c, d);\n    int n = g.size();\n    Poly<T> den(n);\n    T cpw\
    \ = c.pow(n - 1), dpw = 1, cinv = c.inv();\n    rep(i, 0, n) {\n        den[i]\
    \ = cpw * dpw * nCr<T>(n - 1, i);\n        cpw *= cinv, dpw *= d;\n    }\n   \
    \ g *= den.inv();\n    g.resize(n);\n    return g;\n}\n\n/**\n * @brief Mobius\
    \ Transform\n */\n"
  code: "#pragma once\n#include \"Math/comb.hpp\"\n\ntemplate <typename T> Poly<T>\
    \ comp_ApBx(const Poly<T> &f, T a, T b) { // f(a+bx)\n    auto g = f.shift(a.v);\n\
    \    T pw = 1;\n    for (auto &x : g) {\n        x *= pw;\n        pw *= b;\n\
    \    }\n    return g;\n}\n\ntemplate <typename T>\nPoly<T> Mobius(const Poly<T>\
    \ &f, T a, T b, T c, T d) { // f((a+bx)/(c+dx))\n    assert(c != 0 or d != 0);\n\
    \    if (d == 0) {\n        T a_c = a / c, b_c = b / c;\n        return comp_ApBx(f,\
    \ a_c, b_c);\n    }\n    T p = b / d, q = a - b * c / d;\n    auto g = comp_ApBx(f,\
    \ p, q);\n    reverse(ALL(g));\n    g = comp_ApBx(g, c, d);\n    int n = g.size();\n\
    \    Poly<T> den(n);\n    T cpw = c.pow(n - 1), dpw = 1, cinv = c.inv();\n   \
    \ rep(i, 0, n) {\n        den[i] = cpw * dpw * nCr<T>(n - 1, i);\n        cpw\
    \ *= cinv, dpw *= d;\n    }\n    g *= den.inv();\n    g.resize(n);\n    return\
    \ g;\n}\n\n/**\n * @brief Mobius Transform\n */"
  dependsOn:
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/mobius.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/mobius.hpp
layout: document
redirect_from:
- /library/FPS/mobius.hpp
- /library/FPS/mobius.hpp.html
title: Mobius Transform
---
