---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_add_range_sum.test.cpp
    title: Verify/LC_point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_static_range_inversions_query.test.cpp
    title: Verify/LC_static_range_inversions_query.test.cpp
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
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T,T (*ADD)(T,T),T\
    \ (*SUB)(T,T)>struct BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int\
    \ _n=0):n(_n),val(_n+10){}\r\n    void clear(){val.assign(n+10,0); all=T();}\r\
    \n    void add(int i,T x){\r\n        for(i++;i<=n;i+=(i&-i))val[i]=ADD(val[i],x);\r\
    \n        all=ADD(all,x);\r\n    }\r\n    T sum(int i){\r\n        T res=0;\r\n\
    \        for(;i;i-=(i&-i))res=ADD(res,val[i]);\r\n        return res;\r\n    }\r\
    \n    T sum(int L,int R){return SUB(sum(R),sum(L));} // [L,R)\r\n    int lower_bound(T\
    \ x){\r\n        int ret=0,len=1;\r\n        while(2*len<=n)len<<=1;\r\n     \
    \   for(;len>=1;len>>=1){\r\n            if(ret+len<=n and val[ret+len]<x){\r\n\
    \                ret+=len;\r\n                x=SUB(x,val[ret]);\r\n         \
    \   }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Binary Indexed Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T (*ADD)(T,T),T (*SUB)(T,T)>struct\
    \ BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\
    \n    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\
    \n        for(i++;i<=n;i+=(i&-i))val[i]=ADD(val[i],x);\r\n        all=ADD(all,x);\r\
    \n    }\r\n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res=ADD(res,val[i]);\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return SUB(sum(R),sum(L));}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x=SUB(x,val[ret]);\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/bit.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_static_range_sum.test.cpp
  - Verify/LC_static_range_inversions_query.test.cpp
  - Verify/LC_vertex_add_path_sum.test.cpp
  - Verify/LC_point_add_range_sum.test.cpp
documentation_of: DataStructure/bit.hpp
layout: document
redirect_from:
- /library/DataStructure/bit.hpp
- /library/DataStructure/bit.hpp.html
title: Binary Indexed Tree
---
