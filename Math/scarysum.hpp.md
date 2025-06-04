---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Scary Sum
    links: []
  bundledCode: "#line 2 \"Math/scarysum.hpp\"\n\n// f(x)=floor(ax+b/m) path product\n\
    template <typename M> M FloorProd(ll n, ll m, ll a, ll b, M x, M y) {\n    M pre,\
    \ suf;\n    for (;;) {\n        x = M::mul(x, M::pow(y, a / m));\n        a %=\
    \ m;\n        pre = M::mul(pre, M::pow(y, b / m));\n        b %= m;\n        ll\
    \ c = (a * n + b);\n        if (c < m) {\n            pre = M::mul(pre, M::pow(x,\
    \ n));\n            break;\n        }\n        suf = M::mul(y, M::mul(M::pow(x,\
    \ (c % m) / a), suf));\n        n = c / m - 1, b = m - b + a - 1;\n        swap(m,\
    \ a);\n        swap(x, y);\n    }\n    return M::mul(pre, suf);\n}\n\ntemplate\
    \ <typename T, int K, int L> struct FloorPolyMonoid {\n    static constexpr int\
    \ N = max(K, L);\n    static inline T C[N + 1][N + 1];\n    static void init()\
    \ {\n        rep(i, 0, N + 1) {\n            C[i][0] = C[i][i] = 1;\n        \
    \    rep(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n        }\n    }\n\
    \n    T sum[K + 1][L + 1] = {};\n    T dx, dy;\n    FloorPolyMonoid() : dx(0),\
    \ dy(0) {}\n\n    static FloorPolyMonoid mul(FloorPolyMonoid a, FloorPolyMonoid\
    \ b) {\n        array<T, K + 1> pwx;\n        array<T, L + 1> pwy;\n        pwx[0]\
    \ = pwy[0] = 1;\n        rep(i, 0, K) pwx[i + 1] = pwx[i] * a.dx;\n        rep(i,\
    \ 0, L) pwy[i + 1] = pwy[i] * a.dy;\n        rep(i, 0, K + 1) {\n            rrep(j,\
    \ 0, L + 1) {\n                rep(k, j + 1, L + 1) b.sum[i][k] +=\n         \
    \           C[k][j] * pwy[k - j] * b.sum[i][j];\n            }\n        }\n  \
    \      rep(j, 0, L + 1) {\n            rrep(i, 0, K + 1) {\n                rep(k,\
    \ i, K + 1) a.sum[k][j] +=\n                    C[k][i] * pwx[k - i] * b.sum[i][j];\n\
    \            }\n        }\n        a.dx += b.dx;\n        a.dy += b.dy;\n    \
    \    return a;\n    }\n    static FloorPolyMonoid pow(FloorPolyMonoid a, ll n)\
    \ {\n        FloorPolyMonoid ret, base = a;\n        while (n) {\n           \
    \ if (n & 1) {\n                ret = mul(ret, base);\n            }\n       \
    \     base = mul(base, base);\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n    static FloorPolyMonoid to_dx() {\n        FloorPolyMonoid ret;\n\
    \        ret.sum[0][0] = 1, ret.dx = 1;\n        return ret;\n    }\n    static\
    \ FloorPolyMonoid to_dy() {\n        FloorPolyMonoid ret;\n        ret.dy = 1;\n\
    \        return ret;\n    }\n};\n\ntemplate <typename T, int K, int L>\nvector<vector<T>>\
    \ ScarySum(ll n, ll m, ll a, ll b) {\n    vector ret(K + 1, vector<T>(L + 1));\n\
    \    if (n <= 0)\n        return ret;\n    if (m < 0) {\n        m = -m, a = -a,\
    \ b = -b;\n    }\n    if (a < 0) {\n        b = m - 1 - b;\n    }\n    ll quo\
    \ = floor(b, m), rem = b - quo * m;\n    using M = FloorPolyMonoid<T, K, L>;\n\
    \    M::init();\n    auto base = FloorProd<M>(n, m, llabs(a), rem, M::to_dx(),\
    \ M::to_dy());\n    M offset;\n    offset.dy = quo;\n    base = M::mul(offset,\
    \ base);\n\n    rep(i, 0, K + 1) rep(j, 0, L + 1) ret[i][j] = base.sum[i][j];\n\
    \n    if (a < 0) {\n        rep(i, 0, K + 1) rep(j, 0, L + 1) if (j & 1) ret[i][j]\
    \ = -ret[i][j];\n    }\n    return ret;\n}\n\n/**\n * @brief Scary Sum\n */\n"
  code: "#pragma once\n\n// f(x)=floor(ax+b/m) path product\ntemplate <typename M>\
    \ M FloorProd(ll n, ll m, ll a, ll b, M x, M y) {\n    M pre, suf;\n    for (;;)\
    \ {\n        x = M::mul(x, M::pow(y, a / m));\n        a %= m;\n        pre =\
    \ M::mul(pre, M::pow(y, b / m));\n        b %= m;\n        ll c = (a * n + b);\n\
    \        if (c < m) {\n            pre = M::mul(pre, M::pow(x, n));\n        \
    \    break;\n        }\n        suf = M::mul(y, M::mul(M::pow(x, (c % m) / a),\
    \ suf));\n        n = c / m - 1, b = m - b + a - 1;\n        swap(m, a);\n   \
    \     swap(x, y);\n    }\n    return M::mul(pre, suf);\n}\n\ntemplate <typename\
    \ T, int K, int L> struct FloorPolyMonoid {\n    static constexpr int N = max(K,\
    \ L);\n    static inline T C[N + 1][N + 1];\n    static void init() {\n      \
    \  rep(i, 0, N + 1) {\n            C[i][0] = C[i][i] = 1;\n            rep(j,\
    \ 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n        }\n    }\n\n    T sum[K\
    \ + 1][L + 1] = {};\n    T dx, dy;\n    FloorPolyMonoid() : dx(0), dy(0) {}\n\n\
    \    static FloorPolyMonoid mul(FloorPolyMonoid a, FloorPolyMonoid b) {\n    \
    \    array<T, K + 1> pwx;\n        array<T, L + 1> pwy;\n        pwx[0] = pwy[0]\
    \ = 1;\n        rep(i, 0, K) pwx[i + 1] = pwx[i] * a.dx;\n        rep(i, 0, L)\
    \ pwy[i + 1] = pwy[i] * a.dy;\n        rep(i, 0, K + 1) {\n            rrep(j,\
    \ 0, L + 1) {\n                rep(k, j + 1, L + 1) b.sum[i][k] +=\n         \
    \           C[k][j] * pwy[k - j] * b.sum[i][j];\n            }\n        }\n  \
    \      rep(j, 0, L + 1) {\n            rrep(i, 0, K + 1) {\n                rep(k,\
    \ i, K + 1) a.sum[k][j] +=\n                    C[k][i] * pwx[k - i] * b.sum[i][j];\n\
    \            }\n        }\n        a.dx += b.dx;\n        a.dy += b.dy;\n    \
    \    return a;\n    }\n    static FloorPolyMonoid pow(FloorPolyMonoid a, ll n)\
    \ {\n        FloorPolyMonoid ret, base = a;\n        while (n) {\n           \
    \ if (n & 1) {\n                ret = mul(ret, base);\n            }\n       \
    \     base = mul(base, base);\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n    static FloorPolyMonoid to_dx() {\n        FloorPolyMonoid ret;\n\
    \        ret.sum[0][0] = 1, ret.dx = 1;\n        return ret;\n    }\n    static\
    \ FloorPolyMonoid to_dy() {\n        FloorPolyMonoid ret;\n        ret.dy = 1;\n\
    \        return ret;\n    }\n};\n\ntemplate <typename T, int K, int L>\nvector<vector<T>>\
    \ ScarySum(ll n, ll m, ll a, ll b) {\n    vector ret(K + 1, vector<T>(L + 1));\n\
    \    if (n <= 0)\n        return ret;\n    if (m < 0) {\n        m = -m, a = -a,\
    \ b = -b;\n    }\n    if (a < 0) {\n        b = m - 1 - b;\n    }\n    ll quo\
    \ = floor(b, m), rem = b - quo * m;\n    using M = FloorPolyMonoid<T, K, L>;\n\
    \    M::init();\n    auto base = FloorProd<M>(n, m, llabs(a), rem, M::to_dx(),\
    \ M::to_dy());\n    M offset;\n    offset.dy = quo;\n    base = M::mul(offset,\
    \ base);\n\n    rep(i, 0, K + 1) rep(j, 0, L + 1) ret[i][j] = base.sum[i][j];\n\
    \n    if (a < 0) {\n        rep(i, 0, K + 1) rep(j, 0, L + 1) if (j & 1) ret[i][j]\
    \ = -ret[i][j];\n    }\n    return ret;\n}\n\n/**\n * @brief Scary Sum\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/scarysum.hpp
  requiredBy: []
  timestamp: '2025-06-05 05:40:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/scarysum.hpp
layout: document
redirect_from:
- /library/Math/scarysum.hpp
- /library/Math/scarysum.hpp.html
title: Scary Sum
---
