---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/charpoly.hpp
    title: Characteristic Polynomial
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: $\det(A+Bx)$
    links: []
  bundledCode: "#line 2 \"Math/matrix.hpp\"\n\r\ntemplate <class T> struct Matrix\
    \ {\r\n    int h, w;\r\n    vector<vector<T>> val;\r\n    T det;\r\n    Matrix()\
    \ {}\r\n    Matrix(int n) : h(n), w(n), val(vector<vector<T>>(n, vector<T>(n)))\
    \ {}\r\n    Matrix(int n, int m)\r\n        : h(n), w(m), val(vector<vector<T>>(n,\
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
    \ */\n#line 3 \"Math/charpoly.hpp\"\n\ntemplate<typename T>vector<T> CharPoly(Matrix<T>\
    \ a){\n    // to Hessenberg\n    //reference:http://www.oishi.info.waseda.ac.jp/~samukawa/eigvieta.pdf\n\
    \    int n=a.h;\n    rep(s,0,n-2){\n        rep(j,s+1,n)if(a[j][s]!=0){\n    \
    \        swap(a[j],a[s+1]);\n            rep(i,0,n)swap(a[i][j],a[i][s+1]);\n\
    \            break;\n        }\n        if(a[s+1][s]==0)continue;\n        T X=T(1)/a[s+1][s];\n\
    \        rep(i,s+2,n){\n            T base=a[i][s]*X;\n            rep(j,0,n)a[i][j]-=a[s+1][j]*base;\n\
    \            rep(j,0,n)a[j][s+1]+=a[j][i]*base;\n        }\n    }\n    vector\
    \ dp(n+1,vector<T>(n+1));\n    dp[0][0]=1;\n    rep(i,0,n){\n        rep(k,0,i+1){\n\
    \            dp[i+1][k+1]+=dp[i][k];\n            dp[i+1][k]-=dp[i][k]*a[i][i];\n\
    \        }\n        T prod=1;\n        for(int j=i-1;j>=0;j--){\n            prod*=a[j+1][j];\n\
    \            T base=prod*a[j][i];\n            rep(k,0,i+1)dp[i+1][k]-=dp[j][k]*base;\n\
    \        }\n    }\n    return dp[n];\n}\n\n/**\n * @brief Characteristic Polynomial\n\
    */\n#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random {\r\nmt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
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
    \ Random\r\n */\n#line 5 \"Math/detaplusbx.hpp\"\n\ntemplate<typename T>vector<T>\
    \ detApBx(Matrix<T> a,Matrix<T> b){\n    Random gen;\n    int n=a.h;\n    vector<T>\
    \ f(n+1);\n    T ran=gen.get();\n    rep(i,0,n)rep(j,0,n)a[i][j]-=b[i][j]*ran;\n\
    \    auto ainv=a.inv();\n    if(a.det==0)return f;\n    b*=ainv;\n    rep(i,0,n)rep(j,0,n)b[i][j]=-b[i][j];\n\
    \    f=CharPoly(b);\n    reverse(ALL(f));\n    for(auto& x:f)x*=a.det;\n    vector\
    \ C(n+1,vector<T>(n+1));\n    vector<T> pw(n+1,1);\n    rep(i,0,n+1){\n      \
    \  if(i)pw[i]=pw[i-1]*ran;\n        C[i][0]=C[i][i]=1;\n        rep(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];\n\
    \    }\n    vector<T> ret(n+1);\n    rep(i,0,n+1)rep(j,0,i+1)ret[j]+=f[i]*C[i][j]*pw[i-j];\n\
    \    return ret;\n}\n\n/**\n * @brief $\\det(A+Bx)$\n*/\n"
  code: "#pragma once\n#include \"Math/matrix.hpp\"\n#include \"Math/charpoly.hpp\"\
    \n#include \"Utility/random.hpp\"\n\ntemplate<typename T>vector<T> detApBx(Matrix<T>\
    \ a,Matrix<T> b){\n    Random gen;\n    int n=a.h;\n    vector<T> f(n+1);\n  \
    \  T ran=gen.get();\n    rep(i,0,n)rep(j,0,n)a[i][j]-=b[i][j]*ran;\n    auto ainv=a.inv();\n\
    \    if(a.det==0)return f;\n    b*=ainv;\n    rep(i,0,n)rep(j,0,n)b[i][j]=-b[i][j];\n\
    \    f=CharPoly(b);\n    reverse(ALL(f));\n    for(auto& x:f)x*=a.det;\n    vector\
    \ C(n+1,vector<T>(n+1));\n    vector<T> pw(n+1,1);\n    rep(i,0,n+1){\n      \
    \  if(i)pw[i]=pw[i-1]*ran;\n        C[i][0]=C[i][i]=1;\n        rep(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];\n\
    \    }\n    vector<T> ret(n+1);\n    rep(i,0,n+1)rep(j,0,i+1)ret[j]+=f[i]*C[i][j]*pw[i-j];\n\
    \    return ret;\n}\n\n/**\n * @brief $\\det(A+Bx)$\n*/"
  dependsOn:
  - Math/matrix.hpp
  - Math/charpoly.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/detaplusbx.hpp
  requiredBy: []
  timestamp: '2024-06-14 02:46:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/detaplusbx.hpp
layout: document
redirect_from:
- /library/Math/detaplusbx.hpp
- /library/Math/detaplusbx.hpp.html
title: $\det(A+Bx)$
---
