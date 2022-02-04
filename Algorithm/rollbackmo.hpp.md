---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/rollbackmo.md
    document_title: Rollback Mo
    links: []
  bundledCode: "#line 2 \"Algorithm/rollbackmo.hpp\"\n\r\nstruct RollbackMo{\r\n \
    \   using P=array<int,2>;\r\n    int n,w;\r\n    vector<P> qs;\r\n    RollbackMo(int\
    \ _n):n(_n),w(sqrt(n)){}\r\n    void add(int lb,int rb){qs.push_back({lb,rb});}\r\
    \n    void init();\r\n    void insert(int i);\r\n    void snapshot();\r\n    void\
    \ rollback();\r\n    void out(int i);\r\n    void run(){\r\n        const int\
    \ q=qs.size();\r\n        vector<int> ord(q);\r\n        iota(ALL(ord),0);\r\n\
    \        sort(ALL(ord),[&](int i,int j){\r\n            return P{qs[i][0]/w,qs[i][1]}<P{qs[j][0],qs[j][1]};\r\
    \n        });\r\n        init();\r\n        snapshot();\r\n        int last=-1,r=0;\r\
    \n        for(auto& i:ord)if(qs[i][1]-qs[i][0]<w){\r\n            rep(j,qs[i][0],qs[i][1])insert(j);\r\
    \n            out(i);\r\n            rollback();\r\n        }\r\n        for(auto&\
    \ i:ord)if(qs[i][1]-qs[i][0]>=w){\r\n            int b=qs[i][0]/w;\r\n       \
    \     if(last!=b){\r\n                init();\r\n                last=b;\r\n \
    \               r=(b+1)*w;\r\n            }\r\n            while(r<qs[i][1])insert(r++);\r\
    \n            snapshot();\r\n            for(int j=(b+1)*w-1;j>=qs[i][0];j--)insert(j);\r\
    \n            out(i);\r\n            rollback();\r\n        }\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Rollback Mo\r\n * @docs docs/rollbackmo.md\r\n */\n"
  code: "#pragma once\r\n\r\nstruct RollbackMo{\r\n    using P=array<int,2>;\r\n \
    \   int n,w;\r\n    vector<P> qs;\r\n    RollbackMo(int _n):n(_n),w(sqrt(n)){}\r\
    \n    void add(int lb,int rb){qs.push_back({lb,rb});}\r\n    void init();\r\n\
    \    void insert(int i);\r\n    void snapshot();\r\n    void rollback();\r\n \
    \   void out(int i);\r\n    void run(){\r\n        const int q=qs.size();\r\n\
    \        vector<int> ord(q);\r\n        iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int\
    \ i,int j){\r\n            return P{qs[i][0]/w,qs[i][1]}<P{qs[j][0],qs[j][1]};\r\
    \n        });\r\n        init();\r\n        snapshot();\r\n        int last=-1,r=0;\r\
    \n        for(auto& i:ord)if(qs[i][1]-qs[i][0]<w){\r\n            rep(j,qs[i][0],qs[i][1])insert(j);\r\
    \n            out(i);\r\n            rollback();\r\n        }\r\n        for(auto&\
    \ i:ord)if(qs[i][1]-qs[i][0]>=w){\r\n            int b=qs[i][0]/w;\r\n       \
    \     if(last!=b){\r\n                init();\r\n                last=b;\r\n \
    \               r=(b+1)*w;\r\n            }\r\n            while(r<qs[i][1])insert(r++);\r\
    \n            snapshot();\r\n            for(int j=(b+1)*w-1;j>=qs[i][0];j--)insert(j);\r\
    \n            out(i);\r\n            rollback();\r\n        }\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Rollback Mo\r\n * @docs docs/rollbackmo.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/rollbackmo.hpp
  requiredBy: []
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/rollbackmo.hpp
layout: document
redirect_from:
- /library/Algorithm/rollbackmo.hpp
- /library/Algorithm/rollbackmo.hpp.html
title: Rollback Mo
---
## 使い方

`RollbackMo(int n)`: 要素数 $n$ のデータ構造を作成。  
`void add(int L,int R)`: 半開区間 $[L,R)$ をクエリに追加。  
`void run()`: クエリを実行。
* `init()` (初期化)  
* `insert(int i)` (要素 $i$ を追加)  
* `snapshot()` (部分永続的に保存)  
* `rollback()` (保存した状態まで巻き戻す)  
* `out(int $i$)` (クエリ $i$ の結果を書き込む)  
を準備する必要がある。