---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Gaussian Integer
    links: []
  bundledCode: "#line 2 \"Math/gaussian.hpp\"\n\nstruct G{\n    ll x,y;\n    G(){}\n\
    \    G(ll _x,ll _y):x(_x),y(_y){}\n    ll norm()const{return x*x+y*y;}\n    G\
    \ conj()const{return G(x,-y);}\n    G operator-()const{return G(-x,-y);}\n   \
    \ G& operator+=(const G& a){x+=a.x,y+=a.y; return *this;}\n    G& operator-=(const\
    \ G& a){x-=a.x,y-=a.y; return *this;}\n    G& operator*=(const G& a){\n      \
    \  ll nx=x*a.x-y*a.y,ny=x*a.y+y*a.x;\n        x=nx,y=ny;\n        return *this;\n\
    \    }\n    G& operator/=(const G& a){\n        (*this)*=a.conj();\n        ll\
    \ n=a.norm();\n        x=floor(x+n/2,n),y=floor(y+n/2,n);\n        return *this;\n\
    \    }\n    G& operator%=(const G& a){\n        (*this)-=(G(*this)/a)*a;\n   \
    \     return *this;\n    }\n    G operator+(const G& a)const{return G(*this)+=a;}\n\
    \    G operator-(const G& a)const{return G(*this)-=a;}\n    G operator*(const\
    \ G& a)const{return G(*this)*=a;}\n    G operator/(const G& a)const{return G(*this)/=a;}\n\
    \    G operator%(const G& a)const{return G(*this)%=a;}\n    bool operator==(const\
    \ G &a){return (x==a.x and y==a.y);}\n    bool operator!=(const G &a){return (x!=a.x\
    \ or y!=a.y);}\n};\n\nG gcd(G a,G b){\n    while(b!=G(0,0)){\n        a%=b;\n\
    \        swap(a,b);\n    }\n    return a;\n}\n\n/**\n * @brief Gaussian Integer\n\
    */\n"
  code: "#pragma once\n\nstruct G{\n    ll x,y;\n    G(){}\n    G(ll _x,ll _y):x(_x),y(_y){}\n\
    \    ll norm()const{return x*x+y*y;}\n    G conj()const{return G(x,-y);}\n   \
    \ G operator-()const{return G(-x,-y);}\n    G& operator+=(const G& a){x+=a.x,y+=a.y;\
    \ return *this;}\n    G& operator-=(const G& a){x-=a.x,y-=a.y; return *this;}\n\
    \    G& operator*=(const G& a){\n        ll nx=x*a.x-y*a.y,ny=x*a.y+y*a.x;\n \
    \       x=nx,y=ny;\n        return *this;\n    }\n    G& operator/=(const G& a){\n\
    \        (*this)*=a.conj();\n        ll n=a.norm();\n        x=floor(x+n/2,n),y=floor(y+n/2,n);\n\
    \        return *this;\n    }\n    G& operator%=(const G& a){\n        (*this)-=(G(*this)/a)*a;\n\
    \        return *this;\n    }\n    G operator+(const G& a)const{return G(*this)+=a;}\n\
    \    G operator-(const G& a)const{return G(*this)-=a;}\n    G operator*(const\
    \ G& a)const{return G(*this)*=a;}\n    G operator/(const G& a)const{return G(*this)/=a;}\n\
    \    G operator%(const G& a)const{return G(*this)%=a;}\n    bool operator==(const\
    \ G &a){return (x==a.x and y==a.y);}\n    bool operator!=(const G &a){return (x!=a.x\
    \ or y!=a.y);}\n};\n\nG gcd(G a,G b){\n    while(b!=G(0,0)){\n        a%=b;\n\
    \        swap(a,b);\n    }\n    return a;\n}\n\n/**\n * @brief Gaussian Integer\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Math/gaussian.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/gaussian.hpp
layout: document
redirect_from:
- /library/Math/gaussian.hpp
- /library/Math/gaussian.hpp.html
title: Gaussian Integer
---
