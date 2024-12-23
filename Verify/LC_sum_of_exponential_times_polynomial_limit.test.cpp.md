---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/interpolate.hpp
    title: interpolate (one point)
  - icon: ':heavy_check_mark:'
    path: FPS/sumofpolyexp.hpp
    title: $\sum_{k} r^k\cdot poly(k)$
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Math/powertable.hpp
    title: Enumrate $n^k$
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define\
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
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename T> void _show(int\
    \ i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename T1, typename T2,\
    \ typename... T3>\r\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c)\
    \ {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\
    \n    cerr << \":\" << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2\
    \ \"Utility/fastio.hpp\"\n#include <unistd.h>\r\nnamespace fastio {\r\nstatic\
    \ constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar\
    \ out[100];\r\n// pointer of ibuf, obuf\r\n\r\nuint32_t pil = 0, pir = 0, por\
    \ = 0;\r\n\r\nstruct Pre {\r\n    char num[10000][4];\r\n    constexpr Pre() :\
    \ num() {\r\n        for (int i = 0; i < 10000; i++) {\r\n            int n =\
    \ i;\r\n            for (int j = 3; j >= 0; j--) {\r\n                num[i][j]\
    \ = n % 10 | '0';\r\n                n /= 10;\r\n            }\r\n        }\r\n\
    \    }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n    memmove(ibuf, ibuf\
    \ + pil, pir - pil);\r\n    pir = pir - pil + fread(ibuf + pir - pil, 1, SZ -\
    \ pir + pil, stdin);\r\n    pil = 0;\r\n    if (pir < SZ)\r\n        ibuf[pir++]\
    \ = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n    fwrite(obuf, 1, por, stdout);\r\
    \n    por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n    do {\r\n        if (pil +\
    \ 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\
    \n}\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\n    char c;\r\n    do {\r\
    \n        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
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
    Bob\");\r\n}\r\ninline void Takahashi(bool i = true) {\r\n    print(i ? \"Takahashi\"\
    \ : \"Aoki\");\r\n}\r\ninline void yes(bool i = true) {\r\n    print(i ? \"yes\"\
    \ : \"no\");\r\n}\r\ninline void Yes(bool i = true) {\r\n    print(i ? \"Yes\"\
    \ : \"No\");\r\n}\r\ninline void No() {\r\n    print(\"No\");\r\n}\r\ninline void\
    \ YES(bool i = true) {\r\n    print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void\
    \ NO() {\r\n    print(\"NO\");\r\n}\r\ninline void Yay(bool i = true) {\r\n  \
    \  print(i ? \"Yay!\" : \":(\");\r\n}\r\ninline void Possible(bool i = true) {\r\
    \n    print(i ? \"Possible\" : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool\
    \ i = true) {\r\n    print(i ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
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
    \ <unsigned mod> void wt(fp<mod> x) {\r\n    fastio::wt(x.v);\r\n}\r\n\r\n/**\r\
    \n * @brief Modint\r\n */\n#line 7 \"Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \nusing Fp=fp<998244353>;\n\n#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=50101010>vector<int>\
    \ sieve(int N){\r\n    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int\
    \ z=1;z<=5;z+=4){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for(int x=1;x<=sq\
    \ and (n=4*x*x+y*y)<=N;++x){\r\n                isp[n].flip();\r\n           \
    \ }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\n       \
    \         isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n    for(int\
    \ z=2;z<=4;z+=2){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for (int\
    \ x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){\r\n                isp[n].flip();\r\n\
    \            }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\
    \n                isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n  \
    \  for(int y=3;y<=sq;y+=6){\r\n        for(int z=1;z<=2;++z){\r\n            for(int\
    \ x=z;x<=sq and (n=4*x*x+y*y)<=N;x+=3){\r\n                isp[n].flip();\r\n\
    \            }\r\n        }\r\n    }\r\n    for(int n=5;n<=sq;++n)if(isp[n]){\r\
    \n        for(int k=n*n;k<=N;k+=n*n){\r\n            isp[k]=false;\r\n       \
    \ }\r\n    }\r\n    isp[2]=isp[3]=true;\r\n\r\n    vector<int> ret;\r\n    for(int\
    \ i=2;i<=N;i++)if(isp[i]){\r\n        ret.push_back(i);\r\n    }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/powertable.hpp\"\
    \n\ntemplate<typename T>vector<T> powertable(int n,ll k){ //0^k,1^k,..,n^k\n \
    \   assert(k>=0);\n    auto ps=sieve(n+1);\n    vector<T> f(n+1,1);\n    if(k)f[0]=0;\n\
    \    for(auto& p:ps){\n        T pk=T(p).pow(k);\n        for(ll q=p;q<=n;q*=p){\n\
    \            for(ll i=q;i<=n;i+=q)f[i]*=pk;\n        }\n    }\n    return f;\n\
    }\n\n/**\n * @brief Enumrate $n^k$\n*/\n#line 2 \"Math/comb.hpp\"\n\ntemplate\
    \ <typename T> T Inv(ll n) {\n    static int md;\n    static vector<T> buf({0,\
    \ 1});\n    if (md != T::get_mod()) {\n        md = T::get_mod();\n        buf\
    \ = vector<T>({0, 1});\n    }\n    assert(n > 0);\n    n %= md;\n    while (SZ(buf)\
    \ <= n) {\n        int k = SZ(buf), q = (md + k - 1) / k;\n        buf.push_back(buf[k\
    \ * q - md] * q);\n    }\n    return buf[n];\n}\n\ntemplate <typename T> T Fact(ll\
    \ n, bool inv = 0) {\n    static int md;\n    static vector<T> buf({1, 1}), ibuf({1,\
    \ 1});\n    if (md != T::get_mod()) {\n        md = T::get_mod();\n        buf\
    \ = ibuf = vector<T>({1, 1});\n    }\n    assert(n >= 0 and n < md);\n    while\
    \ (SZ(buf) <= n) {\n        buf.push_back(buf.back() * SZ(buf));\n        ibuf.push_back(ibuf.back()\
    \ * Inv<T>(SZ(ibuf)));\n    }\n    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate\
    \ <typename T> T nPr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r ||\
    \ r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^\
    \ 1);\n}\ntemplate <typename T> T nCr(int n, int r, bool inv = 0) {\n    if (n\
    \ < 0 || n < r || r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(r,\
    \ inv ^ 1) * Fact<T>(n - r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename\
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1,\
    \ inv);\n}\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T\
    \ choose(int n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return\
    \ nCr<T>(n + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3\
    \ \"FPS/interpolate.hpp\"\n\ntemplate<typename T>T Interpolate(vector<T>& ys,ll\
    \ t){ // f(0),..,f(d) -> f(t)\n    int d=ys.size()-1;\n    if(t<=d)return ys[t];\n\
    \    vector<T> L(d+1,1),R(d+1,1);\n    rep(i,0,d)L[i+1]=L[i]*(t-i);\n    for(int\
    \ i=d;i;i--)R[i-1]=R[i]*(t-i);\n    T ret;\n    rep(i,0,d+1){\n        T add=ys[i]*L[i]*R[i]*Fact<T>(i,1)*Fact<T>(d-i,1);\n\
    \        if((d-i)&1)ret-=add;\n        else ret+=add;\n    }\n    return ret;\n\
    }\n\n/**\n * @brief interpolate (one point)\n*/\n#line 4 \"FPS/sumofpolyexp.hpp\"\
    \n\ntemplate <typename T>\nT LimitSumOfPolyExp(vector<T> &f, T r) { // sum_{k=0}^inf\
    \ r^k*f(k)\n    assert(r != 1);\n    int d = f.size() - 1;\n    vector<T> rs(d\
    \ + 1);\n    rs[0] = 1;\n    rep(i, 0, d) rs[i + 1] = rs[i] * r;\n    T c, add;\n\
    \    rep(i, 0, d + 1) {\n        add += rs[i] * f[i];\n        if ((d - i) & 1)\n\
    \            c -= nCr<T>(d + 1, i + 1) * rs[d - i] * add;\n        else\n    \
    \        c += nCr<T>(d + 1, i + 1) * rs[d - i] * add;\n    }\n    c /= (-r + 1).pow(d\
    \ + 1);\n    return c;\n}\n\ntemplate <typename T>\nT SumOfPolyExp(vector<T> &f,\
    \ T r, ll n) { // sum_{k=0}^{n-1} r^k*f(k)\n    n--;\n    if (n < 0)\n       \
    \ return 0;\n    int d = f.size() - 1;\n    vector<T> rs(d + 1), rui(d + 1);\n\
    \    rs[0] = 1;\n    rep(i, 0, d) rs[i + 1] = rs[i] * r;\n    rep(i, 0, d + 1)\
    \ rui[i] = rs[i] * f[i];\n    rep(i, 0, d) rui[i + 1] += rui[i];\n    if (r ==\
    \ 0)\n        return f[0];\n    else if (r == 1)\n        return Interpolate(rui,\
    \ n);\n    else {\n        T c;\n        rep(i, 0, d + 1) c +=\n            nCr<T>(d\
    \ + 1, i + 1) * rs[d - i] * rui[i] * ((d - i) & 1 ? -1 : 1);\n        c /= T(-r\
    \ + 1).pow(d + 1);\n        vector<T> ys(d + 1);\n        T pwr = 1, invr = T(r).inv();\n\
    \        rep(i, 0, d + 1) ys[i] = (rui[i] - c) * pwr, pwr *= invr;\n        return\
    \ T(r).pow(n) * Interpolate(ys, n) + c;\n    }\n}\n\n/**\n * @brief $\\sum_{k}\
    \ r^k\\cdot poly(k)$\n */\n#line 11 \"Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n\nint main(){\n    Fp r;\n    int d;\n    read(r.v,d);\n\n    auto pws=powertable<Fp>(d+1,d);\n\
    \    auto ret=LimitSumOfPolyExp(pws,r);\n    print(ret.v);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/modint.hpp\"\nusing Fp=fp<998244353>;\n\n#include \"Math/powertable.hpp\"\
    \n#include \"FPS/sumofpolyexp.hpp\"\n\nint main(){\n    Fp r;\n    int d;\n  \
    \  read(r.v,d);\n\n    auto pws=powertable<Fp>(d+1,d);\n    auto ret=LimitSumOfPolyExp(pws,r);\n\
    \    print(ret.v);\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Math/powertable.hpp
  - Math/sieve.hpp
  - FPS/sumofpolyexp.hpp
  - FPS/interpolate.hpp
  - Math/comb.hpp
  isVerificationFile: true
  path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  requiredBy: []
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
- /verify/Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp.html
title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
---
