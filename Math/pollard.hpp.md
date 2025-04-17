---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy:
  - icon: ':x:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':question:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':warning:'
    path: Math/twosquare.hpp
    title: Represent A Number As Two Square Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_binomial_coefficient.test.cpp
    title: Verify/LC_binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: Verify/LC_factorize.test.cpp
    title: Verify/LC_factorize.test.cpp
  - icon: ':x:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Pollard-Rho
    links: []
  bundledCode: "#line 2 \"Math/miller.hpp\"\n\r\nstruct m64 {\r\n    using i64 = int64_t;\r\
    \n    using u64 = uint64_t;\r\n    using u128 = __uint128_t;\r\n\r\n    static\
    \ u64 mod;\r\n    static u64 r;\r\n    static u64 n2;\r\n\r\n    static u64 get_r()\
    \ {\r\n        u64 ret = mod;\r\n        rep(_,0,5) ret *= 2 - mod * ret;\r\n\
    \        return ret;\r\n    }\r\n\r\n    static void set_mod(u64 m) {\r\n    \
    \    assert(m < (1LL << 62));\r\n        assert((m & 1) == 1);\r\n        mod\
    \ = m;\r\n        n2 = -u128(m) % m;\r\n        r = get_r();\r\n        assert(r\
    \ * mod == 1);\r\n    }\r\n    static u64 get_mod() { return mod; }\r\n\r\n  \
    \  u64 a;\r\n    m64() : a(0) {}\r\n    m64(const int64_t &b) : a(reduce((u128(b)\
    \ + mod) * n2)){};\r\n\r\n    static u64 reduce(const u128 &b) {\r\n        return\
    \ (b + u128(u64(b) * u64(-r)) * mod) >> 64;\r\n    }\r\n    u64 get() const {\r\
    \n        u64 ret = reduce(a);\r\n        return ret >= mod ? ret - mod : ret;\r\
    \n    }\r\n    m64 &operator*=(const m64 &b) {\r\n        a = reduce(u128(a) *\
    \ b.a);\r\n        return *this;\r\n    }\r\n    m64 operator*(const m64 &b) const\
    \ { return m64(*this) *= b; }\r\n    bool operator==(const m64 &b) const {\r\n\
    \        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\r\n\
    \    }\r\n    bool operator!=(const m64 &b) const {\r\n        return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\r\n    }\r\n    m64 pow(u128\
    \ n) const {\r\n        m64 ret(1), mul(*this);\r\n        while (n > 0) {\r\n\
    \        if (n & 1) ret *= mul;\r\n        mul *= mul;\r\n        n >>= 1;\r\n\
    \        }\r\n        return ret;\r\n    }\r\n};\r\ntypename m64::u64 m64::mod,\
    \ m64::r, m64::n2;\r\n\r\nbool Miller(ll n){\r\n    if(n<2 or (n&1)==0)return\
    \ (n==2);\r\n    m64::set_mod(n);\r\n    ll d=n-1; while((d&1)==0)d>>=1;\r\n \
    \   vector<ll> seeds;\r\n    if(n<(1<<30))seeds={2, 7, 61};\r\n    else seeds={2,\
    \ 325, 9375, 28178, 450775, 9780504};\r\n    for(auto& x:seeds){\r\n        if(n<=x)break;\r\
    \n        ll t=d;\r\n        m64 y=m64(x).pow(t);\r\n        while(t!=n-1 and\
    \ y!=1 and y!=n-1){\r\n            y*=y;\r\n            t<<=1;\r\n        }\r\n\
    \        if(y!=n-1 and (t&1)==0)return 0;\r\n    } return 1;\r\n}\r\n\r\n/**\r\
    \n * @brief Miller-Rabin\r\n */\n#line 2 \"Utility/random.hpp\"\n\r\nnamespace\
    \ Random {\r\nmt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nusing u64 = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n\
    }\r\ntemplate <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\
    \n}\r\ntemplate <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R -\
    \ L) + L;\r\n}\r\ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\
    \n}\r\nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a',\
    \ 'z');\r\n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter\
    \ first, Iter last) {\r\n    if (first == last)\r\n        return;\r\n    int\
    \ len = 1;\r\n    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\
    \n        int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n          \
    \  iter_swap(it, first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T>\
    \ select(int n, T L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n    \
    \    vector<T> ret(R - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\
    \n        ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool simple>\r\nvector<pair<int,\
    \ int>> genGraph(int n, int m) {\r\n    vector<pair<int, int>> cand, es;\r\n \
    \   rep(u, 0, n) rep(v, 0, n) {\r\n        if (simple and u == v)\r\n        \
    \    continue;\r\n        if (!directed and u > v)\r\n            continue;\r\n\
    \        cand.push_back({u, v});\r\n    }\r\n    if (m == -1)\r\n        m = get(SZ(cand));\r\
    \n    chmin(m, SZ(cand));\r\n    vector<int> ord;\r\n    if (simple)\r\n     \
    \   ord = select(m, 0, SZ(cand) - 1);\r\n    else {\r\n        rep(_, 0, m) ord.push_back(get(SZ(cand)\
    \ - 1));\r\n    }\r\n    for (auto &i : ord)\r\n        es.push_back(cand[i]);\r\
    \n    relabel(n, es);\r\n    return es;\r\n}\r\nvector<pair<int, int>> genTree(int\
    \ n) {\r\n    vector<pair<int, int>> es;\r\n    rep(i, 1, n) es.push_back({get(i\
    \ - 1), i});\r\n    relabel(n, es);\r\n    return es;\r\n}\r\n}; // namespace\
    \ Random\r\n\r\n/**\r\n * @brief Random\r\n */\n#line 4 \"Math/pollard.hpp\"\n\
    \r\nvector<ll> Pollard(ll n) {\r\n    if (n <= 1)\r\n        return {};\r\n  \
    \  if (Miller(n))\r\n        return {n};\r\n    if ((n & 1) == 0) {\r\n      \
    \  vector<ll> v = Pollard(n >> 1);\r\n        v.push_back(2);\r\n        return\
    \ v;\r\n    }\r\n    for (ll x = 2, y = 2, d;;) {\r\n        ll c = Random::get(2LL,\
    \ n - 1);\r\n        do {\r\n            x = (__int128_t(x) * x + c) % n;\r\n\
    \            y = (__int128_t(y) * y + c) % n;\r\n            y = (__int128_t(y)\
    \ * y + c) % n;\r\n            d = __gcd(x - y + n, n);\r\n        } while (d\
    \ == 1);\r\n        if (d < n) {\r\n            vector<ll> lb = Pollard(d), rb\
    \ = Pollard(n / d);\r\n            lb.insert(lb.end(), ALL(rb));\r\n         \
    \   return lb;\r\n        }\r\n    }\r\n}\r\n\r\nvector<ll> EnumDivisors(ll n)\
    \ {\r\n    auto ps = Pollard(n);\r\n    sort(ALL(ps));\r\n    using P = pair<ll,\
    \ int>;\r\n    vector<P> pes;\r\n    for (auto &p : ps) {\r\n        if (pes.empty()\
    \ or pes.back().first != p) {\r\n            pes.push_back({p, 1});\r\n      \
    \  } else {\r\n            pes.back().second++;\r\n        }\r\n    }\r\n    vector<ll>\
    \ ret;\r\n    auto rec = [&](auto &rec, int id, ll d) -> void {\r\n        if\
    \ (id == SZ(pes)) {\r\n            ret.push_back(d);\r\n            return;\r\n\
    \        }\r\n        rec(rec, id + 1, d);\r\n        rep(e, 0, pes[id].second)\
    \ {\r\n            d *= pes[id].first;\r\n            rec(rec, id + 1, d);\r\n\
    \        }\r\n    };\r\n    rec(rec, 0, 1);\r\n    sort(ALL(ret));\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n"
  code: "#pragma once\r\n#include \"Math/miller.hpp\"\r\n#include \"Utility/random.hpp\"\
    \r\n\r\nvector<ll> Pollard(ll n) {\r\n    if (n <= 1)\r\n        return {};\r\n\
    \    if (Miller(n))\r\n        return {n};\r\n    if ((n & 1) == 0) {\r\n    \
    \    vector<ll> v = Pollard(n >> 1);\r\n        v.push_back(2);\r\n        return\
    \ v;\r\n    }\r\n    for (ll x = 2, y = 2, d;;) {\r\n        ll c = Random::get(2LL,\
    \ n - 1);\r\n        do {\r\n            x = (__int128_t(x) * x + c) % n;\r\n\
    \            y = (__int128_t(y) * y + c) % n;\r\n            y = (__int128_t(y)\
    \ * y + c) % n;\r\n            d = __gcd(x - y + n, n);\r\n        } while (d\
    \ == 1);\r\n        if (d < n) {\r\n            vector<ll> lb = Pollard(d), rb\
    \ = Pollard(n / d);\r\n            lb.insert(lb.end(), ALL(rb));\r\n         \
    \   return lb;\r\n        }\r\n    }\r\n}\r\n\r\nvector<ll> EnumDivisors(ll n)\
    \ {\r\n    auto ps = Pollard(n);\r\n    sort(ALL(ps));\r\n    using P = pair<ll,\
    \ int>;\r\n    vector<P> pes;\r\n    for (auto &p : ps) {\r\n        if (pes.empty()\
    \ or pes.back().first != p) {\r\n            pes.push_back({p, 1});\r\n      \
    \  } else {\r\n            pes.back().second++;\r\n        }\r\n    }\r\n    vector<ll>\
    \ ret;\r\n    auto rec = [&](auto &rec, int id, ll d) -> void {\r\n        if\
    \ (id == SZ(pes)) {\r\n            ret.push_back(d);\r\n            return;\r\n\
    \        }\r\n        rec(rec, id + 1, d);\r\n        rep(e, 0, pes[id].second)\
    \ {\r\n            d *= pes[id].first;\r\n            rec(rec, id + 1, d);\r\n\
    \        }\r\n    };\r\n    rec(rec, 0, 1);\r\n    sort(ALL(ret));\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */"
  dependsOn:
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/pollard.hpp
  requiredBy:
  - Math/twosquare.hpp
  - Math/binomquery.hpp
  - Math/primitive.hpp
  - Convolution/multivariatecyclic.hpp
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_factorize.test.cpp
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
documentation_of: Math/pollard.hpp
layout: document
redirect_from:
- /library/Math/pollard.hpp
- /library/Math/pollard.hpp.html
title: Pollard-Rho
---
