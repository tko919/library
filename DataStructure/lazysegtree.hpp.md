---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_range_affine_range_sum.test.cpp
    title: Verify/LC_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/lazysegtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N\r\n    ,M (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>\r\nclass\
    \ LazySegmentTree{\r\n    int sz,height; vector<M> data; vector<N> lazy;\r\n \
    \   M ref(int k){return g(data[k],lazy[k]);}\r\n    void recalc(int k){while(k>>=1)data[k]=f(ref(2*k),ref(2*k+1));}\r\
    \n    void thrust(int k){for(int i=height;i>0;i--)eval(k>>i);}\r\n    void eval(int\
    \ k){\r\n        lazy[2*k]=h(lazy[2*k],lazy[k]); lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\r\
    \n        data[k]=ref(k); lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int\
    \ n){\r\n        sz=1,height=0; while(sz<n)sz<<=1,height++;\r\n        data.assign(2*sz,m1());\
    \ lazy.assign(2*sz,n1());\r\n    }\r\n    void run(vector<M>& v){\r\n        rep(i,0,v.size())data[i+sz]=v[i];\r\
    \n        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int a,M x){thrust(a+=sz); data[a]=x; recalc(a);}\r\n    void update(int\
    \ a,int b,N x){\r\n        if(a>=b)return;\r\n        thrust(a+=sz); thrust(b+=sz-1);\r\
    \n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\r\n            if(l&1)lazy[l]=h(lazy[l],x),++l;\r\
    \n            if(r&1)--r,lazy[r]=h(lazy[r],x);\r\n        }\r\n        recalc(a);\
    \ recalc(b);\r\n    }\r\n    M query(int a,int b){\r\n        if(a>=b)return m1();\r\
    \n        thrust(a+=sz); thrust(b+=sz-1);\r\n        M L=m1(),R=m1();\r\n    \
    \    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\r\n            if(l&1)L=f(L,ref(l++));\r\
    \n            if(r&1)R=f(ref(--r),R);\r\n        } return f(L,R);\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Lazy Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,typename N\r\n    ,M (*f)(M,M),M\
    \ (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>\r\nclass LazySegmentTree{\r\n   \
    \ int sz,height; vector<M> data; vector<N> lazy;\r\n    M ref(int k){return g(data[k],lazy[k]);}\r\
    \n    void recalc(int k){while(k>>=1)data[k]=f(ref(2*k),ref(2*k+1));}\r\n    void\
    \ thrust(int k){for(int i=height;i>0;i--)eval(k>>i);}\r\n    void eval(int k){\r\
    \n        lazy[2*k]=h(lazy[2*k],lazy[k]); lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\r\
    \n        data[k]=ref(k); lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int\
    \ n){\r\n        sz=1,height=0; while(sz<n)sz<<=1,height++;\r\n        data.assign(2*sz,m1());\
    \ lazy.assign(2*sz,n1());\r\n    }\r\n    void run(vector<M>& v){\r\n        rep(i,0,v.size())data[i+sz]=v[i];\r\
    \n        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int a,M x){thrust(a+=sz); data[a]=x; recalc(a);}\r\n    void update(int\
    \ a,int b,N x){\r\n        if(a>=b)return;\r\n        thrust(a+=sz); thrust(b+=sz-1);\r\
    \n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\r\n            if(l&1)lazy[l]=h(lazy[l],x),++l;\r\
    \n            if(r&1)--r,lazy[r]=h(lazy[r],x);\r\n        }\r\n        recalc(a);\
    \ recalc(b);\r\n    }\r\n    M query(int a,int b){\r\n        if(a>=b)return m1();\r\
    \n        thrust(a+=sz); thrust(b+=sz-1);\r\n        M L=m1(),R=m1();\r\n    \
    \    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\r\n            if(l&1)L=f(L,ref(l++));\r\
    \n            if(r&1)R=f(ref(--r),R);\r\n        } return f(L,R);\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Lazy Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_range_affine_range_sum.test.cpp
documentation_of: DataStructure/lazysegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/lazysegtree.hpp
- /library/DataStructure/lazysegtree.hpp.html
title: Lazy Segment Tree
---
