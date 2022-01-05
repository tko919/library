---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Bitwise Convolution
    links: []
  bundledCode: "#line 2 \"Convolution/bitwise.hpp\"\n\r\ntemplate<typename T>void\
    \ zeta(vector<T>& a){\r\n    int n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\
    \n        if(mask>>k&1)a[mask]+=a[mask^(1<<k)];\r\n    }\r\n}\r\ntemplate<typename\
    \ T>void mobius(vector<T>& a){\r\n    int n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\
    \n        if(mask>>k&1)a[mask]-=a[mask^(1<<k)];\r\n    }\r\n}\r\ntemplate<typename\
    \ T>void fwt(vector<T>& a){\r\n    int n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\
    \n        if(!(mask>>k&1)){\r\n            T x=a[mask],y=a[mask|(1<<k)];\r\n \
    \           a[mask]=x+y,a[mask|(1<<k)]=x-y;\r\n        }\r\n    }\r\n}\r\n\r\n\
    /**\r\n * @brief Bitwise Convolution\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>void zeta(vector<T>& a){\r\n    int\
    \ n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\n        if(mask>>k&1)a[mask]+=a[mask^(1<<k)];\r\
    \n    }\r\n}\r\ntemplate<typename T>void mobius(vector<T>& a){\r\n    int n=__lg(a.size());\r\
    \n    rep(k,0,n)rep(mask,0,1<<n){\r\n        if(mask>>k&1)a[mask]-=a[mask^(1<<k)];\r\
    \n    }\r\n}\r\ntemplate<typename T>void fwt(vector<T>& a){\r\n    int n=__lg(a.size());\r\
    \n    rep(k,0,n)rep(mask,0,1<<n){\r\n        if(!(mask>>k&1)){\r\n           \
    \ T x=a[mask],y=a[mask|(1<<k)];\r\n            a[mask]=x+y,a[mask|(1<<k)]=x-y;\r\
    \n        }\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Bitwise Convolution\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/bitwise.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Convolution/bitwise.hpp
layout: document
redirect_from:
- /library/Convolution/bitwise.hpp
- /library/Convolution/bitwise.hpp.html
title: Bitwise Convolution
---
