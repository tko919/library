---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/bitwise.hpp
    title: Bitwise Convolution
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"Verify/LC_bitwise_xor_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp\
    \ {\r\n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\n\
    \        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
    \ return res;}\r\n    fp& operator+=(const fp& x){return init(v+x.v);}\r\n   \
    \ fp& operator-=(const fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const\
    \ fp& x){v=ll(v)*x.v%mod; return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod;\
    \ return *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\
    \n    fp operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\ntemplate<typename T>struct factorial\
    \ {\r\n    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Modint\r\n */\n#line 2 \"Convolution/bitwise.hpp\"\n\r\ntemplate<typename\
    \ T>void zeta(vector<T>& a){\r\n    int n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\
    \n        if(mask>>k&1)a[mask]+=a[mask^(1<<k)];\r\n    }\r\n}\r\ntemplate<typename\
    \ T>void mobius(vector<T>& a){\r\n    int n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\
    \n        if(mask>>k&1)a[mask]-=a[mask^(1<<k)];\r\n    }\r\n}\r\ntemplate<typename\
    \ T>void fwt(vector<T>& a){\r\n    int n=__lg(a.size());\r\n    rep(k,0,n)rep(mask,0,1<<n){\r\
    \n        if(!(mask>>k&1)){\r\n            T x=a[mask],y=a[mask|(1<<k)];\r\n \
    \           a[mask]=x+y,a[mask|(1<<k)]=x-y;\r\n        }\r\n    }\r\n}\r\n\r\n\
    /**\r\n * @brief Bitwise Convolution\r\n * @docs docs/bitwise.md\r\n */\n#line\
    \ 6 \"Verify/LC_bitwise_xor_convolution.test.cpp\"\n\r\nusing Fp=fp<998244353>;\r\
    \n\r\nint main(){\r\n    int n;\r\n    cin>>n;\r\n    vector<Fp> a(1<<n),b(1<<n);\r\
    \n    for(auto& x:a)cin>>x;\r\n    for(auto& x:b)cin>>x;\r\n    vector<Fp> ret(1<<n);\r\
    \n    fwt(a);\r\n    fwt(b);\r\n    rep(i,0,1<<n)ret[i]=a[i]*b[i];\r\n    fwt(ret);\r\
    \n    for(auto& x:ret)cout<<x/(1<<n)<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"Convolution/bitwise.hpp\"\r\n\r\nusing Fp=fp<998244353>;\r\n\r\nint\
    \ main(){\r\n    int n;\r\n    cin>>n;\r\n    vector<Fp> a(1<<n),b(1<<n);\r\n\
    \    for(auto& x:a)cin>>x;\r\n    for(auto& x:b)cin>>x;\r\n    vector<Fp> ret(1<<n);\r\
    \n    fwt(a);\r\n    fwt(b);\r\n    rep(i,0,1<<n)ret[i]=a[i]*b[i];\r\n    fwt(ret);\r\
    \n    for(auto& x:ret)cout<<x/(1<<n)<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - Convolution/bitwise.hpp
  isVerificationFile: true
  path: Verify/LC_bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_bitwise_xor_convolution.test.cpp
- /verify/Verify/LC_bitwise_xor_convolution.test.cpp.html
title: Verify/LC_bitwise_xor_convolution.test.cpp
---
