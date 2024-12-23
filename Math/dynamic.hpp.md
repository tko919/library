---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Fast Division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Dynamic Modint
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv {\n    using u64 =\
    \ unsigned ll;\n    using u128 = __uint128_t;\n    u128 mod, mh, ml;\n    explicit\
    \ FastDiv(u64 mod = 1) : mod(mod) {\n        u128 m = u128(-1) / mod;\n      \
    \  if (m * mod + mod == u128(0))\n            ++m;\n        mh = m >> 64;\n  \
    \      ml = m & u64(-1);\n    }\n    u64 umod() const {\n        return mod;\n\
    \    }\n    u64 modulo(u128 x) {\n        u128 z = (x & u64(-1)) * ml;\n     \
    \   z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n        z = (x >> 64)\
    \ * mh + (z >> 64);\n        x -= z * mod;\n        return x < mod ? x : x - mod;\n\
    \    }\n    u64 mul(u64 a, u64 b) {\n        return modulo(u128(a) * b);\n   \
    \ }\n};\n\n/**\n * @brief Fast Division\n */\n#line 3 \"Math/dynamic.hpp\"\n\r\
    \nstruct Fp {\r\n    using u64 = uint64_t;\r\n    uint v;\r\n    static int get_mod()\
    \ {\r\n        return _getmod();\r\n    }\r\n    static void set_mod(int _m) {\r\
    \n        bar = FastDiv(_m);\r\n    }\r\n    Fp inv() const {\r\n        int tmp,\
    \ a = v, b = get_mod(), x = 1, y = 0;\r\n        while (b) {\r\n            tmp\
    \ = a / b, a -= tmp * b;\r\n            swap(a, b);\r\n            x -= tmp *\
    \ y;\r\n            swap(x, y);\r\n        }\r\n        if (x < 0) {\r\n     \
    \       x += get_mod();\r\n        }\r\n        return x;\r\n    }\r\n    Fp()\
    \ : v(0) {}\r\n    Fp(ll x) {\r\n        v = x % get_mod();\r\n        if (v <\
    \ 0)\r\n            v += get_mod();\r\n    }\r\n    Fp operator-() const {\r\n\
    \        return Fp() - *this;\r\n    }\r\n    Fp pow(ll t) {\r\n        assert(t\
    \ >= 0);\r\n        Fp res = 1, b = *this;\r\n        while (t) {\r\n        \
    \    if (t & 1)\r\n                res *= b;\r\n            b *= b;\r\n      \
    \      t >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    Fp &operator+=(const\
    \ Fp &x) {\r\n        v += x.v;\r\n        if (v >= get_mod())\r\n           \
    \ v -= get_mod();\r\n        return *this;\r\n    }\r\n    Fp &operator-=(const\
    \ Fp &x) {\r\n        v += get_mod() - x.v;\r\n        if (v >= get_mod())\r\n\
    \            v -= get_mod();\r\n        return *this;\r\n    }\r\n    Fp &operator*=(const\
    \ Fp &x) {\r\n        v = (u64(v) * x.v) % bar;\r\n        return *this;\r\n \
    \   }\r\n    Fp &operator/=(const Fp &x) {\r\n        (*this) *= x.inv();\r\n\
    \        return *this;\r\n    }\r\n    Fp operator+(const Fp &x) const {\r\n \
    \       return Fp(*this) += x;\r\n    }\r\n    Fp operator-(const Fp &x) const\
    \ {\r\n        return Fp(*this) -= x;\r\n    }\r\n    Fp operator*(const Fp &x)\
    \ const {\r\n        return Fp(*this) *= x;\r\n    }\r\n    Fp operator/(const\
    \ Fp &x) const {\r\n        return Fp(*this) /= x;\r\n    }\r\n    bool operator==(const\
    \ Fp &x) const {\r\n        return v == x.v;\r\n    }\r\n    bool operator!=(const\
    \ Fp &x) const {\r\n        return v != x.v;\r\n    }\r\n    friend istream &operator>>(istream\
    \ &is, Fp &x) {\r\n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Fp &x) {\r\n        return os << x.v;\r\n    }\r\n\r\n  private:\r\
    \n    static FastDiv bar;\r\n    static int _getmod() {\r\n        return bar.get();\r\
    \n    }\r\n};\r\nFastDiv Fp::bar(998244353);\r\n\r\nvoid rd(Fp &x) {\r\n    fastio::rd(x.v);\r\
    \n}\r\nvoid wt(Fp x) {\r\n    fastio::wt(x.v);\r\n}\r\n\r\n/**\r\n * @brief Dynamic\
    \ Modint\r\n */\n"
  code: "#pragma once\r\n#include \"Math/fastdiv.hpp\"\r\n\r\nstruct Fp {\r\n    using\
    \ u64 = uint64_t;\r\n    uint v;\r\n    static int get_mod() {\r\n        return\
    \ _getmod();\r\n    }\r\n    static void set_mod(int _m) {\r\n        bar = FastDiv(_m);\r\
    \n    }\r\n    Fp inv() const {\r\n        int tmp, a = v, b = get_mod(), x =\
    \ 1, y = 0;\r\n        while (b) {\r\n            tmp = a / b, a -= tmp * b;\r\
    \n            swap(a, b);\r\n            x -= tmp * y;\r\n            swap(x,\
    \ y);\r\n        }\r\n        if (x < 0) {\r\n            x += get_mod();\r\n\
    \        }\r\n        return x;\r\n    }\r\n    Fp() : v(0) {}\r\n    Fp(ll x)\
    \ {\r\n        v = x % get_mod();\r\n        if (v < 0)\r\n            v += get_mod();\r\
    \n    }\r\n    Fp operator-() const {\r\n        return Fp() - *this;\r\n    }\r\
    \n    Fp pow(ll t) {\r\n        assert(t >= 0);\r\n        Fp res = 1, b = *this;\r\
    \n        while (t) {\r\n            if (t & 1)\r\n                res *= b;\r\
    \n            b *= b;\r\n            t >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n    Fp &operator+=(const Fp &x) {\r\n        v += x.v;\r\n        if\
    \ (v >= get_mod())\r\n            v -= get_mod();\r\n        return *this;\r\n\
    \    }\r\n    Fp &operator-=(const Fp &x) {\r\n        v += get_mod() - x.v;\r\
    \n        if (v >= get_mod())\r\n            v -= get_mod();\r\n        return\
    \ *this;\r\n    }\r\n    Fp &operator*=(const Fp &x) {\r\n        v = (u64(v)\
    \ * x.v) % bar;\r\n        return *this;\r\n    }\r\n    Fp &operator/=(const\
    \ Fp &x) {\r\n        (*this) *= x.inv();\r\n        return *this;\r\n    }\r\n\
    \    Fp operator+(const Fp &x) const {\r\n        return Fp(*this) += x;\r\n \
    \   }\r\n    Fp operator-(const Fp &x) const {\r\n        return Fp(*this) -=\
    \ x;\r\n    }\r\n    Fp operator*(const Fp &x) const {\r\n        return Fp(*this)\
    \ *= x;\r\n    }\r\n    Fp operator/(const Fp &x) const {\r\n        return Fp(*this)\
    \ /= x;\r\n    }\r\n    bool operator==(const Fp &x) const {\r\n        return\
    \ v == x.v;\r\n    }\r\n    bool operator!=(const Fp &x) const {\r\n        return\
    \ v != x.v;\r\n    }\r\n    friend istream &operator>>(istream &is, Fp &x) {\r\
    \n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Fp &x) {\r\n        return os << x.v;\r\n    }\r\n\r\n  private:\r\
    \n    static FastDiv bar;\r\n    static int _getmod() {\r\n        return bar.get();\r\
    \n    }\r\n};\r\nFastDiv Fp::bar(998244353);\r\n\r\nvoid rd(Fp &x) {\r\n    fastio::rd(x.v);\r\
    \n}\r\nvoid wt(Fp x) {\r\n    fastio::wt(x.v);\r\n}\r\n\r\n/**\r\n * @brief Dynamic\
    \ Modint\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  isVerificationFile: false
  path: Math/dynamic.hpp
  requiredBy: []
  timestamp: '2024-12-24 03:24:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
documentation_of: Math/dynamic.hpp
layout: document
redirect_from:
- /library/Math/dynamic.hpp
- /library/Math/dynamic.hpp.html
title: Dynamic Modint
---
