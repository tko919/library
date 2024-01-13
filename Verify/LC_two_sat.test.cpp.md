---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: Strongly Connected Components
  - icon: ':heavy_check_mark:'
    path: Math/twosat.hpp
    title: 2-SAT
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"Verify/LC_two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
    \n#define UB(v,x) int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long\
    \ long int;\r\nusing ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing\
    \ u128=__uint128_t;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Graph/scc.hpp\"\
    \n\r\nstruct SCC{\r\n    int n,m,cur;\r\n    vector<vector<int>> g;\r\n    vector<int>\
    \ low,ord,id;\r\n    SCC(int _n=0):n(_n),m(0),cur(0),g(_n),low(_n),ord(_n,-1),id(_n){}\r\
    \n    void resize(int _n){\r\n        n=_n;\r\n        g.resize(n);\r\n      \
    \  low.resize(n);\r\n        ord.resize(n,-1);\r\n        id.resize(n);\r\n  \
    \  }\r\n    void add_edge(int u,int v){g[u].emplace_back(v);}\r\n    void dfs(int\
    \ v,vector<int>& used){\r\n        ord[v]=low[v]=cur++;\r\n        used.emplace_back(v);\r\
    \n        for(auto& nxt:g[v]){\r\n            if(ord[nxt]==-1){\r\n          \
    \      dfs(nxt,used); chmin(low[v],low[nxt]);\r\n            }\r\n           \
    \ else{\r\n                chmin(low[v],ord[nxt]);\r\n            }\r\n      \
    \  }\r\n        if(ord[v]==low[v]){\r\n            while(1){\r\n             \
    \   int add=used.back(); used.pop_back();\r\n                ord[add]=n; id[add]=m;\r\
    \n                if(v==add)break;\r\n            }\r\n            m++;\r\n  \
    \      }\r\n    }\r\n    void run(){\r\n        vector<int> used;\r\n        rep(v,0,n)if(ord[v]==-1)dfs(v,used);\r\
    \n        for(auto& x:id)x=m-1-x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Strongly\
    \ Connected Components\r\n */\n#line 3 \"Math/twosat.hpp\"\n\r\nstruct TwoSat{\r\
    \n    int n;\r\n    vector<bool> res;\r\n    SCC graph;\r\n    TwoSat(int _n):n(_n),res(n),graph(n*2){}\r\
    \n    void add(int x){\r\n        n+=x;\r\n        res.resize(n);\r\n        graph.resize(n*2);\r\
    \n    }\r\n    void either(int i,bool f,int j,bool g){\r\n        graph.add_edge(2*i+(f^1),2*j+g);\r\
    \n        graph.add_edge(2*j+(g^1),2*i+f);\r\n    }\r\n    void AtMostOne(vector<int>&\
    \ a){\r\n        int offset=n;\r\n        add(a.size());\r\n        rep(i,0,a.size())either(a[i],0,offset+i,1);\r\
    \n        rep(i,1,a.size())either(offset+i-1,0,offset+i,1);\r\n        rep(i,1,a.size())either(a[i],0,offset+i-1,0);\r\
    \n    }\r\n    bool satisfiable(){\r\n        graph.run();\r\n        auto id=graph.id;\r\
    \n        rep(i,0,n){\r\n            if(id[i*2]==id[i*2+1])return false;\r\n \
    \           res[i]=id[i*2]<id[i*2+1];\r\n        }\r\n        return true;\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief 2-SAT\r\n */\n#line 5 \"Verify/LC_two_sat.test.cpp\"\
    \n\r\nint main(){\r\n    string tmp;\r\n    int n,m; cin>>tmp>>tmp>>n>>m;\r\n\
    \    TwoSat ts(n+1);\r\n    rep(i,0,m){\r\n        int a,b; cin>>a>>b>>tmp;\r\n\
    \        ts.either(abs(a),a>0,abs(b),b>0);\r\n    }\r\n    if(!ts.satisfiable()){\r\
    \n        puts(\"s UNSATISFIABLE\");\r\n        return 0;\r\n    }\r\n    puts(\"\
    s SATISFIABLE\");\r\n    cout<<\"v \";\r\n    auto res=ts.res;\r\n    rep(i,1,n+1){\r\
    \n        if(res[i])cout<<i<<' ';\r\n        else cout<<-i<<' ';\r\n    }\r\n\
    \    puts(\"0\");\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"Math/twosat.hpp\"\r\n\r\nint main(){\r\
    \n    string tmp;\r\n    int n,m; cin>>tmp>>tmp>>n>>m;\r\n    TwoSat ts(n+1);\r\
    \n    rep(i,0,m){\r\n        int a,b; cin>>a>>b>>tmp;\r\n        ts.either(abs(a),a>0,abs(b),b>0);\r\
    \n    }\r\n    if(!ts.satisfiable()){\r\n        puts(\"s UNSATISFIABLE\");\r\n\
    \        return 0;\r\n    }\r\n    puts(\"s SATISFIABLE\");\r\n    cout<<\"v \"\
    ;\r\n    auto res=ts.res;\r\n    rep(i,1,n+1){\r\n        if(res[i])cout<<i<<'\
    \ ';\r\n        else cout<<-i<<' ';\r\n    }\r\n    puts(\"0\");\r\n    return\
    \ 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/twosat.hpp
  - Graph/scc.hpp
  isVerificationFile: true
  path: Verify/LC_two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_two_sat.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_two_sat.test.cpp
- /verify/Verify/LC_two_sat.test.cpp.html
title: Verify/LC_two_sat.test.cpp
---
