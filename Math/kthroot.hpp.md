---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Kth Root(Integer)
    links: []
  bundledCode: "#line 2 \"Math/kthroot.hpp\"\n\nuint64_t integer_kth_root(uint64_t\
    \ k, uint64_t a) {\n    assert(k >= 1);\n    if (a == 0 || a == 1 || k == 1) return\
    \ a;\n    if (k >= 64) return 1;\n    if (k == 2) return sqrtl(a);\n    if (a\
    \ == uint64_t(-1)) --a;\n    struct S {\n        uint64_t v;\n        S& operator*=(const\
    \ S& o) {\n            v = v <= uint64_t(-1) / o.v ? v * o.v : uint64_t(-1);\n\
    \            return *this;\n        }\n    };\n    auto power = [&](S x, ll n)\
    \ -> S {\n        S v{1};\n        while (n) {\n            if (n & 1) v *= x;\n\
    \            x *= x;\n            n /= 2;\n        }\n        return v;\n    };\n\
    \    uint64_t res = pow(a, nextafter(1 / double(k), 0));\n    while (power(S{res\
    \ + 1}, k).v <= a) ++res;\n    return res;\n}\n\n/**\n * @brief Kth Root(Integer)\n\
    */\n"
  code: "#pragma once\n\nuint64_t integer_kth_root(uint64_t k, uint64_t a) {\n   \
    \ assert(k >= 1);\n    if (a == 0 || a == 1 || k == 1) return a;\n    if (k >=\
    \ 64) return 1;\n    if (k == 2) return sqrtl(a);\n    if (a == uint64_t(-1))\
    \ --a;\n    struct S {\n        uint64_t v;\n        S& operator*=(const S& o)\
    \ {\n            v = v <= uint64_t(-1) / o.v ? v * o.v : uint64_t(-1);\n     \
    \       return *this;\n        }\n    };\n    auto power = [&](S x, ll n) -> S\
    \ {\n        S v{1};\n        while (n) {\n            if (n & 1) v *= x;\n  \
    \          x *= x;\n            n /= 2;\n        }\n        return v;\n    };\n\
    \    uint64_t res = pow(a, nextafter(1 / double(k), 0));\n    while (power(S{res\
    \ + 1}, k).v <= a) ++res;\n    return res;\n}\n\n/**\n * @brief Kth Root(Integer)\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Math/kthroot.hpp
  requiredBy: []
  timestamp: '2022-12-26 23:10:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/kthroot.hpp
layout: document
redirect_from:
- /library/Math/kthroot.hpp
- /library/Math/kthroot.hpp.html
title: Kth Root(Integer)
---
