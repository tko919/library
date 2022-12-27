---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Math/fastdiv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_floor_of_linear.test.cpp
    title: Verify/LC_sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/floorsum.md
    document_title: Floor Sum
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * Fast Division\n\
    */\n#line 3 \"Math/floorsum.hpp\"\n\r\nll FloorSum(ll n,ll a,ll b,ll m){\r\n \
    \  //sum_{k=0}^{n-1} [(a*k+b)/m]\r\n   FastDiv im(m);\r\n   ll res=0;\r\n   if(a>=m)res-=(a/im)*n*(n-1)/2,a-=a/im*m;\r\
    \n   else if(a<0)res+=((-a+m-1)/im)*n*(n-1)/2,a+=((-a+m-1)/im)*m;\r\n   if(b>=m)res-=(b/im)*n,b-=b/im*m;\r\
    \n   else if(b<0)res+=((-b+m-1)/im)*n,b+=((-b+m-1)/im)*m;\r\n   \r\n   while(1){\r\
    \n      ll y_max=a*n+b;\r\n      if(y_max<m)break;\r\n      n=y_max/im;\r\n  \
    \    b=y_max%im;\r\n      res+=(n*(n-1)/2)*(m/a)+n*(b/a);\r\n      swap(m,a);\r\
    \n      a=a%im;\r\n      b=b%im;\r\n   }\r\n   return res;\r\n}\r\n\r\n/**\r\n\
    \ * @brief Floor Sum\r\n * @docs docs/floorsum.md\r\n */\n"
  code: "#pragma once\r\n#include \"Math/fastdiv.hpp\"\r\n\r\nll FloorSum(ll n,ll\
    \ a,ll b,ll m){\r\n   //sum_{k=0}^{n-1} [(a*k+b)/m]\r\n   FastDiv im(m);\r\n \
    \  ll res=0;\r\n   if(a>=m)res-=(a/im)*n*(n-1)/2,a-=a/im*m;\r\n   else if(a<0)res+=((-a+m-1)/im)*n*(n-1)/2,a+=((-a+m-1)/im)*m;\r\
    \n   if(b>=m)res-=(b/im)*n,b-=b/im*m;\r\n   else if(b<0)res+=((-b+m-1)/im)*n,b+=((-b+m-1)/im)*m;\r\
    \n   \r\n   while(1){\r\n      ll y_max=a*n+b;\r\n      if(y_max<m)break;\r\n\
    \      n=y_max/im;\r\n      b=y_max%im;\r\n      res+=(n*(n-1)/2)*(m/a)+n*(b/a);\r\
    \n      swap(m,a);\r\n      a=a%im;\r\n      b=b%im;\r\n   }\r\n   return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Floor Sum\r\n * @docs docs/floorsum.md\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  isVerificationFile: false
  path: Math/floorsum.hpp
  requiredBy: []
  timestamp: '2022-12-28 03:34:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_floor_of_linear.test.cpp
documentation_of: Math/floorsum.hpp
layout: document
redirect_from:
- /library/Math/floorsum.hpp
- /library/Math/floorsum.hpp.html
title: Floor Sum
---
## 使い方

`ll FloorSum(ll n,ll a,ll b,ll m)`: $\sum_{k=0}^{n-1} \lfloor \frac{ak+b}{m} \rfloor$ を計算。