---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_cycle_detection.test.cpp
    title: Verify/LC_cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_cycle_detection_undirected.test.cpp
    title: Verify/LC_cycle_detection_undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Cycle Detection
    links: []
  bundledCode: "#line 2 \"Graph/cycledetect.hpp\"\n\ntemplate<bool directed>struct\
    \ CycleDetect{\n    using P=pair<int,int>;\n    int n,m;\n    vector<vector<P>>\
    \ g;\n    vector<P> cycle;\n    CycleDetect(){}\n    CycleDetect(int _n):n(_n),m(0),g(n),used(n){}\n\
    \    void add_edge(int u,int v){\n        g[u].push_back({v,m});\n        if(!directed)g[v].push_back({u,m});\n\
    \        m++;\n    }\n    void run(){\n        rep(i,0,n)if(dfs(i,-1)==-2){\n\
    \            reverse(ALL(cycle));\n            break;\n        }\n    }\nprivate:\n\
    \    vector<int> used; // 0:not,1:seen,2:visited\n    int dfs(int v,int pid){\
    \ // -1:over,-2:done\n        if(used[v]==1)return v;\n        if(used[v]==2)return\
    \ -1;\n        used[v]=1;\n        for(auto& [to,id]:g[v])if(id!=pid){\n     \
    \       int nxt=dfs(to,id);\n            if(nxt!=-1){\n                if(nxt==-2)return\
    \ -2;\n                cycle.push_back({to,id});\n                if(nxt==v)return\
    \ -2;\n                return nxt;\n            }\n        }\n        used[v]=2;\n\
    \        return -1;\n    }\n};\n\n/**\n * @brief Cycle Detection\n*/\n"
  code: "#pragma once\n\ntemplate<bool directed>struct CycleDetect{\n    using P=pair<int,int>;\n\
    \    int n,m;\n    vector<vector<P>> g;\n    vector<P> cycle;\n    CycleDetect(){}\n\
    \    CycleDetect(int _n):n(_n),m(0),g(n),used(n){}\n    void add_edge(int u,int\
    \ v){\n        g[u].push_back({v,m});\n        if(!directed)g[v].push_back({u,m});\n\
    \        m++;\n    }\n    void run(){\n        rep(i,0,n)if(dfs(i,-1)==-2){\n\
    \            reverse(ALL(cycle));\n            break;\n        }\n    }\nprivate:\n\
    \    vector<int> used; // 0:not,1:seen,2:visited\n    int dfs(int v,int pid){\
    \ // -1:over,-2:done\n        if(used[v]==1)return v;\n        if(used[v]==2)return\
    \ -1;\n        used[v]=1;\n        for(auto& [to,id]:g[v])if(id!=pid){\n     \
    \       int nxt=dfs(to,id);\n            if(nxt!=-1){\n                if(nxt==-2)return\
    \ -2;\n                cycle.push_back({to,id});\n                if(nxt==v)return\
    \ -2;\n                return nxt;\n            }\n        }\n        used[v]=2;\n\
    \        return -1;\n    }\n};\n\n/**\n * @brief Cycle Detection\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/cycledetect.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_cycle_detection_undirected.test.cpp
  - Verify/LC_cycle_detection.test.cpp
documentation_of: Graph/cycledetect.hpp
layout: document
redirect_from:
- /library/Graph/cycledetect.hpp
- /library/Graph/cycledetect.hpp.html
title: Cycle Detection
---
