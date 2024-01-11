---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/fastdiv.hpp
    title: Fast Division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * @brief Fast\
    \ Division\n*/\n#line 3 \"Math/dynamic.hpp\"\n\r\nstruct Fp{\r\n    using u64=uint64_t;\r\
    \n    int v;\r\n    static int get_mod(){return _getmod();}\r\n    static void\
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
    \nFastDiv Fp::bar(998244353);\r\n\r\n/**\r\n * @brief Dynamic Modint\r\n */\n"
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
    \nFastDiv Fp::bar(998244353);\r\n\r\n/**\r\n * @brief Dynamic Modint\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  isVerificationFile: false
  path: Math/dynamic.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:58:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
documentation_of: Math/dynamic.hpp
layout: document
redirect_from:
- /library/Math/dynamic.hpp
- /library/Math/dynamic.hpp.html
title: Dynamic Modint
---
