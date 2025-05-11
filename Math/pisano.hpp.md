---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Fast Division
  - icon: ':question:'
    path: Math/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pisano Period
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
    \ * b);\n    }\n};\n\n/**\n * @brief Fast Division\n */\n#line 3 \"Math/dynamic.hpp\"\
    \n\r\nstruct Fp {\r\n    using u64 = uint64_t;\r\n    uint v;\r\n    static uint\
    \ get_mod() {\r\n        return _getmod();\r\n    }\r\n    static void set_mod(uint\
    \ _m) {\r\n        bar = FastDiv(_m);\r\n    }\r\n    Fp inv() const {\r\n   \
    \     int tmp, a = v, b = get_mod(), x = 1, y = 0;\r\n        while (b) {\r\n\
    \            tmp = a / b, a -= tmp * b;\r\n            swap(a, b);\r\n       \
    \     x -= tmp * y;\r\n            swap(x, y);\r\n        }\r\n        if (x <\
    \ 0) {\r\n            x += get_mod();\r\n        }\r\n        return x;\r\n  \
    \  }\r\n    Fp() : v(0) {}\r\n    Fp(ll x) {\r\n        v = x % get_mod();\r\n\
    \        if (v < 0)\r\n            v += get_mod();\r\n    }\r\n    Fp operator-()\
    \ const {\r\n        return Fp() - *this;\r\n    }\r\n    Fp pow(ll t) {\r\n \
    \       assert(t >= 0);\r\n        Fp res = 1, b = *this;\r\n        while (t)\
    \ {\r\n            if (t & 1)\r\n                res *= b;\r\n            b *=\
    \ b;\r\n            t >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n\
    \    Fp &operator+=(const Fp &x) {\r\n        v += x.v;\r\n        if (v >= get_mod())\r\
    \n            v -= get_mod();\r\n        return *this;\r\n    }\r\n    Fp &operator-=(const\
    \ Fp &x) {\r\n        v += get_mod() - x.v;\r\n        if (v >= get_mod())\r\n\
    \            v -= get_mod();\r\n        return *this;\r\n    }\r\n    Fp &operator*=(const\
    \ Fp &x) {\r\n        v = (u64(v) * x.v) % bar;\r\n        return *this;\r\n \
    \   }\r\n    Fp &operator/=(const Fp &x) {\r\n        (*this) *= x.inv();\r\n\
    \        return *this;\r\n    }\r\n    Fp operator+(const Fp &x) const {\r\n \
    \       return Fp(*this) += x;\r\n    }\r\n    Fp operator-(const Fp &x) const\
    \ {\r\n        return Fp(*this) -= x;\r\n    }\r\n    Fp operator*(const Fp &x)\
    \ const {\r\n        return Fp(*this) *= x;\r\n    }\r\n    Fp operator/(const\
    \ Fp &x) const {\r\n        return Fp(*this) /= x;\r\n    }\r\n    bool operator==(const\
    \ Fp &x) const {\r\n        return v == x.v;\r\n    }\r\n    bool operator!=(const\
    \ Fp &x) const {\r\n        return v != x.v;\r\n    }\r\n    friend istream &operator>>(istream\
    \ &is, Fp &x) {\r\n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Fp &x) {\r\n        return os << x.v;\r\n    }\r\n\r\n  private:\r\
    \n    static FastDiv bar;\r\n    static uint _getmod() {\r\n        return bar.get();\r\
    \n    }\r\n};\r\nFastDiv Fp::bar(998244353);\r\n\r\nvoid rd(Fp &x) {\r\n    fastio::rd(x.v);\r\
    \n}\r\nvoid wt(Fp x) {\r\n    fastio::wt(x.v);\r\n}\r\n\r\n/**\r\n * @brief Dynamic\
    \ Modint\r\n */\n#line 2 \"Math/matrix.hpp\"\n\r\ntemplate <class T> struct Matrix\
    \ {\r\n    int h, w;\r\n    vector<vector<T>> val;\r\n    T det;\r\n    Matrix()\
    \ {}\r\n    Matrix(int n) : h(n), w(n), val(vector<vector<T>>(n, vector<T>(n)))\
    \ {}\r\n    Matrix(int n, int m)\r\n        : h(n), w(m), val(vector<vector<T>>(n,\
    \ vector<T>(m))) {}\r\n    vector<T> &operator[](const int i) {\r\n        return\
    \ val[i];\r\n    }\r\n    Matrix &operator+=(const Matrix &m) {\r\n        assert(h\
    \ == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w) val[i][j] += m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix &operator-=(const Matrix &m) {\r\
    \n        assert(h == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w)\
    \ val[i][j] -= m.val[i][j];\r\n        return *this;\r\n    }\r\n    Matrix &operator*=(const\
    \ Matrix &m) {\r\n        assert(w == m.h);\r\n        Matrix<T> res(h, m.w);\r\
    \n        rep(i, 0, h) rep(j, 0, m.w) rep(k, 0, w) res.val[i][j] +=\r\n      \
    \      val[i][k] * m.val[k][j];\r\n        *this = res;\r\n        return *this;\r\
    \n    }\r\n    Matrix operator+(const Matrix &m) const {\r\n        return Matrix(*this)\
    \ += m;\r\n    }\r\n    Matrix operator-(const Matrix &m) const {\r\n        return\
    \ Matrix(*this) -= m;\r\n    }\r\n    Matrix operator*(const Matrix &m) const\
    \ {\r\n        return Matrix(*this) *= m;\r\n    }\r\n    Matrix pow(ll k) {\r\
    \n        Matrix<T> res(h, h), c = *this;\r\n        rep(i, 0, h) res.val[i][i]\
    \ = 1;\r\n        while (k) {\r\n            if (k & 1)\r\n                res\
    \ *= c;\r\n            c *= c;\r\n            k >>= 1;\r\n        }\r\n      \
    \  return res;\r\n    }\r\n    vector<int> gauss(int c = -1) {\r\n        det\
    \ = 1;\r\n        if (val.empty())\r\n            return {};\r\n        if (c\
    \ == -1)\r\n            c = w;\r\n        int cur = 0;\r\n        vector<int>\
    \ res;\r\n        rep(i, 0, c) {\r\n            if (cur == h)\r\n            \
    \    break;\r\n            rep(j, cur, h) if (val[j][i] != 0) {\r\n          \
    \      swap(val[cur], val[j]);\r\n                if (cur != j)\r\n          \
    \          det *= -1;\r\n                break;\r\n            }\r\n         \
    \   det *= val[cur][i];\r\n            if (val[cur][i] == 0)\r\n             \
    \   continue;\r\n            rep(j, 0, h) if (j != cur) {\r\n                T\
    \ z = val[j][i] / val[cur][i];\r\n                rep(k, i, w) val[j][k] -= val[cur][k]\
    \ * z;\r\n            }\r\n            res.push_back(i);\r\n            cur++;\r\
    \n        }\r\n        return res;\r\n    }\r\n    Matrix inv() {\r\n        assert(h\
    \ == w);\r\n        Matrix base(h, h * 2), res(h, h);\r\n        rep(i, 0, h)\
    \ rep(j, 0, h) base[i][j] = val[i][j];\r\n        rep(i, 0, h) base[i][h + i]\
    \ = 1;\r\n        base.gauss(h);\r\n        det = base.det;\r\n        rep(i,\
    \ 0, h) rep(j, 0, h) res[i][j] = base[i][h + j] / base[i][i];\r\n        return\
    \ res;\r\n    }\r\n    bool operator==(const Matrix &m) {\r\n        assert(h\
    \ == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w) if (val[i][j] !=\
    \ m.val[i][j]) return false;\r\n        return true;\r\n    }\r\n    bool operator!=(const\
    \ Matrix &m) {\r\n        assert(h == m.h and w == m.w);\r\n        rep(i, 0,\
    \ h) rep(j, 0, w) if (val[i][j] == m.val[i][j]) return false;\r\n        return\
    \ true;\r\n    }\r\n    friend istream &operator>>(istream &is, Matrix &m) {\r\
    \n        rep(i, 0, m.h) rep(j, 0, m.w) is >> m[i][j];\r\n        return is;\r\
    \n    }\r\n    friend ostream &operator<<(ostream &os, Matrix &m) {\r\n      \
    \  rep(i, 0, m.h) {\r\n            rep(j, 0, m.w) os << m[i][j]\r\n          \
    \                    << (j == m.w - 1 and i != m.h - 1 ? '\\n' : ' ');\r\n   \
    \     }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Matrix\r\n\
    \ */\n#line 2 \"Math/miller.hpp\"\n\r\nstruct m64 {\r\n    using i64 = int64_t;\r\
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
    \   return lb;\r\n        }\r\n    }\r\n}\r\n\r\nvector<pair<ll, int>> Pollard2(ll\
    \ n) {\r\n    auto ps = Pollard(n);\r\n    sort(ALL(ps));\r\n    using P = pair<ll,\
    \ int>;\r\n    vector<P> pes;\r\n    for (auto &p : ps) {\r\n        if (pes.empty()\
    \ or pes.back().first != p) {\r\n            pes.push_back({p, 1});\r\n      \
    \  } else {\r\n            pes.back().second++;\r\n        }\r\n    }\r\n    return\
    \ pes;\r\n}\r\n\r\nvector<ll> EnumDivisors(ll n) {\r\n    auto pes = Pollard2(n);\r\
    \n    vector<ll> ret;\r\n    auto rec = [&](auto &rec, int id, ll d) -> void {\r\
    \n        if (id == SZ(pes)) {\r\n            ret.push_back(d);\r\n          \
    \  return;\r\n        }\r\n        rec(rec, id + 1, d);\r\n        rep(e, 0, pes[id].second)\
    \ {\r\n            d *= pes[id].first;\r\n            rec(rec, id + 1, d);\r\n\
    \        }\r\n    };\r\n    rec(rec, 0, 1);\r\n    sort(ALL(ret));\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 5 \"Math/pisano.hpp\"\
    \n\nint Pisano(int p) {\n    if (p == 2)\n        return 3;\n    if (p == 5)\n\
    \        return 20;\n    vector<ll> cand;\n    if (p % 5 == 1 or p % 5 == 4)\n\
    \        cand = EnumDivisors(p - 1);\n    else\n        cand = EnumDivisors(p\
    \ * 2 + 2);\n    auto check = [&](int d, int p) -> bool {\n        Fp::set_mod(p);\n\
    \        Matrix<Fp> mat(2, 2);\n        mat[0][1] = mat[1][0] = mat[1][1] = 1;\n\
    \        mat = mat.pow(d);\n        return mat[0][1] == 0 and mat[1][1] == 1;\n\
    \    };\n    for (auto &d : cand)\n        if (check(d, p)) {\n            return\
    \ d;\n        }\n    assert(0);\n}\n\n/**\n * @brief Pisano Period\n */\n"
  code: "#pragma once\n#include \"Math/dynamic.hpp\"\n#include \"Math/matrix.hpp\"\
    \n#include \"Math/pollard.hpp\"\n\nint Pisano(int p) {\n    if (p == 2)\n    \
    \    return 3;\n    if (p == 5)\n        return 20;\n    vector<ll> cand;\n  \
    \  if (p % 5 == 1 or p % 5 == 4)\n        cand = EnumDivisors(p - 1);\n    else\n\
    \        cand = EnumDivisors(p * 2 + 2);\n    auto check = [&](int d, int p) ->\
    \ bool {\n        Fp::set_mod(p);\n        Matrix<Fp> mat(2, 2);\n        mat[0][1]\
    \ = mat[1][0] = mat[1][1] = 1;\n        mat = mat.pow(d);\n        return mat[0][1]\
    \ == 0 and mat[1][1] == 1;\n    };\n    for (auto &d : cand)\n        if (check(d,\
    \ p)) {\n            return d;\n        }\n    assert(0);\n}\n\n/**\n * @brief\
    \ Pisano Period\n */"
  dependsOn:
  - Math/dynamic.hpp
  - Math/fastdiv.hpp
  - Math/matrix.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/pisano.hpp
  requiredBy: []
  timestamp: '2025-05-11 13:37:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/pisano.hpp
layout: document
redirect_from:
- /library/Math/pisano.hpp
- /library/Math/pisano.hpp.html
title: Pisano Period
---
