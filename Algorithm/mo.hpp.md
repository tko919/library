---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_static_range_inversions_query.test.cpp
    title: Verify/LC_static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 2 \"Algorithm/mo.hpp\"\n\r\nstruct Mo{\r\n    using P=pair<int,int>;\r\
    \n    const int n,w; vector<P> qs;\r\n    Mo(int _n):n(_n),w(sqrt(n)){}\r\n  \
    \  void add(int lb,int rb){qs.push_back({lb,rb});}\r\n    void addl(int i);\r\n\
    \    void addr(int i);\r\n    void dell(int i);\r\n    void delr(int i);\r\n \
    \   void out(int i);\r\n    void run(){\r\n        const int q=qs.size();\r\n\
    \        vector<int> ord(q); iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int\
    \ i,int j){\r\n            if(qs[i].first/w!=qs[j].first/w)return qs[i].first<qs[j].first;\r\
    \n            else return qs[i].second<qs[j].second;\r\n        });\r\n      \
    \  int lb=0,rb=0;\r\n        for(int i:ord){\r\n            auto [li,ri]=qs[i];\r\
    \n            while(lb>li)addl(--lb);\r\n            while(rb<ri)addr(rb++);\r\
    \n            while(lb<li)dell(lb++);\r\n            while(rb>ri)delr(--rb);\r\
    \n            out(i);\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Mo's\
    \ Algorithm\r\n */\n"
  code: "#pragma once\r\n\r\nstruct Mo{\r\n    using P=pair<int,int>;\r\n    const\
    \ int n,w; vector<P> qs;\r\n    Mo(int _n):n(_n),w(sqrt(n)){}\r\n    void add(int\
    \ lb,int rb){qs.push_back({lb,rb});}\r\n    void addl(int i);\r\n    void addr(int\
    \ i);\r\n    void dell(int i);\r\n    void delr(int i);\r\n    void out(int i);\r\
    \n    void run(){\r\n        const int q=qs.size();\r\n        vector<int> ord(q);\
    \ iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int i,int j){\r\n           \
    \ if(qs[i].first/w!=qs[j].first/w)return qs[i].first<qs[j].first;\r\n        \
    \    else return qs[i].second<qs[j].second;\r\n        });\r\n        int lb=0,rb=0;\r\
    \n        for(int i:ord){\r\n            auto [li,ri]=qs[i];\r\n            while(lb>li)addl(--lb);\r\
    \n            while(rb<ri)addr(rb++);\r\n            while(lb<li)dell(lb++);\r\
    \n            while(rb>ri)delr(--rb);\r\n            out(i);\r\n        }\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Mo's Algorithm\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/mo.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_static_range_inversions_query.test.cpp
documentation_of: Algorithm/mo.hpp
layout: document
redirect_from:
- /library/Algorithm/mo.hpp
- /library/Algorithm/mo.hpp.html
title: Mo's Algorithm
---
