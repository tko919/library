---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Hungarian algorithm
    links: []
  bundledCode: "#line 2 \"Graph/hungarian.hpp\"\n\ntemplate <typename T, T MX> vector<int>\
    \ Hungarian(int n, vector<vector<T>> &A) {\n    vector<int> u(n + 1), v(n + 1),\
    \ q(n + 1, n), way(n + 1, n);\n    for (int i = 0; i < n; ++i) {\n        q[n]\
    \ = i;\n        int j0 = n;\n        vector<T> minv(n + 1, MX);\n        vector<bool>\
    \ used(n + 1, false);\n        do {\n            used[j0] = true;\n          \
    \  int i0 = q[j0], j1 = n;\n            T delta = MX;\n            for (int j\
    \ = 0; j < n; ++j)\n                if (!used[j]) {\n                    T cur\
    \ = A[i0][j] - u[i0] - v[j];\n                    if (cur < minv[j])\n       \
    \                 minv[j] = cur, way[j] = j0;\n                    if (minv[j]\
    \ < delta)\n                        delta = minv[j], j1 = j;\n               \
    \ }\n            for (int j = 0; j <= n; ++j)\n                if (used[j])\n\
    \                    u[q[j]] += delta, v[j] -= delta;\n                else\n\
    \                    minv[j] -= delta;\n            j0 = j1;\n        } while\
    \ (q[j0] != n);\n        do {\n            int j1 = way[j0];\n            q[j0]\
    \ = q[j1];\n            j0 = j1;\n        } while (j0 != n);\n    }\n    vector<int>\
    \ p(n);\n    rep(i, 0, n) p[q[i]] = i;\n    return p;\n}\n\n/**\n * @brief Hungarian\
    \ algorithm\n */\n"
  code: "#pragma once\n\ntemplate <typename T, T MX> vector<int> Hungarian(int n,\
    \ vector<vector<T>> &A) {\n    vector<int> u(n + 1), v(n + 1), q(n + 1, n), way(n\
    \ + 1, n);\n    for (int i = 0; i < n; ++i) {\n        q[n] = i;\n        int\
    \ j0 = n;\n        vector<T> minv(n + 1, MX);\n        vector<bool> used(n + 1,\
    \ false);\n        do {\n            used[j0] = true;\n            int i0 = q[j0],\
    \ j1 = n;\n            T delta = MX;\n            for (int j = 0; j < n; ++j)\n\
    \                if (!used[j]) {\n                    T cur = A[i0][j] - u[i0]\
    \ - v[j];\n                    if (cur < minv[j])\n                        minv[j]\
    \ = cur, way[j] = j0;\n                    if (minv[j] < delta)\n            \
    \            delta = minv[j], j1 = j;\n                }\n            for (int\
    \ j = 0; j <= n; ++j)\n                if (used[j])\n                    u[q[j]]\
    \ += delta, v[j] -= delta;\n                else\n                    minv[j]\
    \ -= delta;\n            j0 = j1;\n        } while (q[j0] != n);\n        do {\n\
    \            int j1 = way[j0];\n            q[j0] = q[j1];\n            j0 = j1;\n\
    \        } while (j0 != n);\n    }\n    vector<int> p(n);\n    rep(i, 0, n) p[q[i]]\
    \ = i;\n    return p;\n}\n\n/**\n * @brief Hungarian algorithm\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/hungarian.hpp
  requiredBy: []
  timestamp: '2024-10-01 02:59:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/hungarian.hpp
layout: document
redirect_from:
- /library/Graph/hungarian.hpp
- /library/Graph/hungarian.hpp.html
title: Hungarian algorithm
---
