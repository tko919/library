---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Algorithm/mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Prefix Sum of Binomial Coefficient
    links: []
  bundledCode: "#line 2 \"Algorithm/mo.hpp\"\n\r\nstruct Mo{\r\n    const int n;\r\
    \n    vector<int> L,R;\r\n    Mo(int _n):n(_n){}\r\n    void add(int lb,int rb){\r\
    \n        L.push_back(lb);\r\n        R.push_back(rb);\r\n    }\r\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename OUT>\r\n    void\
    \ run(const AL& addl,const AR& addr,const DL& dell,const DR& delr,const OUT& out){\r\
    \n        const int q=L.size();\r\n        const int w=max<int>(1,1.0*n/max<double>(1.0,sqrt(q*2.0/3.0)));\r\
    \n        vector<int> ord(q);\r\n        iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int\
    \ i,int j){\r\n            int a=L[i]/w,b=L[j]/w;\r\n            if(a!=b)return\
    \ a<b;\r\n            if(a&1)return R[i]<R[j];\r\n            else return R[i]>R[j];\r\
    \n        });\r\n        int lb=0,rb=0;\r\n        for(auto& i:ord){\r\n     \
    \       while(lb>L[i])addl(--lb);\r\n            while(rb<R[i])addr(rb++);\r\n\
    \            while(lb<L[i])dell(lb++);\r\n            while(rb>R[i])delr(--rb);\r\
    \n            out(i);\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Mo's\
    \ Algorithm\r\n * @docs docs/mo.md\r\n */\n#line 3 \"Math/prefixbinom.hpp\"\n\n\
    template <typename T>\nvector<T> PrefixSumOfBinomial(const vector<pair<int, int>>\
    \ &qs) {\n    int N = 2;\n    for (auto &p : qs)\n        N = max(N, p.first);\n\
    \    int Q = qs.size();\n    Mo mo(N);\n    for (auto &p : qs) {\n        mo.add(p.second,\
    \ p.first);\n    }\n    vector<T> ans(Q);\n    T cur = 1;\n    int n = 0, m =\
    \ 0;\n    auto al = [&](int) { cur -= nCr<T>(n, m--); };\n    auto ar = [&](int)\
    \ { cur += cur - nCr<T>(n++, m); };\n    auto el = [&](int) { cur += nCr<T>(n,\
    \ ++m); };\n    auto er = [&](int) { cur = (cur + nCr<T>(--n, m)) * Inv<T>(2);\
    \ };\n    auto q = [&](int i) { ans[i] = cur; };\n    mo.run(al, ar, el, er, q);\n\
    \    return ans;\n}\n\n/**\n * @brief Prefix Sum of Binomial Coefficient\n */\n"
  code: "#pragma once\n#include \"Algorithm/mo.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ PrefixSumOfBinomial(const vector<pair<int, int>> &qs) {\n    int N = 2;\n  \
    \  for (auto &p : qs)\n        N = max(N, p.first);\n    int Q = qs.size();\n\
    \    Mo mo(N);\n    for (auto &p : qs) {\n        mo.add(p.second, p.first);\n\
    \    }\n    vector<T> ans(Q);\n    T cur = 1;\n    int n = 0, m = 0;\n    auto\
    \ al = [&](int) { cur -= nCr<T>(n, m--); };\n    auto ar = [&](int) { cur += cur\
    \ - nCr<T>(n++, m); };\n    auto el = [&](int) { cur += nCr<T>(n, ++m); };\n \
    \   auto er = [&](int) { cur = (cur + nCr<T>(--n, m)) * Inv<T>(2); };\n    auto\
    \ q = [&](int i) { ans[i] = cur; };\n    mo.run(al, ar, el, er, q);\n    return\
    \ ans;\n}\n\n/**\n * @brief Prefix Sum of Binomial Coefficient\n */"
  dependsOn:
  - Algorithm/mo.hpp
  isVerificationFile: false
  path: Math/prefixbinom.hpp
  requiredBy: []
  timestamp: '2026-10-28 08:02:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prefixbinom.hpp
layout: document
redirect_from:
- /library/Math/prefixbinom.hpp
- /library/Math/prefixbinom.hpp.html
title: Prefix Sum of Binomial Coefficient
---
