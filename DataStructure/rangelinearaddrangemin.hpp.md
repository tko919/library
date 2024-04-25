---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Range Linear Add Range Min
    links: []
  bundledCode: "#line 2 \"DataStructure/rangelinearaddrangemin.hpp\"\nstruct RangeLinearAddRangeMin\
    \ {\n    RangeLinearAddRangeMin() {}\n    template <typename T> RangeLinearAddRangeMin(vector<T>\
    \ &a) {\n        n = 1, height = 0;\n        while (n < SZ(a))\n            n\
    \ <<= 1, height++;\n        base.resize(n * 2);\n        lazy.resize(n * 2);\n\
    \        bridges.resize(n * 2);\n        rep(i, n, n * 2) base[i] = P(i - n, 1000000000000LL);\n\
    \        rep(i, 0, SZ(a)) base[i + n] = P(i, a[i]);\n        rep(i, 0, n * 2)\
    \ lazy[i] = Linear{0, 0};\n        rep(i, n, n * 2) bridges[i] = {base[i], base[i]};\n\
    \        for (int i = n - 1; i >= 1; i--)\n            find(i);\n    }\n    void\
    \ update(int L, int R, ll a, ll b) {\n        int lb = L + n, rb = R + n;\n  \
    \      while (lb < rb) {\n            if (lb & 1) {\n                lazy[lb]\
    \ = merge(lazy[lb], Linear{a, b});\n                lb++;\n            }\n   \
    \         lb >>= 1;\n            if (rb & 1) {\n                rb--;\n      \
    \          lazy[rb] = merge(lazy[rb], Linear{a, b});\n            }\n        \
    \    rb >>= 1;\n        }\n        lb = L + n, rb = R + n;\n        for (int i\
    \ = 1; i <= height; i++) {\n            if (((lb >> i) << i) != lb)\n        \
    \        find(lb >> i);\n            if (((rb >> i) << i) != rb)\n           \
    \     find((rb - 1) >> i);\n        }\n    }\n    ll query(int L, int R) {\n \
    \       int lb = L + n, rb = R + n;\n        ll ret = INF;\n        while (lb\
    \ < rb) {\n            if (lb & 1) {\n                chmin(ret, subtree(lb));\n\
    \                lb++;\n            }\n            lb >>= 1;\n            if (rb\
    \ & 1) {\n                rb--;\n                chmin(ret, subtree(rb));\n  \
    \          }\n            rb >>= 1;\n        }\n        return ret;\n    }\n\n\
    \  private:\n    struct P {\n        ll x, y;\n        P(ll _x = 0, ll _y = 0)\
    \ : x(_x), y(_y) {}\n        P operator+(const P &p) const {\n            return\
    \ P(x + p.x, y + p.y);\n        }\n        P operator-(const P &p) const {\n \
    \           return P(x - p.x, y - p.y);\n        }\n        bool operator<(const\
    \ P &p) const {\n            return (y != p.y ? y < p.y : x < p.x);\n        }\n\
    \        bool operator==(const P &p) const {\n            return (x == p.x and\
    \ y == p.y);\n        }\n        bool operator!=(const P &p) const {\n       \
    \     return (x != p.x or y != p.y);\n        }\n    };\n    i128 cross(const\
    \ P &a, const P &b) {\n        return i128(a.x) * b.y - i128(a.y) * b.x;\n   \
    \ }\n\n    int n, height;\n    using Linear = pair<ll, ll>;\n    using B = pair<P,\
    \ P>;\n    vector<P> base;\n    vector<Linear> lazy;\n    vector<B> bridges;\n\
    \n    void find(int i) {\n        if (i >= n)\n            return;\n        Linear\
    \ offset = {0, 0};\n        for (int x = i; x; x >>= 1)\n            offset =\
    \ merge(offset, lazy[x]);\n\n        int lb = i * 2, rb = i * 2 + 1;\n       \
    \ int border = rb;\n        while (border < n)\n            border <<= 1;\n  \
    \      border -= n;\n        Linear Ladd = lazy[lb], Radd = lazy[rb];\n      \
    \  for (;;) {\n            // cerr<<i<<' '<<lb<<' '<<rb<<'\\n';\n            if\
    \ (lb >= n and rb >= n)\n                break;\n            P a = bridges[lb].first,\
    \ b = bridges[lb].second;\n            P c = bridges[rb].first, d = bridges[rb].second;\n\
    \            a = apply(a, offset);\n            b = apply(b, offset);\n      \
    \      c = apply(c, offset);\n            d = apply(d, offset);\n            a\
    \ = apply(a, Ladd);\n            b = apply(b, Ladd);\n            c = apply(c,\
    \ Radd);\n            d = apply(d, Radd);\n\n            if (a != b and cross(b\
    \ - a, c - a) < 0) {\n                lb = lb * 2;\n                Ladd = merge(Ladd,\
    \ lazy[lb]);\n            } else if (c != d and cross(c - b, d - b) < 0) {\n \
    \               rb = rb * 2 + 1;\n                Radd = merge(Radd, lazy[rb]);\n\
    \            } else if (a == b) {\n                rb = rb * 2;\n            \
    \    Radd = merge(Radd, lazy[rb]);\n            } else if (c == d) {\n       \
    \         lb = lb * 2 + 1;\n                Ladd = merge(Ladd, lazy[lb]);\n  \
    \          } else {\n                i128 c1 = cross(b - a, d - c);\n        \
    \        i128 c2 = cross(b - a, b - c);\n                bool side;\n        \
    \        if (c1 == 0 and c2 == 0)\n                    side = (c.x < border);\n\
    \                else\n                    side = (c.x * c1 + (d.x - c.x) * c2\
    \ < c1 * border);\n\n                if (side) {\n                    lb = lb\
    \ * 2 + 1;\n                    Ladd = merge(Ladd, lazy[lb]);\n              \
    \  } else {\n                    rb = rb * 2;\n                    Radd = merge(Radd,\
    \ lazy[rb]);\n                }\n            }\n        }\n        bridges[i]\
    \ = {apply(base[lb], Ladd), apply(base[rb], Radd)};\n    }\n    ll subtree(int\
    \ i) {\n        Linear add = {0, 0};\n        for (int x = i; x; x >>= 1)\n  \
    \          add = merge(add, lazy[x]);\n        while (i < n) {\n            if\
    \ (apply(bridges[i].first, add).y <\n                apply(bridges[i].second,\
    \ add).y)\n                i = i * 2;\n            else\n                i = i\
    \ * 2 + 1;\n            add = merge(add, lazy[i]);\n        }\n        P ret =\
    \ apply(base[i], add);\n        return ret.y;\n    }\n    Linear merge(Linear\
    \ a, Linear b) {\n        a.first += b.first;\n        a.second += b.second;\n\
    \        return a;\n    }\n    P apply(P a, Linear b) {\n        a.y += a.x *\
    \ b.first + b.second;\n        return a;\n    }\n};\n\n/**\n * @brief Range Linear\
    \ Add Range Min\n */\n"
  code: "#pragma once\nstruct RangeLinearAddRangeMin {\n    RangeLinearAddRangeMin()\
    \ {}\n    template <typename T> RangeLinearAddRangeMin(vector<T> &a) {\n     \
    \   n = 1, height = 0;\n        while (n < SZ(a))\n            n <<= 1, height++;\n\
    \        base.resize(n * 2);\n        lazy.resize(n * 2);\n        bridges.resize(n\
    \ * 2);\n        rep(i, n, n * 2) base[i] = P(i - n, 1000000000000LL);\n     \
    \   rep(i, 0, SZ(a)) base[i + n] = P(i, a[i]);\n        rep(i, 0, n * 2) lazy[i]\
    \ = Linear{0, 0};\n        rep(i, n, n * 2) bridges[i] = {base[i], base[i]};\n\
    \        for (int i = n - 1; i >= 1; i--)\n            find(i);\n    }\n    void\
    \ update(int L, int R, ll a, ll b) {\n        int lb = L + n, rb = R + n;\n  \
    \      while (lb < rb) {\n            if (lb & 1) {\n                lazy[lb]\
    \ = merge(lazy[lb], Linear{a, b});\n                lb++;\n            }\n   \
    \         lb >>= 1;\n            if (rb & 1) {\n                rb--;\n      \
    \          lazy[rb] = merge(lazy[rb], Linear{a, b});\n            }\n        \
    \    rb >>= 1;\n        }\n        lb = L + n, rb = R + n;\n        for (int i\
    \ = 1; i <= height; i++) {\n            if (((lb >> i) << i) != lb)\n        \
    \        find(lb >> i);\n            if (((rb >> i) << i) != rb)\n           \
    \     find((rb - 1) >> i);\n        }\n    }\n    ll query(int L, int R) {\n \
    \       int lb = L + n, rb = R + n;\n        ll ret = INF;\n        while (lb\
    \ < rb) {\n            if (lb & 1) {\n                chmin(ret, subtree(lb));\n\
    \                lb++;\n            }\n            lb >>= 1;\n            if (rb\
    \ & 1) {\n                rb--;\n                chmin(ret, subtree(rb));\n  \
    \          }\n            rb >>= 1;\n        }\n        return ret;\n    }\n\n\
    \  private:\n    struct P {\n        ll x, y;\n        P(ll _x = 0, ll _y = 0)\
    \ : x(_x), y(_y) {}\n        P operator+(const P &p) const {\n            return\
    \ P(x + p.x, y + p.y);\n        }\n        P operator-(const P &p) const {\n \
    \           return P(x - p.x, y - p.y);\n        }\n        bool operator<(const\
    \ P &p) const {\n            return (y != p.y ? y < p.y : x < p.x);\n        }\n\
    \        bool operator==(const P &p) const {\n            return (x == p.x and\
    \ y == p.y);\n        }\n        bool operator!=(const P &p) const {\n       \
    \     return (x != p.x or y != p.y);\n        }\n    };\n    i128 cross(const\
    \ P &a, const P &b) {\n        return i128(a.x) * b.y - i128(a.y) * b.x;\n   \
    \ }\n\n    int n, height;\n    using Linear = pair<ll, ll>;\n    using B = pair<P,\
    \ P>;\n    vector<P> base;\n    vector<Linear> lazy;\n    vector<B> bridges;\n\
    \n    void find(int i) {\n        if (i >= n)\n            return;\n        Linear\
    \ offset = {0, 0};\n        for (int x = i; x; x >>= 1)\n            offset =\
    \ merge(offset, lazy[x]);\n\n        int lb = i * 2, rb = i * 2 + 1;\n       \
    \ int border = rb;\n        while (border < n)\n            border <<= 1;\n  \
    \      border -= n;\n        Linear Ladd = lazy[lb], Radd = lazy[rb];\n      \
    \  for (;;) {\n            // cerr<<i<<' '<<lb<<' '<<rb<<'\\n';\n            if\
    \ (lb >= n and rb >= n)\n                break;\n            P a = bridges[lb].first,\
    \ b = bridges[lb].second;\n            P c = bridges[rb].first, d = bridges[rb].second;\n\
    \            a = apply(a, offset);\n            b = apply(b, offset);\n      \
    \      c = apply(c, offset);\n            d = apply(d, offset);\n            a\
    \ = apply(a, Ladd);\n            b = apply(b, Ladd);\n            c = apply(c,\
    \ Radd);\n            d = apply(d, Radd);\n\n            if (a != b and cross(b\
    \ - a, c - a) < 0) {\n                lb = lb * 2;\n                Ladd = merge(Ladd,\
    \ lazy[lb]);\n            } else if (c != d and cross(c - b, d - b) < 0) {\n \
    \               rb = rb * 2 + 1;\n                Radd = merge(Radd, lazy[rb]);\n\
    \            } else if (a == b) {\n                rb = rb * 2;\n            \
    \    Radd = merge(Radd, lazy[rb]);\n            } else if (c == d) {\n       \
    \         lb = lb * 2 + 1;\n                Ladd = merge(Ladd, lazy[lb]);\n  \
    \          } else {\n                i128 c1 = cross(b - a, d - c);\n        \
    \        i128 c2 = cross(b - a, b - c);\n                bool side;\n        \
    \        if (c1 == 0 and c2 == 0)\n                    side = (c.x < border);\n\
    \                else\n                    side = (c.x * c1 + (d.x - c.x) * c2\
    \ < c1 * border);\n\n                if (side) {\n                    lb = lb\
    \ * 2 + 1;\n                    Ladd = merge(Ladd, lazy[lb]);\n              \
    \  } else {\n                    rb = rb * 2;\n                    Radd = merge(Radd,\
    \ lazy[rb]);\n                }\n            }\n        }\n        bridges[i]\
    \ = {apply(base[lb], Ladd), apply(base[rb], Radd)};\n    }\n    ll subtree(int\
    \ i) {\n        Linear add = {0, 0};\n        for (int x = i; x; x >>= 1)\n  \
    \          add = merge(add, lazy[x]);\n        while (i < n) {\n            if\
    \ (apply(bridges[i].first, add).y <\n                apply(bridges[i].second,\
    \ add).y)\n                i = i * 2;\n            else\n                i = i\
    \ * 2 + 1;\n            add = merge(add, lazy[i]);\n        }\n        P ret =\
    \ apply(base[i], add);\n        return ret.y;\n    }\n    Linear merge(Linear\
    \ a, Linear b) {\n        a.first += b.first;\n        a.second += b.second;\n\
    \        return a;\n    }\n    P apply(P a, Linear b) {\n        a.y += a.x *\
    \ b.first + b.second;\n        return a;\n    }\n};\n\n/**\n * @brief Range Linear\
    \ Add Range Min\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/rangelinearaddrangemin.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/rangelinearaddrangemin.hpp
layout: document
redirect_from:
- /library/DataStructure/rangelinearaddrangemin.hpp
- /library/DataStructure/rangelinearaddrangemin.hpp.html
title: Range Linear Add Range Min
---
