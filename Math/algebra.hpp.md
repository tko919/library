---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Algebra Structure
    links: []
  bundledCode: "#line 2 \"Math/algebra.hpp\"\n\r\ntemplate <typename T, T (*add)(T,\
    \ T), T (*inv)(T), T (*e0)()> struct Group : T {\r\n    Group(T v = e0()) : T(v)\
    \ {}\r\n    Group operator-() const {\r\n        return Group(inv(*this));\r\n\
    \    }\r\n    Group &operator+=(const Group &x) {\r\n        return *this = add(*this,\
    \ x);\r\n    }\r\n    Group &operator-=(const Group &x) {\r\n        return *this\
    \ = add(*this, inv(x));\r\n    }\r\n    Group operator+(const Group &x) const\
    \ {\r\n        return Group(*this) += x;\r\n    }\r\n    Group operator-(const\
    \ Group &x) const {\r\n        return Group(*this) -= x;\r\n    }\r\n    bool\
    \ operator==(const Group &x) const {\r\n        return T(*this) == T(x);\r\n \
    \   }\r\n    bool operator!=(const Group &x) const {\r\n        return T(*this)\
    \ != T(x);\r\n    }\r\n};\r\n\r\ntemplate <typename T, T (*add)(T, T), T (*mul)(T,\
    \ T), T (*e0)(), T (*e1)()>\r\nstruct Semiring : T {\r\n    Semiring(T v = e0())\
    \ : T(v) {}\r\n    static T id1() {\r\n        return e1();\r\n    }\r\n    Semiring\
    \ &operator+=(const Semiring &x) {\r\n        return *this = add(*this, x);\r\n\
    \    }\r\n    Semiring &operator*=(const Semiring &x) {\r\n        return *this\
    \ = mul(*this, x);\r\n    }\r\n    Semiring operator+(const Semiring &x) const\
    \ {\r\n        return Semiring(*this) += x;\r\n    }\r\n    Semiring operator*(const\
    \ Semiring &x) const {\r\n        return Semiring(*this) *= x;\r\n    }\r\n  \
    \  bool operator==(const Semiring &x) const {\r\n        return T(*this) == T(x);\r\
    \n    }\r\n    bool operator!=(const Semiring &x) const {\r\n        return T(*this)\
    \ != T(x);\r\n    }\r\n};\r\n\r\ntemplate <class T> struct Matrix {\r\n    int\
    \ h, w;\r\n    vector<vector<T>> val;\r\n    Matrix() {}\r\n    Matrix(int n,\
    \ int m)\r\n        : h(n), w(m), val(vector<vector<T>>(n, vector<T>(m, T())))\
    \ {}\r\n    vector<T> &operator[](const int i) {\r\n        return val[i];\r\n\
    \    }\r\n    Matrix &operator+=(const Matrix &m) {\r\n        rep(i, 0, h) rep(j,\
    \ 0, w) val[i][j] += m.val[i][j];\r\n        return *this;\r\n    }\r\n    Matrix\
    \ &operator*=(const Matrix &m) {\r\n        Matrix<T> res(h, m.w);\r\n       \
    \ rep(i, 0, h) rep(j, 0, m.w) rep(k, 0, w) res.val[i][j] +=\r\n            val[i][k]\
    \ * m.val[k][j];\r\n        *this = res;\r\n        return *this;\r\n    }\r\n\
    \    Matrix operator+(const Matrix &m) const {\r\n        return Matrix(*this)\
    \ += m;\r\n    }\r\n    Matrix operator*(const Matrix &m) const {\r\n        return\
    \ Matrix(*this) *= m;\r\n    }\r\n    Matrix pow(ll k) {\r\n        Matrix<T>\
    \ res(h, h), c = *this;\r\n        rep(i, 0, h) res.val[i][i] = T::id1();\r\n\
    \        while (k) {\r\n            if (k & 1)\r\n                res *= c;\r\n\
    \            c *= c;\r\n            k >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Algebra Structure\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, T (*add)(T, T), T (*inv)(T), T\
    \ (*e0)()> struct Group : T {\r\n    Group(T v = e0()) : T(v) {}\r\n    Group\
    \ operator-() const {\r\n        return Group(inv(*this));\r\n    }\r\n    Group\
    \ &operator+=(const Group &x) {\r\n        return *this = add(*this, x);\r\n \
    \   }\r\n    Group &operator-=(const Group &x) {\r\n        return *this = add(*this,\
    \ inv(x));\r\n    }\r\n    Group operator+(const Group &x) const {\r\n       \
    \ return Group(*this) += x;\r\n    }\r\n    Group operator-(const Group &x) const\
    \ {\r\n        return Group(*this) -= x;\r\n    }\r\n    bool operator==(const\
    \ Group &x) const {\r\n        return T(*this) == T(x);\r\n    }\r\n    bool operator!=(const\
    \ Group &x) const {\r\n        return T(*this) != T(x);\r\n    }\r\n};\r\n\r\n\
    template <typename T, T (*add)(T, T), T (*mul)(T, T), T (*e0)(), T (*e1)()>\r\n\
    struct Semiring : T {\r\n    Semiring(T v = e0()) : T(v) {}\r\n    static T id1()\
    \ {\r\n        return e1();\r\n    }\r\n    Semiring &operator+=(const Semiring\
    \ &x) {\r\n        return *this = add(*this, x);\r\n    }\r\n    Semiring &operator*=(const\
    \ Semiring &x) {\r\n        return *this = mul(*this, x);\r\n    }\r\n    Semiring\
    \ operator+(const Semiring &x) const {\r\n        return Semiring(*this) += x;\r\
    \n    }\r\n    Semiring operator*(const Semiring &x) const {\r\n        return\
    \ Semiring(*this) *= x;\r\n    }\r\n    bool operator==(const Semiring &x) const\
    \ {\r\n        return T(*this) == T(x);\r\n    }\r\n    bool operator!=(const\
    \ Semiring &x) const {\r\n        return T(*this) != T(x);\r\n    }\r\n};\r\n\r\
    \ntemplate <class T> struct Matrix {\r\n    int h, w;\r\n    vector<vector<T>>\
    \ val;\r\n    Matrix() {}\r\n    Matrix(int n, int m)\r\n        : h(n), w(m),\
    \ val(vector<vector<T>>(n, vector<T>(m, T()))) {}\r\n    vector<T> &operator[](const\
    \ int i) {\r\n        return val[i];\r\n    }\r\n    Matrix &operator+=(const\
    \ Matrix &m) {\r\n        rep(i, 0, h) rep(j, 0, w) val[i][j] += m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix &operator*=(const Matrix &m) {\r\
    \n        Matrix<T> res(h, m.w);\r\n        rep(i, 0, h) rep(j, 0, m.w) rep(k,\
    \ 0, w) res.val[i][j] +=\r\n            val[i][k] * m.val[k][j];\r\n        *this\
    \ = res;\r\n        return *this;\r\n    }\r\n    Matrix operator+(const Matrix\
    \ &m) const {\r\n        return Matrix(*this) += m;\r\n    }\r\n    Matrix operator*(const\
    \ Matrix &m) const {\r\n        return Matrix(*this) *= m;\r\n    }\r\n    Matrix\
    \ pow(ll k) {\r\n        Matrix<T> res(h, h), c = *this;\r\n        rep(i, 0,\
    \ h) res.val[i][i] = T::id1();\r\n        while (k) {\r\n            if (k & 1)\r\
    \n                res *= c;\r\n            c *= c;\r\n            k >>= 1;\r\n\
    \        }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Algebra\
    \ Structure\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/algebra.hpp
  requiredBy: []
  timestamp: '2024-07-20 01:49:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/algebra.hpp
layout: document
redirect_from:
- /library/Math/algebra.hpp
- /library/Math/algebra.hpp.html
title: Algebra Structure
---
