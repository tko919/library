---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/fastdiv.hpp
    title: Fast Division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Stirling Number for query
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * @brief Fast\
    \ Division\n*/\n#line 3 \"Math/stirlingquery.hpp\"\n\r\nclass StirlingNumberQuery{\r\
    \n    const int p;\r\n    FastDiv ip;\r\n    vector<vector<int>> binom,F,S;\r\n\
    \    ll nCr(ll n,ll k){\r\n        if(n<0 or k<0 or n<k)return 0;\r\n        ll\
    \ res=1;\r\n        while(n){\r\n            res=(res*binom[n%ip][k%ip])%ip;\r\
    \n            n/=p; k/=p;\r\n        }\r\n        return res;\r\n    }\r\npublic:\r\
    \n    StirlingNumberQuery(int _p):p(_p),ip(p){\r\n        binom.resize(p,vector<int>(p));\r\
    \n        F.resize(p,vector<int>(p));\r\n        S.resize(p,vector<int>(p));\r\
    \n        binom[0][0]=F[0][0]=S[0][0]=1;\r\n        rep(n,1,p)rep(k,0,n+1){\r\n\
    \            if(k)binom[n][k]=binom[n-1][k-1];\r\n            binom[n][k]=(binom[n][k]+binom[n-1][k])%ip;\r\
    \n\r\n            if(k)F[n][k]=F[n-1][k-1];\r\n            F[n][k]=(F[n][k]+ll(p-n+1)*F[n-1][k])%ip;\r\
    \n            \r\n            if(k)S[n][k]=S[n-1][k-1];\r\n            S[n][k]=(S[n][k]+ll(k)*S[n-1][k])%ip;\r\
    \n        }\r\n    }\r\n    int FirstKind(ll n,ll k){\r\n        if(n<0 or k<0\
    \ or k>n)return 0;\r\n        ll i=n/ip,j=n%ip;\r\n        if(k<i)return 0;\r\n\
    \        ll a=(k-i)/(p-1),b=(k-i)%(p-1);\r\n        if(b==0 and j)b+=p-1,a--;\r\
    \n        if(a<0 or a>i or b>j)return 0;\r\n        int res=(nCr(i,a)*F[j][b])%ip;\r\
    \n        if((i+a)&1)res=(p-res)%ip;\r\n        return res;\r\n    }\r\n    int\
    \ SecondKind(ll n,ll k){\r\n        if(n<0 or k<0 or k>n)return 0;\r\n       \
    \ if(n==0)return 1;\r\n        ll i=k/ip,j=k%ip;\r\n        if(n<i)return 0;\r\
    \n        ll a=(n-i)/(p-1),b=(n-i)%(p-1);\r\n        if(b==0)b+=p-1,a--;\r\n \
    \       if(a<0 or b<j)return 0;\r\n        if(b==p-1 and j==0)return nCr(a,i-1);\r\
    \n        else return (nCr(a,i)*S[b][j])%ip;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Stirling Number for query\r\n */\n"
  code: "#pragma once\r\n#include \"Math/fastdiv.hpp\"\r\n\r\nclass StirlingNumberQuery{\r\
    \n    const int p;\r\n    FastDiv ip;\r\n    vector<vector<int>> binom,F,S;\r\n\
    \    ll nCr(ll n,ll k){\r\n        if(n<0 or k<0 or n<k)return 0;\r\n        ll\
    \ res=1;\r\n        while(n){\r\n            res=(res*binom[n%ip][k%ip])%ip;\r\
    \n            n/=p; k/=p;\r\n        }\r\n        return res;\r\n    }\r\npublic:\r\
    \n    StirlingNumberQuery(int _p):p(_p),ip(p){\r\n        binom.resize(p,vector<int>(p));\r\
    \n        F.resize(p,vector<int>(p));\r\n        S.resize(p,vector<int>(p));\r\
    \n        binom[0][0]=F[0][0]=S[0][0]=1;\r\n        rep(n,1,p)rep(k,0,n+1){\r\n\
    \            if(k)binom[n][k]=binom[n-1][k-1];\r\n            binom[n][k]=(binom[n][k]+binom[n-1][k])%ip;\r\
    \n\r\n            if(k)F[n][k]=F[n-1][k-1];\r\n            F[n][k]=(F[n][k]+ll(p-n+1)*F[n-1][k])%ip;\r\
    \n            \r\n            if(k)S[n][k]=S[n-1][k-1];\r\n            S[n][k]=(S[n][k]+ll(k)*S[n-1][k])%ip;\r\
    \n        }\r\n    }\r\n    int FirstKind(ll n,ll k){\r\n        if(n<0 or k<0\
    \ or k>n)return 0;\r\n        ll i=n/ip,j=n%ip;\r\n        if(k<i)return 0;\r\n\
    \        ll a=(k-i)/(p-1),b=(k-i)%(p-1);\r\n        if(b==0 and j)b+=p-1,a--;\r\
    \n        if(a<0 or a>i or b>j)return 0;\r\n        int res=(nCr(i,a)*F[j][b])%ip;\r\
    \n        if((i+a)&1)res=(p-res)%ip;\r\n        return res;\r\n    }\r\n    int\
    \ SecondKind(ll n,ll k){\r\n        if(n<0 or k<0 or k>n)return 0;\r\n       \
    \ if(n==0)return 1;\r\n        ll i=k/ip,j=k%ip;\r\n        if(n<i)return 0;\r\
    \n        ll a=(n-i)/(p-1),b=(n-i)%(p-1);\r\n        if(b==0)b+=p-1,a--;\r\n \
    \       if(a<0 or b<j)return 0;\r\n        if(b==p-1 and j==0)return nCr(a,i-1);\r\
    \n        else return (nCr(a,i)*S[b][j])%ip;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Stirling Number for query\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  isVerificationFile: false
  path: Math/stirlingquery.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_stirling_number_of_the_second_kind_small_p_large_n.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind_small_p_large_n.test.cpp
documentation_of: Math/stirlingquery.hpp
layout: document
redirect_from:
- /library/Math/stirlingquery.hpp
- /library/Math/stirlingquery.hpp.html
title: Stirling Number for query
---
