---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':heavy_check_mark:'
    path: Math/fastdiv.hpp
    title: Fast Division
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient
  bundledCode: "#line 1 \"Verify/LC_binomial_coefficient.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i, a, b)\
    \ for (int i = (int)(a); i < (int)(b); i++)\r\n#define rrep(i, a, b) for (int\
    \ i = (int)(b)-1; i >= (int)(a); i--)\r\n#define ALL(v) (v).begin(), (v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\r\n#define\
    \ SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v)\
    \ *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())\r\
    \n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\n\r\nusing uint\
    \ = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned long long;\r\
    \nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate <typename T> inline bool\
    \ chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a = b;\r\n        return 1;\r\
    \n    }\r\n    return 0;\r\n}\r\ntemplate <typename T> inline bool chmin(T &a,\
    \ T b) {\r\n    if (a > b) {\r\n        a = b;\r\n        return 1;\r\n    }\r\
    \n    return 0;\r\n}\r\ntemplate <typename T, typename U> T ceil(T x, U y) {\r\
    \n    assert(y != 0);\r\n    if (y < 0)\r\n        x = -x, y = -y;\r\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate <typename T, typename U>\
    \ T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x =\
    \ -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1) / y);\r\n}\r\ntemplate\
    \ <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\n}\r\
    \ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63 - __builtin_clzll(x));\r\
    \n}\r\ntemplate <typename T> int lowbit(T x) {\r\n    return (x == 0 ? -1 : __builtin_ctzll(x));\r\
    \n}\r\n\r\ntemplate <class T, class U>\r\nostream &operator<<(ostream &os, const\
    \ pair<T, U> &p) {\r\n    os << \"P(\" << p.first << \", \" << p.second << \"\
    )\";\r\n    return os;\r\n}\r\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &vec) {\r\n    os << \"{\";\r\n    for (int i = 0; i <\
    \ vec.size(); i++) {\r\n        os << vec[i] << (i + 1 == vec.size() ? \"\" :\
    \ \", \");\r\n    }\r\n    os << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename\
    \ T, typename U>\r\nostream &operator<<(ostream &os, const map<T, U> &map_var)\
    \ {\r\n    os << \"{\";\r\n    for (auto itr = map_var.begin(); itr != map_var.end();\
    \ itr++) {\r\n        os << \"(\" << itr->first << \", \" << itr->second << \"\
    )\";\r\n        itr++;\r\n        if (itr != map_var.end())\r\n            os\
    \ << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n    return os;\r\
    \n}\r\ntemplate <typename T> ostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\r\n    os << \"{\";\r\n    for (auto itr = set_var.begin(); itr != set_var.end();\
    \ itr++) {\r\n        os << *itr;\r\n        ++itr;\r\n        if (itr != set_var.end())\r\
    \n            os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n\
    \    return os;\r\n}\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__,\
    \ __VA_ARGS__)\r\n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename\
    \ T> void _show(int i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename\
    \ T1, typename T2, typename... T3>\r\nvoid _show(int i, const T1 &a, const T2\
    \ &b, const T3 &...c) {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n \
    \       cerr << a[i];\r\n    cerr << \":\" << b << \" \";\r\n    _show(i + 1,\
    \ a, c...);\r\n}\n#line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\nnamespace\
    \ fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar\
    \ obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\n\r\nuint32_t pil\
    \ = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n    char num[10000][4];\r\n  \
    \  constexpr Pre() : num() {\r\n        for (int i = 0; i < 10000; i++) {\r\n\
    \            int n = i;\r\n            for (int j = 3; j >= 0; j--) {\r\n    \
    \            num[i][j] = n % 10 | '0';\r\n                n /= 10;\r\n       \
    \     }\r\n        }\r\n    }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\
    \n    memmove(ibuf, ibuf + pil, pir - pil);\r\n    pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n    pil = 0;\r\n    if (pir < SZ)\r\
    \n        ibuf[pir++] = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n    fwrite(obuf,\
    \ 1, por, stdout);\r\n    por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n    do {\r\
    \n        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (isspace(c));\r\n}\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\
    \n    char c;\r\n    do {\r\n        if (pil + 1 > pir)\r\n            load();\r\
    \n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\n    do {\r\n      \
    \  x += c;\r\n        if (pil == pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (!isspace(c));\r\n}\r\n\r\ntemplate <typename T> void rd_real(T\
    \ &x) {\r\n    string s;\r\n    rd(s);\r\n    x = stod(s);\r\n}\r\n\r\ntemplate\
    \ <typename T> void rd_integer(T &x) {\r\n    if (pil + 100 > pir)\r\n       \
    \ load();\r\n    char c;\r\n    do\r\n        c = ibuf[pil++];\r\n    while (c\
    \ < '-');\r\n    bool minus = 0;\r\n    if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\r\n        if (c == '-') {\r\n            minus = 1, c = ibuf[pil++];\r\
    \n        }\r\n    }\r\n    x = 0;\r\n    while ('0' <= c) {\r\n        x = x\
    \ * 10 + (c & 15), c = ibuf[pil++];\r\n    }\r\n    if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n        if (minus)\r\n            x = -x;\r\n  \
    \  }\r\n}\r\n\r\nvoid rd(int &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ll &x)\
    \ {\r\n    rd_integer(x);\r\n}\r\nvoid rd(i128 &x) {\r\n    rd_integer(x);\r\n\
    }\r\nvoid rd(uint &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ull &x) {\r\n  \
    \  rd_integer(x);\r\n}\r\nvoid rd(u128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid\
    \ rd(double &x) {\r\n    rd_real(x);\r\n}\r\nvoid rd(long double &x) {\r\n   \
    \ rd_real(x);\r\n}\r\n\r\ntemplate <class T, class U> void rd(pair<T, U> &p) {\r\
    \n    return rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename\
    \ T> void rd_tuple(T &t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n        auto &x = std::get<N>(t);\r\n        rd(x);\r\n        rd_tuple<N\
    \ + 1>(t);\r\n    }\r\n}\r\ntemplate <class... T> void rd(tuple<T...> &tpl) {\r\
    \n    rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t N = 0, typename T> void rd(array<T,\
    \ N> &x) {\r\n    for (auto &d : x)\r\n        rd(d);\r\n}\r\ntemplate <class\
    \ T> void rd(vector<T> &x) {\r\n    for (auto &d : x)\r\n        rd(d);\r\n}\r\
    \n\r\nvoid read() {}\r\ntemplate <class H, class... T> void read(H &h, T &...t)\
    \ {\r\n    rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n    if (por\
    \ == SZ)\r\n        flush();\r\n    obuf[por++] = c;\r\n}\r\nvoid wt(const string\
    \ s) {\r\n    for (char c : s)\r\n        wt(c);\r\n}\r\nvoid wt(const char *s)\
    \ {\r\n    size_t len = strlen(s);\r\n    for (size_t i = 0; i < len; i++)\r\n\
    \        wt(s[i]);\r\n}\r\n\r\ntemplate <typename T> void wt_integer(T x) {\r\n\
    \    if (por > SZ - 100)\r\n        flush();\r\n    if (x < 0) {\r\n        obuf[por++]\
    \ = '-', x = -x;\r\n    }\r\n    int outi;\r\n    for (outi = 96; x >= 10000;\
    \ outi -= 4) {\r\n        memcpy(out + outi, pre.num[x % 10000], 4);\r\n     \
    \   x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n        memcpy(obuf + por,\
    \ pre.num[x], 4);\r\n        por += 4;\r\n    } else if (x >= 100) {\r\n     \
    \   memcpy(obuf + por, pre.num[x] + 1, 3);\r\n        por += 3;\r\n    } else\
    \ if (x >= 10) {\r\n        int q = (x * 103) >> 10;\r\n        obuf[por] = q\
    \ | '0';\r\n        obuf[por + 1] = (x - q * 10) | '0';\r\n        por += 2;\r\
    \n    } else\r\n        obuf[por++] = x | '0';\r\n    memcpy(obuf + por, out +\
    \ outi + 4, 96 - outi);\r\n    por += 96 - outi;\r\n}\r\n\r\ntemplate <typename\
    \ T> void wt_real(T x) {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15)\
    \ << double(x);\r\n    string s = oss.str();\r\n    wt(s);\r\n}\r\n\r\nvoid wt(int\
    \ x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ll x) {\r\n    wt_integer(x);\r\n\
    }\r\nvoid wt(i128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(uint x) {\r\n   \
    \ wt_integer(x);\r\n}\r\nvoid wt(ull x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(u128\
    \ x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(double x) {\r\n    wt_real(x);\r\n\
    }\r\nvoid wt(long double x) {\r\n    wt_real(x);\r\n}\r\n\r\ntemplate <class T,\
    \ class U> void wt(const pair<T, U> val) {\r\n    wt(val.first);\r\n    wt(' ');\r\
    \n    wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T> void wt_tuple(const\
    \ T t) {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n        if constexpr\
    \ (N > 0) {\r\n            wt(' ');\r\n        }\r\n        const auto x = std::get<N>(t);\r\
    \n        wt(x);\r\n        wt_tuple<N + 1>(t);\r\n    }\r\n}\r\ntemplate <class...\
    \ T> void wt(tuple<T...> tpl) {\r\n    wt_tuple(tpl);\r\n}\r\ntemplate <class\
    \ T, size_t S> void wt(const array<T, S> val) {\r\n    auto n = val.size();\r\n\
    \    for (size_t i = 0; i < n; i++) {\r\n        if (i)\r\n            wt(' ');\r\
    \n        wt(val[i]);\r\n    }\r\n}\r\ntemplate <class T> void wt(const vector<T>\
    \ val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++) {\r\
    \n        if (i)\r\n            wt(' ');\r\n        wt(val[i]);\r\n    }\r\n}\r\
    \n\r\nvoid print() {\r\n    wt('\\n');\r\n}\r\ntemplate <class Head, class...\
    \ Tail> void print(Head &&head, Tail &&...tail) {\r\n    wt(head);\r\n    if (sizeof...(Tail))\r\
    \n        wt(' ');\r\n    print(forward<Tail>(tail)...);\r\n}\r\nvoid __attribute__((destructor))\
    \ _d() {\r\n    flush();\r\n}\r\n} // namespace fastio\r\n\r\nusing fastio::flush;\r\
    \nusing fastio::print;\r\nusing fastio::read;\r\n\r\ninline void first(bool i\
    \ = true) {\r\n    print(i ? \"first\" : \"second\");\r\n}\r\ninline void Alice(bool\
    \ i = true) {\r\n    print(i ? \"Alice\" : \"Bob\");\r\n}\r\ninline void Takahashi(bool\
    \ i = true) {\r\n    print(i ? \"Takahashi\" : \"Aoki\");\r\n}\r\ninline void\
    \ yes(bool i = true) {\r\n    print(i ? \"yes\" : \"no\");\r\n}\r\ninline void\
    \ Yes(bool i = true) {\r\n    print(i ? \"Yes\" : \"No\");\r\n}\r\ninline void\
    \ No() {\r\n    print(\"No\");\r\n}\r\ninline void YES(bool i = true) {\r\n  \
    \  print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void NO() {\r\n    print(\"NO\"\
    );\r\n}\r\ninline void Yay(bool i = true) {\r\n    print(i ? \"Yay!\" : \":(\"\
    );\r\n}\r\ninline void Possible(bool i = true) {\r\n    print(i ? \"Possible\"\
    \ : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool i = true) {\r\n    print(i\
    \ ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n\
    #line 5 \"Verify/LC_binomial_coefficient.test.cpp\"\n\n#line 2 \"Math/fastdiv.hpp\"\
    \n\nstruct FastDiv{\n    using u64=uint64_t;\n    using u128=__uint128_t;\n  \
    \  constexpr FastDiv():m(),s(),x(){}\n    constexpr FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
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
    \n * @brief Primitive Function\r\n */\n#line 4 \"Math/binomquery.hpp\"\n\nstruct\
    \ BinomialQuery{\n    struct X{ // for m=p^q\n        int p,q,m,delta;\n     \
    \   vector<int> fact,ifac;\n        FastDiv im,ip;\n        X(){}\n        X(int\
    \ _p,int _q):p(_p),q(_q),ip(p){\n            m=1;\n            while(_q--)m*=p;\n\
    \            im=FastDiv(m);\n            fact.resize(m);\n            ifac.resize(m);\n\
    \            fact[0]=fact[1]=ifac[0]=ifac[1]=1;\n            rep(i,2,m){\n   \
    \             if(i%ip==0)fact[i]=fact[i-1];\n                else fact[i]=(ll(fact[i-1])*i)%im;\n\
    \            }\n            ifac[m-1]=minv(fact[m-1],m);\n            for(int\
    \ i=m-2;i>1;i--){\n                if(i%ip==p-1)ifac[i]=ifac[i+1];\n         \
    \       else ifac[i]=(ll(ifac[i+1])*(i+1))%im;\n            }\n            delta=(p==2\
    \ and q>=3?0:1);\n        }\n        int nCr(ll n,ll r){\n            if(n<0 or\
    \ r<0 or n<r)return 0;\n            ll s=n-r,ret=1;\n            int e0=0,em=0;\n\
    \            for(int i=1;n;i++){\n                ret=(ret*fact[n%m])%im;\n  \
    \              ret=(ret*ifac[r%m])%im;\n                ret=(ret*ifac[s%m])%im;\n\
    \                n=n/ip,r=r/ip,s=s/ip;\n                int add=n-r-s;\n     \
    \           e0+=add;\n                if(e0>=q)return 0;\n                if(i>=q)em^=add;\n\
    \            }\n            if(delta and em&1)ret=m-ret;\n            ret=(ret*mpow(p,e0,m))%im;\n\
    \            return ret;\n        }\n    };\n    int mod;\n    vector<ll> ms;\n\
    \    vector<X> Xs;\n    BinomialQuery(int M):mod(M){\n        for(int p=2;p*p<=M;p++)if(M%p==0){\n\
    \            int e=0,base=1;\n            while(M%p==0)M/=p,e++,base*=p;\n   \
    \         ms.push_back(base);\n            Xs.push_back(X(p,e));\n        }\n\
    \        if(M!=1){\n            ms.push_back(M);\n            Xs.push_back(X(M,1));\n\
    \        }\n    }\n    int nCr(ll n,ll r){\n        if(mod==1)return 0;\n    \
    \    vector<ll> ret;\n        for(auto& buf:Xs)ret.push_back(buf.nCr(n,r));\n\
    \        return crt(ret,ms).first;\n    }\n};\n\n/**\n * @brief Binomial Coefficient\
    \ for query\n*/\n#line 7 \"Verify/LC_binomial_coefficient.test.cpp\"\n\nint main()\
    \ {\n    int q, m;\n    read(q, m);\n    BinomialQuery buf(m);\n    while (q--)\
    \ {\n        ll n, r;\n        read(n, r);\n        print(buf.nCr(n, r));\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\
    \n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/binomquery.hpp\"\n\nint main() {\n    int q, m;\n    read(q, m);\n  \
    \  BinomialQuery buf(m);\n    while (q--) {\n        ll n, r;\n        read(n,\
    \ r);\n        print(buf.nCr(n, r));\n    }\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/binomquery.hpp
  - Math/fastdiv.hpp
  - Math/primitive.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_binomial_coefficient.test.cpp
  requiredBy: []
  timestamp: '2024-06-23 06:04:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_binomial_coefficient.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_binomial_coefficient.test.cpp
- /verify/Verify/LC_binomial_coefficient.test.cpp.html
title: Verify/LC_binomial_coefficient.test.cpp
---
