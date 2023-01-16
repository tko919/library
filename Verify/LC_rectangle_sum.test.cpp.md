---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/2dsegtree.hpp
    title: 2D Segment Tree
  - icon: ':x:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"Verify/LC_rectangle_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"DataStructure/segtree.hpp\"\
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
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 3 \"DataStructure/2dsegtree.hpp\"\
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
    \n */\n#line 5 \"Verify/LC_rectangle_sum.test.cpp\"\n\r\nll f(ll a,ll b){return\
    \ a+b;}\r\nll g(ll a,ll b){return a+b;}\r\nll e(){return 0;}\r\n\r\nint main(){\r\
    \n    int n,q;\r\n    cin>>n>>q;\r\n    vector<int> x(n),y(n),w(n);\r\n    rep(i,0,n)cin>>x[i]>>y[i]>>w[i];\r\
    \n\r\n    SegmentTree2D<ll,ll,f,g,e> seg;\r\n    rep(i,0,n)seg.push(x[i],y[i]);\r\
    \n    seg.init();\r\n    rep(i,0,n)seg.update(x[i],y[i],w[i]);\r\n    while(q--){\r\
    \n        int l,r,d,u;\r\n        cin>>l>>d>>r>>u;\r\n        cout<<seg.query(l,r,d,u)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n\
    #include \"Template/template.hpp\"\r\n#include \"DataStructure/2dsegtree.hpp\"\
    \r\n\r\nll f(ll a,ll b){return a+b;}\r\nll g(ll a,ll b){return a+b;}\r\nll e(){return\
    \ 0;}\r\n\r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\n    vector<int>\
    \ x(n),y(n),w(n);\r\n    rep(i,0,n)cin>>x[i]>>y[i]>>w[i];\r\n\r\n    SegmentTree2D<ll,ll,f,g,e>\
    \ seg;\r\n    rep(i,0,n)seg.push(x[i],y[i]);\r\n    seg.init();\r\n    rep(i,0,n)seg.update(x[i],y[i],w[i]);\r\
    \n    while(q--){\r\n        int l,r,d,u;\r\n        cin>>l>>d>>r>>u;\r\n    \
    \    cout<<seg.query(l,r,d,u)<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/2dsegtree.hpp
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Verify/LC_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_rectangle_sum.test.cpp
- /verify/Verify/LC_rectangle_sum.test.cpp.html
title: Verify/LC_rectangle_sum.test.cpp
---
