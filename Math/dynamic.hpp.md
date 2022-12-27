---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Math/fastdiv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dynamic Modint
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * Fast Division\n\
    */\n#line 3 \"Math/dynamic.hpp\"\n\r\nstruct Fp{\r\n    using u64=uint64_t;\r\n\
    \    int v;\r\n    static int get_mod(){return _getmod();}\r\n    static void\
    \ set_mod(int _m){bar=FastDiv(_m);}\r\n    Fp inv() const{\r\n        int tmp,a=v,b=get_mod(),x=1,y=0;\r\
    \n        while(b){\r\n            tmp=a/b,a-=tmp*b;\r\n            swap(a,b);\r\
    \n            x-=tmp*y;\r\n            swap(x,y);\r\n        }\r\n        if(x<0){x+=get_mod();}\r\
    \n        return x;\r\n    }\r\n    Fp():v(0){}\r\n    Fp(ll x){\r\n        v=x%get_mod();\r\
    \n        if(v<0)v+=get_mod();\r\n    }\r\n    Fp operator-()const{return Fp()-*this;}\r\
    \n    Fp pow(ll t){\r\n        assert(t>=0);\r\n        Fp res=1,b=*this;\r\n\
    \        while(t){\r\n            if(t&1)res*=b;\r\n            b*=b;\r\n    \
    \        t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    Fp& operator+=(const\
    \ Fp& x){\r\n        v+=x.v;\r\n        if(v>=get_mod())v-=get_mod();\r\n    \
    \    return *this;\r\n    }\r\n    Fp& operator-=(const Fp& x){\r\n        v+=get_mod()-x.v;\r\
    \n        if(v>=get_mod())v-=get_mod();\r\n        return *this;\r\n    }\r\n\
    \    Fp& operator*=(const Fp& x){\r\n        v=(u64(v)*x.v)%bar;\r\n        return\
    \ *this;\r\n    }\r\n    Fp& operator/=(const Fp& x){\r\n        (*this)*=x.inv();\r\
    \n        return *this;\r\n    }\r\n    Fp operator+(const Fp& x)const{return\
    \ Fp(*this)+=x;}\r\n    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}\r\
    \n    Fp operator*(const Fp& x)const{return Fp(*this)*=x;}\r\n    Fp operator/(const\
    \ Fp& x)const{return Fp(*this)/=x;}\r\n    bool operator==(const Fp& x)const{return\
    \ v==x.v;}\r\n    bool operator!=(const Fp& x)const{return v!=x.v;}\r\nprivate:\r\
    \n    static FastDiv bar;\r\n    static int _getmod(){return bar.get();}\r\n};\r\
    \nFastDiv Fp::bar(998244353);\r\n\r\ntemplate<typename T>struct factorial {\r\n\
    \    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Dynamic Modint\r\n */\n"
  code: "#pragma once\r\n#include \"Math/fastdiv.hpp\"\r\n\r\nstruct Fp{\r\n    using\
    \ u64=uint64_t;\r\n    int v;\r\n    static int get_mod(){return _getmod();}\r\
    \n    static void set_mod(int _m){bar=FastDiv(_m);}\r\n    Fp inv() const{\r\n\
    \        int tmp,a=v,b=get_mod(),x=1,y=0;\r\n        while(b){\r\n           \
    \ tmp=a/b,a-=tmp*b;\r\n            swap(a,b);\r\n            x-=tmp*y;\r\n   \
    \         swap(x,y);\r\n        }\r\n        if(x<0){x+=get_mod();}\r\n      \
    \  return x;\r\n    }\r\n    Fp():v(0){}\r\n    Fp(ll x){\r\n        v=x%get_mod();\r\
    \n        if(v<0)v+=get_mod();\r\n    }\r\n    Fp operator-()const{return Fp()-*this;}\r\
    \n    Fp pow(ll t){\r\n        assert(t>=0);\r\n        Fp res=1,b=*this;\r\n\
    \        while(t){\r\n            if(t&1)res*=b;\r\n            b*=b;\r\n    \
    \        t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    Fp& operator+=(const\
    \ Fp& x){\r\n        v+=x.v;\r\n        if(v>=get_mod())v-=get_mod();\r\n    \
    \    return *this;\r\n    }\r\n    Fp& operator-=(const Fp& x){\r\n        v+=get_mod()-x.v;\r\
    \n        if(v>=get_mod())v-=get_mod();\r\n        return *this;\r\n    }\r\n\
    \    Fp& operator*=(const Fp& x){\r\n        v=(u64(v)*x.v)%bar;\r\n        return\
    \ *this;\r\n    }\r\n    Fp& operator/=(const Fp& x){\r\n        (*this)*=x.inv();\r\
    \n        return *this;\r\n    }\r\n    Fp operator+(const Fp& x)const{return\
    \ Fp(*this)+=x;}\r\n    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}\r\
    \n    Fp operator*(const Fp& x)const{return Fp(*this)*=x;}\r\n    Fp operator/(const\
    \ Fp& x)const{return Fp(*this)/=x;}\r\n    bool operator==(const Fp& x)const{return\
    \ v==x.v;}\r\n    bool operator!=(const Fp& x)const{return v!=x.v;}\r\nprivate:\r\
    \n    static FastDiv bar;\r\n    static int _getmod(){return bar.get();}\r\n};\r\
    \nFastDiv Fp::bar(998244353);\r\n\r\ntemplate<typename T>struct factorial {\r\n\
    \    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Dynamic Modint\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  isVerificationFile: false
  path: Math/dynamic.hpp
  requiredBy: []
  timestamp: '2022-12-28 03:34:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/dynamic.hpp
layout: document
redirect_from:
- /library/Math/dynamic.hpp
- /library/Math/dynamic.hpp.html
title: Dynamic Modint
---
