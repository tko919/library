---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/prodofpolys.hpp
    title: Product of Polynomials
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate $\sum_k a_k^i$
    links: []
  bundledCode: "#line 2 \"FPS/prodofpolys.hpp\"\n\ntemplate<typename T>Poly<T> ProdOfPolys(vector<Poly<T>>&\
    \ fs){\n    if(fs.empty())return Poly<T>({T(1)});\n    sort(ALL(fs),[&](Poly<T>&\
    \ a,Poly<T>& b){return a.size()<b.size();});\n    deque<Poly<T>> deq;\n    for(auto&\
    \ f:fs)deq.push_back(f);\n    while(deq.size()>1){\n        deq.push_back(deq[0]*deq[1]);\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Product of Polynomials\n*/\n#line 3 \"FPS/sumofpowers.hpp\"\
    \n\ntemplate<typename T>vector<T> SumOfPowers(vector<T>& a,int m){//0<=i<=m,sum_k\
    \ a_k^i\n    int n=a.size();\n    vector<Poly<T>> fs(n);\n    rep(i,0,n)fs[i]=Poly<T>({T(1),T(-a[i])});\n\
    \    auto ret=ProdOfPolys(fs);\n    ret.resize(m+1);\n    ret=ret.log();\n   \
    \ rep(i,0,m+1)ret[i]=-ret[i]*i;\n    ret[0]=a.size();\n    return ret;\n}\n\n\
    /**\n * @brief Enumerate $\\sum_k a_k^i$\n*/\n"
  code: "#pragma once\n#include \"FPS/prodofpolys.hpp\"\n\ntemplate<typename T>vector<T>\
    \ SumOfPowers(vector<T>& a,int m){//0<=i<=m,sum_k a_k^i\n    int n=a.size();\n\
    \    vector<Poly<T>> fs(n);\n    rep(i,0,n)fs[i]=Poly<T>({T(1),T(-a[i])});\n \
    \   auto ret=ProdOfPolys(fs);\n    ret.resize(m+1);\n    ret=ret.log();\n    rep(i,0,m+1)ret[i]=-ret[i]*i;\n\
    \    ret[0]=a.size();\n    return ret;\n}\n\n/**\n * @brief Enumerate $\\sum_k\
    \ a_k^i$\n*/"
  dependsOn:
  - FPS/prodofpolys.hpp
  isVerificationFile: false
  path: FPS/sumofpowers.hpp
  requiredBy: []
  timestamp: '2023-01-17 03:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/sumofpowers.hpp
layout: document
redirect_from:
- /library/FPS/sumofpowers.hpp
- /library/FPS/sumofpowers.hpp.html
title: Enumerate $\sum_k a_k^i$
---
