---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_factorize.test.cpp
    title: Verify/LC_factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Miller-Rabin
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
    }\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n"
  code: "#pragma once\r\n\r\nbool Miller(ll n){\r\n    if(n<2 or (n&1)==0)return (n==2);\r\
    \n    ll d=n-1; while((d&1)==0)d>>=1;\r\n    vector<ll> seeds;\r\n    auto MP=[&](ll\
    \ x,ll t,ll m)->ll{\r\n        ll res=1;\r\n        while(t){\r\n            if(t&1)res=(__int128_t(res)*x)%m;\r\
    \n            x=(__int128_t(x)*x)%m; t>>=1;\r\n        } return res;\r\n    };\r\
    \n    if(n<(1<<30))seeds={2, 7, 61};\r\n    else seeds={2, 325, 9375, 28178, 450775,\
    \ 9780504};\r\n    for(auto& x:seeds){\r\n        if(n<=x)break;\r\n        ll\
    \ t=d,y=MP(x,t,n);\r\n        while(t!=n-1 and y!=1 and y!=n-1){\r\n         \
    \   y=(__int128_t(y)*y)%n; t<<=1;\r\n        }\r\n        if(y!=n-1 and (t&1)==0)return\
    \ 0;\r\n    } return 1;\r\n}\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/miller.hpp
  requiredBy:
  - Math/pollard.hpp
  - Math/primitive.hpp
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_factorize.test.cpp
documentation_of: Math/miller.hpp
layout: document
redirect_from:
- /library/Math/miller.hpp
- /library/Math/miller.hpp.html
title: Miller-Rabin
---
