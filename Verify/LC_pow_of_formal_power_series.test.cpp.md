---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: FPS/fps.hpp
    title: Formal Power Series (NTT-friendly mod)
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"Verify/LC_pow_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\r\n\r\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \n * @brief Fast IO\r\n */\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate <unsigned\
    \ mod = 1000000007> struct fp {\r\n    unsigned v;\r\n    static constexpr int\
    \ get_mod() {\r\n        return mod;\r\n    }\r\n    constexpr unsigned inv()\
    \ const {\r\n        assert(v != 0);\r\n        int x = v, y = mod, p = 1, q =\
    \ 0, t = 0, tmp = 0;\r\n        while (y > 0) {\r\n            t = x / y;\r\n\
    \            x -= t * y, p -= t * q;\r\n            tmp = x, x = y, y = tmp;\r\
    \n            tmp = p, p = q, q = tmp;\r\n        }\r\n        if (p < 0)\r\n\
    \            p += mod;\r\n        return p;\r\n    }\r\n    constexpr fp(ll x\
    \ = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\r\n    fp operator-()\
    \ const {\r\n        return fp() - *this;\r\n    }\r\n    fp pow(ull t) {\r\n\
    \        fp res = 1, b = *this;\r\n        while (t) {\r\n            if (t &\
    \ 1)\r\n                res *= b;\r\n            b *= b;\r\n            t >>=\
    \ 1;\r\n        }\r\n        return res;\r\n    }\r\n    fp &operator+=(const\
    \ fp &x) {\r\n        if ((v += x.v) >= mod)\r\n            v -= mod;\r\n    \
    \    return *this;\r\n    }\r\n    fp &operator-=(const fp &x) {\r\n        if\
    \ ((v += mod - x.v) >= mod)\r\n            v -= mod;\r\n        return *this;\r\
    \n    }\r\n    fp &operator*=(const fp &x) {\r\n        v = ull(v) * x.v % mod;\r\
    \n        return *this;\r\n    }\r\n    fp &operator/=(const fp &x) {\r\n    \
    \    v = ull(v) * x.inv() % mod;\r\n        return *this;\r\n    }\r\n    fp operator+(const\
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
    \n * @brief Modint\r\n */\n#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate <typename\
    \ T> struct NTT {\r\n    static constexpr int rank2 = __builtin_ctzll(T::get_mod()\
    \ - 1);\r\n    std::array<T, rank2 + 1> root;  // root[i]^(2^i) == 1\r\n    std::array<T,\
    \ rank2 + 1> iroot; // root[i] * iroot[i] == 1\r\n\r\n    std::array<T, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\r\n    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;\r\
    \n\r\n    std::array<T, std::max(0, rank2 - 3 + 1)> rate3;\r\n    std::array<T,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\r\n\r\n    NTT() {\r\n        T g = 2;\r\
    \n        while (g.pow((T::get_mod() - 1) >> 1) == 1) {\r\n            g += 1;\r\
    \n        }\r\n        root[rank2] = g.pow((T::get_mod() - 1) >> rank2);\r\n \
    \       iroot[rank2] = root[rank2].inv();\r\n        for (int i = rank2 - 1; i\
    \ >= 0; i--) {\r\n            root[i] = root[i + 1] * root[i + 1];\r\n       \
    \     iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n        }\r\n\r\n        {\r\n\
    \            T prod = 1, iprod = 1;\r\n            for (int i = 0; i <= rank2\
    \ - 2; i++) {\r\n                rate2[i] = root[i + 2] * prod;\r\n          \
    \      irate2[i] = iroot[i + 2] * iprod;\r\n                prod *= iroot[i +\
    \ 2];\r\n                iprod *= root[i + 2];\r\n            }\r\n        }\r\
    \n        {\r\n            T prod = 1, iprod = 1;\r\n            for (int i =\
    \ 0; i <= rank2 - 3; i++) {\r\n                rate3[i] = root[i + 3] * prod;\r\
    \n                irate3[i] = iroot[i + 3] * iprod;\r\n                prod *=\
    \ iroot[i + 3];\r\n                iprod *= root[i + 3];\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    void ntt(std::vector<T> &a, bool type = 0) {\r\n\
    \        int n = int(a.size());\r\n        int h = __builtin_ctzll((unsigned int)n);\r\
    \n        a.resize(1 << h);\r\n\r\n        if (type) {\r\n            int len\
    \ = h; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n            while\
    \ (len) {\r\n                if (len == 1) {\r\n                    int p = 1\
    \ << (h - len);\r\n                    T irot = 1;\r\n                    for\
    \ (int s = 0; s < (1 << (len - 1)); s++) {\r\n                        int offset\
    \ = s << (h - len + 1);\r\n                        for (int i = 0; i < p; i++)\
    \ {\r\n                            auto l = a[i + offset];\r\n               \
    \             auto r = a[i + offset + p];\r\n                            a[i +\
    \ offset] = l + r;\r\n                            a[i + offset + p] =\r\n    \
    \                            (unsigned long long)(T::get_mod() + l.v - r.v) *\r\
    \n                                irot.v;\r\n                            ;\r\n\
    \                        }\r\n                        if (s + 1 != (1 << (len\
    \ - 1)))\r\n                            irot *= irate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len--;\r\n      \
    \          } else {\r\n                    // 4-base\r\n                    int\
    \ p = 1 << (h - len);\r\n                    T irot = 1, iimag = iroot[2];\r\n\
    \                    for (int s = 0; s < (1 << (len - 2)); s++) {\r\n        \
    \                T irot2 = irot * irot;\r\n                        T irot3 = irot2\
    \ * irot;\r\n                        int offset = s << (h - len + 2);\r\n    \
    \                    for (int i = 0; i < p; i++) {\r\n                       \
    \     auto a0 = 1ULL * a[i + offset + 0 * p].v;\r\n                          \
    \  auto a1 = 1ULL * a[i + offset + 1 * p].v;\r\n                            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].v;\r\n                            auto a3\
    \ = 1ULL * a[i + offset + 3 * p].v;\r\n\r\n                            auto a2na3iimag\
    \ =\r\n                                1ULL * T((T::get_mod() + a2 - a3) * iimag.v).v;\r\
    \n\r\n                            a[i + offset] = a0 + a1 + a2 + a3;\r\n     \
    \                       a[i + offset + 1 * p] =\r\n                          \
    \      (a0 + (T::get_mod() - a1) + a2na3iimag) *\r\n                         \
    \       irot.v;\r\n                            a[i + offset + 2 * p] =\r\n   \
    \                             (a0 + a1 + (T::get_mod() - a2) +\r\n           \
    \                      (T::get_mod() - a3)) *\r\n                            \
    \    irot2.v;\r\n                            a[i + offset + 3 * p] =\r\n     \
    \                           (a0 + (T::get_mod() - a1) +\r\n                  \
    \               (T::get_mod() - a2na3iimag)) *\r\n                           \
    \     irot3.v;\r\n                        }\r\n                        if (s +\
    \ 1 != (1 << (len - 2)))\r\n                            irot *= irate3[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len -= 2;\r\n   \
    \             }\r\n            }\r\n            T e = T(n).inv();\r\n        \
    \    for (auto &x : a)\r\n                x *= e;\r\n        } else {\r\n    \
    \        int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n\
    \            while (len < h) {\r\n                if (h - len == 1) {\r\n    \
    \                int p = 1 << (h - len - 1);\r\n                    T rot = 1;\r\
    \n                    for (int s = 0; s < (1 << len); s++) {\r\n             \
    \           int offset = s << (h - len);\r\n                        for (int i\
    \ = 0; i < p; i++) {\r\n                            auto l = a[i + offset];\r\n\
    \                            auto r = a[i + offset + p] * rot;\r\n           \
    \                 a[i + offset] = l + r;\r\n                            a[i +\
    \ offset + p] = l - r;\r\n                        }\r\n                      \
    \  if (s + 1 != (1 << len))\r\n                            rot *= rate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len++;\r\n      \
    \          } else {\r\n                    // 4-base\r\n                    int\
    \ p = 1 << (h - len - 2);\r\n                    T rot = 1, imag = root[2];\r\n\
    \                    for (int s = 0; s < (1 << len); s++) {\r\n              \
    \          T rot2 = rot * rot;\r\n                        T rot3 = rot2 * rot;\r\
    \n                        int offset = s << (h - len);\r\n                   \
    \     for (int i = 0; i < p; i++) {\r\n                            auto mod2 =\
    \ 1ULL * T::get_mod() * T::get_mod();\r\n                            auto a0 =\
    \ 1ULL * a[i + offset].v;\r\n                            auto a1 = 1ULL * a[i\
    \ + offset + p].v * rot.v;\r\n                            auto a2 = 1ULL * a[i\
    \ + offset + 2 * p].v * rot2.v;\r\n                            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].v * rot3.v;\r\n                            auto a1na3imag\
    \ =\r\n                                1ULL * T(a1 + mod2 - a3).v * imag.v;\r\n\
    \                            auto na2 = mod2 - a2;\r\n                       \
    \     a[i + offset] = a0 + a2 + a1 + a3;\r\n                            a[i +\
    \ offset + 1 * p] =\r\n                                a0 + a2 + (2 * mod2 - (a1\
    \ + a3));\r\n                            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n                            a[i + offset + 3 * p] =\r\n                    \
    \            a0 + na2 + (mod2 - a1na3imag);\r\n                        }\r\n \
    \                       if (s + 1 != (1 << len))\r\n                         \
    \   rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];\r\n                   \
    \ }\r\n                    len += 2;\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n    vector<T> mult(const vector<T> &a, const vector<T>\
    \ &b) {\r\n        if (a.empty() or b.empty())\r\n            return vector<T>();\r\
    \n        int as = a.size(), bs = b.size();\r\n        int n = as + bs - 1;\r\n\
    \        if (as <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n         \
    \       return mult(b, a);\r\n            vector<T> res(n);\r\n            rep(i,\
    \ 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\n            return res;\r\
    \n        }\r\n        int m = 1;\r\n        while (m < n)\r\n            m <<=\
    \ 1;\r\n        vector<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\n\
    \        ntt(res);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i] *=\
    \ res[i];\r\n        else {\r\n            vector<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            ntt(c);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        ntt(res, 1);\r\n        res.resize(n);\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */\n#line 2 \"FPS/fps.hpp\"\n\r\ntemplate <typename T> struct Poly : vector<T>\
    \ {\r\n    Poly(int n = 0) {\r\n        this->assign(n, T());\r\n    }\r\n   \
    \ Poly(const initializer_list<T> f) : vector<T>::vector(f) {}\r\n    Poly(const\
    \ vector<T> &f) {\r\n        this->assign(ALL(f));\r\n    }\r\n    int deg() const\
    \ {\r\n        return this->size() - 1;\r\n    }\r\n    T eval(const T &x) {\r\
    \n        T res;\r\n        for (int i = this->size() - 1; i >= 0; i--)\r\n  \
    \          res *= x, res += this->at(i);\r\n        return res;\r\n    }\r\n \
    \   Poly rev() const {\r\n        Poly res = *this;\r\n        reverse(ALL(res));\r\
    \n        return res;\r\n    }\r\n    void shrink() {\r\n        while (!this->empty()\
    \ and this->back() == 0)\r\n            this->pop_back();\r\n    }\r\n    Poly\
    \ operator>>(ll sz) const {\r\n        if ((int)this->size() <= sz)\r\n      \
    \      return {};\r\n        Poly ret(*this);\r\n        ret.erase(ret.begin(),\
    \ ret.begin() + sz);\r\n        return ret;\r\n    }\r\n    Poly operator<<(ll\
    \ sz) const {\r\n        Poly ret(*this);\r\n        ret.insert(ret.begin(), sz,\
    \ T(0));\r\n        return ret;\r\n    }\r\n    Poly<T> mult(const Poly<T> &a,\
    \ const Poly<T> &b) {\r\n        if (a.empty() or b.empty())\r\n            return\
    \ {};\r\n        int as = a.size(), bs = b.size();\r\n        int n = as + bs\
    \ - 1;\r\n        if (as <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n\
    \                return mult(b, a);\r\n            Poly<T> res(n);\r\n       \
    \     rep(i, 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\n            return\
    \ res;\r\n        }\r\n        int m = 1;\r\n        while (m < n)\r\n       \
    \     m <<= 1;\r\n        Poly<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\
    \n        res.NTT(0);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i]\
    \ *= res[i];\r\n        else {\r\n            Poly<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            c.NTT(0);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        res.NTT(1);\r\n        res.resize(n);\r\n \
    \       return res;\r\n    }\r\n    Poly square() const {\r\n        return Poly(mult(*this,\
    \ *this));\r\n    }\r\n    Poly operator-() const {\r\n        return Poly() -\
    \ *this;\r\n    }\r\n    Poly operator+(const Poly &g) const {\r\n        return\
    \ Poly(*this) += g;\r\n    }\r\n    Poly operator+(const T &g) const {\r\n   \
    \     return Poly(*this) += g;\r\n    }\r\n    Poly operator-(const Poly &g) const\
    \ {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator-(const T\
    \ &g) const {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator*(const\
    \ Poly &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator*(const\
    \ T &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator/(const\
    \ Poly &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator/(const\
    \ T &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator%(const\
    \ Poly &g) const {\r\n        return Poly(*this) %= g;\r\n    }\r\n    pair<Poly,\
    \ Poly> divmod(const Poly &g) const {\r\n        Poly q = *this / g, r = *this\
    \ - g * q;\r\n        r.shrink();\r\n        return {q, r};\r\n    }\r\n    Poly\
    \ &operator+=(const Poly &g) {\r\n        if (g.size() > this->size())\r\n   \
    \         this->resize(g.size());\r\n        rep(i, 0, g.size()) {\r\n       \
    \     (*this)[i] += g[i];\r\n        }\r\n        return *this;\r\n    }\r\n \
    \   Poly &operator+=(const T &g) {\r\n        if (this->empty())\r\n         \
    \   this->push_back(0);\r\n        (*this)[0] += g;\r\n        return *this;\r\
    \n    }\r\n    Poly &operator-=(const Poly &g) {\r\n        if (g.size() > this->size())\r\
    \n            this->resize(g.size());\r\n        rep(i, 0, g.size()) {\r\n   \
    \         (*this)[i] -= g[i];\r\n        }\r\n        return *this;\r\n    }\r\
    \n    Poly &operator-=(const T &g) {\r\n        if (this->empty())\r\n       \
    \     this->push_back(0);\r\n        (*this)[0] -= g;\r\n        return *this;\r\
    \n    }\r\n    Poly &operator*=(const Poly &g) {\r\n        *this = mult(*this,\
    \ g);\r\n        return *this;\r\n    }\r\n    Poly &operator*=(const T &g) {\r\
    \n        rep(i, 0, this->size())(*this)[i] *= g;\r\n        return *this;\r\n\
    \    }\r\n    Poly &operator/=(const Poly &g) {\r\n        if (g.size() > this->size())\
    \ {\r\n            this->clear();\r\n            return *this;\r\n        }\r\n\
    \        Poly g2 = g;\r\n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\
    \n        int n = this->size() - g2.size() + 1;\r\n        this->resize(n);\r\n\
    \        g2.resize(n);\r\n        *this *= g2.inv();\r\n        this->resize(n);\r\
    \n        reverse(ALL(*this));\r\n        shrink();\r\n        return *this;\r\
    \n    }\r\n    Poly &operator/=(const T &g) {\r\n        rep(i, 0, this->size())(*this)[i]\
    \ /= g;\r\n        return *this;\r\n    }\r\n    Poly &operator%=(const Poly &g)\
    \ {\r\n        *this -= *this / g * g;\r\n        shrink();\r\n        return\
    \ *this;\r\n    }\r\n    Poly diff() const {\r\n        Poly res(this->size()\
    \ - 1);\r\n        rep(i, 0, res.size()) res[i] = (*this)[i + 1] * (i + 1);\r\n\
    \        return res;\r\n    }\r\n    Poly inte() const {\r\n        Poly res(this->size()\
    \ + 1);\r\n        for (int i = res.size() - 1; i; i--)\r\n            res[i]\
    \ = (*this)[i - 1] / i;\r\n        return res;\r\n    }\r\n    Poly log() const\
    \ {\r\n        assert(this->front() == 1);\r\n        const int n = this->size();\r\
    \n        Poly res = diff() * inv();\r\n        res = res.inte();\r\n        res.resize(n);\r\
    \n        return res;\r\n    }\r\n    Poly shift(const int &c) const {\r\n   \
    \     const int n = this->size();\r\n        Poly res = *this, g(n);\r\n     \
    \   g[0] = 1;\r\n        rep(i, 1, n) g[i] = g[i - 1] * c / i;\r\n        vector<T>\
    \ fact(n, 1);\r\n        rep(i, 0, n) {\r\n            if (i)\r\n            \
    \    fact[i] = fact[i - 1] * i;\r\n            res[i] *= fact[i];\r\n        }\r\
    \n        res = res.rev();\r\n        res *= g;\r\n        res.resize(n);\r\n\
    \        res = res.rev();\r\n        rep(i, 0, n) res[i] /= fact[i];\r\n     \
    \   return res;\r\n    }\r\n    Poly inv() const {\r\n        const int n = this->size();\r\
    \n        Poly res(1);\r\n        res.front() = T(1) / this->front();\r\n    \
    \    for (int k = 1; k < n; k <<= 1) {\r\n            Poly f(k * 2), g(k * 2);\r\
    \n            rep(i, 0, min(n, k * 2)) f[i] = (*this)[i];\r\n            rep(i,\
    \ 0, k) g[i] = res[i];\r\n            f.NTT(0);\r\n            g.NTT(0);\r\n \
    \           rep(i, 0, k * 2) f[i] *= g[i];\r\n            f.NTT(1);\r\n      \
    \      rep(i, 0, k) {\r\n                f[i] = 0;\r\n                f[i + k]\
    \ = -f[i + k];\r\n            }\r\n            f.NTT(0);\r\n            rep(i,\
    \ 0, k * 2) f[i] *= g[i];\r\n            f.NTT(1);\r\n            rep(i, 0, k)\
    \ f[i] = res[i];\r\n            swap(res, f);\r\n        }\r\n        res.resize(n);\r\
    \n        return res;\r\n    }\r\n    Poly exp() const {\r\n        const int\
    \ n = this->size();\r\n        if (n == 1)\r\n            return Poly({T(1)});\r\
    \n        Poly b(2), c(1), z1, z2(2);\r\n        b[0] = c[0] = z2[0] = z2[1] =\
    \ 1;\r\n        b[1] = (*this)[1];\r\n        for (int k = 2; k < n; k <<= 1)\
    \ {\r\n            Poly y = b;\r\n            y.resize(k * 2);\r\n           \
    \ y.NTT(0);\r\n            z1 = z2;\r\n            Poly z(k);\r\n            rep(i,\
    \ 0, k) z[i] = y[i] * z1[i];\r\n            z.NTT(1);\r\n            rep(i, 0,\
    \ k >> 1) z[i] = 0;\r\n            z.NTT(0);\r\n            rep(i, 0, k) z[i]\
    \ *= -z1[i];\r\n            z.NTT(1);\r\n            c.insert(c.end(), z.begin()\
    \ + (k >> 1), z.end());\r\n            z2 = c;\r\n            z2.resize(k * 2);\r\
    \n            z2.NTT(0);\r\n            Poly x = *this;\r\n            x.resize(k);\r\
    \n            x = x.diff();\r\n            x.resize(k);\r\n            x.NTT(0);\r\
    \n            rep(i, 0, k) x[i] *= y[i];\r\n            x.NTT(1);\r\n        \
    \    Poly bb = b.diff();\r\n            rep(i, 0, k - 1) x[i] -= bb[i];\r\n  \
    \          x.resize(k * 2);\r\n            rep(i, 0, k - 1) {\r\n            \
    \    x[k + i] = x[i];\r\n                x[i] = 0;\r\n            }\r\n      \
    \      x.NTT(0);\r\n            rep(i, 0, k * 2) x[i] *= z2[i];\r\n          \
    \  x.NTT(1);\r\n            x.pop_back();\r\n            x = x.inte();\r\n   \
    \         rep(i, k, min(n, k * 2)) x[i] += (*this)[i];\r\n            rep(i, 0,\
    \ k) x[i] = 0;\r\n            x.NTT(0);\r\n            rep(i, 0, k * 2) x[i] *=\
    \ y[i];\r\n            x.NTT(1);\r\n            b.insert(b.end(), x.begin() +\
    \ k, x.end());\r\n        }\r\n        b.resize(n);\r\n        return b;\r\n \
    \   }\r\n    Poly pow(ll t) {\r\n        if (t == 0) {\r\n            Poly res(this->size());\r\
    \n            res[0] = 1;\r\n            return res;\r\n        }\r\n        int\
    \ n = this->size(), k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n  \
    \          k++;\r\n        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\
    \n            return res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n   \
    \     T c = (*this)[k], ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i\
    \ + k] * ic;\r\n        g = g.log();\r\n        for (auto &x : g)\r\n        \
    \    x *= t;\r\n        g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i,\
    \ 0, n) res[i + t * k] = g[i] * c;\r\n        return res;\r\n    }\r\n    void\
    \ NTT(bool inv);\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series (NTT-friendly\
    \ mod)\r\n */\n#line 8 \"Verify/LC_pow_of_formal_power_series.test.cpp\"\n\r\n\
    using Fp = fp<998244353>;\r\nNTT<Fp> ntt;\r\ntemplate <> void Poly<Fp>::NTT(bool\
    \ inv) {\r\n    ntt.ntt(*this, inv);\r\n}\r\n\r\nint main() {\r\n    int n;\r\n\
    \    cin >> n;\r\n    ll k;\r\n    cin >> k;\r\n    Poly<Fp> a(n);\r\n    rep(i,\
    \ 0, n) cin >> a[i];\r\n    a = a.pow(k);\r\n    rep(i, 0, n) cout << a[i] <<\
    \ '\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n#include \"Math/modint.hpp\"\r\n#include \"Convolution/ntt.hpp\"\r\n#include\
    \ \"FPS/fps.hpp\"\r\n\r\nusing Fp = fp<998244353>;\r\nNTT<Fp> ntt;\r\ntemplate\
    \ <> void Poly<Fp>::NTT(bool inv) {\r\n    ntt.ntt(*this, inv);\r\n}\r\n\r\nint\
    \ main() {\r\n    int n;\r\n    cin >> n;\r\n    ll k;\r\n    cin >> k;\r\n  \
    \  Poly<Fp> a(n);\r\n    rep(i, 0, n) cin >> a[i];\r\n    a = a.pow(k);\r\n  \
    \  rep(i, 0, n) cout << a[i] << '\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - FPS/fps.hpp
  isVerificationFile: true
  path: Verify/LC_pow_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_pow_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_pow_of_formal_power_series.test.cpp
- /verify/Verify/LC_pow_of_formal_power_series.test.cpp.html
title: Verify/LC_pow_of_formal_power_series.test.cpp
---
