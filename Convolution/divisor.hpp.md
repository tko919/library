---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/mobius.hpp
    title: Mobius table
  - icon: ':warning:'
    path: Math/totient.hpp
    title: lpf table
  _extendedVerifiedWith:
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
    _deprecated_at_docs: docs/divisor.md
    document_title: Divisor Multiple Transform
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
    \n */\n"
  code: "#pragma once\r\n#include \"Math/sieve.hpp\"\r\n\r\nnamespace DivisorTransform{\r\
    \n    int n;\r\n    vector<int> ps;\r\n    template<typename T>void zeta(vector<T>&\
    \ a){\r\n        int N=a.size()-1;\r\n        if(n<N){\r\n            ps=sieve(N);\r\
    \n            n=N;\r\n        }\r\n        for(auto& p:ps){\r\n            for(int\
    \ k=1;k*p<=N;k++)a[k*p]+=a[k];\r\n        }\r\n    }\r\n    template<typename\
    \ T>void mobius(vector<T>& a){\r\n        int N=a.size()-1;\r\n        if(n<N){\r\
    \n            ps=sieve(N);\r\n            n=N;\r\n        }\r\n        for(auto&\
    \ p:ps){\r\n            for(int k=N/p;k;k--)a[k*p]-=a[k];\r\n        }\r\n   \
    \ }\r\n};\r\n\r\nnamespace MultipleTransform{\r\n    int n;\r\n    vector<int>\
    \ ps;\r\n    template<typename T>void zeta(vector<T>& a){\r\n        int N=a.size()-1;\r\
    \n        if(n<N){\r\n            ps=sieve(N);\r\n            n=N;\r\n       \
    \ }\r\n        for(auto& p:ps){\r\n            for(int k=N/p;k;k--)a[k]+=a[k*p];\r\
    \n        }\r\n    }\r\n    template<typename T>void mobius(vector<T>& a){\r\n\
    \        int N=a.size()-1;\r\n        if(n<N){\r\n            ps=sieve(N);\r\n\
    \            n=N;\r\n        }\r\n        for(auto& p:ps){\r\n            for(int\
    \ k=1;k*p<=N;k++)a[k]-=a[k*p];\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Divisor Multiple Transform\r\n * @docs docs/divisor.md\r\n */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Convolution/divisor.hpp
  requiredBy:
  - Math/totient.hpp
  - Math/mobius.hpp
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_lcm_convolution.test.cpp
  - Verify/LC_gcd_convolution.test.cpp
documentation_of: Convolution/divisor.hpp
layout: document
redirect_from:
- /library/Convolution/divisor.hpp
- /library/Convolution/divisor.hpp.html
title: Divisor Multiple Transform
---
## 使い方

`void DivisorTransform::zeta(vector<T>& a)`: $a'[n]=\sum_{n \bmod d=0} a[d]$ を計算。 `mobius(vector<T>& a)` は逆変換。  
`void MultipleTransform::zeta(vector<T>& a)`: $a'[n]=\sum_{k \bmod n=0} a[k]$ を計算。 `mobius(vector<T>& a)` は逆変換。