---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/rangeunionset.md
    document_title: Range Union Set
    links: []
  bundledCode: "#line 2 \"DataStructure/rangeunionset.hpp\"\n\r\ntemplate<typename\
    \ T,T mx>struct RangeUnionSet{\r\n    map<T,T> data;\r\n    RangeUnionSet(){}\r\
    \n    void insert(T lb,T rb){\r\n        auto L=data.upper_bound(lb),R=data.upper_bound(rb);\r\
    \n        if(L!=data.begin() and lb<=prev(L)->second)L--;\r\n        if(L!=R){\r\
    \n            chmin(lb,L->first);\r\n            chmax(rb,prev(R)->second);\r\n\
    \            data.erase(L,R);\r\n        }\r\n        data[lb]=rb;\r\n    }\r\n\
    \    void erase(T lb,T rb){\r\n        auto L=data.upper_bound(lb),R=data.upper_bound(rb);\r\
    \n        if(L!=data.begin() and lb<=prev(L)->second)L--;\r\n        if(L==R)return;\r\
    \n        T nl=min(lb,L->first),nr=max(rb,prev(R)->second);\r\n        data.erase(L,R);\r\
    \n        if(nl<lb)data[nl]=lb;\r\n        if(rb<nr)data[rb]=nr;\r\n    }\r\n\
    \    T mex(T x)const{\r\n        auto it=data.lower_bound(x);\r\n        if(it!=data.begin()\
    \ and prev(it)->second>x)it--;\r\n        if(it==data.end())return mx;\r\n   \
    \     return max(x,it->first);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Range Union\
    \ Set\r\n * @docs docs/rangeunionset.md\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T mx>struct RangeUnionSet{\r\n  \
    \  map<T,T> data;\r\n    RangeUnionSet(){}\r\n    void insert(T lb,T rb){\r\n\
    \        auto L=data.upper_bound(lb),R=data.upper_bound(rb);\r\n        if(L!=data.begin()\
    \ and lb<=prev(L)->second)L--;\r\n        if(L!=R){\r\n            chmin(lb,L->first);\r\
    \n            chmax(rb,prev(R)->second);\r\n            data.erase(L,R);\r\n \
    \       }\r\n        data[lb]=rb;\r\n    }\r\n    void erase(T lb,T rb){\r\n \
    \       auto L=data.upper_bound(lb),R=data.upper_bound(rb);\r\n        if(L!=data.begin()\
    \ and lb<=prev(L)->second)L--;\r\n        if(L==R)return;\r\n        T nl=min(lb,L->first),nr=max(rb,prev(R)->second);\r\
    \n        data.erase(L,R);\r\n        if(nl<lb)data[nl]=lb;\r\n        if(rb<nr)data[rb]=nr;\r\
    \n    }\r\n    T mex(T x)const{\r\n        auto it=data.lower_bound(x);\r\n  \
    \      if(it!=data.begin() and prev(it)->second>x)it--;\r\n        if(it==data.end())return\
    \ mx;\r\n        return max(x,it->first);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Range Union Set\r\n * @docs docs/rangeunionset.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/rangeunionset.hpp
  requiredBy: []
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/rangeunionset.hpp
layout: document
redirect_from:
- /library/DataStructure/rangeunionset.hpp
- /library/DataStructure/rangeunionset.hpp.html
title: Range Union Set
---
## 使い方

`RangeUnionSet()`: 空のデータ構造を作成。テンプレートに型と最大値を指定。
`void insert(T L,T R)`: 半開区間 $[L,R)$ を整数集合に追加。
`void erase(T L,T R)`: 半開区間 $[L,R)$ を整数集合から削除。
`T mex(T x)`: 整数集合の mex を求める。