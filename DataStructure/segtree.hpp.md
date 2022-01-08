---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: DataStructure/2dsegtree.hpp
    title: 2D Segment Tree
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_point_add_rectangle_sum.test.cpp
    title: Verify/LC_point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_set_range_composite.test.cpp
    title: Verify/LC_point_set_range_composite.test.cpp
  - icon: ':x:'
    path: Verify/LC_rectangle_sum.test.cpp
    title: Verify/LC_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_staticrmq.test.cpp
    title: Verify/LC_staticrmq.test.cpp
  - icon: ':x:'
    path: Verify/LC_vertex_set_path_composite.test.cpp
    title: Verify/LC_vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree{\r\n    int sz; vector<M>\
    \ data;\r\n    SegmentTree(int n){\r\n        sz=1; while(sz<n)sz<<=1; data.assign(2*sz,m1());\r\
    \n    }\r\n    void run(vector<M> v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+sz]=v[i];\r\
    \n        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=sz; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=sz; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n       } return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+sz];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M\
    \ (*m1)()>struct SegmentTree{\r\n    int sz; vector<M> data;\r\n    SegmentTree(int\
    \ n){\r\n        sz=1; while(sz<n)sz<<=1; data.assign(2*sz,m1());\r\n    }\r\n\
    \    void run(vector<M> v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+sz]=v[i];\r\
    \n        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=sz; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=sz; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n       } return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+sz];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree.hpp
  requiredBy:
  - DataStructure/2dsegtree.hpp
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_point_add_rectangle_sum.test.cpp
  - Verify/LC_vertex_set_path_composite.test.cpp
  - Verify/LC_staticrmq.test.cpp
  - Verify/LC_rectangle_sum.test.cpp
  - Verify/LC_point_set_range_composite.test.cpp
documentation_of: DataStructure/segtree.hpp
layout: document
redirect_from:
- /library/DataStructure/segtree.hpp
- /library/DataStructure/segtree.hpp.html
title: Segment Tree
---
