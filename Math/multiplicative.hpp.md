---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/YUKI_1781.test.cpp
    title: Verify/YUKI_1781.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/multiplicative.md
    document_title: Multiplicative Sum
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/multiplicative.hpp\"\
    \n\r\ntemplate <typename T, T (*pe)(int, int), T (*psum)(ll)>\r\nstruct MultiplicativeSum\
    \ {\r\n    ll N, SQ, sz;\r\n    vector<ll> quo;\r\n    vector<T> dat, add, rui;\r\
    \n    MultiplicativeSum(ll n = 0)\r\n        : N(n), SQ(sqrtl(N)), sz(SQ + n /\
    \ (SQ + 1)), quo(sz), dat(sz), add(sz),\r\n          rui(sz) {\r\n        iota(ALL(quo),\
    \ 1);\r\n        for (ll i = SQ, x = N / (SQ + 1); x; x--, i++)\r\n          \
    \  quo[i] = n / x;\r\n        rep(i, 0, sz) rui[i] = dat[i] = psum(quo[i]);\r\n\
    \r\n        auto ps = sieve(SQ);\r\n        reverse(ALL(ps));\r\n        for (auto\
    \ &p : ps) {\r\n            T pc = pe(p, 1);\r\n            for (ll pw = p, c\
    \ = 1; N / p >= pw; pw *= p, c++) {\r\n                T nxt = pe(p, c + 1);\r\
    \n                rrep(j, 0, sz) {\r\n                    if (quo[j] < pw * p)\r\
    \n                        break;\r\n                    add[j] += pc * (dat[idx(quo[j]\
    \ / pw)] - rui[p - 1]) + nxt;\r\n                }\r\n                pc = nxt;\r\
    \n            }\r\n            rrep(j, 0, sz) {\r\n                if (quo[j]\
    \ < ll(p) * p)\r\n                    break;\r\n                dat[j] += add[j];\r\
    \n                add[j] = 0;\r\n            }\r\n        }\r\n        rep(i,\
    \ 0, sz) dat[i] += 1;\r\n    }\r\n    T operator[](ll x) {\r\n        return dat[idx(x)];\r\
    \n    }\r\n\r\n  private:\r\n    int idx(ll x) const {\r\n        if (x <= SQ)\r\
    \n            return x - 1;\r\n        else\r\n            return sz - N / x;\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs docs/multiplicative.md\r\
    \n */\n"
  code: "#pragma once\r\n#include \"Math/sieve.hpp\"\r\n\r\ntemplate <typename T,\
    \ T (*pe)(int, int), T (*psum)(ll)>\r\nstruct MultiplicativeSum {\r\n    ll N,\
    \ SQ, sz;\r\n    vector<ll> quo;\r\n    vector<T> dat, add, rui;\r\n    MultiplicativeSum(ll\
    \ n = 0)\r\n        : N(n), SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(sz), dat(sz),\
    \ add(sz),\r\n          rui(sz) {\r\n        iota(ALL(quo), 1);\r\n        for\
    \ (ll i = SQ, x = N / (SQ + 1); x; x--, i++)\r\n            quo[i] = n / x;\r\n\
    \        rep(i, 0, sz) rui[i] = dat[i] = psum(quo[i]);\r\n\r\n        auto ps\
    \ = sieve(SQ);\r\n        reverse(ALL(ps));\r\n        for (auto &p : ps) {\r\n\
    \            T pc = pe(p, 1);\r\n            for (ll pw = p, c = 1; N / p >= pw;\
    \ pw *= p, c++) {\r\n                T nxt = pe(p, c + 1);\r\n               \
    \ rrep(j, 0, sz) {\r\n                    if (quo[j] < pw * p)\r\n           \
    \             break;\r\n                    add[j] += pc * (dat[idx(quo[j] / pw)]\
    \ - rui[p - 1]) + nxt;\r\n                }\r\n                pc = nxt;\r\n \
    \           }\r\n            rrep(j, 0, sz) {\r\n                if (quo[j] <\
    \ ll(p) * p)\r\n                    break;\r\n                dat[j] += add[j];\r\
    \n                add[j] = 0;\r\n            }\r\n        }\r\n        rep(i,\
    \ 0, sz) dat[i] += 1;\r\n    }\r\n    T operator[](ll x) {\r\n        return dat[idx(x)];\r\
    \n    }\r\n\r\n  private:\r\n    int idx(ll x) const {\r\n        if (x <= SQ)\r\
    \n            return x - 1;\r\n        else\r\n            return sz - N / x;\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs docs/multiplicative.md\r\
    \n */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/multiplicative.hpp
  requiredBy: []
  timestamp: '2025-06-29 11:23:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/YUKI_1781.test.cpp
documentation_of: Math/multiplicative.hpp
layout: document
redirect_from:
- /library/Math/multiplicative.hpp
- /library/Math/multiplicative.hpp.html
title: Multiplicative Sum
---
## 使い方

`T MultiplicativeSum(ll N)`: **乗法的関数** $f$ について $\sum_{k=1}^N f(k)$ を計算する。テンプレートには
* `T`: 返り値の型
* `T (*pe)(int p,int e)`: $f(p^e)$ を返す関数
* `T (*psum)(ll x)`: $\sum_{p \leq x:\mbox{prime}} f(p)$ を返す関数 ( $x$ は $\lfloor N/d \rfloor$ の形に限られる)

`T AdditiveSum(ll n)`: 上の $f$ が **加法的関数** である場合。