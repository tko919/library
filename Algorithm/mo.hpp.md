---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_static_range_inversions_query.test.cpp
    title: Verify/LC_static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/mo.md
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 2 \"Algorithm/mo.hpp\"\n\r\nstruct Mo{\r\n    const int n;\r\
    \n    vector<int> L,R;\r\n    Mo(int _n):n(_n){}\r\n    void add(int lb,int rb){\r\
    \n        L.push_back(lb);\r\n        R.push_back(rb);\r\n    }\r\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename OUT>\r\n    void\
    \ run(const AL& addl,const AR& addr,const DL& dell,const DR& delr,const OUT& out){\r\
    \n        const int q=L.size();\r\n        const int w=max(1,int(n/sqrt(q+1)));\r\
    \n        vector<int> ord(q);\r\n        iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int\
    \ i,int j){\r\n            int a=L[i]/w,b=L[j]/w;\r\n            if(a!=b)return\
    \ a<b;\r\n            else if(R[i]!=R[j])return (a&1)?R[i]>R[j]:R[i]<R[j];\r\n\
    \            else return L[i]<L[j];\r\n        });\r\n        int lb=0,rb=0;\r\
    \n        for(auto& i:ord){\r\n            while(lb>L[i])addl(--lb);\r\n     \
    \       while(rb<R[i])addr(rb++);\r\n            while(lb<L[i])dell(lb++);\r\n\
    \            while(rb>R[i])delr(--rb);\r\n            out(i);\r\n        }\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Mo's Algorithm\r\n * @docs docs/mo.md\r\n\
    \ */\n"
  code: "#pragma once\r\n\r\nstruct Mo{\r\n    const int n;\r\n    vector<int> L,R;\r\
    \n    Mo(int _n):n(_n){}\r\n    void add(int lb,int rb){\r\n        L.push_back(lb);\r\
    \n        R.push_back(rb);\r\n    }\r\n    template <typename AL, typename AR,\
    \ typename DL, typename DR, typename OUT>\r\n    void run(const AL& addl,const\
    \ AR& addr,const DL& dell,const DR& delr,const OUT& out){\r\n        const int\
    \ q=L.size();\r\n        const int w=max(1,int(n/sqrt(q+1)));\r\n        vector<int>\
    \ ord(q);\r\n        iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int i,int\
    \ j){\r\n            int a=L[i]/w,b=L[j]/w;\r\n            if(a!=b)return a<b;\r\
    \n            else if(R[i]!=R[j])return (a&1)?R[i]>R[j]:R[i]<R[j];\r\n       \
    \     else return L[i]<L[j];\r\n        });\r\n        int lb=0,rb=0;\r\n    \
    \    for(auto& i:ord){\r\n            while(lb>L[i])addl(--lb);\r\n          \
    \  while(rb<R[i])addr(rb++);\r\n            while(lb<L[i])dell(lb++);\r\n    \
    \        while(rb>R[i])delr(--rb);\r\n            out(i);\r\n        }\r\n   \
    \ }\r\n};\r\n\r\n/**\r\n * @brief Mo's Algorithm\r\n * @docs docs/mo.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/mo.hpp
  requiredBy: []
  timestamp: '2022-02-06 21:59:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_static_range_inversions_query.test.cpp
documentation_of: Algorithm/mo.hpp
layout: document
redirect_from:
- /library/Algorithm/mo.hpp
- /library/Algorithm/mo.hpp.html
title: Mo's Algorithm
---
## 使い方

`Mo(int n)`: 要素数 $n$ のデータ構造を作成。  
`void add(int L,int R)`: 半開区間 $[L,R)$ をクエリに追加。  
`void run()`: クエリを実行。  
* `addl(int i)` (左側に要素 $i$ を追加)  
* `addr(int i)` (右側に要素 $i$ を追加)  
* `dell(int i)` (左側の要素 $i$ を削除)  
* `delr(int i)` (右側の要素 $i$ を削除)  
* `out(int i)` (クエリ $i$ の結果を書き込む)  
を準備する必要がある。