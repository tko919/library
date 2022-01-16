---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bipartitematching.test.cpp
    title: Verify/LC_bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bipartite Matching
    links: []
  bundledCode: "#line 2 \"Graph/bimatching.hpp\"\n\r\nclass BiMatching{\r\n    int\
    \ n,m;\r\n    vector<vector<int>> g;\r\n    bitset<501010> used;\r\n    bool dfs(int\
    \ v){\r\n        if(used[v])return false;\r\n        used[v]=1;\r\n        for(auto&\
    \ to:g[v])if(pre[to]==-1 or dfs(pre[to])){\r\n            nxt[v]=to;\r\n     \
    \       pre[to]=v;\r\n            return true;\r\n        }\r\n        return\
    \ false;\r\n    }\r\npublic:\r\n    vector<int> nxt,pre;\r\n    BiMatching(int\
    \ _n,int _m):n(_n),m(_m),g(_n),nxt(_n,-1),pre(_m,-1){}\r\n    void add_edge(int\
    \ u,int v){g[u].push_back(v);}\r\n    int run(){\r\n        int ret=0;\r\n   \
    \     for(;;){\r\n            bool upd=0;\r\n            rep(v,0,n)if(nxt[v]==-1\
    \ and dfs(v)){\r\n                upd=1;\r\n                ret++;\r\n       \
    \     }\r\n            if(upd)used=0;\r\n            else break;\r\n        }\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Bipartite Matching\r\
    \n */\n"
  code: "#pragma once\r\n\r\nclass BiMatching{\r\n    int n,m;\r\n    vector<vector<int>>\
    \ g;\r\n    bitset<501010> used;\r\n    bool dfs(int v){\r\n        if(used[v])return\
    \ false;\r\n        used[v]=1;\r\n        for(auto& to:g[v])if(pre[to]==-1 or\
    \ dfs(pre[to])){\r\n            nxt[v]=to;\r\n            pre[to]=v;\r\n     \
    \       return true;\r\n        }\r\n        return false;\r\n    }\r\npublic:\r\
    \n    vector<int> nxt,pre;\r\n    BiMatching(int _n,int _m):n(_n),m(_m),g(_n),nxt(_n,-1),pre(_m,-1){}\r\
    \n    void add_edge(int u,int v){g[u].push_back(v);}\r\n    int run(){\r\n   \
    \     int ret=0;\r\n        for(;;){\r\n            bool upd=0;\r\n          \
    \  rep(v,0,n)if(nxt[v]==-1 and dfs(v)){\r\n                upd=1;\r\n        \
    \        ret++;\r\n            }\r\n            if(upd)used=0;\r\n           \
    \ else break;\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Bipartite Matching\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bimatching.hpp
  requiredBy: []
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_bipartitematching.test.cpp
documentation_of: Graph/bimatching.hpp
layout: document
redirect_from:
- /library/Graph/bimatching.hpp
- /library/Graph/bimatching.hpp.html
title: Bipartite Matching
---
