---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/mongedp.hpp
    title: Monge Shortest Path
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fibonacci Search
    links: []
  bundledCode: "#line 2 \"Algorithm/fibonacci.hpp\"\n\ntemplate <typename T, typename\
    \ F, bool MINIMIZE = 1>\nT FibonacciSearch(ll lb, ll rb, F f) {\n    ll s = 1,\
    \ t = 2;\n    while (t < rb - lb + 2) {\n        s += t;\n        swap(s, t);\n\
    \    }\n    ll L = lb - 1, m1 = L + t - s, m2 = L + s;\n    T v1 = f(m1), v2 =\
    \ f(m2);\n    while (m1 != m2) {\n        t -= s;\n        swap(s, t);\n     \
    \   if (rb < m2 or (MINIMIZE ? v1 >= v2 : v1 <= v2)) {\n            m2 = m1;\n\
    \            v2 = v1;\n            m1 = L + t - s;\n            v1 = f(m1);\n\
    \        } else {\n            L = m1;\n            m1 = m2;\n            v1 =\
    \ v2;\n            m2 = L + s;\n            v2 = m2 <= rb ? f(m2) : v1;\n    \
    \    }\n    }\n    return m1;\n}\n\n/**\n * @brief Fibonacci Search\n */\n"
  code: "#pragma once\n\ntemplate <typename T, typename F, bool MINIMIZE = 1>\nT FibonacciSearch(ll\
    \ lb, ll rb, F f) {\n    ll s = 1, t = 2;\n    while (t < rb - lb + 2) {\n   \
    \     s += t;\n        swap(s, t);\n    }\n    ll L = lb - 1, m1 = L + t - s,\
    \ m2 = L + s;\n    T v1 = f(m1), v2 = f(m2);\n    while (m1 != m2) {\n       \
    \ t -= s;\n        swap(s, t);\n        if (rb < m2 or (MINIMIZE ? v1 >= v2 :\
    \ v1 <= v2)) {\n            m2 = m1;\n            v2 = v1;\n            m1 = L\
    \ + t - s;\n            v1 = f(m1);\n        } else {\n            L = m1;\n \
    \           m1 = m2;\n            v1 = v2;\n            m2 = L + s;\n        \
    \    v2 = m2 <= rb ? f(m2) : v1;\n        }\n    }\n    return m1;\n}\n\n/**\n\
    \ * @brief Fibonacci Search\n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/fibonacci.hpp
  requiredBy:
  - Algorithm/mongedp.hpp
  timestamp: '2024-04-29 21:46:51+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/fibonacci.hpp
layout: document
redirect_from:
- /library/Algorithm/fibonacci.hpp
- /library/Algorithm/fibonacci.hpp.html
title: Fibonacci Search
---
