---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: Math/bbla.hpp
    title: Black Box Linear Algebra
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_find_linear_recurrence.test.cpp
    title: Verify/LC_find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sparse_matrix_det.test.cpp
    title: Verify/LC_sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Berlekamp Massey Algorithm
    links: []
  bundledCode: "#line 2 \"FPS/berlekampmassey.hpp\"\n\r\ntemplate<typename T>vector<T>\
    \ BerlekampMassey(vector<T>& a){\r\n   int n=a.size(); T d=1;\r\n   vector<T>\
    \ b(1),c(1);\r\n   b[0]=c[0]=1;\r\n   rep(j,1,n+1){\r\n      int l=c.size(),m=b.size();\r\
    \n      T x=0;\r\n      rep(i,0,l)x+=c[i]*a[j-l+i];\r\n      b.push_back(0);\r\
    \n      m++;\r\n      if(x==0)continue;\r\n      T coeff=-x/d;\r\n      if(l<m){\r\
    \n         auto tmp=c;\r\n         c.insert(c.begin(),m-l,0);\r\n         rep(i,0,m)c[m-1-i]+=coeff*b[m-1-i];\r\
    \n         b=tmp; d=x;\r\n      }\r\n      else rep(i,0,m)c[l-1-i]+=coeff*b[m-1-i];\r\
    \n   }\r\n   return c;\r\n}\r\n\r\n/**\r\n * @brief Berlekamp Massey Algorithm\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>vector<T> BerlekampMassey(vector<T>&\
    \ a){\r\n   int n=a.size(); T d=1;\r\n   vector<T> b(1),c(1);\r\n   b[0]=c[0]=1;\r\
    \n   rep(j,1,n+1){\r\n      int l=c.size(),m=b.size();\r\n      T x=0;\r\n   \
    \   rep(i,0,l)x+=c[i]*a[j-l+i];\r\n      b.push_back(0);\r\n      m++;\r\n   \
    \   if(x==0)continue;\r\n      T coeff=-x/d;\r\n      if(l<m){\r\n         auto\
    \ tmp=c;\r\n         c.insert(c.begin(),m-l,0);\r\n         rep(i,0,m)c[m-1-i]+=coeff*b[m-1-i];\r\
    \n         b=tmp; d=x;\r\n      }\r\n      else rep(i,0,m)c[l-1-i]+=coeff*b[m-1-i];\r\
    \n   }\r\n   return c;\r\n}\r\n\r\n/**\r\n * @brief Berlekamp Massey Algorithm\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/berlekampmassey.hpp
  requiredBy:
  - Math/bbla.hpp
  timestamp: '2022-01-10 02:39:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_find_linear_recurrence.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/LC_sparse_matrix_det.test.cpp
documentation_of: FPS/berlekampmassey.hpp
layout: document
redirect_from:
- /library/FPS/berlekampmassey.hpp
- /library/FPS/berlekampmassey.hpp.html
title: Berlekamp Massey Algorithm
---
