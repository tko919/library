---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_biconnected_components.test.cpp
    title: Verify/LC_biconnected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Block Cut Tree
    links: []
  bundledCode: "#line 2 \"Graph/blockcut.hpp\"\n\nstruct BlockCut {\n    using P =\
    \ pair<int, int>;\n    int n;\n    vector<vector<int>> g;\n    vector<int> low,\
    \ ord, st, used;\n    int nxt, k;\n    vector<P> es;\n    BlockCut() {}\n    BlockCut(int\
    \ n) : n(n), g(n), low(n), ord(n), used(n), nxt(n), k(0) {}\n    void add_edge(int\
    \ u, int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\
    \    vector<vector<int>> run() {\n        rep(v, 0, n) if (!used[v]) {\n     \
    \       dfs(v, -1);\n            for (auto &x : st)\n                es.push_back({nxt,\
    \ x});\n            nxt++;\n            st.clear();\n        }\n        vector\
    \ ret(nxt, vector<int>());\n        for (auto &[u, v] : es) {\n            ret[u].push_back(v);\n\
    \            ret[v].push_back(u);\n        }\n        return ret;\n    }\n   \
    \ void dfs(int v, int p) {\n        st.push_back(v);\n        used[v] = 1;\n \
    \       low[v] = ord[v] = k++;\n        int ch = 0;\n        for (auto &to : g[v])\n\
    \            if (to != p) {\n                if (!used[to]) {\n              \
    \      ch++;\n                    int s = SZ(st);\n                    dfs(to,\
    \ v);\n                    chmin(low[v], low[to]);\n                    if ((p\
    \ == -1 and ch > 1) or\n                        (p != -1 and low[to] >= ord[v]))\
    \ {\n                        es.push_back({nxt, v});\n                       \
    \ while (SZ(st) > s) {\n                            es.push_back({nxt, st.back()});\n\
    \                            st.pop_back();\n                        }\n     \
    \                   nxt++;\n                    }\n                } else {\n\
    \                    chmin(low[v], ord[to]);\n                }\n            }\n\
    \    }\n};\n\n/**\n * @brief Block Cut Tree\n */\n"
  code: "#pragma once\n\nstruct BlockCut {\n    using P = pair<int, int>;\n    int\
    \ n;\n    vector<vector<int>> g;\n    vector<int> low, ord, st, used;\n    int\
    \ nxt, k;\n    vector<P> es;\n    BlockCut() {}\n    BlockCut(int n) : n(n), g(n),\
    \ low(n), ord(n), used(n), nxt(n), k(0) {}\n    void add_edge(int u, int v) {\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    vector<vector<int>>\
    \ run() {\n        rep(v, 0, n) if (!used[v]) {\n            dfs(v, -1);\n   \
    \         for (auto &x : st)\n                es.push_back({nxt, x});\n      \
    \      nxt++;\n            st.clear();\n        }\n        vector ret(nxt, vector<int>());\n\
    \        for (auto &[u, v] : es) {\n            ret[u].push_back(v);\n       \
    \     ret[v].push_back(u);\n        }\n        return ret;\n    }\n    void dfs(int\
    \ v, int p) {\n        st.push_back(v);\n        used[v] = 1;\n        low[v]\
    \ = ord[v] = k++;\n        int ch = 0;\n        for (auto &to : g[v])\n      \
    \      if (to != p) {\n                if (!used[to]) {\n                    ch++;\n\
    \                    int s = SZ(st);\n                    dfs(to, v);\n      \
    \              chmin(low[v], low[to]);\n                    if ((p == -1 and ch\
    \ > 1) or\n                        (p != -1 and low[to] >= ord[v])) {\n      \
    \                  es.push_back({nxt, v});\n                        while (SZ(st)\
    \ > s) {\n                            es.push_back({nxt, st.back()});\n      \
    \                      st.pop_back();\n                        }\n           \
    \             nxt++;\n                    }\n                } else {\n      \
    \              chmin(low[v], ord[to]);\n                }\n            }\n   \
    \ }\n};\n\n/**\n * @brief Block Cut Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/blockcut.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_biconnected_components.test.cpp
documentation_of: Graph/blockcut.hpp
layout: document
redirect_from:
- /library/Graph/blockcut.hpp
- /library/Graph/blockcut.hpp.html
title: Block Cut Tree
---
