---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':warning:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
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
    }\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n#line 2 \"Utility/random.hpp\"\n\
    \r\nstruct Random{\r\n    random_device rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\
    \n    Random(){}\r\n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n \
    \       x=y,y=z,z=w;\r\n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n\
    \    unsigned get(unsigned L){\r\n        return get()%(L+1);\r\n    }\r\n   \
    \ template<typename T>T get(T L,T R){\r\n        return get(R-L)+L;\r\n    }\r\
    \n    double uniform(){\r\n        return double(get())/UINT_MAX;\r\n    }\r\n\
    \    string str(int n){\r\n        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\
    \n        return ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter\
    \ first,Iter last){\r\n        if(first==last)return;\r\n        int len=1;\r\n\
    \        for(auto it=first+1;it!=last;it++){\r\n            len++;\r\n       \
    \     int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\n\
    \        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 4 \"Math/pollard.hpp\"\n\r\nRandom genPollard;\r\nvector<ll> Pollard(ll\
    \ n){\r\n    if(n<=1)return {};\r\n    if(Miller(n))return {n};\r\n    if((n&1)==0){\r\
    \n        vector<ll> v=Pollard(n>>1); v.push_back(2);\r\n        return v;\r\n\
    \    }\r\n    for(ll x=2,y=2,d;;){\r\n        ll c=genPollard.get(2LL,n-1);\r\n\
    \        do{\r\n            x=(__int128_t(x)*x+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\
    \n            y=(__int128_t(y)*y+c)%n;\r\n            d=__gcd(x-y+n,n);\r\n  \
    \      }while(d==1);\r\n        if(d<n){\r\n            vector<ll> lb=Pollard(d),rb=Pollard(n/d);\r\
    \n            lb.insert(lb.end(),ALL(rb)); return lb;\r\n        }\r\n    }\r\n\
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n"
  code: "#pragma once\r\n#include \"Math/miller.hpp\"\r\n#include \"Utility/random.hpp\"\
    \r\n\r\nRandom genPollard;\r\nvector<ll> Pollard(ll n){\r\n    if(n<=1)return\
    \ {};\r\n    if(Miller(n))return {n};\r\n    if((n&1)==0){\r\n        vector<ll>\
    \ v=Pollard(n>>1); v.push_back(2);\r\n        return v;\r\n    }\r\n    for(ll\
    \ x=2,y=2,d;;){\r\n        ll c=genPollard.get(2LL,n-1);\r\n        do{\r\n  \
    \          x=(__int128_t(x)*x+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\n\
    \            y=(__int128_t(y)*y+c)%n;\r\n            d=__gcd(x-y+n,n);\r\n   \
    \     }while(d==1);\r\n        if(d<n){\r\n            vector<ll> lb=Pollard(d),rb=Pollard(n/d);\r\
    \n            lb.insert(lb.end(),ALL(rb)); return lb;\r\n        }\r\n    }\r\n\
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */"
  dependsOn:
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/pollard.hpp
  requiredBy:
  - Convolution/multivariatecyclic.hpp
  - Math/binomquery.hpp
  - Math/primitive.hpp
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_factorize.test.cpp
  - Verify/LC_discrete_logarithm_mod.test.cpp
documentation_of: Math/pollard.hpp
layout: document
redirect_from:
- /library/Math/pollard.hpp
- /library/Math/pollard.hpp.html
title: Pollard-Rho
---
