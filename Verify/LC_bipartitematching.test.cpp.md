---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/bimatching.hpp
    title: Bipartite Matching
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"Verify/LC_bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Graph/bimatching.hpp\"\n\r\nclass BiMatching{\r\n    vector<vector<int>>\
    \ g;\r\n    bitset<501010> used;\r\n    int n,m;\r\n    bool dfs(int v){\r\n \
    \       if(used[v])return false;\r\n        used[v]=1;\r\n        for(auto& to:g[v])if(pre[to]==-1\
    \ or dfs(pre[to])){\r\n            nxt[v]=to;\r\n            pre[to]=v;\r\n  \
    \          return true;\r\n        }\r\n        return false;\r\n    }\r\npublic:\r\
    \n    vector<int> nxt,pre;\r\n    BiMatching(int _n,int _m):n(_n),m(_m),g(_n),nxt(_n,-1),pre(_m,-1){}\r\
    \n    void add_edge(int u,int v){g[u].push_back(v);}\r\n    int run(){\r\n   \
    \     int ret=0;\r\n        for(;;){\r\n            bool upd=0;\r\n          \
    \  rep(v,0,n)if(nxt[v]==-1 and dfs(v)){\r\n                upd=1;\r\n        \
    \        ret++;\r\n            }\r\n            if(upd)used=0;\r\n           \
    \ else break;\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Bipartite Matching\r\n */\n#line 5 \"Verify/LC_bipartitematching.test.cpp\"\
    \n\r\nint main(){\r\n    int L,R,m;\r\n    cin>>L>>R>>m;\r\n    BiMatching buf(L,R);\r\
    \n    rep(_,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        buf.add_edge(x,y);\r\
    \n    }\r\n    int ret=buf.run();\r\n    \r\n    cout<<ret<<'\\n';\r\n    rep(i,0,L)if(buf.nxt[i]!=-1){\r\
    \n        cout<<i<<' '<<buf.nxt[i]<<'\\n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\r\n\
    \r\n#include \"Template/template.hpp\"\r\n#include \"Graph/bimatching.hpp\"\r\n\
    \r\nint main(){\r\n    int L,R,m;\r\n    cin>>L>>R>>m;\r\n    BiMatching buf(L,R);\r\
    \n    rep(_,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        buf.add_edge(x,y);\r\
    \n    }\r\n    int ret=buf.run();\r\n    \r\n    cout<<ret<<'\\n';\r\n    rep(i,0,L)if(buf.nxt[i]!=-1){\r\
    \n        cout<<i<<' '<<buf.nxt[i]<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/bimatching.hpp
  isVerificationFile: true
  path: Verify/LC_bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 15:37:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_bipartitematching.test.cpp
- /verify/Verify/LC_bipartitematching.test.cpp.html
title: Verify/LC_bipartitematching.test.cpp
---
