---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: FPS/arbitraryfps.hpp
    title: Formal Power Series (Arbitrary mod)
  - icon: ':heavy_check_mark:'
    path: FPS/multievalgeom.hpp
    title: Multipoint Evaluation on Geometric Sequence
  - icon: ':heavy_check_mark:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':heavy_check_mark:'
    path: Math/fastdiv.hpp
    title: Fast Division
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multivariate_convolution_cyclic
    links:
    - https://judge.yosupo.jp/problem/multivariate_convolution_cyclic
  bundledCode: "#line 1 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\n#define\
    \ PROBLEM                                                                \\\n\
    \    \"https://judge.yosupo.jp/problem/multivariate_convolution_cyclic\"\n\n#line\
    \ 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\n#define\
    \ rrep(i, a, b) for (int i = (int)(b-1); i >= (int)(a); i--)\r\n#define ALL(v)\
    \ (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
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
    \ Fast IO\r\n */\n#line 6 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\
    \n\n#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * @brief Fast\
    \ Division\n*/\n#line 3 \"Math/dynamic.hpp\"\n\r\nstruct Fp{\r\n    using u64=uint64_t;\r\
    \n    int v;\r\n    static int get_mod(){return _getmod();}\r\n    static void\
    \ set_mod(int _m){bar=FastDiv(_m);}\r\n    Fp inv() const{\r\n        int tmp,a=v,b=get_mod(),x=1,y=0;\r\
    \n        while(b){\r\n            tmp=a/b,a-=tmp*b;\r\n            swap(a,b);\r\
    \n            x-=tmp*y;\r\n            swap(x,y);\r\n        }\r\n        if(x<0){x+=get_mod();}\r\
    \n        return x;\r\n    }\r\n    Fp():v(0){}\r\n    Fp(ll x){\r\n        v=x%get_mod();\r\
    \n        if(v<0)v+=get_mod();\r\n    }\r\n    Fp operator-()const{return Fp()-*this;}\r\
    \n    Fp pow(ll t){\r\n        assert(t>=0);\r\n        Fp res=1,b=*this;\r\n\
    \        while(t){\r\n            if(t&1)res*=b;\r\n            b*=b;\r\n    \
    \        t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    Fp& operator+=(const\
    \ Fp& x){\r\n        v+=x.v;\r\n        if(v>=get_mod())v-=get_mod();\r\n    \
    \    return *this;\r\n    }\r\n    Fp& operator-=(const Fp& x){\r\n        v+=get_mod()-x.v;\r\
    \n        if(v>=get_mod())v-=get_mod();\r\n        return *this;\r\n    }\r\n\
    \    Fp& operator*=(const Fp& x){\r\n        v=(u64(v)*x.v)%bar;\r\n        return\
    \ *this;\r\n    }\r\n    Fp& operator/=(const Fp& x){\r\n        (*this)*=x.inv();\r\
    \n        return *this;\r\n    }\r\n    Fp operator+(const Fp& x)const{return\
    \ Fp(*this)+=x;}\r\n    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}\r\
    \n    Fp operator*(const Fp& x)const{return Fp(*this)*=x;}\r\n    Fp operator/(const\
    \ Fp& x)const{return Fp(*this)/=x;}\r\n    bool operator==(const Fp& x)const{return\
    \ v==x.v;}\r\n    bool operator!=(const Fp& x)const{return v!=x.v;}\r\nprivate:\r\
    \n    static FastDiv bar;\r\n    static int _getmod(){return bar.get();}\r\n};\r\
    \nFastDiv Fp::bar(998244353);\r\n\r\n/**\r\n * @brief Dynamic Modint\r\n */\n\
    #line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate <typename T> struct NTT {\r\n  \
    \  static constexpr int rank2 = __builtin_ctzll(T::get_mod() - 1);\r\n    std::array<T,\
    \ rank2 + 1> root;  // root[i]^(2^i) == 1\r\n    std::array<T, rank2 + 1> iroot;\
    \ // root[i] * iroot[i] == 1\r\n\r\n    std::array<T, std::max(0, rank2 - 2 +\
    \ 1)> rate2;\r\n    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;\r\n\r\n\
    \    std::array<T, std::max(0, rank2 - 3 + 1)> rate3;\r\n    std::array<T, std::max(0,\
    \ rank2 - 3 + 1)> irate3;\r\n\r\n    NTT() {\r\n        T g = 2;\r\n        while\
    \ (g.pow((T::get_mod() - 1) >> 1) == 1) {\r\n            g += 1;\r\n        }\r\
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
    \       a[i + offset + p] =\r\n                                (unsigned long\
    \ long)(T::get_mod() + l.v - r.v) *\r\n                                irot.v;\r\
    \n                            ;\r\n                        }\r\n             \
    \           if (s + 1 != (1 << (len - 1)))\r\n                            irot\
    \ *= irate2[__builtin_ctzll(~(unsigned int)(s))];\r\n                    }\r\n\
    \                    len--;\r\n                } else {\r\n                  \
    \  // 4-base\r\n                    int p = 1 << (h - len);\r\n              \
    \      T irot = 1, iimag = iroot[2];\r\n                    for (int s = 0; s\
    \ < (1 << (len - 2)); s++) {\r\n                        T irot2 = irot * irot;\r\
    \n                        T irot3 = irot2 * irot;\r\n                        int\
    \ offset = s << (h - len + 2);\r\n                        for (int i = 0; i <\
    \ p; i++) {\r\n                            auto a0 = 1ULL * a[i + offset + 0 *\
    \ p].v;\r\n                            auto a1 = 1ULL * a[i + offset + 1 * p].v;\r\
    \n                            auto a2 = 1ULL * a[i + offset + 2 * p].v;\r\n  \
    \                          auto a3 = 1ULL * a[i + offset + 3 * p].v;\r\n\r\n \
    \                           auto a2na3iimag =\r\n                            \
    \    1ULL * T((T::get_mod() + a2 - a3) * iimag.v).v;\r\n\r\n                 \
    \           a[i + offset] = a0 + a1 + a2 + a3;\r\n                           \
    \ a[i + offset + 1 * p] =\r\n                                (a0 + (T::get_mod()\
    \ - a1) + a2na3iimag) *\r\n                                irot.v;\r\n       \
    \                     a[i + offset + 2 * p] =\r\n                            \
    \    (a0 + a1 + (T::get_mod() - a2) +\r\n                                 (T::get_mod()\
    \ - a3)) *\r\n                                irot2.v;\r\n                   \
    \         a[i + offset + 3 * p] =\r\n                                (a0 + (T::get_mod()\
    \ - a1) +\r\n                                 (T::get_mod() - a2na3iimag)) *\r\
    \n                                irot3.v;\r\n                        }\r\n  \
    \                      if (s + 1 != (1 << (len - 2)))\r\n                    \
    \        irot *= irate3[__builtin_ctzll(~(unsigned int)(s))];\r\n            \
    \        }\r\n                    len -= 2;\r\n                }\r\n         \
    \   }\r\n            T e = T(n).inv();\r\n            for (auto &x : a)\r\n  \
    \              x *= e;\r\n        } else {\r\n            int len = 0; // a[i,\
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
    \ na2 = mod2 - a2;\r\n                            a[i + offset] = a0 + a2 + a1\
    \ + a3;\r\n                            a[i + offset + 1 * p] =\r\n           \
    \                     a0 + a2 + (2 * mod2 - (a1 + a3));\r\n                  \
    \          a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n                 \
    \           a[i + offset + 3 * p] =\r\n                                a0 + na2\
    \ + (mod2 - a1na3imag);\r\n                        }\r\n                     \
    \   if (s + 1 != (1 << len))\r\n                            rot *= rate3[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len += 2;\r\n   \
    \             }\r\n            }\r\n        }\r\n    }\r\n    vector<T> mult(const\
    \ vector<T> &a, const vector<T> &b) {\r\n        if (a.empty() or b.empty())\r\
    \n            return vector<T>();\r\n        int as = a.size(), bs = b.size();\r\
    \n        int n = as + bs - 1;\r\n        if (as <= 30 or bs <= 30) {\r\n    \
    \        if (as > 30)\r\n                return mult(b, a);\r\n            vector<T>\
    \ res(n);\r\n            rep(i, 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\
    \n            return res;\r\n        }\r\n        int m = 1;\r\n        while\
    \ (m < n)\r\n            m <<= 1;\r\n        vector<T> res(m);\r\n        rep(i,\
    \ 0, as) res[i] = a[i];\r\n        ntt(res);\r\n        if (a == b)\r\n      \
    \      rep(i, 0, m) res[i] *= res[i];\r\n        else {\r\n            vector<T>\
    \ c(m);\r\n            rep(i, 0, bs) c[i] = b[i];\r\n            ntt(c);\r\n \
    \           rep(i, 0, m) res[i] *= c[i];\r\n        }\r\n        ntt(res, 1);\r\
    \n        res.resize(n);\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Number Theoretic Transform\r\n */\n#line 2 \"Math/modint.hpp\"\n\r\n\
    template <unsigned mod = 1000000007> struct fp {\r\n    unsigned v;\r\n    static\
    \ constexpr int get_mod() {\r\n        return mod;\r\n    }\r\n    constexpr unsigned\
    \ inv() const {\r\n        assert(v != 0);\r\n        int x = v, y = mod, p =\
    \ 1, q = 0, t = 0, tmp = 0;\r\n        while (y > 0) {\r\n            t = x /\
    \ y;\r\n            x -= t * y, p -= t * q;\r\n            tmp = x, x = y, y =\
    \ tmp;\r\n            tmp = p, p = q, q = tmp;\r\n        }\r\n        if (p <\
    \ 0)\r\n            p += mod;\r\n        return p;\r\n    }\r\n    constexpr fp(ll\
    \ x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\r\n    fp operator-()\
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
    \n/**\r\n * @brief Modint\r\n */\n#line 4 \"Convolution/arbitrary.hpp\"\n\r\n\
    using M1 = fp<1045430273>;\r\nusing M2 = fp<1051721729>;\r\nusing M3 = fp<1053818881>;\r\
    \nNTT<M1> N1;\r\nNTT<M2> N2;\r\nNTT<M3> N3;\r\nconstexpr int r_12 = M2(M1::get_mod()).inv();\r\
    \nconstexpr int r_13 = M3(M1::get_mod()).inv();\r\nconstexpr int r_23 = M3(M2::get_mod()).inv();\r\
    \nconstexpr int r_1323 = M3(ll(r_13) * r_23).v;\r\nconstexpr ll w1 = M1::get_mod();\r\
    \nconstexpr ll w2 = ll(w1) * M2::get_mod();\r\ntemplate <typename T>\r\nvector<T>\
    \ ArbitraryMult(const vector<int> &a, const vector<int> &b) {\r\n    if (a.empty()\
    \ or b.empty())\r\n        return vector<T>();\r\n    int n = a.size() + b.size()\
    \ - 1;\r\n    vector<T> res(n);\r\n    if (min(a.size(), b.size()) <= 60) {\r\n\
    \        rep(i, 0, a.size()) rep(j, 0, b.size()) res[i + j] += T(a[i]) * b[j];\r\
    \n        return res;\r\n    }\r\n    vector<int> vals[3];\r\n    vector<M1> a1(ALL(a)),\
    \ b1(ALL(b)), c1 = N1.mult(a1, b1);\r\n    vector<M2> a2(ALL(a)), b2(ALL(b)),\
    \ c2 = N2.mult(a2, b2);\r\n    vector<M3> a3(ALL(a)), b3(ALL(b)), c3 = N3.mult(a3,\
    \ b3);\r\n    for (M1 x : c1)\r\n        vals[0].push_back(x.v);\r\n    for (M2\
    \ x : c2)\r\n        vals[1].push_back(x.v);\r\n    for (M3 x : c3)\r\n      \
    \  vals[2].push_back(x.v);\r\n    rep(i, 0, n) {\r\n        ll p = vals[0][i];\r\
    \n        ll q = (vals[1][i] + M2::get_mod() - p) * r_12 % M2::get_mod();\r\n\
    \        ll r = ((vals[2][i] + M3::get_mod() - p) * r_1323 +\r\n             \
    \   (M3::get_mod() - q) * r_23) %\r\n               M3::get_mod();\r\n       \
    \ res[i] = (T(r) * w2 + q * w1 + p);\r\n    }\r\n    return res;\r\n}\r\n\r\n\
    template <typename T>\r\nvector<T> ArbitraryMult(const vector<T> &a, const vector<T>\
    \ &b) {\r\n    vector<int> A, B;\r\n    for (auto &x : a)\r\n        A.push_back(x.v);\r\
    \n    for (auto &x : b)\r\n        B.push_back(x.v);\r\n    return ArbitraryMult<T>(A,\
    \ B);\r\n}\r\n\r\n/**\r\n * @brief Arbitrary Mod Convolution\r\n */\n#line 2 \"\
    FPS/arbitraryfps.hpp\"\n\r\ntemplate <typename T> struct Poly : vector<T> {\r\n\
    \    Poly(int n = 0) {\r\n        this->assign(n, T());\r\n    }\r\n    Poly(const\
    \ initializer_list<T> f) : vector<T>::vector(f) {}\r\n    Poly(const vector<T>\
    \ &f) {\r\n        this->assign(ALL(f));\r\n    }\r\n    int deg() const {\r\n\
    \        return this->size() - 1;\r\n    }\r\n    T eval(const T &x) {\r\n   \
    \     T res;\r\n        for (int i = this->size() - 1; i >= 0; i--)\r\n      \
    \      res *= x, res += this->at(i);\r\n        return res;\r\n    }\r\n    Poly\
    \ rev() const {\r\n        Poly res = *this;\r\n        reverse(ALL(res));\r\n\
    \        return res;\r\n    }\r\n    void shrink() {\r\n        while (!this->empty()\
    \ and this->back() == 0)\r\n            this->pop_back();\r\n    }\r\n    Poly\
    \ operator>>(ll sz) const {\r\n        if ((int)this->size() <= sz)\r\n      \
    \      return {};\r\n        Poly ret(*this);\r\n        ret.erase(ret.begin(),\
    \ ret.begin() + sz);\r\n        return ret;\r\n    }\r\n    Poly operator<<(ll\
    \ sz) const {\r\n        Poly ret(*this);\r\n        ret.insert(ret.begin(), sz,\
    \ T(0));\r\n        return ret;\r\n    }\r\n    Poly inv() const {\r\n       \
    \ assert(this->front() != 0);\r\n        const int n = this->size();\r\n     \
    \   Poly res(1);\r\n        res.front() = T(1) / this->front();\r\n        for\
    \ (int k = 1; k < n; k <<= 1) {\r\n            Poly g = res, h = *this;\r\n  \
    \          h.resize(k * 2);\r\n            res.resize(k * 2);\r\n            g\
    \ = (g.square() * h);\r\n            g.resize(k * 2);\r\n            rep(i, k,\
    \ min(k * 2, n)) res[i] -= g[i];\r\n        }\r\n        res.resize(n);\r\n  \
    \      return res;\r\n    }\r\n    Poly square() const {\r\n        return Poly(mult(*this,\
    \ *this));\r\n    }\r\n    Poly operator-() const {\r\n        return Poly() -\
    \ *this;\r\n    }\r\n    Poly operator+(const Poly &g) const {\r\n        return\
    \ Poly(*this) += g;\r\n    }\r\n    Poly operator+(const T &g) const {\r\n   \
    \     return Poly(*this) += g;\r\n    }\r\n    Poly operator-(const Poly &g) const\
    \ {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator-(const T\
    \ &g) const {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator*(const\
    \ Poly &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator*(const\
    \ T &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator/(const\
    \ Poly &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator%(const\
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
    \n    }\r\n    Poly &operator%=(const Poly &g) {\r\n        *this -= *this / g\
    \ * g;\r\n        shrink();\r\n        return *this;\r\n    }\r\n    Poly diff()\
    \ const {\r\n        Poly res(this->size() - 1);\r\n        rep(i, 0, res.size())\
    \ res[i] = (*this)[i + 1] * (i + 1);\r\n        return res;\r\n    }\r\n    Poly\
    \ inte() const {\r\n        Poly res(this->size() + 1);\r\n        for (int i\
    \ = res.size() - 1; i; i--)\r\n            res[i] = (*this)[i - 1] / i;\r\n  \
    \      return res;\r\n    }\r\n    Poly log() const {\r\n        assert(this->front()\
    \ == 1);\r\n        const int n = this->size();\r\n        Poly res = diff() *\
    \ inv();\r\n        res = res.inte();\r\n        res.resize(n);\r\n        return\
    \ res;\r\n    }\r\n    Poly exp() const {\r\n        assert(this->front() == 0);\r\
    \n        const int n = this->size();\r\n        Poly res(1), g(1);\r\n      \
    \  res.front() = g.front() = 1;\r\n        for (int k = 1; k < n; k <<= 1) {\r\
    \n            g = (g + g - g.square() * res);\r\n            g.resize(k);\r\n\
    \            Poly q = *this;\r\n            q.resize(k);\r\n            q = q.diff();\r\
    \n            Poly w = (q + g * (res.diff() - res * q)), t = *this;\r\n      \
    \      w.resize(k * 2 - 1);\r\n            t.resize(k * 2);\r\n            res\
    \ = (res + res * (t - w.inte()));\r\n            res.resize(k * 2);\r\n      \
    \  }\r\n        res.resize(n);\r\n        return res;\r\n    }\r\n    Poly shift(const\
    \ int &c) const {\r\n        const int n = this->size();\r\n        Poly res =\
    \ *this, g(n);\r\n        g[0] = 1;\r\n        rep(i, 1, n) g[i] = g[i - 1] *\
    \ c / i;\r\n        vector<T> fact(n, 1);\r\n        rep(i, 0, n) {\r\n      \
    \      if (i)\r\n                fact[i] = fact[i - 1] * i;\r\n            res[i]\
    \ *= fact[i];\r\n        }\r\n        res = res.rev();\r\n        res *= g;\r\n\
    \        res.resize(n);\r\n        res = res.rev();\r\n        rep(i, 0, n) res[i]\
    \ /= fact[i];\r\n        return res;\r\n    }\r\n    Poly pow(ll t) {\r\n    \
    \    if (t == 0) {\r\n            Poly res(this->size());\r\n            res[0]\
    \ = 1;\r\n            return res;\r\n        }\r\n        int n = this->size(),\
    \ k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n            k++;\r\n\
    \        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\n            return\
    \ res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n        T c = (*this)[k],\
    \ ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i + k] * ic;\r\n      \
    \  g = g.log();\r\n        for (auto &x : g)\r\n            x *= t;\r\n      \
    \  g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i, 0, n) res[i + t * k]\
    \ = g[i] * c;\r\n        return res;\r\n    }\r\n    vector<T> mult(const vector<T>\
    \ &a, const vector<T> &b) const;\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series\
    \ (Arbitrary mod)\r\n */\n#line 10 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\
    \ntemplate <>\nvector<Fp> Poly<Fp>::mult(const vector<Fp> &a, const vector<Fp>\
    \ &b) const {\n    return ArbitraryMult<Fp>(a, b);\n}\n#line 2 \"Math/miller.hpp\"\
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
    \n * @brief Primitive Function\r\n */\n#line 2 \"FPS/multievalgeom.hpp\"\n\ntemplate<typename\
    \ T>vector<T> MultievalGeomSeq(vector<T>& f,T a,T w,int m){\n    int n=f.size();\n\
    \    vector<T> ret(m);\n    if(w==0){\n        T base=1;\n        rep(i,0,n)ret[0]+=base*f[i],base*=a;\n\
    \        rep(i,1,m)ret[i]=f[0];\n        return ret;\n    }\n    vector<T> tri(n+m-1),itri(n+m-1);\n\
    \    tri[0]=itri[0]=1;\n    T iw=w.inv(),pww=1,pwiw=1;\n    for(int i=1;i<n+m-1;i++,pww*=w,pwiw*=iw){\n\
    \        tri[i]=tri[i-1]*pww;\n        itri[i]=itri[i-1]*pwiw;\n    }\n\n    Poly<T>\
    \ y(n),v(n+m-1);\n    T pwa=1;\n    for(int i=0;i<n;i++,pwa*=a){\n        y[i]=f[i]*itri[i]*pwa;\n\
    \    }\n    rep(i,0,n+m-1)v[i]=tri[i];\n    reverse(ALL(y));\n    y*=v;\n    rep(i,0,m)ret[i]=y[n-1+i]*itri[i];\n\
    \    return ret;\n}\n\n/**\n * @brief Multipoint Evaluation on Geometric Sequence\n\
    */\n#line 4 \"Convolution/multivariatecyclic.hpp\"\n\ntemplate<typename T>vector<T>\
    \ MultivariateCyclic\n    (vector<T> f,vector<T> g,vector<int>& a){\n    int MO=T::get_mod();\n\
    \    int k=a.size(),n=1;\n    for(auto& x:a)n*=x;\n    T pr=getPrimitiveRoot(MO),ipr=T(pr).inv();\n\
    \n    int offset=1;\n    rep(x,0,k){\n        assert((MO-1)%a[x]==0);\n      \
    \  T w=pr.pow((MO-1)/a[x]);\n        rep(i,0,n)if(i%(offset*a[x])<offset){\n \
    \           vector<T> na(a[x]),nb(a[x]);\n            rep(j,0,a[x]){\n       \
    \         na[j]=f[i+offset*j];\n                nb[j]=g[i+offset*j];\n       \
    \     }\n            na=MultievalGeomSeq(na,T(1),w,a[x]);\n            nb=MultievalGeomSeq(nb,T(1),w,a[x]);\n\
    \            rep(j,0,a[x]){\n                f[i+offset*j]=na[j];\n          \
    \      g[i+offset*j]=nb[j];\n            }\n        }\n        offset*=a[x];\n\
    \    }\n\n    rep(i,0,n)f[i]*=g[i];\n    \n    offset=1;\n    rep(x,0,k){\n  \
    \      T iw=ipr.pow((MO-1)/a[x]);\n        rep(i,0,n)if(i%(offset*a[x])<offset){\n\
    \            vector<T> na(a[x]);\n            rep(j,0,a[x])na[j]=f[i+offset*j];\n\
    \            na=MultievalGeomSeq(na,T(1),iw,a[x]);\n            rep(j,0,a[x])f[i+offset*j]=na[j];\n\
    \        }\n        offset*=a[x];\n    }\n    T ninv=T(n).inv();\n    rep(i,0,n)f[i]*=ninv;\n\
    \    return f;\n}\n\n/**\n * @brief Multivarate Convolution Cyclic\n*/\n#line\
    \ 15 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\n\nint main() {\n\
    \    int p, k;\n    read(p, k);\n    Fp::set_mod(p);\n    vector<int> a(k);\n\
    \    read(a);\n    int n = 1;\n    for (auto &x : a)\n        n *= x;\n    vector<Fp>\
    \ f(n), g(n);\n    rep(i, 0, n) read(f[i].v);\n    rep(i, 0, n) read(g[i].v);\n\
    \n    auto ret = MultivariateCyclic(f, g, a);\n    rep(i, 0, n) print(ret[i].v);\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/multivariate_convolution_cyclic\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/dynamic.hpp\"\n#include \"Convolution/arbitrary.hpp\"\n#include \"FPS/arbitraryfps.hpp\"\
    \ntemplate <>\nvector<Fp> Poly<Fp>::mult(const vector<Fp> &a, const vector<Fp>\
    \ &b) const {\n    return ArbitraryMult<Fp>(a, b);\n}\n#include \"Convolution/multivariatecyclic.hpp\"\
    \n\nint main() {\n    int p, k;\n    read(p, k);\n    Fp::set_mod(p);\n    vector<int>\
    \ a(k);\n    read(a);\n    int n = 1;\n    for (auto &x : a)\n        n *= x;\n\
    \    vector<Fp> f(n), g(n);\n    rep(i, 0, n) read(f[i].v);\n    rep(i, 0, n)\
    \ read(g[i].v);\n\n    auto ret = MultivariateCyclic(f, g, a);\n    rep(i, 0,\
    \ n) print(ret[i].v);\n    return 0;\n}\n"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/dynamic.hpp
  - Math/fastdiv.hpp
  - Convolution/arbitrary.hpp
  - Convolution/ntt.hpp
  - Math/modint.hpp
  - FPS/arbitraryfps.hpp
  - Convolution/multivariatecyclic.hpp
  - Math/primitive.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  - FPS/multievalgeom.hpp
  isVerificationFile: true
  path: Verify/LC_multivariate_convolution_cyclic.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 03:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_multivariate_convolution_cyclic.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_multivariate_convolution_cyclic.test.cpp
- /verify/Verify/LC_multivariate_convolution_cyclic.test.cpp.html
title: Verify/LC_multivariate_convolution_cyclic.test.cpp
---
