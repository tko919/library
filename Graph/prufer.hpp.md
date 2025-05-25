---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Prufer Code
    links: []
  bundledCode: "#line 2 \"Graph/prufer.hpp\"\n\nnamespace Prufer {\nvector<vector<int>>\
    \ encode(vector<int> &a) {\n    int n = SZ(a) + 1;\n    assert(a.back() == n -\
    \ 1);\n    vector tree(n, vector<int>());\n    if (n == 1)\n        return tree;\n\
    \    vector<int> deg(n, 1);\n    for (auto &v : a)\n        deg[v]++;\n    int\
    \ ptr = 0, leaf = -1;\n    rep(i, 0, n - 1) {\n        if (leaf == -1) {\n   \
    \         while (deg[ptr] != 1)\n                ptr++;\n            leaf = ptr;\n\
    \        }\n        tree[a[i]].push_back(leaf);\n        tree[leaf].push_back(a[i]);\n\
    \        deg[leaf]--, deg[a[i]]--;\n        if (a[i] < ptr and deg[a[i]] == 1)\n\
    \            leaf = a[i];\n        else\n            leaf = -1;\n    }\n    return\
    \ tree;\n}\nvector<int> decode(vector<vector<int>> &tree) {\n    int n = SZ(tree);\n\
    \    vector<int> par(n);\n    auto dfs = [&](auto &dfs, int v, int p) -> void\
    \ {\n        par[v] = p;\n        for (auto &to : tree[v])\n            if (to\
    \ != p) {\n                dfs(dfs, to, v);\n            }\n    };\n    dfs(dfs,\
    \ n - 1, -1);\n    vector<int> deg(n);\n    rep(v, 0, n) deg[v] = SZ(tree[v]);\n\
    \    vector<int> ret(n - 1);\n    int ptr = 0, leaf = -1;\n    rep(i, 0, n - 1)\
    \ {\n        if (leaf == -1) {\n            while (deg[ptr] != 1)\n          \
    \      ptr++;\n            leaf = ptr;\n        }\n        ret[i] = par[leaf];\n\
    \        deg[leaf]--, deg[par[leaf]]--;\n        if (deg[par[leaf]] == 1 and par[leaf]\
    \ < ptr)\n            leaf = par[leaf];\n        else\n            leaf = -1;\n\
    \    }\n    return ret;\n}\n}; // namespace Prufer\n\n/**\n * @brief Prufer Code\n\
    \ */\n"
  code: "#pragma once\n\nnamespace Prufer {\nvector<vector<int>> encode(vector<int>\
    \ &a) {\n    int n = SZ(a) + 1;\n    assert(a.back() == n - 1);\n    vector tree(n,\
    \ vector<int>());\n    if (n == 1)\n        return tree;\n    vector<int> deg(n,\
    \ 1);\n    for (auto &v : a)\n        deg[v]++;\n    int ptr = 0, leaf = -1;\n\
    \    rep(i, 0, n - 1) {\n        if (leaf == -1) {\n            while (deg[ptr]\
    \ != 1)\n                ptr++;\n            leaf = ptr;\n        }\n        tree[a[i]].push_back(leaf);\n\
    \        tree[leaf].push_back(a[i]);\n        deg[leaf]--, deg[a[i]]--;\n    \
    \    if (a[i] < ptr and deg[a[i]] == 1)\n            leaf = a[i];\n        else\n\
    \            leaf = -1;\n    }\n    return tree;\n}\nvector<int> decode(vector<vector<int>>\
    \ &tree) {\n    int n = SZ(tree);\n    vector<int> par(n);\n    auto dfs = [&](auto\
    \ &dfs, int v, int p) -> void {\n        par[v] = p;\n        for (auto &to :\
    \ tree[v])\n            if (to != p) {\n                dfs(dfs, to, v);\n   \
    \         }\n    };\n    dfs(dfs, n - 1, -1);\n    vector<int> deg(n);\n    rep(v,\
    \ 0, n) deg[v] = SZ(tree[v]);\n    vector<int> ret(n - 1);\n    int ptr = 0, leaf\
    \ = -1;\n    rep(i, 0, n - 1) {\n        if (leaf == -1) {\n            while\
    \ (deg[ptr] != 1)\n                ptr++;\n            leaf = ptr;\n        }\n\
    \        ret[i] = par[leaf];\n        deg[leaf]--, deg[par[leaf]]--;\n       \
    \ if (deg[par[leaf]] == 1 and par[leaf] < ptr)\n            leaf = par[leaf];\n\
    \        else\n            leaf = -1;\n    }\n    return ret;\n}\n}; // namespace\
    \ Prufer\n\n/**\n * @brief Prufer Code\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/prufer.hpp
  requiredBy: []
  timestamp: '2025-05-25 16:11:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/prufer.hpp
layout: document
redirect_from:
- /library/Graph/prufer.hpp
- /library/Graph/prufer.hpp.html
title: Prufer Code
---
