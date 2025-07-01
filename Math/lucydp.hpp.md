---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_counting_primes.test.cpp
    title: Verify/LC_counting_primes.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1781.test.cpp
    title: Verify/YUKI_1781.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/primesum.md
    document_title: Prime Sum
    links: []
  bundledCode: "#line 2 \"Math/sieve.hpp\"\n\r\ntemplate <int L = 101010101> vector<int>\
    \ sieve(int N) {\r\n    bitset<L> isp;\r\n    int n, sq = ceil(sqrt(N));\r\n \
    \   for (int z = 1; z <= 5; z += 4) {\r\n        for (int y = z; y <= sq; y +=\
    \ 6) {\r\n            for (int x = 1; x <= sq and (n = 4 * x * x + y * y) <= N;\
    \ ++x) {\r\n                isp[n].flip();\r\n            }\r\n            for\
    \ (int x = y + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n              \
    \   x += 2) {\r\n                isp[n].flip();\r\n            }\r\n        }\r\
    \n    }\r\n    for (int z = 2; z <= 4; z += 2) {\r\n        for (int y = z; y\
    \ <= sq; y += 6) {\r\n            for (int x = 1; x <= sq and (n = 3 * x * x +\
    \ y * y) <= N; x += 2) {\r\n                isp[n].flip();\r\n            }\r\n\
    \            for (int x = y + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n\
    \                 x += 2) {\r\n                isp[n].flip();\r\n            }\r\
    \n        }\r\n    }\r\n    for (int y = 3; y <= sq; y += 6) {\r\n        for\
    \ (int z = 1; z <= 2; ++z) {\r\n            for (int x = z; x <= sq and (n = 4\
    \ * x * x + y * y) <= N; x += 3) {\r\n                isp[n].flip();\r\n     \
    \       }\r\n        }\r\n    }\r\n    for (int n = 5; n <= sq; ++n)\r\n     \
    \   if (isp[n]) {\r\n            for (int k = n * n; k <= N; k += n * n) {\r\n\
    \                isp[k] = false;\r\n            }\r\n        }\r\n    isp[2] =\
    \ isp[3] = true;\r\n\r\n    vector<int> ret;\r\n    for (int i = 2; i <= N; i++)\r\
    \n        if (isp[i]) {\r\n            ret.push_back(i);\r\n        }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/lucydp.hpp\"\
    \n\r\ntemplate <typename T, T (*F)(ll)> struct LucyDP {\r\n    ll N, SQ, sz;\r\
    \n    vector<ll> quo;\r\n    vector<T> dat;\r\n    static inline pair<vector<ll>,\
    \ vector<int>> gen(ll n) {\r\n        ll sq = sqrtl(n);\r\n        vector<ll>\
    \ quo(sq + n / (sq + 1));\r\n        iota(ALL(quo), 1);\r\n        for (ll i =\
    \ sq, x = n / (sq + 1); x; x--, i++)\r\n            quo[i] = n / x;\r\n      \
    \  auto ps = sieve(sq);\r\n        return {quo, ps};\r\n    }\r\n    LucyDP()\
    \ {}\r\n    LucyDP(ll n, vector<ll> &_quo, vector<int> &ps)\r\n        : N(n),\
    \ SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(_quo), dat(sz) {\r\n        rep(i,\
    \ 0, sz) dat[i] = F(quo[i]) - 1;\r\n        for (auto &p : ps) {\r\n         \
    \   T coe = dat[p - 1] - dat[p - 2];\r\n            for (int i = sz - 1;; i--)\
    \ {\r\n                if (quo[i] < ll(p) * p)\r\n                    break;\r\
    \n                dat[i] -= (dat[idx(quo[i] / p)] - dat[p - 2]) * coe;\r\n   \
    \         }\r\n        }\r\n    }\r\n    T operator[](ll x) {\r\n        return\
    \ dat[idx(x)];\r\n    }\r\n\r\n  private:\r\n    int idx(ll x) const {\r\n   \
    \     if (x <= SQ)\r\n            return x - 1;\r\n        else\r\n          \
    \  return sz - N / x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Prime Sum\r\n * @docs\
    \ docs/primesum.md\r\n */\n"
  code: "#pragma once\r\n#include \"Math/sieve.hpp\"\r\n\r\ntemplate <typename T,\
    \ T (*F)(ll)> struct LucyDP {\r\n    ll N, SQ, sz;\r\n    vector<ll> quo;\r\n\
    \    vector<T> dat;\r\n    static inline pair<vector<ll>, vector<int>> gen(ll\
    \ n) {\r\n        ll sq = sqrtl(n);\r\n        vector<ll> quo(sq + n / (sq + 1));\r\
    \n        iota(ALL(quo), 1);\r\n        for (ll i = sq, x = n / (sq + 1); x; x--,\
    \ i++)\r\n            quo[i] = n / x;\r\n        auto ps = sieve(sq);\r\n    \
    \    return {quo, ps};\r\n    }\r\n    LucyDP() {}\r\n    LucyDP(ll n, vector<ll>\
    \ &_quo, vector<int> &ps)\r\n        : N(n), SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)),\
    \ quo(_quo), dat(sz) {\r\n        rep(i, 0, sz) dat[i] = F(quo[i]) - 1;\r\n  \
    \      for (auto &p : ps) {\r\n            T coe = dat[p - 1] - dat[p - 2];\r\n\
    \            for (int i = sz - 1;; i--) {\r\n                if (quo[i] < ll(p)\
    \ * p)\r\n                    break;\r\n                dat[i] -= (dat[idx(quo[i]\
    \ / p)] - dat[p - 2]) * coe;\r\n            }\r\n        }\r\n    }\r\n    T operator[](ll\
    \ x) {\r\n        return dat[idx(x)];\r\n    }\r\n\r\n  private:\r\n    int idx(ll\
    \ x) const {\r\n        if (x <= SQ)\r\n            return x - 1;\r\n        else\r\
    \n            return sz - N / x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Prime\
    \ Sum\r\n * @docs docs/primesum.md\r\n */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/lucydp.hpp
  requiredBy: []
  timestamp: '2025-06-29 02:34:27+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/YUKI_1781.test.cpp
  - Verify/LC_counting_primes.test.cpp
documentation_of: Math/lucydp.hpp
layout: document
redirect_from:
- /library/Math/lucydp.hpp
- /library/Math/lucydp.hpp.html
title: Prime Sum
---
## 使い方

`PrimeSum(ll n)`: テンプレートには
* `T`: 返り値の型
* `T (*F)(ll)`: **完全乗法的関数** $f$ のprefix sumを返す関数
を指定。

`T operator[](ll x)`: $\sum_{p \leq x:\mbox{prime}} f(p)$ を出力。 $x=\lfloor n/d \rfloor$ で表される必要がある。