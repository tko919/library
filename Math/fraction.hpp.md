---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/FracCoord.hpp
    title: Geometry(Fraction Coordinates)
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
    \ {\r\n    T a, b;\r\n    Frac(T _a = 0) { init(_a, 1); }\r\n    Frac(T _a, T\
    \ _b) { init(_a, _b); }\r\n    Frac &init(T _a, T _b) {\r\n        T g = GCD(_a,\
    \ _b);\r\n        a = _a / g, b = _b / g;\r\n        if (b < 0)\r\n          \
    \  a = -a, b = -b;\r\n        return *this;\r\n    }\r\n    Frac inv() const {\
    \ return Frac(b, a); }\r\n    Frac operator-() const { return Frac(-a, b); }\r\
    \n    Frac &operator+=(const Frac &x) { return init(a * x.b + x.a * b, b * x.b);\
    \ }\r\n    Frac &operator-=(const Frac &x) { return init(a * x.b - x.a * b, b\
    \ * x.b); }\r\n    Frac &operator*=(const Frac &x) { return init(a * x.a, b *\
    \ x.b); }\r\n    Frac &operator/=(const Frac &x) { return init(a * x.b, b * x.a);\
    \ }\r\n    Frac operator+(const Frac &x) const { return Frac(*this) += x; }\r\n\
    \    Frac operator-(const Frac &x) const { return Frac(*this) -= x; }\r\n    Frac\
    \ operator*(const Frac &x) const { return Frac(*this) *= x; }\r\n    Frac operator/(const\
    \ Frac &x) const { return Frac(*this) /= x; }\r\n    bool operator<(const Frac\
    \ &x) const { return a * x.b < b * x.a; }\r\n    bool operator>(const Frac &x)\
    \ const { return x < *this; }\r\n    bool operator<=(const Frac &x) const { return\
    \ !(x < *this); }\r\n    bool operator>=(const Frac &x) const { return !(*this\
    \ < x); }\r\n    bool operator==(const Frac &x) const { return (*this <= x and\
    \ x <= *this); }\r\n    bool operator!=(const Frac &x) const { return !(*this\
    \ == x); }\r\n    T GCD(T a, T b) {\r\n        if (b == 0)\r\n            return\
    \ a;\r\n        else\r\n            return GCD(b, a % b);\r\n    }\r\n};\r\ntemplate\
    \ <typename T> Frac<T> between(const Frac<T> &x, const Frac<T> &y) {\r\n    if\
    \ (x.a < x.b and y.b < y.a)\r\n        return Frac(1);\r\n    else if (x.b <=\
    \ x.a) {\r\n        T add = floor(x.a / x.b);\r\n        return between(x - add,\
    \ y - add) + add;\r\n    } else\r\n        return between(y.inv(), x.inv()).inv();\r\
    \n}\r\n\r\n/**\r\n * @brief Fraction\r\n * @docs docs/fraction.md\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> struct Frac {\r\n    T a, b;\r\n\
    \    Frac(T _a = 0) { init(_a, 1); }\r\n    Frac(T _a, T _b) { init(_a, _b); }\r\
    \n    Frac &init(T _a, T _b) {\r\n        T g = GCD(_a, _b);\r\n        a = _a\
    \ / g, b = _b / g;\r\n        if (b < 0)\r\n            a = -a, b = -b;\r\n  \
    \      return *this;\r\n    }\r\n    Frac inv() const { return Frac(b, a); }\r\
    \n    Frac operator-() const { return Frac(-a, b); }\r\n    Frac &operator+=(const\
    \ Frac &x) { return init(a * x.b + x.a * b, b * x.b); }\r\n    Frac &operator-=(const\
    \ Frac &x) { return init(a * x.b - x.a * b, b * x.b); }\r\n    Frac &operator*=(const\
    \ Frac &x) { return init(a * x.a, b * x.b); }\r\n    Frac &operator/=(const Frac\
    \ &x) { return init(a * x.b, b * x.a); }\r\n    Frac operator+(const Frac &x)\
    \ const { return Frac(*this) += x; }\r\n    Frac operator-(const Frac &x) const\
    \ { return Frac(*this) -= x; }\r\n    Frac operator*(const Frac &x) const { return\
    \ Frac(*this) *= x; }\r\n    Frac operator/(const Frac &x) const { return Frac(*this)\
    \ /= x; }\r\n    bool operator<(const Frac &x) const { return a * x.b < b * x.a;\
    \ }\r\n    bool operator>(const Frac &x) const { return x < *this; }\r\n    bool\
    \ operator<=(const Frac &x) const { return !(x < *this); }\r\n    bool operator>=(const\
    \ Frac &x) const { return !(*this < x); }\r\n    bool operator==(const Frac &x)\
    \ const { return (*this <= x and x <= *this); }\r\n    bool operator!=(const Frac\
    \ &x) const { return !(*this == x); }\r\n    T GCD(T a, T b) {\r\n        if (b\
    \ == 0)\r\n            return a;\r\n        else\r\n            return GCD(b,\
    \ a % b);\r\n    }\r\n};\r\ntemplate <typename T> Frac<T> between(const Frac<T>\
    \ &x, const Frac<T> &y) {\r\n    if (x.a < x.b and y.b < y.a)\r\n        return\
    \ Frac(1);\r\n    else if (x.b <= x.a) {\r\n        T add = floor(x.a / x.b);\r\
    \n        return between(x - add, y - add) + add;\r\n    } else\r\n        return\
    \ between(y.inv(), x.inv()).inv();\r\n}\r\n\r\n/**\r\n * @brief Fraction\r\n *\
    \ @docs docs/fraction.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/fraction.hpp
  requiredBy:
  - Math/sternbrocot.hpp
  - Geometry/FracCoord.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
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