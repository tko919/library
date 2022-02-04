---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_static_range_inversions_query.test.cpp
    title: Verify/LC_static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/mo.md
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 2 \"Algorithm/mo.hpp\"\n\r\nstruct Mo{\r\n    using P=pair<int,int>;\r\
    \n    const int n,w; vector<P> qs;\r\n    Mo(int _n):n(_n),w(sqrt(n)){}\r\n  \
    \  void add(int lb,int rb){qs.push_back({lb,rb});}\r\n    void addl(int i);\r\n\
    \    void addr(int i);\r\n    void dell(int i);\r\n    void delr(int i);\r\n \
    \   void out(int i);\r\n    void run(){\r\n        const int q=qs.size();\r\n\
    \        vector<int> ord(q); iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int\
    \ i,int j){\r\n            if(qs[i].first/w!=qs[j].first/w)return qs[i].first<qs[j].first;\r\
    \n            else return qs[i].second<qs[j].second;\r\n        });\r\n      \
    \  int lb=0,rb=0;\r\n        for(int i:ord){\r\n            auto [li,ri]=qs[i];\r\
    \n            while(lb>li)addl(--lb);\r\n            while(rb<ri)addr(rb++);\r\
    \n            while(lb<li)dell(lb++);\r\n            while(rb>ri)delr(--rb);\r\
    \n            out(i);\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Mo's\
    \ Algorithm\r\n * @docs docs/mo.md\r\n */\n"
  code: "#pragma once\r\n\r\nstruct Mo{\r\n    using P=pair<int,int>;\r\n    const\
    \ int n,w; vector<P> qs;\r\n    Mo(int _n):n(_n),w(sqrt(n)){}\r\n    void add(int\
    \ lb,int rb){qs.push_back({lb,rb});}\r\n    void addl(int i);\r\n    void addr(int\
    \ i);\r\n    void dell(int i);\r\n    void delr(int i);\r\n    void out(int i);\r\
    \n    void run(){\r\n        const int q=qs.size();\r\n        vector<int> ord(q);\
    \ iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int i,int j){\r\n           \
    \ if(qs[i].first/w!=qs[j].first/w)return qs[i].first<qs[j].first;\r\n        \
    \    else return qs[i].second<qs[j].second;\r\n        });\r\n        int lb=0,rb=0;\r\
    \n        for(int i:ord){\r\n            auto [li,ri]=qs[i];\r\n            while(lb>li)addl(--lb);\r\
    \n            while(rb<ri)addr(rb++);\r\n            while(lb<li)dell(lb++);\r\
    \n            while(rb>ri)delr(--rb);\r\n            out(i);\r\n        }\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Mo's Algorithm\r\n * @docs docs/mo.md\r\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/mo.hpp
  requiredBy: []
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
`void run()`: クエリを実行。事前に `addl(int i)` (左側に要素 $i$ を追加)、 `addr(int i)` (右側に要素 $i$ を追加)、 `dell(int i)` (左側の要素 $i$ を削除)、 `delr(int i)` (右側の要素 $i$ を削除)、 `out(int $i$)` (クエリ $i$ の結果を書き込む) を準備する必要がある。