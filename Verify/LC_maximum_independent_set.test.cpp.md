---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/maxindependentset.hpp
    title: Maximum Independent Set
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"Verify/LC_maximum_independent_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Graph/maxindependentset.hpp\"\n\r\ntemplate<typename T>pair<T,ll>\
    \ MaxIndependentSet(vector<vector<int>>& a,vector<T> cost,int _rot=1e6){\r\n \
    \   int n=a.size();\r\n    vector<ll> es(n);\r\n    rep(i,0,n)rep(j,0,n)if(a[i][j]){\r\
    \n        es[i]|=(1LL<<j);\r\n    }\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),0);\r\
    \n    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\n\
    \    T ret=0;\r\n    ll cur=0;\r\n    rep(_,0,_rot){\r\n        shuffle(ALL(ord),mt);\r\
    \n        T add=0;\r\n        ll used=0;\r\n        for(auto& v:ord)if(!(used&es[v])){\r\
    \n            used|=(1LL<<v);\r\n            add+=cost[v];\r\n        }\r\n  \
    \      if(chmax(ret,add))cur=used;\r\n    }\r\n    return {ret,cur};\r\n}\r\n\r\
    \n/**\r\n * @brief Maximum Independent Set\r\n */\n#line 5 \"Verify/LC_maximum_independent_set.test.cpp\"\
    \n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    vector a(n,vector<int>(n));\r\
    \n    rep(i,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        a[x][y]=a[y][x]=1;\r\
    \n    }\r\n    vector<int> cost(n,1);\r\n    auto [ret,mask]=MaxIndependentSet(a,cost);\r\
    \n    cout<<__builtin_popcountll(mask)<<'\\n';\r\n    rep(i,0,n)if(mask>>i&1)cout<<i<<'\
    \ ';\r\n    cout<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Graph/maxindependentset.hpp\"\
    \r\n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    vector a(n,vector<int>(n));\r\
    \n    rep(i,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        a[x][y]=a[y][x]=1;\r\
    \n    }\r\n    vector<int> cost(n,1);\r\n    auto [ret,mask]=MaxIndependentSet(a,cost);\r\
    \n    cout<<__builtin_popcountll(mask)<<'\\n';\r\n    rep(i,0,n)if(mask>>i&1)cout<<i<<'\
    \ ';\r\n    cout<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/maxindependentset.hpp
  isVerificationFile: true
  path: Verify/LC_maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_maximum_independent_set.test.cpp
- /verify/Verify/LC_maximum_independent_set.test.cpp.html
title: Verify/LC_maximum_independent_set.test.cpp
---
