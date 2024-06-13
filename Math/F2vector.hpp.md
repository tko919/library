---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: $\mathbb{F}_2$ vector
    links: []
  bundledCode: "#line 2 \"Math/F2vector.hpp\"\n\nvector<int> Intersection(vector<int>\
    \ &X, vector<int> &Y) {\n    vector<int> Xb, Yb;\n    for (auto x : X) {\n   \
    \     for (auto &b : Xb)\n            chmin(x, x ^ b);\n        if (x)\n     \
    \       Xb.push_back(x);\n    }\n    for (auto y : Y) {\n        for (auto &b\
    \ : Yb)\n            chmin(y, y ^ b);\n        if (y)\n            Yb.push_back(y);\n\
    \    }\n\n    vector<ll> A(SZ(Xb) + SZ(Yb));\n    rep(i, 0, SZ(Xb)) A[i] = ll(Xb[i])\
    \ << 30 | Xb[i];\n    rep(i, 0, SZ(Yb)) A[SZ(Xb) + i] = ll(Yb[i]);\n    int rank\
    \ = 0;\n    rep(k, 0, 30) {\n        if (rank == SZ(A))\n            break;\n\
    \        rep(i, rank, SZ(A)) {\n            if (A[i] >> k & 1) {\n           \
    \     swap(A[rank], A[i]);\n                break;\n            }\n        }\n\
    \        if (!(A[rank] >> k & 1))\n            continue;\n        rep(j, 0, SZ(A))\
    \ if (j != rank) {\n            if (A[j] >> k & 1)\n                A[j] ^= A[rank];\n\
    \        }\n        rank++;\n    }\n    vector<int> ret;\n    rep(i, rank, SZ(A))\
    \ {\n        int add = A[i] >> 30;\n        if (add)\n            ret.push_back(add);\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T> vector<T> inverse(vector<T>\
    \ &a) {\n    int n = SZ(a);\n    vector<T> b(n);\n    rep(i, 0, n) b[i][i] = 1;\n\
    \n    rep(i, 0, n) {\n        rep(k, i + 1, n) if (a[k][i]) {\n            swap(a[k],\
    \ a[i]);\n            swap(b[k], b[i]);\n        }\n        if (!a[i][i]) {\n\
    \            print(-1);\n            return 0;\n        }\n        rep(k, 0, n)\
    \ if (k != i and a[k][i]) {\n            a[k] ^= a[i];\n            b[k] ^= b[i];\n\
    \        }\n    }\n    return b;\n}\n\n/**\n * @brief $\\mathbb{F}_2$ vector\n\
    \ */\n"
  code: "#pragma once\n\nvector<int> Intersection(vector<int> &X, vector<int> &Y)\
    \ {\n    vector<int> Xb, Yb;\n    for (auto x : X) {\n        for (auto &b : Xb)\n\
    \            chmin(x, x ^ b);\n        if (x)\n            Xb.push_back(x);\n\
    \    }\n    for (auto y : Y) {\n        for (auto &b : Yb)\n            chmin(y,\
    \ y ^ b);\n        if (y)\n            Yb.push_back(y);\n    }\n\n    vector<ll>\
    \ A(SZ(Xb) + SZ(Yb));\n    rep(i, 0, SZ(Xb)) A[i] = ll(Xb[i]) << 30 | Xb[i];\n\
    \    rep(i, 0, SZ(Yb)) A[SZ(Xb) + i] = ll(Yb[i]);\n    int rank = 0;\n    rep(k,\
    \ 0, 30) {\n        if (rank == SZ(A))\n            break;\n        rep(i, rank,\
    \ SZ(A)) {\n            if (A[i] >> k & 1) {\n                swap(A[rank], A[i]);\n\
    \                break;\n            }\n        }\n        if (!(A[rank] >> k\
    \ & 1))\n            continue;\n        rep(j, 0, SZ(A)) if (j != rank) {\n  \
    \          if (A[j] >> k & 1)\n                A[j] ^= A[rank];\n        }\n \
    \       rank++;\n    }\n    vector<int> ret;\n    rep(i, rank, SZ(A)) {\n    \
    \    int add = A[i] >> 30;\n        if (add)\n            ret.push_back(add);\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T> vector<T> inverse(vector<T>\
    \ &a) {\n    int n = SZ(a);\n    vector<T> b(n);\n    rep(i, 0, n) b[i][i] = 1;\n\
    \n    rep(i, 0, n) {\n        rep(k, i + 1, n) if (a[k][i]) {\n            swap(a[k],\
    \ a[i]);\n            swap(b[k], b[i]);\n        }\n        if (!a[i][i]) {\n\
    \            print(-1);\n            return 0;\n        }\n        rep(k, 0, n)\
    \ if (k != i and a[k][i]) {\n            a[k] ^= a[i];\n            b[k] ^= b[i];\n\
    \        }\n    }\n    return b;\n}\n\n/**\n * @brief $\\mathbb{F}_2$ vector\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Math/F2vector.hpp
  requiredBy: []
  timestamp: '2024-06-14 02:46:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/F2vector.hpp
layout: document
redirect_from:
- /library/Math/F2vector.hpp
- /library/Math/F2vector.hpp.html
title: $\mathbb{F}_2$ vector
---
