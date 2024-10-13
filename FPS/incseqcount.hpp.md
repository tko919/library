---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Number of Increasing Sequences Between Two Sequences
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
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"FPS/incseqcount.hpp\"\
    \n\ntemplate <typename T>\nT NumberofIncreasingSequencesBetweenTwoSequences(int\
    \ n, vector<int> a,\n                                                 vector<int>\
    \ b) {\n    auto step = [&](int n, vector<int> a, vector<T> &init) -> vector<T>\
    \ {\n        auto rec = [&](auto &self, int L, int R, vector<T> &dp) -> vector<T>\
    \ {\n            assert(SZ(dp) == R - L);\n            if (R - L == 1) {\n   \
    \             vector<T> ret(a[L], dp[0]);\n                return ret;\n     \
    \       }\n            int mid = (L + R) >> 1;\n            int offset = a[mid\
    \ - 1];\n            vector<T> Ldp = {dp.begin(), dp.begin() + mid - L};\n   \
    \         vector<T> Lret = self(self, L, mid, Ldp);\n\n            int sz = a[R\
    \ - 1];\n            vector<T> ret(sz);\n            vector<T> Rdp(R - mid);\n\
    \            if (offset == 0) {\n                rep(i, 0, R - mid) Rdp[i] = dp[i\
    \ + mid - L];\n            } else {\n                {\n                    Poly<T>\
    \ X(offset), Y(R - mid + offset);\n                    rep(j, 0, offset) X[j]\
    \ =\n                        Lret[j] * Fact<T>(offset - 1 - j, 1);\n         \
    \           rep(k, 0, R - mid + offset) Y[k] = Fact<T>(k);\n                 \
    \   X *= Y;\n                    rep(i, 0, R - mid) Rdp[i] +=\n              \
    \          X[i + offset - 1] * Fact<T>(i, 1);\n                }\n           \
    \     {\n                    Poly<T> X(offset), Y(offset);\n                 \
    \   rep(j, 0, offset) X[j] = Lret[j];\n                    rep(k, 0, offset) Y[k]\
    \ = nCr<T>(R - mid - 1 + k, k);\n                    X *= Y;\n               \
    \     rep(i, 0, offset) ret[i] += X[i];\n                }\n                {\n\
    \                    Poly<T> X(R - mid), Y(R - mid);\n                    rep(j,\
    \ 0, R - mid) X[j] = dp[j + mid - L];\n                    rep(j, 0, R - mid)\
    \ Y[j] = nCr<T>(j + offset - 1, j);\n                    X *= Y;\n           \
    \         rep(i, 0, R - mid) Rdp[i] += X[i];\n                }\n            \
    \    {\n                    Poly<T> X(R - mid), Y(offset + R - mid);\n       \
    \             rep(j, 0, R - mid) X[j] =\n                        dp[j + mid -\
    \ L] * Fact<T>(R - mid - 1 - j, 1);\n                    rep(k, 0, offset + R\
    \ - mid) Y[k] = Fact<T>(k);\n                    X *= Y;\n                   \
    \ rep(i, 0, offset) ret[i] +=\n                        X[R - mid - 1 + i] * Fact<T>(i,\
    \ 1);\n                }\n            }\n            rep(j, mid, R) a[j] -= offset;\n\
    \            vector<T> Rret = self(self, mid, R, Rdp);\n            rep(j, offset,\
    \ sz) ret[j] = Rret[j - offset];\n            return ret;\n        };\n      \
    \  auto ret = rec(rec, 0, n, init);\n        rrep(j, 0, SZ(ret) - 1) ret[j + 1]\
    \ -= ret[j];\n        return ret;\n    };\n\n    rep(i, 0, n - 1) chmax(a[i +\
    \ 1], a[i]);\n    rrep(i, 0, n - 1) chmin(b[i], b[i + 1]);\n    rep(i, 0, n) if\
    \ (a[i] >= b[i]) {\n        return 0;\n    }\n    int offset = a.front();\n  \
    \  for (auto &x : a)\n        x -= offset;\n    for (auto &x : b)\n        x -=\
    \ offset + 1;\n    a.insert(a.begin(), 0);\n    b.push_back(b.back());\n\n   \
    \ bool vert = 1;\n    vector<T> dp(b[0] + 1);\n    dp[0] = 1;\n    int x = 0,\
    \ y = 0;\n    for (;;) {\n        if (x == n and y == b.back())\n            break;\n\
    \        if (vert) {\n            // up\n            vector<int> H;\n        \
    \    for (;;) {\n                int add = UB(a, y) - x;\n                H.push_back(add);\n\
    \                if (y == b[x])\n                    break;\n                y++;\n\
    \            }\n            assert(SZ(dp) == SZ(H));\n            auto nxt = step(SZ(H),\
    \ H, dp);\n            swap(dp, nxt);\n        } else {\n            // right\n\
    \            vector<int> H;\n            for (;;) {\n                int add =\
    \ b[x] - y + 1;\n                H.push_back(add);\n                if (x == n\
    \ or y < a[x + 1])\n                    break;\n                x++;\n       \
    \     }\n            assert(SZ(dp) == SZ(H));\n            auto nxt = step(SZ(H),\
    \ H, dp);\n            swap(dp, nxt);\n        }\n        vert ^= 1;\n    }\n\
    \    return accumulate(ALL(dp), T(0));\n}\n\n/**\n * @brief Number of Increasing\
    \ Sequences Between Two Sequences\n */\n"
  code: "#pragma once\n#include \"Math/comb.hpp\"\n\ntemplate <typename T>\nT NumberofIncreasingSequencesBetweenTwoSequences(int\
    \ n, vector<int> a,\n                                                 vector<int>\
    \ b) {\n    auto step = [&](int n, vector<int> a, vector<T> &init) -> vector<T>\
    \ {\n        auto rec = [&](auto &self, int L, int R, vector<T> &dp) -> vector<T>\
    \ {\n            assert(SZ(dp) == R - L);\n            if (R - L == 1) {\n   \
    \             vector<T> ret(a[L], dp[0]);\n                return ret;\n     \
    \       }\n            int mid = (L + R) >> 1;\n            int offset = a[mid\
    \ - 1];\n            vector<T> Ldp = {dp.begin(), dp.begin() + mid - L};\n   \
    \         vector<T> Lret = self(self, L, mid, Ldp);\n\n            int sz = a[R\
    \ - 1];\n            vector<T> ret(sz);\n            vector<T> Rdp(R - mid);\n\
    \            if (offset == 0) {\n                rep(i, 0, R - mid) Rdp[i] = dp[i\
    \ + mid - L];\n            } else {\n                {\n                    Poly<T>\
    \ X(offset), Y(R - mid + offset);\n                    rep(j, 0, offset) X[j]\
    \ =\n                        Lret[j] * Fact<T>(offset - 1 - j, 1);\n         \
    \           rep(k, 0, R - mid + offset) Y[k] = Fact<T>(k);\n                 \
    \   X *= Y;\n                    rep(i, 0, R - mid) Rdp[i] +=\n              \
    \          X[i + offset - 1] * Fact<T>(i, 1);\n                }\n           \
    \     {\n                    Poly<T> X(offset), Y(offset);\n                 \
    \   rep(j, 0, offset) X[j] = Lret[j];\n                    rep(k, 0, offset) Y[k]\
    \ = nCr<T>(R - mid - 1 + k, k);\n                    X *= Y;\n               \
    \     rep(i, 0, offset) ret[i] += X[i];\n                }\n                {\n\
    \                    Poly<T> X(R - mid), Y(R - mid);\n                    rep(j,\
    \ 0, R - mid) X[j] = dp[j + mid - L];\n                    rep(j, 0, R - mid)\
    \ Y[j] = nCr<T>(j + offset - 1, j);\n                    X *= Y;\n           \
    \         rep(i, 0, R - mid) Rdp[i] += X[i];\n                }\n            \
    \    {\n                    Poly<T> X(R - mid), Y(offset + R - mid);\n       \
    \             rep(j, 0, R - mid) X[j] =\n                        dp[j + mid -\
    \ L] * Fact<T>(R - mid - 1 - j, 1);\n                    rep(k, 0, offset + R\
    \ - mid) Y[k] = Fact<T>(k);\n                    X *= Y;\n                   \
    \ rep(i, 0, offset) ret[i] +=\n                        X[R - mid - 1 + i] * Fact<T>(i,\
    \ 1);\n                }\n            }\n            rep(j, mid, R) a[j] -= offset;\n\
    \            vector<T> Rret = self(self, mid, R, Rdp);\n            rep(j, offset,\
    \ sz) ret[j] = Rret[j - offset];\n            return ret;\n        };\n      \
    \  auto ret = rec(rec, 0, n, init);\n        rrep(j, 0, SZ(ret) - 1) ret[j + 1]\
    \ -= ret[j];\n        return ret;\n    };\n\n    rep(i, 0, n - 1) chmax(a[i +\
    \ 1], a[i]);\n    rrep(i, 0, n - 1) chmin(b[i], b[i + 1]);\n    rep(i, 0, n) if\
    \ (a[i] >= b[i]) {\n        return 0;\n    }\n    int offset = a.front();\n  \
    \  for (auto &x : a)\n        x -= offset;\n    for (auto &x : b)\n        x -=\
    \ offset + 1;\n    a.insert(a.begin(), 0);\n    b.push_back(b.back());\n\n   \
    \ bool vert = 1;\n    vector<T> dp(b[0] + 1);\n    dp[0] = 1;\n    int x = 0,\
    \ y = 0;\n    for (;;) {\n        if (x == n and y == b.back())\n            break;\n\
    \        if (vert) {\n            // up\n            vector<int> H;\n        \
    \    for (;;) {\n                int add = UB(a, y) - x;\n                H.push_back(add);\n\
    \                if (y == b[x])\n                    break;\n                y++;\n\
    \            }\n            assert(SZ(dp) == SZ(H));\n            auto nxt = step(SZ(H),\
    \ H, dp);\n            swap(dp, nxt);\n        } else {\n            // right\n\
    \            vector<int> H;\n            for (;;) {\n                int add =\
    \ b[x] - y + 1;\n                H.push_back(add);\n                if (x == n\
    \ or y < a[x + 1])\n                    break;\n                x++;\n       \
    \     }\n            assert(SZ(dp) == SZ(H));\n            auto nxt = step(SZ(H),\
    \ H, dp);\n            swap(dp, nxt);\n        }\n        vert ^= 1;\n    }\n\
    \    return accumulate(ALL(dp), T(0));\n}\n\n/**\n * @brief Number of Increasing\
    \ Sequences Between Two Sequences\n */"
  dependsOn:
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/incseqcount.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/incseqcount.hpp
layout: document
redirect_from:
- /library/FPS/incseqcount.hpp
- /library/FPS/incseqcount.hpp.html
title: Number of Increasing Sequences Between Two Sequences
---
