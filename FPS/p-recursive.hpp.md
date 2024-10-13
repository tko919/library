---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/samplepointshift.hpp
    title: Shift of Sampling Points of Polynomial
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  - icon: ':heavy_check_mark:'
    path: Math/linearequation.hpp
    title: Linear Equation
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: P-recursive
    links: []
  bundledCode: "#line 2 \"Math/comb.hpp\"\n\ntemplate <typename T> T Inv(ll n) {\n\
    \    static int md;\n    static vector<T> buf({0, 1});\n    if (md != T::get_mod())\
    \ {\n        md = T::get_mod();\n        buf = vector<T>({0, 1});\n    }\n   \
    \ assert(n > 0);\n    n %= md;\n    while (SZ(buf) <= n) {\n        int k = SZ(buf),\
    \ q = (md + k - 1) / k;\n        buf.push_back(buf[k * q - md] * q);\n    }\n\
    \    return buf[n];\n}\n\ntemplate <typename T> T Fact(ll n, bool inv = 0) {\n\
    \    static int md;\n    static vector<T> buf({1, 1}), ibuf({1, 1});\n    if (md\
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
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"FPS/samplepointshift.hpp\"\
    \n\ntemplate <typename T>\nPoly<T> SamplePointsShift(vector<T> &ys, T c, int m\
    \ = -1) {\n    ll n = ys.size() - 1, C = c.v % T::get_mod();\n    if (m == -1)\n\
    \        m = n + 1;\n    if (C <= n) {\n        Poly<T> res;\n        rep(i, C,\
    \ n + 1) res.push_back(ys[i]);\n        if (int(res.size()) >= m) {\n        \
    \    res.resize(m);\n            return res;\n        }\n        auto add = SamplePointsShift<T>(ys,\
    \ n + 1, m - res.size());\n        for (int i = 0; int(res.size()) < m; i++) {\n\
    \            res.push_back(add[i]);\n        }\n        return res;\n    }\n \
    \   if (C + m > T::get_mod()) {\n        auto res = SamplePointsShift<T>(ys, c,\
    \ T::get_mod() - c.v);\n        auto add = SamplePointsShift<T>(ys, 0, m - res.size());\n\
    \        rep(i, 0, add.size()) res.push_back(add[i]);\n        return res;\n \
    \   }\n\n    Poly<T> A(n + 1), B(m + n);\n    rep(i, 0, n + 1) {\n        A[i]\
    \ = ys[i] * Fact<T>(i, 1) * Fact<T>(n - i, 1);\n        if ((n - i) & 1)\n   \
    \         A[i] = -A[i];\n    }\n    rep(i, 0, m + n) B[i] = Fp(1) / (c - n + i);\n\
    \    auto AB = A * B;\n    vector<T> res(m);\n    Fp base = 1;\n    rep(x, 0,\
    \ n + 1) base *= (c - x);\n    rep(i, 0, m) {\n        res[i] = AB[n + i] * base;\n\
    \        base *= (c + i + 1);\n        base *= B[i];\n    }\n    return res;\n\
    }\n\n/**\n * @brief Shift of Sampling Points of Polynomial\n */\n#line 2 \"Math/matrix.hpp\"\
    \n\r\ntemplate <class T> struct Matrix {\r\n    int h, w;\r\n    vector<vector<T>>\
    \ val;\r\n    T det;\r\n    Matrix() {}\r\n    Matrix(int n) : h(n), w(n), val(vector<vector<T>>(n,\
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
    \ */\n#line 3 \"Math/linearequation.hpp\"\n\r\ntemplate<typename T>pair<vector<T>,Matrix<T>>\
    \ LinearEquation(Matrix<T> a,vector<T> b){\r\n   int h=a.h,w=a.w;\r\n   rep(i,0,h)a[i].push_back(b[i]);\r\
    \n   a.w++;\r\n   vector<int> idx=a.gauss(w);\r\n   rep(i,idx.size(),h)if(a[i][w]!=0)return\
    \ {{},{}};\r\n   vector<T> res(w);\r\n   rep(i,0,idx.size())res[idx[i]]=a[i][w]/a[i][idx[i]];\r\
    \n   Matrix<T> d(w,h+w);\r\n   rep(i,0,h)rep(j,0,w)d[j][i]=a[i][j];\r\n   rep(i,0,w)d[i][h+i]=1;\r\
    \n   int r=d.gauss(h).size();\r\n   Matrix<T> basis(w-r,w);\r\n   rep(i,r,w)basis[i-r]={d[i].begin()+h,d[i].end()};\r\
    \n   return {res,basis};\r\n}\r\n\r\n/**\r\n * @brief Linear Equation\r\n */\n\
    #line 5 \"FPS/p-recursive.hpp\"\n\ntemplate <typename T>\nMatrix<T> PrefixProdOfPolyMatrix(Matrix<Poly<T>>\
    \ &m, ll K) {\n    using Mat = Matrix<T>;\n\n    int n = m.val.size();\n    int\
    \ deg = 1;\n    rep(i, 0, n) rep(j, 0, n) chmax(deg, (int)m[i][j].size() - 1);\n\
    \    ll SQ = 1;\n    while (SQ * SQ * deg < K)\n        SQ <<= 1;\n    T iSQ =\
    \ T(SQ).inv();\n\n    vector<Mat> G(deg + 1);\n    rep(k, 0, deg + 1) {\n    \
    \    G[k] = Mat(n, n);\n        rep(i, 0, n) rep(j, 0, n) G[k][i][j] = m[i][j].eval(SQ\
    \ * k);\n    }\n\n    auto process = [&](vector<Mat> &base, T x) -> vector<Mat>\
    \ {\n        int D = base.size();\n        vector ret(D, Mat(n, n));\n       \
    \ rep(i, 0, n) rep(j, 0, n) {\n            vector<T> val(D);\n            rep(k,\
    \ 0, D) val[k] = base[k][i][j];\n            auto add = SamplePointsShift<T>(val,\
    \ x);\n            rep(k, 0, D) ret[k][i][j] = add[k];\n        }\n        return\
    \ ret;\n    };\n\n    for (ll w = 1; w < SQ; w <<= 1) {\n        auto G1 = process(G,\
    \ iSQ * w);\n        auto G2 = process(G, w * deg + 1);\n        auto G3 = process(G,\
    \ iSQ * w + w * deg + 1);\n        rep(i, 0, w * deg + 1) G1[i] *= G[i], G3[i]\
    \ *= G2[i];\n        G1.insert(G1.end(), ALL(G3));\n        G1.pop_back();\n \
    \       swap(G, G1);\n    }\n\n    Mat ret(n, n);\n    rep(i, 0, n) ret[i][i]\
    \ = 1;\n    ll k = 0;\n    while (k * SQ + SQ <= K)\n        ret = G[k++] * ret;\n\
    \    k *= SQ;\n    while (k < K) {\n        Mat mul(n, n);\n        rep(i, 0,\
    \ n) rep(j, 0, n) mul[i][j] = m[i][j].eval(k);\n        ret = mul * ret;\n   \
    \     k++;\n    }\n    return ret;\n}\n\n// a_{n+i}*f_n(i)+...+a_i*f_0(i)=0\n\
    // {f_r}:dec order!!!\ntemplate <typename T> vector<Poly<T>> FindPRecursive(vector<T>\
    \ &a, int d) {\n    int n = a.size();\n    int k = (n + 2) / (d + 2) - 1;\n  \
    \  if (k <= 0)\n        return {};\n    int m = (d + 1) * (k + 1);\n    Matrix<T>\
    \ mat(m - 1, m);\n    rep(i, 0, m - 1) rep(j, 0, k + 1) {\n        T base = 1;\n\
    \        rep(deg, 0, d + 1) {\n            mat[i][(d + 1) * j + deg] = a[i + j]\
    \ * base;\n            base *= (i + j);\n        }\n    }\n    auto basis = LinearEquation(mat,\
    \ vector<T>(m - 1)).second;\n    if (basis.val.empty())\n        return {};\n\
    \    auto c = basis[0];\n    vector<Poly<T>> ret;\n    for (int i = 0; i * (d\
    \ + 1) < (int)c.size(); i++) {\n        Poly<T> add, base({T(i), T(1)});\n   \
    \     for (int j = d; j >= 0; j--) {\n            add *= base;\n            if\
    \ (c[i * (d + 1) + j] != 0)\n                add += c[i * (d + 1) + j];\n    \
    \    }\n        ret.push_back(add);\n    }\n    while (ret.back().empty())\n \
    \       ret.pop_back();\n    reverse(ALL(ret));\n    return ret;\n}\n\ntemplate\
    \ <typename T>\nT KthtermOfPRecursive(vector<T> &a, vector<Poly<T>> &fs, ll k)\
    \ {\n    int n = fs.size() - 1;\n    assert(int(a.size()) >= n);\n    if (k <\
    \ int(a.size()))\n        return a[k];\n\n    Matrix<Poly<T>> m(n), den(1);\n\
    \    Matrix<T> base(n);\n    rep(i, 0, n) m[0][i] = -fs[i + 1];\n    rep(i, 1,\
    \ n) m[i][i - 1] = fs[0];\n    den[0][0] = fs[0];\n    rep(i, 0, n) base[i][0]\
    \ = a[n - 1 - i];\n    T ret = (PrefixProdOfPolyMatrix(m, k - n + 1) * base)[0][0];\n\
    \    ret /= PrefixProdOfPolyMatrix(den, k - n + 1)[0][0];\n    return ret;\n}\n\
    \ntemplate <typename T> T KthtermEsper(vector<T> &a, ll k) {\n    if (k < (int)a.size())\n\
    \        return a[k];\n    int n = a.size() - 1;\n    vector<Fp> b = a;\n    b.pop_back();\n\
    \n    for (int d = 0;; d++) {\n        if ((n + 2) / (d + 2) <= 1)\n         \
    \   break;\n        auto fs = FindPRecursive(b, d);\n        if (KthtermOfPRecursive(b,\
    \ fs, n) == a.back()) {\n            show(fs);\n            return KthtermOfPRecursive(a,\
    \ fs, k);\n        }\n    }\n    cerr << \"esper Failed\" << '\\n';\n    assert(0);\n\
    }\n\n/**\n * @brief P-recursive\n */\n"
  code: "#pragma once\n#include \"FPS/samplepointshift.hpp\"\n#include \"Math/matrix.hpp\"\
    \n#include \"Math/linearequation.hpp\"\n\ntemplate <typename T>\nMatrix<T> PrefixProdOfPolyMatrix(Matrix<Poly<T>>\
    \ &m, ll K) {\n    using Mat = Matrix<T>;\n\n    int n = m.val.size();\n    int\
    \ deg = 1;\n    rep(i, 0, n) rep(j, 0, n) chmax(deg, (int)m[i][j].size() - 1);\n\
    \    ll SQ = 1;\n    while (SQ * SQ * deg < K)\n        SQ <<= 1;\n    T iSQ =\
    \ T(SQ).inv();\n\n    vector<Mat> G(deg + 1);\n    rep(k, 0, deg + 1) {\n    \
    \    G[k] = Mat(n, n);\n        rep(i, 0, n) rep(j, 0, n) G[k][i][j] = m[i][j].eval(SQ\
    \ * k);\n    }\n\n    auto process = [&](vector<Mat> &base, T x) -> vector<Mat>\
    \ {\n        int D = base.size();\n        vector ret(D, Mat(n, n));\n       \
    \ rep(i, 0, n) rep(j, 0, n) {\n            vector<T> val(D);\n            rep(k,\
    \ 0, D) val[k] = base[k][i][j];\n            auto add = SamplePointsShift<T>(val,\
    \ x);\n            rep(k, 0, D) ret[k][i][j] = add[k];\n        }\n        return\
    \ ret;\n    };\n\n    for (ll w = 1; w < SQ; w <<= 1) {\n        auto G1 = process(G,\
    \ iSQ * w);\n        auto G2 = process(G, w * deg + 1);\n        auto G3 = process(G,\
    \ iSQ * w + w * deg + 1);\n        rep(i, 0, w * deg + 1) G1[i] *= G[i], G3[i]\
    \ *= G2[i];\n        G1.insert(G1.end(), ALL(G3));\n        G1.pop_back();\n \
    \       swap(G, G1);\n    }\n\n    Mat ret(n, n);\n    rep(i, 0, n) ret[i][i]\
    \ = 1;\n    ll k = 0;\n    while (k * SQ + SQ <= K)\n        ret = G[k++] * ret;\n\
    \    k *= SQ;\n    while (k < K) {\n        Mat mul(n, n);\n        rep(i, 0,\
    \ n) rep(j, 0, n) mul[i][j] = m[i][j].eval(k);\n        ret = mul * ret;\n   \
    \     k++;\n    }\n    return ret;\n}\n\n// a_{n+i}*f_n(i)+...+a_i*f_0(i)=0\n\
    // {f_r}:dec order!!!\ntemplate <typename T> vector<Poly<T>> FindPRecursive(vector<T>\
    \ &a, int d) {\n    int n = a.size();\n    int k = (n + 2) / (d + 2) - 1;\n  \
    \  if (k <= 0)\n        return {};\n    int m = (d + 1) * (k + 1);\n    Matrix<T>\
    \ mat(m - 1, m);\n    rep(i, 0, m - 1) rep(j, 0, k + 1) {\n        T base = 1;\n\
    \        rep(deg, 0, d + 1) {\n            mat[i][(d + 1) * j + deg] = a[i + j]\
    \ * base;\n            base *= (i + j);\n        }\n    }\n    auto basis = LinearEquation(mat,\
    \ vector<T>(m - 1)).second;\n    if (basis.val.empty())\n        return {};\n\
    \    auto c = basis[0];\n    vector<Poly<T>> ret;\n    for (int i = 0; i * (d\
    \ + 1) < (int)c.size(); i++) {\n        Poly<T> add, base({T(i), T(1)});\n   \
    \     for (int j = d; j >= 0; j--) {\n            add *= base;\n            if\
    \ (c[i * (d + 1) + j] != 0)\n                add += c[i * (d + 1) + j];\n    \
    \    }\n        ret.push_back(add);\n    }\n    while (ret.back().empty())\n \
    \       ret.pop_back();\n    reverse(ALL(ret));\n    return ret;\n}\n\ntemplate\
    \ <typename T>\nT KthtermOfPRecursive(vector<T> &a, vector<Poly<T>> &fs, ll k)\
    \ {\n    int n = fs.size() - 1;\n    assert(int(a.size()) >= n);\n    if (k <\
    \ int(a.size()))\n        return a[k];\n\n    Matrix<Poly<T>> m(n), den(1);\n\
    \    Matrix<T> base(n);\n    rep(i, 0, n) m[0][i] = -fs[i + 1];\n    rep(i, 1,\
    \ n) m[i][i - 1] = fs[0];\n    den[0][0] = fs[0];\n    rep(i, 0, n) base[i][0]\
    \ = a[n - 1 - i];\n    T ret = (PrefixProdOfPolyMatrix(m, k - n + 1) * base)[0][0];\n\
    \    ret /= PrefixProdOfPolyMatrix(den, k - n + 1)[0][0];\n    return ret;\n}\n\
    \ntemplate <typename T> T KthtermEsper(vector<T> &a, ll k) {\n    if (k < (int)a.size())\n\
    \        return a[k];\n    int n = a.size() - 1;\n    vector<Fp> b = a;\n    b.pop_back();\n\
    \n    for (int d = 0;; d++) {\n        if ((n + 2) / (d + 2) <= 1)\n         \
    \   break;\n        auto fs = FindPRecursive(b, d);\n        if (KthtermOfPRecursive(b,\
    \ fs, n) == a.back()) {\n            show(fs);\n            return KthtermOfPRecursive(a,\
    \ fs, k);\n        }\n    }\n    cerr << \"esper Failed\" << '\\n';\n    assert(0);\n\
    }\n\n/**\n * @brief P-recursive\n */"
  dependsOn:
  - FPS/samplepointshift.hpp
  - Math/comb.hpp
  - Math/matrix.hpp
  - Math/linearequation.hpp
  isVerificationFile: false
  path: FPS/p-recursive.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/p-recursive.hpp
layout: document
redirect_from:
- /library/FPS/p-recursive.hpp
- /library/FPS/p-recursive.hpp.html
title: P-recursive
---
