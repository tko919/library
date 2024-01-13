---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/2dsegtree.hpp
    title: 2D Segment Tree
  - icon: ':heavy_check_mark:'
    path: DataStructure/sortablesegtree.hpp
    title: Sortable Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_add_rectangle_sum.test.cpp
    title: Verify/LC_point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_set_range_composite.test.cpp
    title: Verify/LC_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_set_range_sort_range_composite.test.cpp
    title: Verify/LC_point_set_range_sort_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_rectangle_sum.test.cpp
    title: Verify/LC_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_staticrmq.test.cpp
    title: Verify/LC_staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_set_path_composite.test.cpp
    title: Verify/LC_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree{\r\n    int n; vector<M>\
    \ data;\r\n    SegmentTree(int _n=0){\r\n        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\
    \n    }\r\n    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\
    \n        for(int k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M\
    \ (*m1)()>struct SegmentTree{\r\n    int n; vector<M> data;\r\n    SegmentTree(int\
    \ _n=0){\r\n        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\n    }\r\n\
    \    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\
    \n        for(int k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree.hpp
  requiredBy:
  - DataStructure/2dsegtree.hpp
  - DataStructure/sortablesegtree.hpp
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_point_set_range_sort_range_composite.test.cpp
  - Verify/LC_point_set_range_composite.test.cpp
  - Verify/LC_staticrmq.test.cpp
  - Verify/LC_rectangle_sum.test.cpp
  - Verify/LC_vertex_set_path_composite.test.cpp
  - Verify/LC_point_add_rectangle_sum.test.cpp
documentation_of: DataStructure/segtree.hpp
layout: document
redirect_from:
- /library/DataStructure/segtree.hpp
- /library/DataStructure/segtree.hpp.html
title: Segment Tree
---
