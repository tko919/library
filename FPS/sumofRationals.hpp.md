---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Sum of Rationals
    links: []
  bundledCode: "#line 2 \"FPS/sumofRationals.hpp\"\n\ntemplate<typename T>pair<Poly<T>,Poly<T>>\
    \ SumOfRationals(vector<pair<Poly<T>,Poly<T>>>& fs){\n    using Ratio=pair<Poly<T>,Poly<T>>;\n\
    \    if(fs.empty())return {Poly<T>({T(1)}),Poly<T>({T(1)})};\n    sort(ALL(fs),[&](Ratio&\
    \ a,Ratio& b){return a.first.size()+a.second.size()<b.first.size()+b.second.size();});\n\
    \    deque<Ratio> deq;\n    for(auto& f:fs)deq.push_back(f);\n    while(deq.size()>1){\n\
    \        auto [f,g]=deq[0];\n        auto [p,q]=deq[1];\n        deq.push_back({f*q+g*p,g*q});\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Sum of Rationals\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>pair<Poly<T>,Poly<T>> SumOfRationals(vector<pair<Poly<T>,Poly<T>>>&\
    \ fs){\n    using Ratio=pair<Poly<T>,Poly<T>>;\n    if(fs.empty())return {Poly<T>({T(1)}),Poly<T>({T(1)})};\n\
    \    sort(ALL(fs),[&](Ratio& a,Ratio& b){return a.first.size()+a.second.size()<b.first.size()+b.second.size();});\n\
    \    deque<Ratio> deq;\n    for(auto& f:fs)deq.push_back(f);\n    while(deq.size()>1){\n\
    \        auto [f,g]=deq[0];\n        auto [p,q]=deq[1];\n        deq.push_back({f*q+g*p,g*q});\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Sum of Rationals\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/sumofRationals.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/sumofRationals.hpp
layout: document
redirect_from:
- /library/FPS/sumofRationals.hpp
- /library/FPS/sumofRationals.hpp.html
title: Sum of Rationals
---
