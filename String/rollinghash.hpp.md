---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/hash.hpp
    title: Hash
  - icon: ':question:'
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
    \ Random\r\n\r\n/**\r\n * @brief Random\r\n */\n#line 2 \"Math/hash.hpp\"\n\n\
    struct Hash {\n    static constexpr ull mod = 0x1fffffffffffffff;\n    ull v;\n\
    \    static constexpr ull get_mod() {\n        return mod;\n    }\n    constexpr\
    \ ull inv() const {\n        assert(v != 0);\n        ull x = v, y = mod, p =\
    \ 1, q = 0, t = 0, tmp = 0;\n        while (y > 0) {\n            t = x / y;\n\
    \            x -= t * y, p -= t * q;\n            tmp = x, x = y, y = tmp;\n \
    \           tmp = p, p = q, q = tmp;\n        }\n        if (p < 0)\n        \
    \    p += mod;\n        return p;\n    }\n    constexpr Hash(ll x = 0) : v(x >=\
    \ 0 ? x % mod : (mod - (-x) % mod) % mod) {}\n    Hash operator-() const {\n \
    \       return Hash() - *this;\n    }\n    Hash pow(ull t) {\n        Hash res\
    \ = 1, b = *this;\n        while (t) {\n            if (t & 1)\n             \
    \   res *= b;\n            b *= b;\n            t >>= 1;\n        }\n        return\
    \ res;\n    }\n    Hash &operator+=(const Hash &x) {\n        if ((v += x.v) >=\
    \ mod)\n            v -= mod;\n        return *this;\n    }\n    Hash &operator-=(const\
    \ Hash &x) {\n        if ((v += mod - x.v) >= mod)\n            v -= mod;\n  \
    \      return *this;\n    }\n    Hash &operator*=(const Hash &x) {\n        u128\
    \ ans = u128(v) * x.v;\n        ans = (ans >> 61) + (ans & mod);\n        if (ans\
    \ >= mod)\n            ans -= mod;\n        v = ans;\n        return *this;\n\
    \    }\n    Hash &operator/=(const Hash &x) {\n        v = ull(v) * x.inv() %\
    \ mod;\n        return *this;\n    }\n    Hash operator+(const Hash &x) const\
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
    \ const Hash &x) {\n        return os << x.v;\n    }\n};\n\nvoid rd(Hash &x) {\n\
    \    fastio::rd(x.v);\n}\n\n/**\n * @brief Hash\n */\n#line 4 \"String/rollinghash.hpp\"\
    \n\nstruct RollingHash {\n    using ull = unsigned long long;\n    const Hash\
    \ base;\n    vector<Hash> hashed, power;\n\n    static inline ull genbase() {\n\
    \        return Random::get(ull(0x1fffffffffffffff));\n    }\n    RollingHash(Hash\
    \ base) : base(base) {}\n\n    template <typename STR> void build(const STR &s)\
    \ {\n        int n = s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 0);\n        power[0] = 1;\n        for (ll i = 0; i < n; i++) {\n    \
    \        power[i + 1] = power[i] * base;\n            hashed[i + 1] = hashed[i]\
    \ * base + s[i];\n        }\n    }\n\n    Hash get(ll l, ll r) const {\n     \
    \   return hashed[r] - hashed[l] * power[r - l];\n    }\n\n    Hash connect(Hash\
    \ h1, Hash h2, ll h2len) const {\n        return h1 * power[h2len] + h2;\n   \
    \ }\n\n    template <typename STR> void connect(const STR &s) {\n        ll n\
    \ = hashed.size() - 1, m = s.size();\n        hashed.resize(n + m + 1);\n    \
    \    power.resize(n + m + 1);\n        for (ll i = n; i < n + m; i++) {\n    \
    \        power[i + 1] = power[i] * base;\n            hashed[i + 1] = hashed[i]\
    \ * base + s[i - n];\n        }\n    }\n\n    ll LCP(const RollingHash &b, ll\
    \ l1, ll r1, ll l2, ll r2) {\n        ll len = min(r1 - l1, r2 - l2);\n      \
    \  ll low = -1, high = len + 1;\n        while (high - low > 1) {\n          \
    \  ll mid = (low + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return low;\n    }\n};\n\n/**\n * @brief Rolling\
    \ Hash\n */\n"
  code: "#pragma once\n#include \"Utility/random.hpp\"\n#include \"Math/hash.hpp\"\
    \n\nstruct RollingHash {\n    using ull = unsigned long long;\n    const Hash\
    \ base;\n    vector<Hash> hashed, power;\n\n    static inline ull genbase() {\n\
    \        return Random::get(ull(0x1fffffffffffffff));\n    }\n    RollingHash(Hash\
    \ base) : base(base) {}\n\n    template <typename STR> void build(const STR &s)\
    \ {\n        int n = s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 0);\n        power[0] = 1;\n        for (ll i = 0; i < n; i++) {\n    \
    \        power[i + 1] = power[i] * base;\n            hashed[i + 1] = hashed[i]\
    \ * base + s[i];\n        }\n    }\n\n    Hash get(ll l, ll r) const {\n     \
    \   return hashed[r] - hashed[l] * power[r - l];\n    }\n\n    Hash connect(Hash\
    \ h1, Hash h2, ll h2len) const {\n        return h1 * power[h2len] + h2;\n   \
    \ }\n\n    template <typename STR> void connect(const STR &s) {\n        ll n\
    \ = hashed.size() - 1, m = s.size();\n        hashed.resize(n + m + 1);\n    \
    \    power.resize(n + m + 1);\n        for (ll i = n; i < n + m; i++) {\n    \
    \        power[i + 1] = power[i] * base;\n            hashed[i + 1] = hashed[i]\
    \ * base + s[i - n];\n        }\n    }\n\n    ll LCP(const RollingHash &b, ll\
    \ l1, ll r1, ll l2, ll r2) {\n        ll len = min(r1 - l1, r2 - l2);\n      \
    \  ll low = -1, high = len + 1;\n        while (high - low > 1) {\n          \
    \  ll mid = (low + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return low;\n    }\n};\n\n/**\n * @brief Rolling\
    \ Hash\n */"
  dependsOn:
  - Utility/random.hpp
  - Math/hash.hpp
  isVerificationFile: false
  path: String/rollinghash.hpp
  requiredBy: []
  timestamp: '2025-04-21 04:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/rollinghash.hpp
layout: document
redirect_from:
- /library/String/rollinghash.hpp
- /library/String/rollinghash.hpp.html
title: Rolling Hash
---
