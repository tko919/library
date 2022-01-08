---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_factorize.test.cpp
    title: Verify/LC_factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Pollard-Rho
    links: []
  bundledCode: "#line 2 \"Math/miller.hpp\"\n\r\nbool Miller(ll n){\r\n    if(n<2\
    \ or (n&1)==0)return (n==2);\r\n    ll d=n-1; while((d&1)==0)d>>=1;\r\n    vector<ll>\
    \ seeds;\r\n    auto MP=[&](ll x,ll t,ll m)->ll{\r\n        ll res=1;\r\n    \
    \    while(t){\r\n            if(t&1)res=(__int128_t(res)*x)%m;\r\n          \
    \  x=(__int128_t(x)*x)%m; t>>=1;\r\n        } return res;\r\n    };\r\n    if(n<(1<<30))seeds={2,\
    \ 7, 61};\r\n    else seeds={2, 325, 9375, 28178, 450775, 9780504};\r\n    for(auto&\
    \ x:seeds){\r\n        if(n<=x)break;\r\n        ll t=d,y=MP(x,t,n);\r\n     \
    \   while(t!=n-1 and y!=1 and y!=n-1){\r\n            y=(__int128_t(y)*y)%n; t<<=1;\r\
    \n        }\r\n        if(y!=n-1 and (t&1)==0)return 0;\r\n    } return 1;\r\n\
    }\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n#line 3 \"Math/pollard.hpp\"\n\r\
    \nmt19937 RND(1341398);\r\nvector<ll> Pollard(ll n){\r\n    if(n<=1)return {};\r\
    \n    if(Miller(n))return {n};\r\n    if((n&1)==0){\r\n        vector<ll> v=Pollard(n>>1);\
    \ v.push_back(2);\r\n        return v;\r\n    }\r\n    for(ll x=2,y=2,d;;){\r\n\
    \        ll c=RND()%(n-2)+2;\r\n        do{\r\n            x=(__int128_t(x)*x+c)%n;\r\
    \n            y=(__int128_t(y)*y+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\
    \n            d=__gcd(x-y+n,n);\r\n        }while(d==1);\r\n        if(d<n){\r\
    \n            vector<ll> lb=Pollard(d),rb=Pollard(n/d);\r\n            lb.insert(lb.end(),ALL(rb));\
    \ return lb;\r\n        }\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n\
    \ */\n"
  code: "#pragma once\r\n#include \"Math/miller.hpp\"\r\n\r\nmt19937 RND(1341398);\r\
    \nvector<ll> Pollard(ll n){\r\n    if(n<=1)return {};\r\n    if(Miller(n))return\
    \ {n};\r\n    if((n&1)==0){\r\n        vector<ll> v=Pollard(n>>1); v.push_back(2);\r\
    \n        return v;\r\n    }\r\n    for(ll x=2,y=2,d;;){\r\n        ll c=RND()%(n-2)+2;\r\
    \n        do{\r\n            x=(__int128_t(x)*x+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\
    \n            y=(__int128_t(y)*y+c)%n;\r\n            d=__gcd(x-y+n,n);\r\n  \
    \      }while(d==1);\r\n        if(d<n){\r\n            vector<ll> lb=Pollard(d),rb=Pollard(n/d);\r\
    \n            lb.insert(lb.end(),ALL(rb)); return lb;\r\n        }\r\n    }\r\n\
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */"
  dependsOn:
  - Math/miller.hpp
  isVerificationFile: false
  path: Math/pollard.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_factorize.test.cpp
documentation_of: Math/pollard.hpp
layout: document
redirect_from:
- /library/Math/pollard.hpp
- /library/Math/pollard.hpp.html
title: Pollard-Rho
---
