---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Algorithm/mo.hpp
    title: Mo's Algorithm
  - icon: ':x:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"Verify/LC_static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\r\n\
    \r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Algorithm/mo.hpp\"\n\r\n\
    struct Mo{\r\n    using P=pair<int,int>;\r\n    const int n,w; vector<P> qs;\r\
    \n    Mo(int _n):n(_n),w(sqrt(n)){}\r\n    void add(int lb,int rb){qs.push_back({lb,rb});}\r\
    \n    void addl(int i);\r\n    void addr(int i);\r\n    void dell(int i);\r\n\
    \    void delr(int i);\r\n    void out(int i);\r\n    void run(){\r\n        const\
    \ int q=qs.size();\r\n        vector<int> ord(q); iota(ALL(ord),0);\r\n      \
    \  sort(ALL(ord),[&](int i,int j){\r\n            if(qs[i].first/w!=qs[j].first/w)return\
    \ qs[i].first<qs[j].first;\r\n            else return qs[i].second<qs[j].second;\r\
    \n        });\r\n        int lb=0,rb=0;\r\n        for(int i:ord){\r\n       \
    \     auto [li,ri]=qs[i];\r\n            while(lb>li)addl(--lb);\r\n         \
    \   while(rb<ri)addr(rb++);\r\n            while(lb<li)dell(lb++);\r\n       \
    \     while(rb>ri)delr(--rb);\r\n            out(i);\r\n        }\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Mo's Algorithm\r\n */\n#line 2 \"DataStructure/bit.hpp\"\
    \n\r\ntemplate<typename T>struct BIT{\r\n    int n; T all=0; vector<T> val;\r\n\
    \    BIT(int _n):n(_n),val(_n+10){}\r\n    void clear(){val.assign(n+10,0); all=T();}\r\
    \n    void add(int i,T x){\r\n        for(i++;i<=n;i+=(i&-i))val[i]+=x;\r\n  \
    \      all+=x;\r\n    }\r\n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 6 \"Verify/LC_static_range_inversions_query.test.cpp\"\
    \n\r\nint a[101010];\r\nll ret[101010],cur=0;\r\nBIT<int> bit(101010);\r\n\r\n\
    void Mo::addl(int i){\r\n    cur+=bit.sum(a[i]);\r\n    bit.add(a[i],1);\r\n}\r\
    \nvoid Mo::addr(int i){\r\n    cur+=bit.all-bit.sum(a[i]);\r\n    bit.add(a[i],1);\r\
    \n}\r\nvoid Mo::dell(int i){\r\n    bit.add(a[i],-1);\r\n    cur-=bit.sum(a[i]);\r\
    \n}\r\nvoid Mo::delr(int i){\r\n    bit.add(a[i],-1);\r\n    cur-=bit.all-bit.sum(a[i]);\r\
    \n}\r\nvoid Mo::out(int i){\r\n    ret[i]=cur;\r\n}\r\n\r\nint main(){\r\n   \
    \ int n,q;\r\n    cin>>n>>q;\r\n    using P=pair<int,int>;\r\n    vector<P> vs(n);\r\
    \n    rep(i,0,n){\r\n        cin>>vs[i].first;\r\n        vs[i].second=i;\r\n\
    \    }\r\n    sort(ALL(vs));\r\n    rep(i,0,n)a[vs[i].second]=i;\r\n    Mo mo(n);\r\
    \n    rep(i,0,q){\r\n        int L,R;\r\n        cin>>L>>R;\r\n        mo.add(L,R);\r\
    \n    }\r\n    mo.run();\r\n    rep(i,0,q)cout<<ret[i]<<'\\n';\r\n    return 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Algorithm/mo.hpp\"\r\n\
    #include \"DataStructure/bit.hpp\"\r\n\r\nint a[101010];\r\nll ret[101010],cur=0;\r\
    \nBIT<int> bit(101010);\r\n\r\nvoid Mo::addl(int i){\r\n    cur+=bit.sum(a[i]);\r\
    \n    bit.add(a[i],1);\r\n}\r\nvoid Mo::addr(int i){\r\n    cur+=bit.all-bit.sum(a[i]);\r\
    \n    bit.add(a[i],1);\r\n}\r\nvoid Mo::dell(int i){\r\n    bit.add(a[i],-1);\r\
    \n    cur-=bit.sum(a[i]);\r\n}\r\nvoid Mo::delr(int i){\r\n    bit.add(a[i],-1);\r\
    \n    cur-=bit.all-bit.sum(a[i]);\r\n}\r\nvoid Mo::out(int i){\r\n    ret[i]=cur;\r\
    \n}\r\n\r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\n    using P=pair<int,int>;\r\
    \n    vector<P> vs(n);\r\n    rep(i,0,n){\r\n        cin>>vs[i].first;\r\n   \
    \     vs[i].second=i;\r\n    }\r\n    sort(ALL(vs));\r\n    rep(i,0,n)a[vs[i].second]=i;\r\
    \n    Mo mo(n);\r\n    rep(i,0,q){\r\n        int L,R;\r\n        cin>>L>>R;\r\
    \n        mo.add(L,R);\r\n    }\r\n    mo.run();\r\n    rep(i,0,q)cout<<ret[i]<<'\\\
    n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Algorithm/mo.hpp
  - DataStructure/bit.hpp
  isVerificationFile: true
  path: Verify/LC_static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_static_range_inversions_query.test.cpp
- /verify/Verify/LC_static_range_inversions_query.test.cpp.html
title: Verify/LC_static_range_inversions_query.test.cpp
---
