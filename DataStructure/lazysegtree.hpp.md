---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_range_affine_range_sum.test.cpp
    title: Verify/LC_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/lazysegtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>\r\n    class LazySegmentTree{\r\
    \n    int sz,height;\r\n    vector<M> data;\r\n    vector<N> lazy;\r\n    void\
    \ update(int k){data[k]=f(data[k*2],data[k*2+1]);}\r\n    void apply(int k,N x){\r\
    \n        data[k]=g(data[k],x);\r\n        if(k<sz)lazy[k]=h(lazy[k],x);\r\n \
    \   }\r\n    void down(int k){\r\n        apply(k*2,lazy[k]);\r\n        apply(k*2+1,lazy[k]);\r\
    \n        lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int n=0):LazySegmentTree(vector<M>(n,m1())){}\r\
    \n    LazySegmentTree(const vector<M>& a){\r\n        sz=1,height=0;\r\n     \
    \   while(sz<(int)a.size())sz<<=1,height++;\r\n        data.assign(2*sz,m1());\r\
    \n        lazy.assign(sz,n1());\r\n        rep(i,0,a.size())data[sz+i]=a[i];\r\
    \n        for(int i=sz-1;i;i--)update(i);\r\n    }\r\n    void set(int k,M x){\r\
    \n        k+=sz;\r\n        for(int i=height;i;i--)down(k>>i);\r\n        data[k]=x;\r\
    \n        for(int i=1;i<=height;i++)update(k>>i);\r\n    }\r\n    void update(int\
    \ L,int R,N x){\r\n        if(L>=R)return;\r\n        L+=sz,R+=sz;\r\n       \
    \ for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\n  \
    \          if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        int lb=L,rb=R;\r\
    \n        while(L<R){\r\n            if(L&1)apply(L++,x);\r\n            if(R&1)apply(--R,x);\r\
    \n            L>>=1;\r\n            R>>=1;\r\n        }\r\n        L=lb,R=rb;\r\
    \n        for(int i=1;i<=height;i++){\r\n            if(((L>>i)<<i)!=L)update(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)update((R-1)>>i);\r\n        }\r\n    }\r\n  \
    \  M query(int L,int R){\r\n        if(L>=R)return m1();\r\n        L+=sz,R+=sz;\r\
    \n        for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        M lb=m1(),rb=m1();\r\
    \n        while(L<R){\r\n            if(L&1)lb=f(lb,data[L++]);\r\n          \
    \  if(R&1)rb=f(data[--R],rb);\r\n            L>>=1;\r\n            R>>=1;\r\n\
    \        }\r\n        return f(lb,rb);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Lazy Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),N\
    \ (*h)(N,N),M (*m1)(),N (*n1)()>\r\n    class LazySegmentTree{\r\n    int sz,height;\r\
    \n    vector<M> data;\r\n    vector<N> lazy;\r\n    void update(int k){data[k]=f(data[k*2],data[k*2+1]);}\r\
    \n    void apply(int k,N x){\r\n        data[k]=g(data[k],x);\r\n        if(k<sz)lazy[k]=h(lazy[k],x);\r\
    \n    }\r\n    void down(int k){\r\n        apply(k*2,lazy[k]);\r\n        apply(k*2+1,lazy[k]);\r\
    \n        lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int n=0):LazySegmentTree(vector<M>(n,m1())){}\r\
    \n    LazySegmentTree(const vector<M>& a){\r\n        sz=1,height=0;\r\n     \
    \   while(sz<(int)a.size())sz<<=1,height++;\r\n        data.assign(2*sz,m1());\r\
    \n        lazy.assign(sz,n1());\r\n        rep(i,0,a.size())data[sz+i]=a[i];\r\
    \n        for(int i=sz-1;i;i--)update(i);\r\n    }\r\n    void set(int k,M x){\r\
    \n        k+=sz;\r\n        for(int i=height;i;i--)down(k>>i);\r\n        data[k]=x;\r\
    \n        for(int i=1;i<=height;i++)update(k>>i);\r\n    }\r\n    void update(int\
    \ L,int R,N x){\r\n        if(L>=R)return;\r\n        L+=sz,R+=sz;\r\n       \
    \ for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\n  \
    \          if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        int lb=L,rb=R;\r\
    \n        while(L<R){\r\n            if(L&1)apply(L++,x);\r\n            if(R&1)apply(--R,x);\r\
    \n            L>>=1;\r\n            R>>=1;\r\n        }\r\n        L=lb,R=rb;\r\
    \n        for(int i=1;i<=height;i++){\r\n            if(((L>>i)<<i)!=L)update(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)update((R-1)>>i);\r\n        }\r\n    }\r\n  \
    \  M query(int L,int R){\r\n        if(L>=R)return m1();\r\n        L+=sz,R+=sz;\r\
    \n        for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        M lb=m1(),rb=m1();\r\
    \n        while(L<R){\r\n            if(L&1)lb=f(lb,data[L++]);\r\n          \
    \  if(R&1)rb=f(data[--R],rb);\r\n            L>>=1;\r\n            R>>=1;\r\n\
    \        }\r\n        return f(lb,rb);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Lazy Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_range_affine_range_sum.test.cpp
documentation_of: DataStructure/lazysegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/lazysegtree.hpp
- /library/DataStructure/lazysegtree.hpp.html
title: Lazy Segment Tree
---
