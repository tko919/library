---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"Verify/LC_factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define\
    \ ALL(v) (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\r\n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\
    \n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T, typename S = T> S SUM(const vector<T> &a) {\r\n    return accumulate(ALL(a),\
    \ S(0));\r\n}\r\ntemplate <typename S, typename T = S> S POW(S a, T b) {\r\n \
    \   S ret = 1, base = a;\r\n    for (;;) {\r\n        if (b & 1)\r\n         \
    \   ret *= base;\r\n        b >>= 1;\r\n        if (b == 0)\r\n            break;\r\
    \n        base *= base;\r\n    }\r\n    return ret;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T> inline\
    \ bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n        return\
    \ 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename U> T ceil(T\
    \ x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x = -x, y = -y;\r\
    \n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate <typename T,\
    \ typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n\
    \        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1) / y);\r\n\
    }\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
    \n}\r\ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x));\r\n}\r\ntemplate <typename T> int lowbit(T x) {\r\n \
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\ntemplate <class T,\
    \ class U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os\
    \ << \"P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\
    \ntemplate <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)\
    \ {\r\n    os << \"{\";\r\n    for (int i = 0; i < vec.size(); i++) {\r\n    \
    \    os << vec[i] << (i + 1 == vec.size() ? \"\" : \", \");\r\n    }\r\n    os\
    \ << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename T, typename U>\r\nostream\
    \ &operator<<(ostream &os, const map<T, U> &map_var) {\r\n    os << \"{\";\r\n\
    \    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\r\n     \
    \   os << \"(\" << itr->first << \", \" << itr->second << \")\";\r\n        itr++;\r\
    \n        if (itr != map_var.end())\r\n            os << \", \";\r\n        itr--;\r\
    \n    }\r\n    os << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename T> ostream\
    \ &operator<<(ostream &os, const set<T> &set_var) {\r\n    os << \"{\";\r\n  \
    \  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\r\n       \
    \ os << *itr;\r\n        ++itr;\r\n        if (itr != set_var.end())\r\n     \
    \       os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n    return\
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define debug 1\r\n#define show(...) _show(0, #__VA_ARGS__,\
    \ __VA_ARGS__)\r\n#else\r\n#define debug 0\r\n#define show(...) true\r\n#endif\r\
    \ntemplate <typename T> void _show(int i, T name) {\r\n    cerr << '\\n';\r\n\
    }\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid _show(int i,\
    \ const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i] != ',' && a[i]\
    \ != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\" << b << \" \";\r\
    \n    _show(i + 1, a, c...);\r\n}\n#line 2 \"Math/miller.hpp\"\n\r\nstruct m64\
    \ {\r\n    using i64 = int64_t;\r\n    using u64 = uint64_t;\r\n    using u128\
    \ = __uint128_t;\r\n\r\n    static u64 mod;\r\n    static u64 r;\r\n    static\
    \ u64 n2;\r\n\r\n    static u64 get_r() {\r\n        u64 ret = mod;\r\n      \
    \  rep(_,0,5) ret *= 2 - mod * ret;\r\n        return ret;\r\n    }\r\n\r\n  \
    \  static void set_mod(u64 m) {\r\n        assert(m < (1LL << 62));\r\n      \
    \  assert((m & 1) == 1);\r\n        mod = m;\r\n        n2 = -u128(m) % m;\r\n\
    \        r = get_r();\r\n        assert(r * mod == 1);\r\n    }\r\n    static\
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
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 5 \"Verify/LC_factorize.test.cpp\"\
    \n\r\nint main(){\r\n    int q;\r\n    cin>>q;\r\n    while(q--){\r\n        ll\
    \ n;\r\n        cin>>n;\r\n        auto ps=Pollard(n);\r\n        cout<<ps.size()<<'\\\
    n';\r\n        sort(ALL(ps));\r\n        for(auto& p:ps)cout<<p<<'\\n';\r\n  \
    \  }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"Math/pollard.hpp\"\r\n\r\nint main(){\r\
    \n    int q;\r\n    cin>>q;\r\n    while(q--){\r\n        ll n;\r\n        cin>>n;\r\
    \n        auto ps=Pollard(n);\r\n        cout<<ps.size()<<'\\n';\r\n        sort(ALL(ps));\r\
    \n        for(auto& p:ps)cout<<p<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_factorize.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_factorize.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_factorize.test.cpp
- /verify/Verify/LC_factorize.test.cpp.html
title: Verify/LC_factorize.test.cpp
---
