---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/subset.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_hafnian_of_matrix.test.cpp
    title: Verify/LC_hafnian_of_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Hafnian of matrix
    links: []
  bundledCode: "#line 2 \"Math/hafnian.hpp\"\n\n#line 2 \"Math/matrix.hpp\"\n\r\n\
    template <class T> struct Matrix {\r\n    int h, w;\r\n    vector<vector<T>> val;\r\
    \n    T det;\r\n    Matrix() {}\r\n    Matrix(int n) : h(n), w(n), val(vector<vector<T>>(n,\
    \ vector<T>(n))) {}\r\n    Matrix(int n, int m)\r\n        : h(n), w(m), val(vector<vector<T>>(n,\
    \ vector<T>(m))) {}\r\n    vector<T> &operator[](const int i) {\r\n        return\
    \ val[i];\r\n    }\r\n    Matrix &operator+=(const Matrix &m) {\r\n        assert(h\
    \ == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w) val[i][j] += m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix &operator-=(const Matrix &m) {\r\
    \n        assert(h == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w)\
    \ val[i][j] -= m.val[i][j];\r\n        return *this;\r\n    }\r\n    Matrix &operator*=(const\
    \ Matrix &m) {\r\n        assert(w == m.h);\r\n        Matrix<T> res(h, m.w);\r\
    \n        rep(i, 0, h) rep(j, 0, m.w) rep(k, 0, w) res.val[i][j] +=\r\n      \
    \      val[i][k] * m.val[k][j];\r\n        *this = res;\r\n        return *this;\r\
    \n    }\r\n    Matrix operator+(const Matrix &m) const {\r\n        return Matrix(*this)\
    \ += m;\r\n    }\r\n    Matrix operator-(const Matrix &m) const {\r\n        return\
    \ Matrix(*this) -= m;\r\n    }\r\n    Matrix operator*(const Matrix &m) const\
    \ {\r\n        return Matrix(*this) *= m;\r\n    }\r\n    Matrix pow(ll k) {\r\
    \n        Matrix<T> res(h, h), c = *this;\r\n        rep(i, 0, h) res.val[i][i]\
    \ = 1;\r\n        while (k) {\r\n            if (k & 1)\r\n                res\
    \ *= c;\r\n            c *= c;\r\n            k >>= 1;\r\n        }\r\n      \
    \  return res;\r\n    }\r\n    vector<int> gauss(int c = -1) {\r\n        det\
    \ = 1;\r\n        if (val.empty())\r\n            return {};\r\n        if (c\
    \ == -1)\r\n            c = w;\r\n        int cur = 0;\r\n        vector<int>\
    \ res;\r\n        rep(i, 0, c) {\r\n            if (cur == h)\r\n            \
    \    break;\r\n            rep(j, cur, h) if (val[j][i] != 0) {\r\n          \
    \      swap(val[cur], val[j]);\r\n                if (cur != j)\r\n          \
    \          det *= -1;\r\n                break;\r\n            }\r\n         \
    \   det *= val[cur][i];\r\n            if (val[cur][i] == 0)\r\n             \
    \   continue;\r\n            rep(j, 0, h) if (j != cur) {\r\n                T\
    \ z = val[j][i] / val[cur][i];\r\n                rep(k, i, w) val[j][k] -= val[cur][k]\
    \ * z;\r\n            }\r\n            res.push_back(i);\r\n            cur++;\r\
    \n        }\r\n        return res;\r\n    }\r\n    Matrix inv() {\r\n        assert(h\
    \ == w);\r\n        Matrix base(h, h * 2), res(h, h);\r\n        rep(i, 0, h)\
    \ rep(j, 0, h) base[i][j] = val[i][j];\r\n        rep(i, 0, h) base[i][h + i]\
    \ = 1;\r\n        base.gauss(h);\r\n        det = base.det;\r\n        rep(i,\
    \ 0, h) rep(j, 0, h) res[i][j] = base[i][h + j] / base[i][i];\r\n        return\
    \ res;\r\n    }\r\n    bool operator==(const Matrix &m) {\r\n        assert(h\
    \ == m.h and w == m.w);\r\n        rep(i, 0, h) rep(j, 0, w) if (val[i][j] !=\
    \ m.val[i][j]) return false;\r\n        return true;\r\n    }\r\n    bool operator!=(const\
    \ Matrix &m) {\r\n        assert(h == m.h and w == m.w);\r\n        rep(i, 0,\
    \ h) rep(j, 0, w) if (val[i][j] == m.val[i][j]) return false;\r\n        return\
    \ true;\r\n    }\r\n    friend istream &operator>>(istream &is, Matrix &m) {\r\
    \n        rep(i, 0, m.h) rep(j, 0, m.w) is >> m[i][j];\r\n        return is;\r\
    \n    }\r\n    friend ostream &operator<<(ostream &os, Matrix &m) {\r\n      \
    \  rep(i, 0, m.h) {\r\n            rep(j, 0, m.w) os << m[i][j]\r\n          \
    \                    << (j == m.w - 1 and i != m.h - 1 ? '\\n' : ' ');\r\n   \
    \     }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Matrix\r\n\
    \ */\n#line 2 \"Math/comb.hpp\"\n\ntemplate <typename T> T Inv(ll n) {\n    static\
    \ int md;\n    static vector<T> buf({0, 1});\n    if (md != T::get_mod()) {\n\
    \        md = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n    assert(n\
    \ > 0);\n    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf), q\
    \ = (md + k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n  \
    \  return buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n \
    \   static int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md\
    \ != T::get_mod()) {\n        md = T::get_mod();\n        buf = ibuf = vector<T>({1,\
    \ 1});\n    }\n    assert(n >= 0 and n < md);\n    while (SZ(buf) <= n) {\n  \
    \      buf.push_back(buf.back() * SZ(buf));\n        ibuf.push_back(ibuf.back()\
    \ * Inv<T>(SZ(ibuf)));\n    }\n    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate\
    \ <typename T> T nPr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r ||\
    \ r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^\
    \ 1);\n}\ntemplate <typename T> T nCr(int n, int r, bool inv = 0) {\n    if (n\
    \ < 0 || n < r || r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(r,\
    \ inv ^ 1) * Fact<T>(n - r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename\
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r, inv);\n\
    }\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T choose(int\
    \ n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return nCr<T>(n\
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"Convolution/subset.hpp\"\
    \n\r\ntemplate <typename T, int LG = 20> struct SubsetConvolution {\r\n    using\
    \ POL = array<T, LG + 1>;\r\n    vector<int> bpc;\r\n    SubsetConvolution() :\
    \ bpc(1 << LG) {\r\n        rep(i, 1, 1 << LG) bpc[i] = bpc[i - (i & -i)] + 1;\r\
    \n    }\r\n    void zeta(vector<POL> &a) {\r\n        int n = topbit(SZ(a));\r\
    \n        rep(d, 0, n) {\r\n            rep(i, 0, 1 << n) if (i >> d & 1) {\r\n\
    \                const int pc = bpc[i];\r\n                rep(j, 0, pc) a[i][j]\
    \ += a[i ^ (1 << d)][j];\r\n            }\r\n        }\r\n    }\r\n    void mobius(vector<POL>\
    \ &a) {\r\n        int n = topbit(SZ(a));\r\n        rep(d, 0, n) {\r\n      \
    \      rep(i, 0, 1 << n) if (i >> d & 1) {\r\n                const int pc = bpc[i];\r\
    \n                rep(j, pc, n + 1) a[i][j] -= a[i ^ (1 << d)][j];\r\n       \
    \     }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T> &a, vector<T> &b)\
    \ {\r\n        assert(a.size() == b.size());\r\n        int n = SZ(a), m = topbit(n);\r\
    \n        vector<POL> A(n), B(n);\r\n        rep(i, 0, n) {\r\n            A[i][bpc[i]]\
    \ = a[i];\r\n            B[i][bpc[i]] = b[i];\r\n        }\r\n        zeta(A);\r\
    \n        zeta(B);\r\n        rep(i, 0, n) {\r\n            POL c = {};\r\n  \
    \          rep(j, 0, m + 1) rep(k, 0, m + 1 - j) c[j + k] += A[i][j] * B[i][k];\r\
    \n            swap(A[i], c);\r\n        }\r\n        mobius(A);\r\n        vector<T>\
    \ ret(n);\r\n        rep(i, 0, n) ret[i] = A[i][bpc[i]];\r\n        return ret;\r\
    \n    }\r\n    vector<T> TransposeMult(vector<T> &a, vector<T> &b) {\r\n     \
    \   auto ret = a;\r\n        reverse(ALL(ret));\r\n        ret = mult(ret, b);\r\
    \n        reverse(ALL(ret));\r\n        return ret;\r\n    }\r\n    vector<T>\
    \ exp(vector<T> &f) {\r\n        int n = topbit(SZ(f));\r\n        vector<T> ret(1\
    \ << n);\r\n        ret[0] = 1;\r\n        rep(i, 0, n) {\r\n            vector<T>\
    \ a = {ret.begin(), ret.begin() + (1 << i)};\r\n            vector<T> b = {f.begin()\
    \ + (1 << i), f.begin() + (2 << i)};\r\n            a = mult(a, b);\r\n      \
    \      copy(ALL(a), ret.begin() + (1 << i));\r\n        }\r\n        return ret;\r\
    \n    }\r\n    vector<T> CompositionEGF(vector<T> &s, vector<T> &f) {\r\n    \
    \    int n = topbit(SZ(s));\r\n        f.resize(n + 1);\r\n        vector<T> dp(1);\r\
    \n        dp[0] = f.back();\r\n        rrep(d, 0, n) {\r\n            vector<T>\
    \ ndp(1 << (n - d));\r\n            ndp[0] = f[d];\r\n            rep(i, 0, n\
    \ - d) {\r\n                vector<T> a = {dp.begin(), dp.begin() + (1 << i)};\r\
    \n                vector<T> b = {s.begin() + (1 << i), s.begin() + (2 << i)};\r\
    \n                a = mult(a, b);\r\n                copy(ALL(a), ndp.begin()\
    \ + (1 << i));\r\n            }\r\n            swap(dp, ndp);\r\n        }\r\n\
    \        return dp;\r\n    }\r\n    vector<T> Composition(vector<T> &s, vector<T>\
    \ &f) {\r\n        int n = topbit(SZ(s));\r\n        T c = s[0];\r\n        s[0]\
    \ = 0;\r\n        // taylor shift\r\n        vector<T> pw(n + 1), g(n + 1);\r\n\
    \        pw[0] = 1;\r\n        rep(i, 0, SZ(f)) {\r\n            rep(j, 0, n +\
    \ 1) g[j] += f[i] * pw[j];\r\n            rrep(j, 0, n + 1) {\r\n            \
    \    if (j != n)\r\n                    pw[j + 1] += pw[j];\r\n              \
    \  pw[j] *= c;\r\n            }\r\n        }\r\n        // to EGF\r\n        T\
    \ fact = 1;\r\n        rep(i, 1, n + 1) {\r\n            fact *= i;\r\n      \
    \      g[i] *= fact;\r\n        }\r\n        return CompositionEGF(s, g);\r\n\
    \    }\r\n    vector<T> TransposeCompositionEGF(vector<T> &s, vector<T> &t) {\r\
    \n        int n = topbit(SZ(s));\r\n        vector<T> dp = t, ret(n + 1);\r\n\
    \        ret[0] = dp[0];\r\n        rep(d, 0, n) {\r\n            vector<T> ndp(1\
    \ << (n - d - 1), 0);\r\n            rrep(i, 0, n - d) {\r\n                vector<T>\
    \ a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\r\n                vector<T>\
    \ b = {s.begin() + (1 << i), s.begin() + (2 << i)};\r\n                a = TransposeMult(a,\
    \ b);\r\n                rep(k, 0, SZ(a)) ndp[k] += a[k];\r\n            }\r\n\
    \            swap(dp, ndp);\r\n            ret[d + 1] = dp[0];\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    vector<T> TransposeComposition(vector<T>\
    \ &s, vector<T> &t, int m) {\r\n        int n = topbit(SZ(s));\r\n        T c\
    \ = s[0];\r\n        s[0] = 0;\r\n\r\n        auto g = TransposeCompositionEGF(s,\
    \ t);\r\n        vector<T> coe(m);\r\n        T pw = 1;\r\n        rep(i, 0, m)\
    \ {\r\n            coe[i] = pw * Fact<T>(i, 1);\r\n            pw *= c;\r\n  \
    \      }\r\n        vector<T> f(m);\r\n        rep(i, 0, m) rep(j, 0, n + 1) if\
    \ (i + j < m) {\r\n            f[i + j] += coe[i] * g[j];\r\n        }\r\n   \
    \     rep(i, 0, m) f[i] *= Fact<T>(i);\r\n        return f;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Subset Convolution\r\n */\n#line 5 \"Math/hafnian.hpp\"\n\
    \ntemplate<typename T>T Hafnian(Matrix<T>& a){\n    int n=a.h;\n    assert(n%2==0);\n\
    \    n>>=1;\n\n    vector<T> cycle(1<<n);\n    vector dp(1<<n,vector<T>(n*2));\n\
    \    rep(base,0,n)dp[1<<base][base*2]=1;\n    rep(mask,0,1<<n){\n        int top=-1;\n\
    \        rep(i,0,n)if(mask>>i&1)top=i;\n        rep(base,0,n*2)if(mask>>(base>>1)&1){\n\
    \            T add=dp[mask][base];\n            rep(nxt,0,top)if(!(mask>>nxt&1)){\n\
    \                dp[mask|(1<<nxt)][nxt*2+1]+=add*a[base][nxt*2];\n           \
    \     dp[mask|(1<<nxt)][nxt*2]+=add*a[base][nxt*2+1];\n            }\n       \
    \ }\n    }\n    rep(mask,1,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)cycle[mask]+=dp[mask][base]*a[base][top*2+1];\n    }\n\
    \    \n    SubsetConvolution<T> buf;\n    auto ret=buf.exp(cycle);\n    return\
    \ ret[(1<<n)-1];\n}\n\n/**\n * @brief Hafnian of matrix\n*/\n"
  code: "#pragma once\n\n#include \"Math/matrix.hpp\"\n#include \"Convolution/subset.hpp\"\
    \n\ntemplate<typename T>T Hafnian(Matrix<T>& a){\n    int n=a.h;\n    assert(n%2==0);\n\
    \    n>>=1;\n\n    vector<T> cycle(1<<n);\n    vector dp(1<<n,vector<T>(n*2));\n\
    \    rep(base,0,n)dp[1<<base][base*2]=1;\n    rep(mask,0,1<<n){\n        int top=-1;\n\
    \        rep(i,0,n)if(mask>>i&1)top=i;\n        rep(base,0,n*2)if(mask>>(base>>1)&1){\n\
    \            T add=dp[mask][base];\n            rep(nxt,0,top)if(!(mask>>nxt&1)){\n\
    \                dp[mask|(1<<nxt)][nxt*2+1]+=add*a[base][nxt*2];\n           \
    \     dp[mask|(1<<nxt)][nxt*2]+=add*a[base][nxt*2+1];\n            }\n       \
    \ }\n    }\n    rep(mask,1,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)cycle[mask]+=dp[mask][base]*a[base][top*2+1];\n    }\n\
    \    \n    SubsetConvolution<T> buf;\n    auto ret=buf.exp(cycle);\n    return\
    \ ret[(1<<n)-1];\n}\n\n/**\n * @brief Hafnian of matrix\n*/"
  dependsOn:
  - Math/matrix.hpp
  - Convolution/subset.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: Math/hafnian.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_hafnian_of_matrix.test.cpp
documentation_of: Math/hafnian.hpp
layout: document
redirect_from:
- /library/Math/hafnian.hpp
- /library/Math/hafnian.hpp.html
title: Hafnian of matrix
---
