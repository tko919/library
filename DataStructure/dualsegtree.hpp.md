---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/AOJ_DSL_2_D.test.cpp
    title: Verify/AOJ_DSL_2_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Dual Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/dualsegtree.hpp\"\n\r\ntemplate<typename M,M\
    \ (*f)(M,M),M (*m1)()>class DualSegmentTree{\r\n    int sz,height;\r\n    vector<M>\
    \ data;\r\n    void down(int k){\r\n        data[k*2]=f(data[k*2],data[k]);\r\n\
    \        data[k*2+1]=f(data[k*2+1],data[k]);\r\n        data[k]=m1();\r\n    }\r\
    \npublic:\r\n    DualSegmentTree(int n){\r\n        sz=1,height=0;\r\n       \
    \ while(sz<n)sz<<=1,height++;\r\n        data.assign(2*sz,m1());\r\n    }\r\n\
    \    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+sz]=v[i];\r\
    \n    }\r\n    void update(int a,int b,M x){\r\n        if(a>=b)return;\r\n  \
    \      a+=sz,b+=sz;\r\n        for(int i=height;i;i--){\r\n            if(((a>>i)<<i)!=a)down(a>>i);\r\
    \n            if(((b>>i)<<i)!=b)down((b-1)>>i);\r\n        }\r\n        for(;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)data[a]=f(data[a],x),a++;\r\n            if(b&1)--b,data[b]=f(data[b],x);\r\
    \n        }\r\n    }\r\n    M query(int k){\r\n        k+=sz;\r\n        for(int\
    \ i=height;i;i--){\r\n            if(((k>>i)<<i)!=k)down(k>>i);\r\n        }\r\
    \n        M ret=data[k];\r\n        while(k>>=1)ret=f(ret,data[k]);\r\n      \
    \  return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Dual Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,M (*f)(M,M),M (*m1)()>class DualSegmentTree{\r\
    \n    int sz,height;\r\n    vector<M> data;\r\n    void down(int k){\r\n     \
    \   data[k*2]=f(data[k*2],data[k]);\r\n        data[k*2+1]=f(data[k*2+1],data[k]);\r\
    \n        data[k]=m1();\r\n    }\r\npublic:\r\n    DualSegmentTree(int n){\r\n\
    \        sz=1,height=0;\r\n        while(sz<n)sz<<=1,height++;\r\n        data.assign(2*sz,m1());\r\
    \n    }\r\n    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+sz]=v[i];\r\
    \n    }\r\n    void update(int a,int b,M x){\r\n        if(a>=b)return;\r\n  \
    \      a+=sz,b+=sz;\r\n        for(int i=height;i;i--){\r\n            if(((a>>i)<<i)!=a)down(a>>i);\r\
    \n            if(((b>>i)<<i)!=b)down((b-1)>>i);\r\n        }\r\n        for(;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)data[a]=f(data[a],x),a++;\r\n            if(b&1)--b,data[b]=f(data[b],x);\r\
    \n        }\r\n    }\r\n    M query(int k){\r\n        k+=sz;\r\n        for(int\
    \ i=height;i;i--){\r\n            if(((k>>i)<<i)!=k)down(k>>i);\r\n        }\r\
    \n        M ret=data[k];\r\n        while(k>>=1)ret=f(ret,data[k]);\r\n      \
    \  return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Dual Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/dualsegtree.hpp
  requiredBy: []
  timestamp: '2022-01-31 02:08:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/AOJ_DSL_2_D.test.cpp
documentation_of: DataStructure/dualsegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/dualsegtree.hpp
- /library/DataStructure/dualsegtree.hpp.html
title: Dual Segment Tree
---
