---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Primitive Function
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
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 3 \"Math/primitive.hpp\"\n\
    \r\nll mpow(ll a,ll t,ll m){\r\n    ll res=1;\r\n    while(t){\r\n        if(t&1)res=__int128_t(res)*a%m;\r\
    \n        a=__int128_t(a)*a%m; t>>=1;\r\n    } return res;\r\n}\r\nll minv(ll\
    \ a,ll m){\r\n    ll b=m,u=1,v=0;\r\n    while(b){\r\n        ll t=a/b;\r\n  \
    \      a-=t*b; swap(a,b);\r\n        u-=t*v; swap(u,v);\r\n    } u=(u%m+m)%m;\
    \ return u;\r\n}\r\nll getPrimitiveRoot(ll p){\r\n    vector<ll> ps=Pollard(p-1);\r\
    \n    sort(ALL(ps));\r\n    rep(x,1,inf){\r\n        for(auto& q:ps){\r\n    \
    \        if(mpow(x,(p-1)/q,p)==1)goto fail;\r\n        }\r\n        return x;\r\
    \n        fail:;\r\n    } assert(0);\r\n}\r\nll extgcd(ll a,ll b,ll& p,ll& q){\r\
    \n    if(b==0){p=1; q=0; return a;}\r\n    ll d=extgcd(b,a%b,q,p); q-=a/b*p; return\
    \ d;\r\n}\r\npair<ll,ll> crt(const vector<ll>& vs,const vector<ll>& ms){\r\n \
    \   ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\n        ll p,q,v=vs[i],m=ms[i];\r\
    \n        if(M<m)swap(M,m),swap(V,v);\r\n        ll d=extgcd(M,m,p,q);\r\n   \
    \     if((v-V)%d!=0)return {0,-1};\r\n        ll md=m/d,tmp=(v-V)/d%md*p%md;\r\
    \n        V+=M*tmp; M*=md;\r\n    } V=(V%M+M)%M; return {V,M};\r\n}\r\nll ModLog(ll\
    \ a,ll b,ll p){\r\n    ll g=1;\r\n    for(ll t=p;t;t>>=1)g=g*a%p;\r\n    g=__gcd(g,p);\r\
    \n    ll t=1,c=0;\r\n    for(;t%g;c++){\r\n        if(t==b)return c;\r\n     \
    \   t=t*a%p;\r\n        }\r\n    if(b%g)return -1;\r\n    t/=g,b/=g;\r\n    ll\
    \ n=p/g,h=0,gs=1;\r\n    for(;h*h<n;h++)gs=gs*a%n;\r\n    unordered_map<ll,ll>\
    \ bs;\r\n    for(ll s=0,e=b;s<h;bs[e]=++s)e=e*a%n;\r\n    for(ll s=0,e=t;s<n;){\r\
    \n        e=e*gs%n,s+=h;\r\n        if(bs.count(e)){\r\n            return c+s-bs[e];\r\
    \n        }\r\n    } return -1;\r\n}\r\n\r\n/**\r\n * @brief Primitive Function\r\
    \n */\n"
  code: "#pragma once\r\n#include \"Math/pollard.hpp\"\r\n\r\nll mpow(ll a,ll t,ll\
    \ m){\r\n    ll res=1;\r\n    while(t){\r\n        if(t&1)res=__int128_t(res)*a%m;\r\
    \n        a=__int128_t(a)*a%m; t>>=1;\r\n    } return res;\r\n}\r\nll minv(ll\
    \ a,ll m){\r\n    ll b=m,u=1,v=0;\r\n    while(b){\r\n        ll t=a/b;\r\n  \
    \      a-=t*b; swap(a,b);\r\n        u-=t*v; swap(u,v);\r\n    } u=(u%m+m)%m;\
    \ return u;\r\n}\r\nll getPrimitiveRoot(ll p){\r\n    vector<ll> ps=Pollard(p-1);\r\
    \n    sort(ALL(ps));\r\n    rep(x,1,inf){\r\n        for(auto& q:ps){\r\n    \
    \        if(mpow(x,(p-1)/q,p)==1)goto fail;\r\n        }\r\n        return x;\r\
    \n        fail:;\r\n    } assert(0);\r\n}\r\nll extgcd(ll a,ll b,ll& p,ll& q){\r\
    \n    if(b==0){p=1; q=0; return a;}\r\n    ll d=extgcd(b,a%b,q,p); q-=a/b*p; return\
    \ d;\r\n}\r\npair<ll,ll> crt(const vector<ll>& vs,const vector<ll>& ms){\r\n \
    \   ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\n        ll p,q,v=vs[i],m=ms[i];\r\
    \n        if(M<m)swap(M,m),swap(V,v);\r\n        ll d=extgcd(M,m,p,q);\r\n   \
    \     if((v-V)%d!=0)return {0,-1};\r\n        ll md=m/d,tmp=(v-V)/d%md*p%md;\r\
    \n        V+=M*tmp; M*=md;\r\n    } V=(V%M+M)%M; return {V,M};\r\n}\r\nll ModLog(ll\
    \ a,ll b,ll p){\r\n    ll g=1;\r\n    for(ll t=p;t;t>>=1)g=g*a%p;\r\n    g=__gcd(g,p);\r\
    \n    ll t=1,c=0;\r\n    for(;t%g;c++){\r\n        if(t==b)return c;\r\n     \
    \   t=t*a%p;\r\n        }\r\n    if(b%g)return -1;\r\n    t/=g,b/=g;\r\n    ll\
    \ n=p/g,h=0,gs=1;\r\n    for(;h*h<n;h++)gs=gs*a%n;\r\n    unordered_map<ll,ll>\
    \ bs;\r\n    for(ll s=0,e=b;s<h;bs[e]=++s)e=e*a%n;\r\n    for(ll s=0,e=t;s<n;){\r\
    \n        e=e*gs%n,s+=h;\r\n        if(bs.count(e)){\r\n            return c+s-bs[e];\r\
    \n        }\r\n    } return -1;\r\n}\r\n\r\n/**\r\n * @brief Primitive Function\r\
    \n */"
  dependsOn:
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/primitive.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_discrete_logarithm_mod.test.cpp
documentation_of: Math/primitive.hpp
layout: document
redirect_from:
- /library/Math/primitive.hpp
- /library/Math/primitive.hpp.html
title: Primitive Function
---
