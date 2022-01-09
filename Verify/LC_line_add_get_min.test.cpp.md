---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lichaotree.hpp
    title: Convex Hull Trick (Li Chao Tree)
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"Verify/LC_line_add_get_min.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"DataStructure/lichaotree.hpp\"\n\r\ntemplate<typename T,T MX>struct\
    \ CHT{\r\n    using Line=pair<T,T>;\r\n    int n;\r\n    vector<T> xs;\r\n   \
    \ vector<Line> ls;\r\n    CHT(vector<T>& ps):xs(ps){\r\n        n=1;\r\n     \
    \   while(n<(int)xs.size())n<<=1;\r\n        xs.resize(n,xs.back());\r\n     \
    \   ls.resize(2*n-1,Line(0,MX));\r\n    }\r\n    T eval(Line& f,T x){return f.first*x+f.second;}\r\
    \n    void add(T a,T b,int k=0,int L=0,int R=-1){\r\n        if(R==-1)R=n;\r\n\
    \        Line f={a,b};\r\n        while(L!=R){\r\n            int mid=(L+R)>>1;\r\
    \n            T lx=xs[L],mx=xs[mid],rx=xs[R-1];\r\n            Line& g=ls[k];\r\
    \n            if(eval(f,lx)<eval(g,lx) and eval(f,rx)<eval(g,rx)){\r\n       \
    \         g=f;\r\n                return;\r\n            }\r\n            if(eval(f,lx)>=eval(g,lx)\
    \ and eval(f,rx)>=eval(g,rx))return;\r\n            if(eval(f,mx)<eval(g,mx))swap(f,g);\r\
    \n            if(eval(f,lx)<eval(g,lx)){\r\n                k=k*2+1;\r\n     \
    \           R=mid;\r\n            }\r\n            else{\r\n                k=k*2+2;\r\
    \n                L=mid;\r\n            }\r\n        }\r\n    }\r\n    void add_segment(T\
    \ a,T b,T L,T R){\r\n        int l=lower_bound(ALL(xs),L)-xs.begin(),r=lower_bound(ALL(xs),R)-xs.begin();\r\
    \n        int a0=l,b0=r;\r\n        l+=n,r+=n;\r\n        int sz=1;\r\n      \
    \  while(l<r){\r\n            if(r&1){\r\n                r--;\r\n           \
    \     b0-=sz;\r\n                add(a,b,r-1,b0,b0+sz);\r\n            }\r\n \
    \           if(l&1){\r\n                add(a,b,l-1,a0,a0+sz);\r\n           \
    \     l++;\r\n                a0+=sz;\r\n            }\r\n            l>>=1;\r\
    \n            r>>=1;\r\n            sz<<=1;\r\n        }\r\n    }\r\n    T getmin(T\
    \ x){\r\n        int k=lower_bound(ALL(xs),x)-xs.begin()+n-1;\r\n        T res=eval(ls[k],x);\r\
    \n        while(k){\r\n            k=(k-1)>>1;\r\n            chmin(res,eval(ls[k],x));\r\
    \n        }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Convex\
    \ Hull Trick (Li Chao Tree)\r\n */\n#line 5 \"Verify/LC_line_add_get_min.test.cpp\"\
    \n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<ll> a(N),b(N);\r\
    \n    rep(i,0,N)cin>>a[i]>>b[i];\r\n    vector<ll> t(Q),c(Q),d(Q);\r\n    vector<ll>\
    \ xs;\r\n    rep(i,0,Q){\r\n        cin>>t[i];\r\n        if(t[i]==0)cin>>c[i]>>d[i];\r\
    \n        else{\r\n            cin>>c[i];\r\n            xs.push_back(c[i]);\r\
    \n        }\r\n    }\r\n    sort(ALL(xs));\r\n    xs.erase(unique(ALL(xs)),xs.end());\r\
    \n\r\n    CHT<ll,INF> cht(xs);\r\n    rep(i,0,N)cht.add(a[i],b[i]);\r\n    rep(i,0,Q){\r\
    \n        if(t[i]==0)cht.add(c[i],d[i]);\r\n        else cout<<cht.getmin(c[i])<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"DataStructure/lichaotree.hpp\"\
    \r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<ll> a(N),b(N);\r\
    \n    rep(i,0,N)cin>>a[i]>>b[i];\r\n    vector<ll> t(Q),c(Q),d(Q);\r\n    vector<ll>\
    \ xs;\r\n    rep(i,0,Q){\r\n        cin>>t[i];\r\n        if(t[i]==0)cin>>c[i]>>d[i];\r\
    \n        else{\r\n            cin>>c[i];\r\n            xs.push_back(c[i]);\r\
    \n        }\r\n    }\r\n    sort(ALL(xs));\r\n    xs.erase(unique(ALL(xs)),xs.end());\r\
    \n\r\n    CHT<ll,INF> cht(xs);\r\n    rep(i,0,N)cht.add(a[i],b[i]);\r\n    rep(i,0,Q){\r\
    \n        if(t[i]==0)cht.add(c[i],d[i]);\r\n        else cout<<cht.getmin(c[i])<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/lichaotree.hpp
  isVerificationFile: true
  path: Verify/LC_line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_line_add_get_min.test.cpp
- /verify/Verify/LC_line_add_get_min.test.cpp.html
title: Verify/LC_line_add_get_min.test.cpp
---
