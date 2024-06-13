---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Algorithm/fibonacci.hpp
    title: Fibonacci Search
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Monge Shortest Path
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
    \    }\n    }\n    return m1;\n}\n\n/**\n * @brief Fibonacci Search\n */\n#line\
    \ 3 \"Algorithm/mongedp.hpp\"\n\ntemplate <typename T, T wmx, typename F> T MongeShortestPath(int\
    \ n, F f) {\n    vector<T> dp(n, wmx);\n    dp[0] = 0;\n    vector<int> amin(n);\n\
    \n    auto check = [&](int i, int j) {\n        T val = dp[j] + f(j, i);\n   \
    \     if (chmin(dp[i], val))\n            amin[i] = j;\n    };\n    auto rec =\
    \ [&](auto &rec, int L, int R) {\n        if (R - L == 1)\n            return;\n\
    \        int mid = (L + R) >> 1;\n        rep(k, amin[L], amin[R] + 1) check(mid,\
    \ k);\n        rec(rec, L, mid);\n        rep(k, L + 1, mid + 1) check(R, k);\n\
    \        rec(rec, mid, R);\n    };\n\n    rec(rec, 0, n - 1);\n    return dp.back();\n\
    }\n\ntemplate <typename T, T wmx, typename F>\nT dEdgeMongeShortestPath(int n,\
    \ int d, F f) {\n    auto calc = [&](T lamb) -> T {\n        T ret = MongeShortestPath<T,\
    \ wmx>(\n                    n, [&](int i, int j) { return f(i, j) + lamb; })\
    \ -\n                lamb * d;\n        return ret;\n    };\n    ll lambda = FibonacciSearch<ll>(-wmx\
    \ * 3, wmx * 3, calc);\n    return calc(lambda);\n}\n\n/**\n * @brief Monge Shortest\
    \ Path\n */\n"
  code: "#pragma once\n#include \"Algorithm/fibonacci.hpp\"\n\ntemplate <typename\
    \ T, T wmx, typename F> T MongeShortestPath(int n, F f) {\n    vector<T> dp(n,\
    \ wmx);\n    dp[0] = 0;\n    vector<int> amin(n);\n\n    auto check = [&](int\
    \ i, int j) {\n        T val = dp[j] + f(j, i);\n        if (chmin(dp[i], val))\n\
    \            amin[i] = j;\n    };\n    auto rec = [&](auto &rec, int L, int R)\
    \ {\n        if (R - L == 1)\n            return;\n        int mid = (L + R) >>\
    \ 1;\n        rep(k, amin[L], amin[R] + 1) check(mid, k);\n        rec(rec, L,\
    \ mid);\n        rep(k, L + 1, mid + 1) check(R, k);\n        rec(rec, mid, R);\n\
    \    };\n\n    rec(rec, 0, n - 1);\n    return dp.back();\n}\n\ntemplate <typename\
    \ T, T wmx, typename F>\nT dEdgeMongeShortestPath(int n, int d, F f) {\n    auto\
    \ calc = [&](T lamb) -> T {\n        T ret = MongeShortestPath<T, wmx>(\n    \
    \                n, [&](int i, int j) { return f(i, j) + lamb; }) -\n        \
    \        lamb * d;\n        return ret;\n    };\n    ll lambda = FibonacciSearch<ll>(-wmx\
    \ * 3, wmx * 3, calc);\n    return calc(lambda);\n}\n\n/**\n * @brief Monge Shortest\
    \ Path\n */"
  dependsOn:
  - Algorithm/fibonacci.hpp
  isVerificationFile: false
  path: Algorithm/mongedp.hpp
  requiredBy: []
  timestamp: '2024-04-29 21:46:51+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/mongedp.hpp
layout: document
redirect_from:
- /library/Algorithm/mongedp.hpp
- /library/Algorithm/mongedp.hpp.html
title: Monge Shortest Path
---
