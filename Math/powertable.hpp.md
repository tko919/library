---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Enumrate $n^k$
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/powertable.hpp\"\
    \n\ntemplate<typename T>vector<T> powertable(int n,ll k){ //0^k,1^k,..,n^k\n \
    \   assert(k>=0);\n    auto ps=sieve(n+1);\n    vector<T> f(n+1,1);\n    if(k)f[0]=0;\n\
    \    for(auto& p:ps){\n        T pk=T(p).pow(k);\n        for(ll q=p;q<=n;q*=p){\n\
    \            for(ll i=q;i<=n;i+=q)f[i]*=pk;\n        }\n    }\n    return f;\n\
    }\n\n/**\n * @brief Enumrate $n^k$\n*/\n"
  code: "#pragma once\n#include \"Math/sieve.hpp\"\n\ntemplate<typename T>vector<T>\
    \ powertable(int n,ll k){ //0^k,1^k,..,n^k\n    assert(k>=0);\n    auto ps=sieve(n+1);\n\
    \    vector<T> f(n+1,1);\n    if(k)f[0]=0;\n    for(auto& p:ps){\n        T pk=T(p).pow(k);\n\
    \        for(ll q=p;q<=n;q*=p){\n            for(ll i=q;i<=n;i+=q)f[i]*=pk;\n\
    \        }\n    }\n    return f;\n}\n\n/**\n * @brief Enumrate $n^k$\n*/"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/powertable.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:58:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
documentation_of: Math/powertable.hpp
layout: document
redirect_from:
- /library/Math/powertable.hpp
- /library/Math/powertable.hpp.html
title: Enumrate $n^k$
---
