---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Nimber
    links: []
  bundledCode: "#line 2 \"Math/nimber.hpp\"\n\r\nusing ull=unsigned long long;\r\n\
    struct NimberManager{\r\n    ull memo[256][256];\r\n    NimberManager(){\r\n \
    \       rep(i,0,256)rep(j,0,256)memo[i][j]=256;\r\n        memo[0][0]=memo[0][1]=memo[1][0]=0;\r\
    \n        memo[1][1]=1;\r\n        rep(i,0,256)rep(j,0,256)memo[i][j]=mul(i,j,8);\r\
    \n    }\r\n    ull mul(ull x,ull y,int k=64){\r\n        if(k<=8&&memo[x][y]<256)return\
    \ memo[x][y];\r\n        k>>=1;\r\n        ull a=x>>k,b=x^(a<<k),c=y>>k,d=y^(c<<k);\r\
    \n        ull ac=mul(a,c,k),bd=mul(b,d,k),abcd=mul(a^b,c^d,k);\r\n        return\
    \ mul(ac,1ull<<(k-1),k)^(abcd^bd)<<k^bd;\r\n    }\r\n};\r\nNimberManager Nim;\r\
    \nstruct Nimber{\r\n    ull v;\r\n    Nimber(ull _v=0):v(_v){}\r\n    Nimber&\
    \ operator+=(const Nimber& x){v^=x.v; return *this;}\r\n    Nimber& operator-=(const\
    \ Nimber& x){v^=x.v; return *this;}\r\n    Nimber& operator*=(const Nimber& x){v=Nim.mul(v,x.v);\
    \ return *this;}\r\n    Nimber operator+(const Nimber& x)const{return Nimber(*this)+=x;}\r\
    \n    Nimber operator-(const Nimber& x)const{return Nimber(*this)-=x;}\r\n   \
    \ Nimber operator*(const Nimber& x)const{return Nimber(*this)*=x;}\r\n    bool\
    \ operator==(const Nimber& x)const{return v==x.v;}\r\n    bool operator!=(const\
    \ Nimber& x)const{return v!=x.v;}\r\n    friend istream& operator>>(istream& is,Nimber&\
    \ x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream& os,const Nimber&\
    \ x){return os<<x.v;}\r\n};\r\n\r\n/**\r\n * @brief Nimber\r\n */\n"
  code: "#pragma once\r\n\r\nusing ull=unsigned long long;\r\nstruct NimberManager{\r\
    \n    ull memo[256][256];\r\n    NimberManager(){\r\n        rep(i,0,256)rep(j,0,256)memo[i][j]=256;\r\
    \n        memo[0][0]=memo[0][1]=memo[1][0]=0;\r\n        memo[1][1]=1;\r\n   \
    \     rep(i,0,256)rep(j,0,256)memo[i][j]=mul(i,j,8);\r\n    }\r\n    ull mul(ull\
    \ x,ull y,int k=64){\r\n        if(k<=8&&memo[x][y]<256)return memo[x][y];\r\n\
    \        k>>=1;\r\n        ull a=x>>k,b=x^(a<<k),c=y>>k,d=y^(c<<k);\r\n      \
    \  ull ac=mul(a,c,k),bd=mul(b,d,k),abcd=mul(a^b,c^d,k);\r\n        return mul(ac,1ull<<(k-1),k)^(abcd^bd)<<k^bd;\r\
    \n    }\r\n};\r\nNimberManager Nim;\r\nstruct Nimber{\r\n    ull v;\r\n    Nimber(ull\
    \ _v=0):v(_v){}\r\n    Nimber& operator+=(const Nimber& x){v^=x.v; return *this;}\r\
    \n    Nimber& operator-=(const Nimber& x){v^=x.v; return *this;}\r\n    Nimber&\
    \ operator*=(const Nimber& x){v=Nim.mul(v,x.v); return *this;}\r\n    Nimber operator+(const\
    \ Nimber& x)const{return Nimber(*this)+=x;}\r\n    Nimber operator-(const Nimber&\
    \ x)const{return Nimber(*this)-=x;}\r\n    Nimber operator*(const Nimber& x)const{return\
    \ Nimber(*this)*=x;}\r\n    bool operator==(const Nimber& x)const{return v==x.v;}\r\
    \n    bool operator!=(const Nimber& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,Nimber& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const Nimber& x){return os<<x.v;}\r\n};\r\n\r\n/**\r\n * @brief Nimber\r\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Math/nimber.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/nimber.hpp
layout: document
redirect_from:
- /library/Math/nimber.hpp
- /library/Math/nimber.hpp.html
title: Nimber
---
