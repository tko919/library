---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"FPS/powenum.hpp\"\n\ntemplate <typename T>\nvector<T> PowEnumerate(Poly<T>\
    \ &f, Poly<T> &g,\n                       int m) { // [x^{deg f}]g f^i (i=0..m)\n\
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
    \ */\n#line 3 \"FPS/compinv.hpp\"\n\ntemplate <typename T> Poly<T> CompositionInv(Poly<T>\
    \ &f) {\n    assert(SZ(f) >= 2 and f[0] == 0 and f[1] != 0);\n    const int n\
    \ = f.deg();\n    const T c = f[1];\n    const T invc = c.inv();\n    for (auto\
    \ &x : f)\n        x *= invc;\n    Poly<T> g(n + 1);\n    g[n] = 1;\n    auto\
    \ ret = Poly<Fp>{PowEnumerate(f, g, n)};\n    rep(i, 1, n + 1) ret[i] *= T(n)\
    \ * Inv<T>(i);\n    reverse(ALL(ret));\n    ret[0] = 1;\n    ret = ret.log();\n\
    \    const T invn = T(1) / -n;\n    for (auto &x : ret)\n        x *= invn;\n\
    \    ret = (ret.exp()) << 1;\n    ret.resize(n + 1);\n    T buf = 1;\n    for\
    \ (auto &x : ret) {\n        x *= buf;\n        buf *= invc;\n    }\n    return\
    \ ret;\n}\n\n/**\n * @brief Compositional Inverse\n */\n"
  code: "#pragma once\n#include \"FPS/powenum.hpp\"\n\ntemplate <typename T> Poly<T>\
    \ CompositionInv(Poly<T> &f) {\n    assert(SZ(f) >= 2 and f[0] == 0 and f[1] !=\
    \ 0);\n    const int n = f.deg();\n    const T c = f[1];\n    const T invc = c.inv();\n\
    \    for (auto &x : f)\n        x *= invc;\n    Poly<T> g(n + 1);\n    g[n] =\
    \ 1;\n    auto ret = Poly<Fp>{PowEnumerate(f, g, n)};\n    rep(i, 1, n + 1) ret[i]\
    \ *= T(n) * Inv<T>(i);\n    reverse(ALL(ret));\n    ret[0] = 1;\n    ret = ret.log();\n\
    \    const T invn = T(1) / -n;\n    for (auto &x : ret)\n        x *= invn;\n\
    \    ret = (ret.exp()) << 1;\n    ret.resize(n + 1);\n    T buf = 1;\n    for\
    \ (auto &x : ret) {\n        x *= buf;\n        buf *= invc;\n    }\n    return\
    \ ret;\n}\n\n/**\n * @brief Compositional Inverse\n */"
  dependsOn:
  - FPS/powenum.hpp
  isVerificationFile: false
  path: FPS/compinv.hpp
  requiredBy: []
  timestamp: '2024-04-29 14:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/compinv.hpp
layout: document
redirect_from:
- /library/FPS/compinv.hpp
- /library/FPS/compinv.hpp.html
title: Compositional Inverse
---
