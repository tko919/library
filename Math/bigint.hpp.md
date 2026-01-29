---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: Math/comb.hpp
    title: Combination
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Fast Division
  - icon: ':question:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':question:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Big Integer(Float)
    links: []
  bundledCode: "#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv {\n    using u64 =\
    \ uint64_t;\n    using u128 = __uint128_t;\n    constexpr FastDiv() : m(), s(),\
    \ x() {}\n    constexpr FastDiv(int _m)\n        : m(_m), s(__lg(m - 1)), x(((u128(1)\
    \ << (s + 64)) + m - 1) / m) {}\n    constexpr int get() {\n        return m;\n\
    \    }\n    constexpr friend u64 operator/(u64 n, const FastDiv &d) {\n      \
    \  return (u128(n) * d.x >> d.s) >> 64;\n    }\n    constexpr friend int operator%(u64\
    \ n, const FastDiv &d) {\n        return n - n / d * d.m;\n    }\n    constexpr\
    \ pair<u64, int> divmod(u64 n) const {\n        u64 q = n / (*this);\n       \
    \ return {q, n - q * m};\n    }\n    int m, s;\n    u64 x;\n};\n\nstruct FastDiv64\
    \ {\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n    u128 mod, mh,\
    \ ml;\n    explicit FastDiv64(u64 mod = 1) : mod(mod) {\n        u128 m = u128(-1)\
    \ / mod;\n        if (m * mod + mod == u128(0))\n            ++m;\n        mh\
    \ = m >> 64;\n        ml = m & u64(-1);\n    }\n    u64 umod() const {\n     \
    \   return mod;\n    }\n    u64 modulo(u128 x) {\n        u128 z = (x & u64(-1))\
    \ * ml;\n        z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n      \
    \  z = (x >> 64) * mh + (z >> 64);\n        x -= z * mod;\n        return x <\
    \ mod ? x : x - mod;\n    }\n    u64 mul(u64 a, u64 b) {\n        return modulo(u128(a)\
    \ * b);\n    }\n};\n\n/**\n * @brief Fast Division\n */\n#line 2 \"Math/miller.hpp\"\
    \n\r\nstruct m64 {\r\n    using i64 = int64_t;\r\n    using u64 = uint64_t;\r\n\
    \    using u128 = __uint128_t;\r\n\r\n    static u64 mod;\r\n    static u64 r;\r\
    \n    static u64 n2;\r\n\r\n    static u64 get_r() {\r\n        u64 ret = mod;\r\
    \n        rep(_,0,5) ret *= 2 - mod * ret;\r\n        return ret;\r\n    }\r\n\
    \r\n    static void set_mod(u64 m) {\r\n        assert(m < (1LL << 62));\r\n \
    \       assert((m & 1) == 1);\r\n        mod = m;\r\n        n2 = -u128(m) % m;\r\
    \n        r = get_r();\r\n        assert(r * mod == 1);\r\n    }\r\n    static\
    \ u64 get_mod() { return mod; }\r\n\r\n    u64 a;\r\n    m64() : a(0) {}\r\n \
    \   m64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\r\n\r\n    static\
    \ u64 reduce(const u128 &b) {\r\n        return (b + u128(u64(b) * u64(-r)) *\
    \ mod) >> 64;\r\n    }\r\n    u64 get() const {\r\n        u64 ret = reduce(a);\r\
    \n        return ret >= mod ? ret - mod : ret;\r\n    }\r\n    m64 &operator*=(const\
    \ m64 &b) {\r\n        a = reduce(u128(a) * b.a);\r\n        return *this;\r\n\
    \    }\r\n    m64 operator*(const m64 &b) const { return m64(*this) *= b; }\r\n\
    \    bool operator==(const m64 &b) const {\r\n        return (a >= mod ? a - mod\
    \ : a) == (b.a >= mod ? b.a - mod : b.a);\r\n    }\r\n    bool operator!=(const\
    \ m64 &b) const {\r\n        return (a >= mod ? a - mod : a) != (b.a >= mod ?\
    \ b.a - mod : b.a);\r\n    }\r\n    m64 pow(u128 n) const {\r\n        m64 ret(1),\
    \ mul(*this);\r\n        while (n > 0) {\r\n        if (n & 1) ret *= mul;\r\n\
    \        mul *= mul;\r\n        n >>= 1;\r\n        }\r\n        return ret;\r\
    \n    }\r\n};\r\ntypename m64::u64 m64::mod, m64::r, m64::n2;\r\n\r\nbool Miller(ll\
    \ n){\r\n    if(n<2 or (n&1)==0)return (n==2);\r\n    m64::set_mod(n);\r\n   \
    \ ll d=n-1; while((d&1)==0)d>>=1;\r\n    vector<ll> seeds;\r\n    if(n<(1<<30))seeds={2,\
    \ 7, 61};\r\n    else seeds={2, 325, 9375, 28178, 450775, 9780504};\r\n    for(auto&\
    \ x:seeds){\r\n        if(n<=x)break;\r\n        ll t=d;\r\n        m64 y=m64(x).pow(t);\r\
    \n        while(t!=n-1 and y!=1 and y!=n-1){\r\n            y*=y;\r\n        \
    \    t<<=1;\r\n        }\r\n        if(y!=n-1 and (t&1)==0)return 0;\r\n    }\
    \ return 1;\r\n}\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n#line 2 \"Utility/random.hpp\"\
    \n\r\nnamespace Random {\r\nmt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
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
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool multi, bool self>\r\
    \nvector<pair<int, int>> genGraph(int n, int m) {\r\n    vector<pair<int, int>>\
    \ cand, es;\r\n    rep(u, 0, n) rep(v, 0, n) {\r\n        if (!self and u == v)\r\
    \n            continue;\r\n        if (!directed and u > v)\r\n            continue;\r\
    \n        cand.push_back({u, v});\r\n    }\r\n    if (m == -1)\r\n        m =\
    \ get(SZ(cand));\r\n    // chmin(m, SZ(cand));\r\n    vector<int> ord;\r\n   \
    \ if (multi)\r\n        rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n   \
    \ else {\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    }\r\n    for (auto\
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
    \    }\r\n}\r\n\r\nvector<pair<ll, int>> Pollard2(ll n) {\r\n    auto ps = Pollard(n);\r\
    \n    sort(ALL(ps));\r\n    using P = pair<ll, int>;\r\n    vector<P> pes;\r\n\
    \    for (auto &p : ps) {\r\n        if (pes.empty() or pes.back().first != p)\
    \ {\r\n            pes.push_back({p, 1});\r\n        } else {\r\n            pes.back().second++;\r\
    \n        }\r\n    }\r\n    return pes;\r\n}\r\n\r\nvector<ll> EnumDivisors(ll\
    \ n) {\r\n    auto pes = Pollard2(n);\r\n    vector<ll> ret;\r\n    auto rec =\
    \ [&](auto &rec, int id, ll d) -> void {\r\n        if (id == SZ(pes)) {\r\n \
    \           ret.push_back(d);\r\n            return;\r\n        }\r\n        rec(rec,\
    \ id + 1, d);\r\n        rep(e, 0, pes[id].second) {\r\n            d *= pes[id].first;\r\
    \n            rec(rec, id + 1, d);\r\n        }\r\n    };\r\n    rec(rec, 0, 1);\r\
    \n    sort(ALL(ret));\r\n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\
    \n */\n#line 4 \"Math/primitive.hpp\"\n\r\nll mpow(ll a, ll t, ll m) {\r\n   \
    \ ll res = 1;\r\n    FastDiv64 im(m);\r\n    while (t) {\r\n        if (t & 1)\r\
    \n            res = im.modulo(__int128_t(res) * a);\r\n        a = im.modulo(__int128_t(a)\
    \ * a);\r\n        t >>= 1;\r\n    }\r\n    return res;\r\n}\r\nll minv(ll a,\
    \ ll m) {\r\n    ll b = m, u = 1, v = 0;\r\n    while (b) {\r\n        ll t =\
    \ a / b;\r\n        a -= t * b;\r\n        swap(a, b);\r\n        u -= t * v;\r\
    \n        swap(u, v);\r\n    }\r\n    u = (u % m + m) % m;\r\n    return u;\r\n\
    }\r\nll getPrimitiveRoot(ll p) {\r\n    vector<ll> ps = Pollard(p - 1);\r\n  \
    \  sort(ALL(ps));\r\n    rep(x, 1, inf) {\r\n        for (auto &q : ps) {\r\n\
    \            if (mpow(x, (p - 1) / q, p) == 1)\r\n                goto fail;\r\
    \n        }\r\n        return x;\r\n    fail:;\r\n    }\r\n    assert(0);\r\n\
    }\r\ntemplate <typename T> T extgcd(T a, T b, T &p, T &q) {\r\n    if (b == 0)\
    \ {\r\n        p = 1;\r\n        q = 0;\r\n        return a;\r\n    }\r\n    T\
    \ d = extgcd(b, a % b, q, p);\r\n    q -= a / b * p;\r\n    return d;\r\n}\r\n\
    template <typename T> pair<T, T> crt(vector<T> vs, vector<T> ms) {\r\n    T V\
    \ = vs[0], M = ms[0];\r\n    rep(i, 1, vs.size()) {\r\n        T p, q, v = vs[i],\
    \ m = ms[i];\r\n        if (M < m)\r\n            swap(M, m), swap(V, v);\r\n\
    \        T d = extgcd(M, m, p, q);\r\n        if ((v - V) % d != 0)\r\n      \
    \      return {0, -1};\r\n        T md = m / d, tmp = (v - V) / d % md * p % md;\r\
    \n        V += M * tmp;\r\n        M *= md;\r\n    }\r\n    V = (V % M + M) %\
    \ M;\r\n    return {V, M};\r\n}\r\nll garner(vector<ll> vs, vector<ll> p, int\
    \ mod) {\r\n    int sz = SZ(vs);\r\n    vector<ll> kp(sz + 1), rmul(sz + 1, 1);\r\
    \n    p.push_back(mod);\r\n    rep(i, 0, sz) {\r\n        ll x = (vs[i] - kp[i])\
    \ * minv(rmul[i], p[i]) % p[i];\r\n        if (x < 0)\r\n            x += p[i];\r\
    \n        rep(j, i + 1, sz + 1) {\r\n            kp[j] += rmul[j] * x;\r\n   \
    \         kp[j] %= p[j];\r\n            rmul[j] *= p[i];\r\n            rmul[j]\
    \ %= p[j];\r\n        }\r\n    }\r\n    return kp.back();\r\n}\r\n\r\nll ModLog(ll\
    \ a, ll b, ll p) {\r\n    ll g = 1;\r\n    for (ll t = p; t; t >>= 1)\r\n    \
    \    g = g * a % p;\r\n    g = __gcd(g, p);\r\n    ll t = 1, c = 0;\r\n    for\
    \ (; t % g; c++) {\r\n        if (t == b)\r\n            return c;\r\n       \
    \ t = t * a % p;\r\n    }\r\n    if (b % g)\r\n        return -1;\r\n    t /=\
    \ g, b /= g;\r\n    ll n = p / g, h = 0, gs = 1;\r\n    for (; h * h < n; h++)\r\
    \n        gs = gs * a % n;\r\n    unordered_map<ll, ll> bs;\r\n    for (ll s =\
    \ 0, e = b; s < h; bs[e] = ++s)\r\n        e = e * a % n;\r\n    for (ll s = 0,\
    \ e = t; s < n;) {\r\n        e = e * gs % n, s += h;\r\n        if (bs.count(e))\
    \ {\r\n            return c + s - bs[e];\r\n        }\r\n    }\r\n    return -1;\r\
    \n}\r\n\r\nll TonelliShanks(ll a, ll p) {\r\n    a %= p;\r\n    if (a == 0)\r\n\
    \        return 0;\r\n    if (p == 2)\r\n        return a;\r\n    if (mpow(a,\
    \ (p - 1) >> 1, p) != 1)\r\n        return -1;\r\n    ll b = 1;\r\n    while (mpow(b,\
    \ (p - 1) >> 1, p) == 1)\r\n        b = Random::get(1LL, p - 1);\r\n\r\n    ll\
    \ q = p - 1, k = 0;\r\n    while (q % 2 == 0) {\r\n        q >>= 1;\r\n      \
    \  k++;\r\n    }\r\n    ll x = mpow(a, (q + 1) >> 1, p);\r\n    b = mpow(b, q,\
    \ p);\r\n    k -= 2;\r\n    while (mpow(x, 2, p) != a) {\r\n        ll err = minv(a,\
    \ p) * mpow(x, 2, p) % p;\r\n        if (mpow(err, 1 << k, p) != 1)\r\n      \
    \      x = x * b % p;\r\n        b = mpow(b, 2, p);\r\n        k--;\r\n    }\r\
    \n    return x;\r\n}\r\n\r\nll mod_root(ll k, ll a, ll m) {\r\n    if (a == 0)\r\
    \n        return k ? 0 : -1;\r\n    if (m == 2)\r\n        return a & 1;\r\n \
    \   k %= m - 1;\r\n    ll g = gcd(k, m - 1);\r\n    if (mpow(a, (m - 1) / g, m)\
    \ != 1)\r\n        return -1;\r\n    a = mpow(a, minv(k / g, (m - 1) / g), m);\r\
    \n    FastDiv64 im(m);\r\n\r\n    auto _subroot = [&](ll p, int e, ll a) -> ll\
    \ { // x^(p^e)==a(mod m)\r\n        ll q = m - 1;\r\n        int s = 0;\r\n  \
    \      while (q % p == 0) {\r\n            q /= p;\r\n            s++;\r\n   \
    \     }\r\n        int d = s - e;\r\n        ll pe = mpow(p, e, m),\r\n      \
    \     res = mpow(a, ((pe - 1) * minv(q, pe) % pe * q + 1) / pe, m), c = 1;\r\n\
    \        while (mpow(c, (m - 1) / p, m) == 1)\r\n            c++;\r\n        c\
    \ = mpow(c, q, m);\r\n        map<ll, ll> mp;\r\n        ll v = 1, block = sqrt(d\
    \ * p) + 1,\r\n           bs = mpow(c, mpow(p, s - 1, m - 1) * block % (m - 1),\
    \ m);\r\n        rep(i, 0, block + 1) mp[v] = i, v = im.modulo(i128(v) * bs);\r\
    \n        ll gs = minv(mpow(c, mpow(p, s - 1, m - 1), m), m);\r\n        rep(i,\
    \ 0, d) {\r\n            ll err = im.modulo(i128(a) * minv(mpow(res, pe, m), m));\r\
    \n            ll pos = mpow(err, mpow(p, d - 1 - i, m - 1), m);\r\n          \
    \  rep(j, 0, block + 1) {\r\n                if (mp.count(pos)) {\r\n        \
    \            res = im.modulo(i128(res) *\r\n                                 \
    \   mpow(c,\r\n                                         (block * mp[pos] + j)\
    \ *\r\n                                             mpow(p, i, m - 1) % (m - 1),\r\
    \n                                         m));\r\n                    break;\r\
    \n                }\r\n                pos = im.modulo(i128(pos) * gs);\r\n  \
    \          }\r\n        }\r\n        return res;\r\n    };\r\n\r\n    for (ll\
    \ d = 2; d * d <= g; d++)\r\n        if (g % d == 0) {\r\n            int sz =\
    \ 0;\r\n            while (g % d == 0) {\r\n                g /= d;\r\n      \
    \          sz++;\r\n            }\r\n            a = _subroot(d, sz, a);\r\n \
    \       }\r\n    if (g > 1)\r\n        a = _subroot(g, 1, a);\r\n    return a;\r\
    \n}\r\n\r\null floor_root(ull a, ull k) {\r\n    if (a <= 1 or k == 1)\r\n   \
    \     return a;\r\n    if (k >= 64)\r\n        return 1;\r\n    if (k == 2)\r\n\
    \        return sqrtl(a);\r\n    constexpr ull LIM = -1;\r\n    if (a == LIM)\r\
    \n        a--;\r\n    auto mul = [&](ull &x, const ull &y) {\r\n        if (x\
    \ <= LIM / y)\r\n            x *= y;\r\n        else\r\n            x = LIM;\r\
    \n    };\r\n    auto pw = [&](ull x, ull t) -> ull {\r\n        ull y = 1;\r\n\
    \        while (t) {\r\n            if (t & 1)\r\n                mul(y, x);\r\
    \n            mul(x, x);\r\n            t >>= 1;\r\n        }\r\n        return\
    \ y;\r\n    };\r\n    ull ret = (k == 3 ? cbrt(a) - 1 : pow(a, nextafter(1 / double(k),\
    \ 0)));\r\n    while (pw(ret + 1, k) <= a)\r\n        ret++;\r\n    return ret;\r\
    \n}\r\n\r\n/**\r\n * @brief Primitive Function\r\n */\n#line 3 \"Convolution/ntt.hpp\"\
    \n\r\ntemplate <typename T> struct NTT {\r\n    static constexpr int rank2 = __builtin_ctzll(T::get_mod()\
    \ - 1);\r\n    std::array<T, rank2 + 1> root;  // root[i]^(2^i) == 1\r\n    std::array<T,\
    \ rank2 + 1> iroot; // root[i] * iroot[i] == 1\r\n\r\n    std::array<T, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\r\n    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;\r\
    \n\r\n    std::array<T, std::max(0, rank2 - 3 + 1)> rate3;\r\n    std::array<T,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\r\n\r\n    NTT() {\r\n        T g = getPrimitiveRoot(T::get_mod());\r\
    \n        root[rank2] = g.pow((T::get_mod() - 1) >> rank2);\r\n        iroot[rank2]\
    \ = root[rank2].inv();\r\n        for (int i = rank2 - 1; i >= 0; i--) {\r\n \
    \           root[i] = root[i + 1] * root[i + 1];\r\n            iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n        }\r\n\r\n        {\r\n            T prod = 1,\
    \ iprod = 1;\r\n            for (int i = 0; i <= rank2 - 2; i++) {\r\n       \
    \         rate2[i] = root[i + 2] * prod;\r\n                irate2[i] = iroot[i\
    \ + 2] * iprod;\r\n                prod *= iroot[i + 2];\r\n                iprod\
    \ *= root[i + 2];\r\n            }\r\n        }\r\n        {\r\n            T\
    \ prod = 1, iprod = 1;\r\n            for (int i = 0; i <= rank2 - 3; i++) {\r\
    \n                rate3[i] = root[i + 3] * prod;\r\n                irate3[i]\
    \ = iroot[i + 3] * iprod;\r\n                prod *= iroot[i + 3];\r\n       \
    \         iprod *= root[i + 3];\r\n            }\r\n        }\r\n    }\r\n\r\n\
    \    void ntt(std::vector<T> &a, bool type = 0) {\r\n        int n = int(a.size());\r\
    \n        int h = __builtin_ctzll((unsigned int)n);\r\n        a.resize(1 << h);\r\
    \n\r\n        if (type) {\r\n            int len = h; // a[i, i+(n>>len), i+2*(n>>len),\
    \ ..] is transformed\r\n            while (len) {\r\n                if (len ==\
    \ 1) {\r\n                    int p = 1 << (h - len);\r\n                    T\
    \ irot = 1;\r\n                    for (int s = 0; s < (1 << (len - 1)); s++)\
    \ {\r\n                        int offset = s << (h - len + 1);\r\n          \
    \              for (int i = 0; i < p; i++) {\r\n                            auto\
    \ l = a[i + offset];\r\n                            auto r = a[i + offset + p];\r\
    \n                            a[i + offset] = l + r;\r\n                     \
    \       a[i + offset + p] =\r\n                                ((unsigned long\
    \ long)(T::get_mod() + l.v -\r\n                                             \
    \         r.v) *\r\n                                 irot.v) %\r\n           \
    \                     T::get_mod();\r\n                        }\r\n         \
    \               if (s + 1 != (1 << (len - 1)))\r\n                           \
    \ irot *= irate2[__builtin_ctzll(~(unsigned int)(s))];\r\n                   \
    \ }\r\n                    len--;\r\n                } else {\r\n            \
    \        // 4-base\r\n                    int p = 1 << (h - len);\r\n        \
    \            T irot = 1, iimag = iroot[2];\r\n                    for (int s =\
    \ 0; s < (1 << (len - 2)); s++) {\r\n                        T irot2 = irot *\
    \ irot;\r\n                        T irot3 = irot2 * irot;\r\n               \
    \         int offset = s << (h - len + 2);\r\n                        for (int\
    \ i = 0; i < p; i++) {\r\n                            auto a0 = 1ULL * a[i + offset\
    \ + 0 * p].v;\r\n                            auto a1 = 1ULL * a[i + offset + 1\
    \ * p].v;\r\n                            auto a2 = 1ULL * a[i + offset + 2 * p].v;\r\
    \n                            auto a3 = 1ULL * a[i + offset + 3 * p].v;\r\n\r\n\
    \                            auto a2na3iimag =\r\n                           \
    \     1ULL * T((T::get_mod() + a2 - a3) * iimag.v).v;\r\n\r\n                \
    \            a[i + offset] = (a0 + a1 + a2 + a3) % T::get_mod();\r\n         \
    \                   a[i + offset + 1 * p] =\r\n                              \
    \  (a0 + (T::get_mod() - a1) + a2na3iimag) *\r\n                             \
    \   irot.v % T::get_mod();\r\n                            a[i + offset + 2 * p]\
    \ =\r\n                                (a0 + a1 + (T::get_mod() - a2) +\r\n  \
    \                               (T::get_mod() - a3)) *\r\n                   \
    \             irot2.v % T::get_mod();\r\n                            a[i + offset\
    \ + 3 * p] =\r\n                                (a0 + (T::get_mod() - a1) +\r\n\
    \                                 (T::get_mod() - a2na3iimag)) *\r\n         \
    \                       irot3.v % T::get_mod();\r\n                        }\r\
    \n                        if (s + 1 != (1 << (len - 2)))\r\n                 \
    \           irot *= irate3[__builtin_ctzll(~(unsigned int)(s))];\r\n         \
    \           }\r\n                    len -= 2;\r\n                }\r\n      \
    \      }\r\n            T e = T(n).inv();\r\n            for (auto &x : a)\r\n\
    \                x *= e;\r\n        } else {\r\n            int len = 0; // a[i,\
    \ i+(n>>len), i+2*(n>>len), ..] is transformed\r\n            while (len < h)\
    \ {\r\n                if (h - len == 1) {\r\n                    int p = 1 <<\
    \ (h - len - 1);\r\n                    T rot = 1;\r\n                    for\
    \ (int s = 0; s < (1 << len); s++) {\r\n                        int offset = s\
    \ << (h - len);\r\n                        for (int i = 0; i < p; i++) {\r\n \
    \                           auto l = a[i + offset];\r\n                      \
    \      auto r = a[i + offset + p] * rot;\r\n                            a[i +\
    \ offset] = l + r;\r\n                            a[i + offset + p] = l - r;\r\
    \n                        }\r\n                        if (s + 1 != (1 << len))\r\
    \n                            rot *= rate2[__builtin_ctzll(~(unsigned int)(s))];\r\
    \n                    }\r\n                    len++;\r\n                } else\
    \ {\r\n                    // 4-base\r\n                    int p = 1 << (h -\
    \ len - 2);\r\n                    T rot = 1, imag = root[2];\r\n            \
    \        for (int s = 0; s < (1 << len); s++) {\r\n                        T rot2\
    \ = rot * rot;\r\n                        T rot3 = rot2 * rot;\r\n           \
    \             int offset = s << (h - len);\r\n                        for (int\
    \ i = 0; i < p; i++) {\r\n                            auto mod2 = 1ULL * T::get_mod()\
    \ * T::get_mod();\r\n                            auto a0 = 1ULL * a[i + offset].v;\r\
    \n                            auto a1 = 1ULL * a[i + offset + p].v * rot.v;\r\n\
    \                            auto a2 = 1ULL * a[i + offset + 2 * p].v * rot2.v;\r\
    \n                            auto a3 = 1ULL * a[i + offset + 3 * p].v * rot3.v;\r\
    \n                            auto a1na3imag =\r\n                           \
    \     1ULL * T(a1 + mod2 - a3).v * imag.v;\r\n                            auto\
    \ na2 = mod2 - a2;\r\n                            a[i + offset] = (a0 + a2 + a1\
    \ + a3) % T::get_mod();\r\n                            a[i + offset + 1 * p] =\r\
    \n                                (a0 + a2 + (2 * mod2 - (a1 + a3))) %\r\n   \
    \                             T::get_mod();\r\n                            a[i\
    \ + offset + 2 * p] =\r\n                                (a0 + na2 + a1na3imag)\
    \ % T::get_mod();\r\n                            a[i + offset + 3 * p] =\r\n \
    \                               (a0 + na2 + (mod2 - a1na3imag)) % T::get_mod();\r\
    \n                        }\r\n                        if (s + 1 != (1 << len))\r\
    \n                            rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];\r\
    \n                    }\r\n                    len += 2;\r\n                }\r\
    \n            }\r\n        }\r\n    }\r\n    vector<T> mult(const vector<T> &a,\
    \ const vector<T> &b) {\r\n        if (a.empty() or b.empty())\r\n           \
    \ return vector<T>();\r\n        int as = a.size(), bs = b.size();\r\n       \
    \ int n = as + bs - 1;\r\n        assert(n <= (1 << rank2));\r\n        if (as\
    \ <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n                return mult(b,\
    \ a);\r\n            vector<T> res(n);\r\n            rep(i, 0, as) rep(j, 0,\
    \ bs) res[i + j] += a[i] * b[j];\r\n            return res;\r\n        }\r\n \
    \       int m = 1;\r\n        while (m < n)\r\n            m <<= 1;\r\n      \
    \  vector<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\n        ntt(res);\r\
    \n        if (a == b)\r\n            rep(i, 0, m) res[i] *= res[i];\r\n      \
    \  else {\r\n            vector<T> c(m);\r\n            rep(i, 0, bs) c[i] = b[i];\r\
    \n            ntt(c);\r\n            rep(i, 0, m) res[i] *= c[i];\r\n        }\r\
    \n        ntt(res, 1);\r\n        res.resize(n);\r\n        return res;\r\n  \
    \  }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\n */\n#line 2\
    \ \"Math/comb.hpp\"\n\ntemplate <typename T> T Inv(ll n) {\n    static int md;\n\
    \    static vector<T> buf({0, 1});\n    if (md != T::get_mod()) {\n        md\
    \ = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n    assert(n > 0);\n\
    \    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf), q = (md +\
    \ k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n    return\
    \ buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n    static\
    \ int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md != T::get_mod())\
    \ {\n        md = T::get_mod();\n        buf = ibuf = vector<T>({1, 1});\n   \
    \ }\n    assert(n >= 0 and n < md);\n    while (SZ(buf) <= n) {\n        buf.push_back(buf.back()\
    \ * SZ(buf));\n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\n    }\n\
    \    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate <typename T> T nPr(int n, int\
    \ r, bool inv = 0) {\n    if (n < 0 || n < r || r < 0)\n        return 0;\n  \
    \  return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\n}\ntemplate <typename T>\
    \ T nCr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r || r < 0)\n    \
    \    return 0;\n    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n -\
    \ r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename T> T nHr(int n, int\
    \ r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1, inv);\n}\n// [x^n]C(x)^k\n\
    template <typename T> T Catalan(int n, int k) {\n    if (k == 0)\n        return\
    \ (n == 0 ? 1 : 0);\n    return T(k) * Inv<T>(n * 2 + k) * nCr<T>(n * 2 + k, n);\n\
    }\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T choose(int\
    \ n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return nCr<T>(n\
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"Math/modint.hpp\"\
    \n\r\ntemplate <unsigned mod = 1000000007> struct fp {\r\n    static_assert(mod\
    \ < uint(1) << 31);\r\n    unsigned v;\r\n    static constexpr int get_mod() {\r\
    \n        return mod;\r\n    }\r\n    constexpr unsigned inv() const {\r\n   \
    \     assert(v != 0);\r\n        int x = v, y = mod, p = 1, q = 0, t = 0, tmp\
    \ = 0;\r\n        while (y > 0) {\r\n            t = x / y;\r\n            x -=\
    \ t * y, p -= t * q;\r\n            tmp = x, x = y, y = tmp;\r\n            tmp\
    \ = p, p = q, q = tmp;\r\n        }\r\n        if (p < 0)\r\n            p +=\
    \ mod;\r\n        return p;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x >= 0\
    \ ? x % mod : (mod - (-x) % mod) % mod) {}\r\n    fp operator-() const {\r\n \
    \       return fp() - *this;\r\n    }\r\n    fp pow(ull t) {\r\n        fp res\
    \ = 1, b = *this;\r\n        while (t) {\r\n            if (t & 1)\r\n       \
    \         res *= b;\r\n            b *= b;\r\n            t >>= 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n    fp &operator+=(const fp &x) {\r\n \
    \       if ((v += x.v) >= mod)\r\n            v -= mod;\r\n        return *this;\r\
    \n    }\r\n    fp &operator-=(const fp &x) {\r\n        if ((v += mod - x.v) >=\
    \ mod)\r\n            v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator*=(const\
    \ fp &x) {\r\n        v = ull(v) * x.v % mod;\r\n        return *this;\r\n   \
    \ }\r\n    fp &operator/=(const fp &x) {\r\n        if (x.v < 15000000) {\r\n\
    \            return *this *= Inv<fp>(x.v);\r\n        }\r\n        v = ull(v)\
    \ * x.inv() % mod;\r\n        return *this;\r\n    }\r\n    fp operator+(const\
    \ fp &x) const {\r\n        return fp(*this) += x;\r\n    }\r\n    fp operator-(const\
    \ fp &x) const {\r\n        return fp(*this) -= x;\r\n    }\r\n    fp operator*(const\
    \ fp &x) const {\r\n        return fp(*this) *= x;\r\n    }\r\n    fp operator/(const\
    \ fp &x) const {\r\n        return fp(*this) /= x;\r\n    }\r\n    bool operator==(const\
    \ fp &x) const {\r\n        return v == x.v;\r\n    }\r\n    bool operator!=(const\
    \ fp &x) const {\r\n        return v != x.v;\r\n    }\r\n    friend istream &operator>>(istream\
    \ &is, fp &x) {\r\n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const fp &x) {\r\n        return os << x.v;\r\n    }\r\n};\r\n\r\ntemplate\
    \ <unsigned mod> void rd(fp<mod> &x) {\r\n    fastio::rd(x.v);\r\n}\r\ntemplate\
    \ <unsigned mod> void wt(fp<mod> x) {\r\n    fastio::wt(x.v);\r\n}\r\n\r\n/**\r\
    \n * @brief Modint\r\n */\n#line 4 \"Convolution/arbitrary.hpp\"\n\r\nusing M1\
    \ = fp<469762049>;  // 2^26\r\nusing M2 = fp<1811939329>; // 2^26\r\nusing M3\
    \ = fp<2013265921>; // 2^27\r\nNTT<M1> N1;\r\nNTT<M2> N2;\r\nNTT<M3> N3;\r\nconstexpr\
    \ uint r_12 = M2(M1::get_mod()).inv();\r\nconstexpr uint r_13 = M3(M1::get_mod()).inv();\r\
    \nconstexpr uint r_23 = M3(M2::get_mod()).inv();\r\nconstexpr uint r_1323 = M3(ll(r_13)\
    \ * r_23).v;\r\nconstexpr ll w1 = M1::get_mod();\r\nconstexpr ll w2 = ll(w1) *\
    \ M2::get_mod();\r\ntemplate <typename T>\r\nvector<T> ArbitraryMultint(const\
    \ vector<int> &a, const vector<int> &b) {\r\n    if (a.empty() or b.empty())\r\
    \n        return vector<T>();\r\n    int n = a.size() + b.size() - 1;\r\n    vector<T>\
    \ res(n);\r\n    if (min(a.size(), b.size()) <= 60) {\r\n        rep(i, 0, a.size())\
    \ rep(j, 0, b.size()) res[i + j] += T(a[i]) * b[j];\r\n        return res;\r\n\
    \    }\r\n    vector<ll> vals[3];\r\n    vector<M1> a1(ALL(a)), b1(ALL(b)), c1\
    \ = N1.mult(a1, b1);\r\n    vector<M2> a2(ALL(a)), b2(ALL(b)), c2 = N2.mult(a2,\
    \ b2);\r\n    vector<M3> a3(ALL(a)), b3(ALL(b)), c3 = N3.mult(a3, b3);\r\n   \
    \ for (M1 x : c1)\r\n        vals[0].push_back(x.v);\r\n    for (M2 x : c2)\r\n\
    \        vals[1].push_back(x.v);\r\n    for (M3 x : c3)\r\n        vals[2].push_back(x.v);\r\
    \n    rep(i, 0, n) {\r\n        ll p = vals[0][i];\r\n        ll q = (vals[1][i]\
    \ + M2::get_mod() - p) * r_12 % M2::get_mod();\r\n        ll r = ((vals[2][i]\
    \ + M3::get_mod() - p) * r_1323 +\r\n                (M3::get_mod() - q) * r_23)\
    \ %\r\n               M3::get_mod();\r\n        res[i] = (T(r) * w2 + q * w1 +\
    \ p);\r\n    }\r\n    return res;\r\n}\r\n\r\ntemplate <typename T>\r\nvector<T>\
    \ ArbitraryMult(const vector<T> &a, const vector<T> &b) {\r\n    vector<int> A,\
    \ B;\r\n    for (auto &x : a)\r\n        A.push_back(x.v);\r\n    for (auto &x\
    \ : b)\r\n        B.push_back(x.v);\r\n    return ArbitraryMultint<T>(A, B);\r\
    \n}\r\n\r\n/**\r\n * @brief Arbitrary Mod Convolution\r\n */\n#line 3 \"Math/bigint.hpp\"\
    \n\r\ntemplate <int D> struct bigint {\r\n    using u128 = __uint128_t;\r\n  \
    \  static const int B = pow(10, D);\r\n    int sign = 0;\r\n    vector<int> v;\r\
    \n    static int get_D() { return D; }\r\n    static int get_B() { return B; }\r\
    \n    bigint() {}\r\n    bigint(const vector<int> &_v, bool _s = false) : sign(_s),\
    \ v(_v) {}\r\n    bigint(ll x) {\r\n        if (x < 0)\r\n            x *= -1,\
    \ sign = 1;\r\n        while (x) {\r\n            v.push_back(x % B);\r\n    \
    \        x /= B;\r\n        }\r\n    }\r\n    bigint(string s) {\r\n        if\
    \ (s[0] == '-')\r\n            s.erase(s.begin()), sign = 1;\r\n        int add\
    \ = 0, cnt = 0, base = 1;\r\n        while (s.size()) {\r\n            if (cnt\
    \ == D) {\r\n                v.push_back(add);\r\n                cnt = 0;\r\n\
    \                add = 0;\r\n                base = 1;\r\n            }\r\n  \
    \          add = (s.back() - '0') * base + add;\r\n            cnt++;\r\n    \
    \        base *= 10;\r\n            s.pop_back();\r\n        }\r\n        if (add)\r\
    \n            v.push_back(add);\r\n    }\r\n    bigint operator-() const {\r\n\
    \        bigint res = *this;\r\n        res.sign ^= 1;\r\n        return res;\r\
    \n    }\r\n    bigint abs() const {\r\n        bigint res = *this;\r\n       \
    \ res.sign = 0;\r\n        return res;\r\n    }\r\n    int &operator[](const int\
    \ i) { return v[i]; }\r\n    int size() const { return v.size(); }\r\n    void\
    \ norm() {\r\n        rep(i, 0, v.size() - 1) {\r\n            if (v[i] >= 0)\
    \ {\r\n                v[i + 1] += v[i] / B;\r\n                v[i] %= B;\r\n\
    \            } else {\r\n                int c = (-v[i] + B - 1) / B;\r\n    \
    \            v[i] += c * B;\r\n                v[i + 1] -= c;\r\n            }\r\
    \n        }\r\n        while (!v.empty() and v.back() >= B) {\r\n            int\
    \ c = v.back() / B;\r\n            v.back() %= B;\r\n            v.push_back(c);\r\
    \n        }\r\n        while (!v.empty() and v.back() == 0)\r\n            v.pop_back();\r\
    \n    }\r\n    string to_str() const {\r\n        string res;\r\n        if (v.empty())\r\
    \n            return \"0\";\r\n        if (sign)\r\n            res += '-';\r\n\
    \        res += to_string(v.back());\r\n        for (int i = v.size() - 2; i >=\
    \ 0; i--) {\r\n            string add;\r\n            int w = v[i];\r\n      \
    \      rep(_, 0, D) {\r\n                add += ('0' + (w % 10));\r\n        \
    \        w /= 10;\r\n            }\r\n            reverse(ALL(add));\r\n     \
    \       res += add;\r\n        }\r\n        return res;\r\n    }\r\n    friend\
    \ istream &operator>>(istream &is, bigint<D> &x) {\r\n        string tmp;\r\n\
    \        is >> tmp;\r\n        x = bigint(tmp);\r\n        return is;\r\n    }\r\
    \n    friend ostream &operator<<(ostream &os, bigint<D> x) {\r\n        os <<\
    \ x.to_str();\r\n        return os;\r\n    }\r\n    bigint &operator<<=(const\
    \ int &x) {\r\n        if (!v.empty()) {\r\n            vector<int> add(x, 0);\r\
    \n            v.insert(v.begin(), ALL(add));\r\n        }\r\n        return *this;\r\
    \n    }\r\n    bigint &operator>>=(const int &x) {\r\n        v = vector<int>(v.begin()\
    \ + min(x, (int)v.size()), v.end());\r\n        return *this;\r\n    }\r\n   \
    \ bigint &operator+=(const bigint &x) {\r\n        if (sign != x.sign) {\r\n \
    \           *this -= (-x);\r\n            return *this;\r\n        }\r\n     \
    \   if ((int)v.size() < (int)x.size())\r\n            v.resize(x.size(), 0);\r\
    \n        rep(i, 0, x.size()) { v[i] += x.v[i]; }\r\n        norm();\r\n     \
    \   return *this;\r\n    }\r\n    bigint &operator-=(const bigint &x) {\r\n  \
    \      if (sign != x.sign) {\r\n            *this += (-x);\r\n            return\
    \ *this;\r\n        }\r\n        if (abs() < x.abs()) {\r\n            *this =\
    \ x - (*this);\r\n            sign ^= 1;\r\n            return *this;\r\n    \
    \    }\r\n        rep(i, 0, x.size()) { v[i] -= x.v[i]; }\r\n        norm();\r\
    \n        return *this;\r\n    }\r\n    bigint &operator*=(const bigint &x) {\r\
    \n        sign ^= x.sign;\r\n        auto v1 = ArbitraryMult<u128>(v, x.v);\r\n\
    \        u128 add = 0;\r\n        v.clear();\r\n        v.reserve(v1.size() +\
    \ 3);\r\n        for (int i = 0;; i++) {\r\n            if (i >= int(v1.size())\
    \ and add == 0)\r\n                break;\r\n            if (i < int(v1.size()))\r\
    \n                add += v1[i];\r\n            v.push_back(add % B);\r\n     \
    \       add /= B;\r\n        }\r\n        norm();\r\n        return *this;\r\n\
    \    }\r\n    bigint div_naive(const bigint &a, const bigint &b) {\r\n       \
    \ if (SZ(b) == 1)\r\n            return a.div(b.v.back());\r\n        if (a <\
    \ b)\r\n            return bigint();\r\n        int norm = B / (b.v.back() + 1);\r\
    \n        bigint x = a.mul(norm), y = b.mul(norm);\r\n        int yb = y.v.back();\r\
    \n        bigint quo, rem;\r\n        quo.v.resize(x.size() - y.size() + 1);\r\
    \n        rem.v = {x.v.end() - y.size(), x.v.end()};\r\n        for (int i = x.size()\
    \ - y.size(); i >= 0; i--) {\r\n            if (rem.size() == y.size()) {\r\n\
    \                if (rem >= y) {\r\n                    quo[i] = 1;\r\n      \
    \              rem -= y;\r\n                }\r\n            } else if (rem.size()\
    \ > y.size()) {\r\n                ll rb = ll(rem.v.back()) * B + rem[rem.size()\
    \ - 2];\r\n                int q = rb / yb;\r\n                bigint yq = y.mul(q);\r\
    \n                while (rem < yq) {\r\n                    q--;\r\n         \
    \           yq -= y;\r\n                }\r\n                rem -= yq;\r\n  \
    \              while (rem >= y) {\r\n                    q++;\r\n            \
    \        rem -= y;\r\n                }\r\n                quo[i] = q;\r\n   \
    \         }\r\n            if (i)\r\n                rem.v.insert(rem.v.begin(),\
    \ x[i - 1]);\r\n        }\r\n        return quo;\r\n    }\r\n    bigint &operator/=(const\
    \ bigint &x) {\r\n        bigint a = abs(), b = x.abs();\r\n        sign ^= x.sign;\r\
    \n        if (a < b)\r\n            return *this = bigint();\r\n        if (b.size()\
    \ == 1)\r\n            return *this = a.div(b.v.back());\r\n\r\n        int deg\
    \ = a.size() - b.size() + 2, k = deg;\r\n        while (k > 64)\r\n          \
    \  k = (k + 1) >> 1;\r\n        bigint base(1);\r\n        base <<= (b.size()\
    \ + k);\r\n        bigint inv(div_naive(base, b));\r\n\r\n        while (k < deg)\
    \ {\r\n            bigint y = inv.square();\r\n            y.v.insert(y.v.begin(),\
    \ 0);\r\n            int l = min(SZ(b), k * 2 + 1);\r\n            bigint pref;\r\
    \n            pref.v = {b.v.end() - l, b.v.end()};\r\n            y *= pref;\r\
    \n            y >>= l;\r\n            inv = inv + inv;\r\n            inv <<=\
    \ k + 1;\r\n            inv -= y;\r\n            inv.v.erase(inv.v.begin());\r\
    \n            k <<= 1;\r\n        }\r\n        inv >>= (k - deg);\r\n\r\n    \
    \    (*this) = a * inv;\r\n        (*this) >>= int(a.size() + 2);\r\n        bigint\
    \ mul = (*this) * b;\r\n        while (mul + b <= a) {\r\n            (*this)\
    \ += bigint(1);\r\n            mul += b;\r\n        }\r\n        while (mul >\
    \ a) {\r\n            (*this) -= bigint(1);\r\n            mul -= b;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    bigint &operator%=(const bigint\
    \ &x) {\r\n        bigint div = (*this) / x;\r\n        (*this) -= div * x;\r\n\
    \        return *this;\r\n    }\r\n    bigint square() const {\r\n        bigint\
    \ ret;\r\n        auto v1 = ArbitraryMult<u128>(v, v);\r\n        u128 add = 0;\r\
    \n        ret.v.reserve(v1.size() + 3);\r\n        for (int i = 0;; i++) {\r\n\
    \            if (i >= int(v1.size()) and add == 0)\r\n                break;\r\
    \n            if (i < int(v1.size()))\r\n                add += v1[i];\r\n   \
    \         ret.v.push_back(add % B);\r\n            add /= B;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    bigint mul(ll x) const {\r\n        bigint\
    \ res;\r\n        if (x < 0)\r\n            res.sign ^= 1, x *= -1;\r\n      \
    \  u128 add = 0;\r\n        res.v.reserve(v.size() + 3);\r\n        for (int i\
    \ = 0;; i++) {\r\n            if (i >= int(v.size()) and add == 0)\r\n       \
    \         break;\r\n            if (i < int(v.size()))\r\n                add\
    \ += ll(v[i]) * x;\r\n            res.v.push_back(add % B);\r\n            add\
    \ /= B;\r\n        }\r\n        return res;\r\n    }\r\n    bigint div(ll x) const\
    \ {\r\n        bigint res = *this;\r\n        if (x < 0)\r\n            res.sign\
    \ ^= 1, x *= -1;\r\n        ll add = 0;\r\n        for (int i = res.v.size() -\
    \ 1; i >= 0; i--) {\r\n            add = add * B + res.v[i];\r\n            int\
    \ q = add / x, r = add % x;\r\n            res.v[i] = q, add = r;\r\n        }\r\
    \n        res.norm();\r\n        return res;\r\n    }\r\n    bigint operator<<(const\
    \ int &x) const { return bigint(*this) <<= x; }\r\n    bigint operator>>(const\
    \ int &x) const { return bigint(*this) >>= x; }\r\n    bigint operator+(const\
    \ bigint &x) const { return bigint(*this) += x; }\r\n    bigint operator-(const\
    \ bigint &x) const { return bigint(*this) -= x; }\r\n    bigint operator*(const\
    \ bigint &x) const { return bigint(*this) *= x; }\r\n    bigint operator/(const\
    \ bigint &x) const { return bigint(*this) /= x; }\r\n    bigint operator%(const\
    \ bigint &x) const { return bigint(*this) %= x; }\r\n    bool operator<(const\
    \ bigint &x) const {\r\n        if (sign != x.sign)\r\n            return sign\
    \ > x.sign;\r\n        if ((int)v.size() != (int)x.size()) {\r\n            if\
    \ (sign)\r\n                return (int)x.size() < (int)v.size();\r\n        \
    \    else\r\n                return (int)v.size() < (int)x.size();\r\n       \
    \ }\r\n        for (int i = v.size() - 1; i >= 0; i--)\r\n            if (v[i]\
    \ != x.v[i]) {\r\n                if (sign)\r\n                    return x.v[i]\
    \ < v[i];\r\n                else\r\n                    return v[i] < x.v[i];\r\
    \n            }\r\n        return false;\r\n    }\r\n    bool operator>(const\
    \ bigint &x) const { return x < *this; }\r\n    bool operator<=(const bigint &x)\
    \ const { return !(*this > x); }\r\n    bool operator>=(const bigint &x) const\
    \ { return !(*this < x); }\r\n    bool operator==(const bigint &x) const {\r\n\
    \        return !(*this < x) and !(*this > x);\r\n    }\r\n    bool operator!=(const\
    \ bigint &x) const { return !(*this == x); }\r\n};\r\ntypedef bigint<9> Bigint;\r\
    \n\r\nstruct Bigfloat {\r\n    Bigint v;\r\n    int p = 0;\r\n    Bigfloat() {}\r\
    \n    Bigfloat(const ll &_v) { v = Bigint(_v); }\r\n    Bigfloat(const Bigint\
    \ &_v, int _p = 0) : v(_v), p(_p) {}\r\n    void set(int _p) {\r\n        if (p\
    \ < _p) {\r\n            v >>= (_p - p);\r\n        } else {\r\n            v\
    \ <<= (p - _p);\r\n        }\r\n        p = _p;\r\n    }\r\n    Bigint to_int()\
    \ const {\r\n        if (p < 0)\r\n            return v >> (-p);\r\n        else\r\
    \n            return v << p;\r\n    }\r\n    Bigfloat &operator+=(const Bigfloat\
    \ &x) {\r\n        if (p > x.p)\r\n            set(x.p), v += x.v;\r\n       \
    \ else\r\n            v += x.v << (x.p - p);\r\n        return *this;\r\n    }\r\
    \n    Bigfloat &operator-=(const Bigfloat &x) {\r\n        if (p > x.p)\r\n  \
    \          set(x.p), v -= x.v;\r\n        else\r\n            v -= x.v << (x.p\
    \ - p);\r\n        return *this;\r\n    }\r\n    Bigfloat square() {\r\n     \
    \   Bigfloat res = *this;\r\n        res.p *= 2;\r\n        res.v = res.v.square();\r\
    \n        return res;\r\n    }\r\n    Bigfloat mul(ll x) {\r\n        Bigfloat\
    \ res = *this;\r\n        res.v = v.mul(x);\r\n        return res;\r\n    }\r\n\
    \    Bigfloat div(ll x) {\r\n        Bigfloat res = *this;\r\n        res.v =\
    \ v.div(x);\r\n        return res;\r\n    }\r\n    Bigfloat &operator*=(const\
    \ Bigfloat &x) {\r\n        p += x.p;\r\n        v *= x.v;\r\n        return *this;\r\
    \n    }\r\n    Bigfloat &operator/=(const Bigfloat &x) {\r\n        p -= x.p;\r\
    \n        v /= x.v;\r\n        return *this;\r\n    }\r\n    Bigfloat operator+(const\
    \ Bigfloat &x) const { return Bigfloat(*this) += x; }\r\n    Bigfloat operator-(const\
    \ Bigfloat &x) const { return Bigfloat(*this) -= x; }\r\n    Bigfloat operator*(const\
    \ Bigfloat &x) const { return Bigfloat(*this) *= x; }\r\n    Bigfloat operator/(const\
    \ Bigfloat &x) const { return Bigfloat(*this) /= x; }\r\n    string to_str() {\r\
    \n        string res = v.abs().to_str();\r\n        int d = Bigint::get_D();\r\
    \n        if (p * d > 0)\r\n            res += string(p * d, '0');\r\n       \
    \ else if (-p * d >= 1 and -p * d < (int)res.size()) {\r\n            res = res.substr(0,\
    \ (int)res.size() + p * d) + '.' +\r\n                  res.substr((int)res.size()\
    \ + p * d);\r\n        } else if (-p * d >= (int)res.size())\r\n            res\
    \ = \"0.\" + string(-p * d - (int)res.size(), '0') + res;\r\n        if (v.sign)\
    \ {\r\n            res.insert(res.begin(), '-');\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    friend ostream &operator<<(ostream &os, Bigfloat x) {\r\
    \n        os << x.to_str();\r\n        return os;\r\n    }\r\n};\r\n\r\nBigfloat\
    \ sqrt(ll n, int d) {\r\n    Bigfloat res(Bigint((ll)sqrt(1LL * Bigint::get_B()\
    \ * Bigint::get_B() / n)),\r\n                 -1),\r\n        pre;\r\n    int\
    \ cur = 1;\r\n    while (pre.v != res.v) {\r\n        cur = min(cur << 1, d);\r\
    \n        pre = res;\r\n        Bigfloat add = Bigfloat(1) - res.square().mul(n);\r\
    \n        add.set(-cur);\r\n        res += (res * add).div(2);\r\n        res.set(-cur);\r\
    \n    }\r\n    return res.mul(n);\r\n}\r\n\r\n/**\r\n * @brief Big Integer(Float)\r\
    \n */\n"
  code: "#pragma once\r\n#include \"Convolution/arbitrary.hpp\"\r\n\r\ntemplate <int\
    \ D> struct bigint {\r\n    using u128 = __uint128_t;\r\n    static const int\
    \ B = pow(10, D);\r\n    int sign = 0;\r\n    vector<int> v;\r\n    static int\
    \ get_D() { return D; }\r\n    static int get_B() { return B; }\r\n    bigint()\
    \ {}\r\n    bigint(const vector<int> &_v, bool _s = false) : sign(_s), v(_v) {}\r\
    \n    bigint(ll x) {\r\n        if (x < 0)\r\n            x *= -1, sign = 1;\r\
    \n        while (x) {\r\n            v.push_back(x % B);\r\n            x /= B;\r\
    \n        }\r\n    }\r\n    bigint(string s) {\r\n        if (s[0] == '-')\r\n\
    \            s.erase(s.begin()), sign = 1;\r\n        int add = 0, cnt = 0, base\
    \ = 1;\r\n        while (s.size()) {\r\n            if (cnt == D) {\r\n      \
    \          v.push_back(add);\r\n                cnt = 0;\r\n                add\
    \ = 0;\r\n                base = 1;\r\n            }\r\n            add = (s.back()\
    \ - '0') * base + add;\r\n            cnt++;\r\n            base *= 10;\r\n  \
    \          s.pop_back();\r\n        }\r\n        if (add)\r\n            v.push_back(add);\r\
    \n    }\r\n    bigint operator-() const {\r\n        bigint res = *this;\r\n \
    \       res.sign ^= 1;\r\n        return res;\r\n    }\r\n    bigint abs() const\
    \ {\r\n        bigint res = *this;\r\n        res.sign = 0;\r\n        return\
    \ res;\r\n    }\r\n    int &operator[](const int i) { return v[i]; }\r\n    int\
    \ size() const { return v.size(); }\r\n    void norm() {\r\n        rep(i, 0,\
    \ v.size() - 1) {\r\n            if (v[i] >= 0) {\r\n                v[i + 1]\
    \ += v[i] / B;\r\n                v[i] %= B;\r\n            } else {\r\n     \
    \           int c = (-v[i] + B - 1) / B;\r\n                v[i] += c * B;\r\n\
    \                v[i + 1] -= c;\r\n            }\r\n        }\r\n        while\
    \ (!v.empty() and v.back() >= B) {\r\n            int c = v.back() / B;\r\n  \
    \          v.back() %= B;\r\n            v.push_back(c);\r\n        }\r\n    \
    \    while (!v.empty() and v.back() == 0)\r\n            v.pop_back();\r\n   \
    \ }\r\n    string to_str() const {\r\n        string res;\r\n        if (v.empty())\r\
    \n            return \"0\";\r\n        if (sign)\r\n            res += '-';\r\n\
    \        res += to_string(v.back());\r\n        for (int i = v.size() - 2; i >=\
    \ 0; i--) {\r\n            string add;\r\n            int w = v[i];\r\n      \
    \      rep(_, 0, D) {\r\n                add += ('0' + (w % 10));\r\n        \
    \        w /= 10;\r\n            }\r\n            reverse(ALL(add));\r\n     \
    \       res += add;\r\n        }\r\n        return res;\r\n    }\r\n    friend\
    \ istream &operator>>(istream &is, bigint<D> &x) {\r\n        string tmp;\r\n\
    \        is >> tmp;\r\n        x = bigint(tmp);\r\n        return is;\r\n    }\r\
    \n    friend ostream &operator<<(ostream &os, bigint<D> x) {\r\n        os <<\
    \ x.to_str();\r\n        return os;\r\n    }\r\n    bigint &operator<<=(const\
    \ int &x) {\r\n        if (!v.empty()) {\r\n            vector<int> add(x, 0);\r\
    \n            v.insert(v.begin(), ALL(add));\r\n        }\r\n        return *this;\r\
    \n    }\r\n    bigint &operator>>=(const int &x) {\r\n        v = vector<int>(v.begin()\
    \ + min(x, (int)v.size()), v.end());\r\n        return *this;\r\n    }\r\n   \
    \ bigint &operator+=(const bigint &x) {\r\n        if (sign != x.sign) {\r\n \
    \           *this -= (-x);\r\n            return *this;\r\n        }\r\n     \
    \   if ((int)v.size() < (int)x.size())\r\n            v.resize(x.size(), 0);\r\
    \n        rep(i, 0, x.size()) { v[i] += x.v[i]; }\r\n        norm();\r\n     \
    \   return *this;\r\n    }\r\n    bigint &operator-=(const bigint &x) {\r\n  \
    \      if (sign != x.sign) {\r\n            *this += (-x);\r\n            return\
    \ *this;\r\n        }\r\n        if (abs() < x.abs()) {\r\n            *this =\
    \ x - (*this);\r\n            sign ^= 1;\r\n            return *this;\r\n    \
    \    }\r\n        rep(i, 0, x.size()) { v[i] -= x.v[i]; }\r\n        norm();\r\
    \n        return *this;\r\n    }\r\n    bigint &operator*=(const bigint &x) {\r\
    \n        sign ^= x.sign;\r\n        auto v1 = ArbitraryMult<u128>(v, x.v);\r\n\
    \        u128 add = 0;\r\n        v.clear();\r\n        v.reserve(v1.size() +\
    \ 3);\r\n        for (int i = 0;; i++) {\r\n            if (i >= int(v1.size())\
    \ and add == 0)\r\n                break;\r\n            if (i < int(v1.size()))\r\
    \n                add += v1[i];\r\n            v.push_back(add % B);\r\n     \
    \       add /= B;\r\n        }\r\n        norm();\r\n        return *this;\r\n\
    \    }\r\n    bigint div_naive(const bigint &a, const bigint &b) {\r\n       \
    \ if (SZ(b) == 1)\r\n            return a.div(b.v.back());\r\n        if (a <\
    \ b)\r\n            return bigint();\r\n        int norm = B / (b.v.back() + 1);\r\
    \n        bigint x = a.mul(norm), y = b.mul(norm);\r\n        int yb = y.v.back();\r\
    \n        bigint quo, rem;\r\n        quo.v.resize(x.size() - y.size() + 1);\r\
    \n        rem.v = {x.v.end() - y.size(), x.v.end()};\r\n        for (int i = x.size()\
    \ - y.size(); i >= 0; i--) {\r\n            if (rem.size() == y.size()) {\r\n\
    \                if (rem >= y) {\r\n                    quo[i] = 1;\r\n      \
    \              rem -= y;\r\n                }\r\n            } else if (rem.size()\
    \ > y.size()) {\r\n                ll rb = ll(rem.v.back()) * B + rem[rem.size()\
    \ - 2];\r\n                int q = rb / yb;\r\n                bigint yq = y.mul(q);\r\
    \n                while (rem < yq) {\r\n                    q--;\r\n         \
    \           yq -= y;\r\n                }\r\n                rem -= yq;\r\n  \
    \              while (rem >= y) {\r\n                    q++;\r\n            \
    \        rem -= y;\r\n                }\r\n                quo[i] = q;\r\n   \
    \         }\r\n            if (i)\r\n                rem.v.insert(rem.v.begin(),\
    \ x[i - 1]);\r\n        }\r\n        return quo;\r\n    }\r\n    bigint &operator/=(const\
    \ bigint &x) {\r\n        bigint a = abs(), b = x.abs();\r\n        sign ^= x.sign;\r\
    \n        if (a < b)\r\n            return *this = bigint();\r\n        if (b.size()\
    \ == 1)\r\n            return *this = a.div(b.v.back());\r\n\r\n        int deg\
    \ = a.size() - b.size() + 2, k = deg;\r\n        while (k > 64)\r\n          \
    \  k = (k + 1) >> 1;\r\n        bigint base(1);\r\n        base <<= (b.size()\
    \ + k);\r\n        bigint inv(div_naive(base, b));\r\n\r\n        while (k < deg)\
    \ {\r\n            bigint y = inv.square();\r\n            y.v.insert(y.v.begin(),\
    \ 0);\r\n            int l = min(SZ(b), k * 2 + 1);\r\n            bigint pref;\r\
    \n            pref.v = {b.v.end() - l, b.v.end()};\r\n            y *= pref;\r\
    \n            y >>= l;\r\n            inv = inv + inv;\r\n            inv <<=\
    \ k + 1;\r\n            inv -= y;\r\n            inv.v.erase(inv.v.begin());\r\
    \n            k <<= 1;\r\n        }\r\n        inv >>= (k - deg);\r\n\r\n    \
    \    (*this) = a * inv;\r\n        (*this) >>= int(a.size() + 2);\r\n        bigint\
    \ mul = (*this) * b;\r\n        while (mul + b <= a) {\r\n            (*this)\
    \ += bigint(1);\r\n            mul += b;\r\n        }\r\n        while (mul >\
    \ a) {\r\n            (*this) -= bigint(1);\r\n            mul -= b;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    bigint &operator%=(const bigint\
    \ &x) {\r\n        bigint div = (*this) / x;\r\n        (*this) -= div * x;\r\n\
    \        return *this;\r\n    }\r\n    bigint square() const {\r\n        bigint\
    \ ret;\r\n        auto v1 = ArbitraryMult<u128>(v, v);\r\n        u128 add = 0;\r\
    \n        ret.v.reserve(v1.size() + 3);\r\n        for (int i = 0;; i++) {\r\n\
    \            if (i >= int(v1.size()) and add == 0)\r\n                break;\r\
    \n            if (i < int(v1.size()))\r\n                add += v1[i];\r\n   \
    \         ret.v.push_back(add % B);\r\n            add /= B;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    bigint mul(ll x) const {\r\n        bigint\
    \ res;\r\n        if (x < 0)\r\n            res.sign ^= 1, x *= -1;\r\n      \
    \  u128 add = 0;\r\n        res.v.reserve(v.size() + 3);\r\n        for (int i\
    \ = 0;; i++) {\r\n            if (i >= int(v.size()) and add == 0)\r\n       \
    \         break;\r\n            if (i < int(v.size()))\r\n                add\
    \ += ll(v[i]) * x;\r\n            res.v.push_back(add % B);\r\n            add\
    \ /= B;\r\n        }\r\n        return res;\r\n    }\r\n    bigint div(ll x) const\
    \ {\r\n        bigint res = *this;\r\n        if (x < 0)\r\n            res.sign\
    \ ^= 1, x *= -1;\r\n        ll add = 0;\r\n        for (int i = res.v.size() -\
    \ 1; i >= 0; i--) {\r\n            add = add * B + res.v[i];\r\n            int\
    \ q = add / x, r = add % x;\r\n            res.v[i] = q, add = r;\r\n        }\r\
    \n        res.norm();\r\n        return res;\r\n    }\r\n    bigint operator<<(const\
    \ int &x) const { return bigint(*this) <<= x; }\r\n    bigint operator>>(const\
    \ int &x) const { return bigint(*this) >>= x; }\r\n    bigint operator+(const\
    \ bigint &x) const { return bigint(*this) += x; }\r\n    bigint operator-(const\
    \ bigint &x) const { return bigint(*this) -= x; }\r\n    bigint operator*(const\
    \ bigint &x) const { return bigint(*this) *= x; }\r\n    bigint operator/(const\
    \ bigint &x) const { return bigint(*this) /= x; }\r\n    bigint operator%(const\
    \ bigint &x) const { return bigint(*this) %= x; }\r\n    bool operator<(const\
    \ bigint &x) const {\r\n        if (sign != x.sign)\r\n            return sign\
    \ > x.sign;\r\n        if ((int)v.size() != (int)x.size()) {\r\n            if\
    \ (sign)\r\n                return (int)x.size() < (int)v.size();\r\n        \
    \    else\r\n                return (int)v.size() < (int)x.size();\r\n       \
    \ }\r\n        for (int i = v.size() - 1; i >= 0; i--)\r\n            if (v[i]\
    \ != x.v[i]) {\r\n                if (sign)\r\n                    return x.v[i]\
    \ < v[i];\r\n                else\r\n                    return v[i] < x.v[i];\r\
    \n            }\r\n        return false;\r\n    }\r\n    bool operator>(const\
    \ bigint &x) const { return x < *this; }\r\n    bool operator<=(const bigint &x)\
    \ const { return !(*this > x); }\r\n    bool operator>=(const bigint &x) const\
    \ { return !(*this < x); }\r\n    bool operator==(const bigint &x) const {\r\n\
    \        return !(*this < x) and !(*this > x);\r\n    }\r\n    bool operator!=(const\
    \ bigint &x) const { return !(*this == x); }\r\n};\r\ntypedef bigint<9> Bigint;\r\
    \n\r\nstruct Bigfloat {\r\n    Bigint v;\r\n    int p = 0;\r\n    Bigfloat() {}\r\
    \n    Bigfloat(const ll &_v) { v = Bigint(_v); }\r\n    Bigfloat(const Bigint\
    \ &_v, int _p = 0) : v(_v), p(_p) {}\r\n    void set(int _p) {\r\n        if (p\
    \ < _p) {\r\n            v >>= (_p - p);\r\n        } else {\r\n            v\
    \ <<= (p - _p);\r\n        }\r\n        p = _p;\r\n    }\r\n    Bigint to_int()\
    \ const {\r\n        if (p < 0)\r\n            return v >> (-p);\r\n        else\r\
    \n            return v << p;\r\n    }\r\n    Bigfloat &operator+=(const Bigfloat\
    \ &x) {\r\n        if (p > x.p)\r\n            set(x.p), v += x.v;\r\n       \
    \ else\r\n            v += x.v << (x.p - p);\r\n        return *this;\r\n    }\r\
    \n    Bigfloat &operator-=(const Bigfloat &x) {\r\n        if (p > x.p)\r\n  \
    \          set(x.p), v -= x.v;\r\n        else\r\n            v -= x.v << (x.p\
    \ - p);\r\n        return *this;\r\n    }\r\n    Bigfloat square() {\r\n     \
    \   Bigfloat res = *this;\r\n        res.p *= 2;\r\n        res.v = res.v.square();\r\
    \n        return res;\r\n    }\r\n    Bigfloat mul(ll x) {\r\n        Bigfloat\
    \ res = *this;\r\n        res.v = v.mul(x);\r\n        return res;\r\n    }\r\n\
    \    Bigfloat div(ll x) {\r\n        Bigfloat res = *this;\r\n        res.v =\
    \ v.div(x);\r\n        return res;\r\n    }\r\n    Bigfloat &operator*=(const\
    \ Bigfloat &x) {\r\n        p += x.p;\r\n        v *= x.v;\r\n        return *this;\r\
    \n    }\r\n    Bigfloat &operator/=(const Bigfloat &x) {\r\n        p -= x.p;\r\
    \n        v /= x.v;\r\n        return *this;\r\n    }\r\n    Bigfloat operator+(const\
    \ Bigfloat &x) const { return Bigfloat(*this) += x; }\r\n    Bigfloat operator-(const\
    \ Bigfloat &x) const { return Bigfloat(*this) -= x; }\r\n    Bigfloat operator*(const\
    \ Bigfloat &x) const { return Bigfloat(*this) *= x; }\r\n    Bigfloat operator/(const\
    \ Bigfloat &x) const { return Bigfloat(*this) /= x; }\r\n    string to_str() {\r\
    \n        string res = v.abs().to_str();\r\n        int d = Bigint::get_D();\r\
    \n        if (p * d > 0)\r\n            res += string(p * d, '0');\r\n       \
    \ else if (-p * d >= 1 and -p * d < (int)res.size()) {\r\n            res = res.substr(0,\
    \ (int)res.size() + p * d) + '.' +\r\n                  res.substr((int)res.size()\
    \ + p * d);\r\n        } else if (-p * d >= (int)res.size())\r\n            res\
    \ = \"0.\" + string(-p * d - (int)res.size(), '0') + res;\r\n        if (v.sign)\
    \ {\r\n            res.insert(res.begin(), '-');\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    friend ostream &operator<<(ostream &os, Bigfloat x) {\r\
    \n        os << x.to_str();\r\n        return os;\r\n    }\r\n};\r\n\r\nBigfloat\
    \ sqrt(ll n, int d) {\r\n    Bigfloat res(Bigint((ll)sqrt(1LL * Bigint::get_B()\
    \ * Bigint::get_B() / n)),\r\n                 -1),\r\n        pre;\r\n    int\
    \ cur = 1;\r\n    while (pre.v != res.v) {\r\n        cur = min(cur << 1, d);\r\
    \n        pre = res;\r\n        Bigfloat add = Bigfloat(1) - res.square().mul(n);\r\
    \n        add.set(-cur);\r\n        res += (res * add).div(2);\r\n        res.set(-cur);\r\
    \n    }\r\n    return res.mul(n);\r\n}\r\n\r\n/**\r\n * @brief Big Integer(Float)\r\
    \n */"
  dependsOn:
  - Convolution/arbitrary.hpp
  - Convolution/ntt.hpp
  - Math/primitive.hpp
  - Math/fastdiv.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  - Math/modint.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: Math/bigint.hpp
  requiredBy: []
  timestamp: '2026-01-30 05:37:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/bigint.hpp
layout: document
redirect_from:
- /library/Math/bigint.hpp
- /library/Math/bigint.hpp.html
title: Big Integer(Float)
---
