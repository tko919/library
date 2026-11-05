---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Fast Division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Stirling Number for query
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv {\n    using u64 =\
    \ uint64_t;\n    using u128 = __uint128_t;\n    constexpr FastDiv() : m(), s(),\
    \ x() {}\n    constexpr FastDiv(int _m)\n        : m(_m), s(__lg(m - 1)), x(((u128(1)\
    \ << (s + 64)) + m - 1) / m) {}\n    constexpr int get() {\n        return m;\n\
    \    }\n    constexpr friend u64 operator/(u64 n, const FastDiv &d) {\n      \
    \  return (u128(n) * d.x >> d.s) >> 64;\n    }\n    constexpr friend int operator%(u64\
    \ n, const FastDiv &d) {\n        return n - n / d * d.m;\n    }\n    constexpr\
    \ pair<u64, int> divmod(u64 n) const {\n        u64 q = n / (*this);\n       \
    \ return {q, n - q * m};\n    }\n    int m, s;\n    u64 x;\n};\n\nstruct FastDiv64\
    \ {\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n    u128 mod, mh,\
    \ ml;\n    explicit FastDiv64(u64 mod = 1) : mod(mod) {\n        u128 m = u128(-1)\
    \ / mod;\n        if (m * mod + mod == u128(0))\n            ++m;\n        mh\
    \ = m >> 64;\n        ml = m & u64(-1);\n    }\n    u64 umod() const {\n     \
    \   return mod;\n    }\n    u64 modulo(u128 x) {\n        u128 z = (x & u64(-1))\
    \ * ml;\n        z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n      \
    \  z = (x >> 64) * mh + (z >> 64);\n        x -= z * mod;\n        return x <\
    \ mod ? x : x - mod;\n    }\n    u64 mul(u64 a, u64 b) {\n        return modulo(u128(a)\
    \ * b);\n    }\n};\n\n/**\n * @brief Fast Division\n */\n#line 3 \"Math/stirlingquery.hpp\"\
    \n\r\nclass StirlingNumberQuery {\r\n    const int p;\r\n    FastDiv ip;\r\n \
    \   vector<vector<int>> binom, F, S;\r\n    ll nCr(ll n, ll k) {\r\n        if\
    \ (n < 0 or k < 0 or n < k)\r\n            return 0;\r\n        ll res = 1;\r\n\
    \        while (n) {\r\n            res = (res * binom[n % ip][k % ip]) % ip;\r\
    \n            n /= p;\r\n            k /= p;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n  public:\r\n    StirlingNumberQuery(int _p) : p(_p), ip(p) {\r\
    \n        binom.resize(p, vector<int>(p));\r\n        F.resize(p, vector<int>(p));\r\
    \n        S.resize(p, vector<int>(p));\r\n        binom[0][0] = F[0][0] = S[0][0]\
    \ = 1;\r\n        rep(n, 1, p) rep(k, 0, n + 1) {\r\n            if (k)\r\n  \
    \              binom[n][k] = binom[n - 1][k - 1];\r\n            binom[n][k] =\
    \ (binom[n][k] + binom[n - 1][k]) % ip;\r\n\r\n            if (k)\r\n        \
    \        F[n][k] = F[n - 1][k - 1];\r\n            F[n][k] = (F[n][k] + ll(p -\
    \ n + 1) * F[n - 1][k]) % ip;\r\n\r\n            if (k)\r\n                S[n][k]\
    \ = S[n - 1][k - 1];\r\n            S[n][k] = (S[n][k] + ll(k) * S[n - 1][k])\
    \ % ip;\r\n        }\r\n    }\r\n    int FirstKind(ll n, ll k) {\r\n        if\
    \ (n < 0 or k < 0 or k > n)\r\n            return 0;\r\n        ll i = n / ip,\
    \ j = n % ip;\r\n        if (k < i)\r\n            return 0;\r\n        ll a =\
    \ (k - i) / (p - 1), b = (k - i) % (p - 1);\r\n        if (b == 0 and j)\r\n \
    \           b += p - 1, a--;\r\n        if (a < 0 or a > i or b > j)\r\n     \
    \       return 0;\r\n        int res = (nCr(i, a) * F[j][b]) % ip;\r\n       \
    \ if ((i + a) & 1)\r\n            res = (p - res) % ip;\r\n        return res;\r\
    \n    }\r\n    int SecondKind(ll n, ll k) {\r\n        if (n < 0 or k < 0 or k\
    \ > n)\r\n            return 0;\r\n        if (n == 0)\r\n            return 1;\r\
    \n        ll i = k / ip, j = k % ip;\r\n        if (n < i)\r\n            return\
    \ 0;\r\n        ll a = (n - i) / (p - 1), b = (n - i) % (p - 1);\r\n        if\
    \ (b == 0)\r\n            b += p - 1, a--;\r\n        if (a < 0 or b < j)\r\n\
    \            return 0;\r\n        if (b == p - 1 and j == 0)\r\n            return\
    \ nCr(a, i - 1);\r\n        else\r\n            return (nCr(a, i) * S[b][j]) %\
    \ ip;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Stirling Number for query\r\n */\n"
  code: "#pragma once\r\n#include \"Math/fastdiv.hpp\"\r\n\r\nclass StirlingNumberQuery\
    \ {\r\n    const int p;\r\n    FastDiv ip;\r\n    vector<vector<int>> binom, F,\
    \ S;\r\n    ll nCr(ll n, ll k) {\r\n        if (n < 0 or k < 0 or n < k)\r\n \
    \           return 0;\r\n        ll res = 1;\r\n        while (n) {\r\n      \
    \      res = (res * binom[n % ip][k % ip]) % ip;\r\n            n /= p;\r\n  \
    \          k /= p;\r\n        }\r\n        return res;\r\n    }\r\n\r\n  public:\r\
    \n    StirlingNumberQuery(int _p) : p(_p), ip(p) {\r\n        binom.resize(p,\
    \ vector<int>(p));\r\n        F.resize(p, vector<int>(p));\r\n        S.resize(p,\
    \ vector<int>(p));\r\n        binom[0][0] = F[0][0] = S[0][0] = 1;\r\n       \
    \ rep(n, 1, p) rep(k, 0, n + 1) {\r\n            if (k)\r\n                binom[n][k]\
    \ = binom[n - 1][k - 1];\r\n            binom[n][k] = (binom[n][k] + binom[n -\
    \ 1][k]) % ip;\r\n\r\n            if (k)\r\n                F[n][k] = F[n - 1][k\
    \ - 1];\r\n            F[n][k] = (F[n][k] + ll(p - n + 1) * F[n - 1][k]) % ip;\r\
    \n\r\n            if (k)\r\n                S[n][k] = S[n - 1][k - 1];\r\n   \
    \         S[n][k] = (S[n][k] + ll(k) * S[n - 1][k]) % ip;\r\n        }\r\n   \
    \ }\r\n    int FirstKind(ll n, ll k) {\r\n        if (n < 0 or k < 0 or k > n)\r\
    \n            return 0;\r\n        ll i = n / ip, j = n % ip;\r\n        if (k\
    \ < i)\r\n            return 0;\r\n        ll a = (k - i) / (p - 1), b = (k -\
    \ i) % (p - 1);\r\n        if (b == 0 and j)\r\n            b += p - 1, a--;\r\
    \n        if (a < 0 or a > i or b > j)\r\n            return 0;\r\n        int\
    \ res = (nCr(i, a) * F[j][b]) % ip;\r\n        if ((i + a) & 1)\r\n          \
    \  res = (p - res) % ip;\r\n        return res;\r\n    }\r\n    int SecondKind(ll\
    \ n, ll k) {\r\n        if (n < 0 or k < 0 or k > n)\r\n            return 0;\r\
    \n        if (n == 0)\r\n            return 1;\r\n        ll i = k / ip, j = k\
    \ % ip;\r\n        if (n < i)\r\n            return 0;\r\n        ll a = (n -\
    \ i) / (p - 1), b = (n - i) % (p - 1);\r\n        if (b == 0)\r\n            b\
    \ += p - 1, a--;\r\n        if (a < 0 or b < j)\r\n            return 0;\r\n \
    \       if (b == p - 1 and j == 0)\r\n            return nCr(a, i - 1);\r\n  \
    \      else\r\n            return (nCr(a, i) * S[b][j]) % ip;\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Stirling Number for query\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  isVerificationFile: false
  path: Math/stirlingquery.hpp
  requiredBy: []
  timestamp: '2024-12-26 05:48:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
documentation_of: Math/stirlingquery.hpp
layout: document
redirect_from:
- /library/Math/stirlingquery.hpp
- /library/Math/stirlingquery.hpp.html
title: Stirling Number for query
---
