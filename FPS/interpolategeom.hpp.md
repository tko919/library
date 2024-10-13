---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"FPS/interpolategeom.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ InterpolateGeomSeq(int n, T a, T w, vector<T> &y) {\n    if (n == 0)\n     \
    \   return {};\n    auto listinv = [&](vector<T> a) -> vector<T> {\n        int\
    \ N = a.size();\n        vector<T> rui(N + 1, 1);\n        rep(i, 0, N) rui[i\
    \ + 1] = rui[i] * a[i];\n        T c = rui.back().inv();\n        rui.pop_back();\n\
    \        for (int i = N - 1; i >= 0; i--) {\n            rui[i] *= c;\n      \
    \      c *= a[i];\n        }\n        return rui;\n    };\n    vector<T> pw(n\
    \ + 1, 1), tri(n + 1, 1), ttri(n + 1, 1), s(n, 1), W(n, 1);\n    rep(i, 0, n)\
    \ pw[i + 1] = pw[i] * w;\n    rep(i, 0, n) {\n        tri[i + 1] = tri[i] * pw[i];\n\
    \        if (i != n - 1) {\n            ttri[i + 1] = ttri[i] * pw[n - i - 2];\n\
    \            s[i + 1] = s[i] * (-pw[i + 1] + 1);\n        }\n    }\n    T sn =\
    \ s[n - 1] * (-pw[n] + 1);\n    auto ittri = listinv(ttri), is = listinv(s);\n\
    \    rep(i, 0, n) {\n        T den = ittri[i] * is[i] * is[n - i - 1];\n     \
    \   if (i & 1)\n            den = -den;\n        W[i] = y[i] * den;\n    }\n\n\
    \    // prod (1-w^i x)\n    Poly<T> f(n);\n    f[0] = 1;\n    rep(k, 1, n) {\n\
    \        f[k] = tri[k] * sn * (is[k] * is[n - k]);\n        if (k & 1)\n     \
    \       f[k] = -f[k];\n    }\n\n    // sum W_i/(1-w^i x)\n    Poly<T> g = MultievalGeomSeq(W,\
    \ T(1), w, n);\n\n    f *= g;\n    f.resize(n);\n    reverse(ALL(f));\n    T ia\
    \ = a.inv(), c = 1;\n    rep(i, 0, n) {\n        f[i] *= c;\n        c *= ia;\n\
    \    }\n    return f;\n}\n\n/**\n * Polynomial Interpolation on Geometric Sequence\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T>\nvector<T> InterpolateGeomSeq(int n,\
    \ T a, T w, vector<T> &y) {\n    if (n == 0)\n        return {};\n    auto listinv\
    \ = [&](vector<T> a) -> vector<T> {\n        int N = a.size();\n        vector<T>\
    \ rui(N + 1, 1);\n        rep(i, 0, N) rui[i + 1] = rui[i] * a[i];\n        T\
    \ c = rui.back().inv();\n        rui.pop_back();\n        for (int i = N - 1;\
    \ i >= 0; i--) {\n            rui[i] *= c;\n            c *= a[i];\n        }\n\
    \        return rui;\n    };\n    vector<T> pw(n + 1, 1), tri(n + 1, 1), ttri(n\
    \ + 1, 1), s(n, 1), W(n, 1);\n    rep(i, 0, n) pw[i + 1] = pw[i] * w;\n    rep(i,\
    \ 0, n) {\n        tri[i + 1] = tri[i] * pw[i];\n        if (i != n - 1) {\n \
    \           ttri[i + 1] = ttri[i] * pw[n - i - 2];\n            s[i + 1] = s[i]\
    \ * (-pw[i + 1] + 1);\n        }\n    }\n    T sn = s[n - 1] * (-pw[n] + 1);\n\
    \    auto ittri = listinv(ttri), is = listinv(s);\n    rep(i, 0, n) {\n      \
    \  T den = ittri[i] * is[i] * is[n - i - 1];\n        if (i & 1)\n           \
    \ den = -den;\n        W[i] = y[i] * den;\n    }\n\n    // prod (1-w^i x)\n  \
    \  Poly<T> f(n);\n    f[0] = 1;\n    rep(k, 1, n) {\n        f[k] = tri[k] * sn\
    \ * (is[k] * is[n - k]);\n        if (k & 1)\n            f[k] = -f[k];\n    }\n\
    \n    // sum W_i/(1-w^i x)\n    Poly<T> g = MultievalGeomSeq(W, T(1), w, n);\n\
    \n    f *= g;\n    f.resize(n);\n    reverse(ALL(f));\n    T ia = a.inv(), c =\
    \ 1;\n    rep(i, 0, n) {\n        f[i] *= c;\n        c *= ia;\n    }\n    return\
    \ f;\n}\n\n/**\n * Polynomial Interpolation on Geometric Sequence\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/interpolategeom.hpp
  requiredBy: []
  timestamp: '2024-10-13 16:49:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/interpolategeom.hpp
layout: document
redirect_from:
- /library/FPS/interpolategeom.hpp
- /library/FPS/interpolategeom.hpp.html
title: FPS/interpolategeom.hpp
---
