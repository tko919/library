---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Convolution/2D.hpp
    title: 2D Convolution
  - icon: ':warning:'
    path: FPS/powenum.hpp
    title: Pow Enumerate
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Compositional Inverse
    links: []
  bundledCode: "#line 2 \"Convolution/2D.hpp\"\n\ntemplate <typename T> void mult2D(vector<Poly<T>>\
    \ &f, vector<Poly<T>> g) {\n    int H1 = SZ(f), W1 = SZ(f[0]);\n    int H2 = SZ(g),\
    \ W2 = SZ(g[0]);\n    int H = H1 + H2 - 1, W = W1 + W2 - 1;\n\n    Poly<T> ff(H1\
    \ * W), gg(H2 * W);\n\n    rep(i, 0, H1) rep(j, 0, W1) ff[i * W + j] = f[i][j];\n\
    \    rep(i, 0, H2) rep(j, 0, W2) gg[i * W + j] = g[i][j];\n    ff *= gg;\n\n \
    \   f.resize(H);\n    rep(i, 0, H) {\n        f[i].resize(W);\n        rep(j,\
    \ 0, W) f[i][j] = ff[i * W + j];\n    }\n    return;\n}\n\n/**\n * @brief 2D Convolution\n\
    \ */\n#line 3 \"FPS/powenum.hpp\"\n\ntemplate <typename T>\nvector<T> PowEnumerate(Poly<T>\
    \ &f, Poly<T> &g) { // [x^n]f^i g (n=deg f,i=0..n)\n    assert(f[0] == 0);\n \
    \   int n = f.deg();\n    int k = 1;\n    // vector P(n + 1, Poly<T>(k + 1));\n\
    \    // vector Q(n + 1, Poly<T>(k + 1));\n    Poly<T> P((n + 1) * (k * 2 + 1)),\
    \ Q((n + 1) * (k * 2 + 1));\n    rep(i, 0, n + 1) P[i * (k * 2 + 1)] = g[i];\n\
    \    Q[0] = 1;\n    rep(i, 1, n + 1) Q[i * (k * 2 + 1) + 1] = -f[i];\n\n    while\
    \ (n) {\n        auto R = Q;\n        for (int i = 1; i <= n; i += 2)\n      \
    \      rep(j, 0, k + 1) R[i * (k * 2 + 1) + j] = -R[i * (k * 2 + 1) + j];\n  \
    \      P *= R;\n        Q *= R;\n        Poly<T> nP((n / 2 + 1) * (k * 4 + 1)),\
    \ nQ((n / 2 + 1) * (k * 4 + 1));\n        for (int i = 0, x = n & 1; x <= n; i++,\
    \ x += 2)\n            rep(j, 0, k * 2 + 1) nP[i * (k * 4 + 1) + j] =\n      \
    \          P[x * (k * 2 + 1) + j];\n        for (int i = 0, x = 0; x <= n; i++,\
    \ x += 2)\n            rep(j, 0, k * 2 + 1) nQ[i * (k * 4 + 1) + j] =\n      \
    \          Q[x * (k * 2 + 1) + j];\n        swap(P, nP);\n        swap(Q, nQ);\n\
    \        n >>= 1;\n        k <<= 1;\n    }\n    vector<T> ret(SZ(f));\n    rep(i,\
    \ 0, SZ(f)) ret[i] = P[i];\n    return ret;\n}\n\n/**\n * @brief Pow Enumerate\n\
    \ */\n#line 3 \"FPS/compinv.hpp\"\n\ntemplate <typename T> Poly<T> CompositionInv(Poly<T>\
    \ &f) {\n    assert(SZ(f) >= 2 and f[0] == 0 and f[1] != 0);\n    const int n\
    \ = f.deg();\n    const T c = f[1];\n    const T invc = c.inv();\n    for (auto\
    \ &x : f)\n        x *= invc;\n    Poly<T> g(n + 1);\n    g[0] = 1;\n    auto\
    \ ret = Poly<Fp>{PowEnumerate(f, g)};\n    rep(i, 1, n + 1) ret[i] *= T(n) * Inv<T>(i);\n\
    \    reverse(ALL(ret));\n    ret[0] = 1;\n    ret = ret.log();\n    const T invn\
    \ = Inv<T>(-n);\n    for (auto &x : ret)\n        x *= invn;\n    ret = (ret.exp())\
    \ << 1;\n    ret.resize(n + 1);\n    T buf = 1;\n    for (auto &x : ret) {\n \
    \       x *= buf;\n        buf *= invc;\n    }\n    return ret;\n}\n\n/**\n *\
    \ @brief Compositional Inverse\n */\n"
  code: "#pragma once\n#include \"FPS/powenum.hpp\"\n\ntemplate <typename T> Poly<T>\
    \ CompositionInv(Poly<T> &f) {\n    assert(SZ(f) >= 2 and f[0] == 0 and f[1] !=\
    \ 0);\n    const int n = f.deg();\n    const T c = f[1];\n    const T invc = c.inv();\n\
    \    for (auto &x : f)\n        x *= invc;\n    Poly<T> g(n + 1);\n    g[0] =\
    \ 1;\n    auto ret = Poly<Fp>{PowEnumerate(f, g)};\n    rep(i, 1, n + 1) ret[i]\
    \ *= T(n) * Inv<T>(i);\n    reverse(ALL(ret));\n    ret[0] = 1;\n    ret = ret.log();\n\
    \    const T invn = Inv<T>(-n);\n    for (auto &x : ret)\n        x *= invn;\n\
    \    ret = (ret.exp()) << 1;\n    ret.resize(n + 1);\n    T buf = 1;\n    for\
    \ (auto &x : ret) {\n        x *= buf;\n        buf *= invc;\n    }\n    return\
    \ ret;\n}\n\n/**\n * @brief Compositional Inverse\n */"
  dependsOn:
  - FPS/powenum.hpp
  - Convolution/2D.hpp
  isVerificationFile: false
  path: FPS/compinv.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/compinv.hpp
layout: document
redirect_from:
- /library/FPS/compinv.hpp
- /library/FPS/compinv.hpp.html
title: Compositional Inverse
---
