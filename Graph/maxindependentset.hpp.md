---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_maximum_independent_set.test.cpp
    title: Verify/LC_maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Maximum Independent Set
    links: []
  bundledCode: "#line 2 \"Graph/maxindependentset.hpp\"\n\r\ntemplate<typename T>pair<T,ll>\
    \ MaxIndependentSet(vector<vector<int>>& a,vector<T> cost,int _rot=1e6){\r\n \
    \   int n=a.size();\r\n    vector<ll> es(n);\r\n    rep(i,0,n)rep(j,0,n)if(a[i][j]){\r\
    \n        es[i]|=(1LL<<j);\r\n    }\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),0);\r\
    \n    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\n\
    \    T ret=0;\r\n    ll cur=0;\r\n    rep(_,0,_rot){\r\n        shuffle(ALL(ord),mt);\r\
    \n        T add=0;\r\n        ll used=0;\r\n        for(auto& v:ord)if(!(used&es[v])){\r\
    \n            used|=(1LL<<v);\r\n            add+=cost[v];\r\n        }\r\n  \
    \      if(chmax(ret,add))cur=used;\r\n    }\r\n    return {ret,cur};\r\n}\r\n\r\
    \n/**\r\n * @brief Maximum Independent Set\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>pair<T,ll> MaxIndependentSet(vector<vector<int>>&\
    \ a,vector<T> cost,int _rot=1e6){\r\n    int n=a.size();\r\n    vector<ll> es(n);\r\
    \n    rep(i,0,n)rep(j,0,n)if(a[i][j]){\r\n        es[i]|=(1LL<<j);\r\n    }\r\n\
    \    vector<int> ord(n);\r\n    iota(ALL(ord),0);\r\n    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n    T ret=0;\r\n    ll cur=0;\r\n    rep(_,0,_rot){\r\n        shuffle(ALL(ord),mt);\r\
    \n        T add=0;\r\n        ll used=0;\r\n        for(auto& v:ord)if(!(used&es[v])){\r\
    \n            used|=(1LL<<v);\r\n            add+=cost[v];\r\n        }\r\n  \
    \      if(chmax(ret,add))cur=used;\r\n    }\r\n    return {ret,cur};\r\n}\r\n\r\
    \n/**\r\n * @brief Maximum Independent Set\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/maxindependentset.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_maximum_independent_set.test.cpp
documentation_of: Graph/maxindependentset.hpp
layout: document
redirect_from:
- /library/Graph/maxindependentset.hpp
- /library/Graph/maxindependentset.hpp.html
title: Maximum Independent Set
---
