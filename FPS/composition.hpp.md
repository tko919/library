---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Composition of Formal Power Series
    links: []
  bundledCode: "#line 2 \"FPS/composition.hpp\"\n\ntemplate <typename T> Poly<T> Composition(Poly<T>\
    \ &f, Poly<T> &g) {\n    assert(SZ(f) == SZ(g) and g[0] == 0);\n\n    auto dfs\
    \ = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {\n        if (n == 1)\
    \ {\n            reverse(ALL(f));\n            Poly<T> P(k * 2);\n           \
    \ rep(i, 0, k) P[i * 2] = f[i];\n            return P;\n        }\n        int\
    \ n2 = n >> 1, k2 = k << 1;\n\n        auto R = Q;\n        rep(i, 0, 2 * n *\
    \ k) if (i & 1) R[i] = -R[i];\n        auto QR = Q * R;\n        QR.resize(4 *\
    \ n * k);\n        rep(i, 0, 2 * n * k) QR[2 * n * k + i] += Q[i] + R[i];\n  \
    \      Poly<T> nQ(2 * n * k);\n        rep(i, 0, k2) rep(j, 0, n2) nQ[n * i +\
    \ j] = QR[2 * n * i + 2 * j];\n\n        auto nP = dfs(dfs, n2, k2, nQ);\n   \
    \     Poly<T> PR(4 * n * k);\n        rep(i, 0, k2) rep(j, 0, n2) PR[2 * n * i\
    \ + 2 * j + 1] = nP[n * i + j];\n        Poly<T> P(2 * n * k);\n        rep(i,\
    \ 0, 2 * n * k) P[i] += PR[2 * n * k + i];\n        // middle product\n      \
    \  const int M = R.deg();\n        reverse(ALL(R));\n        R.resize(4 * n *\
    \ k);\n        PR.NTT(0);\n        R.NTT(0);\n        rep(i, 0, 4 * n * k) PR[i]\
    \ *= R[i];\n        PR.NTT(1);\n        rep(i, 0, 2 * n * k) P[i] += PR[i + M];\n\
    \        return P;\n    };\n\n    int n = SZ(f), N = 1;\n    while (N < n)\n \
    \       N <<= 1;\n    f.resize(N);\n    g.resize(N);\n    int k = 1;\n    Poly<T>\
    \ Q(N * 2);\n    rep(i, 0, n) Q[i] = -g[i];\n    auto P = dfs(dfs, N, k, Q);\n\
    \    Poly<T> ret(n);\n    rep(i, 0, n) ret[i] = P[N - 1 - i];\n    return ret;\n\
    };\n\n/**\n * @brief Composition of Formal Power Series\n */\n"
  code: "#pragma once\n\ntemplate <typename T> Poly<T> Composition(Poly<T> &f, Poly<T>\
    \ &g) {\n    assert(SZ(f) == SZ(g) and g[0] == 0);\n\n    auto dfs = [&](auto\
    \ &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {\n        if (n == 1) {\n      \
    \      reverse(ALL(f));\n            Poly<T> P(k * 2);\n            rep(i, 0,\
    \ k) P[i * 2] = f[i];\n            return P;\n        }\n        int n2 = n >>\
    \ 1, k2 = k << 1;\n\n        auto R = Q;\n        rep(i, 0, 2 * n * k) if (i &\
    \ 1) R[i] = -R[i];\n        auto QR = Q * R;\n        QR.resize(4 * n * k);\n\
    \        rep(i, 0, 2 * n * k) QR[2 * n * k + i] += Q[i] + R[i];\n        Poly<T>\
    \ nQ(2 * n * k);\n        rep(i, 0, k2) rep(j, 0, n2) nQ[n * i + j] = QR[2 * n\
    \ * i + 2 * j];\n\n        auto nP = dfs(dfs, n2, k2, nQ);\n        Poly<T> PR(4\
    \ * n * k);\n        rep(i, 0, k2) rep(j, 0, n2) PR[2 * n * i + 2 * j + 1] = nP[n\
    \ * i + j];\n        Poly<T> P(2 * n * k);\n        rep(i, 0, 2 * n * k) P[i]\
    \ += PR[2 * n * k + i];\n        // middle product\n        const int M = R.deg();\n\
    \        reverse(ALL(R));\n        R.resize(4 * n * k);\n        PR.NTT(0);\n\
    \        R.NTT(0);\n        rep(i, 0, 4 * n * k) PR[i] *= R[i];\n        PR.NTT(1);\n\
    \        rep(i, 0, 2 * n * k) P[i] += PR[i + M];\n        return P;\n    };\n\n\
    \    int n = SZ(f), N = 1;\n    while (N < n)\n        N <<= 1;\n    f.resize(N);\n\
    \    g.resize(N);\n    int k = 1;\n    Poly<T> Q(N * 2);\n    rep(i, 0, n) Q[i]\
    \ = -g[i];\n    auto P = dfs(dfs, N, k, Q);\n    Poly<T> ret(n);\n    rep(i, 0,\
    \ n) ret[i] = P[N - 1 - i];\n    return ret;\n};\n\n/**\n * @brief Composition\
    \ of Formal Power Series\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/composition.hpp
  requiredBy: []
  timestamp: '2024-04-30 04:21:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/composition.hpp
layout: document
redirect_from:
- /library/FPS/composition.hpp
- /library/FPS/composition.hpp.html
title: Composition of Formal Power Series
---
