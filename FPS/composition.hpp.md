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
    \ &f, Poly<T> &g) {\n    assert(SZ(f) == SZ(g) and g[0] == 0);\n    const int\
    \ N = f.deg();\n\n    auto dfs = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T>\
    \ {\n        if (n == 0) {\n            Poly<T> P(k * 2 + 1);\n            rep(i,\
    \ 0, N + 1) P[i] = f[i];\n            return P;\n        }\n        int n2 = n\
    \ >> 1, k2 = k << 1;\n\n        auto R = Q;\n        for (int i = 1; i <= n; i\
    \ += 2)\n            rep(j, 0, k + 1) R[i * (k * 2 + 1) + j] = -R[i * (k * 2 +\
    \ 1) + j];\n        auto bufQ = Q * R;\n        Poly<T> nQ((n2 + 1) * (k2 * 2\
    \ + 1));\n        for (int i = 0, x = 0; x <= n; i++, x += 2)\n            rep(j,\
    \ 0, k * 2 + 1) nQ[i * (k2 * 2 + 1) + j] =\n                bufQ[x * (k * 2 +\
    \ 1) + j];\n        auto nP = dfs(dfs, n2, k2, nQ);\n\n        Poly<T> bufP((n\
    \ + 1) * (k * 2 + 1));\n        for (int i = 0, x = n & 1; x <= n; i++, x += 2)\n\
    \            rep(j, 0, k * 2 + 1) bufP[x * (k * 2 + 1) + j] =\n              \
    \  nP[i * (k * 4 + 1) + j];\n\n        // middle product\n        const int M\
    \ = R.deg();\n        reverse(ALL(R));\n        bufP *= R;\n        Poly<T> P((n\
    \ + 1) * (k * 2 + 1));\n        rep(i, 0, SZ(P)) P[i] = bufP[i + M];\n       \
    \ return P;\n    };\n    int k = 1;\n    Poly<T> Q((N + 1) * (k * 2 + 1));\n \
    \   Q[0] = 1;\n    rep(i, 1, N + 1) Q[i * (k * 2 + 1) + 1] = -g[i];\n    auto\
    \ P = dfs(dfs, N, 1, Q);\n    Poly<T> ret(N + 1);\n    rep(i, 0, N + 1) ret[i]\
    \ = P[i * (k * 2 + 1)];\n    reverse(ALL(ret));\n    return ret;\n};\n\n/**\n\
    \ * @brief Composition of Formal Power Series\n */\n"
  code: "#pragma once\n\ntemplate <typename T> Poly<T> Composition(Poly<T> &f, Poly<T>\
    \ &g) {\n    assert(SZ(f) == SZ(g) and g[0] == 0);\n    const int N = f.deg();\n\
    \n    auto dfs = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {\n     \
    \   if (n == 0) {\n            Poly<T> P(k * 2 + 1);\n            rep(i, 0, N\
    \ + 1) P[i] = f[i];\n            return P;\n        }\n        int n2 = n >> 1,\
    \ k2 = k << 1;\n\n        auto R = Q;\n        for (int i = 1; i <= n; i += 2)\n\
    \            rep(j, 0, k + 1) R[i * (k * 2 + 1) + j] = -R[i * (k * 2 + 1) + j];\n\
    \        auto bufQ = Q * R;\n        Poly<T> nQ((n2 + 1) * (k2 * 2 + 1));\n  \
    \      for (int i = 0, x = 0; x <= n; i++, x += 2)\n            rep(j, 0, k *\
    \ 2 + 1) nQ[i * (k2 * 2 + 1) + j] =\n                bufQ[x * (k * 2 + 1) + j];\n\
    \        auto nP = dfs(dfs, n2, k2, nQ);\n\n        Poly<T> bufP((n + 1) * (k\
    \ * 2 + 1));\n        for (int i = 0, x = n & 1; x <= n; i++, x += 2)\n      \
    \      rep(j, 0, k * 2 + 1) bufP[x * (k * 2 + 1) + j] =\n                nP[i\
    \ * (k * 4 + 1) + j];\n\n        // middle product\n        const int M = R.deg();\n\
    \        reverse(ALL(R));\n        bufP *= R;\n        Poly<T> P((n + 1) * (k\
    \ * 2 + 1));\n        rep(i, 0, SZ(P)) P[i] = bufP[i + M];\n        return P;\n\
    \    };\n    int k = 1;\n    Poly<T> Q((N + 1) * (k * 2 + 1));\n    Q[0] = 1;\n\
    \    rep(i, 1, N + 1) Q[i * (k * 2 + 1) + 1] = -g[i];\n    auto P = dfs(dfs, N,\
    \ 1, Q);\n    Poly<T> ret(N + 1);\n    rep(i, 0, N + 1) ret[i] = P[i * (k * 2\
    \ + 1)];\n    reverse(ALL(ret));\n    return ret;\n};\n\n/**\n * @brief Composition\
    \ of Formal Power Series\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/composition.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/composition.hpp
layout: document
redirect_from:
- /library/FPS/composition.hpp
- /library/FPS/composition.hpp.html
title: Composition of Formal Power Series
---
