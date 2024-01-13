---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FPS/sumofpowers.hpp
    title: Enumerate $\sum_k a_k^i$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_product_of_polynomial_sequence.test.cpp
    title: Verify/LC_product_of_polynomial_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Product of Polynomials
    links: []
  bundledCode: "#line 2 \"FPS/prodofpolys.hpp\"\n\ntemplate<typename T>Poly<T> ProdOfPolys(vector<Poly<T>>&\
    \ fs){\n    if(fs.empty())return Poly<T>({T(1)});\n    sort(ALL(fs),[&](Poly<T>&\
    \ a,Poly<T>& b){return a.size()<b.size();});\n    deque<Poly<T>> deq;\n    for(auto&\
    \ f:fs)deq.push_back(f);\n    while(deq.size()>1){\n        deq.push_back(deq[0]*deq[1]);\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Product of Polynomials\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>Poly<T> ProdOfPolys(vector<Poly<T>>&\
    \ fs){\n    if(fs.empty())return Poly<T>({T(1)});\n    sort(ALL(fs),[&](Poly<T>&\
    \ a,Poly<T>& b){return a.size()<b.size();});\n    deque<Poly<T>> deq;\n    for(auto&\
    \ f:fs)deq.push_back(f);\n    while(deq.size()>1){\n        deq.push_back(deq[0]*deq[1]);\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Product of Polynomials\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/prodofpolys.hpp
  requiredBy:
  - FPS/sumofpowers.hpp
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_product_of_polynomial_sequence.test.cpp
documentation_of: FPS/prodofpolys.hpp
layout: document
redirect_from:
- /library/FPS/prodofpolys.hpp
- /library/FPS/prodofpolys.hpp.html
title: Product of Polynomials
---
