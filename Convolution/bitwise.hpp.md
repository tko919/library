---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_bitwise_and_convolution.test.cpp
    title: Verify/LC_bitwise_and_convolution.test.cpp
  - icon: ':x:'
    path: Verify/LC_bitwise_xor_convolution.test.cpp
    title: Verify/LC_bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/bitwise.md
    document_title: Bitwise Convolution
    links: []
  bundledCode: "#line 2 \"Convolution/bitwise.hpp\"\n\r\nnamespace Bitwise{\r\n  \
    \  template<typename T>void zeta(vector<T>& a){\r\n        int n=__lg(a.size());\r\
    \n        rep(k,0,n)rep(mask,0,1<<n){\r\n            if(mask>>k&1)a[mask]+=a[mask^(1<<k)];\r\
    \n        }\r\n    }\r\n    template<typename T>void mobius(vector<T>& a){\r\n\
    \        int n=__lg(a.size());\r\n        rep(k,0,n)rep(mask,0,1<<n){\r\n    \
    \        if(mask>>k&1)a[mask]-=a[mask^(1<<k)];\r\n        }\r\n    }\r\n    template<typename\
    \ T>void fwt(vector<T>& a){\r\n        int n=__lg(a.size());\r\n        rep(k,0,n)rep(mask,0,1<<n){\r\
    \n            if(!(mask>>k&1)){\r\n                T x=a[mask],y=a[mask|(1<<k)];\r\
    \n                a[mask]=x+y,a[mask|(1<<k)]=x-y;\r\n            }\r\n       \
    \ }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Bitwise Convolution\r\n * @docs docs/bitwise.md\r\
    \n */\n"
  code: "#pragma once\r\n\r\nnamespace Bitwise{\r\n    template<typename T>void zeta(vector<T>&\
    \ a){\r\n        int n=__lg(a.size());\r\n        rep(k,0,n)rep(mask,0,1<<n){\r\
    \n            if(mask>>k&1)a[mask]+=a[mask^(1<<k)];\r\n        }\r\n    }\r\n\
    \    template<typename T>void mobius(vector<T>& a){\r\n        int n=__lg(a.size());\r\
    \n        rep(k,0,n)rep(mask,0,1<<n){\r\n            if(mask>>k&1)a[mask]-=a[mask^(1<<k)];\r\
    \n        }\r\n    }\r\n    template<typename T>void fwt(vector<T>& a){\r\n  \
    \      int n=__lg(a.size());\r\n        rep(k,0,n)rep(mask,0,1<<n){\r\n      \
    \      if(!(mask>>k&1)){\r\n                T x=a[mask],y=a[mask|(1<<k)];\r\n\
    \                a[mask]=x+y,a[mask|(1<<k)]=x-y;\r\n            }\r\n        }\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Bitwise Convolution\r\n * @docs docs/bitwise.md\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/bitwise.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_bitwise_xor_convolution.test.cpp
  - Verify/LC_bitwise_and_convolution.test.cpp
documentation_of: Convolution/bitwise.hpp
layout: document
redirect_from:
- /library/Convolution/bitwise.hpp
- /library/Convolution/bitwise.hpp.html
title: Bitwise Convolution
---
## 使い方

`void zeta(vector<T>& a)`: $a'[n]=\sum_{k \subset n} a[k]$ を計算。  
`void mobius(vector<T>& a)`: $a[n]=\sum_{k \subset n} a'[k]$ を計算。  
`void fwt(vector<T>& a)`: $a$ と $n$ 次 Hadamard 行列の積を計算。