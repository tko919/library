---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/divisor.hpp
    title: Divisor Multiple Transform
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_enumerate_primes.test.cpp
    title: Verify/LC_enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_gcd_convolution.test.cpp
    title: Verify/LC_gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_lcm_convolution.test.cpp
    title: Verify/LC_lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Prime Sieve
    links: []
  bundledCode: "#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=1010101>vector<int>\
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<int L=1010101>vector<int> sieve(int N){\r\n\
    \    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int z=1;z<=5;z+=4){\r\
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve.hpp
  requiredBy:
  - Convolution/divisor.hpp
  timestamp: '2022-01-22 19:43:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_gcd_convolution.test.cpp
  - Verify/LC_enumerate_primes.test.cpp
  - Verify/LC_lcm_convolution.test.cpp
documentation_of: Math/sieve.hpp
layout: document
redirect_from:
- /library/Math/sieve.hpp
- /library/Math/sieve.hpp.html
title: Prime Sieve
---