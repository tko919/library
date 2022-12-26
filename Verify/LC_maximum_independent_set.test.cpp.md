---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/maxindependentset.hpp
    title: Maximum Independent Set
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
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
    \ 0;}\n#line 2 \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device\
    \ rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\
    \n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
    \n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned\
    \ L){\r\n        return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T\
    \ L,T R){\r\n        return get(R-L)+L;\r\n    }\r\n    double uniform(){\r\n\
    \        return double(get())/UINT_MAX;\r\n    }\r\n    string str(int n){\r\n\
    \        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\n        return\
    \ ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter first,Iter last){\r\
    \n        if(first==last)return;\r\n        int len=1;\r\n        for(auto it=first+1;it!=last;it++){\r\
    \n            len++;\r\n            int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\
    \n        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
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
    \ */\n#line 5 \"Verify/LC_maximum_independent_set.test.cpp\"\n\r\nint main(){\r\
    \n    int n,m;\r\n    cin>>n>>m;\r\n    MaxIndependentSet g(n);\r\n    rep(i,0,m){\r\
    \n        int x,y;\r\n        cin>>x>>y;\r\n        g.add_edge(x,y);\r\n    }\r\
    \n    vector<ll> cost(n,1);\r\n    auto [ret,mask]=g.run(cost);\r\n    cout<<__builtin_popcountll(mask)<<'\\\
    n';\r\n    rep(i,0,n)if(mask>>i&1)cout<<i<<' ';\r\n    cout<<'\\n';\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Graph/maxindependentset.hpp\"\
    \r\n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    MaxIndependentSet\
    \ g(n);\r\n    rep(i,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n     \
    \   g.add_edge(x,y);\r\n    }\r\n    vector<ll> cost(n,1);\r\n    auto [ret,mask]=g.run(cost);\r\
    \n    cout<<__builtin_popcountll(mask)<<'\\n';\r\n    rep(i,0,n)if(mask>>i&1)cout<<i<<'\
    \ ';\r\n    cout<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/maxindependentset.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_maximum_independent_set.test.cpp
- /verify/Verify/LC_maximum_independent_set.test.cpp.html
title: Verify/LC_maximum_independent_set.test.cpp
---
