---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Math/multiplicative2.hpp
    title: Multiplicative Sum $O(n^{2/3}(\log n)^{-1})$
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_multiplicative_function.test.cpp
    title: Verify/LC_sum_of_multiplicative_function.test.cpp
  - icon: ':x:'
    path: Verify/LC_sum_of_totient_function.test.cpp
    title: Verify/LC_sum_of_totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Dirichlet series
    links: []
  bundledCode: "#line 2 \"Math/dirichlet.hpp\"\n\r\ntemplate <typename T> struct Dir\
    \ {\r\n    ll n;\r\n    int SQ, sz;\r\n    vector<T> dat;\r\n    Dir() {}\r\n\
    \    Dir(ll n) : n(n), SQ(sqrtl(n)), sz(SQ + n / (SQ + 1) + 1), dat(sz) {}\r\n\
    \    T &operator[](int i) {\r\n        return dat[i];\r\n    }\r\n    void pref()\
    \ {\r\n        rep(i, 0, sz - 1) dat[i + 1] += dat[i];\r\n    }\r\n    void diff()\
    \ {\r\n        rrep(i, 0, sz - 1) dat[i + 1] -= dat[i];\r\n    }\r\n    int idx(ll\
    \ x) const {\r\n        return (x <= SQ ? x : sz - n / x);\r\n    }\r\n    ll\
    \ val(int id) const {\r\n        return (id <= SQ ? id : n / (sz - id));\r\n \
    \   }\r\n};\r\n\r\ntemplate <typename T> Dir<T> mult(ll n, Dir<T> &a, Dir<T> &b)\
    \ {\r\n    int SQ = sqrtl(n);\r\n    Dir<T> c(n);\r\n    int thre = a.idx(max<int>(1,\
    \ pow(n, 2. / 3)));\r\n    auto get = [&](Dir<T> &A, Dir<T> &B) -> vector<pair<int,\
    \ T>> {\r\n        vector<pair<int, T>> ret;\r\n        rep(i, 1, SQ + 1) if (A[i\
    \ - 1] != A[i]) {\r\n            T x = A[i] - A[i - 1];\r\n            ret.push_back({i,\
    \ x});\r\n            rrep(j, thre + 1, c.sz) {\r\n                ll k = c.val(j);\r\
    \n                int to = B.idx(k / i);\r\n                if (to < i)\r\n  \
    \                  break;\r\n                c[j] += x * B[to];\r\n          \
    \  }\r\n        }\r\n        rep(i, SQ + 1, thre + 1) {\r\n            if (A[i\
    \ - 1] != A[i]) {\r\n                T x = A[i] - A[i - 1];\r\n              \
    \  ret.push_back({A.val(i), x});\r\n            }\r\n        }\r\n        return\
    \ ret;\r\n    };\r\n    auto posA = get(a, b);\r\n    auto posB = get(b, a);\r\
    \n    for (auto &[v, x] : posA) {\r\n        for (auto &[w, y] : posB) {\r\n \
    \           int to = c.idx(ll(v) * w);\r\n            if (to > thre)\r\n     \
    \           break;\r\n            c[c.idx(v * w)] += x * y;\r\n        }\r\n \
    \   }\r\n    rep(i, 1, thre + 1) {\r\n        c[i] += c[i - 1];\r\n    }\r\n\r\
    \n    rrep(i, thre + 1, c.sz) {\r\n        ll x = c.val(i);\r\n        int j =\
    \ sqrtl(x);\r\n        c[i] -= a[j] * b[j];\r\n    }\r\n\r\n    return c;\r\n\
    }\r\n\r\ntemplate <typename T> Dir<T> div(ll n, Dir<T> c, Dir<T> a) {\r\n    T\
    \ coe = T(1) / a[1];\r\n    for (auto &x : a.dat)\r\n        x *= coe;\r\n\r\n\
    \    int SQ = sqrtl(n);\r\n    int thre = a.idx(max<int>(1, pow(n, 2. / 3)));\r\
    \n    Dir<T> dc = c, da = a, db(n), b(n);\r\n    dc.diff();\r\n    da.diff();\r\
    \n\r\n    db[1] = c[1];\r\n    rep(i, 2, thre + 1) {\r\n        db[i] = dc[i]\
    \ - da[i] * db[1];\r\n        ll x = a.val(i);\r\n        {\r\n            int\
    \ j = a.idx(x * x);\r\n            if (j <= thre)\r\n                dc[j] -=\
    \ da[i] * db[i];\r\n        }\r\n        rep(j, 2, i) {\r\n            int k =\
    \ a.idx(x * a.val(j));\r\n            if (k > thre)\r\n                break;\r\
    \n            dc[k] -= da[i] * db[j] + da[j] * db[i];\r\n        }\r\n    }\r\n\
    \    rep(i, 1, thre + 1) {\r\n        b[i] = db[i] + b[i - 1];\r\n    }\r\n  \
    \  rep(i, thre + 1, a.sz) {\r\n        b[i] = c[i] - a[i] * b[1];\r\n        ll\
    \ x = a.val(i);\r\n        {\r\n            int j = a.idx(sqrtl(x));\r\n     \
    \       b[i] += a[j] * b[j];\r\n        }\r\n        rep(j, 2, i + 1) {\r\n  \
    \          int k = a.idx(x / j);\r\n            if (j > k)\r\n               \
    \ break;\r\n            b[i] -= da[j] * b[k] + a[k] * db[j];\r\n        }\r\n\
    \    }\r\n\r\n    for (auto &x : b.dat)\r\n        x *= coe;\r\n    return b;\r\
    \n}\r\n\r\n/**\r\n * @brief Dirichlet series\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> struct Dir {\r\n    ll n;\r\n \
    \   int SQ, sz;\r\n    vector<T> dat;\r\n    Dir() {}\r\n    Dir(ll n) : n(n),\
    \ SQ(sqrtl(n)), sz(SQ + n / (SQ + 1) + 1), dat(sz) {}\r\n    T &operator[](int\
    \ i) {\r\n        return dat[i];\r\n    }\r\n    void pref() {\r\n        rep(i,\
    \ 0, sz - 1) dat[i + 1] += dat[i];\r\n    }\r\n    void diff() {\r\n        rrep(i,\
    \ 0, sz - 1) dat[i + 1] -= dat[i];\r\n    }\r\n    int idx(ll x) const {\r\n \
    \       return (x <= SQ ? x : sz - n / x);\r\n    }\r\n    ll val(int id) const\
    \ {\r\n        return (id <= SQ ? id : n / (sz - id));\r\n    }\r\n};\r\n\r\n\
    template <typename T> Dir<T> mult(ll n, Dir<T> &a, Dir<T> &b) {\r\n    int SQ\
    \ = sqrtl(n);\r\n    Dir<T> c(n);\r\n    int thre = a.idx(max<int>(1, pow(n, 2.\
    \ / 3)));\r\n    auto get = [&](Dir<T> &A, Dir<T> &B) -> vector<pair<int, T>>\
    \ {\r\n        vector<pair<int, T>> ret;\r\n        rep(i, 1, SQ + 1) if (A[i\
    \ - 1] != A[i]) {\r\n            T x = A[i] - A[i - 1];\r\n            ret.push_back({i,\
    \ x});\r\n            rrep(j, thre + 1, c.sz) {\r\n                ll k = c.val(j);\r\
    \n                int to = B.idx(k / i);\r\n                if (to < i)\r\n  \
    \                  break;\r\n                c[j] += x * B[to];\r\n          \
    \  }\r\n        }\r\n        rep(i, SQ + 1, thre + 1) {\r\n            if (A[i\
    \ - 1] != A[i]) {\r\n                T x = A[i] - A[i - 1];\r\n              \
    \  ret.push_back({A.val(i), x});\r\n            }\r\n        }\r\n        return\
    \ ret;\r\n    };\r\n    auto posA = get(a, b);\r\n    auto posB = get(b, a);\r\
    \n    for (auto &[v, x] : posA) {\r\n        for (auto &[w, y] : posB) {\r\n \
    \           int to = c.idx(ll(v) * w);\r\n            if (to > thre)\r\n     \
    \           break;\r\n            c[c.idx(v * w)] += x * y;\r\n        }\r\n \
    \   }\r\n    rep(i, 1, thre + 1) {\r\n        c[i] += c[i - 1];\r\n    }\r\n\r\
    \n    rrep(i, thre + 1, c.sz) {\r\n        ll x = c.val(i);\r\n        int j =\
    \ sqrtl(x);\r\n        c[i] -= a[j] * b[j];\r\n    }\r\n\r\n    return c;\r\n\
    }\r\n\r\ntemplate <typename T> Dir<T> div(ll n, Dir<T> c, Dir<T> a) {\r\n    T\
    \ coe = T(1) / a[1];\r\n    for (auto &x : a.dat)\r\n        x *= coe;\r\n\r\n\
    \    int SQ = sqrtl(n);\r\n    int thre = a.idx(max<int>(1, pow(n, 2. / 3)));\r\
    \n    Dir<T> dc = c, da = a, db(n), b(n);\r\n    dc.diff();\r\n    da.diff();\r\
    \n\r\n    db[1] = c[1];\r\n    rep(i, 2, thre + 1) {\r\n        db[i] = dc[i]\
    \ - da[i] * db[1];\r\n        ll x = a.val(i);\r\n        {\r\n            int\
    \ j = a.idx(x * x);\r\n            if (j <= thre)\r\n                dc[j] -=\
    \ da[i] * db[i];\r\n        }\r\n        rep(j, 2, i) {\r\n            int k =\
    \ a.idx(x * a.val(j));\r\n            if (k > thre)\r\n                break;\r\
    \n            dc[k] -= da[i] * db[j] + da[j] * db[i];\r\n        }\r\n    }\r\n\
    \    rep(i, 1, thre + 1) {\r\n        b[i] = db[i] + b[i - 1];\r\n    }\r\n  \
    \  rep(i, thre + 1, a.sz) {\r\n        b[i] = c[i] - a[i] * b[1];\r\n        ll\
    \ x = a.val(i);\r\n        {\r\n            int j = a.idx(sqrtl(x));\r\n     \
    \       b[i] += a[j] * b[j];\r\n        }\r\n        rep(j, 2, i + 1) {\r\n  \
    \          int k = a.idx(x / j);\r\n            if (j > k)\r\n               \
    \ break;\r\n            b[i] -= da[j] * b[k] + a[k] * db[j];\r\n        }\r\n\
    \    }\r\n\r\n    for (auto &x : b.dat)\r\n        x *= coe;\r\n    return b;\r\
    \n}\r\n\r\n/**\r\n * @brief Dirichlet series\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/dirichlet.hpp
  requiredBy:
  - Math/multiplicative2.hpp
  timestamp: '2025-07-13 05:51:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_totient_function.test.cpp
  - Verify/LC_sum_of_multiplicative_function.test.cpp
documentation_of: Math/dirichlet.hpp
layout: document
redirect_from:
- /library/Math/dirichlet.hpp
- /library/Math/dirichlet.hpp.html
title: Dirichlet series
---
