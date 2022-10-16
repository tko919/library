---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Stirling Number for query
    links: []
  bundledCode: "#line 2 \"Math/stirlingquery.hpp\"\n\r\nclass StirlingNumberQuery{\r\
    \n    const int p;\r\n    vector<vector<int>> binom,F,S;\r\n    ll nCr(ll n,ll\
    \ k){\r\n        if(n<0 or k<0 or n<k)return 0;\r\n        ll res=1;\r\n     \
    \   while(n){\r\n            res=(res*binom[n%p][k%p])%p;\r\n            n/=p;\
    \ k/=p;\r\n        }\r\n        return res;\r\n    }\r\npublic:\r\n    StirlingNumberQuery(int\
    \ _p):p(_p){\r\n        binom.resize(p,vector<int>(p));\r\n        F.resize(p,vector<int>(p));\r\
    \n        S.resize(p,vector<int>(p));\r\n        binom[0][0]=F[0][0]=S[0][0]=1;\r\
    \n        rep(n,1,p)rep(k,0,n+1){\r\n            if(k)binom[n][k]=binom[n-1][k-1];\r\
    \n            binom[n][k]=(binom[n][k]+binom[n-1][k])%p;\r\n\r\n            if(k)F[n][k]=F[n-1][k-1];\r\
    \n            F[n][k]=(F[n][k]+ll(p-n+1)*F[n-1][k])%p;\r\n            \r\n   \
    \         if(k)S[n][k]=S[n-1][k-1];\r\n            S[n][k]=(S[n][k]+ll(k)*S[n-1][k])%p;\r\
    \n        }\r\n    }\r\n    int FirstKind(ll n,ll k){\r\n        if(n<0 or k<0\
    \ or k>n)return 0;\r\n        ll i=n/p,j=n%p;\r\n        if(k<i)return 0;\r\n\
    \        ll a=(k-i)/(p-1),b=(k-i)%(p-1);\r\n        if(b==0 and j)b+=p-1,a--;\r\
    \n        if(a<0 or a>i or b>j)return 0;\r\n        int res=(nCr(i,a)*F[j][b])%p;\r\
    \n        if((i+a)&1)res=(p-res)%p;\r\n        return res;\r\n    }\r\n    int\
    \ SecondKind(ll n,ll k){\r\n        if(n<0 or k<0 or k>n)return 0;\r\n       \
    \ if(n==0)return 1;\r\n        ll i=k/p,j=k%p;\r\n        if(n<i)return 0;\r\n\
    \        ll a=(n-i)/(p-1),b=(n-i)%(p-1);\r\n        if(b==0)b+=p-1,a--;\r\n  \
    \      if(a<0 or b<j)return 0;\r\n        if(b==p-1 and j==0)return nCr(a,i-1);\r\
    \n        else return (nCr(a,i)*S[b][j])%p;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Stirling Number for query\r\n */\n"
  code: "#pragma once\r\n\r\nclass StirlingNumberQuery{\r\n    const int p;\r\n  \
    \  vector<vector<int>> binom,F,S;\r\n    ll nCr(ll n,ll k){\r\n        if(n<0\
    \ or k<0 or n<k)return 0;\r\n        ll res=1;\r\n        while(n){\r\n      \
    \      res=(res*binom[n%p][k%p])%p;\r\n            n/=p; k/=p;\r\n        }\r\n\
    \        return res;\r\n    }\r\npublic:\r\n    StirlingNumberQuery(int _p):p(_p){\r\
    \n        binom.resize(p,vector<int>(p));\r\n        F.resize(p,vector<int>(p));\r\
    \n        S.resize(p,vector<int>(p));\r\n        binom[0][0]=F[0][0]=S[0][0]=1;\r\
    \n        rep(n,1,p)rep(k,0,n+1){\r\n            if(k)binom[n][k]=binom[n-1][k-1];\r\
    \n            binom[n][k]=(binom[n][k]+binom[n-1][k])%p;\r\n\r\n            if(k)F[n][k]=F[n-1][k-1];\r\
    \n            F[n][k]=(F[n][k]+ll(p-n+1)*F[n-1][k])%p;\r\n            \r\n   \
    \         if(k)S[n][k]=S[n-1][k-1];\r\n            S[n][k]=(S[n][k]+ll(k)*S[n-1][k])%p;\r\
    \n        }\r\n    }\r\n    int FirstKind(ll n,ll k){\r\n        if(n<0 or k<0\
    \ or k>n)return 0;\r\n        ll i=n/p,j=n%p;\r\n        if(k<i)return 0;\r\n\
    \        ll a=(k-i)/(p-1),b=(k-i)%(p-1);\r\n        if(b==0 and j)b+=p-1,a--;\r\
    \n        if(a<0 or a>i or b>j)return 0;\r\n        int res=(nCr(i,a)*F[j][b])%p;\r\
    \n        if((i+a)&1)res=(p-res)%p;\r\n        return res;\r\n    }\r\n    int\
    \ SecondKind(ll n,ll k){\r\n        if(n<0 or k<0 or k>n)return 0;\r\n       \
    \ if(n==0)return 1;\r\n        ll i=k/p,j=k%p;\r\n        if(n<i)return 0;\r\n\
    \        ll a=(n-i)/(p-1),b=(n-i)%(p-1);\r\n        if(b==0)b+=p-1,a--;\r\n  \
    \      if(a<0 or b<j)return 0;\r\n        if(b==p-1 and j==0)return nCr(a,i-1);\r\
    \n        else return (nCr(a,i)*S[b][j])%p;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Stirling Number for query\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/stirlingquery.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/stirlingquery.hpp
layout: document
redirect_from:
- /library/Math/stirlingquery.hpp
- /library/Math/stirlingquery.hpp.html
title: Stirling Number for query
---
