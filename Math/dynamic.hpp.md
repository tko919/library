---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dynamic Modint
    links: []
  bundledCode: "#line 2 \"Math/dynamic.hpp\"\n\r\nstruct Fp{\r\n    int v;\r\n   \
    \ static int get_mod(){return mod;}\r\n    static void set_mod(int _m){mod=_m;}\r\
    \n    int inv() const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    Fp(ll x=0){init(x%mod+mod);}\r\
    \n    Fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    Fp operator-()const{return\
    \ Fp()-*this;}\r\n    Fp pow(ll t){assert(t>=0); Fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
    \ return res;}\r\n    Fp& operator+=(const Fp& x){return init(v+x.v);}\r\n   \
    \ Fp& operator-=(const Fp& x){return init(v+mod-x.v);}\r\n    Fp& operator*=(const\
    \ Fp& x){v=ll(v)*x.v%mod; return *this;}\r\n    Fp& operator/=(const Fp& x){v=ll(v)*x.inv()%mod;\
    \ return *this;}\r\n    Fp operator+(const Fp& x)const{return Fp(*this)+=x;}\r\
    \n    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}\r\n    Fp operator*(const\
    \ Fp& x)const{return Fp(*this)*=x;}\r\n    Fp operator/(const Fp& x)const{return\
    \ Fp(*this)/=x;}\r\n    bool operator==(const Fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const Fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,Fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const Fp& x){return os<<x.v;}\r\nprivate:\r\n    static int mod;\r\n};\r\n\
    int Fp::mod;\r\ntemplate<typename T>struct factorial {\r\n    vector<T> Fact,Finv,Inv;\r\
    \n    factorial(int maxx){\r\n        Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);\r\
    \n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;}\
    \ Finv[maxx-1]=Fact[maxx-1].inv();\r\n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i;\
    \ Inv[i]=Finv[i]*Fact[i-1];}\r\n    }\r\n    T fact(int n,bool inv=0){if(n<0)return\
    \ 0; return (inv?Finv[n]:Fact[n]);}\r\n    T inv(int n){if(n<0)return 0; return\
    \ Inv[n];}\r\n    T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return\
    \ fact(n,inv)*fact(n-r,inv^1);}\r\n    T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return\
    \ 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\n    T nHr(int n,int\
    \ r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\n * @brief Dynamic\
    \ Modint\r\n */\n"
  code: "#pragma once\r\n\r\nstruct Fp{\r\n    int v;\r\n    static int get_mod(){return\
    \ mod;}\r\n    static void set_mod(int _m){mod=_m;}\r\n    int inv() const{\r\n\
    \        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    Fp(ll x=0){init(x%mod+mod);}\r\
    \n    Fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    Fp operator-()const{return\
    \ Fp()-*this;}\r\n    Fp pow(ll t){assert(t>=0); Fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
    \ return res;}\r\n    Fp& operator+=(const Fp& x){return init(v+x.v);}\r\n   \
    \ Fp& operator-=(const Fp& x){return init(v+mod-x.v);}\r\n    Fp& operator*=(const\
    \ Fp& x){v=ll(v)*x.v%mod; return *this;}\r\n    Fp& operator/=(const Fp& x){v=ll(v)*x.inv()%mod;\
    \ return *this;}\r\n    Fp operator+(const Fp& x)const{return Fp(*this)+=x;}\r\
    \n    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}\r\n    Fp operator*(const\
    \ Fp& x)const{return Fp(*this)*=x;}\r\n    Fp operator/(const Fp& x)const{return\
    \ Fp(*this)/=x;}\r\n    bool operator==(const Fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const Fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,Fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const Fp& x){return os<<x.v;}\r\nprivate:\r\n    static int mod;\r\n};\r\n\
    int Fp::mod;\r\ntemplate<typename T>struct factorial {\r\n    vector<T> Fact,Finv,Inv;\r\
    \n    factorial(int maxx){\r\n        Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);\r\
    \n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;}\
    \ Finv[maxx-1]=Fact[maxx-1].inv();\r\n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i;\
    \ Inv[i]=Finv[i]*Fact[i-1];}\r\n    }\r\n    T fact(int n,bool inv=0){if(n<0)return\
    \ 0; return (inv?Finv[n]:Fact[n]);}\r\n    T inv(int n){if(n<0)return 0; return\
    \ Inv[n];}\r\n    T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return\
    \ fact(n,inv)*fact(n-r,inv^1);}\r\n    T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return\
    \ 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\n    T nHr(int n,int\
    \ r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\n * @brief Dynamic\
    \ Modint\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/dynamic.hpp
  requiredBy: []
  timestamp: '2022-10-18 18:02:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/dynamic.hpp
layout: document
redirect_from:
- /library/Math/dynamic.hpp
- /library/Math/dynamic.hpp.html
title: Dynamic Modint
---
