---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_add_range_sum.test.cpp
    title: Verify/LC_point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_static_range_sum.test.cpp
    title: Verify/LC_static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_add_path_sum.test.cpp
    title: Verify/LC_vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct\
    \ BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int _n):n(_n),val(_n+10){}\r\
    \n    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\
    \n        for(i++;i<=n;i+=(i&-i))val[i]+=x;\r\n        all+=x;\r\n    }\r\n  \
    \  T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n};\r\n\r\n/**\r\n * @brief Binary Indexed Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct BIT{\r\n    int n; T all=0;\
    \ vector<T> val;\r\n    BIT(int _n):n(_n),val(_n+10){}\r\n    void clear(){val.assign(n+10,0);\
    \ all=T();}\r\n    void add(int i,T x){\r\n        for(i++;i<=n;i+=(i&-i))val[i]+=x;\r\
    \n        all+=x;\r\n    }\r\n    T sum(int i){\r\n        T res=0;\r\n      \
    \  for(;i;i-=(i&-i))res+=val[i];\r\n        return res;\r\n    }\r\n    T sum(int\
    \ L,int R){return sum(R)-sum(L);} // [L,R)\r\n};\r\n\r\n/**\r\n * @brief Binary\
    \ Indexed Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/bit.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_static_range_sum.test.cpp
  - Verify/LC_point_add_range_sum.test.cpp
  - Verify/LC_vertex_add_path_sum.test.cpp
documentation_of: DataStructure/bit.hpp
layout: document
redirect_from:
- /library/DataStructure/bit.hpp
- /library/DataStructure/bit.hpp.html
title: Binary Indexed Tree
---
