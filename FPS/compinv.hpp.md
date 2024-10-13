---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/powenum.hpp
    title: Pow Enumerate
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Compositional Inverse
    links: []
  bundledCode: "#line 2 \"FPS/powenum.hpp\"\n\ntemplate <typename T>\nvector<T> PowEnumerate(Poly<T>\
    \ &f, Poly<T> &g,\n                       int m) { // sum_j g_j [x^j] f^i (i=0..m)\n\
    \    assert(f[0] == 0);\n    int n = 1;\n    while (n < SZ(f))\n        n <<=\
    \ 1;\n    int k = 1;\n    Poly<T> P(n * 2), Q(n * 2);\n    f.resize(n);\n    g.resize(n);\n\
    \    reverse(ALL(g));\n    rep(i, 0, n) P[i] = g[i];\n    rep(i, 1, n) Q[i] =\
    \ -f[i];\n\n    while (n > 1) {\n        auto R = Q;\n        rep(i, 0, SZ(R))\
    \ if (i & 1) R[i] = -R[i];\n        auto PR = P * R;\n        auto QR = Q * R;\n\
    \        PR.resize(4 * n * k);\n        QR.resize(4 * n * k);\n        rep(i,\
    \ 0, n * k * 2) {\n            PR[2 * n * k + i] += P[i];\n            QR[2 *\
    \ n * k + i] += Q[i] + R[i];\n        }\n        P.assign(n * 2 * k, 0);\n   \
    \     Q.assign(n * 2 * k, 0);\n        rep(j, 0, k * 2) rep(i, 0, n / 2) {\n \
    \           P[j * n + i] = PR[j * 2 * n + i * 2 + 1];\n            Q[j * n + i]\
    \ = QR[j * 2 * n + i * 2];\n        }\n        n >>= 1;\n        k <<= 1;\n  \
    \  }\n    vector<T> ret(k);\n    rep(i, 0, k) ret[i] = P[i * 2];\n    reverse(ALL(ret));\n\
    \    ret.resize(m + 1);\n    return ret;\n}\n\n/**\n * @brief Pow Enumerate\n\
    \ */\n#line 2 \"Math/comb.hpp\"\n\ntemplate <typename T> T Inv(ll n) {\n    static\
    \ int md;\n    static vector<T> buf({0, 1});\n    if (md != T::get_mod()) {\n\
    \        md = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n    assert(n\
    \ > 0);\n    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf), q\
    \ = (md + k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n  \
    \  return buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n \
    \   static int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md\
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
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 4 \"FPS/compinv.hpp\"\
    \n\ntemplate <typename T> Poly<T> CompositionInv(Poly<T> &f) {\n    assert(SZ(f)\
    \ >= 2 and f[0] == 0 and f[1] != 0);\n    const int n = f.deg();\n    const T\
    \ c = f[1];\n    const T invc = c.inv();\n    for (auto &x : f)\n        x *=\
    \ invc;\n    Poly<T> g(n + 1);\n    g[n] = 1;\n    auto ret = Poly<Fp>{PowEnumerate(f,\
    \ g, n)};\n    rep(i, 1, n + 1) ret[i] *= T(n) * Inv<T>(i);\n    reverse(ALL(ret));\n\
    \    ret[0] = 1;\n    ret = ret.log();\n    const T invn = T(1) / -n;\n    for\
    \ (auto &x : ret)\n        x *= invn;\n    ret = (ret.exp()) << 1;\n    ret.resize(n\
    \ + 1);\n    T buf = 1;\n    for (auto &x : ret) {\n        x *= buf;\n      \
    \  buf *= invc;\n    }\n    return ret;\n}\n\n/**\n * @brief Compositional Inverse\n\
    \ */\n"
  code: "#pragma once\n#include \"FPS/powenum.hpp\"\n#include \"Math/comb.hpp\"\n\n\
    template <typename T> Poly<T> CompositionInv(Poly<T> &f) {\n    assert(SZ(f) >=\
    \ 2 and f[0] == 0 and f[1] != 0);\n    const int n = f.deg();\n    const T c =\
    \ f[1];\n    const T invc = c.inv();\n    for (auto &x : f)\n        x *= invc;\n\
    \    Poly<T> g(n + 1);\n    g[n] = 1;\n    auto ret = Poly<Fp>{PowEnumerate(f,\
    \ g, n)};\n    rep(i, 1, n + 1) ret[i] *= T(n) * Inv<T>(i);\n    reverse(ALL(ret));\n\
    \    ret[0] = 1;\n    ret = ret.log();\n    const T invn = T(1) / -n;\n    for\
    \ (auto &x : ret)\n        x *= invn;\n    ret = (ret.exp()) << 1;\n    ret.resize(n\
    \ + 1);\n    T buf = 1;\n    for (auto &x : ret) {\n        x *= buf;\n      \
    \  buf *= invc;\n    }\n    return ret;\n}\n\n/**\n * @brief Compositional Inverse\n\
    \ */"
  dependsOn:
  - FPS/powenum.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/compinv.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/compinv.hpp
layout: document
redirect_from:
- /library/FPS/compinv.hpp
- /library/FPS/compinv.hpp.html
title: Compositional Inverse
---
