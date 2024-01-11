---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Utility/random.hpp
    title: Random
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
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random{\r\n    mt19937_64\
    \ randgen(chrono::steady_clock::now().time_since_epoch().count());\r\n    using\
    \ u64=unsigned long long;\r\n    u64 get(){\r\n        return randgen();\r\n \
    \   }\r\n    template<typename T>T get(T L){\r\n        return get()%(L+1);\r\n\
    \    }\r\n    template<typename T>T get(T L,T R){\r\n        return get(R-L)+L;\r\
    \n    }\r\n    double uniform(){\r\n        return double(get(1000000000))/1000000000;\r\
    \n    }\r\n    string str(int n){\r\n        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\
    \n        return ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter\
    \ first,Iter last){\r\n        if(first==last)return;\r\n        int len=1;\r\n\
    \        for(auto it=first+1;it!=last;it++){\r\n            len++;\r\n       \
    \     int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\n\
    \        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 3 \"Graph/maxindependentset.hpp\"\n\r\nstruct MaxIndependentSet{\r\
    \n    const int n;\r\n    vector<ll> es;\r\n    MaxIndependentSet(int _n):n(_n),es(n){}\r\
    \n    void add_edge(int u,int v){\r\n        es[u]|=1LL<<v;\r\n        es[v]|=1LL<<u;\r\
    \n    }\r\n    pair<ll,ll> run(vector<ll>& cost,int _rot=1e6){\r\n        vector<int>\
    \ ord(n);\r\n        iota(ALL(ord),0);\r\n        Random gen;\r\n        ll ret=0;\r\
    \n        ll cur=0;\r\n        rep(_,0,_rot){\r\n            gen.shuffle(ALL(ord));\r\
    \n            ll add=0;\r\n            ll used=0;\r\n            for(auto& v:ord)if(!(used&es[v])){\r\
    \n                used|=(1LL<<v);\r\n                add+=cost[v];\r\n       \
    \     }\r\n            if(chmax(ret,add))cur=used;\r\n        }\r\n        return\
    \ {ret,cur};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Independent Set\r\n\
    \ */\n"
  code: "#pragma once\r\n#include \"Utility/random.hpp\"\r\n\r\nstruct MaxIndependentSet{\r\
    \n    const int n;\r\n    vector<ll> es;\r\n    MaxIndependentSet(int _n):n(_n),es(n){}\r\
    \n    void add_edge(int u,int v){\r\n        es[u]|=1LL<<v;\r\n        es[v]|=1LL<<u;\r\
    \n    }\r\n    pair<ll,ll> run(vector<ll>& cost,int _rot=1e6){\r\n        vector<int>\
    \ ord(n);\r\n        iota(ALL(ord),0);\r\n        Random gen;\r\n        ll ret=0;\r\
    \n        ll cur=0;\r\n        rep(_,0,_rot){\r\n            gen.shuffle(ALL(ord));\r\
    \n            ll add=0;\r\n            ll used=0;\r\n            for(auto& v:ord)if(!(used&es[v])){\r\
    \n                used|=(1LL<<v);\r\n                add+=cost[v];\r\n       \
    \     }\r\n            if(chmax(ret,add))cur=used;\r\n        }\r\n        return\
    \ {ret,cur};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Independent Set\r\n\
    \ */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: Graph/maxindependentset.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
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
