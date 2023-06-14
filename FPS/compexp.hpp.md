---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/sumofRationals.hpp
    title: Sum of Rationals
  - icon: ':heavy_check_mark:'
    path: Math/factorial.hpp
    title: Factorial
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: $f(\exp(x))$
    links: []
  bundledCode: "#line 2 \"FPS/sumofRationals.hpp\"\n\ntemplate<typename T>pair<Poly<T>,Poly<T>>\
    \ SumOfRationals(vector<pair<Poly<T>,Poly<T>>>& fs){\n    using Ratio=pair<Poly<T>,Poly<T>>;\n\
    \    if(fs.empty())return {Poly<T>({T(1)}),Poly<T>({T(1)})};\n    sort(ALL(fs),[&](Ratio&\
    \ a,Ratio& b){return a.first.size()+a.second.size()<b.first.size()+b.second.size();});\n\
    \    deque<Ratio> deq;\n    for(auto& f:fs)deq.push_back(f);\n    while(deq.size()>1){\n\
    \        auto [f,g]=deq[0];\n        auto [p,q]=deq[1];\n        deq.push_back({f*q+g*p,g*q});\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Sum of Rationals\n*/\n#line 2 \"Math/factorial.hpp\"\n\ntemplate<typename\
    \ T>struct factorial {\n    vector<T> Fact,Finv,Inv;\n    factorial(int maxx){\n\
    \        Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\n\
    \        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=T(1)/Fact[maxx-1];\n\
    \        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\n\
    \    }\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\n\
    \    T inv(int n){if(n<0)return 0; return Inv[n];}\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\n   \
    \ T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\n\
    \    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\n};\n\n/**\n * @brief\
    \ Factorial\n*/\n#line 4 \"FPS/compexp.hpp\"\n\ntemplate<typename T>Poly<T> CompExp(Poly<T>&\
    \ f,int m){\n    int n=f.size();\n    vector<pair<Poly<T>,Poly<T>>> fs;\n    rep(i,0,n){\n\
    \        Poly<T> p({Fp(f[i])});\n        Poly<T> q({Fp(1),Fp(-i)});\n        fs.push_back({p,q});\n\
    \    }\n    auto [p,q]=SumOfRationals(fs);\n    q.resize(m);\n    p*=q.inv();\n\
    \    p.resize(m);\n    factorial<T> fact(m+1);\n    rep(i,0,m)p[i]*=fact.fact(i,1);\n\
    \    return p;\n}\n\n/**\n * @brief $f(\\exp(x))$\n*/\n"
  code: "#pragma once\n#include \"FPS/sumofRationals.hpp\"\n#include \"Math/factorial.hpp\"\
    \n\ntemplate<typename T>Poly<T> CompExp(Poly<T>& f,int m){\n    int n=f.size();\n\
    \    vector<pair<Poly<T>,Poly<T>>> fs;\n    rep(i,0,n){\n        Poly<T> p({Fp(f[i])});\n\
    \        Poly<T> q({Fp(1),Fp(-i)});\n        fs.push_back({p,q});\n    }\n   \
    \ auto [p,q]=SumOfRationals(fs);\n    q.resize(m);\n    p*=q.inv();\n    p.resize(m);\n\
    \    factorial<T> fact(m+1);\n    rep(i,0,m)p[i]*=fact.fact(i,1);\n    return\
    \ p;\n}\n\n/**\n * @brief $f(\\exp(x))$\n*/"
  dependsOn:
  - FPS/sumofRationals.hpp
  - Math/factorial.hpp
  isVerificationFile: false
  path: FPS/compexp.hpp
  requiredBy: []
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/compexp.hpp
layout: document
redirect_from:
- /library/FPS/compexp.hpp
- /library/FPS/compexp.hpp.html
title: $f(\exp(x))$
---
