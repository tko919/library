---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FPS/compinv.hpp
    title: Compositional Inverse
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pow Enumerate
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
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T>\nvector<T> PowEnumerate(Poly<T> &f,\
    \ Poly<T> &g,\n                       int m) { // sum_j g_j [x^j] f^i (i=0..m)\n\
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
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/powenum.hpp
  requiredBy:
  - FPS/compinv.hpp
  timestamp: '2024-04-30 04:21:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/powenum.hpp
layout: document
redirect_from:
- /library/FPS/powenum.hpp
- /library/FPS/powenum.hpp.html
title: Pow Enumerate
---
