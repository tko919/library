---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/kprojectselection.hpp
    title: K-Project Selection
  - icon: ':warning:'
    path: Algorithm/projectselection.hpp
    title: Project Selection
  - icon: ':x:'
    path: Graph/mincostflow.hpp
    title: Minimum Cost b-flow
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/AOJ_GRL_6_A.test.cpp
    title: Verify/AOJ_GRL_6_A.test.cpp
  - icon: ':x:'
    path: Verify/LC_min_cost_b_flow.test.cpp
    title: Verify/LC_min_cost_b_flow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Maximum Flow
    links: []
  bundledCode: "#line 2 \"Graph/maxflow.hpp\"\n\r\nstruct MaxFlow {\r\n    struct\
    \ Edge {\r\n        int to, rev;\r\n        ll cap;\r\n    };\r\n    int V;\r\n\
    \    vector<vector<Edge>> G;\r\n    vector<int> itr, level;\r\n    using P = pair<int,\
    \ int>;\r\n    vector<P> es;\r\n\r\n  public:\r\n    MaxFlow() {}\r\n    MaxFlow(int\
    \ V) : V(V) {\r\n        G.assign(V, vector<Edge>());\r\n    }\r\n    int add_vertex()\
    \ {\r\n        G.push_back(vector<Edge>());\r\n        return V++;\r\n    }\r\n\
    \    void add_edge(int from, int to, ll cap) {\r\n        int fid = SZ(G[from]),\
    \ tid = SZ(G[to]);\r\n        if (from == to)\r\n            tid++;\r\n      \
    \  es.push_back({from, fid});\r\n        G[from].push_back({to, tid, cap});\r\n\
    \        G[to].push_back({from, fid, 0});\r\n    }\r\n    struct Type {\r\n  \
    \      int from, to;\r\n        ll cap, recap;\r\n    };\r\n    Type get_edge(int\
    \ i) {\r\n        auto [from, pos] = es[i];\r\n        auto e = G[from][pos];\r\
    \n        auto re = G[e.to][e.rev];\r\n        return Type{from, e.to, e.cap,\
    \ re.cap};\r\n    }\r\n    void bfs(int s) {\r\n        level.assign(V, -1);\r\
    \n        queue<int> q;\r\n        level[s] = 0;\r\n        q.push(s);\r\n   \
    \     while (!q.empty()) {\r\n            int v = q.front();\r\n            q.pop();\r\
    \n            for (auto &e : G[v]) {\r\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\r\n                    level[e.to] = level[v] + 1;\r\n              \
    \      q.push(e.to);\r\n                }\r\n            }\r\n        }\r\n  \
    \  }\r\n    ll dfs(int v, int t, ll f) {\r\n        if (v == t)\r\n          \
    \  return f;\r\n        for (int &i = itr[v]; i < (int)G[v].size(); i++) {\r\n\
    \            Edge &e = G[v][i];\r\n            if (e.cap > 0 && level[v] < level[e.to])\
    \ {\r\n                ll d = dfs(e.to, t, min(f, e.cap));\r\n               \
    \ if (d > 0) {\r\n                    e.cap -= d, G[e.to][e.rev].cap += d;\r\n\
    \                    return d;\r\n                }\r\n            }\r\n     \
    \   }\r\n        return 0;\r\n    }\r\n    ll run(int s, int t) {\r\n        ll\
    \ ret = 0, f;\r\n        while (bfs(s), level[t] >= 0) {\r\n            itr.assign(V,\
    \ 0);\r\n            while ((f = dfs(s, t, INF)) > 0)\r\n                ret +=\
    \ f;\r\n        }\r\n        return ret;\r\n    }\r\n    vector<int> cut() {\r\
    \n        vector<int> ret(V);\r\n        rep(v, 0, V) if (level[v] < 0) ret[v]\
    \ = 1;\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Flow\r\
    \n */\n"
  code: "#pragma once\r\n\r\nstruct MaxFlow {\r\n    struct Edge {\r\n        int\
    \ to, rev;\r\n        ll cap;\r\n    };\r\n    int V;\r\n    vector<vector<Edge>>\
    \ G;\r\n    vector<int> itr, level;\r\n    using P = pair<int, int>;\r\n    vector<P>\
    \ es;\r\n\r\n  public:\r\n    MaxFlow() {}\r\n    MaxFlow(int V) : V(V) {\r\n\
    \        G.assign(V, vector<Edge>());\r\n    }\r\n    int add_vertex() {\r\n \
    \       G.push_back(vector<Edge>());\r\n        return V++;\r\n    }\r\n    void\
    \ add_edge(int from, int to, ll cap) {\r\n        int fid = SZ(G[from]), tid =\
    \ SZ(G[to]);\r\n        if (from == to)\r\n            tid++;\r\n        es.push_back({from,\
    \ fid});\r\n        G[from].push_back({to, tid, cap});\r\n        G[to].push_back({from,\
    \ fid, 0});\r\n    }\r\n    struct Type {\r\n        int from, to;\r\n       \
    \ ll cap, recap;\r\n    };\r\n    Type get_edge(int i) {\r\n        auto [from,\
    \ pos] = es[i];\r\n        auto e = G[from][pos];\r\n        auto re = G[e.to][e.rev];\r\
    \n        return Type{from, e.to, e.cap, re.cap};\r\n    }\r\n    void bfs(int\
    \ s) {\r\n        level.assign(V, -1);\r\n        queue<int> q;\r\n        level[s]\
    \ = 0;\r\n        q.push(s);\r\n        while (!q.empty()) {\r\n            int\
    \ v = q.front();\r\n            q.pop();\r\n            for (auto &e : G[v]) {\r\
    \n                if (e.cap > 0 && level[e.to] < 0) {\r\n                    level[e.to]\
    \ = level[v] + 1;\r\n                    q.push(e.to);\r\n                }\r\n\
    \            }\r\n        }\r\n    }\r\n    ll dfs(int v, int t, ll f) {\r\n \
    \       if (v == t)\r\n            return f;\r\n        for (int &i = itr[v];\
    \ i < (int)G[v].size(); i++) {\r\n            Edge &e = G[v][i];\r\n         \
    \   if (e.cap > 0 && level[v] < level[e.to]) {\r\n                ll d = dfs(e.to,\
    \ t, min(f, e.cap));\r\n                if (d > 0) {\r\n                    e.cap\
    \ -= d, G[e.to][e.rev].cap += d;\r\n                    return d;\r\n        \
    \        }\r\n            }\r\n        }\r\n        return 0;\r\n    }\r\n   \
    \ ll run(int s, int t) {\r\n        ll ret = 0, f;\r\n        while (bfs(s), level[t]\
    \ >= 0) {\r\n            itr.assign(V, 0);\r\n            while ((f = dfs(s, t,\
    \ INF)) > 0)\r\n                ret += f;\r\n        }\r\n        return ret;\r\
    \n    }\r\n    vector<int> cut() {\r\n        vector<int> ret(V);\r\n        rep(v,\
    \ 0, V) if (level[v] < 0) ret[v] = 1;\r\n        return ret;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Maximum Flow\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/maxflow.hpp
  requiredBy:
  - Graph/mincostflow.hpp
  - Algorithm/projectselection.hpp
  - Algorithm/kprojectselection.hpp
  timestamp: '2024-04-29 14:20:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_min_cost_b_flow.test.cpp
  - Verify/AOJ_GRL_6_A.test.cpp
documentation_of: Graph/maxflow.hpp
layout: document
redirect_from:
- /library/Graph/maxflow.hpp
- /library/Graph/maxflow.hpp.html
title: Maximum Flow
---
