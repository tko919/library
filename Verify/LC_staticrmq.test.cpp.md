---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Verify/LC_staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"DataStructure/segtree.hpp\"\
    \n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct\
    \ SegmentTree{\r\n    int n; vector<M> data;\r\n    SegmentTree(int _n=0){\r\n\
    \        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\n    }\r\n    void run(vector<M>&\
    \ v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\n        for(int\
    \ k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    void set(int\
    \ k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 5 \"Verify/LC_staticrmq.test.cpp\"\
    \n\r\nint f(int a,int b){return min(a,b);}\r\nint g(int a,int b){return b;}\r\n\
    int e(){return inf;}\r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n\
    \    vector<int> a(N);\r\n    rep(i,0,N)cin>>a[i];\r\n\r\n    SegmentTree<int,int,f,g,e>\
    \ seg(N);\r\n    seg.run(a);\r\n    while(Q--){\r\n        int L,R;\r\n      \
    \  cin>>L>>R;\r\n        cout<<seg.query(L,R)<<'\\n';\r\n    }\r\n    return 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"DataStructure/segtree.hpp\"\r\n\r\n\
    int f(int a,int b){return min(a,b);}\r\nint g(int a,int b){return b;}\r\nint e(){return\
    \ inf;}\r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<int>\
    \ a(N);\r\n    rep(i,0,N)cin>>a[i];\r\n\r\n    SegmentTree<int,int,f,g,e> seg(N);\r\
    \n    seg.run(a);\r\n    while(Q--){\r\n        int L,R;\r\n        cin>>L>>R;\r\
    \n        cout<<seg.query(L,R)<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Verify/LC_staticrmq.test.cpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_staticrmq.test.cpp
- /verify/Verify/LC_staticrmq.test.cpp.html
title: Verify/LC_staticrmq.test.cpp
---
