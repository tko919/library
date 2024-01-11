---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate $\sum_{k=0}^{N-1} k^i$
    links: []
  bundledCode: "#line 2 \"FPS/prefixsumofpowers.hpp\"\n\ntemplate<typename T>vector<T>\
    \ PrefixSumOfPowers(ll n,int k){ // 0<=i<=k,sum_n=0^{N-1} n^i\n    Poly<T> num(k+1),den(k+1);\n\
    \    num[0]=n,den[0]=1;\n    rep(i,0,k)num[i+1]=num[i]*n;\n    rep(i,0,k+1){\n\
    \        num[i]*=Fact<T>(i+1,1);\n        den[i]=Fact<T>(i+1,1);\n    }\n    num*=den.inv();\n\
    \    num.resize(k+1);\n    rep(i,0,k+1)num[i]*=Fact<T>(i);\n    return num;\n\
    }\n\n/**\n * @brief Enumerate $\\sum_{k=0}^{N-1} k^i$\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>vector<T> PrefixSumOfPowers(ll n,int\
    \ k){ // 0<=i<=k,sum_n=0^{N-1} n^i\n    Poly<T> num(k+1),den(k+1);\n    num[0]=n,den[0]=1;\n\
    \    rep(i,0,k)num[i+1]=num[i]*n;\n    rep(i,0,k+1){\n        num[i]*=Fact<T>(i+1,1);\n\
    \        den[i]=Fact<T>(i+1,1);\n    }\n    num*=den.inv();\n    num.resize(k+1);\n\
    \    rep(i,0,k+1)num[i]*=Fact<T>(i);\n    return num;\n}\n\n/**\n * @brief Enumerate\
    \ $\\sum_{k=0}^{N-1} k^i$\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/prefixsumofpowers.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/prefixsumofpowers.hpp
layout: document
redirect_from:
- /library/FPS/prefixsumofpowers.hpp
- /library/FPS/prefixsumofpowers.hpp.html
title: Enumerate $\sum_{k=0}^{N-1} k^i$
---
