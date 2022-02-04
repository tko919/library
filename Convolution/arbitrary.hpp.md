---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_1000000007.test.cpp
    title: Verify/LC_convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1080.test.cpp
    title: Verify/YUKI_1080.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Arbitrary Mod Convolution
    links: []
  bundledCode: "#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct\
    \ fp {\r\n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\
    \n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
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
    \n * @brief Modint\r\n */\n#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate<typename\
    \ T,unsigned p=3>struct NTT{\r\n    vector<T> rt,irt;\r\n    NTT(int lg=21){\r\
    \n        unsigned m=T::get_mod()-1; T prt=p;\r\n        rt.resize(lg); irt.resize(lg);\r\
    \n        rep(k,0,lg){\r\n            rt[k]=-prt.pow(m>>(k+2));\r\n          \
    \  irt[k]=rt[k].inv();\r\n        }\r\n    }\r\n    void ntt(vector<T>& f,bool\
    \ inv=0){\r\n        int n=f.size();\r\n        if(inv){\r\n            for(int\
    \ m=1;m<n;m<<=1){ T w=1;\r\n                for(int s=0,t=0;s<n;s+=m*2){\r\n \
    \                   for(int i=s,j=s+m;i<s+m;i++,j++){\r\n                    \
    \    auto x=f[i],y=f[j];\r\n                        f[i]=x+y; f[j]=(x-y)*w;\r\n\
    \                    } w*=irt[__builtin_ctz(++t)];\r\n                }\r\n  \
    \           } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;\r\n        }else{\r\n   \
    \         for(int m=n;m>>=1;){ T w=1;\r\n                for(int s=0,t=0;s<n;s+=m*2){\r\
    \n                    for(int i=s,j=s+m;i<s+m;i++,j++){\r\n                  \
    \      auto x=f[i],y=f[j]*w;\r\n                        f[i]=x+y; f[j]=x-y;\r\n\
    \                    } w*=rt[__builtin_ctz(++t)];\r\n                }\r\n   \
    \         }\r\n         }\r\n    }\r\n    vector<T> mult(const vector<T>& a,const\
    \ vector<T>& b,bool same=0){\r\n        if(a.empty() or b.empty())return vector<T>();\r\
    \n        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\n        vector<T> res(m);\
    \ rep(i,0,a.size()){res[i]=a[i];} ntt(res);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\
    \n        else{\r\n            vector<T> c(m); rep(i,0,b.size())c[i]=b[i];\r\n\
    \            ntt(c); rep(i,0,m)res[i]*=c[i];\r\n        } ntt(res,1); res.resize(n);\
    \ return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */\n#line 4 \"Convolution/arbitrary.hpp\"\n\r\nusing M1=fp<1045430273>; using\
    \ M2=fp<1051721729>; using M3=fp<1053818881>;\r\nNTT<fp<1045430273>,3> N1; NTT<fp<1051721729>,6>\
    \ N2; NTT<fp<1053818881>,7> N3;\r\ntemplate<typename T>vector<T> ArbitraryMult(const\
    \ vector<T>& a,const vector<T>& b,bool same=0){\r\n    if(a.empty() or b.empty())return\
    \ vector<T>();\r\n    int n=a.size()+b.size()-1; vector<T> res(n); vector<int>\
    \ vals[3];\r\n    vector<int> aa(a.size()),bb(b.size());\r\n    rep(i,0,a.size())aa[i]=a[i].v;\
    \ rep(i,0,b.size())bb[i]=b[i].v;\r\n    vector<M1> a1(ALL(aa)),b1(ALL(bb)),c1=N1.mult(a1,b1,same);\r\
    \n    vector<M2> a2(ALL(aa)),b2(ALL(bb)),c2=N2.mult(a2,b2,same);\r\n    vector<M3>\
    \ a3(ALL(aa)),b3(ALL(bb)),c3=N3.mult(a3,b3,same);\r\n    for(M1 x:c1)vals[0].push_back(x.v);\r\
    \n    for(M2 x:c2)vals[1].push_back(x.v);\r\n    for(M3 x:c3)vals[2].push_back(x.v);\r\
    \n    M2 r_12=M2(M1::get_mod()).inv();\r\n    M3 r_13=M3(M1::get_mod()).inv(),r_23=M3(M2::get_mod()).inv();\r\
    \n    M3 r_1323=r_13*r_23;\r\n    T w1(M1::get_mod()),w2=w1*T(M2::get_mod());\r\
    \n    rep(i,0,n){\r\n        ll p=vals[0][i];\r\n        ll q=(vals[1][i]+M2::get_mod()-p)*r_12.v%M2::get_mod();\r\
    \n        ll r=((vals[2][i]+M3::get_mod()-p)*r_1323.v+\r\n            (M3::get_mod()-q)*r_23.v)%M3::get_mod();\r\
    \n        res[i]=(p+q*w1.v+r*w2.v);\r\n    } return res;\r\n}\r\n\r\n/**\r\n *\
    \ @brief Arbitrary Mod Convolution\r\n */\n"
  code: "#pragma once\r\n#include \"Math/modint.hpp\"\r\n#include \"Convolution/ntt.hpp\"\
    \r\n\r\nusing M1=fp<1045430273>; using M2=fp<1051721729>; using M3=fp<1053818881>;\r\
    \nNTT<fp<1045430273>,3> N1; NTT<fp<1051721729>,6> N2; NTT<fp<1053818881>,7> N3;\r\
    \ntemplate<typename T>vector<T> ArbitraryMult(const vector<T>& a,const vector<T>&\
    \ b,bool same=0){\r\n    if(a.empty() or b.empty())return vector<T>();\r\n   \
    \ int n=a.size()+b.size()-1; vector<T> res(n); vector<int> vals[3];\r\n    vector<int>\
    \ aa(a.size()),bb(b.size());\r\n    rep(i,0,a.size())aa[i]=a[i].v; rep(i,0,b.size())bb[i]=b[i].v;\r\
    \n    vector<M1> a1(ALL(aa)),b1(ALL(bb)),c1=N1.mult(a1,b1,same);\r\n    vector<M2>\
    \ a2(ALL(aa)),b2(ALL(bb)),c2=N2.mult(a2,b2,same);\r\n    vector<M3> a3(ALL(aa)),b3(ALL(bb)),c3=N3.mult(a3,b3,same);\r\
    \n    for(M1 x:c1)vals[0].push_back(x.v);\r\n    for(M2 x:c2)vals[1].push_back(x.v);\r\
    \n    for(M3 x:c3)vals[2].push_back(x.v);\r\n    M2 r_12=M2(M1::get_mod()).inv();\r\
    \n    M3 r_13=M3(M1::get_mod()).inv(),r_23=M3(M2::get_mod()).inv();\r\n    M3\
    \ r_1323=r_13*r_23;\r\n    T w1(M1::get_mod()),w2=w1*T(M2::get_mod());\r\n   \
    \ rep(i,0,n){\r\n        ll p=vals[0][i];\r\n        ll q=(vals[1][i]+M2::get_mod()-p)*r_12.v%M2::get_mod();\r\
    \n        ll r=((vals[2][i]+M3::get_mod()-p)*r_1323.v+\r\n            (M3::get_mod()-q)*r_23.v)%M3::get_mod();\r\
    \n        res[i]=(p+q*w1.v+r*w2.v);\r\n    } return res;\r\n}\r\n\r\n/**\r\n *\
    \ @brief Arbitrary Mod Convolution\r\n */"
  dependsOn:
  - Math/modint.hpp
  - Convolution/ntt.hpp
  isVerificationFile: false
  path: Convolution/arbitrary.hpp
  requiredBy: []
  timestamp: '2022-02-02 00:14:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/YUKI_1080.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_convolution_mod_1000000007.test.cpp
documentation_of: Convolution/arbitrary.hpp
layout: document
redirect_from:
- /library/Convolution/arbitrary.hpp
- /library/Convolution/arbitrary.hpp.html
title: Arbitrary Mod Convolution
---
