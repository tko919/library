---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: FPS/factlarge.hpp
    title: Factorial (Large)
  - icon: ':warning:'
    path: FPS/p-recursive.hpp
    title: P-recursive
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_many_factorials.test.cpp
    title: Verify/LC_many_factorials.test.cpp
  - icon: ':x:'
    path: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Shift of Sampling Points of Polynomial
    links: []
  bundledCode: "#line 2 \"FPS/samplepointshift.hpp\"\n\ntemplate<typename T>Poly<T>\
    \ SamplePointsShift(vector<T>& ys,T c,int m=-1){\n    ll n=ys.size()-1,C=c.v%T::get_mod();\n\
    \    if(m==-1)m=n+1;\n    if(C<=n){\n        Poly<T> res;\n        rep(i,C,n+1)res.push_back(ys[i]);\n\
    \        if(int(res.size())>=m){\n            res.resize(m);\n            return\
    \ res;\n        }\n        auto add=SamplePointsShift<T>(ys,n+1,m-res.size());\n\
    \        for(int i=0;int(res.size())<m;i++){\n            res.push_back(add[i]);\n\
    \        }\n        return res;\n    }\n    if(C+m>T::get_mod()){\n        auto\
    \ res=SamplePointsShift<T>(ys,c,T::get_mod()-c.v);\n        auto add=SamplePointsShift<T>(ys,0,m-res.size());\n\
    \        rep(i,0,add.size())res.push_back(add[i]);\n        return res;\n    }\n\
    \n    Poly<T> A(n+1),B(m+n);\n    rep(i,0,n+1){\n        A[i]=ys[i]*Fact<T>(i,1)*Fact<T>(n-i,1);\n\
    \        if((n-i)&1)A[i]=-A[i];\n    }\n    rep(i,0,m+n)B[i]=Fp(1)/(c-n+i);\n\
    \    auto AB=A*B;\n    vector<T> res(m);\n    Fp base=1;\n    rep(x,0,n+1)base*=(c-x);\n\
    \    rep(i,0,m){\n        res[i]=AB[n+i]*base;\n        base*=(c+i+1);\n     \
    \   base*=B[i];\n    }\n    return res;\n}\n\n/**\n * @brief Shift of Sampling\
    \ Points of Polynomial\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>Poly<T> SamplePointsShift(vector<T>&\
    \ ys,T c,int m=-1){\n    ll n=ys.size()-1,C=c.v%T::get_mod();\n    if(m==-1)m=n+1;\n\
    \    if(C<=n){\n        Poly<T> res;\n        rep(i,C,n+1)res.push_back(ys[i]);\n\
    \        if(int(res.size())>=m){\n            res.resize(m);\n            return\
    \ res;\n        }\n        auto add=SamplePointsShift<T>(ys,n+1,m-res.size());\n\
    \        for(int i=0;int(res.size())<m;i++){\n            res.push_back(add[i]);\n\
    \        }\n        return res;\n    }\n    if(C+m>T::get_mod()){\n        auto\
    \ res=SamplePointsShift<T>(ys,c,T::get_mod()-c.v);\n        auto add=SamplePointsShift<T>(ys,0,m-res.size());\n\
    \        rep(i,0,add.size())res.push_back(add[i]);\n        return res;\n    }\n\
    \n    Poly<T> A(n+1),B(m+n);\n    rep(i,0,n+1){\n        A[i]=ys[i]*Fact<T>(i,1)*Fact<T>(n-i,1);\n\
    \        if((n-i)&1)A[i]=-A[i];\n    }\n    rep(i,0,m+n)B[i]=Fp(1)/(c-n+i);\n\
    \    auto AB=A*B;\n    vector<T> res(m);\n    Fp base=1;\n    rep(x,0,n+1)base*=(c-x);\n\
    \    rep(i,0,m){\n        res[i]=AB[n+i]*base;\n        base*=(c+i+1);\n     \
    \   base*=B[i];\n    }\n    return res;\n}\n\n/**\n * @brief Shift of Sampling\
    \ Points of Polynomial\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/samplepointshift.hpp
  requiredBy:
  - FPS/factlarge.hpp
  - FPS/p-recursive.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_many_factorials.test.cpp
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: FPS/samplepointshift.hpp
layout: document
redirect_from:
- /library/FPS/samplepointshift.hpp
- /library/FPS/samplepointshift.hpp.html
title: Shift of Sampling Points of Polynomial
---
