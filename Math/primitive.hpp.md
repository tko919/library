---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Primitive Function
    links: []
  bundledCode: "#line 2 \"Math/primitive.hpp\"\n\r\nll mpow(ll a,ll t,ll m){\r\n \
    \   ll res=1;\r\n    while(t){\r\n        if(t&1)res=(res*a)%m;\r\n        a=(a*a)%m;\
    \ t>>=1;\r\n    } return res;\r\n}\r\nll minv(ll a,ll m){\r\n    ll b=m,u=1,v=0;\r\
    \n    while(b){\r\n        ll t=a/b;\r\n        a-=t*b; swap(a,b);\r\n       \
    \ u-=t*v; swap(u,v);\r\n    } u=(u%m+m)%m; return u;\r\n}\r\nll getPrimitiveRoot(ll\
    \ p){\r\n    vector<ll> ds;\r\n    for(ll x=1;x*x<=p-1;x++)if((p-1)%x==0){\r\n\
    \        ds.push_back(x);\r\n        if(x*x!=p-1)ds.push_back((p-1)/x);\r\n  \
    \  }\r\n    sort(ALL(ds));\r\n    ds.pop_back();\r\n    for(int x=1;x<p;x++){\r\
    \n        for(auto& d:ds){\r\n            if(mpow(x,d,p)==1)goto fail;\r\n   \
    \     }\r\n        return x;\r\n        fail:;\r\n    } assert(0);\r\n}\r\nll\
    \ extgcd(ll a,ll b,ll& p,ll& q){\r\n    if(b==0){p=1; q=0; return a;}\r\n    ll\
    \ d=extgcd(b,a%b,q,p); q-=a/b*p; return d;\r\n}\r\npair<ll,ll> crt(const vector<ll>&\
    \ vs,const vector<ll>& ms){\r\n    ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\
    \n        ll p,q,v=vs[i],m=ms[i];\r\n        if(M<m)swap(M,m),swap(V,v);\r\n \
    \       ll d=extgcd(M,m,p,q);\r\n        if((v-V)%d!=0)return {0,-1};\r\n    \
    \    ll md=m/d,tmp=(v-V)/d%md*p%md;\r\n        V+=M*tmp; M*=md;\r\n    } V=(V%M+M)%M;\
    \ return {V,M};\r\n}\r\n\r\n/**\r\n * @brief Primitive Function\r\n */\n"
  code: "#pragma once\r\n\r\nll mpow(ll a,ll t,ll m){\r\n    ll res=1;\r\n    while(t){\r\
    \n        if(t&1)res=(res*a)%m;\r\n        a=(a*a)%m; t>>=1;\r\n    } return res;\r\
    \n}\r\nll minv(ll a,ll m){\r\n    ll b=m,u=1,v=0;\r\n    while(b){\r\n       \
    \ ll t=a/b;\r\n        a-=t*b; swap(a,b);\r\n        u-=t*v; swap(u,v);\r\n  \
    \  } u=(u%m+m)%m; return u;\r\n}\r\nll getPrimitiveRoot(ll p){\r\n    vector<ll>\
    \ ds;\r\n    for(ll x=1;x*x<=p-1;x++)if((p-1)%x==0){\r\n        ds.push_back(x);\r\
    \n        if(x*x!=p-1)ds.push_back((p-1)/x);\r\n    }\r\n    sort(ALL(ds));\r\n\
    \    ds.pop_back();\r\n    for(int x=1;x<p;x++){\r\n        for(auto& d:ds){\r\
    \n            if(mpow(x,d,p)==1)goto fail;\r\n        }\r\n        return x;\r\
    \n        fail:;\r\n    } assert(0);\r\n}\r\nll extgcd(ll a,ll b,ll& p,ll& q){\r\
    \n    if(b==0){p=1; q=0; return a;}\r\n    ll d=extgcd(b,a%b,q,p); q-=a/b*p; return\
    \ d;\r\n}\r\npair<ll,ll> crt(const vector<ll>& vs,const vector<ll>& ms){\r\n \
    \   ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\n        ll p,q,v=vs[i],m=ms[i];\r\
    \n        if(M<m)swap(M,m),swap(V,v);\r\n        ll d=extgcd(M,m,p,q);\r\n   \
    \     if((v-V)%d!=0)return {0,-1};\r\n        ll md=m/d,tmp=(v-V)/d%md*p%md;\r\
    \n        V+=M*tmp; M*=md;\r\n    } V=(V%M+M)%M; return {V,M};\r\n}\r\n\r\n/**\r\
    \n * @brief Primitive Function\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/primitive.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/primitive.hpp
layout: document
redirect_from:
- /library/Math/primitive.hpp
- /library/Math/primitive.hpp.html
title: Primitive Function
---
