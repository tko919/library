---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/fraction.hpp
    title: Fraction
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Stern-Brocot Tree
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
    };\r\n\r\n/**\r\n * @brief Fraction\r\n * @docs docs/fraction.md\r\n */\n#line\
    \ 3 \"Math/sternbrocot.hpp\"\n\nnamespace SternBrocotTree {\n// R start\nstatic\
    \ vector<int> encode(Frac x) {\n    return get(x).first;\n}\nstatic Frac decode(vector<int>\
    \ &v) {\n    Frac L(0, 1), R(1, 0);\n    rep(i, 0, v.size()) {\n        if (i\
    \ & 1)\n            R = Frac(L.a * v[i] + R.a, L.b * v[i] + R.b);\n        else\n\
    \            L = Frac(R.a * v[i] + L.a, R.b * v[i] + L.b);\n    }\n    return\
    \ Frac(L.a + R.a, L.b + R.b);\n}\nstatic Frac lca(Frac x, Frac y) {\n    auto\
    \ px = encode(x), py = encode(y);\n    vector<int> q;\n    rep(i, 0, min(px.size(),\
    \ py.size())) {\n        q.push_back(min(px[i], py[i]));\n        if (q.back()\
    \ != px[i] or q.back() != py[i])\n            break;\n    }\n    return decode(q);\n\
    }\nstatic pair<Frac, Frac> child(Frac x) {\n    auto [L, R] = subtree(x);\n  \
    \  Frac lb(L.a + x.a, L.b + x.b), rb(R.a + x.a, R.b + x.b);\n    return {lb, rb};\n\
    }\nstatic Frac la(Frac x, ll k) {\n    auto path = encode(x);\n    for (;;) {\n\
    \        if (path.empty())\n            return Frac(-1, 1);\n        if (k <=\
    \ path.back()) {\n            path.back() -= k;\n            break;\n        }\
    \ else {\n            k = path.back();\n            path.pop_back();\n       \
    \ }\n    }\n    return decode(path);\n}\nstatic pair<Frac, Frac> subtree(Frac\
    \ x) {\n    return get(x).second;\n}\n\nprivate:\nstatic ll ceil(ll a, ll b) {\n\
    \    return (a + b - 1) / b;\n}\nstatic pair<vector<int>, pair<Frac, Frac>> get(Frac\
    \ &x) {\n    Frac L(0, 1), R(1, 0), mid(1, 1);\n    vector<int> path;\n    for\
    \ (;;) {\n        if (mid == x)\n            break;\n        ll k = ceil(x.a *\
    \ L.b - x.b * L.a, x.b * R.a - x.a * R.b) - 1;\n        L = Frac(L.a + k * R.a,\
    \ L.b + k * R.b);\n        mid = Frac(L.a + R.a, L.b + R.b);\n        path.push_back(k);\n\
    \        if (mid == x)\n            break;\n        k = ceil(x.b * R.a - x.a *\
    \ R.b, x.a * L.b - x.b * L.a) - 1;\n        R = Frac(R.a + k * L.a, R.b + k *\
    \ L.b);\n        mid = Frac(L.a + R.a, L.b + R.b);\n        path.push_back(k);\n\
    \    }\n    return {path, {L, R}};\n}\n}; // namespace SternBrocotTree\n\n/**\n\
    \ * @brief Stern-Brocot Tree\n */\n"
  code: "#pragma once\n#include \"Math/fraction.hpp\"\n\nnamespace SternBrocotTree\
    \ {\n// R start\nstatic vector<int> encode(Frac x) {\n    return get(x).first;\n\
    }\nstatic Frac decode(vector<int> &v) {\n    Frac L(0, 1), R(1, 0);\n    rep(i,\
    \ 0, v.size()) {\n        if (i & 1)\n            R = Frac(L.a * v[i] + R.a, L.b\
    \ * v[i] + R.b);\n        else\n            L = Frac(R.a * v[i] + L.a, R.b * v[i]\
    \ + L.b);\n    }\n    return Frac(L.a + R.a, L.b + R.b);\n}\nstatic Frac lca(Frac\
    \ x, Frac y) {\n    auto px = encode(x), py = encode(y);\n    vector<int> q;\n\
    \    rep(i, 0, min(px.size(), py.size())) {\n        q.push_back(min(px[i], py[i]));\n\
    \        if (q.back() != px[i] or q.back() != py[i])\n            break;\n   \
    \ }\n    return decode(q);\n}\nstatic pair<Frac, Frac> child(Frac x) {\n    auto\
    \ [L, R] = subtree(x);\n    Frac lb(L.a + x.a, L.b + x.b), rb(R.a + x.a, R.b +\
    \ x.b);\n    return {lb, rb};\n}\nstatic Frac la(Frac x, ll k) {\n    auto path\
    \ = encode(x);\n    for (;;) {\n        if (path.empty())\n            return\
    \ Frac(-1, 1);\n        if (k <= path.back()) {\n            path.back() -= k;\n\
    \            break;\n        } else {\n            k = path.back();\n        \
    \    path.pop_back();\n        }\n    }\n    return decode(path);\n}\nstatic pair<Frac,\
    \ Frac> subtree(Frac x) {\n    return get(x).second;\n}\n\nprivate:\nstatic ll\
    \ ceil(ll a, ll b) {\n    return (a + b - 1) / b;\n}\nstatic pair<vector<int>,\
    \ pair<Frac, Frac>> get(Frac &x) {\n    Frac L(0, 1), R(1, 0), mid(1, 1);\n  \
    \  vector<int> path;\n    for (;;) {\n        if (mid == x)\n            break;\n\
    \        ll k = ceil(x.a * L.b - x.b * L.a, x.b * R.a - x.a * R.b) - 1;\n    \
    \    L = Frac(L.a + k * R.a, L.b + k * R.b);\n        mid = Frac(L.a + R.a, L.b\
    \ + R.b);\n        path.push_back(k);\n        if (mid == x)\n            break;\n\
    \        k = ceil(x.b * R.a - x.a * R.b, x.a * L.b - x.b * L.a) - 1;\n       \
    \ R = Frac(R.a + k * L.a, R.b + k * L.b);\n        mid = Frac(L.a + R.a, L.b +\
    \ R.b);\n        path.push_back(k);\n    }\n    return {path, {L, R}};\n}\n};\
    \ // namespace SternBrocotTree\n\n/**\n * @brief Stern-Brocot Tree\n */\n"
  dependsOn:
  - Math/fraction.hpp
  isVerificationFile: false
  path: Math/sternbrocot.hpp
  requiredBy: []
  timestamp: '2025-06-05 05:40:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sternbrocot.hpp
layout: document
redirect_from:
- /library/Math/sternbrocot.hpp
- /library/Math/sternbrocot.hpp.html
title: Stern-Brocot Tree
---
