---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_line_add_get_min.test.cpp
    title: Verify/LC_line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_segment_add_get_min.test.cpp
    title: Verify/LC_segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lichaotree.md
    document_title: Convex Hull Trick (Li Chao Tree)
    links: []
  bundledCode: "#line 2 \"DataStructure/lichaotree.hpp\"\n\r\ntemplate<typename T,T\
    \ MX>struct CHT{\r\n    using Line=pair<T,T>;\r\n    int n;\r\n    vector<T> xs;\r\
    \n    vector<Line> ls;\r\n    CHT(vector<T>& ps):xs(ps){\r\n        n=1;\r\n \
    \       while(n<(int)xs.size())n<<=1;\r\n        xs.resize(n,xs.back());\r\n \
    \       ls.resize(2*n-1,Line(0,MX));\r\n    }\r\n    T eval(Line& f,T x){return\
    \ f.first*x+f.second;}\r\n    void add(T a,T b,int k=0,int L=0,int R=-1){\r\n\
    \        if(R==-1)R=n;\r\n        Line f={a,b};\r\n        while(L!=R){\r\n  \
    \          int mid=(L+R)>>1;\r\n            T lx=xs[L],mx=xs[mid],rx=xs[R-1];\r\
    \n            Line& g=ls[k];\r\n            if(eval(f,lx)<eval(g,lx) and eval(f,rx)<eval(g,rx)){\r\
    \n                g=f;\r\n                return;\r\n            }\r\n       \
    \     if(eval(f,lx)>=eval(g,lx) and eval(f,rx)>=eval(g,rx))return;\r\n       \
    \     if(eval(f,mx)<eval(g,mx))swap(f,g);\r\n            if(eval(f,lx)<eval(g,lx)){\r\
    \n                k=k*2+1;\r\n                R=mid;\r\n            }\r\n    \
    \        else{\r\n                k=k*2+2;\r\n                L=mid;\r\n     \
    \       }\r\n        }\r\n    }\r\n    void add_segment(T a,T b,T L,T R){\r\n\
    \        int l=lower_bound(ALL(xs),L)-xs.begin(),r=lower_bound(ALL(xs),R)-xs.begin();\r\
    \n        int a0=l,b0=r;\r\n        l+=n,r+=n;\r\n        int sz=1;\r\n      \
    \  while(l<r){\r\n            if(r&1){\r\n                r--;\r\n           \
    \     b0-=sz;\r\n                add(a,b,r-1,b0,b0+sz);\r\n            }\r\n \
    \           if(l&1){\r\n                add(a,b,l-1,a0,a0+sz);\r\n           \
    \     l++;\r\n                a0+=sz;\r\n            }\r\n            l>>=1;\r\
    \n            r>>=1;\r\n            sz<<=1;\r\n        }\r\n    }\r\n    T getmin(T\
    \ x){\r\n        int k=lower_bound(ALL(xs),x)-xs.begin()+n-1;\r\n        T res=eval(ls[k],x);\r\
    \n        while(k){\r\n            k=(k-1)>>1;\r\n            chmin(res,eval(ls[k],x));\r\
    \n        }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Convex\
    \ Hull Trick (Li Chao Tree)\r\n * @docs docs/lichaotree.md\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T MX>struct CHT{\r\n    using Line=pair<T,T>;\r\
    \n    int n;\r\n    vector<T> xs;\r\n    vector<Line> ls;\r\n    CHT(vector<T>&\
    \ ps):xs(ps){\r\n        n=1;\r\n        while(n<(int)xs.size())n<<=1;\r\n   \
    \     xs.resize(n,xs.back());\r\n        ls.resize(2*n-1,Line(0,MX));\r\n    }\r\
    \n    T eval(Line& f,T x){return f.first*x+f.second;}\r\n    void add(T a,T b,int\
    \ k=0,int L=0,int R=-1){\r\n        if(R==-1)R=n;\r\n        Line f={a,b};\r\n\
    \        while(L!=R){\r\n            int mid=(L+R)>>1;\r\n            T lx=xs[L],mx=xs[mid],rx=xs[R-1];\r\
    \n            Line& g=ls[k];\r\n            if(eval(f,lx)<eval(g,lx) and eval(f,rx)<eval(g,rx)){\r\
    \n                g=f;\r\n                return;\r\n            }\r\n       \
    \     if(eval(f,lx)>=eval(g,lx) and eval(f,rx)>=eval(g,rx))return;\r\n       \
    \     if(eval(f,mx)<eval(g,mx))swap(f,g);\r\n            if(eval(f,lx)<eval(g,lx)){\r\
    \n                k=k*2+1;\r\n                R=mid;\r\n            }\r\n    \
    \        else{\r\n                k=k*2+2;\r\n                L=mid;\r\n     \
    \       }\r\n        }\r\n    }\r\n    void add_segment(T a,T b,T L,T R){\r\n\
    \        int l=lower_bound(ALL(xs),L)-xs.begin(),r=lower_bound(ALL(xs),R)-xs.begin();\r\
    \n        int a0=l,b0=r;\r\n        l+=n,r+=n;\r\n        int sz=1;\r\n      \
    \  while(l<r){\r\n            if(r&1){\r\n                r--;\r\n           \
    \     b0-=sz;\r\n                add(a,b,r-1,b0,b0+sz);\r\n            }\r\n \
    \           if(l&1){\r\n                add(a,b,l-1,a0,a0+sz);\r\n           \
    \     l++;\r\n                a0+=sz;\r\n            }\r\n            l>>=1;\r\
    \n            r>>=1;\r\n            sz<<=1;\r\n        }\r\n    }\r\n    T getmin(T\
    \ x){\r\n        int k=lower_bound(ALL(xs),x)-xs.begin()+n-1;\r\n        T res=eval(ls[k],x);\r\
    \n        while(k){\r\n            k=(k-1)>>1;\r\n            chmin(res,eval(ls[k],x));\r\
    \n        }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Convex\
    \ Hull Trick (Li Chao Tree)\r\n * @docs docs/lichaotree.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/lichaotree.hpp
  requiredBy: []
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_line_add_get_min.test.cpp
  - Verify/LC_segment_add_get_min.test.cpp
documentation_of: DataStructure/lichaotree.hpp
layout: document
redirect_from:
- /library/DataStructure/lichaotree.hpp
- /library/DataStructure/lichaotree.hpp.html
title: Convex Hull Trick (Li Chao Tree)
---
## 使い方

`CHT(vector<T>& ps)`: クエリを与える点を渡してデータ構造を作成。テンプレートに型と最大値を指定。  
`void add(T a,T b)`: 直線 $ax+b$ を追加。  
`void add_segment(T a,T b,T L,T R)`: 半開区間 $[L,R)$ に線分 $ax+b$ を追加。  
`T getmin(T x)`: y 座標の最小値を求める。(無ければ最大値を返す)