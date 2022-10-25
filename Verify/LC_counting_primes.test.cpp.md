---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/primesum.hpp
    title: Prime Sum
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"Verify/LC_counting_primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/counting_primes\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=1010101>vector<int> sieve(int\
    \ N){\r\n    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int z=1;z<=5;z+=4){\r\
    \n        for(int y=z;y<=sq;y+=6){\r\n            for(int x=1;x<=sq and (n=4*x*x+y*y)<=N;++x){\r\
    \n                isp[n].flip();\r\n            }\r\n            for(int x=y+1;x<=sq\
    \ and (n=3*x*x-y*y)<=N;x+=2){\r\n                isp[n].flip();\r\n          \
    \  }\r\n        }\r\n    }\r\n    for(int z=2;z<=4;z+=2){\r\n        for(int y=z;y<=sq;y+=6){\r\
    \n            for (int x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){\r\n             \
    \   isp[n].flip();\r\n            }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\
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
    \ */\n#line 5 \"Verify/LC_counting_primes.test.cpp\"\n\r\nll F(ll x){return x;}\r\
    \n\r\nint main(){\r\n    ll n;\r\n    cin>>n;\r\n    PrimeSum<ll,F> pc(n);\r\n\
    \    cout<<pc[n]<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Math/primesum.hpp\"\r\n\r\n\
    ll F(ll x){return x;}\r\n\r\nint main(){\r\n    ll n;\r\n    cin>>n;\r\n    PrimeSum<ll,F>\
    \ pc(n);\r\n    cout<<pc[n]<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/primesum.hpp
  - Math/sieve.hpp
  isVerificationFile: true
  path: Verify/LC_counting_primes.test.cpp
  requiredBy: []
  timestamp: '2022-10-24 03:44:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_counting_primes.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_counting_primes.test.cpp
- /verify/Verify/LC_counting_primes.test.cpp.html
title: Verify/LC_counting_primes.test.cpp
---
