---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/primecount.hpp
    title: Prime Count
  - icon: ':question:'
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
    \ 0;}\n#line 2 \"Math/primecount.hpp\"\n\r\nstruct PrimeCount{\r\n    const ll\
    \ N; const ll M;\r\n    vector<int> lo; vector<ll> hi;\r\n    PrimeCount(const\
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
    \n\r\n/**\r\n * @brief Prime Count\r\n */\n#line 5 \"Verify/LC_counting_primes.test.cpp\"\
    \n\r\nint main(){\r\n    ll n;\r\n    cin>>n;\r\n    PrimeCount pc(n);\r\n   \
    \ cout<<pc.pi(n)<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Math/primecount.hpp\"\r\n\r\
    \nint main(){\r\n    ll n;\r\n    cin>>n;\r\n    PrimeCount pc(n);\r\n    cout<<pc.pi(n)<<'\\\
    n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/primecount.hpp
  isVerificationFile: true
  path: Verify/LC_counting_primes.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_counting_primes.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_counting_primes.test.cpp
- /verify/Verify/LC_counting_primes.test.cpp.html
title: Verify/LC_counting_primes.test.cpp
---
