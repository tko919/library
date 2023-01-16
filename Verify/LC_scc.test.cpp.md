---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: Strongly Connected Components
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Verify/LC_scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Graph/scc.hpp\"\
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
    \ Connected Components\r\n */\n#line 5 \"Verify/LC_scc.test.cpp\"\n\r\nint main(){\r\
    \n    int n,m;\r\n    cin>>n>>m;\r\n    SCC scc(n);\r\n    rep(i,0,m){\r\n   \
    \     int x,y;\r\n        cin>>x>>y;\r\n        scc.add_edge(x,y);\r\n    }\r\n\
    \    scc.run();\r\n    vector g(scc.m,vector<int>());\r\n    rep(i,0,n)g[scc.id[i]].push_back(i);\r\
    \n    cout<<g.size()<<'\\n';\r\n    rep(i,0,g.size()){\r\n        cout<<g[i].size()<<'\
    \ ';\r\n        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\\\
    n':' ');\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include \"\
    Template/template.hpp\"\r\n#include \"Graph/scc.hpp\"\r\n\r\nint main(){\r\n \
    \   int n,m;\r\n    cin>>n>>m;\r\n    SCC scc(n);\r\n    rep(i,0,m){\r\n     \
    \   int x,y;\r\n        cin>>x>>y;\r\n        scc.add_edge(x,y);\r\n    }\r\n\
    \    scc.run();\r\n    vector g(scc.m,vector<int>());\r\n    rep(i,0,n)g[scc.id[i]].push_back(i);\r\
    \n    cout<<g.size()<<'\\n';\r\n    rep(i,0,g.size()){\r\n        cout<<g[i].size()<<'\
    \ ';\r\n        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\\\
    n':' ');\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/scc.hpp
  isVerificationFile: true
  path: Verify/LC_scc.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_scc.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_scc.test.cpp
- /verify/Verify/LC_scc.test.cpp.html
title: Verify/LC_scc.test.cpp
---