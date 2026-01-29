---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/rollinghash.hpp
    title: Rolling Hash
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Hash
    links: []
  bundledCode: "#line 2 \"Math/hash.hpp\"\n\nstruct Hash {\n    static constexpr ull\
    \ mod = 0x1fffffffffffffff;\n    ull v;\n    static constexpr ull get_mod() {\n\
    \        return mod;\n    }\n    Hash inv() const {\n        return pow(mod -\
    \ 2);\n    }\n    constexpr Hash(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x)\
    \ % mod) % mod) {}\n    Hash operator-() const {\n        return Hash() - *this;\n\
    \    }\n    Hash pow(ull t) const {\n        Hash res = 1, b = *this;\n      \
    \  while (t) {\n            if (t & 1)\n                res *= b;\n          \
    \  b *= b;\n            t >>= 1;\n        }\n        return res;\n    }\n    Hash\
    \ &operator+=(const Hash &x) {\n        if ((v += x.v) >= mod)\n            v\
    \ -= mod;\n        return *this;\n    }\n    Hash &operator-=(const Hash &x) {\n\
    \        if ((v += mod - x.v) >= mod)\n            v -= mod;\n        return *this;\n\
    \    }\n    Hash &operator*=(const Hash &x) {\n        u128 ans = u128(v) * x.v;\n\
    \        ans = (ans >> 61) + (ans & mod);\n        if (ans >= mod)\n         \
    \   ans -= mod;\n        v = ans;\n        return *this;\n    }\n    Hash &operator/=(const\
    \ Hash &x) {\n        u128 ans = u128(v) * x.inv().v;\n        ans = (ans >> 61)\
    \ + (ans & mod);\n        if (ans >= mod)\n            ans -= mod;\n        v\
    \ = ans;\n        return *this;\n    }\n    Hash operator+(const Hash &x) const\
    \ {\n        return Hash(*this) += x;\n    }\n    Hash operator-(const Hash &x)\
    \ const {\n        return Hash(*this) -= x;\n    }\n    Hash operator*(const Hash\
    \ &x) const {\n        return Hash(*this) *= x;\n    }\n    Hash operator/(const\
    \ Hash &x) const {\n        return Hash(*this) /= x;\n    }\n    bool operator==(const\
    \ Hash &x) const {\n        return v == x.v;\n    }\n    bool operator!=(const\
    \ Hash &x) const {\n        return v != x.v;\n    }\n    // map\u306B\u8F09\u305B\
    \u308B\u6642\u7528\n    bool operator<(const Hash &x) const {\n        return\
    \ v < x.v;\n    }\n    bool operator<=(const Hash &x) const {\n        return\
    \ v <= x.v;\n    }\n    bool operator>(const Hash &x) const {\n        return\
    \ v > x.v;\n    }\n    bool operator>=(const Hash &x) const {\n        return\
    \ v >= x.v;\n    }\n    friend istream &operator>>(istream &is, Hash &x) {\n \
    \       return is >> x.v;\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const Hash &x) {\n        return os << x.v;\n    }\n};\n\n/**\n * @brief Hash\n\
    \ */\n"
  code: "#pragma once\n\nstruct Hash {\n    static constexpr ull mod = 0x1fffffffffffffff;\n\
    \    ull v;\n    static constexpr ull get_mod() {\n        return mod;\n    }\n\
    \    Hash inv() const {\n        return pow(mod - 2);\n    }\n    constexpr Hash(ll\
    \ x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\n    Hash operator-()\
    \ const {\n        return Hash() - *this;\n    }\n    Hash pow(ull t) const {\n\
    \        Hash res = 1, b = *this;\n        while (t) {\n            if (t & 1)\n\
    \                res *= b;\n            b *= b;\n            t >>= 1;\n      \
    \  }\n        return res;\n    }\n    Hash &operator+=(const Hash &x) {\n    \
    \    if ((v += x.v) >= mod)\n            v -= mod;\n        return *this;\n  \
    \  }\n    Hash &operator-=(const Hash &x) {\n        if ((v += mod - x.v) >= mod)\n\
    \            v -= mod;\n        return *this;\n    }\n    Hash &operator*=(const\
    \ Hash &x) {\n        u128 ans = u128(v) * x.v;\n        ans = (ans >> 61) + (ans\
    \ & mod);\n        if (ans >= mod)\n            ans -= mod;\n        v = ans;\n\
    \        return *this;\n    }\n    Hash &operator/=(const Hash &x) {\n       \
    \ u128 ans = u128(v) * x.inv().v;\n        ans = (ans >> 61) + (ans & mod);\n\
    \        if (ans >= mod)\n            ans -= mod;\n        v = ans;\n        return\
    \ *this;\n    }\n    Hash operator+(const Hash &x) const {\n        return Hash(*this)\
    \ += x;\n    }\n    Hash operator-(const Hash &x) const {\n        return Hash(*this)\
    \ -= x;\n    }\n    Hash operator*(const Hash &x) const {\n        return Hash(*this)\
    \ *= x;\n    }\n    Hash operator/(const Hash &x) const {\n        return Hash(*this)\
    \ /= x;\n    }\n    bool operator==(const Hash &x) const {\n        return v ==\
    \ x.v;\n    }\n    bool operator!=(const Hash &x) const {\n        return v !=\
    \ x.v;\n    }\n    // map\u306B\u8F09\u305B\u308B\u6642\u7528\n    bool operator<(const\
    \ Hash &x) const {\n        return v < x.v;\n    }\n    bool operator<=(const\
    \ Hash &x) const {\n        return v <= x.v;\n    }\n    bool operator>(const\
    \ Hash &x) const {\n        return v > x.v;\n    }\n    bool operator>=(const\
    \ Hash &x) const {\n        return v >= x.v;\n    }\n    friend istream &operator>>(istream\
    \ &is, Hash &x) {\n        return is >> x.v;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const Hash &x) {\n        return os << x.v;\n    }\n};\n\n/**\n * @brief\
    \ Hash\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/hash.hpp
  requiredBy:
  - String/rollinghash.hpp
  timestamp: '2026-01-30 05:37:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/hash.hpp
layout: document
redirect_from:
- /library/Math/hash.hpp
- /library/Math/hash.hpp.html
title: Hash
---
