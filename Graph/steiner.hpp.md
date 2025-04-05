---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Steiner Tree
    links: []
  bundledCode: "#line 2 \"Graph/steiner.hpp\"\n\r\ntemplate <typename T>\r\npair<T,\
    \ vector<int>> MinimumSteinerTree(int n, vector<tuple<int, int, T>> &es,\r\n \
    \                                       vector<int> &terminal) {\r\n    vector\
    \ g(n, vector<tuple<int, T, int>>());\r\n    rep(i, 0, SZ(es)) {\r\n        auto\
    \ [x, y, w] = es[i];\r\n        g[x].push_back({y, w, i});\r\n        g[y].push_back({x,\
    \ w, i});\r\n    }\r\n    int t = SZ(terminal);\r\n    using P = pair<ll, int>;\r\
    \n    vector dp(1 << t, vector<T>(n, numeric_limits<T>::max() / 10));\r\n    vector\
    \ pre(1 << t, vector<P>(n, {-1, -1})); // {subset,-1} or {from,eid}\r\n    rep(i,\
    \ 0, t) {\r\n        dp[1 << i][terminal[i]] = 0;\r\n    }\r\n    rep(mask, 1,\
    \ 1 << t) {\r\n        rep(v, 0, n) {\r\n            for (int sub = mask; sub;\
    \ sub = (sub - 1) & mask) {\r\n                if (chmin(dp[mask][v], dp[sub][v]\
    \ + dp[mask ^ sub][v]))\r\n                    pre[mask][v] = {sub, -1};\r\n \
    \           }\r\n        }\r\n        if (mask == ((1 << t) - 1))\r\n        \
    \    break;\r\n        priority_queue<P, vector<P>, greater<P>> pq;\r\n      \
    \  rep(v, 0, n) pq.push({dp[mask][v], v});\r\n        while (!pq.empty()) {\r\n\
    \            auto [d, v] = pq.top();\r\n            pq.pop();\r\n            if\
    \ (dp[mask][v] != d)\r\n                continue;\r\n            for (auto &[to,\
    \ cost, id] : g[v])\r\n                if (chmin(dp[mask][to], dp[mask][v] + cost))\
    \ {\r\n                    pq.push({dp[mask][to], to});\r\n                  \
    \  pre[mask][to] = {v, id};\r\n                }\r\n        }\r\n    }\r\n   \
    \ ll cost = dp[(1 << t) - 1][terminal[0]];\r\n    vector<int> ret;\r\n    {\r\n\
    \        queue<P> que;\r\n        que.push({(1 << t) - 1, terminal[0]});\r\n \
    \       while (!que.empty()) {\r\n            auto [mask, v] = que.front();\r\n\
    \            que.pop();\r\n            auto [a, b] = pre[mask][v];\r\n       \
    \     if (a == -1)\r\n                continue;\r\n            else if (b == -1)\
    \ {\r\n                que.push({a, v});\r\n                que.push({mask ^ a,\
    \ v});\r\n            } else {\r\n                que.push({mask, a});\r\n   \
    \             ret.push_back(b);\r\n            }\r\n        }\r\n    }\r\n   \
    \ return {cost, ret};\r\n}\r\n\r\n/**\r\n * @brief Steiner Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\npair<T, vector<int>> MinimumSteinerTree(int\
    \ n, vector<tuple<int, int, T>> &es,\r\n                                     \
    \   vector<int> &terminal) {\r\n    vector g(n, vector<tuple<int, T, int>>());\r\
    \n    rep(i, 0, SZ(es)) {\r\n        auto [x, y, w] = es[i];\r\n        g[x].push_back({y,\
    \ w, i});\r\n        g[y].push_back({x, w, i});\r\n    }\r\n    int t = SZ(terminal);\r\
    \n    using P = pair<ll, int>;\r\n    vector dp(1 << t, vector<T>(n, numeric_limits<T>::max()\
    \ / 10));\r\n    vector pre(1 << t, vector<P>(n, {-1, -1})); // {subset,-1} or\
    \ {from,eid}\r\n    rep(i, 0, t) {\r\n        dp[1 << i][terminal[i]] = 0;\r\n\
    \    }\r\n    rep(mask, 1, 1 << t) {\r\n        rep(v, 0, n) {\r\n           \
    \ for (int sub = mask; sub; sub = (sub - 1) & mask) {\r\n                if (chmin(dp[mask][v],\
    \ dp[sub][v] + dp[mask ^ sub][v]))\r\n                    pre[mask][v] = {sub,\
    \ -1};\r\n            }\r\n        }\r\n        if (mask == ((1 << t) - 1))\r\n\
    \            break;\r\n        priority_queue<P, vector<P>, greater<P>> pq;\r\n\
    \        rep(v, 0, n) pq.push({dp[mask][v], v});\r\n        while (!pq.empty())\
    \ {\r\n            auto [d, v] = pq.top();\r\n            pq.pop();\r\n      \
    \      if (dp[mask][v] != d)\r\n                continue;\r\n            for (auto\
    \ &[to, cost, id] : g[v])\r\n                if (chmin(dp[mask][to], dp[mask][v]\
    \ + cost)) {\r\n                    pq.push({dp[mask][to], to});\r\n         \
    \           pre[mask][to] = {v, id};\r\n                }\r\n        }\r\n   \
    \ }\r\n    ll cost = dp[(1 << t) - 1][terminal[0]];\r\n    vector<int> ret;\r\n\
    \    {\r\n        queue<P> que;\r\n        que.push({(1 << t) - 1, terminal[0]});\r\
    \n        while (!que.empty()) {\r\n            auto [mask, v] = que.front();\r\
    \n            que.pop();\r\n            auto [a, b] = pre[mask][v];\r\n      \
    \      if (a == -1)\r\n                continue;\r\n            else if (b ==\
    \ -1) {\r\n                que.push({a, v});\r\n                que.push({mask\
    \ ^ a, v});\r\n            } else {\r\n                que.push({mask, a});\r\n\
    \                ret.push_back(b);\r\n            }\r\n        }\r\n    }\r\n\
    \    return {cost, ret};\r\n}\r\n\r\n/**\r\n * @brief Steiner Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/steiner.hpp
  requiredBy: []
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/steiner.hpp
layout: document
redirect_from:
- /library/Graph/steiner.hpp
- /library/Graph/steiner.hpp.html
title: Steiner Tree
---
