---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1781.test.cpp
    title: Verify/YUKI_1781.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative.md
    document_title: Multiplicative Sum
    links: []
  bundledCode: "#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=50101010>vector<int>\
    \ sieve(int N){\r\n    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int\
    \ z=1;z<=5;z+=4){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for(int x=1;x<=sq\
    \ and (n=4*x*x+y*y)<=N;++x){\r\n                isp[n].flip();\r\n           \
    \ }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\n       \
    \         isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n    for(int\
    \ z=2;z<=4;z+=2){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for (int\
    \ x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){\r\n                isp[n].flip();\r\n\
    \            }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\
    \n                isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n  \
    \  for(int y=3;y<=sq;y+=6){\r\n        for(int z=1;z<=2;++z){\r\n            for(int\
    \ x=z;x<=sq and (n=4*x*x+y*y)<=N;x+=3){\r\n                isp[n].flip();\r\n\
    \            }\r\n        }\r\n    }\r\n    for(int n=5;n<=sq;++n)if(isp[n]){\r\
    \n        for(int k=n*n;k<=N;k+=n*n){\r\n            isp[k]=false;\r\n       \
    \ }\r\n    }\r\n    isp[2]=isp[3]=true;\r\n\r\n    vector<int> ret;\r\n    for(int\
    \ i=2;i<=N;i++)if(isp[i]){\r\n        ret.push_back(i);\r\n    }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/multiplicative.hpp\"\
    \n\r\ntemplate <typename T, T (*pe)(int, int), T (*psum)(ll)>\r\nT MultiplicativeSum(ll\
    \ N) {\r\n    class Array {\r\n        std::vector<T> data;\r\n        std::vector<int>\
    \ written;\r\n\r\n      public:\r\n        int n;\r\n        Array(int n) : data(n),\
    \ n(n) {}\r\n        void add(int i, T val) {\r\n            data[i] += val;\r\
    \n            written.push_back(i);\r\n        }\r\n        void lazy(vector<T>\
    \ &base) {\r\n            for (auto i : written) {\r\n                base[i]\
    \ += data[i];\r\n                data[i] = 0;\r\n            }\r\n           \
    \ written.clear();\r\n        }\r\n    };\r\n\r\n    ll SQ = sqrtl(N);\r\n   \
    \ vector<T> lo(SQ + 1), hi(SQ + 1);\r\n    rep(i, 1, SQ + 1) {\r\n        lo[i]\
    \ = psum(i);\r\n        hi[i] = psum(N / i);\r\n    }\r\n\r\n    auto ps = sieve(SQ);\r\
    \n    reverse(ALL(ps));\r\n    Array loa(SQ + 1), hia(SQ + 1);\r\n    for (auto\
    \ &p : ps) {\r\n        if (ll(p) * p > N)\r\n            break;\r\n        ll\
    \ c = 1, pc = p;\r\n        while (N / p >= pc) {\r\n            T x = pe(p, c),\
    \ y = pe(p, c + 1), z = psum(p);\r\n            rep(i, 1, SQ + 1) {\r\n      \
    \          ll k = double(N) / (i * pc);\r\n                if (k < p)\r\n    \
    \                break;\r\n                if (k <= SQ)\r\n                  \
    \  hia.add(i, x * (lo[k] - z) + y);\r\n                else\r\n              \
    \      hia.add(i, x * (hi[i * pc] - z) + y);\r\n            }\r\n            rrep(i,\
    \ 1, SQ + 1) {\r\n                int k = double(i) / pc;\r\n                if\
    \ (k < p)\r\n                    break;\r\n                loa.add(i, x * (lo[k]\
    \ - z) + y);\r\n            }\r\n            c++;\r\n            pc *= p;\r\n\
    \        }\r\n        loa.lazy(lo);\r\n        hia.lazy(hi);\r\n    }\r\n    return\
    \ hi[1] + 1;\r\n}\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs docs/multiplicative.md\r\
    \n */\n"
  code: "#pragma once\r\n#include \"Math/sieve.hpp\"\r\n\r\ntemplate <typename T,\
    \ T (*pe)(int, int), T (*psum)(ll)>\r\nT MultiplicativeSum(ll N) {\r\n    class\
    \ Array {\r\n        std::vector<T> data;\r\n        std::vector<int> written;\r\
    \n\r\n      public:\r\n        int n;\r\n        Array(int n) : data(n), n(n)\
    \ {}\r\n        void add(int i, T val) {\r\n            data[i] += val;\r\n  \
    \          written.push_back(i);\r\n        }\r\n        void lazy(vector<T> &base)\
    \ {\r\n            for (auto i : written) {\r\n                base[i] += data[i];\r\
    \n                data[i] = 0;\r\n            }\r\n            written.clear();\r\
    \n        }\r\n    };\r\n\r\n    ll SQ = sqrtl(N);\r\n    vector<T> lo(SQ + 1),\
    \ hi(SQ + 1);\r\n    rep(i, 1, SQ + 1) {\r\n        lo[i] = psum(i);\r\n     \
    \   hi[i] = psum(N / i);\r\n    }\r\n\r\n    auto ps = sieve(SQ);\r\n    reverse(ALL(ps));\r\
    \n    Array loa(SQ + 1), hia(SQ + 1);\r\n    for (auto &p : ps) {\r\n        if\
    \ (ll(p) * p > N)\r\n            break;\r\n        ll c = 1, pc = p;\r\n     \
    \   while (N / p >= pc) {\r\n            T x = pe(p, c), y = pe(p, c + 1), z =\
    \ psum(p);\r\n            rep(i, 1, SQ + 1) {\r\n                ll k = double(N)\
    \ / (i * pc);\r\n                if (k < p)\r\n                    break;\r\n\
    \                if (k <= SQ)\r\n                    hia.add(i, x * (lo[k] - z)\
    \ + y);\r\n                else\r\n                    hia.add(i, x * (hi[i *\
    \ pc] - z) + y);\r\n            }\r\n            rrep(i, 1, SQ + 1) {\r\n    \
    \            int k = double(i) / pc;\r\n                if (k < p)\r\n       \
    \             break;\r\n                loa.add(i, x * (lo[k] - z) + y);\r\n \
    \           }\r\n            c++;\r\n            pc *= p;\r\n        }\r\n   \
    \     loa.lazy(lo);\r\n        hia.lazy(hi);\r\n    }\r\n    return hi[1] + 1;\r\
    \n}\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs docs/multiplicative.md\r\
    \n */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/multiplicative.hpp
  requiredBy: []
  timestamp: '2024-09-19 03:09:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
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