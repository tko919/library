---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pfaffian
    links: []
  bundledCode: "#line 2 \"Math/matrix.hpp\"\n\r\ntemplate <class T> struct Matrix\
    \ {\r\n    int h, w;\r\n    vector<vector<T>> val;\r\n    T det;\r\n    Matrix()\
    \ {}\r\n    Matrix(int n) : h(n), w(n), val(vector<vector<T>>(n, vector<T>(n)))\
    \ {}\r\n    Matrix(int n, int m)\r\n        : h(n), w(m), val(vector<vector<T>>(n,\
    \ vector<T>(m))) {}\r\n    vector<T> &operator[](const int i) {\r\n        return\
    \ val[i];\r\n    }\r\n    Matrix &operator+=(const Matrix &m) {\r\n        assert(h\
    \ == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w) val[i][j] += m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix &operator-=(const Matrix &m) {\r\
    \n        assert(h == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w)\
    \ val[i][j] -= m.val[i][j];\r\n        return *this;\r\n    }\r\n    Matrix &operator*=(const\
    \ Matrix &m) {\r\n        assert(w == m.h);\r\n        Matrix<T> res(h, m.w);\r\
    \n        rep(i, 0, h) rep(j, 0, m.w) rep(k, 0, w) res.val[i][j] +=\r\n      \
    \      val[i][k] * m.val[k][j];\r\n        *this = res;\r\n        return *this;\r\
    \n    }\r\n    Matrix operator+(const Matrix &m) const {\r\n        return Matrix(*this)\
    \ += m;\r\n    }\r\n    Matrix operator-(const Matrix &m) const {\r\n        return\
    \ Matrix(*this) -= m;\r\n    }\r\n    Matrix operator*(const Matrix &m) const\
    \ {\r\n        return Matrix(*this) *= m;\r\n    }\r\n    Matrix pow(ll k) {\r\
    \n        Matrix<T> res(h, h), c = *this;\r\n        rep(i, 0, h) res.val[i][i]\
    \ = 1;\r\n        while (k) {\r\n            if (k & 1)\r\n                res\
    \ *= c;\r\n            c *= c;\r\n            k >>= 1;\r\n        }\r\n      \
    \  return res;\r\n    }\r\n    vector<int> gauss(int c = -1) {\r\n        det\
    \ = 1;\r\n        if (val.empty())\r\n            return {};\r\n        if (c\
    \ == -1)\r\n            c = w;\r\n        int cur = 0;\r\n        vector<int>\
    \ res;\r\n        rep(i, 0, c) {\r\n            if (cur == h)\r\n            \
    \    break;\r\n            rep(j, cur, h) if (val[j][i] != 0) {\r\n          \
    \      swap(val[cur], val[j]);\r\n                if (cur != j)\r\n          \
    \          det *= -1;\r\n                break;\r\n            }\r\n         \
    \   det *= val[cur][i];\r\n            if (val[cur][i] == 0)\r\n             \
    \   continue;\r\n            rep(j, 0, h) if (j != cur) {\r\n                T\
    \ z = val[j][i] / val[cur][i];\r\n                rep(k, i, w) val[j][k] -= val[cur][k]\
    \ * z;\r\n            }\r\n            res.push_back(i);\r\n            cur++;\r\
    \n        }\r\n        return res;\r\n    }\r\n    Matrix inv() {\r\n        assert(h\
    \ == w);\r\n        Matrix base(h, h * 2), res(h, h);\r\n        rep(i, 0, h)\
    \ rep(j, 0, h) base[i][j] = val[i][j];\r\n        rep(i, 0, h) base[i][h + i]\
    \ = 1;\r\n        base.gauss(h);\r\n        det = base.det;\r\n        rep(i,\
    \ 0, h) rep(j, 0, h) res[i][j] = base[i][h + j] / base[i][i];\r\n        return\
    \ res;\r\n    }\r\n    bool operator==(const Matrix &m) {\r\n        assert(h\
    \ == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w) if (val[i][j] !=\
    \ m.val[i][j]) return false;\r\n        return true;\r\n    }\r\n    bool operator!=(const\
    \ Matrix &m) {\r\n        assert(h == m.h and w == m.w);\r\n        rep(i, 0,\
    \ h) rep(j, 0, w) if (val[i][j] == m.val[i][j]) return false;\r\n        return\
    \ true;\r\n    }\r\n    friend istream &operator>>(istream &is, Matrix &m) {\r\
    \n        rep(i, 0, m.h) rep(j, 0, m.w) is >> m[i][j];\r\n        return is;\r\
    \n    }\r\n    friend ostream &operator<<(ostream &os, Matrix &m) {\r\n      \
    \  rep(i, 0, m.h) {\r\n            rep(j, 0, m.w) os << m[i][j]\r\n          \
    \                    << (j == m.w - 1 and i != m.h - 1 ? '\\n' : ' ');\r\n   \
    \     }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Matrix\r\n\
    \ */\n#line 3 \"Math/pfaffian.hpp\"\n\ntemplate <typename T> T Pfaffian(Matrix<T>\
    \ &a) {\n    int n = a.h;\n    assert(n == a.w and n % 2 == 0);\n    T ret = 1;\n\
    \    for (int i = 1; i < n; i += 2) {\n        rep(j, i, n) if (a[j][i - 1] !=\
    \ 0) {\n            swap(a[j], a[i]);\n            for (auto &v : a.val)\n   \
    \             swap(v[j], v[i]);\n            if (i != j)\n                ret\
    \ = -ret;\n            break;\n        }\n        if (a[i][i - 1] == 0)\n    \
    \        return 0;\n        ret *= -a[i][i - 1];\n        T inv = T(1) / a[i][i\
    \ - 1];\n        rep(j, i + 1, n) {\n            T z = a[j][i - 1] * inv;\n  \
    \          rep(k, 0, n) a[j][k] -= z * a[i][k];\n        }\n        inv = T(1)\
    \ / a[i - 1][i];\n        rep(j, i + 1, n) {\n            T z = a[i - 1][j] *\
    \ inv;\n            rep(k, 0, n) a[k][j] -= z * a[k][i];\n        }\n    }\n \
    \   return ret;\n}\n\n/**\n * @brief Pfaffian\n */\n"
  code: "#pragma once\n#include \"Math/matrix.hpp\"\n\ntemplate <typename T> T Pfaffian(Matrix<T>\
    \ &a) {\n    int n = a.h;\n    assert(n == a.w and n % 2 == 0);\n    T ret = 1;\n\
    \    for (int i = 1; i < n; i += 2) {\n        rep(j, i, n) if (a[j][i - 1] !=\
    \ 0) {\n            swap(a[j], a[i]);\n            for (auto &v : a.val)\n   \
    \             swap(v[j], v[i]);\n            if (i != j)\n                ret\
    \ = -ret;\n            break;\n        }\n        if (a[i][i - 1] == 0)\n    \
    \        return 0;\n        ret *= -a[i][i - 1];\n        T inv = T(1) / a[i][i\
    \ - 1];\n        rep(j, i + 1, n) {\n            T z = a[j][i - 1] * inv;\n  \
    \          rep(k, 0, n) a[j][k] -= z * a[i][k];\n        }\n        inv = T(1)\
    \ / a[i - 1][i];\n        rep(j, i + 1, n) {\n            T z = a[i - 1][j] *\
    \ inv;\n            rep(k, 0, n) a[k][j] -= z * a[k][i];\n        }\n    }\n \
    \   return ret;\n}\n\n/**\n * @brief Pfaffian\n */"
  dependsOn:
  - Math/matrix.hpp
  isVerificationFile: false
  path: Math/pfaffian.hpp
  requiredBy: []
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/pfaffian.hpp
layout: document
redirect_from:
- /library/Math/pfaffian.hpp
- /library/Math/pfaffian.hpp.html
title: Pfaffian
---
