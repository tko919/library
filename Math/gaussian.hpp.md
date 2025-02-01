---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/twosquare.hpp
    title: Represent A Number As Two Square Sum
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Gaussaussian Integer
    links: []
  bundledCode: "#line 2 \"Math/gaussian.hpp\"\n\ntemplate <typename T> struct Gauss\
    \ {\n    T x, y;\n    Gauss() {}\n    Gauss(T _x, T _y) : x(_x), y(_y) {}\n  \
    \  T norm() const {\n        return x * x + y * y;\n    }\n    Gauss conj() const\
    \ {\n        return Gauss(x, -y);\n    }\n    Gauss operator-() const {\n    \
    \    return Gauss(-x, -y);\n    }\n    Gauss pow(ll n) const {\n        assert(n\
    \ >= 0);\n        Gauss ret(1), mul(*this);\n        while (n) {\n           \
    \ if (n & 1)\n                ret *= mul;\n            mul *= mul;\n         \
    \   n >>= 1;\n        }\n        return ret;\n    }\n    Gauss &operator+=(const\
    \ Gauss &a) {\n        x += a.x, y += a.y;\n        return *this;\n    }\n   \
    \ Gauss &operator-=(const Gauss &a) {\n        x -= a.x, y -= a.y;\n        return\
    \ *this;\n    }\n    Gauss &operator*=(const Gauss &a) {\n        T nx = x * a.x\
    \ - y * a.y, ny = x * a.y + y * a.x;\n        x = nx, y = ny;\n        return\
    \ *this;\n    }\n    Gauss &operator/=(const Gauss &a) {\n        (*this) *= a.conj();\n\
    \        T n = a.norm();\n        x = floor(x + n / 2, n), y = floor(y + n / 2,\
    \ n);\n        return *this;\n    }\n    Gauss &operator%=(const Gauss &a) {\n\
    \        (*this) -= (Gauss(*this) / a) * a;\n        return *this;\n    }\n  \
    \  Gauss operator+(const Gauss &a) const {\n        return Gauss(*this) += a;\n\
    \    }\n    Gauss operator-(const Gauss &a) const {\n        return Gauss(*this)\
    \ -= a;\n    }\n    Gauss operator*(const Gauss &a) const {\n        return Gauss(*this)\
    \ *= a;\n    }\n    Gauss operator/(const Gauss &a) const {\n        return Gauss(*this)\
    \ /= a;\n    }\n    Gauss operator%(const Gauss &a) const {\n        return Gauss(*this)\
    \ %= a;\n    }\n    bool operator==(const Gauss &a) {\n        return (x == a.x\
    \ and y == a.y);\n    }\n    bool operator!=(const Gauss &a) {\n        return\
    \ (x != a.x or y != a.y);\n    }\n};\n\ntemplate <typename T> Gauss<T> gcd(Gauss<T>\
    \ a, Gauss<T> b) {\n    while (b != Gauss<T>(0, 0)) {\n        a %= b;\n     \
    \   swap(a, b);\n    }\n    return a;\n}\n\n/**\n * @brief Gaussaussian Integer\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T> struct Gauss {\n    T x, y;\n    Gauss()\
    \ {}\n    Gauss(T _x, T _y) : x(_x), y(_y) {}\n    T norm() const {\n        return\
    \ x * x + y * y;\n    }\n    Gauss conj() const {\n        return Gauss(x, -y);\n\
    \    }\n    Gauss operator-() const {\n        return Gauss(-x, -y);\n    }\n\
    \    Gauss pow(ll n) const {\n        assert(n >= 0);\n        Gauss ret(1), mul(*this);\n\
    \        while (n) {\n            if (n & 1)\n                ret *= mul;\n  \
    \          mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n    Gauss &operator+=(const Gauss &a) {\n        x += a.x, y += a.y;\n\
    \        return *this;\n    }\n    Gauss &operator-=(const Gauss &a) {\n     \
    \   x -= a.x, y -= a.y;\n        return *this;\n    }\n    Gauss &operator*=(const\
    \ Gauss &a) {\n        T nx = x * a.x - y * a.y, ny = x * a.y + y * a.x;\n   \
    \     x = nx, y = ny;\n        return *this;\n    }\n    Gauss &operator/=(const\
    \ Gauss &a) {\n        (*this) *= a.conj();\n        T n = a.norm();\n       \
    \ x = floor(x + n / 2, n), y = floor(y + n / 2, n);\n        return *this;\n \
    \   }\n    Gauss &operator%=(const Gauss &a) {\n        (*this) -= (Gauss(*this)\
    \ / a) * a;\n        return *this;\n    }\n    Gauss operator+(const Gauss &a)\
    \ const {\n        return Gauss(*this) += a;\n    }\n    Gauss operator-(const\
    \ Gauss &a) const {\n        return Gauss(*this) -= a;\n    }\n    Gauss operator*(const\
    \ Gauss &a) const {\n        return Gauss(*this) *= a;\n    }\n    Gauss operator/(const\
    \ Gauss &a) const {\n        return Gauss(*this) /= a;\n    }\n    Gauss operator%(const\
    \ Gauss &a) const {\n        return Gauss(*this) %= a;\n    }\n    bool operator==(const\
    \ Gauss &a) {\n        return (x == a.x and y == a.y);\n    }\n    bool operator!=(const\
    \ Gauss &a) {\n        return (x != a.x or y != a.y);\n    }\n};\n\ntemplate <typename\
    \ T> Gauss<T> gcd(Gauss<T> a, Gauss<T> b) {\n    while (b != Gauss<T>(0, 0)) {\n\
    \        a %= b;\n        swap(a, b);\n    }\n    return a;\n}\n\n/**\n * @brief\
    \ Gaussaussian Integer\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/gaussian.hpp
  requiredBy:
  - Math/twosquare.hpp
  timestamp: '2025-02-02 04:09:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/gaussian.hpp
layout: document
redirect_from:
- /library/Math/gaussian.hpp
- /library/Math/gaussian.hpp.html
title: Gaussaussian Integer
---
