---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate Triangle
    links: []
  bundledCode: "#line 2 \"Graph/enumtriangle.hpp\"\n\n// query(u,v,w,i,j,k): vertex\
    \ {u,v,w}, edge {i,j,k}\ntemplate <typename F>\nvoid EnumTriangle(int n, vector<pair<int,\
    \ int>> &es, F query) {\n    using P = pair<int, int>;\n    vector<int> deg(n);\n\
    \    for (auto &[x, y] : es)\n        deg[x]++, deg[y]++;\n    vector H(n, vector<P>());\n\
    \    rep(i, 0, SZ(es)) {\n        auto [x, y] = es[i];\n        if (P{deg[x],\
    \ x} < P{deg[y], y})\n            H[x].push_back({y, i});\n        else\n    \
    \        H[y].push_back({x, i});\n    }\n    vector<int> used(n, -1);\n    rep(u,\
    \ 0, n) {\n        for (auto &[v, i] : H[u])\n            used[v] = i;\n     \
    \   for (auto &[v, j] : H[u]) {\n            for (auto &[w, k] : H[v])\n     \
    \           if (used[w] != -1) {\n                    query(u, v, w, used[w],\
    \ j, k);\n                }\n        }\n        for (auto &[v, i] : H[u])\n  \
    \          used[v] = -1;\n    }\n}\n\n/**\n * @brief Enumerate Triangle\n */\n"
  code: "#pragma once\n\n// query(u,v,w,i,j,k): vertex {u,v,w}, edge {i,j,k}\ntemplate\
    \ <typename F>\nvoid EnumTriangle(int n, vector<pair<int, int>> &es, F query)\
    \ {\n    using P = pair<int, int>;\n    vector<int> deg(n);\n    for (auto &[x,\
    \ y] : es)\n        deg[x]++, deg[y]++;\n    vector H(n, vector<P>());\n    rep(i,\
    \ 0, SZ(es)) {\n        auto [x, y] = es[i];\n        if (P{deg[x], x} < P{deg[y],\
    \ y})\n            H[x].push_back({y, i});\n        else\n            H[y].push_back({x,\
    \ i});\n    }\n    vector<int> used(n, -1);\n    rep(u, 0, n) {\n        for (auto\
    \ &[v, i] : H[u])\n            used[v] = i;\n        for (auto &[v, j] : H[u])\
    \ {\n            for (auto &[w, k] : H[v])\n                if (used[w] != -1)\
    \ {\n                    query(u, v, w, used[w], j, k);\n                }\n \
    \       }\n        for (auto &[v, i] : H[u])\n            used[v] = -1;\n    }\n\
    }\n\n/**\n * @brief Enumerate Triangle\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/enumtriangle.hpp
  requiredBy: []
  timestamp: '2024-12-12 04:29:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/enumtriangle.hpp
layout: document
redirect_from:
- /library/Graph/enumtriangle.hpp
- /library/Graph/enumtriangle.hpp.html
title: Enumerate Triangle
---
