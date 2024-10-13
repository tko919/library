---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/subset.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Chromatic Number
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
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"Convolution/subset.hpp\"\
    \n\r\ntemplate <typename T, int LG = 20> struct SubsetConvolution {\r\n    using\
    \ POL = array<T, LG + 1>;\r\n    vector<int> bpc;\r\n    SubsetConvolution() :\
    \ bpc(1 << LG) {\r\n        rep(i, 1, 1 << LG) bpc[i] = bpc[i - (i & -i)] + 1;\r\
    \n    }\r\n    void zeta(vector<POL> &a) {\r\n        int n = topbit(SZ(a));\r\
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
    \r\n/**\r\n * @brief Subset Convolution\r\n */\n#line 3 \"Graph/chromaticpoly.hpp\"\
    \n\ntemplate <typename T>\nvector<T> ChromaticPolynomial(int n,\n            \
    \                  vector<ull> &g) { // v-th bit of g[u]:has u-v edge\n    vector<T>\
    \ base(1 << n);\n    rep(mask, 1, 1 << n) {\n        base[mask] = 1;\n       \
    \ rep(u, 0, n) if (mask >> u & 1) {\n            rep(v, 0, n) if (mask >> v &\
    \ 1) {\n                if (g[u] >> v & 1) {\n                    base[mask] =\
    \ 0;\n                    break;\n                }\n            }\n         \
    \   if (base[mask] == 0)\n                break;\n        }\n    }\n\n    vector<T>\
    \ t(1 << n);\n    t.back() = 1;\n    SubsetConvolution<T> buf;\n    auto ways\
    \ = buf.TransposeCompositionEGF(base, t);\n    vector<T> ret(n + 1);\n    rep(i,\
    \ 0, n + 1) {\n        vector<T> add(1, 1);\n        rep(j, 0, i) {\n        \
    \    vector<T> nxt(SZ(add) + 1);\n            rep(k, 0, SZ(add)) {\n         \
    \       nxt[k + 1] += add[k];\n                nxt[k] -= add[k] * j;\n       \
    \     }\n            swap(add, nxt);\n        }\n        rep(k, 0, SZ(add)) ret[k]\
    \ += ways[i] * add[k];\n    }\n    return ret;\n}\n\n/**\n * @brief Chromatic\
    \ Number\n */\n"
  code: "#pragma once\n#include \"Convolution/subset.hpp\"\n\ntemplate <typename T>\n\
    vector<T> ChromaticPolynomial(int n,\n                              vector<ull>\
    \ &g) { // v-th bit of g[u]:has u-v edge\n    vector<T> base(1 << n);\n    rep(mask,\
    \ 1, 1 << n) {\n        base[mask] = 1;\n        rep(u, 0, n) if (mask >> u &\
    \ 1) {\n            rep(v, 0, n) if (mask >> v & 1) {\n                if (g[u]\
    \ >> v & 1) {\n                    base[mask] = 0;\n                    break;\n\
    \                }\n            }\n            if (base[mask] == 0)\n        \
    \        break;\n        }\n    }\n\n    vector<T> t(1 << n);\n    t.back() =\
    \ 1;\n    SubsetConvolution<T> buf;\n    auto ways = buf.TransposeCompositionEGF(base,\
    \ t);\n    vector<T> ret(n + 1);\n    rep(i, 0, n + 1) {\n        vector<T> add(1,\
    \ 1);\n        rep(j, 0, i) {\n            vector<T> nxt(SZ(add) + 1);\n     \
    \       rep(k, 0, SZ(add)) {\n                nxt[k + 1] += add[k];\n        \
    \        nxt[k] -= add[k] * j;\n            }\n            swap(add, nxt);\n \
    \       }\n        rep(k, 0, SZ(add)) ret[k] += ways[i] * add[k];\n    }\n   \
    \ return ret;\n}\n\n/**\n * @brief Chromatic Number\n */"
  dependsOn:
  - Convolution/subset.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: Graph/chromaticpoly.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/chromaticpoly.hpp
layout: document
redirect_from:
- /library/Graph/chromaticpoly.hpp
- /library/Graph/chromaticpoly.hpp.html
title: Chromatic Number
---
