---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"Math/multiplicative.hpp\"\n\r\ntemplate <typename T, T (*pe)(int,\
    \ int), T (*psum)(ll)>\r\nstruct MultiplicativeSum {\r\n    ll N, SQ, sz;\r\n\
    \    vector<ll> quo;\r\n    vector<T> dat;\r\n    MultiplicativeSum() {}\r\n \
    \   MultiplicativeSum(ll n, vector<ll> &_quo, vector<int> &ps)\r\n        : N(n),\
    \ SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(_quo), dat(sz) {\r\n        rep(i,\
    \ 0, sz) dat[i] = psum(quo[i]);\r\n\r\n        reverse(ALL(ps));\r\n        vector<T>\
    \ ndat = dat;\r\n        for (auto &p : ps) {\r\n            T pc = pe(p, 1);\r\
    \n            T rui = psum(p);\r\n            int L = sz;\r\n            for (ll\
    \ pw = p, c = 1; N / p >= pw; pw *= p, c++) {\r\n                T nxt = pe(p,\
    \ c + 1);\r\n                rrep(j, 0, sz) {\r\n                    if (quo[j]\
    \ < pw * p) {\r\n                        chmin(L, j + 1);\r\n                \
    \        break;\r\n                    }\r\n                    ndat[j] += pc\
    \ * (dat[idx(quo[j] / pw)] - rui) + nxt;\r\n                }\r\n            \
    \    pc = nxt;\r\n            }\r\n            copy(ndat.begin() + L, ndat.end(),\
    \ dat.begin() + L);\r\n        }\r\n        rep(i, 0, sz) dat[i] += 1;\r\n   \
    \ }\r\n    T operator[](ll x) {\r\n        return dat[idx(x)];\r\n    }\r\n\r\n\
    \  private:\r\n    int idx(ll x) const {\r\n        if (x <= SQ)\r\n         \
    \   return x - 1;\r\n        else\r\n            return sz - N / x;\r\n    }\r\
    \n};\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs docs/multiplicative.md\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, T (*pe)(int, int), T (*psum)(ll)>\r\
    \nstruct MultiplicativeSum {\r\n    ll N, SQ, sz;\r\n    vector<ll> quo;\r\n \
    \   vector<T> dat;\r\n    MultiplicativeSum() {}\r\n    MultiplicativeSum(ll n,\
    \ vector<ll> &_quo, vector<int> &ps)\r\n        : N(n), SQ(sqrtl(N)), sz(SQ +\
    \ n / (SQ + 1)), quo(_quo), dat(sz) {\r\n        rep(i, 0, sz) dat[i] = psum(quo[i]);\r\
    \n\r\n        reverse(ALL(ps));\r\n        vector<T> ndat = dat;\r\n        for\
    \ (auto &p : ps) {\r\n            T pc = pe(p, 1);\r\n            T rui = psum(p);\r\
    \n            int L = sz;\r\n            for (ll pw = p, c = 1; N / p >= pw; pw\
    \ *= p, c++) {\r\n                T nxt = pe(p, c + 1);\r\n                rrep(j,\
    \ 0, sz) {\r\n                    if (quo[j] < pw * p) {\r\n                 \
    \       chmin(L, j + 1);\r\n                        break;\r\n               \
    \     }\r\n                    ndat[j] += pc * (dat[idx(quo[j] / pw)] - rui) +\
    \ nxt;\r\n                }\r\n                pc = nxt;\r\n            }\r\n\
    \            copy(ndat.begin() + L, ndat.end(), dat.begin() + L);\r\n        }\r\
    \n        rep(i, 0, sz) dat[i] += 1;\r\n    }\r\n    T operator[](ll x) {\r\n\
    \        return dat[idx(x)];\r\n    }\r\n\r\n  private:\r\n    int idx(ll x) const\
    \ {\r\n        if (x <= SQ)\r\n            return x - 1;\r\n        else\r\n \
    \           return sz - N / x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Multiplicative\
    \ Sum\r\n * @docs docs/multiplicative.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/multiplicative.hpp
  requiredBy: []
  timestamp: '2025-06-29 02:34:27+00:00'
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