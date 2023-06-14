---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_counting_primes.test.cpp
    title: Verify/LC_counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1781.test.cpp
    title: Verify/YUKI_1781.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/primesum.md
    document_title: Prime Sum
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/primesum.hpp\"\
    \n\r\ntemplate<typename T,T (*F)(ll)>struct PrimeSum{\r\n    ll N,SQ;\r\n    vector<T>\
    \ lo,hi;\r\n    PrimeSum(ll n=0):N(n),SQ(sqrtl(N)),lo(SQ+1),hi(SQ+1){\r\n    \
    \    rep(i,1,SQ+1){\r\n            lo[i]=F(i)-1;\r\n            hi[i]=F(N/i)-1;\r\
    \n        }\r\n        auto ps=sieve(SQ);\r\n        for(auto& p:ps){\r\n    \
    \        ll q=ll(p)*p;\r\n            if(q>N)break;\r\n            T sub=lo[p-1],fp=lo[p]-lo[p-1];\r\
    \n            ll L=min(SQ,N/q),M=SQ/p;\r\n            rep(i,1,M+1)hi[i]-=fp*(hi[i*p]-sub);\r\
    \n            rep(i,M+1,L+1)hi[i]-=fp*(lo[double(N)/(i*p)]-sub);\r\n         \
    \   for(int i=SQ;i>=q;i--)lo[i]-=fp*(lo[double(i)/p]-sub);\r\n        }\r\n  \
    \  }\r\n    T operator[](ll x) {\r\n        return (x<=SQ?lo[x]:hi[N/x]);\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Prime Sum\r\n * @docs docs/primesum.md\r\n\
    \ */\n"
  code: "#pragma once\r\n#include \"Math/sieve.hpp\"\r\n\r\ntemplate<typename T,T\
    \ (*F)(ll)>struct PrimeSum{\r\n    ll N,SQ;\r\n    vector<T> lo,hi;\r\n    PrimeSum(ll\
    \ n=0):N(n),SQ(sqrtl(N)),lo(SQ+1),hi(SQ+1){\r\n        rep(i,1,SQ+1){\r\n    \
    \        lo[i]=F(i)-1;\r\n            hi[i]=F(N/i)-1;\r\n        }\r\n       \
    \ auto ps=sieve(SQ);\r\n        for(auto& p:ps){\r\n            ll q=ll(p)*p;\r\
    \n            if(q>N)break;\r\n            T sub=lo[p-1],fp=lo[p]-lo[p-1];\r\n\
    \            ll L=min(SQ,N/q),M=SQ/p;\r\n            rep(i,1,M+1)hi[i]-=fp*(hi[i*p]-sub);\r\
    \n            rep(i,M+1,L+1)hi[i]-=fp*(lo[double(N)/(i*p)]-sub);\r\n         \
    \   for(int i=SQ;i>=q;i--)lo[i]-=fp*(lo[double(i)/p]-sub);\r\n        }\r\n  \
    \  }\r\n    T operator[](ll x) {\r\n        return (x<=SQ?lo[x]:hi[N/x]);\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Prime Sum\r\n * @docs docs/primesum.md\r\n\
    \ */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/primesum.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_counting_primes.test.cpp
  - Verify/YUKI_1781.test.cpp
documentation_of: Math/primesum.hpp
layout: document
redirect_from:
- /library/Math/primesum.hpp
- /library/Math/primesum.hpp.html
title: Prime Sum
---
## 使い方

`PrimeSum(ll n)`: テンプレートには
* `T`: 返り値の型
* `T (*F)(ll)`: **完全乗法的関数** $f$ のprefix sumを返す関数
を指定。

`T operator[](ll x)`: $\sum_{p \leq x:\mbox{prime}} f(p)$ を出力。 $x=\lfloor n/d \rfloor$ で表される必要がある。