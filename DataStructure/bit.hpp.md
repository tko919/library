---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/2dbit.hpp
    title: 2D Binary Indexed Tree
  - icon: ':x:'
    path: DataStructure/staticrectaddrectsum.hpp
    title: Static Rectangle Add Rectangle Sum
  - icon: ':x:'
    path: DataStructure/staticrectsum.hpp
    title: Static Rectangle Sum
  - icon: ':x:'
    path: String/prefixsubstrlcs.hpp
    title: Prefix Substring LCS
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_point_add_range_sum.test.cpp
    title: Verify/LC_point_add_range_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_prefix_substring_lcs.test.cpp
    title: Verify/LC_prefix_substring_lcs.test.cpp
  - icon: ':x:'
    path: Verify/LC_static_range_inversions_query.test.cpp
    title: Verify/LC_static_range_inversions_query.test.cpp
  - icon: ':x:'
    path: Verify/LC_static_range_sum.test.cpp
    title: Verify/LC_static_range_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
    title: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_vertex_add_path_sum.test.cpp
    title: Verify/LC_vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
    title: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct\
    \ BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\
    \n    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\
    \n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct BIT{\r\n    int n; T all=0;\
    \ vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\n    void clear(){val.assign(n+10,0);\
    \ all=T();}\r\n    void add(int i,T x){\r\n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\
    \n        all+=x;\r\n    }\r\n    T sum(int i){\r\n        T res=0;\r\n      \
    \  for(;i;i-=(i&-i))res+=val[i];\r\n        return res;\r\n    }\r\n    T sum(int\
    \ L,int R){return sum(R)-sum(L);} // [L,R)\r\n    int lower_bound(T x){\r\n  \
    \      int ret=0,len=1;\r\n        while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\
    \n            if(ret+len<=n and val[ret+len]<x){\r\n                ret+=len;\r\
    \n                x-=val[ret];\r\n            }\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Binary Indexed Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/bit.hpp
  requiredBy:
  - DataStructure/2dbit.hpp
  - DataStructure/staticrectaddrectsum.hpp
  - DataStructure/staticrectsum.hpp
  - String/prefixsubstrlcs.hpp
  timestamp: '2022-10-24 03:26:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_vertex_add_path_sum.test.cpp
  - Verify/LC_static_range_sum.test.cpp
  - Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
  - Verify/LC_prefix_substring_lcs.test.cpp
  - Verify/LC_static_range_inversions_query.test.cpp
  - Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
  - Verify/LC_point_add_range_sum.test.cpp
documentation_of: DataStructure/bit.hpp
layout: document
redirect_from:
- /library/DataStructure/bit.hpp
- /library/DataStructure/bit.hpp.html
title: Binary Indexed Tree
---
