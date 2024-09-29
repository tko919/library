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
  bundledCode: "#line 2 \"Graph/hungarian.hpp\"\n\nvector<int> hungarian(int n, const\
    \ vector<vector<ll>> &a) {\n    int p, q;\n    vector<ll> fx(n, inf), fy(n, 0);\n\
    \    vector<int> x(n, -1), y(n, -1);\n    for (int i = 0; i < n;) {\n        vector<ll>\
    \ t(n, -1), s(n + 1, i);\n        for (p = q = 0; p <= q && x[i] < 0; p++) {\n\
    \            for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {\n           \
    \     if (fx[k] + fy[j] == a[k][j] && t[j] < 0) {\n                    s[++q]\
    \ = y[j], t[j] = k;\n                    if (s[q] < 0)\n                     \
    \   for (p = j; p >= 0; j = p) {\n                            y[j] = k = t[j],\
    \ p = x[k], x[k] = j;\n                        }\n                }\n        \
    \    }\n        }\n        if (x[i] < 0) {\n            ll d = INF;\n        \
    \    rep(k, 0, q + 1) rep(j, 0, n) if (t[j] < 0)\n                chmin(d, fx[s[k]]\
    \ + fy[j] - a[s[k]][j]);\n            rep(j, 0, n) fy[j] += (t[j] < 0 ? 0 : d);\n\
    \            rep(k, 0, q + 1) fx[s[k]] -= d;\n        } else\n            i++;\n\
    \    }\n    return x;\n}\n\n/**\n * @brief Hungarian algorithm\n */\n"
  code: "#pragma once\n\nvector<int> hungarian(int n, const vector<vector<ll>> &a)\
    \ {\n    int p, q;\n    vector<ll> fx(n, inf), fy(n, 0);\n    vector<int> x(n,\
    \ -1), y(n, -1);\n    for (int i = 0; i < n;) {\n        vector<ll> t(n, -1),\
    \ s(n + 1, i);\n        for (p = q = 0; p <= q && x[i] < 0; p++) {\n         \
    \   for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {\n                if (fx[k]\
    \ + fy[j] == a[k][j] && t[j] < 0) {\n                    s[++q] = y[j], t[j] =\
    \ k;\n                    if (s[q] < 0)\n                        for (p = j; p\
    \ >= 0; j = p) {\n                            y[j] = k = t[j], p = x[k], x[k]\
    \ = j;\n                        }\n                }\n            }\n        }\n\
    \        if (x[i] < 0) {\n            ll d = INF;\n            rep(k, 0, q + 1)\
    \ rep(j, 0, n) if (t[j] < 0)\n                chmin(d, fx[s[k]] + fy[j] - a[s[k]][j]);\n\
    \            rep(j, 0, n) fy[j] += (t[j] < 0 ? 0 : d);\n            rep(k, 0,\
    \ q + 1) fx[s[k]] -= d;\n        } else\n            i++;\n    }\n    return x;\n\
    }\n\n/**\n * @brief Hungarian algorithm\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/hungarian.hpp
  requiredBy: []
  timestamp: '2024-09-30 03:29:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/hungarian.hpp
layout: document
redirect_from:
- /library/Graph/hungarian.hpp
- /library/Graph/hungarian.hpp.html
title: Hungarian algorithm
---
