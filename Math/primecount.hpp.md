---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Prime Count(Lucy's DP)
    links: []
  bundledCode: "#line 2 \"Math/primecount.hpp\"\n\r\nstruct PrimeCount{\r\n    const\
    \ ll N; const ll M;\r\n    vector<int> lo; vector<ll> hi;\r\n    PrimeCount(const\
    \ ll& _N):N(_N),M(int(sqrt(N))),lo(M+1),hi(M+1){\r\n        rep(i,1,M+1)lo[i]=i-1,hi[i]=N/i-1;\r\
    \n        int cnt=0;\r\n        for(int p=2;p<=M;p++){\r\n            if(lo[p-1]==lo[p])continue;\r\
    \n            const ll n=N/p;\r\n            const ll q=ll(p)*p;\r\n         \
    \   const int w=M/p;\r\n            const ll L=min(M,N/q);\r\n            for(int\
    \ i=1;i<=w;i++)hi[i]-=hi[i*p]-cnt;\r\n            const int t=min<int>(sqrt(n),L);\r\
    \n            for(int i=w+1;i<=t;i++)hi[i]-=lo[n/i]-cnt;\r\n            for(int\
    \ i=L,j=n/L;i>t;j++){\r\n                int c=lo[j];\r\n                while(j+1<=M\
    \ and lo[j+1]==c)j++;\r\n                c-=cnt;\r\n                for(int e=max<int>(t,n/(j+1));i>e;i--)hi[i]-=c;\r\
    \n            }\r\n            for(int i=M,j=M/p;j>=p;j--){\r\n              \
    \  const int c=lo[j]-cnt;\r\n                for(int e=j*p;i>=e;i--)lo[i]-=c;\r\
    \n            }\r\n            cnt++;\r\n        }\r\n    }\r\n    ll pi(ll x){\r\
    \n        if(x<=M)return lo[x];\r\n        else return hi[N/x];\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Prime Count(Lucy's DP)\r\n */\n"
  code: "#pragma once\r\n\r\nstruct PrimeCount{\r\n    const ll N; const ll M;\r\n\
    \    vector<int> lo; vector<ll> hi;\r\n    PrimeCount(const ll& _N):N(_N),M(int(sqrt(N))),lo(M+1),hi(M+1){\r\
    \n        rep(i,1,M+1)lo[i]=i-1,hi[i]=N/i-1;\r\n        int cnt=0;\r\n       \
    \ for(int p=2;p<=M;p++){\r\n            if(lo[p-1]==lo[p])continue;\r\n      \
    \      const ll n=N/p;\r\n            const ll q=ll(p)*p;\r\n            const\
    \ int w=M/p;\r\n            const ll L=min(M,N/q);\r\n            for(int i=1;i<=w;i++)hi[i]-=hi[i*p]-cnt;\r\
    \n            const int t=min<int>(sqrt(n),L);\r\n            for(int i=w+1;i<=t;i++)hi[i]-=lo[n/i]-cnt;\r\
    \n            for(int i=L,j=n/L;i>t;j++){\r\n                int c=lo[j];\r\n\
    \                while(j+1<=M and lo[j+1]==c)j++;\r\n                c-=cnt;\r\
    \n                for(int e=max<int>(t,n/(j+1));i>e;i--)hi[i]-=c;\r\n        \
    \    }\r\n            for(int i=M,j=M/p;j>=p;j--){\r\n                const int\
    \ c=lo[j]-cnt;\r\n                for(int e=j*p;i>=e;i--)lo[i]-=c;\r\n       \
    \     }\r\n            cnt++;\r\n        }\r\n    }\r\n    ll pi(ll x){\r\n  \
    \      if(x<=M)return lo[x];\r\n        else return hi[N/x];\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Prime Count(Lucy's DP)\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/primecount.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/primecount.hpp
layout: document
redirect_from:
- /library/Math/primecount.hpp
- /library/Math/primecount.hpp.html
title: Prime Count(Lucy's DP)
---
