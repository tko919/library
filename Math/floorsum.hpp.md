---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sum_of_floor_of_linear.test.cpp
    title: Verify/LC_sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Floor Sum
    links: []
  bundledCode: "#line 2 \"Math/floorsum.hpp\"\n\r\nll FloorSum(ll n,ll a,ll b,ll m){\r\
    \n   //sum_{k=0}^{n-1} [(a*k+b)/m]\r\n   ll res=0;\r\n   while(1){\r\n      ll\
    \ y_max=a*n+b;\r\n      if(y_max<m)break;\r\n      n=y_max/m;\r\n      b=y_max%m;\r\
    \n      res+=(n*(n-1)/2)*(m/a)+n*(b/a);\r\n      swap(m,a);\r\n      a%=m;\r\n\
    \      b%=m;\r\n   }\r\n   return res;\r\n}\r\n\r\n/**\r\n * @brief Floor Sum\r\
    \n */\n"
  code: "#pragma once\r\n\r\nll FloorSum(ll n,ll a,ll b,ll m){\r\n   //sum_{k=0}^{n-1}\
    \ [(a*k+b)/m]\r\n   ll res=0;\r\n   while(1){\r\n      ll y_max=a*n+b;\r\n   \
    \   if(y_max<m)break;\r\n      n=y_max/m;\r\n      b=y_max%m;\r\n      res+=(n*(n-1)/2)*(m/a)+n*(b/a);\r\
    \n      swap(m,a);\r\n      a%=m;\r\n      b%=m;\r\n   }\r\n   return res;\r\n\
    }\r\n\r\n/**\r\n * @brief Floor Sum\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/floorsum.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_sum_of_floor_of_linear.test.cpp
documentation_of: Math/floorsum.hpp
layout: document
redirect_from:
- /library/Math/floorsum.hpp
- /library/Math/floorsum.hpp.html
title: Floor Sum
---
