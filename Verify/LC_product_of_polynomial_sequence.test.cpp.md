---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: FPS/fps.hpp
    title: Formal Power Series (NTT-friendly mod)
  - icon: ':x:'
    path: FPS/prodofpolys.hpp
    title: Product of Polynomials
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
    PROBLEM: https://judge.yosupo.jp/problem/product_of_polynomial_sequence
    links:
    - https://judge.yosupo.jp/problem/product_of_polynomial_sequence
  bundledCode: "#line 1 \"Verify/LC_product_of_polynomial_sequence.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\n\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
    \n#define UB(v,x) int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long\
    \ long int;\r\nusing ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing\
    \ u128=__uint128_t;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\n\r\nclass FastIO {\r\n    static constexpr int L = 1\
    \ << 16;\r\n    char rdbuf[L];\r\n    int rdLeft = 0, rdRight = 0;\r\n    inline\
    \ void reload() {\r\n        int len = rdRight - rdLeft;\r\n        memmove(rdbuf,\
    \ rdbuf + rdLeft, len);\r\n        rdLeft = 0, rdRight = len;\r\n        rdRight\
    \ += fread(rdbuf + len, 1, L - len, stdin);\r\n    }\r\n    inline bool skip()\
    \ {\r\n        for (;;) {\r\n            while (rdLeft != rdRight and rdbuf[rdLeft]\
    \ <= ' ')\r\n                rdLeft++;\r\n            if (rdLeft == rdRight) {\r\
    \n                reload();\r\n                if (rdLeft == rdRight)\r\n    \
    \                return false;\r\n            } else\r\n                break;\r\
    \n        }\r\n        return true;\r\n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n     \
    \       return false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\
    \n        bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n       \
    \     neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n\
    \        while (rdbuf[rdLeft] >= '0' and rdLeft < rdRight) {\r\n            x\
    \ = x * 10 +\r\n                (neg ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++]\
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
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_product_of_polynomial_sequence.test.cpp\"\
    \n\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate <int mod = 1000000007> struct fp\
    \ {\r\n    int v;\r\n    static constexpr int get_mod() { return mod; }\r\n  \
    \  constexpr int inv() const {\r\n        int tmp, a = v, b = mod, x = 1, y =\
    \ 0;\r\n        while (b)\r\n            tmp = a / b, a -= tmp * b, swap(a, b),\
    \ x -= tmp * y, swap(x, y);\r\n        if (x < 0) {\r\n            x += mod;\r\
    \n        }\r\n        return x;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x\
    \ >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\r\n    fp operator-() const {\
    \ return fp() - *this; }\r\n    fp pow(ll t) {\r\n        assert(t >= 0);\r\n\
    \        fp res = 1, b = *this;\r\n        while (t) {\r\n            if (t &\
    \ 1)\r\n                res *= b;\r\n            b *= b;\r\n            t >>=\
    \ 1;\r\n        }\r\n        return res;\r\n    }\r\n    fp &operator+=(const\
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
    \n */\n#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate <typename T> struct NTT {\r\
    \n    static constexpr int rank2 = __builtin_ctzll(T::get_mod() - 1);\r\n    std::array<T,\
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
    \ * @brief Number Theoretic Transform\r\n */\n#line 2 \"FPS/fps.hpp\"\n\r\ntemplate\
    \ <typename T> struct Poly : vector<T> {\r\n    Poly(int n = 0) { this->assign(n,\
    \ T()); }\r\n    Poly(const initializer_list<T> f) : vector<T>::vector(f) {}\r\
    \n    Poly(const vector<T> &f) { this->assign(ALL(f)); }\r\n    T eval(const T\
    \ &x) {\r\n        T res;\r\n        for (int i = this->size() - 1; i >= 0; i--)\r\
    \n            res *= x, res += this->at(i);\r\n        return res;\r\n    }\r\n\
    \    Poly rev() const {\r\n        Poly res = *this;\r\n        reverse(ALL(res));\r\
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
    \n        NTT(res, 0);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i]\
    \ *= res[i];\r\n        else {\r\n            Poly<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            NTT(c, 0);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        NTT(res, 1);\r\n        res.resize(n);\r\n\
    \        return res;\r\n    }\r\n    Poly square() const { return Poly(mult(*this,\
    \ *this)); }\r\n    Poly operator-() const { return Poly() - *this; }\r\n    Poly\
    \ operator+(const Poly &g) const { return Poly(*this) += g; }\r\n    Poly operator+(const\
    \ T &g) const { return Poly(*this) += g; }\r\n    Poly operator-(const Poly &g)\
    \ const { return Poly(*this) -= g; }\r\n    Poly operator-(const T &g) const {\
    \ return Poly(*this) -= g; }\r\n    Poly operator*(const Poly &g) const { return\
    \ Poly(*this) *= g; }\r\n    Poly operator*(const T &g) const { return Poly(*this)\
    \ *= g; }\r\n    Poly operator/(const Poly &g) const { return Poly(*this) /= g;\
    \ }\r\n    Poly operator/(const T &g) const { return Poly(*this) /= g; }\r\n \
    \   Poly operator%(const Poly &g) const { return Poly(*this) %= g; }\r\n    pair<Poly,\
    \ Poly> divmod(const Poly &g) const {\r\n        Poly q = *this / g, r = *this\
    \ - g * q;\r\n        r.shrink();\r\n        return {q, r};\r\n    }\r\n    Poly\
    \ &operator+=(const Poly &g) {\r\n        if (g.size() > this->size())\r\n   \
    \         this->resize(g.size());\r\n        rep(i, 0, g.size()) { (*this)[i]\
    \ += g[i]; }\r\n        return *this;\r\n    }\r\n    Poly &operator+=(const T\
    \ &g) {\r\n        if (this->empty())\r\n            this->push_back(0);\r\n \
    \       (*this)[0] += g;\r\n        return *this;\r\n    }\r\n    Poly &operator-=(const\
    \ Poly &g) {\r\n        if (g.size() > this->size())\r\n            this->resize(g.size());\r\
    \n        rep(i, 0, g.size()) { (*this)[i] -= g[i]; }\r\n        return *this;\r\
    \n    }\r\n    Poly &operator-=(const T &g) {\r\n        if (this->empty())\r\n\
    \            this->push_back(0);\r\n        (*this)[0] -= g;\r\n        return\
    \ *this;\r\n    }\r\n    Poly &operator*=(const Poly &g) {\r\n        *this =\
    \ mult(*this, g);\r\n        return *this;\r\n    }\r\n    Poly &operator*=(const\
    \ T &g) {\r\n        rep(i, 0, this->size())(*this)[i] *= g;\r\n        return\
    \ *this;\r\n    }\r\n    Poly &operator/=(const Poly &g) {\r\n        if (g.size()\
    \ > this->size()) {\r\n            this->clear();\r\n            return *this;\r\
    \n        }\r\n        Poly g2 = g;\r\n        reverse(ALL(*this));\r\n      \
    \  reverse(ALL(g2));\r\n        int n = this->size() - g2.size() + 1;\r\n    \
    \    this->resize(n);\r\n        g2.resize(n);\r\n        *this *= g2.inv();\r\
    \n        this->resize(n);\r\n        reverse(ALL(*this));\r\n        shrink();\r\
    \n        return *this;\r\n    }\r\n    Poly &operator/=(const T &g) {\r\n   \
    \     rep(i, 0, this->size())(*this)[i] /= g;\r\n        return *this;\r\n   \
    \ }\r\n    Poly &operator%=(const Poly &g) {\r\n        *this -= *this / g * g;\r\
    \n        shrink();\r\n        return *this;\r\n    }\r\n    Poly diff() const\
    \ {\r\n        Poly res(this->size() - 1);\r\n        rep(i, 0, res.size()) res[i]\
    \ = (*this)[i + 1] * (i + 1);\r\n        return res;\r\n    }\r\n    Poly inte()\
    \ const {\r\n        Poly res(this->size() + 1);\r\n        for (int i = res.size()\
    \ - 1; i; i--)\r\n            res[i] = (*this)[i - 1] / i;\r\n        return res;\r\
    \n    }\r\n    Poly log() const {\r\n        assert(this->front() == 1);\r\n \
    \       const int n = this->size();\r\n        Poly res = diff() * inv();\r\n\
    \        res = res.inte();\r\n        res.resize(n);\r\n        return res;\r\n\
    \    }\r\n    Poly shift(const int &c) const {\r\n        const int n = this->size();\r\
    \n        Poly res = *this, g(n);\r\n        g[0] = 1;\r\n        rep(i, 1, n)\
    \ g[i] = g[i - 1] * c / i;\r\n        vector<T> fact(n, 1);\r\n        rep(i,\
    \ 0, n) {\r\n            if (i)\r\n                fact[i] = fact[i - 1] * i;\r\
    \n            res[i] *= fact[i];\r\n        }\r\n        res = res.rev();\r\n\
    \        res *= g;\r\n        res.resize(n);\r\n        res = res.rev();\r\n \
    \       rep(i, 0, n) res[i] /= fact[i];\r\n        return res;\r\n    }\r\n  \
    \  Poly inv() const {\r\n        const int n = this->size();\r\n        Poly res(1);\r\
    \n        res.front() = T(1) / this->front();\r\n        for (int k = 1; k < n;\
    \ k <<= 1) {\r\n            Poly f(k * 2), g(k * 2);\r\n            rep(i, 0,\
    \ min(n, k * 2)) f[i] = (*this)[i];\r\n            rep(i, 0, k) g[i] = res[i];\r\
    \n            NTT(f, 0);\r\n            NTT(g, 0);\r\n            rep(i, 0, k\
    \ * 2) f[i] *= g[i];\r\n            NTT(f, 1);\r\n            rep(i, 0, k) {\r\
    \n                f[i] = 0;\r\n                f[i + k] = -f[i + k];\r\n     \
    \       }\r\n            NTT(f, 0);\r\n            rep(i, 0, k * 2) f[i] *= g[i];\r\
    \n            NTT(f, 1);\r\n            rep(i, 0, k) f[i] = res[i];\r\n      \
    \      swap(res, f);\r\n        }\r\n        res.resize(n);\r\n        return\
    \ res;\r\n    }\r\n    Poly exp() const {\r\n        const int n = this->size();\r\
    \n        if (n == 1)\r\n            return Poly({T(1)});\r\n        Poly b(2),\
    \ c(1), z1, z2(2);\r\n        b[0] = c[0] = z2[0] = z2[1] = 1;\r\n        b[1]\
    \ = (*this)[1];\r\n        for (int k = 2; k < n; k <<= 1) {\r\n            Poly\
    \ y = b;\r\n            y.resize(k * 2);\r\n            NTT(y, 0);\r\n       \
    \     z1 = z2;\r\n            Poly z(k);\r\n            rep(i, 0, k) z[i] = y[i]\
    \ * z1[i];\r\n            NTT(z, 1);\r\n            rep(i, 0, k >> 1) z[i] = 0;\r\
    \n            NTT(z, 0);\r\n            rep(i, 0, k) z[i] *= -z1[i];\r\n     \
    \       NTT(z, 1);\r\n            c.insert(c.end(), z.begin() + (k >> 1), z.end());\r\
    \n            z2 = c;\r\n            z2.resize(k * 2);\r\n            NTT(z2,\
    \ 0);\r\n            Poly x = *this;\r\n            x.resize(k);\r\n         \
    \   x = x.diff();\r\n            x.resize(k);\r\n            NTT(x, 0);\r\n  \
    \          rep(i, 0, k) x[i] *= y[i];\r\n            NTT(x, 1);\r\n          \
    \  Poly bb = b.diff();\r\n            rep(i, 0, k - 1) x[i] -= bb[i];\r\n    \
    \        x.resize(k * 2);\r\n            rep(i, 0, k - 1) {\r\n              \
    \  x[k + i] = x[i];\r\n                x[i] = 0;\r\n            }\r\n        \
    \    NTT(x, 0);\r\n            rep(i, 0, k * 2) x[i] *= z2[i];\r\n           \
    \ NTT(x, 1);\r\n            x.pop_back();\r\n            x = x.inte();\r\n   \
    \         rep(i, k, min(n, k * 2)) x[i] += (*this)[i];\r\n            rep(i, 0,\
    \ k) x[i] = 0;\r\n            NTT(x, 0);\r\n            rep(i, 0, k * 2) x[i]\
    \ *= y[i];\r\n            NTT(x, 1);\r\n            b.insert(b.end(), x.begin()\
    \ + k, x.end());\r\n        }\r\n        b.resize(n);\r\n        return b;\r\n\
    \    }\r\n    Poly pow(ll t) {\r\n        if (t == 0) {\r\n            Poly res(this->size());\r\
    \n            res[0] = 1;\r\n            return res;\r\n        }\r\n        int\
    \ n = this->size(), k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n  \
    \          k++;\r\n        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\
    \n            return res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n   \
    \     T c = (*this)[k], ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i\
    \ + k] * ic;\r\n        g = g.log();\r\n        for (auto &x : g)\r\n        \
    \    x *= t;\r\n        g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i,\
    \ 0, n) res[i + t * k] = g[i] * c;\r\n        return res;\r\n    }\r\n    void\
    \ NTT(vector<T> &a, bool inv) const;\r\n};\r\n\r\n/**\r\n * @brief Formal Power\
    \ Series (NTT-friendly mod)\r\n */\n#line 9 \"Verify/LC_product_of_polynomial_sequence.test.cpp\"\
    \nusing Fp = fp<998244353>;\nNTT<Fp> ntt;\ntemplate <> void Poly<Fp>::NTT(vector<Fp>\
    \ &v, bool inv) const {\n    return ntt.ntt(v, inv);\n}\n\n#line 2 \"FPS/prodofpolys.hpp\"\
    \n\ntemplate<typename T>Poly<T> ProdOfPolys(vector<Poly<T>>& fs){\n    if(fs.empty())return\
    \ Poly<T>({T(1)});\n    sort(ALL(fs),[&](Poly<T>& a,Poly<T>& b){return a.size()<b.size();});\n\
    \    deque<Poly<T>> deq;\n    for(auto& f:fs)deq.push_back(f);\n    while(deq.size()>1){\n\
    \        deq.push_back(deq[0]*deq[1]);\n        deq.pop_front();\n        deq.pop_front();\n\
    \    }\n    return deq[0];\n}\n\n/**\n * @brief Product of Polynomials\n*/\n#line\
    \ 16 \"Verify/LC_product_of_polynomial_sequence.test.cpp\"\n\nFastIO io;\nint\
    \ main() {\n    int n;\n    io.read(n);\n    vector<Poly<Fp>> fs(n);\n    rep(i,\
    \ 0, n) {\n        int m;\n        io.read(m);\n        fs[i] = Poly<Fp>(m + 1);\n\
    \        rep(j, 0, m + 1) io.read(fs[i][j].v);\n    }\n\n    auto ret = ProdOfPolys(fs);\n\
    \    rep(i, 0, ret.size()) io.write(ret[i].v);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/modint.hpp\"\n#include \"Convolution/ntt.hpp\"\n#include \"FPS/fps.hpp\"\
    \nusing Fp = fp<998244353>;\nNTT<Fp> ntt;\ntemplate <> void Poly<Fp>::NTT(vector<Fp>\
    \ &v, bool inv) const {\n    return ntt.ntt(v, inv);\n}\n\n#include \"FPS/prodofpolys.hpp\"\
    \n\nFastIO io;\nint main() {\n    int n;\n    io.read(n);\n    vector<Poly<Fp>>\
    \ fs(n);\n    rep(i, 0, n) {\n        int m;\n        io.read(m);\n        fs[i]\
    \ = Poly<Fp>(m + 1);\n        rep(j, 0, m + 1) io.read(fs[i][j].v);\n    }\n\n\
    \    auto ret = ProdOfPolys(fs);\n    rep(i, 0, ret.size()) io.write(ret[i].v);\n\
    \    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - FPS/fps.hpp
  - FPS/prodofpolys.hpp
  isVerificationFile: true
  path: Verify/LC_product_of_polynomial_sequence.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 05:13:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_product_of_polynomial_sequence.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_product_of_polynomial_sequence.test.cpp
- /verify/Verify/LC_product_of_polynomial_sequence.test.cpp.html
title: Verify/LC_product_of_polynomial_sequence.test.cpp
---
