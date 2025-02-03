---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Big Integer(Float)
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
    \n */\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate <unsigned mod = 1000000007> struct\
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
    \n * @brief Modint\r\n */\n#line 4 \"Convolution/arbitrary.hpp\"\n\r\nusing M1\
    \ = fp<1045430273>;\r\nusing M2 = fp<1051721729>;\r\nusing M3 = fp<1053818881>;\r\
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
    \ B);\r\n}\r\n\r\n/**\r\n * @brief Arbitrary Mod Convolution\r\n */\n#line 3 \"\
    Math/bigint.hpp\"\n\r\ntemplate <int D> struct bigint {\r\n    using u128 = __uint128_t;\r\
    \n    static const int B = pow(10, D);\r\n    int sign = 0;\r\n    vector<int>\
    \ v;\r\n    static int get_D() { return D; }\r\n    static int get_B() { return\
    \ B; }\r\n    bigint() {}\r\n    bigint(const vector<int> &_v, bool _s = false)\
    \ : sign(_s), v(_v) {}\r\n    bigint(ll x) {\r\n        if (x < 0)\r\n       \
    \     x *= -1, sign = 1;\r\n        while (x) {\r\n            v.push_back(x %\
    \ B);\r\n            x /= B;\r\n        }\r\n    }\r\n    bigint(string s) {\r\
    \n        if (s[0] == '-')\r\n            s.erase(s.begin()), sign = 1;\r\n  \
    \      int add = 0, cnt = 0, base = 1;\r\n        while (s.size()) {\r\n     \
    \       if (cnt == D) {\r\n                v.push_back(add);\r\n             \
    \   cnt = 0;\r\n                add = 0;\r\n                base = 1;\r\n    \
    \        }\r\n            add = (s.back() - '0') * base + add;\r\n           \
    \ cnt++;\r\n            base *= 10;\r\n            s.pop_back();\r\n        }\r\
    \n        if (add)\r\n            v.push_back(add);\r\n    }\r\n    bigint operator-()\
    \ const {\r\n        bigint res = *this;\r\n        res.sign ^= 1;\r\n       \
    \ return res;\r\n    }\r\n    bigint abs() const {\r\n        bigint res = *this;\r\
    \n        res.sign = 0;\r\n        return res;\r\n    }\r\n    int &operator[](const\
    \ int i) { return v[i]; }\r\n    int size() const { return v.size(); }\r\n   \
    \ void norm() {\r\n        rep(i, 0, v.size() - 1) {\r\n            if (v[i] >=\
    \ 0) {\r\n                v[i + 1] += v[i] / B;\r\n                v[i] %= B;\r\
    \n            } else {\r\n                int c = (-v[i] + B - 1) / B;\r\n   \
    \             v[i] += c * B;\r\n                v[i + 1] -= c;\r\n           \
    \ }\r\n        }\r\n        while (!v.empty() and v.back() >= B) {\r\n       \
    \     int c = v.back() / B;\r\n            v.back() %= B;\r\n            v.push_back(c);\r\
    \n        }\r\n        while (!v.empty() and v.back() == 0)\r\n            v.pop_back();\r\
    \n    }\r\n    string to_str() const {\r\n        string res;\r\n        if (v.empty())\r\
    \n            return \"0\";\r\n        if (sign)\r\n            res += '-';\r\n\
    \        res += to_string(v.back());\r\n        for (int i = v.size() - 2; i >=\
    \ 0; i--) {\r\n            string add;\r\n            int w = v[i];\r\n      \
    \      rep(_, 0, D) {\r\n                add += ('0' + (w % 10));\r\n        \
    \        w /= 10;\r\n            }\r\n            reverse(ALL(add));\r\n     \
    \       res += add;\r\n        }\r\n        return res;\r\n    }\r\n    friend\
    \ istream &operator>>(istream &is, bigint<D> &x) {\r\n        string tmp;\r\n\
    \        is >> tmp;\r\n        x = bigint(tmp);\r\n        return is;\r\n    }\r\
    \n    friend ostream &operator<<(ostream &os, bigint<D> x) {\r\n        os <<\
    \ x.to_str();\r\n        return os;\r\n    }\r\n    bigint &operator<<=(const\
    \ int &x) {\r\n        if (!v.empty()) {\r\n            vector<int> add(x, 0);\r\
    \n            v.insert(v.begin(), ALL(add));\r\n        }\r\n        return *this;\r\
    \n    }\r\n    bigint &operator>>=(const int &x) {\r\n        v = vector<int>(v.begin()\
    \ + min(x, (int)v.size()), v.end());\r\n        return *this;\r\n    }\r\n   \
    \ bigint &operator+=(const bigint &x) {\r\n        if (sign != x.sign) {\r\n \
    \           *this -= (-x);\r\n            return *this;\r\n        }\r\n     \
    \   if ((int)v.size() < (int)x.size())\r\n            v.resize(x.size(), 0);\r\
    \n        rep(i, 0, x.size()) { v[i] += x.v[i]; }\r\n        norm();\r\n     \
    \   return *this;\r\n    }\r\n    bigint &operator-=(const bigint &x) {\r\n  \
    \      if (sign != x.sign) {\r\n            *this += (-x);\r\n            return\
    \ *this;\r\n        }\r\n        if (abs() < x.abs()) {\r\n            *this =\
    \ x - (*this);\r\n            sign ^= 1;\r\n            return *this;\r\n    \
    \    }\r\n        rep(i, 0, x.size()) { v[i] -= x.v[i]; }\r\n        norm();\r\
    \n        return *this;\r\n    }\r\n    bigint &operator*=(const bigint &x) {\r\
    \n        sign ^= x.sign;\r\n        auto v1 = ArbitraryMult<u128>(v, x.v);\r\n\
    \        u128 add = 0;\r\n        v.clear();\r\n        v.reserve(v1.size() +\
    \ 3);\r\n        for (int i = 0;; i++) {\r\n            if (i >= int(v1.size())\
    \ and add == 0)\r\n                break;\r\n            if (i < int(v1.size()))\r\
    \n                add += v1[i];\r\n            v.push_back(add % B);\r\n     \
    \       add /= B;\r\n        }\r\n        norm();\r\n        return *this;\r\n\
    \    }\r\n    bigint div_naive(const bigint &a, const bigint &b) {\r\n       \
    \ if (SZ(b) == 1)\r\n            return a.div(b.v.back());\r\n        if (a <\
    \ b)\r\n            return bigint();\r\n        int norm = B / (b.v.back() + 1);\r\
    \n        bigint x = a.mul(norm), y = b.mul(norm);\r\n        int yb = y.v.back();\r\
    \n        bigint quo, rem;\r\n        quo.v.resize(x.size() - y.size() + 1);\r\
    \n        rem.v = {x.v.end() - y.size(), x.v.end()};\r\n        for (int i = x.size()\
    \ - y.size(); i >= 0; i--) {\r\n            if (rem.size() == y.size()) {\r\n\
    \                if (rem >= y) {\r\n                    quo[i] = 1;\r\n      \
    \              rem -= y;\r\n                }\r\n            } else if (rem.size()\
    \ > y.size()) {\r\n                ll rb = ll(rem.v.back()) * B + rem[rem.size()\
    \ - 2];\r\n                int q = rb / yb;\r\n                bigint yq = y.mul(q);\r\
    \n                while (rem < yq) {\r\n                    q--;\r\n         \
    \           yq -= y;\r\n                }\r\n                rem -= yq;\r\n  \
    \              while (rem >= y) {\r\n                    q++;\r\n            \
    \        rem -= y;\r\n                }\r\n                quo[i] = q;\r\n   \
    \         }\r\n            if (i)\r\n                rem.v.insert(rem.v.begin(),\
    \ x[i - 1]);\r\n        }\r\n        return quo;\r\n    }\r\n    bigint &operator/=(const\
    \ bigint &x) {\r\n        bigint a = abs(), b = x.abs();\r\n        sign ^= x.sign;\r\
    \n        if (a < b)\r\n            return *this = bigint();\r\n        if (b.size()\
    \ == 1)\r\n            return *this = a.div(b.v.back());\r\n\r\n        int deg\
    \ = a.size() - b.size() + 2, k = deg;\r\n        while (k > 64)\r\n          \
    \  k = (k + 1) >> 1;\r\n        bigint base(1);\r\n        base <<= (b.size()\
    \ + k);\r\n        bigint inv(div_naive(base, b));\r\n\r\n        while (k < deg)\
    \ {\r\n            bigint y = inv.square();\r\n            y.v.insert(y.v.begin(),\
    \ 0);\r\n            int l = min(SZ(b), k * 2 + 1);\r\n            bigint pref;\r\
    \n            pref.v = {b.v.end() - l, b.v.end()};\r\n            y *= pref;\r\
    \n            y >>= l;\r\n            inv = inv + inv;\r\n            inv <<=\
    \ k + 1;\r\n            inv -= y;\r\n            inv.v.erase(inv.v.begin());\r\
    \n            k <<= 1;\r\n        }\r\n        inv >>= (k - deg);\r\n\r\n    \
    \    (*this) = a * inv;\r\n        (*this) >>= int(a.size() + 2);\r\n        bigint\
    \ mul = (*this) * b;\r\n        while (mul + b <= a) {\r\n            (*this)\
    \ += bigint(1);\r\n            mul += b;\r\n        }\r\n        while (mul >\
    \ a) {\r\n            (*this) -= bigint(1);\r\n            mul -= b;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    bigint &operator%=(const bigint\
    \ &x) {\r\n        bigint div = (*this) / x;\r\n        (*this) -= div * x;\r\n\
    \        return *this;\r\n    }\r\n    bigint square() const {\r\n        bigint\
    \ ret;\r\n        auto v1 = ArbitraryMult<u128>(v, v);\r\n        u128 add = 0;\r\
    \n        ret.v.reserve(v1.size() + 3);\r\n        for (int i = 0;; i++) {\r\n\
    \            if (i >= int(v1.size()) and add == 0)\r\n                break;\r\
    \n            if (i < int(v1.size()))\r\n                add += v1[i];\r\n   \
    \         ret.v.push_back(add % B);\r\n            add /= B;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    bigint mul(ll x) const {\r\n        bigint\
    \ res;\r\n        if (x < 0)\r\n            res.sign ^= 1, x *= -1;\r\n      \
    \  u128 add = 0;\r\n        res.v.reserve(v.size() + 3);\r\n        for (int i\
    \ = 0;; i++) {\r\n            if (i >= int(v.size()) and add == 0)\r\n       \
    \         break;\r\n            if (i < int(v.size()))\r\n                add\
    \ += ll(v[i]) * x;\r\n            res.v.push_back(add % B);\r\n            add\
    \ /= B;\r\n        }\r\n        return res;\r\n    }\r\n    bigint div(ll x) const\
    \ {\r\n        bigint res = *this;\r\n        if (x < 0)\r\n            res.sign\
    \ ^= 1, x *= -1;\r\n        ll add = 0;\r\n        for (int i = res.v.size() -\
    \ 1; i >= 0; i--) {\r\n            add = add * B + res.v[i];\r\n            int\
    \ q = add / x, r = add % x;\r\n            res.v[i] = q, add = r;\r\n        }\r\
    \n        res.norm();\r\n        return res;\r\n    }\r\n    bigint operator<<(const\
    \ int &x) const { return bigint(*this) <<= x; }\r\n    bigint operator>>(const\
    \ int &x) const { return bigint(*this) >>= x; }\r\n    bigint operator+(const\
    \ bigint &x) const { return bigint(*this) += x; }\r\n    bigint operator-(const\
    \ bigint &x) const { return bigint(*this) -= x; }\r\n    bigint operator*(const\
    \ bigint &x) const { return bigint(*this) *= x; }\r\n    bigint operator/(const\
    \ bigint &x) const { return bigint(*this) /= x; }\r\n    bigint operator%(const\
    \ bigint &x) const { return bigint(*this) %= x; }\r\n    bool operator<(const\
    \ bigint &x) const {\r\n        if (sign != x.sign)\r\n            return sign\
    \ > x.sign;\r\n        if ((int)v.size() != (int)x.size()) {\r\n            if\
    \ (sign)\r\n                return (int)x.size() < (int)v.size();\r\n        \
    \    else\r\n                return (int)v.size() < (int)x.size();\r\n       \
    \ }\r\n        for (int i = v.size() - 1; i >= 0; i--)\r\n            if (v[i]\
    \ != x.v[i]) {\r\n                if (sign)\r\n                    return x.v[i]\
    \ < v[i];\r\n                else\r\n                    return v[i] < x.v[i];\r\
    \n            }\r\n        return false;\r\n    }\r\n    bool operator>(const\
    \ bigint &x) const { return x < *this; }\r\n    bool operator<=(const bigint &x)\
    \ const { return !(*this > x); }\r\n    bool operator>=(const bigint &x) const\
    \ { return !(*this < x); }\r\n    bool operator==(const bigint &x) const {\r\n\
    \        return !(*this < x) and !(*this > x);\r\n    }\r\n    bool operator!=(const\
    \ bigint &x) const { return !(*this == x); }\r\n};\r\ntypedef bigint<9> Bigint;\r\
    \n\r\nstruct Bigfloat {\r\n    Bigint v;\r\n    int p = 0;\r\n    Bigfloat() {}\r\
    \n    Bigfloat(const ll &_v) { v = Bigint(_v); }\r\n    Bigfloat(const Bigint\
    \ &_v, int _p = 0) : v(_v), p(_p) {}\r\n    void set(int _p) {\r\n        if (p\
    \ < _p) {\r\n            v >>= (_p - p);\r\n        } else {\r\n            v\
    \ <<= (p - _p);\r\n        }\r\n        p = _p;\r\n    }\r\n    Bigint to_int()\
    \ const {\r\n        if (p < 0)\r\n            return v >> (-p);\r\n        else\r\
    \n            return v << p;\r\n    }\r\n    Bigfloat &operator+=(const Bigfloat\
    \ &x) {\r\n        if (p > x.p)\r\n            set(x.p), v += x.v;\r\n       \
    \ else\r\n            v += x.v << (x.p - p);\r\n        return *this;\r\n    }\r\
    \n    Bigfloat &operator-=(const Bigfloat &x) {\r\n        if (p > x.p)\r\n  \
    \          set(x.p), v -= x.v;\r\n        else\r\n            v -= x.v << (x.p\
    \ - p);\r\n        return *this;\r\n    }\r\n    Bigfloat square() {\r\n     \
    \   Bigfloat res = *this;\r\n        res.p *= 2;\r\n        res.v = res.v.square();\r\
    \n        return res;\r\n    }\r\n    Bigfloat mul(ll x) {\r\n        Bigfloat\
    \ res = *this;\r\n        res.v = v.mul(x);\r\n        return res;\r\n    }\r\n\
    \    Bigfloat div(ll x) {\r\n        Bigfloat res = *this;\r\n        res.v =\
    \ v.div(x);\r\n        return res;\r\n    }\r\n    Bigfloat &operator*=(const\
    \ Bigfloat &x) {\r\n        p += x.p;\r\n        v *= x.v;\r\n        return *this;\r\
    \n    }\r\n    Bigfloat &operator/=(const Bigfloat &x) {\r\n        p -= x.p;\r\
    \n        v /= x.v;\r\n        return *this;\r\n    }\r\n    Bigfloat operator+(const\
    \ Bigfloat &x) const { return Bigfloat(*this) += x; }\r\n    Bigfloat operator-(const\
    \ Bigfloat &x) const { return Bigfloat(*this) -= x; }\r\n    Bigfloat operator*(const\
    \ Bigfloat &x) const { return Bigfloat(*this) *= x; }\r\n    Bigfloat operator/(const\
    \ Bigfloat &x) const { return Bigfloat(*this) /= x; }\r\n    string to_str() {\r\
    \n        string res = v.abs().to_str();\r\n        int d = Bigint::get_D();\r\
    \n        if (p * d > 0)\r\n            res += string(p * d, '0');\r\n       \
    \ else if (-p * d >= 1 and -p * d < (int)res.size()) {\r\n            res = res.substr(0,\
    \ (int)res.size() + p * d) + '.' +\r\n                  res.substr((int)res.size()\
    \ + p * d);\r\n        } else if (-p * d >= (int)res.size())\r\n            res\
    \ = \"0.\" + string(-p * d - (int)res.size(), '0') + res;\r\n        if (v.sign)\
    \ {\r\n            res.insert(res.begin(), '-');\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    friend ostream &operator<<(ostream &os, Bigfloat x) {\r\
    \n        os << x.to_str();\r\n        return os;\r\n    }\r\n};\r\n\r\nBigfloat\
    \ sqrt(ll n, int d) {\r\n    Bigfloat res(Bigint((ll)sqrt(1LL * Bigint::get_B()\
    \ * Bigint::get_B() / n)),\r\n                 -1),\r\n        pre;\r\n    int\
    \ cur = 1;\r\n    while (pre.v != res.v) {\r\n        cur = min(cur << 1, d);\r\
    \n        pre = res;\r\n        Bigfloat add = Bigfloat(1) - res.square().mul(n);\r\
    \n        add.set(-cur);\r\n        res += (res * add).div(2);\r\n        res.set(-cur);\r\
    \n    }\r\n    return res.mul(n);\r\n}\r\n\r\n/**\r\n * @brief Big Integer(Float)\r\
    \n */\n"
  code: "#pragma once\r\n#include \"Convolution/arbitrary.hpp\"\r\n\r\ntemplate <int\
    \ D> struct bigint {\r\n    using u128 = __uint128_t;\r\n    static const int\
    \ B = pow(10, D);\r\n    int sign = 0;\r\n    vector<int> v;\r\n    static int\
    \ get_D() { return D; }\r\n    static int get_B() { return B; }\r\n    bigint()\
    \ {}\r\n    bigint(const vector<int> &_v, bool _s = false) : sign(_s), v(_v) {}\r\
    \n    bigint(ll x) {\r\n        if (x < 0)\r\n            x *= -1, sign = 1;\r\
    \n        while (x) {\r\n            v.push_back(x % B);\r\n            x /= B;\r\
    \n        }\r\n    }\r\n    bigint(string s) {\r\n        if (s[0] == '-')\r\n\
    \            s.erase(s.begin()), sign = 1;\r\n        int add = 0, cnt = 0, base\
    \ = 1;\r\n        while (s.size()) {\r\n            if (cnt == D) {\r\n      \
    \          v.push_back(add);\r\n                cnt = 0;\r\n                add\
    \ = 0;\r\n                base = 1;\r\n            }\r\n            add = (s.back()\
    \ - '0') * base + add;\r\n            cnt++;\r\n            base *= 10;\r\n  \
    \          s.pop_back();\r\n        }\r\n        if (add)\r\n            v.push_back(add);\r\
    \n    }\r\n    bigint operator-() const {\r\n        bigint res = *this;\r\n \
    \       res.sign ^= 1;\r\n        return res;\r\n    }\r\n    bigint abs() const\
    \ {\r\n        bigint res = *this;\r\n        res.sign = 0;\r\n        return\
    \ res;\r\n    }\r\n    int &operator[](const int i) { return v[i]; }\r\n    int\
    \ size() const { return v.size(); }\r\n    void norm() {\r\n        rep(i, 0,\
    \ v.size() - 1) {\r\n            if (v[i] >= 0) {\r\n                v[i + 1]\
    \ += v[i] / B;\r\n                v[i] %= B;\r\n            } else {\r\n     \
    \           int c = (-v[i] + B - 1) / B;\r\n                v[i] += c * B;\r\n\
    \                v[i + 1] -= c;\r\n            }\r\n        }\r\n        while\
    \ (!v.empty() and v.back() >= B) {\r\n            int c = v.back() / B;\r\n  \
    \          v.back() %= B;\r\n            v.push_back(c);\r\n        }\r\n    \
    \    while (!v.empty() and v.back() == 0)\r\n            v.pop_back();\r\n   \
    \ }\r\n    string to_str() const {\r\n        string res;\r\n        if (v.empty())\r\
    \n            return \"0\";\r\n        if (sign)\r\n            res += '-';\r\n\
    \        res += to_string(v.back());\r\n        for (int i = v.size() - 2; i >=\
    \ 0; i--) {\r\n            string add;\r\n            int w = v[i];\r\n      \
    \      rep(_, 0, D) {\r\n                add += ('0' + (w % 10));\r\n        \
    \        w /= 10;\r\n            }\r\n            reverse(ALL(add));\r\n     \
    \       res += add;\r\n        }\r\n        return res;\r\n    }\r\n    friend\
    \ istream &operator>>(istream &is, bigint<D> &x) {\r\n        string tmp;\r\n\
    \        is >> tmp;\r\n        x = bigint(tmp);\r\n        return is;\r\n    }\r\
    \n    friend ostream &operator<<(ostream &os, bigint<D> x) {\r\n        os <<\
    \ x.to_str();\r\n        return os;\r\n    }\r\n    bigint &operator<<=(const\
    \ int &x) {\r\n        if (!v.empty()) {\r\n            vector<int> add(x, 0);\r\
    \n            v.insert(v.begin(), ALL(add));\r\n        }\r\n        return *this;\r\
    \n    }\r\n    bigint &operator>>=(const int &x) {\r\n        v = vector<int>(v.begin()\
    \ + min(x, (int)v.size()), v.end());\r\n        return *this;\r\n    }\r\n   \
    \ bigint &operator+=(const bigint &x) {\r\n        if (sign != x.sign) {\r\n \
    \           *this -= (-x);\r\n            return *this;\r\n        }\r\n     \
    \   if ((int)v.size() < (int)x.size())\r\n            v.resize(x.size(), 0);\r\
    \n        rep(i, 0, x.size()) { v[i] += x.v[i]; }\r\n        norm();\r\n     \
    \   return *this;\r\n    }\r\n    bigint &operator-=(const bigint &x) {\r\n  \
    \      if (sign != x.sign) {\r\n            *this += (-x);\r\n            return\
    \ *this;\r\n        }\r\n        if (abs() < x.abs()) {\r\n            *this =\
    \ x - (*this);\r\n            sign ^= 1;\r\n            return *this;\r\n    \
    \    }\r\n        rep(i, 0, x.size()) { v[i] -= x.v[i]; }\r\n        norm();\r\
    \n        return *this;\r\n    }\r\n    bigint &operator*=(const bigint &x) {\r\
    \n        sign ^= x.sign;\r\n        auto v1 = ArbitraryMult<u128>(v, x.v);\r\n\
    \        u128 add = 0;\r\n        v.clear();\r\n        v.reserve(v1.size() +\
    \ 3);\r\n        for (int i = 0;; i++) {\r\n            if (i >= int(v1.size())\
    \ and add == 0)\r\n                break;\r\n            if (i < int(v1.size()))\r\
    \n                add += v1[i];\r\n            v.push_back(add % B);\r\n     \
    \       add /= B;\r\n        }\r\n        norm();\r\n        return *this;\r\n\
    \    }\r\n    bigint div_naive(const bigint &a, const bigint &b) {\r\n       \
    \ if (SZ(b) == 1)\r\n            return a.div(b.v.back());\r\n        if (a <\
    \ b)\r\n            return bigint();\r\n        int norm = B / (b.v.back() + 1);\r\
    \n        bigint x = a.mul(norm), y = b.mul(norm);\r\n        int yb = y.v.back();\r\
    \n        bigint quo, rem;\r\n        quo.v.resize(x.size() - y.size() + 1);\r\
    \n        rem.v = {x.v.end() - y.size(), x.v.end()};\r\n        for (int i = x.size()\
    \ - y.size(); i >= 0; i--) {\r\n            if (rem.size() == y.size()) {\r\n\
    \                if (rem >= y) {\r\n                    quo[i] = 1;\r\n      \
    \              rem -= y;\r\n                }\r\n            } else if (rem.size()\
    \ > y.size()) {\r\n                ll rb = ll(rem.v.back()) * B + rem[rem.size()\
    \ - 2];\r\n                int q = rb / yb;\r\n                bigint yq = y.mul(q);\r\
    \n                while (rem < yq) {\r\n                    q--;\r\n         \
    \           yq -= y;\r\n                }\r\n                rem -= yq;\r\n  \
    \              while (rem >= y) {\r\n                    q++;\r\n            \
    \        rem -= y;\r\n                }\r\n                quo[i] = q;\r\n   \
    \         }\r\n            if (i)\r\n                rem.v.insert(rem.v.begin(),\
    \ x[i - 1]);\r\n        }\r\n        return quo;\r\n    }\r\n    bigint &operator/=(const\
    \ bigint &x) {\r\n        bigint a = abs(), b = x.abs();\r\n        sign ^= x.sign;\r\
    \n        if (a < b)\r\n            return *this = bigint();\r\n        if (b.size()\
    \ == 1)\r\n            return *this = a.div(b.v.back());\r\n\r\n        int deg\
    \ = a.size() - b.size() + 2, k = deg;\r\n        while (k > 64)\r\n          \
    \  k = (k + 1) >> 1;\r\n        bigint base(1);\r\n        base <<= (b.size()\
    \ + k);\r\n        bigint inv(div_naive(base, b));\r\n\r\n        while (k < deg)\
    \ {\r\n            bigint y = inv.square();\r\n            y.v.insert(y.v.begin(),\
    \ 0);\r\n            int l = min(SZ(b), k * 2 + 1);\r\n            bigint pref;\r\
    \n            pref.v = {b.v.end() - l, b.v.end()};\r\n            y *= pref;\r\
    \n            y >>= l;\r\n            inv = inv + inv;\r\n            inv <<=\
    \ k + 1;\r\n            inv -= y;\r\n            inv.v.erase(inv.v.begin());\r\
    \n            k <<= 1;\r\n        }\r\n        inv >>= (k - deg);\r\n\r\n    \
    \    (*this) = a * inv;\r\n        (*this) >>= int(a.size() + 2);\r\n        bigint\
    \ mul = (*this) * b;\r\n        while (mul + b <= a) {\r\n            (*this)\
    \ += bigint(1);\r\n            mul += b;\r\n        }\r\n        while (mul >\
    \ a) {\r\n            (*this) -= bigint(1);\r\n            mul -= b;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    bigint &operator%=(const bigint\
    \ &x) {\r\n        bigint div = (*this) / x;\r\n        (*this) -= div * x;\r\n\
    \        return *this;\r\n    }\r\n    bigint square() const {\r\n        bigint\
    \ ret;\r\n        auto v1 = ArbitraryMult<u128>(v, v);\r\n        u128 add = 0;\r\
    \n        ret.v.reserve(v1.size() + 3);\r\n        for (int i = 0;; i++) {\r\n\
    \            if (i >= int(v1.size()) and add == 0)\r\n                break;\r\
    \n            if (i < int(v1.size()))\r\n                add += v1[i];\r\n   \
    \         ret.v.push_back(add % B);\r\n            add /= B;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    bigint mul(ll x) const {\r\n        bigint\
    \ res;\r\n        if (x < 0)\r\n            res.sign ^= 1, x *= -1;\r\n      \
    \  u128 add = 0;\r\n        res.v.reserve(v.size() + 3);\r\n        for (int i\
    \ = 0;; i++) {\r\n            if (i >= int(v.size()) and add == 0)\r\n       \
    \         break;\r\n            if (i < int(v.size()))\r\n                add\
    \ += ll(v[i]) * x;\r\n            res.v.push_back(add % B);\r\n            add\
    \ /= B;\r\n        }\r\n        return res;\r\n    }\r\n    bigint div(ll x) const\
    \ {\r\n        bigint res = *this;\r\n        if (x < 0)\r\n            res.sign\
    \ ^= 1, x *= -1;\r\n        ll add = 0;\r\n        for (int i = res.v.size() -\
    \ 1; i >= 0; i--) {\r\n            add = add * B + res.v[i];\r\n            int\
    \ q = add / x, r = add % x;\r\n            res.v[i] = q, add = r;\r\n        }\r\
    \n        res.norm();\r\n        return res;\r\n    }\r\n    bigint operator<<(const\
    \ int &x) const { return bigint(*this) <<= x; }\r\n    bigint operator>>(const\
    \ int &x) const { return bigint(*this) >>= x; }\r\n    bigint operator+(const\
    \ bigint &x) const { return bigint(*this) += x; }\r\n    bigint operator-(const\
    \ bigint &x) const { return bigint(*this) -= x; }\r\n    bigint operator*(const\
    \ bigint &x) const { return bigint(*this) *= x; }\r\n    bigint operator/(const\
    \ bigint &x) const { return bigint(*this) /= x; }\r\n    bigint operator%(const\
    \ bigint &x) const { return bigint(*this) %= x; }\r\n    bool operator<(const\
    \ bigint &x) const {\r\n        if (sign != x.sign)\r\n            return sign\
    \ > x.sign;\r\n        if ((int)v.size() != (int)x.size()) {\r\n            if\
    \ (sign)\r\n                return (int)x.size() < (int)v.size();\r\n        \
    \    else\r\n                return (int)v.size() < (int)x.size();\r\n       \
    \ }\r\n        for (int i = v.size() - 1; i >= 0; i--)\r\n            if (v[i]\
    \ != x.v[i]) {\r\n                if (sign)\r\n                    return x.v[i]\
    \ < v[i];\r\n                else\r\n                    return v[i] < x.v[i];\r\
    \n            }\r\n        return false;\r\n    }\r\n    bool operator>(const\
    \ bigint &x) const { return x < *this; }\r\n    bool operator<=(const bigint &x)\
    \ const { return !(*this > x); }\r\n    bool operator>=(const bigint &x) const\
    \ { return !(*this < x); }\r\n    bool operator==(const bigint &x) const {\r\n\
    \        return !(*this < x) and !(*this > x);\r\n    }\r\n    bool operator!=(const\
    \ bigint &x) const { return !(*this == x); }\r\n};\r\ntypedef bigint<9> Bigint;\r\
    \n\r\nstruct Bigfloat {\r\n    Bigint v;\r\n    int p = 0;\r\n    Bigfloat() {}\r\
    \n    Bigfloat(const ll &_v) { v = Bigint(_v); }\r\n    Bigfloat(const Bigint\
    \ &_v, int _p = 0) : v(_v), p(_p) {}\r\n    void set(int _p) {\r\n        if (p\
    \ < _p) {\r\n            v >>= (_p - p);\r\n        } else {\r\n            v\
    \ <<= (p - _p);\r\n        }\r\n        p = _p;\r\n    }\r\n    Bigint to_int()\
    \ const {\r\n        if (p < 0)\r\n            return v >> (-p);\r\n        else\r\
    \n            return v << p;\r\n    }\r\n    Bigfloat &operator+=(const Bigfloat\
    \ &x) {\r\n        if (p > x.p)\r\n            set(x.p), v += x.v;\r\n       \
    \ else\r\n            v += x.v << (x.p - p);\r\n        return *this;\r\n    }\r\
    \n    Bigfloat &operator-=(const Bigfloat &x) {\r\n        if (p > x.p)\r\n  \
    \          set(x.p), v -= x.v;\r\n        else\r\n            v -= x.v << (x.p\
    \ - p);\r\n        return *this;\r\n    }\r\n    Bigfloat square() {\r\n     \
    \   Bigfloat res = *this;\r\n        res.p *= 2;\r\n        res.v = res.v.square();\r\
    \n        return res;\r\n    }\r\n    Bigfloat mul(ll x) {\r\n        Bigfloat\
    \ res = *this;\r\n        res.v = v.mul(x);\r\n        return res;\r\n    }\r\n\
    \    Bigfloat div(ll x) {\r\n        Bigfloat res = *this;\r\n        res.v =\
    \ v.div(x);\r\n        return res;\r\n    }\r\n    Bigfloat &operator*=(const\
    \ Bigfloat &x) {\r\n        p += x.p;\r\n        v *= x.v;\r\n        return *this;\r\
    \n    }\r\n    Bigfloat &operator/=(const Bigfloat &x) {\r\n        p -= x.p;\r\
    \n        v /= x.v;\r\n        return *this;\r\n    }\r\n    Bigfloat operator+(const\
    \ Bigfloat &x) const { return Bigfloat(*this) += x; }\r\n    Bigfloat operator-(const\
    \ Bigfloat &x) const { return Bigfloat(*this) -= x; }\r\n    Bigfloat operator*(const\
    \ Bigfloat &x) const { return Bigfloat(*this) *= x; }\r\n    Bigfloat operator/(const\
    \ Bigfloat &x) const { return Bigfloat(*this) /= x; }\r\n    string to_str() {\r\
    \n        string res = v.abs().to_str();\r\n        int d = Bigint::get_D();\r\
    \n        if (p * d > 0)\r\n            res += string(p * d, '0');\r\n       \
    \ else if (-p * d >= 1 and -p * d < (int)res.size()) {\r\n            res = res.substr(0,\
    \ (int)res.size() + p * d) + '.' +\r\n                  res.substr((int)res.size()\
    \ + p * d);\r\n        } else if (-p * d >= (int)res.size())\r\n            res\
    \ = \"0.\" + string(-p * d - (int)res.size(), '0') + res;\r\n        if (v.sign)\
    \ {\r\n            res.insert(res.begin(), '-');\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    friend ostream &operator<<(ostream &os, Bigfloat x) {\r\
    \n        os << x.to_str();\r\n        return os;\r\n    }\r\n};\r\n\r\nBigfloat\
    \ sqrt(ll n, int d) {\r\n    Bigfloat res(Bigint((ll)sqrt(1LL * Bigint::get_B()\
    \ * Bigint::get_B() / n)),\r\n                 -1),\r\n        pre;\r\n    int\
    \ cur = 1;\r\n    while (pre.v != res.v) {\r\n        cur = min(cur << 1, d);\r\
    \n        pre = res;\r\n        Bigfloat add = Bigfloat(1) - res.square().mul(n);\r\
    \n        add.set(-cur);\r\n        res += (res * add).div(2);\r\n        res.set(-cur);\r\
    \n    }\r\n    return res.mul(n);\r\n}\r\n\r\n/**\r\n * @brief Big Integer(Float)\r\
    \n */"
  dependsOn:
  - Convolution/arbitrary.hpp
  - Convolution/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: false
  path: Math/bigint.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/bigint.hpp
layout: document
redirect_from:
- /library/Math/bigint.hpp
- /library/Math/bigint.hpp.html
title: Big Integer(Float)
---
