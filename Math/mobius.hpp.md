---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/divisor.hpp
    title: Divisor Multiple Transform
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mobius table
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Convolution/divisor.hpp\"\
    \n\r\nnamespace DivisorTransform{\r\n    int n;\r\n    vector<int> ps;\r\n   \
    \ template<typename T>void zeta(vector<T>& a){\r\n        int N=a.size()-1;\r\n\
    \        if(n<N){\r\n            ps=sieve(N);\r\n            n=N;\r\n        }\r\
    \n        for(auto& p:ps){\r\n            for(int k=1;k*p<=N;k++)a[k*p]+=a[k];\r\
    \n        }\r\n    }\r\n    template<typename T>void mobius(vector<T>& a){\r\n\
    \        int N=a.size()-1;\r\n        if(n<N){\r\n            ps=sieve(N);\r\n\
    \            n=N;\r\n        }\r\n        for(auto& p:ps){\r\n            for(int\
    \ k=N/p;k;k--)a[k*p]-=a[k];\r\n        }\r\n    }\r\n};\r\n\r\nnamespace MultipleTransform{\r\
    \n    int n;\r\n    vector<int> ps;\r\n    template<typename T>void zeta(vector<T>&\
    \ a){\r\n        int N=a.size()-1;\r\n        if(n<N){\r\n            ps=sieve(N);\r\
    \n            n=N;\r\n        }\r\n        for(auto& p:ps){\r\n            for(int\
    \ k=N/p;k;k--)a[k]+=a[k*p];\r\n        }\r\n    }\r\n    template<typename T>void\
    \ mobius(vector<T>& a){\r\n        int N=a.size()-1;\r\n        if(n<N){\r\n \
    \           ps=sieve(N);\r\n            n=N;\r\n        }\r\n        for(auto&\
    \ p:ps){\r\n            for(int k=1;k*p<=N;k++)a[k]-=a[k*p];\r\n        }\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Divisor Multiple Transform\r\n * @docs docs/divisor.md\r\
    \n */\n#line 3 \"Math/mobius.hpp\"\n\nvector<int> Mobius(ll n) {\n    vector<int>\
    \ mu(n + 1);\n    mu[1] = 1;\n    DivisorTransform::mobius(mu);\n    return mu;\n\
    }\n\n/**\n * @brief Mobius table\n */\n"
  code: "#pragma once\n#include \"Convolution/divisor.hpp\"\n\nvector<int> Mobius(ll\
    \ n) {\n    vector<int> mu(n + 1);\n    mu[1] = 1;\n    DivisorTransform::mobius(mu);\n\
    \    return mu;\n}\n\n/**\n * @brief Mobius table\n */"
  dependsOn:
  - Convolution/divisor.hpp
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/mobius.hpp
  requiredBy: []
  timestamp: '2024-12-26 05:48:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/mobius.hpp
layout: document
redirect_from:
- /library/Math/mobius.hpp
- /library/Math/mobius.hpp.html
title: Mobius table
---
