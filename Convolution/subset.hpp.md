---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/chromaticpoly.hpp
    title: Chromatic Number
  - icon: ':heavy_check_mark:'
    path: Math/hafnian.hpp
    title: Hafnian of matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_hafnian_of_matrix.test.cpp
    title: Verify/LC_hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_subset_convolution.test.cpp
    title: Verify/LC_subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Subset Convolution
    links: []
  bundledCode: "#line 2 \"Convolution/subset.hpp\"\n\r\ntemplate <typename T, int\
    \ LG = 20> struct SubsetConvolution {\r\n    using POL = array<T, LG + 1>;\r\n\
    \    vector<int> bpc;\r\n    SubsetConvolution() : bpc(1 << LG) {\r\n        rep(i,\
    \ 1, 1 << LG) bpc[i] = bpc[i - (i & -i)] + 1;\r\n    }\r\n    void zeta(vector<POL>\
    \ &a) {\r\n        int n = topbit(SZ(a));\r\n        rep(d, 0, n) {\r\n      \
    \      rep(i, 0, 1 << n) if (i >> d & 1) {\r\n                const int pc = bpc[i];\r\
    \n                rep(j, 0, pc) a[i][j] += a[i ^ (1 << d)][j];\r\n           \
    \ }\r\n        }\r\n    }\r\n    void mobius(vector<POL> &a) {\r\n        int\
    \ n = topbit(SZ(a));\r\n        rep(d, 0, n) {\r\n            rep(i, 0, 1 << n)\
    \ if (i >> d & 1) {\r\n                const int pc = bpc[i];\r\n            \
    \    rep(j, pc, n + 1) a[i][j] -= a[i ^ (1 << d)][j];\r\n            }\r\n   \
    \     }\r\n    }\r\n    vector<T> mult(vector<T> &a, vector<T> &b) {\r\n     \
    \   assert(a.size() == b.size());\r\n        int n = SZ(a), m = topbit(n);\r\n\
    \        vector<POL> A(n), B(n);\r\n        rep(i, 0, n) {\r\n            A[i][bpc[i]]\
    \ = a[i];\r\n            B[i][bpc[i]] = b[i];\r\n        }\r\n        zeta(A);\r\
    \n        zeta(B);\r\n        rep(i, 0, n) {\r\n            POL c = {};\r\n  \
    \          rep(j, 0, m + 1) rep(k, 0, m + 1 - j) c[j + k] += A[i][j] * B[i][k];\r\
    \n            swap(A[i], c);\r\n        }\r\n        mobius(A);\r\n        vector<T>\
    \ ret(n);\r\n        rep(i, 0, n) ret[i] = A[i][bpc[i]];\r\n        return ret;\r\
    \n    }\r\n    vector<T> TransposeMult(vector<T> &a, vector<T> &b) {\r\n     \
    \   auto ret = a;\r\n        reverse(ALL(ret));\r\n        ret = mult(ret, b);\r\
    \n        reverse(ALL(ret));\r\n        return ret;\r\n    }\r\n    vector<T>\
    \ exp(vector<T> &f) {\r\n        int n = topbit(SZ(f));\r\n        vector<T> ret(1\
    \ << n);\r\n        ret[0] = 1;\r\n        rep(i, 0, n) {\r\n            vector<T>\
    \ a = {ret.begin(), ret.begin() + (1 << i)};\r\n            vector<T> b = {f.begin()\
    \ + (1 << i), f.begin() + (2 << i)};\r\n            a = mult(a, b);\r\n      \
    \      copy(ALL(a), ret.begin() + (1 << i));\r\n        }\r\n        return ret;\r\
    \n    }\r\n    vector<T> CompositionEGF(vector<T> &s, vector<T> &f) {\r\n    \
    \    int n = topbit(SZ(s));\r\n        f.resize(n + 1);\r\n        vector<T> dp(1);\r\
    \n        dp[0] = f.back();\r\n        rrep(d, 0, n) {\r\n            vector<T>\
    \ ndp(1 << (n - d));\r\n            ndp[0] = f[d];\r\n            rep(i, 0, n\
    \ - d) {\r\n                vector<T> a = {dp.begin(), dp.begin() + (1 << i)};\r\
    \n                vector<T> b = {s.begin() + (1 << i), s.begin() + (2 << i)};\r\
    \n                a = mult(a, b);\r\n                copy(ALL(a), ndp.begin()\
    \ + (1 << i));\r\n            }\r\n            swap(dp, ndp);\r\n        }\r\n\
    \        return dp;\r\n    }\r\n    vector<T> Composition(vector<T> &s, vector<T>\
    \ &f) {\r\n        int n = topbit(SZ(s));\r\n        T c = s[0];\r\n        s[0]\
    \ = 0;\r\n        // taylor shift\r\n        vector<T> pw(n + 1), g(n + 1);\r\n\
    \        pw[0] = 1;\r\n        rep(i, 0, SZ(f)) {\r\n            rep(j, 0, n +\
    \ 1) g[j] += f[i] * pw[j];\r\n            rrep(j, 0, n + 1) {\r\n            \
    \    if (j != n)\r\n                    pw[j + 1] += pw[j];\r\n              \
    \  pw[j] *= c;\r\n            }\r\n        }\r\n        // to EGF\r\n        T\
    \ fact = 1;\r\n        rep(i, 1, n + 1) {\r\n            fact *= i;\r\n      \
    \      g[i] *= fact;\r\n        }\r\n        return CompositionEGF(s, g);\r\n\
    \    }\r\n    vector<T> TransposeCompositionEGF(vector<T> &s, vector<T> &t) {\r\
    \n        int n = topbit(SZ(s));\r\n        vector<T> dp = t, ret(n + 1);\r\n\
    \        ret[0] = dp[0];\r\n        rep(d, 0, n) {\r\n            vector<T> ndp(1\
    \ << (n - d - 1), 0);\r\n            rrep(i, 0, n - d) {\r\n                vector<T>\
    \ a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\r\n                vector<T>\
    \ b = {s.begin() + (1 << i), s.begin() + (2 << i)};\r\n                a = TransposeMult(a,\
    \ b);\r\n                rep(k, 0, SZ(a)) ndp[k] += a[k];\r\n            }\r\n\
    \            swap(dp, ndp);\r\n            ret[d + 1] = dp[0];\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    vector<T> TransposeComposition(vector<T>\
    \ &s, vector<T> &t, int m) {\r\n        int n = topbit(SZ(s));\r\n        T c\
    \ = s[0];\r\n        s[0] = 0;\r\n\r\n        auto g = TransposeCompositionEGF(s,\
    \ t);\r\n        vector<T> coe(m);\r\n        T pw = 1;\r\n        rep(i, 0, m)\
    \ {\r\n            coe[i] = pw * Fact<T>(i, 1);\r\n            pw *= c;\r\n  \
    \      }\r\n        vector<T> f(m);\r\n        rep(i, 0, m) rep(j, 0, n + 1) if\
    \ (i + j < m) {\r\n            f[i + j] += coe[i] * g[j];\r\n        }\r\n   \
    \     rep(i, 0, m) f[i] *= Fact<T>(i);\r\n        return f;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Subset Convolution\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, int LG = 20> struct SubsetConvolution\
    \ {\r\n    using POL = array<T, LG + 1>;\r\n    vector<int> bpc;\r\n    SubsetConvolution()\
    \ : bpc(1 << LG) {\r\n        rep(i, 1, 1 << LG) bpc[i] = bpc[i - (i & -i)] +\
    \ 1;\r\n    }\r\n    void zeta(vector<POL> &a) {\r\n        int n = topbit(SZ(a));\r\
    \n        rep(d, 0, n) {\r\n            rep(i, 0, 1 << n) if (i >> d & 1) {\r\n\
    \                const int pc = bpc[i];\r\n                rep(j, 0, pc) a[i][j]\
    \ += a[i ^ (1 << d)][j];\r\n            }\r\n        }\r\n    }\r\n    void mobius(vector<POL>\
    \ &a) {\r\n        int n = topbit(SZ(a));\r\n        rep(d, 0, n) {\r\n      \
    \      rep(i, 0, 1 << n) if (i >> d & 1) {\r\n                const int pc = bpc[i];\r\
    \n                rep(j, pc, n + 1) a[i][j] -= a[i ^ (1 << d)][j];\r\n       \
    \     }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T> &a, vector<T> &b)\
    \ {\r\n        assert(a.size() == b.size());\r\n        int n = SZ(a), m = topbit(n);\r\
    \n        vector<POL> A(n), B(n);\r\n        rep(i, 0, n) {\r\n            A[i][bpc[i]]\
    \ = a[i];\r\n            B[i][bpc[i]] = b[i];\r\n        }\r\n        zeta(A);\r\
    \n        zeta(B);\r\n        rep(i, 0, n) {\r\n            POL c = {};\r\n  \
    \          rep(j, 0, m + 1) rep(k, 0, m + 1 - j) c[j + k] += A[i][j] * B[i][k];\r\
    \n            swap(A[i], c);\r\n        }\r\n        mobius(A);\r\n        vector<T>\
    \ ret(n);\r\n        rep(i, 0, n) ret[i] = A[i][bpc[i]];\r\n        return ret;\r\
    \n    }\r\n    vector<T> TransposeMult(vector<T> &a, vector<T> &b) {\r\n     \
    \   auto ret = a;\r\n        reverse(ALL(ret));\r\n        ret = mult(ret, b);\r\
    \n        reverse(ALL(ret));\r\n        return ret;\r\n    }\r\n    vector<T>\
    \ exp(vector<T> &f) {\r\n        int n = topbit(SZ(f));\r\n        vector<T> ret(1\
    \ << n);\r\n        ret[0] = 1;\r\n        rep(i, 0, n) {\r\n            vector<T>\
    \ a = {ret.begin(), ret.begin() + (1 << i)};\r\n            vector<T> b = {f.begin()\
    \ + (1 << i), f.begin() + (2 << i)};\r\n            a = mult(a, b);\r\n      \
    \      copy(ALL(a), ret.begin() + (1 << i));\r\n        }\r\n        return ret;\r\
    \n    }\r\n    vector<T> CompositionEGF(vector<T> &s, vector<T> &f) {\r\n    \
    \    int n = topbit(SZ(s));\r\n        f.resize(n + 1);\r\n        vector<T> dp(1);\r\
    \n        dp[0] = f.back();\r\n        rrep(d, 0, n) {\r\n            vector<T>\
    \ ndp(1 << (n - d));\r\n            ndp[0] = f[d];\r\n            rep(i, 0, n\
    \ - d) {\r\n                vector<T> a = {dp.begin(), dp.begin() + (1 << i)};\r\
    \n                vector<T> b = {s.begin() + (1 << i), s.begin() + (2 << i)};\r\
    \n                a = mult(a, b);\r\n                copy(ALL(a), ndp.begin()\
    \ + (1 << i));\r\n            }\r\n            swap(dp, ndp);\r\n        }\r\n\
    \        return dp;\r\n    }\r\n    vector<T> Composition(vector<T> &s, vector<T>\
    \ &f) {\r\n        int n = topbit(SZ(s));\r\n        T c = s[0];\r\n        s[0]\
    \ = 0;\r\n        // taylor shift\r\n        vector<T> pw(n + 1), g(n + 1);\r\n\
    \        pw[0] = 1;\r\n        rep(i, 0, SZ(f)) {\r\n            rep(j, 0, n +\
    \ 1) g[j] += f[i] * pw[j];\r\n            rrep(j, 0, n + 1) {\r\n            \
    \    if (j != n)\r\n                    pw[j + 1] += pw[j];\r\n              \
    \  pw[j] *= c;\r\n            }\r\n        }\r\n        // to EGF\r\n        T\
    \ fact = 1;\r\n        rep(i, 1, n + 1) {\r\n            fact *= i;\r\n      \
    \      g[i] *= fact;\r\n        }\r\n        return CompositionEGF(s, g);\r\n\
    \    }\r\n    vector<T> TransposeCompositionEGF(vector<T> &s, vector<T> &t) {\r\
    \n        int n = topbit(SZ(s));\r\n        vector<T> dp = t, ret(n + 1);\r\n\
    \        ret[0] = dp[0];\r\n        rep(d, 0, n) {\r\n            vector<T> ndp(1\
    \ << (n - d - 1), 0);\r\n            rrep(i, 0, n - d) {\r\n                vector<T>\
    \ a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\r\n                vector<T>\
    \ b = {s.begin() + (1 << i), s.begin() + (2 << i)};\r\n                a = TransposeMult(a,\
    \ b);\r\n                rep(k, 0, SZ(a)) ndp[k] += a[k];\r\n            }\r\n\
    \            swap(dp, ndp);\r\n            ret[d + 1] = dp[0];\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    vector<T> TransposeComposition(vector<T>\
    \ &s, vector<T> &t, int m) {\r\n        int n = topbit(SZ(s));\r\n        T c\
    \ = s[0];\r\n        s[0] = 0;\r\n\r\n        auto g = TransposeCompositionEGF(s,\
    \ t);\r\n        vector<T> coe(m);\r\n        T pw = 1;\r\n        rep(i, 0, m)\
    \ {\r\n            coe[i] = pw * Fact<T>(i, 1);\r\n            pw *= c;\r\n  \
    \      }\r\n        vector<T> f(m);\r\n        rep(i, 0, m) rep(j, 0, n + 1) if\
    \ (i + j < m) {\r\n            f[i + j] += coe[i] * g[j];\r\n        }\r\n   \
    \     rep(i, 0, m) f[i] *= Fact<T>(i);\r\n        return f;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Subset Convolution\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/subset.hpp
  requiredBy:
  - Graph/chromaticpoly.hpp
  - Math/hafnian.hpp
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_subset_convolution.test.cpp
  - Verify/LC_hafnian_of_matrix.test.cpp
documentation_of: Convolution/subset.hpp
layout: document
redirect_from:
- /library/Convolution/subset.hpp
- /library/Convolution/subset.hpp.html
title: Subset Convolution
---
