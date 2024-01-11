---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/sumofRationals.hpp
    title: Sum of Rationals
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
    }\n\n/**\n * @brief Sum of Rationals\n*/\n#line 3 \"FPS/compexp.hpp\"\n\ntemplate<typename\
    \ T>Poly<T> CompExp(Poly<T>& f,int m){\n    int n=f.size();\n    vector<pair<Poly<T>,Poly<T>>>\
    \ fs;\n    rep(i,0,n){\n        Poly<T> p({Fp(f[i])});\n        Poly<T> q({Fp(1),Fp(-i)});\n\
    \        fs.push_back({p,q});\n    }\n    auto [p,q]=SumOfRationals(fs);\n   \
    \ q.resize(m);\n    p*=q.inv();\n    p.resize(m);\n    rep(i,0,m)p[i]*=Fact<T>(i,1);\n\
    \    return p;\n}\n\n/**\n * @brief $f(\\exp(x))$\n*/\n"
  code: "#pragma once\n#include \"FPS/sumofRationals.hpp\"\n\ntemplate<typename T>Poly<T>\
    \ CompExp(Poly<T>& f,int m){\n    int n=f.size();\n    vector<pair<Poly<T>,Poly<T>>>\
    \ fs;\n    rep(i,0,n){\n        Poly<T> p({Fp(f[i])});\n        Poly<T> q({Fp(1),Fp(-i)});\n\
    \        fs.push_back({p,q});\n    }\n    auto [p,q]=SumOfRationals(fs);\n   \
    \ q.resize(m);\n    p*=q.inv();\n    p.resize(m);\n    rep(i,0,m)p[i]*=Fact<T>(i,1);\n\
    \    return p;\n}\n\n/**\n * @brief $f(\\exp(x))$\n*/"
  dependsOn:
  - FPS/sumofRationals.hpp
  isVerificationFile: false
  path: FPS/compexp.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/compexp.hpp
layout: document
redirect_from:
- /library/FPS/compexp.hpp
- /library/FPS/compexp.hpp.html
title: $f(\exp(x))$
---
