---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Rolling Hash
    links: []
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random {\r\nmt19937_64\
    \ randgen(chrono::steady_clock::now().time_since_epoch().count());\r\nusing u64\
    \ = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n}\r\ntemplate\
    \ <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\n}\r\ntemplate\
    \ <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R - L) + L;\r\n}\r\
    \ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\n}\r\
    \nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a', 'z');\r\
    \n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter first, Iter\
    \ last) {\r\n    if (first == last)\r\n        return;\r\n    int len = 1;\r\n\
    \    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\n     \
    \   int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n            iter_swap(it,\
    \ first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T> select(int n, T\
    \ L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n        vector<T> ret(R\
    \ - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\n  \
    \      ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool simple> vector<pair<int,\
    \ int>> genGraph(int n) {\r\n    vector<pair<int, int>> cand, es;\r\n    rep(u,\
    \ 0, n) rep(v, 0, n) {\r\n        if (simple and u == v)\r\n            continue;\r\
    \n        if (!directed and u > v)\r\n            continue;\r\n        cand.push_back({u,\
    \ v});\r\n    }\r\n    int m = get(SZ(cand));\r\n    vector<int> ord;\r\n    if\
    \ (simple)\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    else {\r\n    \
    \    rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n    }\r\n    for (auto\
    \ &i : ord)\r\n        es.push_back(cand[i]);\r\n    relabel(n, es);\r\n    return\
    \ es;\r\n}\r\nvector<pair<int, int>> genTree(int n) {\r\n    vector<pair<int,\
    \ int>> es;\r\n    rep(i, 1, n) es.push_back({get(i - 1), i});\r\n    relabel(n,\
    \ es);\r\n    return es;\r\n}\r\n}; // namespace Random\r\n\r\n/**\r\n * @brief\
    \ Random\r\n */\n#line 3 \"String/rollinghash.hpp\"\n\nstruct RollingHash {\n\
    \    using ull = unsigned long long;\n    const ull MOD = 0x1fffffffffffffff;\n\
    \    const ull base;\n    vector<ull> hashed, power;\n\n    static constexpr ull\
    \ mask(ll a) {\n        return (1ULL << a) - 1;\n    }\n\n    inline ull mul(ull\
    \ a, ull b) const {\n        __uint128_t ans = __uint128_t(a) * b;\n        ans\
    \ = (ans >> 61) + (ans & MOD);\n        if (ans >= MOD)\n            ans -= MOD;\n\
    \        return ans;\n    }\n\n    static inline ull genbase() {\n        return\
    \ Random::get(ull(0x1fffffffffffffff));\n    }\n    RollingHash() = default;\n\
    \n    template <typename STR> RollingHash(const STR &s, ull base) : base(base)\
    \ {\n        ll n = s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 0);\n        power[0] = 1;\n        for (ll i = 0; i < n; i++) {\n    \
    \        power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i],\
    \ base) + s[i];\n            if (hashed[i + 1] >= MOD)\n                hashed[i\
    \ + 1] -= MOD;\n        }\n    }\n\n    ull get(ll l, ll r) const {\n        ull\
    \ ret = hashed[r] + MOD - mul(hashed[l], power[r - l]);\n        if (ret >= MOD)\n\
    \            ret -= MOD;\n        return ret;\n    }\n\n    ull connect(ull h1,\
    \ ull h2, ll h2len) const {\n        ull ret = mul(h1, power[h2len]) + h2;\n \
    \       if (ret >= MOD)\n            ret -= MOD;\n        return ret;\n    }\n\
    \n    template <typename STR> void connect(const STR &s) {\n        ll n = hashed.size()\
    \ - 1, m = s.size();\n        hashed.resize(n + m + 1);\n        power.resize(n\
    \ + m + 1);\n        for (ll i = n; i < n + m; i++) {\n            power[i + 1]\
    \ = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i], base) + s[i\
    \ - n];\n            if (hashed[i + 1] >= MOD)\n                hashed[i + 1]\
    \ -= MOD;\n        }\n    }\n\n    ll LCP(const RollingHash &b, ll l1, ll r1,\
    \ ll l2, ll r2) {\n        ll len = min(r1 - l1, r2 - l2);\n        ll low = -1,\
    \ high = len + 1;\n        while (high - low > 1) {\n            ll mid = (low\
    \ + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))\n  \
    \              low = mid;\n            else\n                high = mid;\n   \
    \     }\n        return low;\n    }\n};\n\n/**\n * @brief Rolling Hash\n */\n"
  code: "#pragma once\n#include \"Utility/random.hpp\"\n\nstruct RollingHash {\n \
    \   using ull = unsigned long long;\n    const ull MOD = 0x1fffffffffffffff;\n\
    \    const ull base;\n    vector<ull> hashed, power;\n\n    static constexpr ull\
    \ mask(ll a) {\n        return (1ULL << a) - 1;\n    }\n\n    inline ull mul(ull\
    \ a, ull b) const {\n        __uint128_t ans = __uint128_t(a) * b;\n        ans\
    \ = (ans >> 61) + (ans & MOD);\n        if (ans >= MOD)\n            ans -= MOD;\n\
    \        return ans;\n    }\n\n    static inline ull genbase() {\n        return\
    \ Random::get(ull(0x1fffffffffffffff));\n    }\n    RollingHash() = default;\n\
    \n    template <typename STR> RollingHash(const STR &s, ull base) : base(base)\
    \ {\n        ll n = s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 0);\n        power[0] = 1;\n        for (ll i = 0; i < n; i++) {\n    \
    \        power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i],\
    \ base) + s[i];\n            if (hashed[i + 1] >= MOD)\n                hashed[i\
    \ + 1] -= MOD;\n        }\n    }\n\n    ull get(ll l, ll r) const {\n        ull\
    \ ret = hashed[r] + MOD - mul(hashed[l], power[r - l]);\n        if (ret >= MOD)\n\
    \            ret -= MOD;\n        return ret;\n    }\n\n    ull connect(ull h1,\
    \ ull h2, ll h2len) const {\n        ull ret = mul(h1, power[h2len]) + h2;\n \
    \       if (ret >= MOD)\n            ret -= MOD;\n        return ret;\n    }\n\
    \n    template <typename STR> void connect(const STR &s) {\n        ll n = hashed.size()\
    \ - 1, m = s.size();\n        hashed.resize(n + m + 1);\n        power.resize(n\
    \ + m + 1);\n        for (ll i = n; i < n + m; i++) {\n            power[i + 1]\
    \ = mul(power[i], base);\n            hashed[i + 1] = mul(hashed[i], base) + s[i\
    \ - n];\n            if (hashed[i + 1] >= MOD)\n                hashed[i + 1]\
    \ -= MOD;\n        }\n    }\n\n    ll LCP(const RollingHash &b, ll l1, ll r1,\
    \ ll l2, ll r2) {\n        ll len = min(r1 - l1, r2 - l2);\n        ll low = -1,\
    \ high = len + 1;\n        while (high - low > 1) {\n            ll mid = (low\
    \ + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))\n  \
    \              low = mid;\n            else\n                high = mid;\n   \
    \     }\n        return low;\n    }\n};\n\n/**\n * @brief Rolling Hash\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: String/rollinghash.hpp
  requiredBy: []
  timestamp: '2024-09-30 03:29:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/rollinghash.hpp
layout: document
redirect_from:
- /library/String/rollinghash.hpp
- /library/String/rollinghash.hpp.html
title: Rolling Hash
---
