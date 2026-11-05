---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_nim_product_64.test.cpp
    title: Verify/LC_nim_product_64.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Nimber
    links: []
  bundledCode: "#line 2 \"Math/nimber.hpp\"\n\r\nusing ull = unsigned long long;\r\
    \nnamespace NimberManager {\r\nunsigned short E[65536 * 2 + 7], L[65536];\r\n\
    inline void __attribute__((constructor)) init() {\r\n    unsigned short c[] =\
    \ {10279, 15417, 35722, 52687, 44124, 62628,\r\n                          15661,\
    \ 5686,  3862,  1323,  334,   647,\r\n                          61560, 20636,\
    \ 4267,  8445};\r\n    unsigned short d[65536];\r\n    for (int i = 0; i < 16;\
    \ ++i)\r\n        for (int j = 1 << i; j--;)\r\n            d[1 << i | j] = d[j]\
    \ ^ c[i];\r\n    E[0] = 1;\r\n    for (int i = 0; i < 65534; ++i)\r\n        E[i\
    \ + 1] = d[E[i]];\r\n    memcpy(E + 65535, E, 131070), memcpy(E + 131070, E, 14);\r\
    \n    for (int i = 0; i < 65535; ++i)\r\n        L[E[i]] = i;\r\n}\r\ninline uint\
    \ mul16(const uint &x, const uint &y) {\r\n    return x && y ? E[uint(L[x]) +\
    \ L[y]] : 0;\r\n}\r\ninline uint mul16_15(const uint &x, const uint &y) {\r\n\
    \    return x && y ? E[uint(L[x]) + L[y] + 3] : 0;\r\n}\r\ninline uint mul15_15(const\
    \ uint &x, const uint &y) {\r\n    return x && y ? E[uint(L[x]) + L[y] + 6] :\
    \ 0;\r\n}\r\ninline uint mul15(const uint &x) {\r\n    return x ? E[L[x] + 3]\
    \ : 0;\r\n}\r\ninline uint mul(const uint &x, const uint &y) {\r\n    const uint\
    \ xh = x >> 16, xl = x & 65535, yh = y >> 16, yl = y & 65535,\r\n            \
    \   c = mul16(xl, yl);\r\n    return (ull)(mul16(xl ^ xh, yl ^ yh) ^ c) << 16\
    \ | (mul16_15(xh, yh) ^ c);\r\n}\r\ninline uint mul32_31(const uint &x, const\
    \ uint &y) {\r\n    const uint xh = x >> 16, xl = x & 65535, yh = y >> 16, yl\
    \ = y & 65535,\r\n               c = mul16_15(xl ^ xh, yl ^ yh);\r\n    return\
    \ (ull)(c ^ mul15_15(xh, yh)) << 16 | mul15(mul16_15(xl, yl) ^ c);\r\n}\r\ninline\
    \ ull mul(const ull &x, const ull &y) {\r\n    const uint xh = x >> 32, xl = x\
    \ & UINT_MAX, yh = y >> 32, yl = y & UINT_MAX,\r\n               c = mul(xl, yl);\r\
    \n    return (ull)(mul(xl ^ xh, yl ^ yh) ^ c) << 32 | (mul32_31(xh, yh) ^ c);\r\
    \n}\r\n}; // namespace NimberManager\r\nstruct Nimber {\r\n    ull v;\r\n    Nimber(ull\
    \ _v = 0) : v(_v) {}\r\n    Nimber &operator+=(const Nimber &x) {\r\n        v\
    \ ^= x.v;\r\n        return *this;\r\n    }\r\n    Nimber &operator-=(const Nimber\
    \ &x) {\r\n        v ^= x.v;\r\n        return *this;\r\n    }\r\n    Nimber &operator*=(const\
    \ Nimber &x) {\r\n        v = NimberManager::mul(v, x.v);\r\n        return *this;\r\
    \n    }\r\n    Nimber operator+(const Nimber &x) const {\r\n        return Nimber(*this)\
    \ += x;\r\n    }\r\n    Nimber operator-(const Nimber &x) const {\r\n        return\
    \ Nimber(*this) -= x;\r\n    }\r\n    Nimber operator*(const Nimber &x) const\
    \ {\r\n        return Nimber(*this) *= x;\r\n    }\r\n    bool operator==(const\
    \ Nimber &x) const {\r\n        return v == x.v;\r\n    }\r\n    bool operator!=(const\
    \ Nimber &x) const {\r\n        return v != x.v;\r\n    }\r\n    Nimber pow(ull\
    \ t) {\r\n        Nimber res = 1, b = *this;\r\n        while (t) {\r\n      \
    \      if (t & 1)\r\n                res *= b;\r\n            b *= b;\r\n    \
    \        t >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    Nimber inv()\
    \ { // \u66AB\u5B9A\r\n        return pow(ull(-2));\r\n    }\r\n    friend istream\
    \ &operator>>(istream &is, Nimber &x) {\r\n        return is >> x.v;\r\n    }\r\
    \n    friend ostream &operator<<(ostream &os, const Nimber &x) {\r\n        return\
    \ os << x.v;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Nimber\r\n */\n"
  code: "#pragma once\r\n\r\nusing ull = unsigned long long;\r\nnamespace NimberManager\
    \ {\r\nunsigned short E[65536 * 2 + 7], L[65536];\r\ninline void __attribute__((constructor))\
    \ init() {\r\n    unsigned short c[] = {10279, 15417, 35722, 52687, 44124, 62628,\r\
    \n                          15661, 5686,  3862,  1323,  334,   647,\r\n      \
    \                    61560, 20636, 4267,  8445};\r\n    unsigned short d[65536];\r\
    \n    for (int i = 0; i < 16; ++i)\r\n        for (int j = 1 << i; j--;)\r\n \
    \           d[1 << i | j] = d[j] ^ c[i];\r\n    E[0] = 1;\r\n    for (int i =\
    \ 0; i < 65534; ++i)\r\n        E[i + 1] = d[E[i]];\r\n    memcpy(E + 65535, E,\
    \ 131070), memcpy(E + 131070, E, 14);\r\n    for (int i = 0; i < 65535; ++i)\r\
    \n        L[E[i]] = i;\r\n}\r\ninline uint mul16(const uint &x, const uint &y)\
    \ {\r\n    return x && y ? E[uint(L[x]) + L[y]] : 0;\r\n}\r\ninline uint mul16_15(const\
    \ uint &x, const uint &y) {\r\n    return x && y ? E[uint(L[x]) + L[y] + 3] :\
    \ 0;\r\n}\r\ninline uint mul15_15(const uint &x, const uint &y) {\r\n    return\
    \ x && y ? E[uint(L[x]) + L[y] + 6] : 0;\r\n}\r\ninline uint mul15(const uint\
    \ &x) {\r\n    return x ? E[L[x] + 3] : 0;\r\n}\r\ninline uint mul(const uint\
    \ &x, const uint &y) {\r\n    const uint xh = x >> 16, xl = x & 65535, yh = y\
    \ >> 16, yl = y & 65535,\r\n               c = mul16(xl, yl);\r\n    return (ull)(mul16(xl\
    \ ^ xh, yl ^ yh) ^ c) << 16 | (mul16_15(xh, yh) ^ c);\r\n}\r\ninline uint mul32_31(const\
    \ uint &x, const uint &y) {\r\n    const uint xh = x >> 16, xl = x & 65535, yh\
    \ = y >> 16, yl = y & 65535,\r\n               c = mul16_15(xl ^ xh, yl ^ yh);\r\
    \n    return (ull)(c ^ mul15_15(xh, yh)) << 16 | mul15(mul16_15(xl, yl) ^ c);\r\
    \n}\r\ninline ull mul(const ull &x, const ull &y) {\r\n    const uint xh = x >>\
    \ 32, xl = x & UINT_MAX, yh = y >> 32, yl = y & UINT_MAX,\r\n               c\
    \ = mul(xl, yl);\r\n    return (ull)(mul(xl ^ xh, yl ^ yh) ^ c) << 32 | (mul32_31(xh,\
    \ yh) ^ c);\r\n}\r\n}; // namespace NimberManager\r\nstruct Nimber {\r\n    ull\
    \ v;\r\n    Nimber(ull _v = 0) : v(_v) {}\r\n    Nimber &operator+=(const Nimber\
    \ &x) {\r\n        v ^= x.v;\r\n        return *this;\r\n    }\r\n    Nimber &operator-=(const\
    \ Nimber &x) {\r\n        v ^= x.v;\r\n        return *this;\r\n    }\r\n    Nimber\
    \ &operator*=(const Nimber &x) {\r\n        v = NimberManager::mul(v, x.v);\r\n\
    \        return *this;\r\n    }\r\n    Nimber operator+(const Nimber &x) const\
    \ {\r\n        return Nimber(*this) += x;\r\n    }\r\n    Nimber operator-(const\
    \ Nimber &x) const {\r\n        return Nimber(*this) -= x;\r\n    }\r\n    Nimber\
    \ operator*(const Nimber &x) const {\r\n        return Nimber(*this) *= x;\r\n\
    \    }\r\n    bool operator==(const Nimber &x) const {\r\n        return v ==\
    \ x.v;\r\n    }\r\n    bool operator!=(const Nimber &x) const {\r\n        return\
    \ v != x.v;\r\n    }\r\n    Nimber pow(ull t) {\r\n        Nimber res = 1, b =\
    \ *this;\r\n        while (t) {\r\n            if (t & 1)\r\n                res\
    \ *= b;\r\n            b *= b;\r\n            t >>= 1;\r\n        }\r\n      \
    \  return res;\r\n    }\r\n    Nimber inv() { // \u66AB\u5B9A\r\n        return\
    \ pow(ull(-2));\r\n    }\r\n    friend istream &operator>>(istream &is, Nimber\
    \ &x) {\r\n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Nimber &x) {\r\n        return os << x.v;\r\n    }\r\n};\r\n\r\n\
    /**\r\n * @brief Nimber\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/nimber.hpp
  requiredBy: []
  timestamp: '2025-01-28 06:32:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_nim_product_64.test.cpp
documentation_of: Math/nimber.hpp
layout: document
redirect_from:
- /library/Math/nimber.hpp
- /library/Math/nimber.hpp.html
title: Nimber
---
