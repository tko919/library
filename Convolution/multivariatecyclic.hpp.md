---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/multievalgeom.hpp
    title: Multipoint Evaluation on Geometric Sequence
  - icon: ':heavy_check_mark:'
    path: Math/fastdiv.hpp
    title: Fast Division
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Multivarate Convolution Cyclic
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * @brief Fast\
    \ Division\n*/\n#line 2 \"Math/miller.hpp\"\n\r\nbool Miller(ll n){\r\n    if(n<2\
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
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 4 \"Math/primitive.hpp\"\n\
    \r\nll mpow(ll a,ll t,ll m){\r\n    ll res=1;\r\n    FastDiv im(m);\r\n    while(t){\r\
    \n        if(t&1)res=__int128_t(res)*a%im;\r\n        a=__int128_t(a)*a%im;\r\n\
    \        t>>=1;\r\n    } return res;\r\n}\r\nll minv(ll a,ll m){\r\n    ll b=m,u=1,v=0;\r\
    \n    while(b){\r\n        ll t=a/b;\r\n        a-=t*b; swap(a,b);\r\n       \
    \ u-=t*v; swap(u,v);\r\n    }\r\n    u=(u%m+m)%m;\r\n    return u;\r\n}\r\nll\
    \ getPrimitiveRoot(ll p){\r\n    vector<ll> ps=Pollard(p-1);\r\n    sort(ALL(ps));\r\
    \n    rep(x,1,inf){\r\n        for(auto& q:ps){\r\n            if(mpow(x,(p-1)/q,p)==1)goto\
    \ fail;\r\n        }\r\n        return x;\r\n        fail:;\r\n    } assert(0);\r\
    \n}\r\nll extgcd(ll a,ll b,ll& p,ll& q){\r\n    if(b==0){p=1; q=0; return a;}\r\
    \n    ll d=extgcd(b,a%b,q,p); q-=a/b*p; return d;\r\n}\r\npair<ll,ll> crt(const\
    \ vector<ll>& vs,const vector<ll>& ms){\r\n    ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\
    \n        ll p,q,v=vs[i],m=ms[i];\r\n        if(M<m)swap(M,m),swap(V,v);\r\n \
    \       ll d=extgcd(M,m,p,q);\r\n        if((v-V)%d!=0)return {0,-1};\r\n    \
    \    ll md=m/d,tmp=(v-V)/d%md*p%md;\r\n        V+=M*tmp; M*=md;\r\n    }\r\n \
    \   V=(V%M+M)%M;\r\n    return {V,M};\r\n}\r\nll ModLog(ll a,ll b,ll p){\r\n \
    \   ll g=1;\r\n    for(ll t=p;t;t>>=1)g=g*a%p;\r\n    g=__gcd(g,p);\r\n    ll\
    \ t=1,c=0;\r\n    for(;t%g;c++){\r\n        if(t==b)return c;\r\n        t=t*a%p;\r\
    \n    }\r\n    if(b%g)return -1;\r\n    t/=g,b/=g;\r\n    ll n=p/g,h=0,gs=1;\r\
    \n    for(;h*h<n;h++)gs=gs*a%n;\r\n    unordered_map<ll,ll> bs;\r\n    for(ll\
    \ s=0,e=b;s<h;bs[e]=++s)e=e*a%n;\r\n    for(ll s=0,e=t;s<n;){\r\n        e=e*gs%n,s+=h;\r\
    \n        if(bs.count(e)){\r\n            return c+s-bs[e];\r\n        }\r\n \
    \   }\r\n    return -1;\r\n}\r\n\r\nll mod_root(ll k,ll a,ll m){\r\n    if(a==0)return\
    \ k?0:-1;\r\n    if(m==2)return a&1;\r\n    k%=m-1;\r\n    ll g=gcd(k,m-1);\r\n\
    \    if(mpow(a,(m-1)/g,m)!=1)return -1;\r\n    a=mpow(a,minv(k/g,(m-1)/g),m);\r\
    \n    FastDiv im(m);\r\n\r\n    auto _subroot=[&](ll p,int e,ll a)->ll{//x^(p^e)==a(mod\
    \ m)\r\n        ll q=m-1; int s=0;\r\n        while(q%p==0){q/=p; s++;}\r\n  \
    \      int d=s-e;\r\n        ll pe=mpow(p,e,m),res=mpow(a,((pe-1)*minv(q,pe)%pe*q+1)/pe,m),c=1;\r\
    \n        while(mpow(c,(m-1)/p,m)==1)c++;\r\n        c=mpow(c,q,m);\r\n      \
    \  map<ll,ll> mp;\r\n        ll v=1,block=sqrt(d*p)+1,bs=mpow(c,mpow(p,s-1,m-1)*block%(m-1),m);\r\
    \n        rep(i,0,block+1)mp[v]=i,v=v*bs%im;\r\n        ll gs=minv(mpow(c,mpow(p,s-1,m-1),m),m);\r\
    \n        rep(i,0,d){\r\n            ll err=a*minv(mpow(res,pe,m),m)%im;\r\n \
    \           ll pos=mpow(err,mpow(p,d-1-i,m-1),m);\r\n            rep(j,0,block+1){\r\
    \n                if(mp.count(pos)){\r\n                    res=res*mpow(c,(block*mp[pos]+j)*mpow(p,i,m-1)%(m-1),m)%im;\r\
    \n                    break;\r\n                }\r\n                pos=pos*gs%im;\r\
    \n            } \r\n        }\r\n        return res;\r\n    };\r\n\r\n    for(ll\
    \ d=2;d*d<=g;d++)if(g%d==0){\r\n        int sz=0;\r\n        while(g%d==0){g/=d;\
    \ sz++;}\r\n        a=_subroot(d,sz,a);\r\n    }\r\n    if(g>1)a=_subroot(g,1,a);\r\
    \n    return a;\r\n}\r\n\r\n/**\r\n * @brief Primitive Function\r\n */\n#line\
    \ 2 \"FPS/multievalgeom.hpp\"\n\ntemplate<typename T>vector<T> MultievalGeomSeq(vector<T>&\
    \ f,T a,T w,int m){\n    int n=f.size();\n    vector<T> tri(n+m-1),itri(n+m-1);\n\
    \    tri[0]=itri[0]=1;\n    T iw=w.inv(),pww=1,pwiw=1;\n    for(int i=1;i<n+m-1;i++,pww*=w,pwiw*=iw){\n\
    \        tri[i]=tri[i-1]*pww;\n        itri[i]=itri[i-1]*pwiw;\n    }\n\n    Poly<T>\
    \ y(n),v(n+m-1);\n    T pwa=1;\n    for(int i=0;i<n;i++,pwa*=a){\n        y[i]=f[i]*itri[i]*pwa;\n\
    \    }\n    rep(i,0,n+m-1)v[i]=tri[i];\n    reverse(ALL(y));\n    y*=v;\n    vector<T>\
    \ ret(m);\n    rep(i,0,m)ret[i]=y[n-1+i]*itri[i];\n    return ret;\n}\n\n/**\n\
    \ * @brief Multipoint Evaluation on Geometric Sequence\n*/\n#line 4 \"Convolution/multivariatecyclic.hpp\"\
    \n\ntemplate<typename T>vector<T> MultivariateCyclic\n    (vector<T> f,vector<T>\
    \ g,vector<int>& a){\n    int MO=T::get_mod();\n    int k=a.size(),n=1;\n    for(auto&\
    \ x:a)n*=x;\n    T pr=getPrimitiveRoot(MO),ipr=T(pr).inv();\n\n    int offset=1;\n\
    \    rep(x,0,k){\n        assert((MO-1)%a[x]==0);\n        T w=pr.pow((MO-1)/a[x]);\n\
    \        rep(i,0,n)if(i%(offset*a[x])<offset){\n            vector<T> na(a[x]),nb(a[x]);\n\
    \            rep(j,0,a[x]){\n                na[j]=f[i+offset*j];\n          \
    \      nb[j]=g[i+offset*j];\n            }\n            na=MultievalGeomSeq(na,T(1),w,a[x]);\n\
    \            nb=MultievalGeomSeq(nb,T(1),w,a[x]);\n            rep(j,0,a[x]){\n\
    \                f[i+offset*j]=na[j];\n                g[i+offset*j]=nb[j];\n\
    \            }\n        }\n        offset*=a[x];\n    }\n\n    rep(i,0,n)f[i]*=g[i];\n\
    \    \n    offset=1;\n    rep(x,0,k){\n        T iw=ipr.pow((MO-1)/a[x]);\n  \
    \      rep(i,0,n)if(i%(offset*a[x])<offset){\n            vector<T> na(a[x]);\n\
    \            rep(j,0,a[x])na[j]=f[i+offset*j];\n            na=MultievalGeomSeq(na,T(1),iw,a[x]);\n\
    \            rep(j,0,a[x])f[i+offset*j]=na[j];\n        }\n        offset*=a[x];\n\
    \    }\n    T ninv=T(n).inv();\n    rep(i,0,n)f[i]*=ninv;\n    return f;\n}\n\n\
    /**\n * @brief Multivarate Convolution Cyclic\n*/\n"
  code: "#pragma once\n#include \"Math/primitive.hpp\"\n#include \"FPS/multievalgeom.hpp\"\
    \n\ntemplate<typename T>vector<T> MultivariateCyclic\n    (vector<T> f,vector<T>\
    \ g,vector<int>& a){\n    int MO=T::get_mod();\n    int k=a.size(),n=1;\n    for(auto&\
    \ x:a)n*=x;\n    T pr=getPrimitiveRoot(MO),ipr=T(pr).inv();\n\n    int offset=1;\n\
    \    rep(x,0,k){\n        assert((MO-1)%a[x]==0);\n        T w=pr.pow((MO-1)/a[x]);\n\
    \        rep(i,0,n)if(i%(offset*a[x])<offset){\n            vector<T> na(a[x]),nb(a[x]);\n\
    \            rep(j,0,a[x]){\n                na[j]=f[i+offset*j];\n          \
    \      nb[j]=g[i+offset*j];\n            }\n            na=MultievalGeomSeq(na,T(1),w,a[x]);\n\
    \            nb=MultievalGeomSeq(nb,T(1),w,a[x]);\n            rep(j,0,a[x]){\n\
    \                f[i+offset*j]=na[j];\n                g[i+offset*j]=nb[j];\n\
    \            }\n        }\n        offset*=a[x];\n    }\n\n    rep(i,0,n)f[i]*=g[i];\n\
    \    \n    offset=1;\n    rep(x,0,k){\n        T iw=ipr.pow((MO-1)/a[x]);\n  \
    \      rep(i,0,n)if(i%(offset*a[x])<offset){\n            vector<T> na(a[x]);\n\
    \            rep(j,0,a[x])na[j]=f[i+offset*j];\n            na=MultievalGeomSeq(na,T(1),iw,a[x]);\n\
    \            rep(j,0,a[x])f[i+offset*j]=na[j];\n        }\n        offset*=a[x];\n\
    \    }\n    T ninv=T(n).inv();\n    rep(i,0,n)f[i]*=ninv;\n    return f;\n}\n\n\
    /**\n * @brief Multivarate Convolution Cyclic\n*/"
  dependsOn:
  - Math/primitive.hpp
  - Math/fastdiv.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  - FPS/multievalgeom.hpp
  isVerificationFile: false
  path: Convolution/multivariatecyclic.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
documentation_of: Convolution/multivariatecyclic.hpp
layout: document
redirect_from:
- /library/Convolution/multivariatecyclic.hpp
- /library/Convolution/multivariatecyclic.hpp.html
title: Multivarate Convolution Cyclic
---
