---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: FPS/berlekampmassey.hpp
    title: Berlekamp Massey Algorithm
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sparse_matrix_det.test.cpp
    title: Verify/LC_sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Black Box Linear Algebra
    links: []
  bundledCode: "#line 2 \"Math/bbla.hpp\"\n\r\n#line 2 \"FPS/berlekampmassey.hpp\"\
    \n\r\ntemplate <typename T> vector<T> BerlekampMassey(vector<T> &a) {\r\n    int\
    \ n = a.size();\r\n    T d = 1;\r\n    vector<T> b(1), c(1);\r\n    b[0] = c[0]\
    \ = 1;\r\n    rep(j, 1, n + 1) {\r\n        int l = c.size(), m = b.size();\r\n\
    \        T x = 0;\r\n        rep(i, 0, l) x += c[i] * a[j - l + i];\r\n      \
    \  b.push_back(0);\r\n        m++;\r\n        if (x == 0)\r\n            continue;\r\
    \n        T coeff = -x / d;\r\n        if (l < m) {\r\n            auto tmp =\
    \ c;\r\n            c.insert(c.begin(), m - l, 0);\r\n            rep(i, 0, m)\
    \ c[m - 1 - i] += coeff * b[m - 1 - i];\r\n            b = tmp;\r\n          \
    \  d = x;\r\n        } else\r\n            rep(i, 0, m) c[l - 1 - i] += coeff\
    \ * b[m - 1 - i];\r\n    }\r\n    reverse(ALL(c));\r\n    return c;\r\n}\r\n\r\
    \n/**\r\n * @brief Berlekamp Massey Algorithm\r\n */\n#line 2 \"Utility/random.hpp\"\
    \n\r\nnamespace Random {\r\nmt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nusing u64 = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n\
    }\r\ntemplate <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\
    \n}\r\ntemplate <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R -\
    \ L) + L;\r\n}\r\ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\
    \n}\r\nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a',\
    \ 'z');\r\n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter\
    \ first, Iter last) {\r\n    if (first == last)\r\n        return;\r\n    int\
    \ len = 1;\r\n    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\
    \n        int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n          \
    \  iter_swap(it, first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T>\
    \ select(int n, T L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n    \
    \    vector<T> ret(R - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\
    \n        ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool multi, bool self>\r\
    \nvector<pair<int, int>> genGraph(int n, int m) {\r\n    vector<pair<int, int>>\
    \ cand, es;\r\n    rep(u, 0, n) rep(v, 0, n) {\r\n        if (!self and u == v)\r\
    \n            continue;\r\n        if (!directed and u > v)\r\n            continue;\r\
    \n        cand.push_back({u, v});\r\n    }\r\n    if (m == -1)\r\n        m =\
    \ get(SZ(cand));\r\n    // chmin(m, SZ(cand));\r\n    vector<int> ord;\r\n   \
    \ if (multi)\r\n        rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n   \
    \ else {\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    }\r\n    for (auto\
    \ &i : ord)\r\n        es.push_back(cand[i]);\r\n    relabel(n, es);\r\n    return\
    \ es;\r\n}\r\nvector<pair<int, int>> genTree(int n) {\r\n    vector<pair<int,\
    \ int>> es;\r\n    rep(i, 1, n) es.push_back({get(i - 1), i});\r\n    relabel(n,\
    \ es);\r\n    return es;\r\n}\r\n}; // namespace Random\r\n\r\n/**\r\n * @brief\
    \ Random\r\n */\n#line 5 \"Math/bbla.hpp\"\n\r\ntemplate <typename T> Poly<T>\
    \ RandPoly(int n) {\r\n    Poly<T> ret(n);\r\n    for (auto &x : ret)\r\n    \
    \    x = Random::get(1, T::get_mod() - 1);\r\n    return ret;\r\n}\r\ntemplate\
    \ <typename T> struct SparseMatrix {\r\n    vector<T> base;\r\n    vector<map<int,\
    \ T>> extra;\r\n    SparseMatrix(int n, T v = 0) : base(n, v), extra(n) {}\r\n\
    \    int size() const { return base.size(); }\r\n    inline void add(int i, int\
    \ j, T x) { extra[i][j] += x; }\r\n    friend Poly<T> operator*(const SparseMatrix<T>\
    \ &A, const Poly<T> &b) {\r\n        int n = A.size();\r\n        Poly<T> ret(n);\r\
    \n        T sum;\r\n        for (auto &v : b)\r\n            sum += v;\r\n   \
    \     rep(i, 0, n) {\r\n            T add = sum;\r\n            for (auto &[j,\
    \ v] : A.extra[i]) {\r\n                ret[i] += v * b[j];\r\n              \
    \  add -= b[j];\r\n            }\r\n            ret[i] += add * A.base[i];\r\n\
    \        }\r\n        return ret;\r\n    }\r\n    void mul(int i, T x) {\r\n \
    \       base[i] *= x;\r\n        for (auto &[_, v] : extra[i])\r\n           \
    \ v *= x;\r\n    }\r\n};\r\n\r\ntemplate <typename T> Poly<T> MinPolyforVector(const\
    \ vector<Poly<T>> &b) {\r\n    int n = b.size(), m = b[0].size();\r\n    Poly<T>\
    \ base = RandPoly<T>(m), a(n);\r\n    rep(i, 0, n) rep(j, 0, m) a[i] += base[j]\
    \ * b[i][j];\r\n    return Poly<T>(BerlekampMassey(a)).rev();\r\n}\r\ntemplate\
    \ <typename T> Poly<T> MinPolyforMatrix(const SparseMatrix<T> &A) {\r\n    int\
    \ n = A.size();\r\n    Poly<T> base = RandPoly<T>(n);\r\n    vector<Poly<T>> b(n\
    \ * 2 + 1);\r\n    rep(i, 0, n * 2 + 1) b[i] = base, base = A * base;\r\n    return\
    \ MinPolyforVector(b);\r\n}\r\ntemplate <typename T>\r\nPoly<T> FastPow(const\
    \ SparseMatrix<T> &A, Poly<T> b, ll t) {\r\n    int n = A.size();\r\n    auto\
    \ mp = MinPolyforMatrix(A).rev();\r\n    Poly<T> cs({T(1)}), base({T(0), T(1)});\r\
    \n    while (t) {\r\n        if (t & 1) {\r\n            cs *= base;\r\n     \
    \       cs %= mp;\r\n        }\r\n        base = base.square();\r\n        base\
    \ %= mp;\r\n        t >>= 1;\r\n    }\r\n    Poly<T> ret(n);\r\n    for (auto\
    \ &c : cs)\r\n        ret += b * c, b = A * b;\r\n    return ret;\r\n}\r\ntemplate\
    \ <typename T> T FastDet(const SparseMatrix<T> &A) {\r\n    int n = A.size();\r\
    \n    for (;;) {\r\n        Poly<T> d = RandPoly<T>(n);\r\n        SparseMatrix<T>\
    \ AD = A;\r\n        rep(i, 0, n) AD.mul(i, d[i]);\r\n        auto mp = MinPolyforMatrix(AD);\r\
    \n        if (mp.back() == 0)\r\n            return 0;\r\n        if (int(mp.size())\
    \ != n + 1)\r\n            continue;\r\n        T ret = mp.back(), base = 1;\r\
    \n        if (n & 1)\r\n            ret = -ret;\r\n        for (auto &v : d)\r\
    \n            base *= v;\r\n        return ret / base;\r\n    }\r\n}\r\n\r\n/**\r\
    \n * @brief Black Box Linear Algebra\r\n */\n"
  code: "#pragma once\r\n\r\n#include \"FPS/berlekampmassey.hpp\"\r\n#include \"Utility/random.hpp\"\
    \r\n\r\ntemplate <typename T> Poly<T> RandPoly(int n) {\r\n    Poly<T> ret(n);\r\
    \n    for (auto &x : ret)\r\n        x = Random::get(1, T::get_mod() - 1);\r\n\
    \    return ret;\r\n}\r\ntemplate <typename T> struct SparseMatrix {\r\n    vector<T>\
    \ base;\r\n    vector<map<int, T>> extra;\r\n    SparseMatrix(int n, T v = 0)\
    \ : base(n, v), extra(n) {}\r\n    int size() const { return base.size(); }\r\n\
    \    inline void add(int i, int j, T x) { extra[i][j] += x; }\r\n    friend Poly<T>\
    \ operator*(const SparseMatrix<T> &A, const Poly<T> &b) {\r\n        int n = A.size();\r\
    \n        Poly<T> ret(n);\r\n        T sum;\r\n        for (auto &v : b)\r\n \
    \           sum += v;\r\n        rep(i, 0, n) {\r\n            T add = sum;\r\n\
    \            for (auto &[j, v] : A.extra[i]) {\r\n                ret[i] += v\
    \ * b[j];\r\n                add -= b[j];\r\n            }\r\n            ret[i]\
    \ += add * A.base[i];\r\n        }\r\n        return ret;\r\n    }\r\n    void\
    \ mul(int i, T x) {\r\n        base[i] *= x;\r\n        for (auto &[_, v] : extra[i])\r\
    \n            v *= x;\r\n    }\r\n};\r\n\r\ntemplate <typename T> Poly<T> MinPolyforVector(const\
    \ vector<Poly<T>> &b) {\r\n    int n = b.size(), m = b[0].size();\r\n    Poly<T>\
    \ base = RandPoly<T>(m), a(n);\r\n    rep(i, 0, n) rep(j, 0, m) a[i] += base[j]\
    \ * b[i][j];\r\n    return Poly<T>(BerlekampMassey(a)).rev();\r\n}\r\ntemplate\
    \ <typename T> Poly<T> MinPolyforMatrix(const SparseMatrix<T> &A) {\r\n    int\
    \ n = A.size();\r\n    Poly<T> base = RandPoly<T>(n);\r\n    vector<Poly<T>> b(n\
    \ * 2 + 1);\r\n    rep(i, 0, n * 2 + 1) b[i] = base, base = A * base;\r\n    return\
    \ MinPolyforVector(b);\r\n}\r\ntemplate <typename T>\r\nPoly<T> FastPow(const\
    \ SparseMatrix<T> &A, Poly<T> b, ll t) {\r\n    int n = A.size();\r\n    auto\
    \ mp = MinPolyforMatrix(A).rev();\r\n    Poly<T> cs({T(1)}), base({T(0), T(1)});\r\
    \n    while (t) {\r\n        if (t & 1) {\r\n            cs *= base;\r\n     \
    \       cs %= mp;\r\n        }\r\n        base = base.square();\r\n        base\
    \ %= mp;\r\n        t >>= 1;\r\n    }\r\n    Poly<T> ret(n);\r\n    for (auto\
    \ &c : cs)\r\n        ret += b * c, b = A * b;\r\n    return ret;\r\n}\r\ntemplate\
    \ <typename T> T FastDet(const SparseMatrix<T> &A) {\r\n    int n = A.size();\r\
    \n    for (;;) {\r\n        Poly<T> d = RandPoly<T>(n);\r\n        SparseMatrix<T>\
    \ AD = A;\r\n        rep(i, 0, n) AD.mul(i, d[i]);\r\n        auto mp = MinPolyforMatrix(AD);\r\
    \n        if (mp.back() == 0)\r\n            return 0;\r\n        if (int(mp.size())\
    \ != n + 1)\r\n            continue;\r\n        T ret = mp.back(), base = 1;\r\
    \n        if (n & 1)\r\n            ret = -ret;\r\n        for (auto &v : d)\r\
    \n            base *= v;\r\n        return ret / base;\r\n    }\r\n}\r\n\r\n/**\r\
    \n * @brief Black Box Linear Algebra\r\n */"
  dependsOn:
  - FPS/berlekampmassey.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/bbla.hpp
  requiredBy: []
  timestamp: '2025-05-25 16:11:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sparse_matrix_det.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/YUKI_1112.test.cpp
documentation_of: Math/bbla.hpp
layout: document
redirect_from:
- /library/Math/bbla.hpp
- /library/Math/bbla.hpp.html
title: Black Box Linear Algebra
---
