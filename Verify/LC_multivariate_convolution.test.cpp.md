---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariate.hpp
    title: Multivariate Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multivariate_convolution
    links:
    - https://judge.yosupo.jp/problem/multivariate_convolution
  bundledCode: "#line 1 \"Verify/LC_multivariate_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/multivariate_convolution\"\r\n\r\n#line 1\
    \ \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v)\
    \ (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
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
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Math/modint.hpp\"\
    \n\r\ntemplate <int mod = 1000000007> struct fp {\r\n    int v;\r\n    static\
    \ constexpr int get_mod() { return mod; }\r\n    constexpr int inv() const {\r\
    \n        assert(v != 0);\r\n        int x = v, y = mod, u = 1, v = 0, t = 0,\
    \ tmp = 0;\r\n        while (y > 0) {\r\n            t = x / y;\r\n          \
    \  x -= t * y, u -= t * v;\r\n            tmp = x, x = y, y = tmp;\r\n       \
    \     tmp = u, u = v, v = tmp;\r\n        }\r\n        if (u < 0)\r\n        \
    \    u += mod;\r\n        return u;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x\
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
    \ * @brief Number Theoretic Transform\r\n */\n#line 3 \"Convolution/multivariate.hpp\"\
    \n\r\ntemplate<typename T,void (*ntt)(vector<T>&,bool)>vector<T> MultivariateConvolution\r\
    \n    (const vector<T>& f,const vector<T>& g,vector<int>& a){\r\n    int n=f.size(),k=a.size(),m=1<<__lg(4*n-1);\r\
    \n    if(k==0)return vector<T>({f[0]*g[0]});\r\n    \r\n    vector<int> chi(n);\r\
    \n    rep(x,0,n){\r\n        int t=x;\r\n        rep(i,0,k-1){\r\n           \
    \ t/=a[i];\r\n            chi[x]+=t;\r\n        }\r\n        chi[x]%=k;\r\n  \
    \  }\r\n\r\n    vector F(k,vector<T>(m)),G(k,vector<T>(m));\r\n    rep(i,0,n){\r\
    \n        F[chi[i]][i]=f[i];\r\n        G[chi[i]][i]=g[i];\r\n    }\r\n\r\n  \
    \  for(auto& v:F)ntt(v,0);\r\n    for(auto& v:G)ntt(v,0);\r\n    rep(x,0,m){\r\
    \n        vector<T> tmp(k);\r\n        rep(i,0,k)rep(j,0,k){\r\n            tmp[(i+j)%k]+=F[i][x]*G[j][x];\r\
    \n        }\r\n        rep(i,0,k)F[i][x]=tmp[i];\r\n    }\r\n    for(auto& v:F)ntt(v,1);\r\
    \n    vector<T> res(n);\r\n    rep(i,0,n)res[i]=F[chi[i]][i];\r\n    return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Multivariate Convolution\r\n */\n#line 7 \"Verify/LC_multivariate_convolution.test.cpp\"\
    \n\r\nusing Fp = fp<998244353>;\r\nNTT<Fp> ntt;\r\nvoid F(vector<Fp> &a, bool\
    \ f) { ntt.ntt(a, f); }\r\n\r\nint main() {\r\n    int k, n = 1;\r\n    cin >>\
    \ k;\r\n    vector<int> a(k);\r\n    rep(i, 0, k) {\r\n        cin >> a[i];\r\n\
    \        n *= a[i];\r\n    }\r\n    vector<Fp> f(n), g(n);\r\n    rep(i, 0, n)\
    \ cin >> f[i];\r\n    rep(i, 0, n) cin >> g[i];\r\n\r\n    auto res = MultivariateConvolution<Fp,\
    \ F>(f, g, a);\r\n    for (auto &x : res)\r\n        cout << x << '\\n';\r\n \
    \   return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"Convolution/ntt.hpp\"\r\n#include \"Convolution/multivariate.hpp\"\r\
    \n\r\nusing Fp = fp<998244353>;\r\nNTT<Fp> ntt;\r\nvoid F(vector<Fp> &a, bool\
    \ f) { ntt.ntt(a, f); }\r\n\r\nint main() {\r\n    int k, n = 1;\r\n    cin >>\
    \ k;\r\n    vector<int> a(k);\r\n    rep(i, 0, k) {\r\n        cin >> a[i];\r\n\
    \        n *= a[i];\r\n    }\r\n    vector<Fp> f(n), g(n);\r\n    rep(i, 0, n)\
    \ cin >> f[i];\r\n    rep(i, 0, n) cin >> g[i];\r\n\r\n    auto res = MultivariateConvolution<Fp,\
    \ F>(f, g, a);\r\n    for (auto &x : res)\r\n        cout << x << '\\n';\r\n \
    \   return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - Convolution/multivariate.hpp
  isVerificationFile: true
  path: Verify/LC_multivariate_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-01-14 02:40:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_multivariate_convolution.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_multivariate_convolution.test.cpp
- /verify/Verify/LC_multivariate_convolution.test.cpp.html
title: Verify/LC_multivariate_convolution.test.cpp
---
