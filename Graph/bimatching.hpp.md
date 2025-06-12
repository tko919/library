---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/matroid.hpp
    title: Matroid
  - icon: ':warning:'
    path: Graph/dmdecomp.hpp
    title: DM decomposition
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
    \n}\r\n\r\n/**\r\n * @brief Bipartite Matching\r\n */\n"
  code: "#pragma once\r\n\r\nvector<int> BiMatching(int n, int m, vector<vector<int>>\
    \ &g) {\r\n    vector<int> L(n, -1), R(m, -1), d(n);\r\n    auto dfs = [&](auto\
    \ &dfs, int v) -> bool {\r\n        int nd = exchange(d[v], 0) + 1;\r\n      \
    \  for (auto &u : g[v]) {\r\n            if (R[u] == -1 or (d[R[u]] == nd and\
    \ dfs(dfs, R[u]))) {\r\n                L[v] = u, R[u] = v;\r\n              \
    \  return 1;\r\n            }\r\n        }\r\n        return 0;\r\n    };\r\n\
    \    for (;;) {\r\n        d.assign(n, 0);\r\n        queue<int> que;\r\n    \
    \    bool ch = 0;\r\n        rep(i, 0, n) if (L[i] == -1) {\r\n            que.push(i);\r\
    \n            d[i] = 1;\r\n        }\r\n        while (!que.empty()) {\r\n   \
    \         int v = que.front();\r\n            que.pop();\r\n            for (auto\
    \ &u : g[v]) {\r\n                if (R[u] == -1)\r\n                    ch =\
    \ 1;\r\n                else if (!d[R[u]]) {\r\n                    d[R[u]] =\
    \ d[v] + 1;\r\n                    que.push(R[u]);\r\n                }\r\n  \
    \          }\r\n        }\r\n        if (!ch)\r\n            break;\r\n      \
    \  rep(i, 0, n) if (L[i] == -1) dfs(dfs, i);\r\n    }\r\n    return L;\r\n}\r\n\
    \r\n/**\r\n * @brief Bipartite Matching\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bimatching.hpp
  requiredBy:
  - Algorithm/matroid.hpp
  - Graph/dmdecomp.hpp
  timestamp: '2024-09-30 03:29:42+09:00'
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
