---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: FPS/samplepointshift.hpp
    title: Shift of Sampling Points of Polynomial
  - icon: ':question:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_many_factorials.test.cpp
    title: Verify/LC_many_factorials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Factorial (Large)
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
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1,\
    \ inv);\n}\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T\
    \ choose(int n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return\
    \ nCr<T>(n + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3\
    \ \"FPS/samplepointshift.hpp\"\n\ntemplate <typename T>\nPoly<T> SamplePointsShift(vector<T>\
    \ &ys, T c, int m = -1) {\n    ll n = ys.size() - 1, C = c.v % T::get_mod();\n\
    \    if (m == -1)\n        m = n + 1;\n    if (C <= n) {\n        Poly<T> res;\n\
    \        rep(i, C, n + 1) res.push_back(ys[i]);\n        if (int(res.size()) >=\
    \ m) {\n            res.resize(m);\n            return res;\n        }\n     \
    \   auto add = SamplePointsShift<T>(ys, n + 1, m - res.size());\n        for (int\
    \ i = 0; int(res.size()) < m; i++) {\n            res.push_back(add[i]);\n   \
    \     }\n        return res;\n    }\n    if (C + m > T::get_mod()) {\n       \
    \ auto res = SamplePointsShift<T>(ys, c, T::get_mod() - c.v);\n        auto add\
    \ = SamplePointsShift<T>(ys, 0, m - res.size());\n        rep(i, 0, add.size())\
    \ res.push_back(add[i]);\n        return res;\n    }\n\n    Poly<T> A(n + 1),\
    \ B(m + n);\n    rep(i, 0, n + 1) {\n        A[i] = ys[i] * Fact<T>(i, 1) * Fact<T>(n\
    \ - i, 1);\n        if ((n - i) & 1)\n            A[i] = -A[i];\n    }\n    rep(i,\
    \ 0, m + n) B[i] = Fp(1) / (c - n + i);\n    auto AB = A * B;\n    vector<T> res(m);\n\
    \    Fp base = 1;\n    rep(x, 0, n + 1) base *= (c - x);\n    rep(i, 0, m) {\n\
    \        res[i] = AB[n + i] * base;\n        base *= (c + i + 1);\n        base\
    \ *= B[i];\n    }\n    return res;\n}\n\n/**\n * @brief Shift of Sampling Points\
    \ of Polynomial\n */\n#line 3 \"FPS/factlarge.hpp\"\n\ntemplate <typename T> struct\
    \ FactLarge {\n    static constexpr int LOG_BLOCK_SIZE = 9;\n    static constexpr\
    \ int BLOCK_SIZE = 1 << LOG_BLOCK_SIZE;\n    static constexpr int BLOCK_NUM =\
    \ T::get_mod() >> LOG_BLOCK_SIZE;\n    static inline vector<T> buf;\n    static\
    \ T fact(int n) {\n        if (buf.empty())\n            run();\n        int q\
    \ = n / BLOCK_SIZE, r = n % BLOCK_SIZE;\n        T ret;\n        if (r * 2 <=\
    \ BLOCK_SIZE) {\n            ret = buf[q];\n            rep(i, n + 1 - r, n +\
    \ 1) ret *= i;\n        } else if (q != BLOCK_NUM) {\n            ret = buf[q\
    \ + 1];\n            T den = 1;\n            rep(i, 1, BLOCK_SIZE - r + 1) den\
    \ *= n + i;\n            ret /= den;\n        } else {\n            ret = T::get_mod()\
    \ - 1;\n            T den = 1;\n            rep(i, n + 1, T::get_mod()) den *=\
    \ i;\n            ret /= den;\n        }\n        return ret;\n    }\n\n  private:\n\
    \    static void run() {\n        vector<T> f(2);\n        f[0] = 1, f[1] = 3;\n\
    \        for (int x = 2; x < BLOCK_SIZE; x <<= 1) {\n            auto ext = SamplePointsShift(f,\
    \ T(x), x * 3);\n            vector<T> g(x * 2);\n            rep(j, 0, x >> 1)\
    \ g[j] =\n                f[j * 2] * f[j * 2 + 1] * ((2 * j + 1) * x);\n     \
    \       rep(j, x >> 1, x * 2) g[j] =\n                ext[j * 2 - x] * ext[j *\
    \ 2 + 1 - x] * ((2 * j + 1) * x);\n            swap(f, g);\n        }\n      \
    \  if (BLOCK_NUM > BLOCK_SIZE) {\n            auto add =\n                SamplePointsShift(f,\
    \ T(BLOCK_SIZE), BLOCK_NUM - BLOCK_SIZE);\n            f.insert(f.end(), ALL(add));\n\
    \        } else\n            f.resize(BLOCK_NUM);\n        rep(i, 0, BLOCK_NUM)\
    \ f[i] *= T(i + 1) * BLOCK_SIZE;\n        buf = vector<T>(BLOCK_NUM + 1);\n  \
    \      buf[0] = 1;\n        rep(i, 0, BLOCK_NUM) buf[i + 1] = buf[i] * f[i];\n\
    \    }\n};\n\n/**\n * @brief Factorial (Large)\n */\n"
  code: "#pragma once\n#include \"FPS/samplepointshift.hpp\"\n\ntemplate <typename\
    \ T> struct FactLarge {\n    static constexpr int LOG_BLOCK_SIZE = 9;\n    static\
    \ constexpr int BLOCK_SIZE = 1 << LOG_BLOCK_SIZE;\n    static constexpr int BLOCK_NUM\
    \ = T::get_mod() >> LOG_BLOCK_SIZE;\n    static inline vector<T> buf;\n    static\
    \ T fact(int n) {\n        if (buf.empty())\n            run();\n        int q\
    \ = n / BLOCK_SIZE, r = n % BLOCK_SIZE;\n        T ret;\n        if (r * 2 <=\
    \ BLOCK_SIZE) {\n            ret = buf[q];\n            rep(i, n + 1 - r, n +\
    \ 1) ret *= i;\n        } else if (q != BLOCK_NUM) {\n            ret = buf[q\
    \ + 1];\n            T den = 1;\n            rep(i, 1, BLOCK_SIZE - r + 1) den\
    \ *= n + i;\n            ret /= den;\n        } else {\n            ret = T::get_mod()\
    \ - 1;\n            T den = 1;\n            rep(i, n + 1, T::get_mod()) den *=\
    \ i;\n            ret /= den;\n        }\n        return ret;\n    }\n\n  private:\n\
    \    static void run() {\n        vector<T> f(2);\n        f[0] = 1, f[1] = 3;\n\
    \        for (int x = 2; x < BLOCK_SIZE; x <<= 1) {\n            auto ext = SamplePointsShift(f,\
    \ T(x), x * 3);\n            vector<T> g(x * 2);\n            rep(j, 0, x >> 1)\
    \ g[j] =\n                f[j * 2] * f[j * 2 + 1] * ((2 * j + 1) * x);\n     \
    \       rep(j, x >> 1, x * 2) g[j] =\n                ext[j * 2 - x] * ext[j *\
    \ 2 + 1 - x] * ((2 * j + 1) * x);\n            swap(f, g);\n        }\n      \
    \  if (BLOCK_NUM > BLOCK_SIZE) {\n            auto add =\n                SamplePointsShift(f,\
    \ T(BLOCK_SIZE), BLOCK_NUM - BLOCK_SIZE);\n            f.insert(f.end(), ALL(add));\n\
    \        } else\n            f.resize(BLOCK_NUM);\n        rep(i, 0, BLOCK_NUM)\
    \ f[i] *= T(i + 1) * BLOCK_SIZE;\n        buf = vector<T>(BLOCK_NUM + 1);\n  \
    \      buf[0] = 1;\n        rep(i, 0, BLOCK_NUM) buf[i + 1] = buf[i] * f[i];\n\
    \    }\n};\n\n/**\n * @brief Factorial (Large)\n */"
  dependsOn:
  - FPS/samplepointshift.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/factlarge.hpp
  requiredBy: []
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_many_factorials.test.cpp
documentation_of: FPS/factlarge.hpp
layout: document
redirect_from:
- /library/FPS/factlarge.hpp
- /library/FPS/factlarge.hpp.html
title: Factorial (Large)
---
