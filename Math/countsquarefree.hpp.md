---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/kthroot.hpp
    title: Kth Root(Integer)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Count Square-free integers
    links: []
  bundledCode: "#line 2 \"Math/kthroot.hpp\"\n\nuint64_t Kthroot(uint64_t k, uint64_t\
    \ a) {\n    assert(k >= 1);\n    if (a == 0 || a == 1 || k == 1) return a;\n \
    \   if (k >= 64) return 1;\n    if (k == 2) return sqrtl(a);\n    if (a == uint64_t(-1))\
    \ --a;\n    struct S {\n        uint64_t v;\n        S& operator*=(const S& o)\
    \ {\n            v = v <= uint64_t(-1) / o.v ? v * o.v : uint64_t(-1);\n     \
    \       return *this;\n        }\n    };\n    auto power = [&](S x, ll n) -> S\
    \ {\n        S v{1};\n        while (n) {\n            if (n & 1) v *= x;\n  \
    \          x *= x;\n            n /= 2;\n        }\n        return v;\n    };\n\
    \    uint64_t res = pow(a, nextafter(1 / double(k), 0));\n    while (power(S{res\
    \ + 1}, k).v <= a) ++res;\n    return res;\n}\n\n/**\n * @brief Kth Root(Integer)\n\
    */\n#line 3 \"Math/countsquarefree.hpp\"\n\nll CountSquarefree(ll n) {\n    if\
    \ (n <= 3)\n        return n;\n    const int I = Kthroot(n, 5);\n    const int\
    \ D = sqrtl(n / I);\n    vector<int> prime(D + 1, 1), mobius(D + 1);\n    mobius[1]\
    \ = 1;\n    rep(i, 2, D + 1) if (prime[i]) {\n        for (int j = D / i; j >=\
    \ 1; j--) {\n            if (j >= i and prime[j])\n                prime[i * j]\
    \ = 0;\n            if (mobius[j])\n                mobius[i * j] = -mobius[j];\n\
    \        }\n    }\n\n    ll ret = 0;\n    rep(i, 1, D + 1) ret += mobius[i] *\
    \ (n / (ll(i) * i));\n\n    auto mertens = mobius;\n    rep(i, 0, D) mertens[i\
    \ + 1] += mertens[i];\n\n    vector<ll> Mxi(I);\n    for (int i = I - 1; i >=\
    \ 1; i--) {\n        const int xi = sqrtl(n / i);\n        const int sqxi = sqrtl(xi);\n\
    \        Mxi[i] = 1;\n        rep(j, 2, sqxi + 1) {\n            if (xi / j <=\
    \ D)\n                Mxi[i] -= mertens[xi / j];\n            else\n         \
    \       Mxi[i] -= Mxi[i * j * j];\n        }\n        rep(j, 1, xi / (sqxi + 1)\
    \ + 1) Mxi[i] -=\n            (xi / j - xi / (j + 1)) * mertens[j];\n        ret\
    \ += Mxi[i];\n    }\n    ret -= ll(I - 1) * mertens[D];\n    return ret;\n}\n\n\
    /**\n * @brief Count Square-free integers\n */\n"
  code: "#pragma once\n#include \"Math/kthroot.hpp\"\n\nll CountSquarefree(ll n) {\n\
    \    if (n <= 3)\n        return n;\n    const int I = Kthroot(n, 5);\n    const\
    \ int D = sqrtl(n / I);\n    vector<int> prime(D + 1, 1), mobius(D + 1);\n   \
    \ mobius[1] = 1;\n    rep(i, 2, D + 1) if (prime[i]) {\n        for (int j = D\
    \ / i; j >= 1; j--) {\n            if (j >= i and prime[j])\n                prime[i\
    \ * j] = 0;\n            if (mobius[j])\n                mobius[i * j] = -mobius[j];\n\
    \        }\n    }\n\n    ll ret = 0;\n    rep(i, 1, D + 1) ret += mobius[i] *\
    \ (n / (ll(i) * i));\n\n    auto mertens = mobius;\n    rep(i, 0, D) mertens[i\
    \ + 1] += mertens[i];\n\n    vector<ll> Mxi(I);\n    for (int i = I - 1; i >=\
    \ 1; i--) {\n        const int xi = sqrtl(n / i);\n        const int sqxi = sqrtl(xi);\n\
    \        Mxi[i] = 1;\n        rep(j, 2, sqxi + 1) {\n            if (xi / j <=\
    \ D)\n                Mxi[i] -= mertens[xi / j];\n            else\n         \
    \       Mxi[i] -= Mxi[i * j * j];\n        }\n        rep(j, 1, xi / (sqxi + 1)\
    \ + 1) Mxi[i] -=\n            (xi / j - xi / (j + 1)) * mertens[j];\n        ret\
    \ += Mxi[i];\n    }\n    ret -= ll(I - 1) * mertens[D];\n    return ret;\n}\n\n\
    /**\n * @brief Count Square-free integers\n */"
  dependsOn:
  - Math/kthroot.hpp
  isVerificationFile: false
  path: Math/countsquarefree.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/countsquarefree.hpp
layout: document
redirect_from:
- /library/Math/countsquarefree.hpp
- /library/Math/countsquarefree.hpp.html
title: Count Square-free integers
---
