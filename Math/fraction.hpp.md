---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/FracCoord.hpp
    title: Geometry(Fraction Coordinates)
  - icon: ':warning:'
    path: Math/partizangame.hpp
    title: Partizan Game Solver
  - icon: ':warning:'
    path: Math/sternbrocot.hpp
    title: Stern-Brocot Tree
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/fraction.md
    document_title: Fraction
    links: []
  bundledCode: "#line 2 \"Math/fraction.hpp\"\n\r\ntemplate <typename T> struct Frac\
    \ {\r\n    T a, b;\r\n    Frac(T _a = 0) {\r\n        init(_a, 1);\r\n    }\r\n\
    \    Frac(T _a, T _b) {\r\n        init(_a, _b);\r\n    }\r\n    template <typename\
    \ V> V get() const {\r\n        return V(a) / b;\r\n    }\r\n    Frac &init(T\
    \ _a, T _b) {\r\n        T g = gcd(_a, _b);\r\n        a = _a / g, b = _b / g;\r\
    \n        if (b < 0)\r\n            a = -a, b = -b;\r\n        return *this;\r\
    \n    }\r\n    Frac inv() const {\r\n        return Frac(b, a);\r\n    }\r\n \
    \   Frac operator-() const {\r\n        return Frac(-a, b);\r\n    }\r\n    Frac\
    \ &operator+=(const Frac &x) {\r\n        return init(a * x.b + x.a * b, b * x.b);\r\
    \n    }\r\n    Frac &operator-=(const Frac &x) {\r\n        return init(a * x.b\
    \ - x.a * b, b * x.b);\r\n    }\r\n    Frac &operator*=(const Frac &x) {\r\n \
    \       return init(a * x.a, b * x.b);\r\n    }\r\n    Frac &operator/=(const\
    \ Frac &x) {\r\n        return init(a * x.b, b * x.a);\r\n    }\r\n    Frac operator+(const\
    \ Frac &x) const {\r\n        return Frac(*this) += x;\r\n    }\r\n    Frac operator-(const\
    \ Frac &x) const {\r\n        return Frac(*this) -= x;\r\n    }\r\n    Frac operator*(const\
    \ Frac &x) const {\r\n        return Frac(*this) *= x;\r\n    }\r\n    Frac operator/(const\
    \ Frac &x) const {\r\n        return Frac(*this) /= x;\r\n    }\r\n    bool operator<(const\
    \ Frac &x) const {\r\n        return a * x.b < b * x.a;\r\n    }\r\n    bool operator>(const\
    \ Frac &x) const {\r\n        return x < *this;\r\n    }\r\n    bool operator<=(const\
    \ Frac &x) const {\r\n        return !(x < *this);\r\n    }\r\n    bool operator>=(const\
    \ Frac &x) const {\r\n        return !(*this < x);\r\n    }\r\n    bool operator==(const\
    \ Frac &x) const {\r\n        return (*this <= x and x <= *this);\r\n    }\r\n\
    \    bool operator!=(const Frac &x) const {\r\n        return !(*this == x);\r\
    \n    }\r\n\r\n    friend istream &operator>>(istream &is, Frac &x) {\r\n    \
    \    return is >> x.a >> x.b;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Frac &x) {\r\n        return os << x.a << '/' << x.b;\r\n    }\r\n\
    };\r\ntemplate <typename T> Frac<T> between(const Frac<T> &x, const Frac<T> &y)\
    \ {\r\n    if (x.a < x.b and y.b < y.a)\r\n        return Frac(1);\r\n    else\
    \ if (x.b <= x.a) {\r\n        T add = floor(x.a / x.b);\r\n        return between(x\
    \ - add, y - add) + add;\r\n    } else\r\n        return between(y.inv(), x.inv()).inv();\r\
    \n}\r\n\r\n/**\r\n * @brief Fraction\r\n * @docs docs/fraction.md\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> struct Frac {\r\n    T a, b;\r\n\
    \    Frac(T _a = 0) {\r\n        init(_a, 1);\r\n    }\r\n    Frac(T _a, T _b)\
    \ {\r\n        init(_a, _b);\r\n    }\r\n    template <typename V> V get() const\
    \ {\r\n        return V(a) / b;\r\n    }\r\n    Frac &init(T _a, T _b) {\r\n \
    \       T g = gcd(_a, _b);\r\n        a = _a / g, b = _b / g;\r\n        if (b\
    \ < 0)\r\n            a = -a, b = -b;\r\n        return *this;\r\n    }\r\n  \
    \  Frac inv() const {\r\n        return Frac(b, a);\r\n    }\r\n    Frac operator-()\
    \ const {\r\n        return Frac(-a, b);\r\n    }\r\n    Frac &operator+=(const\
    \ Frac &x) {\r\n        return init(a * x.b + x.a * b, b * x.b);\r\n    }\r\n\
    \    Frac &operator-=(const Frac &x) {\r\n        return init(a * x.b - x.a *\
    \ b, b * x.b);\r\n    }\r\n    Frac &operator*=(const Frac &x) {\r\n        return\
    \ init(a * x.a, b * x.b);\r\n    }\r\n    Frac &operator/=(const Frac &x) {\r\n\
    \        return init(a * x.b, b * x.a);\r\n    }\r\n    Frac operator+(const Frac\
    \ &x) const {\r\n        return Frac(*this) += x;\r\n    }\r\n    Frac operator-(const\
    \ Frac &x) const {\r\n        return Frac(*this) -= x;\r\n    }\r\n    Frac operator*(const\
    \ Frac &x) const {\r\n        return Frac(*this) *= x;\r\n    }\r\n    Frac operator/(const\
    \ Frac &x) const {\r\n        return Frac(*this) /= x;\r\n    }\r\n    bool operator<(const\
    \ Frac &x) const {\r\n        return a * x.b < b * x.a;\r\n    }\r\n    bool operator>(const\
    \ Frac &x) const {\r\n        return x < *this;\r\n    }\r\n    bool operator<=(const\
    \ Frac &x) const {\r\n        return !(x < *this);\r\n    }\r\n    bool operator>=(const\
    \ Frac &x) const {\r\n        return !(*this < x);\r\n    }\r\n    bool operator==(const\
    \ Frac &x) const {\r\n        return (*this <= x and x <= *this);\r\n    }\r\n\
    \    bool operator!=(const Frac &x) const {\r\n        return !(*this == x);\r\
    \n    }\r\n\r\n    friend istream &operator>>(istream &is, Frac &x) {\r\n    \
    \    return is >> x.a >> x.b;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Frac &x) {\r\n        return os << x.a << '/' << x.b;\r\n    }\r\n\
    };\r\ntemplate <typename T> Frac<T> between(const Frac<T> &x, const Frac<T> &y)\
    \ {\r\n    if (x.a < x.b and y.b < y.a)\r\n        return Frac(1);\r\n    else\
    \ if (x.b <= x.a) {\r\n        T add = floor(x.a / x.b);\r\n        return between(x\
    \ - add, y - add) + add;\r\n    } else\r\n        return between(y.inv(), x.inv()).inv();\r\
    \n}\r\n\r\n/**\r\n * @brief Fraction\r\n * @docs docs/fraction.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/fraction.hpp
  requiredBy:
  - Math/partizangame.hpp
  - Math/sternbrocot.hpp
  - Geometry/FracCoord.hpp
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/fraction.hpp
layout: document
redirect_from:
- /library/Math/fraction.hpp
- /library/Math/fraction.hpp.html
title: Fraction
---
## 使い方

`Frac between(const Frac& x,const Frac& y)`: $(x,y)$ 内で分母が最小の分数。