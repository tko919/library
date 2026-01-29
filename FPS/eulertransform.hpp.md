---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Euler Transform
    links: []
  bundledCode: "#line 2 \"FPS/eulertransform.hpp\"\n\ntemplate <typename T> Poly<T>\
    \ EulerTransform(Poly<T> &f) {\n    int n = SZ(f);\n    Poly<Fp> g(n);\n    rep(d,\
    \ 1, n) {\n        for (int k = d; k < n; k += d)\n            g[k] += f[d] *\
    \ d;\n    }\n    rep(d, 1, n) g[d] /= d;\n    return g.exp();\n}\n\n/**\n * @brief\
    \ Euler Transform\n */\n"
  code: "#pragma once\n\ntemplate <typename T> Poly<T> EulerTransform(Poly<T> &f)\
    \ {\n    int n = SZ(f);\n    Poly<Fp> g(n);\n    rep(d, 1, n) {\n        for (int\
    \ k = d; k < n; k += d)\n            g[k] += f[d] * d;\n    }\n    rep(d, 1, n)\
    \ g[d] /= d;\n    return g.exp();\n}\n\n/**\n * @brief Euler Transform\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/eulertransform.hpp
  requiredBy: []
  timestamp: '2026-01-30 05:37:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/eulertransform.hpp
layout: document
redirect_from:
- /library/FPS/eulertransform.hpp
- /library/FPS/eulertransform.hpp.html
title: Euler Transform
---
