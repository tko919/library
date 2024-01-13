---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/bigint.hpp
    title: Big Integer(Float)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_convolution_mod_1000000007.test.cpp
    title: Verify/LC_convolution_mod_1000000007.test.cpp
  - icon: ':x:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Arbitrary Mod Convolution
    links: []
  bundledCode: "#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate <typename T> struct\
    \ NTT {\r\n    static constexpr int rank2 = __builtin_ctzll(T::get_mod() - 1);\r\
    \n    std::array<T, rank2 + 1> root;  // root[i]^(2^i) == 1\r\n    std::array<T,\
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
    \n */\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate <int mod = 1000000007> struct\
    \ fp {\r\n    int v;\r\n    static constexpr int get_mod() { return mod; }\r\n\
    \    constexpr int inv() const {\r\n        assert(v != 0);\r\n        int x =\
    \ v, y = mod, u = 1, v = 0, t = 0, tmp = 0;\r\n        while (y > 0) {\r\n   \
    \         t = x / y;\r\n            x -= t * y, u -= t * v;\r\n            tmp\
    \ = x, x = y, y = tmp;\r\n            tmp = u, u = v, v = tmp;\r\n        }\r\n\
    \        return u;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod\
    \ : (mod - (-x) % mod) % mod) {}\r\n    fp operator-() const { return fp() - *this;\
    \ }\r\n    fp pow(ll t) {\r\n        assert(t >= 0);\r\n        fp res = 1, b\
    \ = *this;\r\n        while (t) {\r\n            if (t & 1)\r\n              \
    \  res *= b;\r\n            b *= b;\r\n            t >>= 1;\r\n        }\r\n \
    \       return res;\r\n    }\r\n    fp &operator+=(const fp &x) {\r\n        if\
    \ ((v += x.v) >= mod)\r\n            v -= mod;\r\n        return *this;\r\n  \
    \  }\r\n    fp &operator-=(const fp &x) {\r\n        if ((v += mod - x.v) >= mod)\r\
    \n            v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator*=(const\
    \ fp &x) {\r\n        v = ll(v) * x.v % mod;\r\n        return *this;\r\n    }\r\
    \n    fp &operator/=(const fp &x) {\r\n        v = ll(v) * x.inv() % mod;\r\n\
    \        return *this;\r\n    }\r\n    fp operator+(const fp &x) const { return\
    \ fp(*this) += x; }\r\n    fp operator-(const fp &x) const { return fp(*this)\
    \ -= x; }\r\n    fp operator*(const fp &x) const { return fp(*this) *= x; }\r\n\
    \    fp operator/(const fp &x) const { return fp(*this) /= x; }\r\n    bool operator==(const\
    \ fp &x) const { return v == x.v; }\r\n    bool operator!=(const fp &x) const\
    \ { return v != x.v; }\r\n    friend istream &operator>>(istream &is, fp &x) {\
    \ return is >> x.v; }\r\n    friend ostream &operator<<(ostream &os, const fp\
    \ &x) { return os << x.v; }\r\n};\r\n\r\ntemplate <typename T> T Inv(ll n) {\r\
    \n    static const int md = T::get_mod();\r\n    static vector<T> buf({0, 1});\r\
    \n    assert(n > 0);\r\n    n %= md;\r\n    while (SZ(buf) <= n) {\r\n       \
    \ int k = SZ(buf), q = (md + k - 1) / k;\r\n        buf.push_back(buf[k * q -\
    \ md] * q);\r\n    }\r\n    return buf[n];\r\n}\r\n\r\ntemplate <typename T> T\
    \ Fact(ll n, bool inv = 0) {\r\n    static const int md = T::get_mod();\r\n  \
    \  static vector<T> buf({1, 1}), ibuf({1, 1});\r\n    assert(n >= 0 and n < md);\r\
    \n    while (SZ(buf) <= n) {\r\n        buf.push_back(buf.back() * SZ(buf));\r\
    \n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\r\n    }\r\n    return\
    \ inv ? ibuf[n] : buf[n];\r\n}\r\n\r\ntemplate <typename T> T nPr(int n, int r,\
    \ bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\n        return 0;\r\n\
    \    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\r\n}\r\ntemplate <typename\
    \ T> T nCr(int n, int r, bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\
    \n        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n\
    \ - r, inv ^ 1);\r\n}\r\ntemplate <typename T> T nHr(int n, int r, bool inv =\
    \ 0) {\r\n    return nCr<T>(n + r - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\
    \n */\n#line 4 \"Convolution/arbitrary.hpp\"\n\r\nusing M1 = fp<1045430273>;\r\
    \nusing M2 = fp<1051721729>;\r\nusing M3 = fp<1053818881>;\r\nNTT<M1> N1;\r\n\
    NTT<M2> N2;\r\nNTT<M3> N3;\r\nconstexpr int r_12 = M2(M1::get_mod()).inv();\r\n\
    constexpr int r_13 = M3(M1::get_mod()).inv();\r\nconstexpr int r_23 = M3(M2::get_mod()).inv();\r\
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
    \ B);\r\n}\r\n\r\n/**\r\n * @brief Arbitrary Mod Convolution\r\n */\n"
  code: "#pragma once\r\n#include \"Convolution/ntt.hpp\"\r\n#include \"Math/modint.hpp\"\
    \r\n\r\nusing M1 = fp<1045430273>;\r\nusing M2 = fp<1051721729>;\r\nusing M3 =\
    \ fp<1053818881>;\r\nNTT<M1> N1;\r\nNTT<M2> N2;\r\nNTT<M3> N3;\r\nconstexpr int\
    \ r_12 = M2(M1::get_mod()).inv();\r\nconstexpr int r_13 = M3(M1::get_mod()).inv();\r\
    \nconstexpr int r_23 = M3(M2::get_mod()).inv();\r\nconstexpr int r_1323 = M3(ll(r_13)\
    \ * r_23).v;\r\nconstexpr ll w1 = M1::get_mod();\r\nconstexpr ll w2 = ll(w1) *\
    \ M2::get_mod();\r\ntemplate <typename T>\r\nvector<T> ArbitraryMult(const vector<int>\
    \ &a, const vector<int> &b) {\r\n    if (a.empty() or b.empty())\r\n        return\
    \ vector<T>();\r\n    int n = a.size() + b.size() - 1;\r\n    vector<T> res(n);\r\
    \n    if (min(a.size(), b.size()) <= 60) {\r\n        rep(i, 0, a.size()) rep(j,\
    \ 0, b.size()) res[i + j] += T(a[i]) * b[j];\r\n        return res;\r\n    }\r\
    \n    vector<int> vals[3];\r\n    vector<M1> a1(ALL(a)), b1(ALL(b)), c1 = N1.mult(a1,\
    \ b1);\r\n    vector<M2> a2(ALL(a)), b2(ALL(b)), c2 = N2.mult(a2, b2);\r\n   \
    \ vector<M3> a3(ALL(a)), b3(ALL(b)), c3 = N3.mult(a3, b3);\r\n    for (M1 x :\
    \ c1)\r\n        vals[0].push_back(x.v);\r\n    for (M2 x : c2)\r\n        vals[1].push_back(x.v);\r\
    \n    for (M3 x : c3)\r\n        vals[2].push_back(x.v);\r\n    rep(i, 0, n) {\r\
    \n        ll p = vals[0][i];\r\n        ll q = (vals[1][i] + M2::get_mod() - p)\
    \ * r_12 % M2::get_mod();\r\n        ll r = ((vals[2][i] + M3::get_mod() - p)\
    \ * r_1323 +\r\n                (M3::get_mod() - q) * r_23) %\r\n            \
    \   M3::get_mod();\r\n        res[i] = (T(r) * w2 + q * w1 + p);\r\n    }\r\n\
    \    return res;\r\n}\r\n\r\ntemplate <typename T>\r\nvector<T> ArbitraryMult(const\
    \ vector<T> &a, const vector<T> &b) {\r\n    vector<int> A, B;\r\n    for (auto\
    \ &x : a)\r\n        A.push_back(x.v);\r\n    for (auto &x : b)\r\n        B.push_back(x.v);\r\
    \n    return ArbitraryMult<T>(A, B);\r\n}\r\n\r\n/**\r\n * @brief Arbitrary Mod\
    \ Convolution\r\n */"
  dependsOn:
  - Convolution/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: false
  path: Convolution/arbitrary.hpp
  requiredBy:
  - Math/bigint.hpp
  timestamp: '2024-01-14 02:23:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_convolution_mod_1000000007.test.cpp
documentation_of: Convolution/arbitrary.hpp
layout: document
redirect_from:
- /library/Convolution/arbitrary.hpp
- /library/Convolution/arbitrary.hpp.html
title: Arbitrary Mod Convolution
---
