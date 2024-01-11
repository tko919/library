---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/divisor.hpp
    title: Divisor Multiple Transform
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"Verify/LC_gcd_convolution.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/gcd_convolution\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\n#define\
    \ UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define SZ(v)\
    \ (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\n#define UB(v,x)\
    \ int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long long int;\r\n\
    using ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing u128=__uint128_t;\r\
    \nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate<typename\
    \ T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename\
    \ T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}\r\ntemplate<typename\
    \ T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\
    \ntemplate<typename T,typename U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\
    \ntemplate<typename T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\
    \ntemplate<typename T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n\
    #line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\n\r\nclass FastIO {\r\n\
    \    static constexpr int L = 1 << 16;\r\n    char rdbuf[L];\r\n    int rdLeft\
    \ = 0, rdRight = 0;\r\n    inline void reload() {\r\n        int len = rdRight\
    \ - rdLeft;\r\n        memmove(rdbuf, rdbuf + rdLeft, len);\r\n        rdLeft\
    \ = 0, rdRight = len;\r\n        rdRight += fread(rdbuf + len, 1, L - len, stdin);\r\
    \n    }\r\n    inline bool skip() {\r\n        for (;;) {\r\n            while\
    \ (rdLeft != rdRight and rdbuf[rdLeft] <= ' ')\r\n                rdLeft++;\r\n\
    \            if (rdLeft == rdRight) {\r\n                reload();\r\n       \
    \         if (rdLeft == rdRight)\r\n                    return false;\r\n    \
    \        } else\r\n                break;\r\n        }\r\n        return true;\r\
    \n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n            return\
    \ false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\n \
    \       bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n         \
    \   neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n  \
    \      while (rdbuf[rdLeft] >= '0' and rdLeft < rdRight) {\r\n            x =\
    \ x * 10 +\r\n                (neg ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++]\
    \ ^ 48));\r\n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__int128_t\
    \ &x) {\r\n        if (!skip())\r\n            return false;\r\n        if (rdLeft\
    \ + 40 >= rdRight)\r\n            reload();\r\n        bool neg = false;\r\n \
    \       if (rdbuf[rdLeft] == '-') {\r\n            neg = true;\r\n           \
    \ rdLeft++;\r\n        }\r\n        x = 0;\r\n        while (rdbuf[rdLeft] >=\
    \ '0' and rdLeft < rdRight) {\r\n            x = x * 10 +\r\n                (neg\
    \ ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++] ^ 48));\r\n        }\r\n      \
    \  return true;\r\n    }\r\n    inline bool _read(__uint128_t &x) {\r\n      \
    \  if (!skip())\r\n            return false;\r\n        if (rdLeft + 40 >= rdRight)\r\
    \n            reload();\r\n        x = 0;\r\n        while (rdbuf[rdLeft] >= '0'\
    \ and rdLeft < rdRight) {\r\n            x = x * 10 + (rdbuf[rdLeft++] ^ 48);\r\
    \n        }\r\n        return true;\r\n    }\r\n    template <typename T, enable_if_t<is_floating_point<T>::value,\
    \ int> = 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n     \
    \       return false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\
    \n        bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n       \
    \     neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n\
    \        while (rdbuf[rdLeft] >= '0' and rdbuf[rdLeft] <= '9' and\r\n        \
    \       rdLeft < rdRight) {\r\n            x = x * 10 + (rdbuf[rdLeft++] ^ 48);\r\
    \n        }\r\n        if (rdbuf[rdLeft] != '.')\r\n            return true;\r\
    \n        rdLeft++;\r\n        T base = .1;\r\n        while (rdbuf[rdLeft] >=\
    \ '0' and rdbuf[rdLeft] <= '9' and\r\n               rdLeft < rdRight) {\r\n \
    \           x += base * (rdbuf[rdLeft++] ^ 48);\r\n            base *= .1;\r\n\
    \        }\r\n        if (neg)\r\n            x = -x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char &x) {\r\n        if (!skip())\r\n      \
    \      return false;\r\n        if (rdLeft + 1 >= rdRight)\r\n            reload();\r\
    \n        x = rdbuf[rdLeft++];\r\n        return true;\r\n    }\r\n    inline\
    \ bool _read(string &x) {\r\n        if (!skip())\r\n            return false;\r\
    \n        for (;;) {\r\n            int pos = rdLeft;\r\n            while (pos\
    \ < rdRight and rdbuf[pos] > ' ')\r\n                pos++;\r\n            x.append(rdbuf\
    \ + rdLeft, pos - rdLeft);\r\n            if (rdLeft == pos)\r\n             \
    \   break;\r\n            rdLeft = pos;\r\n            if (rdLeft == rdRight)\r\
    \n                reload();\r\n            else\r\n                break;\r\n\
    \        }\r\n        return true;\r\n    }\r\n    template <typename T> inline\
    \ bool _read(vector<T> &v) {\r\n        for (auto &x : v) {\r\n            if\
    \ (!_read(x))\r\n                return false;\r\n        }\r\n        return\
    \ true;\r\n    }\r\n\r\n    char wtbuf[L], tmp[50];\r\n    int wtRight = 0;\r\n\
    \    inline void _write(const char &x) {\r\n        if (wtRight > L - 32)\r\n\
    \            flush();\r\n        wtbuf[wtRight++] = x;\r\n    }\r\n    inline\
    \ void _write(const string &x) {\r\n        for (auto &c : x)\r\n            _write(c);\r\
    \n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\r\n    inline void _write(T x) {\r\n        if (wtRight > L - 32)\r\n   \
    \         flush();\r\n        if (x == 0) {\r\n            _write('0');\r\n  \
    \          return;\r\n        } else if (x < 0) {\r\n            _write('-');\r\
    \n            if (__builtin_expect(x == std::numeric_limits<T>::min(), 0)) {\r\
    \n                switch (sizeof(x)) {\r\n                case 2:\r\n        \
    \            _write(\"32768\");\r\n                    return;\r\n           \
    \     case 4:\r\n                    _write(\"2147483648\");\r\n             \
    \       return;\r\n                case 8:\r\n                    _write(\"9223372036854775808\"\
    );\r\n                    return;\r\n                }\r\n            }\r\n  \
    \          x = -x;\r\n        }\r\n        int pos = 0;\r\n        while (x !=\
    \ 0) {\r\n            tmp[pos++] = char((x % 10) | 48);\r\n            x /= 10;\r\
    \n        }\r\n        rep(i, 0, pos) wtbuf[wtRight + i] = tmp[pos - 1 - i];\r\
    \n        wtRight += pos;\r\n    }\r\n    inline void _write(__int128_t x) {\r\
    \n        if (wtRight > L - 40)\r\n            flush();\r\n        if (x == 0)\
    \ {\r\n            _write('0');\r\n            return;\r\n        } else if (x\
    \ < 0) {\r\n            _write('-');\r\n            x = -x;\r\n        }\r\n \
    \       int pos = 0;\r\n        while (x != 0) {\r\n            tmp[pos++] = char((x\
    \ % 10) | 48);\r\n            x /= 10;\r\n        }\r\n        rep(i, 0, pos)\
    \ wtbuf[wtRight + i] = tmp[pos - 1 - i];\r\n        wtRight += pos;\r\n    }\r\
    \n    inline void _write(__uint128_t x) {\r\n        if (wtRight > L - 40)\r\n\
    \            flush();\r\n        if (x == 0) {\r\n            _write('0');\r\n\
    \            return;\r\n        }\r\n        int pos = 0;\r\n        while (x\
    \ != 0) {\r\n            tmp[pos++] = char((x % 10) | 48);\r\n            x /=\
    \ 10;\r\n        }\r\n        rep(i, 0, pos) wtbuf[wtRight + i] = tmp[pos - 1\
    \ - i];\r\n        wtRight += pos;\r\n    }\r\n    inline void _write(double x)\
    \ {\r\n        ostringstream oss;\r\n        oss << fixed << setprecision(15)\
    \ << double(x);\r\n        string s = oss.str();\r\n        _write(s);\r\n   \
    \ }\r\n    template <typename T> inline void _write(const vector<T> &v) {\r\n\
    \        rep(i, 0, v.size()) {\r\n            if (i)\r\n                _write('\
    \ ');\r\n            _write(v[i]);\r\n        }\r\n    }\r\n\r\n  public:\r\n\
    \    FastIO() {}\r\n    ~FastIO() { flush(); }\r\n    inline void read() {}\r\n\
    \    template <typename Head, typename... Tail>\r\n    inline void read(Head &head,\
    \ Tail &...tail) {\r\n        assert(_read(head));\r\n        read(tail...);\r\
    \n    }\r\n    template <bool ln = true, bool space = false> inline void write()\
    \ {\r\n        if (ln)\r\n            _write('\\n');\r\n    }\r\n    template\
    \ <bool ln = true, bool space = false, typename Head,\r\n              typename...\
    \ Tail>\r\n    inline void write(const Head &head, const Tail &...tail) {\r\n\
    \        if (space)\r\n            _write(' ');\r\n        _write(head);\r\n \
    \       write<ln, true>(tail...);\r\n    }\r\n    inline void flush() {\r\n  \
    \      fwrite(wtbuf, 1, wtRight, stdout);\r\n        wtRight = 0;\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate\
    \ <int mod = 1000000007> struct fp {\r\n    int v;\r\n    static constexpr int\
    \ get_mod() { return mod; }\r\n    int inv() const {\r\n        int tmp, a = v,\
    \ b = mod, x = 1, y = 0;\r\n        while (b)\r\n            tmp = a / b, a -=\
    \ tmp * b, swap(a, b), x -= tmp * y, swap(x, y);\r\n        if (x < 0) {\r\n \
    \           x += mod;\r\n        }\r\n        return x;\r\n    }\r\n    fp(ll\
    \ x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\r\n    fp operator-()\
    \ const { return fp() - *this; }\r\n    fp pow(ll t) {\r\n        assert(t >=\
    \ 0);\r\n        fp res = 1, b = *this;\r\n        while (t) {\r\n           \
    \ if (t & 1)\r\n                res *= b;\r\n            b *= b;\r\n         \
    \   t >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    fp &operator+=(const\
    \ fp &x) {\r\n        if ((v += x.v) >= mod)\r\n            v -= mod;\r\n    \
    \    return *this;\r\n    }\r\n    fp &operator-=(const fp &x) {\r\n        if\
    \ ((v += mod - x.v) >= mod)\r\n            v -= mod;\r\n        return *this;\r\
    \n    }\r\n    fp &operator*=(const fp &x) {\r\n        v = ll(v) * x.v % mod;\r\
    \n        return *this;\r\n    }\r\n    fp &operator/=(const fp &x) {\r\n    \
    \    v = ll(v) * x.inv() % mod;\r\n        return *this;\r\n    }\r\n    fp operator+(const\
    \ fp &x) const { return fp(*this) += x; }\r\n    fp operator-(const fp &x) const\
    \ { return fp(*this) -= x; }\r\n    fp operator*(const fp &x) const { return fp(*this)\
    \ *= x; }\r\n    fp operator/(const fp &x) const { return fp(*this) /= x; }\r\n\
    \    bool operator==(const fp &x) const { return v == x.v; }\r\n    bool operator!=(const\
    \ fp &x) const { return v != x.v; }\r\n    friend istream &operator>>(istream\
    \ &is, fp &x) { return is >> x.v; }\r\n    friend ostream &operator<<(ostream\
    \ &os, const fp &x) { return os << x.v; }\r\n};\r\n\r\ntemplate <typename T> T\
    \ Inv(ll n) {\r\n    static const int md = T::get_mod();\r\n    static vector<T>\
    \ buf({0, 1});\r\n    assert(n > 0);\r\n    n %= md;\r\n    while (SZ(buf) <=\
    \ n) {\r\n        int k = SZ(buf), q = (md + k - 1) / k;\r\n        buf.push_back(buf[k\
    \ * q - md] * q);\r\n    }\r\n    return buf[n];\r\n}\r\n\r\ntemplate <typename\
    \ T> T Fact(ll n, bool inv = 0) {\r\n    static const int md = T::get_mod();\r\
    \n    static vector<T> buf({1, 1}), ibuf({1, 1});\r\n    assert(n >= 0 and n <\
    \ md);\r\n    while (SZ(buf) <= n) {\r\n        buf.push_back(buf.back() * SZ(buf));\r\
    \n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\r\n    }\r\n    return\
    \ inv ? ibuf[n] : buf[n];\r\n}\r\n\r\ntemplate <typename T> T nPr(int n, int r,\
    \ bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\n        return 0;\r\n\
    \    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\r\n}\r\ntemplate <typename\
    \ T> T nCr(int n, int r, bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\
    \n        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n\
    \ - r, inv ^ 1);\r\n}\r\ntemplate <typename T> T nHr(int n, int r, bool inv =\
    \ 0) {\r\n    return nCr<T>(n + r - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\
    \n */\n#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=50101010>vector<int> sieve(int\
    \ N){\r\n    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int z=1;z<=5;z+=4){\r\
    \n        for(int y=z;y<=sq;y+=6){\r\n            for(int x=1;x<=sq and (n=4*x*x+y*y)<=N;++x){\r\
    \n                isp[n].flip();\r\n            }\r\n            for(int x=y+1;x<=sq\
    \ and (n=3*x*x-y*y)<=N;x+=2){\r\n                isp[n].flip();\r\n          \
    \  }\r\n        }\r\n    }\r\n    for(int z=2;z<=4;z+=2){\r\n        for(int y=z;y<=sq;y+=6){\r\
    \n            for (int x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){\r\n             \
    \   isp[n].flip();\r\n            }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\
    \n                isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n  \
    \  for(int y=3;y<=sq;y+=6){\r\n        for(int z=1;z<=2;++z){\r\n            for(int\
    \ x=z;x<=sq and (n=4*x*x+y*y)<=N;x+=3){\r\n                isp[n].flip();\r\n\
    \            }\r\n        }\r\n    }\r\n    for(int n=5;n<=sq;++n)if(isp[n]){\r\
    \n        for(int k=n*n;k<=N;k+=n*n){\r\n            isp[k]=false;\r\n       \
    \ }\r\n    }\r\n    isp[2]=isp[3]=true;\r\n\r\n    vector<int> ret;\r\n    for(int\
    \ i=2;i<=N;i++)if(isp[i]){\r\n        ret.push_back(i);\r\n    }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Convolution/divisor.hpp\"\
    \n\r\nnamespace DivisorTransform{\r\n    int n;\r\n    vector<int> ps;\r\n   \
    \ template<typename T>void zeta(vector<T>& a){\r\n        int N=a.size()-1;\r\n\
    \        if(n<N){\r\n            ps=sieve(N);\r\n            n=N;\r\n        }\r\
    \n        for(auto& p:ps){\r\n            for(int k=1;k*p<=N;k++)a[k*p]+=a[k];\r\
    \n        }\r\n    }\r\n    template<typename T>void mobius(vector<T>& a){\r\n\
    \        int N=a.size()-1;\r\n        if(n<N){\r\n            ps=sieve(N);\r\n\
    \            n=N;\r\n        }\r\n        for(auto& p:ps){\r\n            for(int\
    \ k=N/p;k;k--)a[k*p]-=a[k];\r\n        }\r\n    }\r\n};\r\n\r\nnamespace MultipleTransform{\r\
    \n    int n;\r\n    vector<int> ps;\r\n    template<typename T>void zeta(vector<T>&\
    \ a){\r\n        int N=a.size()-1;\r\n        if(n<N){\r\n            ps=sieve(N);\r\
    \n            n=N;\r\n        }\r\n        for(auto& p:ps){\r\n            for(int\
    \ k=N/p;k;k--)a[k]+=a[k*p];\r\n        }\r\n    }\r\n    template<typename T>void\
    \ mobius(vector<T>& a){\r\n        int N=a.size()-1;\r\n        if(n<N){\r\n \
    \           ps=sieve(N);\r\n            n=N;\r\n        }\r\n        for(auto&\
    \ p:ps){\r\n            for(int k=1;k*p<=N;k++)a[k]-=a[k*p];\r\n        }\r\n\
    \    }\r\n};\r\n\r\n/**\r\n * @brief Divisor Multiple Transform\r\n * @docs docs/divisor.md\r\
    \n */\n#line 7 \"Verify/LC_gcd_convolution.test.cpp\"\n\r\nusing Fp=fp<998244353>;\r\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n;\r\n    io.read(n);\r\n    vector<Fp>\
    \ a(n+1),b(n+1);\r\n    rep(i,1,n+1)io.read(a[i].v);\r\n    rep(i,1,n+1)io.read(b[i].v);\r\
    \n\r\n    MultipleTransform::zeta(a);\r\n    MultipleTransform::zeta(b);\r\n \
    \   rep(i,1,n+1)a[i]*=b[i];\r\n    MultipleTransform::mobius(a);\r\n    rep(i,1,n+1)io.write(a[i].v);\r\
    \n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n#include\
    \ \"Math/modint.hpp\"\r\n#include \"Convolution/divisor.hpp\"\r\n\r\nusing Fp=fp<998244353>;\r\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n;\r\n    io.read(n);\r\n    vector<Fp>\
    \ a(n+1),b(n+1);\r\n    rep(i,1,n+1)io.read(a[i].v);\r\n    rep(i,1,n+1)io.read(b[i].v);\r\
    \n\r\n    MultipleTransform::zeta(a);\r\n    MultipleTransform::zeta(b);\r\n \
    \   rep(i,1,n+1)a[i]*=b[i];\r\n    MultipleTransform::mobius(a);\r\n    rep(i,1,n+1)io.write(a[i].v);\r\
    \n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Convolution/divisor.hpp
  - Math/sieve.hpp
  isVerificationFile: true
  path: Verify/LC_gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:46:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_gcd_convolution.test.cpp
- /verify/Verify/LC_gcd_convolution.test.cpp.html
title: Verify/LC_gcd_convolution.test.cpp
---
