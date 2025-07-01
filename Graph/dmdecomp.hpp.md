---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/bimatching.hpp
    title: Bipartite Matching
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: Strongly Connected Components
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/matroid.hpp
    title: Matroid
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: DM decomposition
    links: []
  bundledCode: "#line 2 \"Graph/bimatching.hpp\"\n\r\nvector<int> BiMatching(int n,\
    \ int m, vector<vector<int>> &g) {\r\n    vector<int> L(n, -1), R(m, -1), d(n);\r\
    \n    auto dfs = [&](auto &dfs, int v) -> bool {\r\n        int nd = exchange(d[v],\
    \ 0) + 1;\r\n        for (auto &u : g[v]) {\r\n            if (R[u] == -1 or (d[R[u]]\
    \ == nd and dfs(dfs, R[u]))) {\r\n                L[v] = u, R[u] = v;\r\n    \
    \            return 1;\r\n            }\r\n        }\r\n        return 0;\r\n\
    \    };\r\n    for (;;) {\r\n        d.assign(n, 0);\r\n        queue<int> que;\r\
    \n        bool ch = 0;\r\n        rep(i, 0, n) if (L[i] == -1) {\r\n         \
    \   que.push(i);\r\n            d[i] = 1;\r\n        }\r\n        while (!que.empty())\
    \ {\r\n            int v = que.front();\r\n            que.pop();\r\n        \
    \    for (auto &u : g[v]) {\r\n                if (R[u] == -1)\r\n           \
    \         ch = 1;\r\n                else if (!d[R[u]]) {\r\n                \
    \    d[R[u]] = d[v] + 1;\r\n                    que.push(R[u]);\r\n          \
    \      }\r\n            }\r\n        }\r\n        if (!ch)\r\n            break;\r\
    \n        rep(i, 0, n) if (L[i] == -1) dfs(dfs, i);\r\n    }\r\n    return L;\r\
    \n}\r\n\r\n/**\r\n * @brief Bipartite Matching\r\n */\n#line 2 \"Graph/scc.hpp\"\
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
    \ Connected Components\r\n */\n#line 4 \"Graph/dmdecomp.hpp\"\n\nvector<vector<int>>\
    \ DMdecomposition(int n, int m, vector<vector<int>> &g,\n                    \
    \                vector<int> match) {\n    if (match.empty())\n        match =\
    \ BiMatching(n, m, g);\n    vector G(n + m, vector<int>()), REV(n + m, vector<int>());\n\
    \    rep(i, 0, n) for (auto &j : g[i]) {\n        G[i].push_back(j + n);\n   \
    \     REV[j + n].push_back(i);\n    }\n    vector<int> R(m, -1);\n    rep(i, 0,\
    \ n) if (match[i] != -1) {\n        G[match[i] + n].push_back(i);\n        REV[i].push_back(match[i]\
    \ + n);\n        R[match[i]] = i;\n    }\n\n    vector<int> V0, Vinf;\n    queue<int>\
    \ que;\n    vector<int> used(n + m);\n    rep(i, 0, n) if (match[i] == -1) {\n\
    \        used[i] = 1;\n        que.push(i);\n    }\n    while (!que.empty()) {\n\
    \        int v = que.front();\n        que.pop();\n        Vinf.push_back(v);\n\
    \        for (auto &to : G[v])\n            if (!used[to]) {\n               \
    \ used[to] = 1;\n                que.push(to);\n            }\n    }\n    rep(i,\
    \ 0, m) if (R[i] == -1) {\n        used[i + n] = 1;\n        que.push(i + n);\n\
    \    }\n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        V0.push_back(v);\n        for (auto &to : REV[v])\n            if (!used[to])\
    \ {\n                used[to] = 1;\n                que.push(to);\n          \
    \  }\n    }\n\n    SCC scc(n + m);\n    rep(i, 0, n + m) for (auto &to : G[i])\
    \ {\n        if (!used[i] and !used[to])\n            scc.add_edge(i, to);\n \
    \   }\n    scc.run();\n    vector group(scc.m, vector<int>());\n    rep(i, 0,\
    \ n + m) if (!used[i]) group[scc.id[i]].push_back(i);\n\n    vector<vector<int>>\
    \ ret;\n    ret.push_back(V0);\n    for (auto &v : group)\n        ret.push_back(v);\n\
    \    ret.push_back(Vinf);\n    return ret;\n}\n\n/**\n * @brief DM decomposition\n\
    \ */\n"
  code: "#pragma once\n#include \"Graph/bimatching.hpp\"\n#include \"Graph/scc.hpp\"\
    \n\nvector<vector<int>> DMdecomposition(int n, int m, vector<vector<int>> &g,\n\
    \                                    vector<int> match) {\n    if (match.empty())\n\
    \        match = BiMatching(n, m, g);\n    vector G(n + m, vector<int>()), REV(n\
    \ + m, vector<int>());\n    rep(i, 0, n) for (auto &j : g[i]) {\n        G[i].push_back(j\
    \ + n);\n        REV[j + n].push_back(i);\n    }\n    vector<int> R(m, -1);\n\
    \    rep(i, 0, n) if (match[i] != -1) {\n        G[match[i] + n].push_back(i);\n\
    \        REV[i].push_back(match[i] + n);\n        R[match[i]] = i;\n    }\n\n\
    \    vector<int> V0, Vinf;\n    queue<int> que;\n    vector<int> used(n + m);\n\
    \    rep(i, 0, n) if (match[i] == -1) {\n        used[i] = 1;\n        que.push(i);\n\
    \    }\n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        Vinf.push_back(v);\n        for (auto &to : G[v])\n            if (!used[to])\
    \ {\n                used[to] = 1;\n                que.push(to);\n          \
    \  }\n    }\n    rep(i, 0, m) if (R[i] == -1) {\n        used[i + n] = 1;\n  \
    \      que.push(i + n);\n    }\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        V0.push_back(v);\n        for (auto &to : REV[v])\n\
    \            if (!used[to]) {\n                used[to] = 1;\n               \
    \ que.push(to);\n            }\n    }\n\n    SCC scc(n + m);\n    rep(i, 0, n\
    \ + m) for (auto &to : G[i]) {\n        if (!used[i] and !used[to])\n        \
    \    scc.add_edge(i, to);\n    }\n    scc.run();\n    vector group(scc.m, vector<int>());\n\
    \    rep(i, 0, n + m) if (!used[i]) group[scc.id[i]].push_back(i);\n\n    vector<vector<int>>\
    \ ret;\n    ret.push_back(V0);\n    for (auto &v : group)\n        ret.push_back(v);\n\
    \    ret.push_back(Vinf);\n    return ret;\n}\n\n/**\n * @brief DM decomposition\n\
    \ */"
  dependsOn:
  - Graph/bimatching.hpp
  - Graph/scc.hpp
  isVerificationFile: false
  path: Graph/dmdecomp.hpp
  requiredBy:
  - Algorithm/matroid.hpp
  timestamp: '2024-09-30 03:29:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dmdecomp.hpp
layout: document
redirect_from:
- /library/Graph/dmdecomp.hpp
- /library/Graph/dmdecomp.hpp.html
title: DM decomposition
---
