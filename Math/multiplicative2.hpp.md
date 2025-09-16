---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/comb.hpp
    title: Combination
  - icon: ':x:'
    path: Math/dirichlet.hpp
    title: Dirichlet series
  - icon: ':question:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_multiplicative_function.test.cpp
    title: Verify/LC_sum_of_multiplicative_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Multiplicative Sum $O(n^{2/3}(\log n)^{-1})$
    links:
    - https://scrapbox.io/nachia-cp/%E4%B9%97%E6%B3%95%E7%9A%84%E9%96%A2%E6%95%B0%E7%B4%AF%E7%A9%8D%E5%92%8C-%E4%B8%AD%E5%9B%BD%E3%82%B3%E3%83%9F%E3%83%A5%E3%83%8B%E3%83%86%E3%82%A3%E3%81%AE%E6%96%B9%E6%B3%95
  bundledCode: "#line 2 \"Math/comb.hpp\"\n\ntemplate <typename T> T Inv(ll n) {\n\
    \    static int md;\n    static vector<T> buf({0, 1});\n    if (md != T::get_mod())\
    \ {\n        md = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n   \
    \ assert(n > 0);\n    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf),\
    \ q = (md + k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n\
    \    return buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n\
    \    static int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md\
    \ != T::get_mod()) {\n        md = T::get_mod();\n        buf = ibuf = vector<T>({1,\
    \ 1});\n    }\n    assert(n >= 0 and n < md);\n    while (SZ(buf) <= n) {\n  \
    \      buf.push_back(buf.back() * SZ(buf));\n        ibuf.push_back(ibuf.back()\
    \ * Inv<T>(SZ(ibuf)));\n    }\n    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate\
    \ <typename T> T nPr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r ||\
    \ r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^\
    \ 1);\n}\ntemplate <typename T> T nCr(int n, int r, bool inv = 0) {\n    if (n\
    \ < 0 || n < r || r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(r,\
    \ inv ^ 1) * Fact<T>(n - r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename\
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1,\
    \ inv);\n}\n// [x^n]C(x)^k\ntemplate <typename T> T Catalan(int n, int k) {\n\
    \    if (k == 0)\n        return (n == 0 ? 1 : 0);\n    return T(k) * Inv<T>(n\
    \ * 2 + k) * nCr<T>(n * 2 + k, n);\n}\n// sum = n, a nonzero tuples and b tuples\n\
    template <typename T> T choose(int n, int a, int b) {\n    if (n == 0)\n     \
    \   return !a;\n    return nCr<T>(n + b - 1, a + b - 1);\n}\n\n/**\n * @brief\
    \ Combination\n */\n#line 2 \"Math/sieve.hpp\"\n\r\ntemplate <int L = 101010101>\
    \ vector<int> sieve(int N) {\r\n    bitset<L> isp;\r\n    int n, sq = ceil(sqrt(N));\r\
    \n    for (int z = 1; z <= 5; z += 4) {\r\n        for (int y = z; y <= sq; y\
    \ += 6) {\r\n            for (int x = 1; x <= sq and (n = 4 * x * x + y * y) <=\
    \ N; ++x) {\r\n                isp[n].flip();\r\n            }\r\n           \
    \ for (int x = y + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n          \
    \       x += 2) {\r\n                isp[n].flip();\r\n            }\r\n     \
    \   }\r\n    }\r\n    for (int z = 2; z <= 4; z += 2) {\r\n        for (int y\
    \ = z; y <= sq; y += 6) {\r\n            for (int x = 1; x <= sq and (n = 3 *\
    \ x * x + y * y) <= N; x += 2) {\r\n                isp[n].flip();\r\n       \
    \     }\r\n            for (int x = y + 1; x <= sq and (n = 3 * x * x - y * y)\
    \ <= N;\r\n                 x += 2) {\r\n                isp[n].flip();\r\n  \
    \          }\r\n        }\r\n    }\r\n    for (int y = 3; y <= sq; y += 6) {\r\
    \n        for (int z = 1; z <= 2; ++z) {\r\n            for (int x = z; x <= sq\
    \ and (n = 4 * x * x + y * y) <= N; x += 3) {\r\n                isp[n].flip();\r\
    \n            }\r\n        }\r\n    }\r\n    for (int n = 5; n <= sq; ++n)\r\n\
    \        if (isp[n]) {\r\n            for (int k = n * n; k <= N; k += n * n)\
    \ {\r\n                isp[k] = false;\r\n            }\r\n        }\r\n    isp[2]\
    \ = isp[3] = true;\r\n\r\n    vector<int> ret;\r\n    for (int i = 2; i <= N;\
    \ i++)\r\n        if (isp[i]) {\r\n            ret.push_back(i);\r\n        }\r\
    \n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 2 \"\
    Math/dirichlet.hpp\"\n\r\ntemplate <typename T> struct Dir {\r\n    ll n;\r\n\
    \    int SQ, sz;\r\n    vector<T> dat;\r\n    Dir() {}\r\n    Dir(ll n) : n(n),\
    \ SQ(sqrtl(n)), sz(SQ + n / (SQ + 1) + 1), dat(sz) {}\r\n    T &operator[](int\
    \ i) {\r\n        return dat[i];\r\n    }\r\n    void pref() {\r\n        rep(i,\
    \ 0, sz - 1) dat[i + 1] += dat[i];\r\n    }\r\n    void diff() {\r\n        rrep(i,\
    \ 0, sz - 1) dat[i + 1] -= dat[i];\r\n    }\r\n    int idx(ll x) const {\r\n \
    \       return (x <= SQ ? x : sz - n / x);\r\n    }\r\n    ll val(int id) const\
    \ {\r\n        return (id <= SQ ? id : n / (sz - id));\r\n    }\r\n};\r\n\r\n\
    template <typename T> Dir<T> mult(ll n, Dir<T> &a, Dir<T> &b) {\r\n    int SQ\
    \ = sqrtl(n);\r\n    Dir<T> c(n);\r\n    int thre = a.idx(max<int>(1, pow(n, 2.\
    \ / 3)));\r\n    auto get = [&](Dir<T> &A, Dir<T> &B) -> vector<pair<int, T>>\
    \ {\r\n        vector<pair<int, T>> ret;\r\n        rep(i, 1, SQ + 1) if (A[i\
    \ - 1] != A[i]) {\r\n            T x = A[i] - A[i - 1];\r\n            ret.push_back({i,\
    \ x});\r\n            rrep(j, thre + 1, c.sz) {\r\n                ll k = c.val(j);\r\
    \n                int to = B.idx(k / i);\r\n                if (to < i)\r\n  \
    \                  break;\r\n                c[j] += x * B[to];\r\n          \
    \  }\r\n        }\r\n        rep(i, SQ + 1, thre + 1) {\r\n            if (A[i\
    \ - 1] != A[i]) {\r\n                T x = A[i] - A[i - 1];\r\n              \
    \  ret.push_back({A.val(i), x});\r\n            }\r\n        }\r\n        return\
    \ ret;\r\n    };\r\n    auto posA = get(a, b);\r\n    auto posB = get(b, a);\r\
    \n    for (auto &[v, x] : posA) {\r\n        for (auto &[w, y] : posB) {\r\n \
    \           int to = c.idx(ll(v) * w);\r\n            if (to > thre)\r\n     \
    \           break;\r\n            c[c.idx(v * w)] += x * y;\r\n        }\r\n \
    \   }\r\n    rep(i, 1, thre + 1) {\r\n        c[i] += c[i - 1];\r\n    }\r\n\r\
    \n    rrep(i, thre + 1, c.sz) {\r\n        ll x = c.val(i);\r\n        int j =\
    \ sqrtl(x);\r\n        c[i] -= a[j] * b[j];\r\n    }\r\n\r\n    return c;\r\n\
    }\r\n\r\ntemplate <typename T> Dir<T> div(ll n, Dir<T> c, Dir<T> a) {\r\n    T\
    \ coe = T(1) / a[1];\r\n    for (auto &x : a.dat)\r\n        x *= coe;\r\n\r\n\
    \    int SQ = sqrtl(n);\r\n    int thre = a.idx(max<int>(1, pow(n, 2. / 3)));\r\
    \n    Dir<T> dc = c, da = a, db(n), b(n);\r\n    dc.diff();\r\n    da.diff();\r\
    \n\r\n    db[1] = c[1];\r\n    rep(i, 2, thre + 1) {\r\n        db[i] = dc[i]\
    \ - da[i] * db[1];\r\n        ll x = a.val(i);\r\n        {\r\n            int\
    \ j = a.idx(x * x);\r\n            if (j <= thre)\r\n                dc[j] -=\
    \ da[i] * db[i];\r\n        }\r\n        rep(j, 2, i) {\r\n            int k =\
    \ a.idx(x * a.val(j));\r\n            if (k > thre)\r\n                break;\r\
    \n            dc[k] -= da[i] * db[j] + da[j] * db[i];\r\n        }\r\n    }\r\n\
    \    rep(i, 1, thre + 1) {\r\n        b[i] = db[i] + b[i - 1];\r\n    }\r\n  \
    \  rep(i, thre + 1, a.sz) {\r\n        b[i] = c[i] - a[i] * b[1];\r\n        ll\
    \ x = a.val(i);\r\n        {\r\n            int j = a.idx(sqrtl(x));\r\n     \
    \       b[i] += a[j] * b[j];\r\n        }\r\n        rep(j, 2, i + 1) {\r\n  \
    \          int k = a.idx(x / j);\r\n            if (j > k)\r\n               \
    \ break;\r\n            b[i] -= da[j] * b[k] + a[k] * db[j];\r\n        }\r\n\
    \    }\r\n\r\n    for (auto &x : b.dat)\r\n        x *= coe;\r\n    return b;\r\
    \n}\r\n\r\n/**\r\n * @brief Dirichlet series\r\n */\n#line 5 \"Math/multiplicative2.hpp\"\
    \n\ntemplate <typename T, T (*F)(ll)> Dir<T> getLarge(ll n) {\n    Dir<T> base(n);\n\
    \    int SQ = sqrtl(n);\n    auto ps = sieve(SQ);\n    vector<T> small(SQ + 10);\n\
    \    rep(x, 1, SQ + 10) small[x] = F(x);\n    rrep(i, 1, SQ + 10) small[i] -=\
    \ small[i - 1];\n    Dir<T> den(n), lg(n);\n\n    int SQ6 = max<int>(1, pow(n,\
    \ 1. / 6));\n    for (auto &p : ps)\n        if (SQ6 < p) {\n            T f_p\
    \ = small[p];\n            T X[10] = {}, base[10] = {};\n            rep(i, 1,\
    \ 10) {\n                base[i] = POW<T>(f_p, i);\n            }\n          \
    \  rep(i, 1, 10) {\n                T tmp = base[i] * i;\n                rep(j,\
    \ 1, i + 1) tmp -= base[j] * X[i - j];\n                X[i] = tmp;\n        \
    \    }\n            rep(i, 1, 10) X[i] /= i;\n\n            for (ll x = 1, i =\
    \ 0;; x *= p, i++) {\n                lg[den.idx(x)] += X[i];\n              \
    \  if (x > n / p)\n                    break;\n            }\n        }\n    lg.pref();\n\
    \n    // exp\n    {\n        Dir<T> add(n);\n        rep(i, 1, add.sz) add[i]\
    \ = den[i] = 1;\n        rep(e, 1, 5 + 1) {\n            add = mult(n, add, lg);\n\
    \            rep(i, 1, add.sz) den[i] += add[i] * Fact<T>(e, 1);\n        }\n\
    \    }\n\n    for (auto &p : ps)\n        if (p <= SQ6) {\n            T f_p =\
    \ small[p];\n            rep(i, 1, den.sz) {\n                ll x = den.val(i);\n\
    \                den[i] += den[den.idx(x / p)] * f_p;\n            }\n       \
    \ }\n\n    Dir<T> ret(n);\n    rrep(i, 1, SQ + 1) if (n / i > SQ) {\n        int\
    \ id = den.idx(n / i);\n        T tmp = F(n / i) - den[id];\n        for (int\
    \ j = 2; i * j <= SQ; j++)\n            tmp -= small[j] * ret[ret.idx(n / i /\
    \ j)];\n        ret[id] = tmp;\n    }\n\n    ret.diff();\n    return ret;\n}\n\
    \ntemplate <typename T, T (*pe)(int p, int e)>\nDir<T> MultiplicativeSum(ll n,\
    \ Dir<T> &large) {\n    Dir<T> base(n), lg(n);\n    int SQ = sqrtl(n);\n    auto\
    \ ps = sieve(SQ);\n\n    int SQ6 = max<int>(1, pow(n, 1. / 6));\n    for (auto\
    \ &p : ps) {\n        if (p <= SQ6)\n            continue;\n        T X[10] =\
    \ {}, base[10] = {};\n        rep(i, 1, 10) {\n            base[i] = pe(p, i);\n\
    \        }\n        rep(i, 1, 10) {\n            T tmp = base[i] * i;\n      \
    \      rep(j, 1, i + 1) tmp -= base[j] * X[i - j];\n            X[i] = tmp;\n\
    \        }\n        rep(i, 1, 10) X[i] /= i;\n        for (ll x = 1, i = 0;; x\
    \ *= p, i++) {\n            lg[lg.idx(x)] += X[i];\n            if (x > n / p)\n\
    \                break;\n        }\n    }\n    lg.pref();\n\n    // exp\n    {\n\
    \        Dir<T> add(n);\n        rep(i, 1, add.sz) add[i] = base[i] = 1;\n   \
    \     rep(e, 1, 5 + 1) {\n            add = mult(n, add, lg);\n            rep(i,\
    \ 1, add.sz) base[i] += add[i] * Fact<T>(e, 1);\n        }\n    }\n\n    rrep(x,\
    \ 1, SQ + 1) {\n        int i = base.idx(n / x);\n        for (int y = 1; x *\
    \ y <= SQ; y++)\n            if (base[y - 1] != base[y]) {\n                base[i]\
    \ +=\n                    (base[y] - base[y - 1]) * large[large.idx(n / x / y)];\n\
    \            }\n    }\n\n    for (auto &p : ps) {\n        if (p > SQ6)\n    \
    \        break;\n        T buf[65];\n        rep(e, 0, 65) buf[e] = pe(p, e);\n\
    \        rrep(i, 1, base.sz) {\n            ll x = base.val(i) / p;\n        \
    \    for (int e = 1;; e++) {\n                base[i] += base[base.idx(x)] * buf[e];\n\
    \                x /= p;\n                if (x == 0)\n                    break;\n\
    \            }\n        }\n    }\n\n    return base;\n}\n\n/**\n * @brief Multiplicative\
    \ Sum $O(n^{2/3}(\\log n)^{-1})$\n * @ref\n * https://scrapbox.io/nachia-cp/%E4%B9%97%E6%B3%95%E7%9A%84%E9%96%A2%E6%95%B0%E7%B4%AF%E7%A9%8D%E5%92%8C-%E4%B8%AD%E5%9B%BD%E3%82%B3%E3%83%9F%E3%83%A5%E3%83%8B%E3%83%86%E3%82%A3%E3%81%AE%E6%96%B9%E6%B3%95\n\
    \ */\n"
  code: "#pragma once\n#include \"Math/comb.hpp\"\n#include \"Math/sieve.hpp\"\n#include\
    \ \"Math/dirichlet.hpp\"\n\ntemplate <typename T, T (*F)(ll)> Dir<T> getLarge(ll\
    \ n) {\n    Dir<T> base(n);\n    int SQ = sqrtl(n);\n    auto ps = sieve(SQ);\n\
    \    vector<T> small(SQ + 10);\n    rep(x, 1, SQ + 10) small[x] = F(x);\n    rrep(i,\
    \ 1, SQ + 10) small[i] -= small[i - 1];\n    Dir<T> den(n), lg(n);\n\n    int\
    \ SQ6 = max<int>(1, pow(n, 1. / 6));\n    for (auto &p : ps)\n        if (SQ6\
    \ < p) {\n            T f_p = small[p];\n            T X[10] = {}, base[10] =\
    \ {};\n            rep(i, 1, 10) {\n                base[i] = POW<T>(f_p, i);\n\
    \            }\n            rep(i, 1, 10) {\n                T tmp = base[i] *\
    \ i;\n                rep(j, 1, i + 1) tmp -= base[j] * X[i - j];\n          \
    \      X[i] = tmp;\n            }\n            rep(i, 1, 10) X[i] /= i;\n\n  \
    \          for (ll x = 1, i = 0;; x *= p, i++) {\n                lg[den.idx(x)]\
    \ += X[i];\n                if (x > n / p)\n                    break;\n     \
    \       }\n        }\n    lg.pref();\n\n    // exp\n    {\n        Dir<T> add(n);\n\
    \        rep(i, 1, add.sz) add[i] = den[i] = 1;\n        rep(e, 1, 5 + 1) {\n\
    \            add = mult(n, add, lg);\n            rep(i, 1, add.sz) den[i] +=\
    \ add[i] * Fact<T>(e, 1);\n        }\n    }\n\n    for (auto &p : ps)\n      \
    \  if (p <= SQ6) {\n            T f_p = small[p];\n            rep(i, 1, den.sz)\
    \ {\n                ll x = den.val(i);\n                den[i] += den[den.idx(x\
    \ / p)] * f_p;\n            }\n        }\n\n    Dir<T> ret(n);\n    rrep(i, 1,\
    \ SQ + 1) if (n / i > SQ) {\n        int id = den.idx(n / i);\n        T tmp =\
    \ F(n / i) - den[id];\n        for (int j = 2; i * j <= SQ; j++)\n           \
    \ tmp -= small[j] * ret[ret.idx(n / i / j)];\n        ret[id] = tmp;\n    }\n\n\
    \    ret.diff();\n    return ret;\n}\n\ntemplate <typename T, T (*pe)(int p, int\
    \ e)>\nDir<T> MultiplicativeSum(ll n, Dir<T> &large) {\n    Dir<T> base(n), lg(n);\n\
    \    int SQ = sqrtl(n);\n    auto ps = sieve(SQ);\n\n    int SQ6 = max<int>(1,\
    \ pow(n, 1. / 6));\n    for (auto &p : ps) {\n        if (p <= SQ6)\n        \
    \    continue;\n        T X[10] = {}, base[10] = {};\n        rep(i, 1, 10) {\n\
    \            base[i] = pe(p, i);\n        }\n        rep(i, 1, 10) {\n       \
    \     T tmp = base[i] * i;\n            rep(j, 1, i + 1) tmp -= base[j] * X[i\
    \ - j];\n            X[i] = tmp;\n        }\n        rep(i, 1, 10) X[i] /= i;\n\
    \        for (ll x = 1, i = 0;; x *= p, i++) {\n            lg[lg.idx(x)] += X[i];\n\
    \            if (x > n / p)\n                break;\n        }\n    }\n    lg.pref();\n\
    \n    // exp\n    {\n        Dir<T> add(n);\n        rep(i, 1, add.sz) add[i]\
    \ = base[i] = 1;\n        rep(e, 1, 5 + 1) {\n            add = mult(n, add, lg);\n\
    \            rep(i, 1, add.sz) base[i] += add[i] * Fact<T>(e, 1);\n        }\n\
    \    }\n\n    rrep(x, 1, SQ + 1) {\n        int i = base.idx(n / x);\n       \
    \ for (int y = 1; x * y <= SQ; y++)\n            if (base[y - 1] != base[y]) {\n\
    \                base[i] +=\n                    (base[y] - base[y - 1]) * large[large.idx(n\
    \ / x / y)];\n            }\n    }\n\n    for (auto &p : ps) {\n        if (p\
    \ > SQ6)\n            break;\n        T buf[65];\n        rep(e, 0, 65) buf[e]\
    \ = pe(p, e);\n        rrep(i, 1, base.sz) {\n            ll x = base.val(i) /\
    \ p;\n            for (int e = 1;; e++) {\n                base[i] += base[base.idx(x)]\
    \ * buf[e];\n                x /= p;\n                if (x == 0)\n          \
    \          break;\n            }\n        }\n    }\n\n    return base;\n}\n\n\
    /**\n * @brief Multiplicative Sum $O(n^{2/3}(\\log n)^{-1})$\n * @ref\n * https://scrapbox.io/nachia-cp/%E4%B9%97%E6%B3%95%E7%9A%84%E9%96%A2%E6%95%B0%E7%B4%AF%E7%A9%8D%E5%92%8C-%E4%B8%AD%E5%9B%BD%E3%82%B3%E3%83%9F%E3%83%A5%E3%83%8B%E3%83%86%E3%82%A3%E3%81%AE%E6%96%B9%E6%B3%95\n\
    \ */"
  dependsOn:
  - Math/comb.hpp
  - Math/sieve.hpp
  - Math/dirichlet.hpp
  isVerificationFile: false
  path: Math/multiplicative2.hpp
  requiredBy: []
  timestamp: '2025-07-13 05:51:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_multiplicative_function.test.cpp
documentation_of: Math/multiplicative2.hpp
layout: document
redirect_from:
- /library/Math/multiplicative2.hpp
- /library/Math/multiplicative2.hpp.html
title: Multiplicative Sum $O(n^{2/3}(\log n)^{-1})$
---
