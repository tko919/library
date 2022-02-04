---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Convolution/convexminplus.hpp
    title: Convex Min Plus Convolution
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/monotoneminima.md
    document_title: Monotone Minima
    links: []
  bundledCode: "#line 2 \"Algorithm/monotoneminima.hpp\"\n\r\ntemplate<typename F>vector<int>\
    \ MonotoneMinima(int R,int C,F cmp){\r\n    // cmp(i,j,k) := compare A[i,j] and\
    \ A[i,k] (A[i,j] -> false, A[i,k] -> true)\r\n    vector<int> ret(R);\r\n    auto\
    \ rec=[&](auto& f,vector<int> target)->void{\r\n        int m=target.size();\r\
    \n        if(m==0)return;\r\n        vector<int> even;\r\n        for(int i=1;i<m;i+=2)even.push_back(target[i]);\r\
    \n        f(f,even);\r\n        int cur=0;\r\n        for(int i=0;i<m;i+=2){\r\
    \n            ret[target[i]]=cur;\r\n            int end=C-1;\r\n            if(i!=m-1)end=ret[even[i/2]];\r\
    \n            while(cur<end){\r\n                cur++;\r\n                if(cmp(target[i],ret[target[i]],cur))ret[target[i]]=cur;\r\
    \n            }\r\n        }\r\n    };\r\n    vector<int> tmp(R);\r\n    iota(ALL(tmp),0);\r\
    \n    rec(rec,tmp);\r\n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Monotone Minima\r\
    \n * @docs docs/monotoneminima.md\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename F>vector<int> MonotoneMinima(int R,int\
    \ C,F cmp){\r\n    // cmp(i,j,k) := compare A[i,j] and A[i,k] (A[i,j] -> false,\
    \ A[i,k] -> true)\r\n    vector<int> ret(R);\r\n    auto rec=[&](auto& f,vector<int>\
    \ target)->void{\r\n        int m=target.size();\r\n        if(m==0)return;\r\n\
    \        vector<int> even;\r\n        for(int i=1;i<m;i+=2)even.push_back(target[i]);\r\
    \n        f(f,even);\r\n        int cur=0;\r\n        for(int i=0;i<m;i+=2){\r\
    \n            ret[target[i]]=cur;\r\n            int end=C-1;\r\n            if(i!=m-1)end=ret[even[i/2]];\r\
    \n            while(cur<end){\r\n                cur++;\r\n                if(cmp(target[i],ret[target[i]],cur))ret[target[i]]=cur;\r\
    \n            }\r\n        }\r\n    };\r\n    vector<int> tmp(R);\r\n    iota(ALL(tmp),0);\r\
    \n    rec(rec,tmp);\r\n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Monotone Minima\r\
    \n * @docs docs/monotoneminima.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/monotoneminima.hpp
  requiredBy:
  - Convolution/convexminplus.hpp
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/monotoneminima.hpp
layout: document
redirect_from:
- /library/Algorithm/monotoneminima.hpp
- /library/Algorithm/monotoneminima.hpp.html
title: Monotone Minima
---
## 使い方

`vector<int> MonotoneMinima(int R,int C,function<bool(int,int,int)> f)`: $R \times C$ 行列の各行で最小値を取る列の index を返す。  
$f(i,j,k)$ は $A_{i,j}$ と $A_{i,k}$ を比較して、 $A_{i,j}$ を採用するなら false ( $A_{i,k}$ を採用するなら true ) を返す関数。