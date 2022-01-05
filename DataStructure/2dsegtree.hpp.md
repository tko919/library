---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 2D Segment Tree
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
    \ data[k+sz];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 3 \"DataStructure/2dsegtree.hpp\"\
    \n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct\
    \ SegmentTree2D{\r\n    int n;\r\n    vector<SegmentTree<M,N,f,g,m1>> st;\r\n\
    \    vector<vector<int>> ys;\r\n    SegmentTree2D(){}\r\n    int id(int x,int\
    \ y){return lower_bound(ALL(ys[x]),y)-ys[x].begin();}\r\n    using P=pair<int,int>;\r\
    \n    vector<int> xs; vector<P> ps;\r\n    void push(int x,int y){\r\n       \
    \ ps.push_back({x,y});\r\n    }\r\n    void init(){\r\n        for(auto& [x,y]:ps)xs.push_back(x);\r\
    \n        sort(ALL(xs));\r\n        xs.erase(unique(ALL(xs)),xs.end());\r\n  \
    \      n=xs.size();\r\n        ys.resize(n*2);\r\n        for(auto& [x,y]:ps){\r\
    \n            int i=lower_bound(ALL(xs),x)-xs.begin();\r\n            for(i+=n;i;i>>=1)ys[i].push_back(y);\r\
    \n        }\r\n        for(int i=0;i<n*2;i++){\r\n            sort(ALL(ys[i]));\r\
    \n            ys[i].erase(unique(ALL(ys[i])),ys[i].end());\r\n            st.push_back(SegmentTree<M,N,f,g,m1>(ys[i].size()));\r\
    \n        }\r\n    }\r\n    void update(int x,int y,N w){\r\n        x=(lower_bound(ALL(xs),x)-xs.begin())+n;\r\
    \n        st[x].update(id(x,y),w);\r\n        M cur=st[x][id(x,y)];\r\n      \
    \  int pos=x;\r\n        while(x>>=1){\r\n            M opp=st[pos^1].query(id(pos^1,y),id(pos^1,y+1));\r\
    \n            cur=f(cur,opp);\r\n            st[x].set(id(x,y),cur);\r\n     \
    \       pos>>=1;\r\n        }\r\n    }\r\n    M query(int x0,int x1,int y0,int\
    \ y1){\r\n        x0=lower_bound(ALL(xs),x0)-xs.begin();\r\n        x1=lower_bound(ALL(xs),x1)-xs.begin();\r\
    \n        M res=m1();\r\n        for(x0+=n,x1+=n;x0<x1;x0>>=1,x1>>=1){\r\n   \
    \         if(x0&1)res=f(res,st[x0].query(id(x0,y0),id(x0,y1))),x0++;\r\n     \
    \       if(x1&1)x1--,res=f(res,st[x1].query(id(x1,y0),id(x1,y1)));\r\n       \
    \ }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief 2D Segment Tree\r\
    \n */\n"
  code: "#pragma once\r\n#include \"DataStructure/segtree.hpp\"\r\n\r\ntemplate<typename\
    \ M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree2D{\r\n   \
    \ int n;\r\n    vector<SegmentTree<M,N,f,g,m1>> st;\r\n    vector<vector<int>>\
    \ ys;\r\n    SegmentTree2D(){}\r\n    int id(int x,int y){return lower_bound(ALL(ys[x]),y)-ys[x].begin();}\r\
    \n    using P=pair<int,int>;\r\n    vector<int> xs; vector<P> ps;\r\n    void\
    \ push(int x,int y){\r\n        ps.push_back({x,y});\r\n    }\r\n    void init(){\r\
    \n        for(auto& [x,y]:ps)xs.push_back(x);\r\n        sort(ALL(xs));\r\n  \
    \      xs.erase(unique(ALL(xs)),xs.end());\r\n        n=xs.size();\r\n       \
    \ ys.resize(n*2);\r\n        for(auto& [x,y]:ps){\r\n            int i=lower_bound(ALL(xs),x)-xs.begin();\r\
    \n            for(i+=n;i;i>>=1)ys[i].push_back(y);\r\n        }\r\n        for(int\
    \ i=0;i<n*2;i++){\r\n            sort(ALL(ys[i]));\r\n            ys[i].erase(unique(ALL(ys[i])),ys[i].end());\r\
    \n            st.push_back(SegmentTree<M,N,f,g,m1>(ys[i].size()));\r\n       \
    \ }\r\n    }\r\n    void update(int x,int y,N w){\r\n        x=(lower_bound(ALL(xs),x)-xs.begin())+n;\r\
    \n        st[x].update(id(x,y),w);\r\n        M cur=st[x][id(x,y)];\r\n      \
    \  int pos=x;\r\n        while(x>>=1){\r\n            M opp=st[pos^1].query(id(pos^1,y),id(pos^1,y+1));\r\
    \n            cur=f(cur,opp);\r\n            st[x].set(id(x,y),cur);\r\n     \
    \       pos>>=1;\r\n        }\r\n    }\r\n    M query(int x0,int x1,int y0,int\
    \ y1){\r\n        x0=lower_bound(ALL(xs),x0)-xs.begin();\r\n        x1=lower_bound(ALL(xs),x1)-xs.begin();\r\
    \n        M res=m1();\r\n        for(x0+=n,x1+=n;x0<x1;x0>>=1,x1>>=1){\r\n   \
    \         if(x0&1)res=f(res,st[x0].query(id(x0,y0),id(x0,y1))),x0++;\r\n     \
    \       if(x1&1)x1--,res=f(res,st[x1].query(id(x1,y0),id(x1,y1)));\r\n       \
    \ }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief 2D Segment Tree\r\
    \n */"
  dependsOn:
  - DataStructure/segtree.hpp
  isVerificationFile: false
  path: DataStructure/2dsegtree.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/2dsegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/2dsegtree.hpp
- /library/DataStructure/2dsegtree.hpp.html
title: 2D Segment Tree
---
