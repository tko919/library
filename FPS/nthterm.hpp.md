---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Bostan-Mori Algorithm
    links: []
  bundledCode: "#line 2 \"FPS/nthterm.hpp\"\n\r\ntemplate <typename T> T nth(Poly<T>\
    \ p, Poly<T> q, ll n) {\r\n    while (n) {\r\n        Poly<T> base(q), np, nq;\r\
    \n        for (int i = 1; i < (int)q.size(); i += 2)\r\n            base[i] =\
    \ -base[i];\r\n        p *= base;\r\n        q *= base;\r\n        for (int i\
    \ = n & 1; i < (int)p.size(); i += 2)\r\n            np.emplace_back(p[i]);\r\n\
    \        for (int i = 0; i < (int)q.size(); i += 2)\r\n            nq.emplace_back(q[i]);\r\
    \n        swap(p, np);\r\n        swap(q, nq);\r\n        n >>= 1;\r\n    }\r\n\
    \    return p[0] / q[0];\r\n}\r\n\r\ntemplate <typename T> T nthWithNTT(Poly<T>\
    \ p, Poly<T> q, ll n) {\r\n    assert(!p.empty() and !q.empty() and q[0] != T(0));\r\
    \n    if (n == 0)\r\n        return p[0] / q[0];\r\n\r\n    int m = 1;\r\n   \
    \ while (m < (int)max(p.size(), q.size()))\r\n        m <<= 1;\r\n\r\n    static\
    \ NTT<T> trans;\r\n    assert(2LL * m <= (1LL << NTT<T>::rank2));\r\n\r\n    p.resize(m);\r\
    \n    q.resize(m);\r\n    trans.ntt(p);\r\n    trans.ntt(q);\r\n\r\n    // In\
    \ this NTT's (bit-reversed) order, index i represents evaluation at\r\n    //\
    \ root[log2(2m)]^bit_reverse(i).  These factors are needed when taking\r\n   \
    \ // the odd coefficients of p(x)q(-x).\r\n    const int h = __builtin_ctzll((unsigned\
    \ int)m);\r\n    vector<int> rev(m);\r\n    for (int i = 1; i < m; i++)\r\n  \
    \      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h - 1));\r\n\r\n    vector<T>\
    \ inv_alpha(m);\r\n    T pw = 1, izeta = trans.iroot[h + 1];\r\n    for (int i\
    \ = 0; i < m; i++) {\r\n        inv_alpha[rev[i]] = pw;\r\n        pw *= izeta;\r\
    \n    }\r\n\r\n    const T inv2 = T(2).inv();\r\n    while (n) {\r\n        trans.doubling(p);\r\
    \n        trans.doubling(q);\r\n\r\n        Poly<T> np(m), nq(m);\r\n        for\
    \ (int i = 0; i < m; i++) {\r\n            T a = p[2 * i] * q[2 * i + 1];\r\n\
    \            T b = p[2 * i + 1] * q[2 * i];\r\n            if (n & 1)\r\n    \
    \            np[i] = (a - b) * inv2 * inv_alpha[i];\r\n            else\r\n  \
    \              np[i] = (a + b) * inv2;\r\n            nq[i] = q[2 * i] * q[2 *\
    \ i + 1];\r\n        }\r\n        p.swap(np);\r\n        q.swap(nq);\r\n     \
    \   n >>= 1;\r\n    }\r\n\r\n    // The constant coefficient is the average of\
    \ all transformed values;\r\n    // the common factor 1/m cancels in the quotient.\r\
    \n    T ps = 0, qs = 0;\r\n    for (int i = 0; i < m; i++) {\r\n        ps +=\
    \ p[i];\r\n        qs += q[i];\r\n    }\r\n    return ps / qs;\r\n}\r\n\r\n/**\r\
    \n * @brief Bostan-Mori Algorithm\r\n */\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> T nth(Poly<T> p, Poly<T> q, ll\
    \ n) {\r\n    while (n) {\r\n        Poly<T> base(q), np, nq;\r\n        for (int\
    \ i = 1; i < (int)q.size(); i += 2)\r\n            base[i] = -base[i];\r\n   \
    \     p *= base;\r\n        q *= base;\r\n        for (int i = n & 1; i < (int)p.size();\
    \ i += 2)\r\n            np.emplace_back(p[i]);\r\n        for (int i = 0; i <\
    \ (int)q.size(); i += 2)\r\n            nq.emplace_back(q[i]);\r\n        swap(p,\
    \ np);\r\n        swap(q, nq);\r\n        n >>= 1;\r\n    }\r\n    return p[0]\
    \ / q[0];\r\n}\r\n\r\ntemplate <typename T> T nthWithNTT(Poly<T> p, Poly<T> q,\
    \ ll n) {\r\n    assert(!p.empty() and !q.empty() and q[0] != T(0));\r\n    if\
    \ (n == 0)\r\n        return p[0] / q[0];\r\n\r\n    int m = 1;\r\n    while (m\
    \ < (int)max(p.size(), q.size()))\r\n        m <<= 1;\r\n\r\n    static NTT<T>\
    \ trans;\r\n    assert(2LL * m <= (1LL << NTT<T>::rank2));\r\n\r\n    p.resize(m);\r\
    \n    q.resize(m);\r\n    trans.ntt(p);\r\n    trans.ntt(q);\r\n\r\n    // In\
    \ this NTT's (bit-reversed) order, index i represents evaluation at\r\n    //\
    \ root[log2(2m)]^bit_reverse(i).  These factors are needed when taking\r\n   \
    \ // the odd coefficients of p(x)q(-x).\r\n    const int h = __builtin_ctzll((unsigned\
    \ int)m);\r\n    vector<int> rev(m);\r\n    for (int i = 1; i < m; i++)\r\n  \
    \      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h - 1));\r\n\r\n    vector<T>\
    \ inv_alpha(m);\r\n    T pw = 1, izeta = trans.iroot[h + 1];\r\n    for (int i\
    \ = 0; i < m; i++) {\r\n        inv_alpha[rev[i]] = pw;\r\n        pw *= izeta;\r\
    \n    }\r\n\r\n    const T inv2 = T(2).inv();\r\n    while (n) {\r\n        trans.doubling(p);\r\
    \n        trans.doubling(q);\r\n\r\n        Poly<T> np(m), nq(m);\r\n        for\
    \ (int i = 0; i < m; i++) {\r\n            T a = p[2 * i] * q[2 * i + 1];\r\n\
    \            T b = p[2 * i + 1] * q[2 * i];\r\n            if (n & 1)\r\n    \
    \            np[i] = (a - b) * inv2 * inv_alpha[i];\r\n            else\r\n  \
    \              np[i] = (a + b) * inv2;\r\n            nq[i] = q[2 * i] * q[2 *\
    \ i + 1];\r\n        }\r\n        p.swap(np);\r\n        q.swap(nq);\r\n     \
    \   n >>= 1;\r\n    }\r\n\r\n    // The constant coefficient is the average of\
    \ all transformed values;\r\n    // the common factor 1/m cancels in the quotient.\r\
    \n    T ps = 0, qs = 0;\r\n    for (int i = 0; i < m; i++) {\r\n        ps +=\
    \ p[i];\r\n        qs += q[i];\r\n    }\r\n    return ps / qs;\r\n}\r\n\r\n/**\r\
    \n * @brief Bostan-Mori Algorithm\r\n */\r\n"
  dependsOn: []
  isVerificationFile: false
  path: FPS/nthterm.hpp
  requiredBy: []
  timestamp: '2026-10-28 08:02:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: FPS/nthterm.hpp
layout: document
redirect_from:
- /library/FPS/nthterm.hpp
- /library/FPS/nthterm.hpp.html
title: Bostan-Mori Algorithm
---
