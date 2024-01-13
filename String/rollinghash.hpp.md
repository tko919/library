---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random{\r\n    mt19937_64\
    \ randgen(chrono::steady_clock::now().time_since_epoch().count());\r\n    using\
    \ u64=unsigned long long;\r\n    u64 get(){\r\n        return randgen();\r\n \
    \   }\r\n    template<typename T>T get(T L){\r\n        return get()%(L+1);\r\n\
    \    }\r\n    template<typename T>T get(T L,T R){\r\n        return get(R-L)+L;\r\
    \n    }\r\n    double uniform(){\r\n        return double(get(1000000000))/1000000000;\r\
    \n    }\r\n    string str(int n){\r\n        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\
    \n        return ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter\
    \ first,Iter last){\r\n        if(first==last)return;\r\n        int len=1;\r\n\
    \        for(auto it=first+1;it!=last;it++){\r\n            len++;\r\n       \
    \     int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\n\
    \        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 3 \"String/rollinghash.hpp\"\n\nstruct RollingHash {\n    using ull\
    \ = unsigned long long;\n    const ull MOD = 0x1fffffffffffffff;\n    const ull\
    \ base;\n    vector<ull> hashed, power;\n\n    static constexpr ull mask(ll a)\
    \ { return (1ULL << a) - 1; }\n\n    inline ull mul(ull a, ull b) const {\n  \
    \      __uint128_t ans = __uint128_t(a) * b;\n        ans = (ans >> 61) + (ans\
    \ & MOD);\n        if (ans >= MOD)\n            ans -= MOD;\n        return ans;\n\
    \    }\n\n    static inline ull genbase() { return Random::get(ull(0x1fffffffffffffff));\
    \ }\n    RollingHash() = default;\n\n    RollingHash(const string &s, ull base)\
    \ : base(base) {\n        ll n = s.size();\n        hashed.assign(n + 1, 0);\n\
    \        power.assign(n + 1, 0);\n        power[0] = 1;\n        for (ll i = 0;\
    \ i < n; i++) {\n            power[i + 1] = mul(power[i], base);\n           \
    \ hashed[i + 1] = mul(hashed[i], base) + s[i];\n            if (hashed[i + 1]\
    \ >= MOD)\n                hashed[i + 1] -= MOD;\n        }\n    }\n\n    ull\
    \ get(ll l, ll r) const {\n        ull ret = hashed[r] + MOD - mul(hashed[l],\
    \ power[r - l]);\n        if (ret >= MOD)\n            ret -= MOD;\n        return\
    \ ret;\n    }\n\n    ull connect(ull h1, ull h2, ll h2len) const {\n        ull\
    \ ret = mul(h1, power[h2len]) + h2;\n        if (ret >= MOD)\n            ret\
    \ -= MOD;\n        return ret;\n    }\n\n    void connect(const string &s) {\n\
    \        ll n = hashed.size() - 1, m = s.size();\n        hashed.resize(n + m\
    \ + 1);\n        power.resize(n + m + 1);\n        for (ll i = n; i < n + m; i++)\
    \ {\n            power[i + 1] = mul(power[i], base);\n            hashed[i + 1]\
    \ = mul(hashed[i], base) + s[i - n];\n            if (hashed[i + 1] >= MOD)\n\
    \                hashed[i + 1] -= MOD;\n        }\n    }\n\n    ll LCP(const RollingHash\
    \ &b, ll l1, ll r1, ll l2, ll r2) {\n        ll len = min(r1 - l1, r2 - l2);\n\
    \        ll low = -1, high = len + 1;\n        while (high - low > 1) {\n    \
    \        ll mid = (low + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return low;\n    }\n};\n\n/**\n * @brief Rolling\
    \ Hash\n */\n"
  code: "#pragma once\n#include \"Utility/random.hpp\"\n\nstruct RollingHash {\n \
    \   using ull = unsigned long long;\n    const ull MOD = 0x1fffffffffffffff;\n\
    \    const ull base;\n    vector<ull> hashed, power;\n\n    static constexpr ull\
    \ mask(ll a) { return (1ULL << a) - 1; }\n\n    inline ull mul(ull a, ull b) const\
    \ {\n        __uint128_t ans = __uint128_t(a) * b;\n        ans = (ans >> 61)\
    \ + (ans & MOD);\n        if (ans >= MOD)\n            ans -= MOD;\n        return\
    \ ans;\n    }\n\n    static inline ull genbase() { return Random::get(ull(0x1fffffffffffffff));\
    \ }\n    RollingHash() = default;\n\n    RollingHash(const string &s, ull base)\
    \ : base(base) {\n        ll n = s.size();\n        hashed.assign(n + 1, 0);\n\
    \        power.assign(n + 1, 0);\n        power[0] = 1;\n        for (ll i = 0;\
    \ i < n; i++) {\n            power[i + 1] = mul(power[i], base);\n           \
    \ hashed[i + 1] = mul(hashed[i], base) + s[i];\n            if (hashed[i + 1]\
    \ >= MOD)\n                hashed[i + 1] -= MOD;\n        }\n    }\n\n    ull\
    \ get(ll l, ll r) const {\n        ull ret = hashed[r] + MOD - mul(hashed[l],\
    \ power[r - l]);\n        if (ret >= MOD)\n            ret -= MOD;\n        return\
    \ ret;\n    }\n\n    ull connect(ull h1, ull h2, ll h2len) const {\n        ull\
    \ ret = mul(h1, power[h2len]) + h2;\n        if (ret >= MOD)\n            ret\
    \ -= MOD;\n        return ret;\n    }\n\n    void connect(const string &s) {\n\
    \        ll n = hashed.size() - 1, m = s.size();\n        hashed.resize(n + m\
    \ + 1);\n        power.resize(n + m + 1);\n        for (ll i = n; i < n + m; i++)\
    \ {\n            power[i + 1] = mul(power[i], base);\n            hashed[i + 1]\
    \ = mul(hashed[i], base) + s[i - n];\n            if (hashed[i + 1] >= MOD)\n\
    \                hashed[i + 1] -= MOD;\n        }\n    }\n\n    ll LCP(const RollingHash\
    \ &b, ll l1, ll r1, ll l2, ll r2) {\n        ll len = min(r1 - l1, r2 - l2);\n\
    \        ll low = -1, high = len + 1;\n        while (high - low > 1) {\n    \
    \        ll mid = (low + high) / 2;\n            if (get(l1, l1 + mid) == b.get(l2,\
    \ l2 + mid))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return low;\n    }\n};\n\n/**\n * @brief Rolling\
    \ Hash\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: String/rollinghash.hpp
  requiredBy: []
  timestamp: '2024-01-14 01:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/rollinghash.hpp
layout: document
redirect_from:
- /library/String/rollinghash.hpp
- /library/String/rollinghash.hpp.html
title: Rolling Hash
---
