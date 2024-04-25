---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: DataStructure/staticrectaddrectsum.hpp
    title: Static Rectangle Add Rectangle Sum
  - icon: ':x:'
    path: DataStructure/staticrectsum.hpp
    title: Static Rectangle Sum
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
  bundledCode: "#line 1 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b-1); i >= (int)(a); i--)\r\n#define\
    \ ALL(v) (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\r\n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\
    \n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a\
    \ = b;\r\n        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename\
    \ U> T ceil(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x\
    \ = -x, y = -y;\r\n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate\
    \ <typename T, typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if\
    \ (y < 0)\r\n        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1)\
    \ / y);\r\n}\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
    \n}\r\ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x));\r\n}\r\ntemplate <typename T> int lowbit(T x) {\r\n \
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\n#ifdef LOCAL\r\n#define\
    \ show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\n#else\r\n#define show(...)\
    \ true\r\n#endif\r\ntemplate <typename T> void _show(int i, T name) {\r\n    cerr\
    \ << '\\n';\r\n}\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid\
    \ _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i]\
    \ != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\"\
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\r\ntemplate <class T, class\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os << \"\
    P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\ntemplate\
    \ <typename T, template <class> class C>\r\nostream &operator<<(ostream &os, const\
    \ C<T> &v) {\r\n    os << \"[\";\r\n    for (auto d : v)\r\n        os << d <<\
    \ \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\nnamespace fastio {\r\nstatic constexpr uint32_t SZ =\
    \ 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar out[100];\r\n// pointer\
    \ of ibuf, obuf\r\n\r\nuint32_t pil = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\
    \n    char num[10000][4];\r\n    constexpr Pre() : num() {\r\n        for (int\
    \ i = 0; i < 10000; i++) {\r\n            int n = i;\r\n            for (int j\
    \ = 3; j >= 0; j--) {\r\n                num[i][j] = n % 10 | '0';\r\n       \
    \         n /= 10;\r\n            }\r\n        }\r\n    }\r\n} constexpr pre;\r\
    \n\r\ninline void load() {\r\n    memmove(ibuf, ibuf + pil, pir - pil);\r\n  \
    \  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\r\n  \
    \  pil = 0;\r\n    if (pir < SZ)\r\n        ibuf[pir++] = '\\n';\r\n}\r\n\r\n\
    inline void flush() {\r\n    fwrite(obuf, 1, por, stdout);\r\n    por = 0;\r\n\
    }\r\n\r\nvoid rd(char &c) {\r\n    do {\r\n        if (pil + 1 > pir)\r\n    \
    \        load();\r\n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\n\
    }\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\n    char c;\r\n    do {\r\n\
    \        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (isspace(c));\r\n    do {\r\n        x += c;\r\n        if (pil\
    \ == pir)\r\n            load();\r\n        c = ibuf[pil++];\r\n    } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T> void rd_real(T &x) {\r\n    string s;\r\n   \
    \ rd(s);\r\n    x = stod(s);\r\n}\r\n\r\ntemplate <typename T> void rd_integer(T\
    \ &x) {\r\n    if (pil + 100 > pir)\r\n        load();\r\n    char c;\r\n    do\r\
    \n        c = ibuf[pil++];\r\n    while (c < '-');\r\n    bool minus = 0;\r\n\
    \    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n        if\
    \ (c == '-') {\r\n            minus = 1, c = ibuf[pil++];\r\n        }\r\n   \
    \ }\r\n    x = 0;\r\n    while ('0' <= c) {\r\n        x = x * 10 + (c & 15),\
    \ c = ibuf[pil++];\r\n    }\r\n    if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\r\n        if (minus)\r\n            x = -x;\r\n    }\r\n}\r\n\r\n\
    void rd(int &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ll &x) {\r\n    rd_integer(x);\r\
    \n}\r\nvoid rd(i128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(uint &x) {\r\n\
    \    rd_integer(x);\r\n}\r\nvoid rd(ull &x) {\r\n    rd_integer(x);\r\n}\r\nvoid\
    \ rd(u128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(double &x) {\r\n    rd_real(x);\r\
    \n}\r\nvoid rd(long double &x) {\r\n    rd_real(x);\r\n}\r\n\r\ntemplate <class\
    \ T, class U> void rd(pair<T, U> &p) {\r\n    return rd(p.first), rd(p.second);\r\
    \n}\r\ntemplate <size_t N = 0, typename T> void rd_tuple(T &t) {\r\n    if constexpr\
    \ (N < std::tuple_size<T>::value) {\r\n        auto &x = std::get<N>(t);\r\n \
    \       rd(x);\r\n        rd_tuple<N + 1>(t);\r\n    }\r\n}\r\ntemplate <class...\
    \ T> void rd(tuple<T...> &tpl) {\r\n    rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t\
    \ N = 0, typename T> void rd(array<T, N> &x) {\r\n    for (auto &d : x)\r\n  \
    \      rd(d);\r\n}\r\ntemplate <class T> void rd(vector<T> &x) {\r\n    for (auto\
    \ &d : x)\r\n        rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T> void read(H &h, T &...t) {\r\n    rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n    if (por == SZ)\r\n        flush();\r\n    obuf[por++] = c;\r\
    \n}\r\nvoid wt(const string s) {\r\n    for (char c : s)\r\n        wt(c);\r\n\
    }\r\nvoid wt(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t\
    \ i = 0; i < len; i++)\r\n        wt(s[i]);\r\n}\r\n\r\ntemplate <typename T>\
    \ void wt_integer(T x) {\r\n    if (por > SZ - 100)\r\n        flush();\r\n  \
    \  if (x < 0) {\r\n        obuf[por++] = '-', x = -x;\r\n    }\r\n    int outi;\r\
    \n    for (outi = 96; x >= 10000; outi -= 4) {\r\n        memcpy(out + outi, pre.num[x\
    \ % 10000], 4);\r\n        x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n  \
    \      memcpy(obuf + por, pre.num[x], 4);\r\n        por += 4;\r\n    } else if\
    \ (x >= 100) {\r\n        memcpy(obuf + por, pre.num[x] + 1, 3);\r\n        por\
    \ += 3;\r\n    } else if (x >= 10) {\r\n        int q = (x * 103) >> 10;\r\n \
    \       obuf[por] = q | '0';\r\n        obuf[por + 1] = (x - q * 10) | '0';\r\n\
    \        por += 2;\r\n    } else\r\n        obuf[por++] = x | '0';\r\n    memcpy(obuf\
    \ + por, out + outi + 4, 96 - outi);\r\n    por += 96 - outi;\r\n}\r\n\r\ntemplate\
    \ <typename T> void wt_real(T x) {\r\n    ostringstream oss;\r\n    oss << fixed\
    \ << setprecision(15) << double(x);\r\n    string s = oss.str();\r\n    wt(s);\r\
    \n}\r\n\r\nvoid wt(int x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ll x) {\r\n\
    \    wt_integer(x);\r\n}\r\nvoid wt(i128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid\
    \ wt(uint x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ull x) {\r\n    wt_integer(x);\r\
    \n}\r\nvoid wt(u128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(double x) {\r\n\
    \    wt_real(x);\r\n}\r\nvoid wt(long double x) {\r\n    wt_real(x);\r\n}\r\n\r\
    \ntemplate <class T, class U> void wt(const pair<T, U> val) {\r\n    wt(val.first);\r\
    \n    wt(' ');\r\n    wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename\
    \ T> void wt_tuple(const T t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n        if constexpr (N > 0) {\r\n            wt(' ');\r\n        }\r\n\
    \        const auto x = std::get<N>(t);\r\n        wt(x);\r\n        wt_tuple<N\
    \ + 1>(t);\r\n    }\r\n}\r\ntemplate <class... T> void wt(tuple<T...> tpl) {\r\
    \n    wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S> void wt(const array<T,\
    \ S> val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++)\
    \ {\r\n        if (i)\r\n            wt(' ');\r\n        wt(val[i]);\r\n    }\r\
    \n}\r\ntemplate <class T> void wt(const vector<T> val) {\r\n    auto n = val.size();\r\
    \n    for (size_t i = 0; i < n; i++) {\r\n        if (i)\r\n            wt(' ');\r\
    \n        wt(val[i]);\r\n    }\r\n}\r\n\r\nvoid print() {\r\n    wt('\\n');\r\n\
    }\r\ntemplate <class Head, class... Tail> void print(Head &&head, Tail &&...tail)\
    \ {\r\n    wt(head);\r\n    if (sizeof...(Tail))\r\n        wt(' ');\r\n    print(forward<Tail>(tail)...);\r\
    \n}\r\nvoid __attribute__((destructor)) _d() {\r\n    flush();\r\n}\r\n} // namespace\
    \ fastio\r\n\r\nusing fastio::flush;\r\nusing fastio::print;\r\nusing fastio::read;\r\
    \n\r\ninline void first(bool i = true) {\r\n    print(i ? \"first\" : \"second\"\
    );\r\n}\r\ninline void Alice(bool i = true) {\r\n    print(i ? \"Alice\" : \"\
    Bob\");\r\n}\r\ninline void yes(bool i = true) {\r\n    print(i ? \"yes\" : \"\
    no\");\r\n}\r\ninline void Yes(bool i = true) {\r\n    print(i ? \"Yes\" : \"\
    No\");\r\n}\r\ninline void No() {\r\n    print(\"No\");\r\n}\r\ninline void YES(bool\
    \ i = true) {\r\n    print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void NO() {\r\
    \n    print(\"NO\");\r\n}\r\ninline void Yay(bool i = true) {\r\n    print(i ?\
    \ \"Yay!\" : \":(\");\r\n}\r\ninline void Possible(bool i = true) {\r\n    print(i\
    \ ? \"Possible\" : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool i = true)\
    \ {\r\n    print(i ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\n * @brief\
    \ Fast IO\r\n */\n#line 5 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\
    \n\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate <unsigned mod = 1000000007> struct\
    \ fp {\r\n    unsigned v;\r\n    static constexpr int get_mod() {\r\n        return\
    \ mod;\r\n    }\r\n    constexpr unsigned inv() const {\r\n        assert(v !=\
    \ 0);\r\n        int x = v, y = mod, p = 1, q = 0, t = 0, tmp = 0;\r\n       \
    \ while (y > 0) {\r\n            t = x / y;\r\n            x -= t * y, p -= t\
    \ * q;\r\n            tmp = x, x = y, y = tmp;\r\n            tmp = p, p = q,\
    \ q = tmp;\r\n        }\r\n        if (p < 0)\r\n            p += mod;\r\n   \
    \     return p;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod :\
    \ (mod - (-x) % mod) % mod) {}\r\n    fp operator-() const {\r\n        return\
    \ fp() - *this;\r\n    }\r\n    fp pow(ull t) {\r\n        fp res = 1, b = *this;\r\
    \n        while (t) {\r\n            if (t & 1)\r\n                res *= b;\r\
    \n            b *= b;\r\n            t >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n    fp &operator+=(const fp &x) {\r\n        if ((v += x.v) >= mod)\r\
    \n            v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator-=(const\
    \ fp &x) {\r\n        if ((v += mod - x.v) >= mod)\r\n            v -= mod;\r\n\
    \        return *this;\r\n    }\r\n    fp &operator*=(const fp &x) {\r\n     \
    \   v = ull(v) * x.v % mod;\r\n        return *this;\r\n    }\r\n    fp &operator/=(const\
    \ fp &x) {\r\n        v = ull(v) * x.inv() % mod;\r\n        return *this;\r\n\
    \    }\r\n    fp operator+(const fp &x) const {\r\n        return fp(*this) +=\
    \ x;\r\n    }\r\n    fp operator-(const fp &x) const {\r\n        return fp(*this)\
    \ -= x;\r\n    }\r\n    fp operator*(const fp &x) const {\r\n        return fp(*this)\
    \ *= x;\r\n    }\r\n    fp operator/(const fp &x) const {\r\n        return fp(*this)\
    \ /= x;\r\n    }\r\n    bool operator==(const fp &x) const {\r\n        return\
    \ v == x.v;\r\n    }\r\n    bool operator!=(const fp &x) const {\r\n        return\
    \ v != x.v;\r\n    }\r\n    friend istream &operator>>(istream &is, fp &x) {\r\
    \n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const fp &x) {\r\n        return os << x.v;\r\n    }\r\n};\r\n\r\ntemplate\
    \ <unsigned mod> void rd(fp<mod> &x) {\r\n    fastio::rd(x.v);\r\n}\r\ntemplate\
    \ <unsigned mod> void wt(fp<mod> x) {\r\n    fastio::wt(x.v);\r\n}\r\n\r\ntemplate\
    \ <typename T> T Inv(ll n) {\r\n    static const int md = T::get_mod();\r\n  \
    \  static vector<T> buf({0, 1});\r\n    assert(n > 0);\r\n    n %= md;\r\n   \
    \ while (SZ(buf) <= n) {\r\n        int k = SZ(buf), q = (md + k - 1) / k;\r\n\
    \        buf.push_back(buf[k * q - md] * q);\r\n    }\r\n    return buf[n];\r\n\
    }\r\n\r\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\r\n    static const\
    \ int md = T::get_mod();\r\n    static vector<T> buf({1, 1}), ibuf({1, 1});\r\n\
    \    assert(n >= 0 and n < md);\r\n    while (SZ(buf) <= n) {\r\n        buf.push_back(buf.back()\
    \ * SZ(buf));\r\n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\r\n \
    \   }\r\n    return inv ? ibuf[n] : buf[n];\r\n}\r\n\r\ntemplate <typename T>\
    \ T nPr(int n, int r, bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\n\
    \        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\r\n\
    }\r\ntemplate <typename T> T nCr(int n, int r, bool inv = 0) {\r\n    if (n <\
    \ 0 || n < r || r < 0)\r\n        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(r,\
    \ inv ^ 1) * Fact<T>(n - r, inv ^ 1);\r\n}\r\ntemplate <typename T> T nHr(int\
    \ n, int r, bool inv = 0) {\r\n    return nCr<T>(n + r - 1, r, inv);\r\n}\r\n\r\
    \n/**\r\n * @brief Modint\r\n */\n#line 7 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\
    \nusing Fp=fp<998244353>;\n\n#line 2 \"DataStructure/staticrectaddrectsum.hpp\"\
    \n\n#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct BIT{\r\n\
    \    int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\n\
    \    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\n\
    \        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 3 \"DataStructure/staticrectsum.hpp\"\
    \n\ntemplate<class T>struct StaticRectangleSum{\n    struct P{\n        ll x,y;\
    \ T w;\n    };\n    struct Rect{\n        ll l,d,r,u;\n    };\n    struct Q{\n\
    \        ll x,d,u,id,inv;\n    };\n    vector<P> plus;\n    vector<Rect> que;\n\
    \    StaticRectangleSum(){}\n    void add(ll x,ll y,T w){\n        plus.push_back({x,y,w});\n\
    \    }\n    void query(ll l,ll d,ll r,ll u){\n        que.push_back({l,d,r,u});\n\
    \    }\n    vector<T> run(){\n        ll n=plus.size(),q=que.size();\n       \
    \ sort(ALL(plus),[](P& p,P& q){return p.y<q.y;});\n        vector<ll> ys;\n  \
    \      rep(i,0,n)ys.push_back(plus[i].y);\n        ys.erase(unique(ALL(ys)),ys.end());\n\
    \        rep(i,0,n)plus[i].y=lower_bound(ALL(ys),plus[i].y)-ys.begin();\n    \
    \    vector<Q> qs;\n        rep(i,0,q){\n            auto& [l,d,r,u]=que[i];\n\
    \            d=lower_bound(ALL(ys),d)-ys.begin();\n            u=lower_bound(ALL(ys),u)-ys.begin();\n\
    \            qs.push_back({l,d,u,i,1});\n            qs.push_back({r,d,u,i,-1});\n\
    \        }\n        sort(ALL(plus),[](P& p,P& q){return p.x<q.x;});\n        sort(ALL(qs),[](Q&\
    \ p,Q& q){return p.x<q.x;});\n        vector<T> res(q);\n        ll k=0;\n   \
    \     BIT<T> bit(ys.size());\n        for(auto& q:qs){\n            while(k<n\
    \ and plus[k].x<q.x){\n                bit.add(plus[k].y,plus[k].w);\n       \
    \         k++;\n            }\n            res[q.id]+=bit.sum(q.u,q.d)*q.inv;\n\
    \        }\n        return res;\n    }\n};\n\n/**\n * @brief Static Rectangle\
    \ Sum\n*/\n#line 4 \"DataStructure/staticrectaddrectsum.hpp\"\ntemplate<typename\
    \ T>struct StaticRectangleAddRectangleSum{\n    StaticRectangleSum<T> bit[4];\
    \ //XY,X,Y,Const\n    struct Rect{int l,d,r,u;};\n    vector<Rect> que;\n    StaticRectangleAddRectangleSum(){}\n\
    \    void add(int x,int y,T w){\n        bit[0].add(x,y,w);\n        bit[1].add(x,y,w*-y);\n\
    \        bit[2].add(x,y,w*-x);\n        bit[3].add(x,y,w*x*y);\n    }\n    void\
    \ add(int l,int d,int r,int u,T w){\n        add(l,d,w);\n        add(l,u,-w);\n\
    \        add(r,d,-w);\n        add(r,u,w);\n    }\n    void query(int l,int d,int\
    \ r,int u){\n        que.push_back({l,d,r,u});\n    }\n    vector<T> run(){\n\
    \        int q=que.size();\n        for(auto& [l,d,r,u]:que){\n            rep(j,0,4){\n\
    \                bit[j].query(0,0,l,d);\n                bit[j].query(0,0,l,u);\n\
    \                bit[j].query(0,0,r,d);\n                bit[j].query(0,0,r,u);\n\
    \            }\n        }\n        auto XY=bit[0].run();\n        auto X=bit[1].run();\n\
    \        auto Y=bit[2].run();\n        auto Const=bit[3].run();\n        vector<T>\
    \ res(q);\n        rep(i,0,q){\n            auto [l,d,r,u]=que[i];\n         \
    \   res[i]+=XY[4*i]*l*d;\n            res[i]+=X[4*i]*l;\n            res[i]+=Y[4*i]*d;\n\
    \            res[i]+=Const[4*i];\n\n            res[i]-=XY[4*i+1]*l*u;\n     \
    \       res[i]-=X[4*i+1]*l;\n            res[i]-=Y[4*i+1]*u;\n            res[i]-=Const[4*i+1];\n\
    \n            res[i]-=XY[4*i+2]*r*d;\n            res[i]-=X[4*i+2]*r;\n      \
    \      res[i]-=Y[4*i+2]*d;\n            res[i]-=Const[4*i+2];\n\n            res[i]+=XY[4*i+3]*r*u;\n\
    \            res[i]+=X[4*i+3]*r;\n            res[i]+=Y[4*i+3]*u;\n          \
    \  res[i]+=Const[4*i+3];\n        }\n        return res;\n    }\n};\n\n/**\n *\
    \ @brief Static Rectangle Add Rectangle Sum\n*/\n#line 10 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\
    \n\nint main(){\n    int n,q;\n    read(n,q);\n\n    StaticRectangleAddRectangleSum<Fp>\
    \ buf;\n    rep(i,0,n){\n        int L,D,R,U,w;\n        read(L,D,R,U,w);\n  \
    \      buf.add(L,D,R,U,w);\n    }\n    rep(i,0,q){\n        int L,D,R,U;\n   \
    \     read(L,D,R,U);\n        buf.query(L,D,R,U);\n    }\n    auto ret=buf.run();\n\
    \    rep(i,0,q)print(ret[i].v);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/modint.hpp\"\nusing Fp=fp<998244353>;\n\n#include \"DataStructure/staticrectaddrectsum.hpp\"\
    \n\nint main(){\n    int n,q;\n    read(n,q);\n\n    StaticRectangleAddRectangleSum<Fp>\
    \ buf;\n    rep(i,0,n){\n        int L,D,R,U,w;\n        read(L,D,R,U,w);\n  \
    \      buf.add(L,D,R,U,w);\n    }\n    rep(i,0,q){\n        int L,D,R,U;\n   \
    \     read(L,D,R,U);\n        buf.query(L,D,R,U);\n    }\n    auto ret=buf.run();\n\
    \    rep(i,0,q)print(ret[i].v);\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - DataStructure/staticrectaddrectsum.hpp
  - DataStructure/staticrectsum.hpp
  - DataStructure/bit.hpp
  isVerificationFile: true
  path: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 03:32:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
- /verify/Verify/LC_static_rectangle_add_rectangle_sum.test.cpp.html
title: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
---
