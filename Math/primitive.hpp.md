---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/fastdiv.hpp
    title: Fast Division
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_binomial_coefficient.test.cpp
    title: Verify/LC_binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Primitive Function
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * @brief Fast\
    \ Division\n*/\n#line 2 \"Math/miller.hpp\"\n\r\nstruct m64 {\r\n    using i64\
    \ = int64_t;\r\n    using u64 = uint64_t;\r\n    using u128 = __uint128_t;\r\n\
    \r\n    static u64 mod;\r\n    static u64 r;\r\n    static u64 n2;\r\n\r\n   \
    \ static u64 get_r() {\r\n        u64 ret = mod;\r\n        rep(_,0,5) ret *=\
    \ 2 - mod * ret;\r\n        return ret;\r\n    }\r\n\r\n    static void set_mod(u64\
    \ m) {\r\n        assert(m < (1LL << 62));\r\n        assert((m & 1) == 1);\r\n\
    \        mod = m;\r\n        n2 = -u128(m) % m;\r\n        r = get_r();\r\n  \
    \      assert(r * mod == 1);\r\n    }\r\n    static u64 get_mod() { return mod;\
    \ }\r\n\r\n    u64 a;\r\n    m64() : a(0) {}\r\n    m64(const int64_t &b) : a(reduce((u128(b)\
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
    \ Random\r\n */\n#line 4 \"Math/pollard.hpp\"\n\r\nvector<ll> Pollard(ll n) {\r\
    \n    if (n <= 1)\r\n        return {};\r\n    if (Miller(n))\r\n        return\
    \ {n};\r\n    if ((n & 1) == 0) {\r\n        vector<ll> v = Pollard(n >> 1);\r\
    \n        v.push_back(2);\r\n        return v;\r\n    }\r\n    for (ll x = 2,\
    \ y = 2, d;;) {\r\n        ll c = Random::get(2LL, n - 1);\r\n        do {\r\n\
    \            x = (__int128_t(x) * x + c) % n;\r\n            y = (__int128_t(y)\
    \ * y + c) % n;\r\n            y = (__int128_t(y) * y + c) % n;\r\n          \
    \  d = __gcd(x - y + n, n);\r\n        } while (d == 1);\r\n        if (d < n)\
    \ {\r\n            vector<ll> lb = Pollard(d), rb = Pollard(n / d);\r\n      \
    \      lb.insert(lb.end(), ALL(rb));\r\n            return lb;\r\n        }\r\n\
    \    }\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 4 \"Math/primitive.hpp\"\
    \n\r\nll mpow(ll a, ll t, ll m) {\r\n    ll res = 1;\r\n    FastDiv im(m);\r\n\
    \    while (t) {\r\n        if (t & 1)\r\n            res = __int128_t(res) *\
    \ a % im;\r\n        a = __int128_t(a) * a % im;\r\n        t >>= 1;\r\n    }\r\
    \n    return res;\r\n}\r\nll minv(ll a, ll m) {\r\n    ll b = m, u = 1, v = 0;\r\
    \n    while (b) {\r\n        ll t = a / b;\r\n        a -= t * b;\r\n        swap(a,\
    \ b);\r\n        u -= t * v;\r\n        swap(u, v);\r\n    }\r\n    u = (u % m\
    \ + m) % m;\r\n    return u;\r\n}\r\nll getPrimitiveRoot(ll p) {\r\n    vector<ll>\
    \ ps = Pollard(p - 1);\r\n    sort(ALL(ps));\r\n    rep(x, 1, inf) {\r\n     \
    \   for (auto &q : ps) {\r\n            if (mpow(x, (p - 1) / q, p) == 1)\r\n\
    \                goto fail;\r\n        }\r\n        return x;\r\n    fail:;\r\n\
    \    }\r\n    assert(0);\r\n}\r\nll extgcd(ll a, ll b, ll &p, ll &q) {\r\n   \
    \ if (b == 0) {\r\n        p = 1;\r\n        q = 0;\r\n        return a;\r\n \
    \   }\r\n    ll d = extgcd(b, a % b, q, p);\r\n    q -= a / b * p;\r\n    return\
    \ d;\r\n}\r\npair<ll, ll> crt(const vector<ll> &vs, const vector<ll> &ms) {\r\n\
    \    ll V = vs[0], M = ms[0];\r\n    rep(i, 1, vs.size()) {\r\n        ll p, q,\
    \ v = vs[i], m = ms[i];\r\n        if (M < m)\r\n            swap(M, m), swap(V,\
    \ v);\r\n        ll d = extgcd(M, m, p, q);\r\n        if ((v - V) % d != 0)\r\
    \n            return {0, -1};\r\n        ll md = m / d, tmp = (v - V) / d % md\
    \ * p % md;\r\n        V += M * tmp;\r\n        M *= md;\r\n    }\r\n    V = (V\
    \ % M + M) % M;\r\n    return {V, M};\r\n}\r\nll ModLog(ll a, ll b, ll p) {\r\n\
    \    ll g = 1;\r\n    for (ll t = p; t; t >>= 1)\r\n        g = g * a % p;\r\n\
    \    g = __gcd(g, p);\r\n    ll t = 1, c = 0;\r\n    for (; t % g; c++) {\r\n\
    \        if (t == b)\r\n            return c;\r\n        t = t * a % p;\r\n  \
    \  }\r\n    if (b % g)\r\n        return -1;\r\n    t /= g, b /= g;\r\n    ll\
    \ n = p / g, h = 0, gs = 1;\r\n    for (; h * h < n; h++)\r\n        gs = gs *\
    \ a % n;\r\n    unordered_map<ll, ll> bs;\r\n    for (ll s = 0, e = b; s < h;\
    \ bs[e] = ++s)\r\n        e = e * a % n;\r\n    for (ll s = 0, e = t; s < n;)\
    \ {\r\n        e = e * gs % n, s += h;\r\n        if (bs.count(e)) {\r\n     \
    \       return c + s - bs[e];\r\n        }\r\n    }\r\n    return -1;\r\n}\r\n\
    \r\nll mod_root(ll k, ll a, ll m) {\r\n    if (a == 0)\r\n        return k ? 0\
    \ : -1;\r\n    if (m == 2)\r\n        return a & 1;\r\n    k %= m - 1;\r\n   \
    \ ll g = gcd(k, m - 1);\r\n    if (mpow(a, (m - 1) / g, m) != 1)\r\n        return\
    \ -1;\r\n    a = mpow(a, minv(k / g, (m - 1) / g), m);\r\n    FastDiv im(m);\r\
    \n\r\n    auto _subroot = [&](ll p, int e, ll a) -> ll { // x^(p^e)==a(mod m)\r\
    \n        ll q = m - 1;\r\n        int s = 0;\r\n        while (q % p == 0) {\r\
    \n            q /= p;\r\n            s++;\r\n        }\r\n        int d = s -\
    \ e;\r\n        ll pe = mpow(p, e, m),\r\n           res = mpow(a, ((pe - 1) *\
    \ minv(q, pe) % pe * q + 1) / pe, m), c = 1;\r\n        while (mpow(c, (m - 1)\
    \ / p, m) == 1)\r\n            c++;\r\n        c = mpow(c, q, m);\r\n        map<ll,\
    \ ll> mp;\r\n        ll v = 1, block = sqrt(d * p) + 1,\r\n           bs = mpow(c,\
    \ mpow(p, s - 1, m - 1) * block % (m - 1), m);\r\n        rep(i, 0, block + 1)\
    \ mp[v] = i, v = v * bs % im;\r\n        ll gs = minv(mpow(c, mpow(p, s - 1, m\
    \ - 1), m), m);\r\n        rep(i, 0, d) {\r\n            ll err = a * minv(mpow(res,\
    \ pe, m), m) % im;\r\n            ll pos = mpow(err, mpow(p, d - 1 - i, m - 1),\
    \ m);\r\n            rep(j, 0, block + 1) {\r\n                if (mp.count(pos))\
    \ {\r\n                    res = res *\r\n                          mpow(c,\r\n\
    \                               (block * mp[pos] + j) * mpow(p, i, m - 1) %\r\n\
    \                                   (m - 1),\r\n                             \
    \  m) %\r\n                          im;\r\n                    break;\r\n   \
    \             }\r\n                pos = pos * gs % im;\r\n            }\r\n \
    \       }\r\n        return res;\r\n    };\r\n\r\n    for (ll d = 2; d * d <=\
    \ g; d++)\r\n        if (g % d == 0) {\r\n            int sz = 0;\r\n        \
    \    while (g % d == 0) {\r\n                g /= d;\r\n                sz++;\r\
    \n            }\r\n            a = _subroot(d, sz, a);\r\n        }\r\n    if\
    \ (g > 1)\r\n        a = _subroot(g, 1, a);\r\n    return a;\r\n}\r\n\r\null floor_root(ull\
    \ a, ull k) {\r\n    if (a <= 1 or k == 1)\r\n        return a;\r\n    if (k >=\
    \ 64)\r\n        return 1;\r\n    if (k == 2)\r\n        return sqrtl(a);\r\n\
    \    constexpr ull LIM = -1;\r\n    if (a == LIM)\r\n        a--;\r\n    auto\
    \ mul = [&](ull &x, const ull &y) {\r\n        if (x <= LIM / y)\r\n         \
    \   x *= y;\r\n        else\r\n            x = LIM;\r\n    };\r\n    auto pw =\
    \ [&](ull x, ull t) -> ull {\r\n        ull y = 1;\r\n        while (t) {\r\n\
    \            if (t & 1)\r\n                mul(y, x);\r\n            mul(x, x);\r\
    \n            t >>= 1;\r\n        }\r\n        return y;\r\n    };\r\n    ull\
    \ ret = (k == 3 ? cbrt(a) - 1 : pow(a, nextafter(1 / double(k), 0)));\r\n    while\
    \ (pw(ret + 1, k) <= a)\r\n        ret++;\r\n    return ret;\r\n}\r\n\r\n/**\r\
    \n * @brief Primitive Function\r\n */\n"
  code: "#pragma once\r\n#include \"Math/fastdiv.hpp\"\r\n#include \"Math/pollard.hpp\"\
    \r\n\r\nll mpow(ll a, ll t, ll m) {\r\n    ll res = 1;\r\n    FastDiv im(m);\r\
    \n    while (t) {\r\n        if (t & 1)\r\n            res = __int128_t(res) *\
    \ a % im;\r\n        a = __int128_t(a) * a % im;\r\n        t >>= 1;\r\n    }\r\
    \n    return res;\r\n}\r\nll minv(ll a, ll m) {\r\n    ll b = m, u = 1, v = 0;\r\
    \n    while (b) {\r\n        ll t = a / b;\r\n        a -= t * b;\r\n        swap(a,\
    \ b);\r\n        u -= t * v;\r\n        swap(u, v);\r\n    }\r\n    u = (u % m\
    \ + m) % m;\r\n    return u;\r\n}\r\nll getPrimitiveRoot(ll p) {\r\n    vector<ll>\
    \ ps = Pollard(p - 1);\r\n    sort(ALL(ps));\r\n    rep(x, 1, inf) {\r\n     \
    \   for (auto &q : ps) {\r\n            if (mpow(x, (p - 1) / q, p) == 1)\r\n\
    \                goto fail;\r\n        }\r\n        return x;\r\n    fail:;\r\n\
    \    }\r\n    assert(0);\r\n}\r\nll extgcd(ll a, ll b, ll &p, ll &q) {\r\n   \
    \ if (b == 0) {\r\n        p = 1;\r\n        q = 0;\r\n        return a;\r\n \
    \   }\r\n    ll d = extgcd(b, a % b, q, p);\r\n    q -= a / b * p;\r\n    return\
    \ d;\r\n}\r\npair<ll, ll> crt(const vector<ll> &vs, const vector<ll> &ms) {\r\n\
    \    ll V = vs[0], M = ms[0];\r\n    rep(i, 1, vs.size()) {\r\n        ll p, q,\
    \ v = vs[i], m = ms[i];\r\n        if (M < m)\r\n            swap(M, m), swap(V,\
    \ v);\r\n        ll d = extgcd(M, m, p, q);\r\n        if ((v - V) % d != 0)\r\
    \n            return {0, -1};\r\n        ll md = m / d, tmp = (v - V) / d % md\
    \ * p % md;\r\n        V += M * tmp;\r\n        M *= md;\r\n    }\r\n    V = (V\
    \ % M + M) % M;\r\n    return {V, M};\r\n}\r\nll ModLog(ll a, ll b, ll p) {\r\n\
    \    ll g = 1;\r\n    for (ll t = p; t; t >>= 1)\r\n        g = g * a % p;\r\n\
    \    g = __gcd(g, p);\r\n    ll t = 1, c = 0;\r\n    for (; t % g; c++) {\r\n\
    \        if (t == b)\r\n            return c;\r\n        t = t * a % p;\r\n  \
    \  }\r\n    if (b % g)\r\n        return -1;\r\n    t /= g, b /= g;\r\n    ll\
    \ n = p / g, h = 0, gs = 1;\r\n    for (; h * h < n; h++)\r\n        gs = gs *\
    \ a % n;\r\n    unordered_map<ll, ll> bs;\r\n    for (ll s = 0, e = b; s < h;\
    \ bs[e] = ++s)\r\n        e = e * a % n;\r\n    for (ll s = 0, e = t; s < n;)\
    \ {\r\n        e = e * gs % n, s += h;\r\n        if (bs.count(e)) {\r\n     \
    \       return c + s - bs[e];\r\n        }\r\n    }\r\n    return -1;\r\n}\r\n\
    \r\nll mod_root(ll k, ll a, ll m) {\r\n    if (a == 0)\r\n        return k ? 0\
    \ : -1;\r\n    if (m == 2)\r\n        return a & 1;\r\n    k %= m - 1;\r\n   \
    \ ll g = gcd(k, m - 1);\r\n    if (mpow(a, (m - 1) / g, m) != 1)\r\n        return\
    \ -1;\r\n    a = mpow(a, minv(k / g, (m - 1) / g), m);\r\n    FastDiv im(m);\r\
    \n\r\n    auto _subroot = [&](ll p, int e, ll a) -> ll { // x^(p^e)==a(mod m)\r\
    \n        ll q = m - 1;\r\n        int s = 0;\r\n        while (q % p == 0) {\r\
    \n            q /= p;\r\n            s++;\r\n        }\r\n        int d = s -\
    \ e;\r\n        ll pe = mpow(p, e, m),\r\n           res = mpow(a, ((pe - 1) *\
    \ minv(q, pe) % pe * q + 1) / pe, m), c = 1;\r\n        while (mpow(c, (m - 1)\
    \ / p, m) == 1)\r\n            c++;\r\n        c = mpow(c, q, m);\r\n        map<ll,\
    \ ll> mp;\r\n        ll v = 1, block = sqrt(d * p) + 1,\r\n           bs = mpow(c,\
    \ mpow(p, s - 1, m - 1) * block % (m - 1), m);\r\n        rep(i, 0, block + 1)\
    \ mp[v] = i, v = v * bs % im;\r\n        ll gs = minv(mpow(c, mpow(p, s - 1, m\
    \ - 1), m), m);\r\n        rep(i, 0, d) {\r\n            ll err = a * minv(mpow(res,\
    \ pe, m), m) % im;\r\n            ll pos = mpow(err, mpow(p, d - 1 - i, m - 1),\
    \ m);\r\n            rep(j, 0, block + 1) {\r\n                if (mp.count(pos))\
    \ {\r\n                    res = res *\r\n                          mpow(c,\r\n\
    \                               (block * mp[pos] + j) * mpow(p, i, m - 1) %\r\n\
    \                                   (m - 1),\r\n                             \
    \  m) %\r\n                          im;\r\n                    break;\r\n   \
    \             }\r\n                pos = pos * gs % im;\r\n            }\r\n \
    \       }\r\n        return res;\r\n    };\r\n\r\n    for (ll d = 2; d * d <=\
    \ g; d++)\r\n        if (g % d == 0) {\r\n            int sz = 0;\r\n        \
    \    while (g % d == 0) {\r\n                g /= d;\r\n                sz++;\r\
    \n            }\r\n            a = _subroot(d, sz, a);\r\n        }\r\n    if\
    \ (g > 1)\r\n        a = _subroot(g, 1, a);\r\n    return a;\r\n}\r\n\r\null floor_root(ull\
    \ a, ull k) {\r\n    if (a <= 1 or k == 1)\r\n        return a;\r\n    if (k >=\
    \ 64)\r\n        return 1;\r\n    if (k == 2)\r\n        return sqrtl(a);\r\n\
    \    constexpr ull LIM = -1;\r\n    if (a == LIM)\r\n        a--;\r\n    auto\
    \ mul = [&](ull &x, const ull &y) {\r\n        if (x <= LIM / y)\r\n         \
    \   x *= y;\r\n        else\r\n            x = LIM;\r\n    };\r\n    auto pw =\
    \ [&](ull x, ull t) -> ull {\r\n        ull y = 1;\r\n        while (t) {\r\n\
    \            if (t & 1)\r\n                mul(y, x);\r\n            mul(x, x);\r\
    \n            t >>= 1;\r\n        }\r\n        return y;\r\n    };\r\n    ull\
    \ ret = (k == 3 ? cbrt(a) - 1 : pow(a, nextafter(1 / double(k), 0)));\r\n    while\
    \ (pw(ret + 1, k) <= a)\r\n        ret++;\r\n    return ret;\r\n}\r\n\r\n/**\r\
    \n * @brief Primitive Function\r\n */"
  dependsOn:
  - Math/fastdiv.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/primitive.hpp
  requiredBy:
  - Math/binomquery.hpp
  - Convolution/multivariatecyclic.hpp
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_discrete_logarithm_mod.test.cpp
  - Verify/LC_binomial_coefficient.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
documentation_of: Math/primitive.hpp
layout: document
redirect_from:
- /library/Math/primitive.hpp
- /library/Math/primitive.hpp.html
title: Primitive Function
---
