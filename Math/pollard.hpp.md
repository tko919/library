---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_binomial_coefficient.test.cpp
    title: Verify/LC_binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_factorize.test.cpp
    title: Verify/LC_factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ Random{\r\n    mt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n    using u64=unsigned long long;\r\n    u64 get(){\r\n        return randgen();\r\
    \n    }\r\n    template<typename T>T get(T L){\r\n        return get()%(L+1);\r\
    \n    }\r\n    template<typename T>T get(T L,T R){\r\n        return get(R-L)+L;\r\
    \n    }\r\n    double uniform(){\r\n        return double(get(1000000000))/1000000000;\r\
    \n    }\r\n    string str(int n){\r\n        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\
    \n        return ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter\
    \ first,Iter last){\r\n        if(first==last)return;\r\n        int len=1;\r\n\
    \        for(auto it=first+1;it!=last;it++){\r\n            len++;\r\n       \
    \     int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\n\
    \        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 4 \"Math/pollard.hpp\"\n\r\nvector<ll> Pollard(ll n) {\r\n    if (n\
    \ <= 1)\r\n        return {};\r\n    if (Miller(n))\r\n        return {n};\r\n\
    \    if ((n & 1) == 0) {\r\n        vector<ll> v = Pollard(n >> 1);\r\n      \
    \  v.push_back(2);\r\n        return v;\r\n    }\r\n    for (ll x = 2, y = 2,\
    \ d;;) {\r\n        ll c = Random::get(2LL, n - 1);\r\n        do {\r\n      \
    \      x = (__int128_t(x) * x + c) % n;\r\n            y = (__int128_t(y) * y\
    \ + c) % n;\r\n            y = (__int128_t(y) * y + c) % n;\r\n            d =\
    \ __gcd(x - y + n, n);\r\n        } while (d == 1);\r\n        if (d < n) {\r\n\
    \            vector<ll> lb = Pollard(d), rb = Pollard(n / d);\r\n            lb.insert(lb.end(),\
    \ ALL(rb));\r\n            return lb;\r\n        }\r\n    }\r\n}\r\n\r\n/**\r\n\
    \ * @brief Pollard-Rho\r\n */\n"
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
    \   return lb;\r\n        }\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\
    \n */"
  dependsOn:
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/pollard.hpp
  requiredBy:
  - Convolution/multivariatecyclic.hpp
  - Math/binomquery.hpp
  - Math/primitive.hpp
  timestamp: '2024-01-12 05:13:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_factorize.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
documentation_of: Math/pollard.hpp
layout: document
redirect_from:
- /library/Math/pollard.hpp
- /library/Math/pollard.hpp.html
title: Pollard-Rho
---
