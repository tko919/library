---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Diameter
    links: []
  bundledCode: "#line 2 \"Graph/diameter.hpp\"\n\npair<ll, vector<int>> Diameter(vector<vector<pair<int,\
    \ ll>>> &g) {\n    int n = SZ(g);\n    vector<ll> dist(n, INF);\n    queue<int>\
    \ que;\n    dist[0] = 0;\n    que.push(0);\n    while (!que.empty()) {\n     \
    \   int v = que.front();\n        que.pop();\n        for (auto &[to, c] : g[v])\n\
    \            if (dist[to] == INF) {\n                dist[to] = dist[v] + c;\n\
    \                que.push(to);\n            }\n    }\n    int v1 = -1;\n    {\n\
    \        ll mx = -INF;\n        rep(v, 0, n) if (chmax(mx, dist[v])) v1 = v;\n\
    \    }\n    dist.assign(n, INF);\n    dist[v1] = 0;\n    que.push(v1);\n    vector<int>\
    \ par(n);\n    par[v1] = -1;\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (auto &[to, c] : g[v])\n            if (dist[to]\
    \ == INF) {\n                dist[to] = dist[v] + c;\n                par[to]\
    \ = v;\n                que.push(to);\n            }\n    }\n    int v2 = -1;\n\
    \    ll diam = -INF;\n    rep(v, 0, n) if (chmax(diam, dist[v])) v2 = v;\n   \
    \ vector<int> path;\n    int cur = v2;\n    path.push_back(cur);\n    while (cur\
    \ != v1) {\n        cur = par[cur];\n        path.push_back(cur);\n    }\n   \
    \ return {diam, path};\n}\n\npair<ll, vector<int>> Diameter(vector<vector<int>>\
    \ &g) {\n    int n = SZ(g);\n    vector<vector<pair<int, ll>>> g2(n);\n    rep(v,\
    \ 0, n) for (auto &u : g[v]) g2[v].push_back({u, 1});\n    return Diameter(g2);\n\
    }\n\n/**\n * @brief Diameter\n */\n"
  code: "#pragma once\n\npair<ll, vector<int>> Diameter(vector<vector<pair<int, ll>>>\
    \ &g) {\n    int n = SZ(g);\n    vector<ll> dist(n, INF);\n    queue<int> que;\n\
    \    dist[0] = 0;\n    que.push(0);\n    while (!que.empty()) {\n        int v\
    \ = que.front();\n        que.pop();\n        for (auto &[to, c] : g[v])\n   \
    \         if (dist[to] == INF) {\n                dist[to] = dist[v] + c;\n  \
    \              que.push(to);\n            }\n    }\n    int v1 = -1;\n    {\n\
    \        ll mx = -INF;\n        rep(v, 0, n) if (chmax(mx, dist[v])) v1 = v;\n\
    \    }\n    dist.assign(n, INF);\n    dist[v1] = 0;\n    que.push(v1);\n    vector<int>\
    \ par(n);\n    par[v1] = -1;\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (auto &[to, c] : g[v])\n            if (dist[to]\
    \ == INF) {\n                dist[to] = dist[v] + c;\n                par[to]\
    \ = v;\n                que.push(to);\n            }\n    }\n    int v2 = -1;\n\
    \    ll diam = -INF;\n    rep(v, 0, n) if (chmax(diam, dist[v])) v2 = v;\n   \
    \ vector<int> path;\n    int cur = v2;\n    path.push_back(cur);\n    while (cur\
    \ != v1) {\n        cur = par[cur];\n        path.push_back(cur);\n    }\n   \
    \ return {diam, path};\n}\n\npair<ll, vector<int>> Diameter(vector<vector<int>>\
    \ &g) {\n    int n = SZ(g);\n    vector<vector<pair<int, ll>>> g2(n);\n    rep(v,\
    \ 0, n) for (auto &u : g[v]) g2[v].push_back({u, 1});\n    return Diameter(g2);\n\
    }\n\n/**\n * @brief Diameter\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/diameter.hpp
  requiredBy: []
  timestamp: '2025-05-25 16:11:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/diameter.hpp
layout: document
redirect_from:
- /library/Graph/diameter.hpp
- /library/Graph/diameter.hpp.html
title: Diameter
---
