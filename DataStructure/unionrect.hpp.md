---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazysegtree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_area_of_union_of_rectangles.test.cpp
    title: Verify/LC_area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Area of Union of Rectangles
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
    \ Lazy Segment Tree\r\n */\n#line 3 \"DataStructure/unionrect.hpp\"\n\r\nstruct\
    \ UnionInterval{\r\n    struct M{\r\n        ll len,mi,cnt;\r\n    };\r\n    static\
    \ M f(M a,M b){\r\n        if(a.mi<b.mi)return {a.len+b.len,a.mi,a.cnt};\r\n \
    \       else if(a.mi>b.mi)return {a.len+b.len,b.mi,b.cnt};\r\n        else return\
    \ {a.len+b.len,a.mi,a.cnt+b.cnt};\r\n    }\r\n    static M g(M a,int b){\r\n \
    \       return M{a.len,min(INF,a.mi+b),a.cnt};\r\n    }\r\n    static int h(int\
    \ a,int b){\r\n        return a+b;\r\n    }\r\n    static M m1(){\r\n        return\
    \ M{0,INF,0};\r\n    }\r\n    static int m2(){return 0;}\r\n\r\n    const int\
    \ n=0;\r\n    LazySegmentTree<M,int,f,g,h,m1,m2> seg;\r\n    UnionInterval(){}\r\
    \n    UnionInterval(vector<int>& xs):n(xs.size()-1){\r\n        vector<M> init(n);\r\
    \n        rep(i,0,n){\r\n            init[i]=M{xs[i+1]-xs[i],0,xs[i+1]-xs[i]};\r\
    \n        }\r\n        seg=LazySegmentTree<M,int,f,g,h,m1,m2>(init);\r\n    }\r\
    \n    void add(int L,int R){\r\n        seg.update(L,R,1);\r\n    }\r\n    void\
    \ erase(int L,int R){\r\n        seg.update(L,R,-1);\r\n    }\r\n    ll run(){\r\
    \n        auto [len,mi,cnt]=seg.query(0,n);\r\n        if(mi==0)len-=cnt;\r\n\
    \        return len;\r\n    }\r\n};\r\n\r\nstruct UnionRect{\r\n    vector<int>\
    \ L,R,D,U;\r\n    UnionRect(){}\r\n    void add(int lb,int rb,int db,int ub){\r\
    \n        L.push_back(lb);\r\n        R.push_back(rb);\r\n        D.push_back(db);\r\
    \n        U.push_back(ub);\r\n    }\r\n    ll run(){\r\n        int n=L.size();\r\
    \n        vector<int> xs=L,ys=D;\r\n        xs.insert(xs.end(),ALL(R));\r\n  \
    \      ys.insert(ys.end(),ALL(U));\r\n        sort(ALL(xs));\r\n        xs.erase(unique(ALL(xs)),xs.end());\r\
    \n        sort(ALL(ys));\r\n        ys.erase(unique(ALL(ys)),ys.end());\r\n\r\n\
    \        UnionInterval buf=UnionInterval(ys);\r\n        using P=pair<int,int>;\r\
    \n        vector in(xs.size(),vector<P>()),out(xs.size(),vector<P>());\r\n   \
    \     rep(i,0,n){\r\n            L[i]=lower_bound(ALL(xs),L[i])-xs.begin();\r\n\
    \            R[i]=lower_bound(ALL(xs),R[i])-xs.begin();\r\n            D[i]=lower_bound(ALL(ys),D[i])-ys.begin();\r\
    \n            U[i]=lower_bound(ALL(ys),U[i])-ys.begin();\r\n            in[L[i]].push_back({D[i],U[i]});\r\
    \n            out[R[i]].push_back({D[i],U[i]});\r\n        }\r\n        ll ret=0;\r\
    \n        rep(i,0,xs.size()-1){\r\n            for(auto& [d,u]:in[i])buf.add(d,u);\r\
    \n            for(auto& [d,u]:out[i])buf.erase(d,u);\r\n            ret+=buf.run()*(xs[i+1]-xs[i]);\r\
    \n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Area\
    \ of Union of Rectangles\r\n */\n"
  code: "#pragma once\r\n#include \"DataStructure/lazysegtree.hpp\"\r\n\r\nstruct\
    \ UnionInterval{\r\n    struct M{\r\n        ll len,mi,cnt;\r\n    };\r\n    static\
    \ M f(M a,M b){\r\n        if(a.mi<b.mi)return {a.len+b.len,a.mi,a.cnt};\r\n \
    \       else if(a.mi>b.mi)return {a.len+b.len,b.mi,b.cnt};\r\n        else return\
    \ {a.len+b.len,a.mi,a.cnt+b.cnt};\r\n    }\r\n    static M g(M a,int b){\r\n \
    \       return M{a.len,min(INF,a.mi+b),a.cnt};\r\n    }\r\n    static int h(int\
    \ a,int b){\r\n        return a+b;\r\n    }\r\n    static M m1(){\r\n        return\
    \ M{0,INF,0};\r\n    }\r\n    static int m2(){return 0;}\r\n\r\n    const int\
    \ n=0;\r\n    LazySegmentTree<M,int,f,g,h,m1,m2> seg;\r\n    UnionInterval(){}\r\
    \n    UnionInterval(vector<int>& xs):n(xs.size()-1){\r\n        vector<M> init(n);\r\
    \n        rep(i,0,n){\r\n            init[i]=M{xs[i+1]-xs[i],0,xs[i+1]-xs[i]};\r\
    \n        }\r\n        seg=LazySegmentTree<M,int,f,g,h,m1,m2>(init);\r\n    }\r\
    \n    void add(int L,int R){\r\n        seg.update(L,R,1);\r\n    }\r\n    void\
    \ erase(int L,int R){\r\n        seg.update(L,R,-1);\r\n    }\r\n    ll run(){\r\
    \n        auto [len,mi,cnt]=seg.query(0,n);\r\n        if(mi==0)len-=cnt;\r\n\
    \        return len;\r\n    }\r\n};\r\n\r\nstruct UnionRect{\r\n    vector<int>\
    \ L,R,D,U;\r\n    UnionRect(){}\r\n    void add(int lb,int rb,int db,int ub){\r\
    \n        L.push_back(lb);\r\n        R.push_back(rb);\r\n        D.push_back(db);\r\
    \n        U.push_back(ub);\r\n    }\r\n    ll run(){\r\n        int n=L.size();\r\
    \n        vector<int> xs=L,ys=D;\r\n        xs.insert(xs.end(),ALL(R));\r\n  \
    \      ys.insert(ys.end(),ALL(U));\r\n        sort(ALL(xs));\r\n        xs.erase(unique(ALL(xs)),xs.end());\r\
    \n        sort(ALL(ys));\r\n        ys.erase(unique(ALL(ys)),ys.end());\r\n\r\n\
    \        UnionInterval buf=UnionInterval(ys);\r\n        using P=pair<int,int>;\r\
    \n        vector in(xs.size(),vector<P>()),out(xs.size(),vector<P>());\r\n   \
    \     rep(i,0,n){\r\n            L[i]=lower_bound(ALL(xs),L[i])-xs.begin();\r\n\
    \            R[i]=lower_bound(ALL(xs),R[i])-xs.begin();\r\n            D[i]=lower_bound(ALL(ys),D[i])-ys.begin();\r\
    \n            U[i]=lower_bound(ALL(ys),U[i])-ys.begin();\r\n            in[L[i]].push_back({D[i],U[i]});\r\
    \n            out[R[i]].push_back({D[i],U[i]});\r\n        }\r\n        ll ret=0;\r\
    \n        rep(i,0,xs.size()-1){\r\n            for(auto& [d,u]:in[i])buf.add(d,u);\r\
    \n            for(auto& [d,u]:out[i])buf.erase(d,u);\r\n            ret+=buf.run()*(xs[i+1]-xs[i]);\r\
    \n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Area\
    \ of Union of Rectangles\r\n */"
  dependsOn:
  - DataStructure/lazysegtree.hpp
  isVerificationFile: false
  path: DataStructure/unionrect.hpp
  requiredBy: []
  timestamp: '2022-10-24 03:26:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_area_of_union_of_rectangles.test.cpp
documentation_of: DataStructure/unionrect.hpp
layout: document
redirect_from:
- /library/DataStructure/unionrect.hpp
- /library/DataStructure/unionrect.hpp.html
title: Area of Union of Rectangles
---