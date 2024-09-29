---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: General Matching
    links: []
  bundledCode: "#line 2 \"Graph/general.hpp\"\n\nvector<pair<int, int>> GeneralMatch(int\
    \ n, vector<pair<int, int>> &es) {\n    mt19937 rnd;\n    vector<vector<int>>\
    \ g(n + 1);\n    for (auto &[u, v] : es) {\n        g[u + 1].push_back(v + 1);\n\
    \        g[v + 1].push_back(u + 1);\n    }\n    vector<int> used(n + 1), mate(n\
    \ + 1);\n    int T;\n    auto dfs = [&](auto &dfs, int v) -> bool {\n        used[v]\
    \ = T;\n        shuffle(ALL(g[v]), rnd);\n        for (auto &u : g[v]) {\n   \
    \         int w = mate[u];\n            if (used[w] < T) {\n                mate[v]\
    \ = u, mate[u] = v, mate[w] = 0;\n                if (!w or dfs(dfs, w))\n   \
    \                 return 1;\n                mate[u] = w, mate[w] = u, mate[v]\
    \ = 0;\n            }\n        }\n        return 0;\n    };\n    rep(_, 0, 10)\
    \ {\n        used.assign(n + 1, 0);\n        rep(v, 1, n + 1) if (!mate[v]) {\n\
    \            T++;\n            dfs(dfs, v);\n        }\n    }\n    vector<pair<int,\
    \ int>> ret;\n    rep(v, 1, n + 1) if (v < mate[v]) ret.push_back({v - 1, mate[v]\
    \ - 1});\n    return ret;\n}\n\n/**\n * @brief General Matching\n */\n"
  code: "#pragma once\n\nvector<pair<int, int>> GeneralMatch(int n, vector<pair<int,\
    \ int>> &es) {\n    mt19937 rnd;\n    vector<vector<int>> g(n + 1);\n    for (auto\
    \ &[u, v] : es) {\n        g[u + 1].push_back(v + 1);\n        g[v + 1].push_back(u\
    \ + 1);\n    }\n    vector<int> used(n + 1), mate(n + 1);\n    int T;\n    auto\
    \ dfs = [&](auto &dfs, int v) -> bool {\n        used[v] = T;\n        shuffle(ALL(g[v]),\
    \ rnd);\n        for (auto &u : g[v]) {\n            int w = mate[u];\n      \
    \      if (used[w] < T) {\n                mate[v] = u, mate[u] = v, mate[w] =\
    \ 0;\n                if (!w or dfs(dfs, w))\n                    return 1;\n\
    \                mate[u] = w, mate[w] = u, mate[v] = 0;\n            }\n     \
    \   }\n        return 0;\n    };\n    rep(_, 0, 10) {\n        used.assign(n +\
    \ 1, 0);\n        rep(v, 1, n + 1) if (!mate[v]) {\n            T++;\n       \
    \     dfs(dfs, v);\n        }\n    }\n    vector<pair<int, int>> ret;\n    rep(v,\
    \ 1, n + 1) if (v < mate[v]) ret.push_back({v - 1, mate[v] - 1});\n    return\
    \ ret;\n}\n\n/**\n * @brief General Matching\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/general.hpp
  requiredBy: []
  timestamp: '2024-09-30 03:29:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/general.hpp
layout: document
redirect_from:
- /library/Graph/general.hpp
- /library/Graph/general.hpp.html
title: General Matching
---
