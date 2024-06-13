---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/countspanning.hpp
    title: Counting Spanning Tree
  - icon: ':x:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Counting Eulerian Circuits
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
    \ */\n#line 3 \"Graph/countspanning.hpp\"\n\ntemplate <typename T, typename U>\n\
    T UndirectedCountSpanningTree(vector<vector<pair<int, U>>> &g) {\n    int n =\
    \ SZ(g);\n    Matrix<T> mat(n - 1, n - 1);\n    rep(u, 0, n) for (auto &[v, mul]\
    \ : g[u]) {\n        if (u != n - 1)\n            mat[u][u] += mul;\n        if\
    \ (v != n - 1)\n            mat[v][v] += mul;\n        if (u != n - 1 and v !=\
    \ n - 1) {\n            mat[u][v] -= mul;\n            mat[v][u] -= mul;\n   \
    \     }\n    }\n    mat.gauss();\n    return mat.det;\n}\n\ntemplate <typename\
    \ T, typename U>\nT DirectedCountSpanningTree(vector<vector<pair<int, U>>> &g,\
    \ int r) {\n    int n = SZ(g);\n    Matrix<T> mat(n - 1, n - 1);\n    rep(u, 0,\
    \ n) for (auto &[v, mul] : g[u]) {\n        if (v == r)\n            continue;\n\
    \        if (v > r)\n            v--;\n        mat[v][v] += mul;\n        if (u\
    \ == r)\n            continue;\n        if (u > r)\n            u--;\n       \
    \ mat[u][v] -= mul;\n    }\n    mat.gauss();\n    return mat.det;\n}\n\n/**\n\
    \ * @brief Counting Spanning Tree\n */\n#line 3 \"Graph/counteuler.hpp\"\n\ntemplate\
    \ <typename T, typename U>\nT CountEulerianCircuits(vector<vector<pair<int, U>>>\
    \ &g) {\n    int n = SZ(g);\n    vector<int> vs;\n    rep(u, 0, n) for (auto &[v,\
    \ _] : g[u]) {\n        vs.push_back(u);\n        vs.push_back(v);\n    }\n  \
    \  UNIQUE(vs);\n    vector<vector<pair<int, U>>> G(SZ(vs));\n    rep(u, 0, n)\
    \ for (auto &[v, mul] : g[u]) {\n        G[LB(vs, u)].push_back({LB(vs, v), mul});\n\
    \    }\n    n = SZ(vs);\n    vector<U> in(n), out(n);\n    rep(u, 0, n) for (auto\
    \ &[v, mul] : G[u]) {\n        in[u] += mul;\n        out[v] += mul;\n    }\n\
    \    rep(v, 0, n) if (in[v] != out[v]) {\n        return 0;\n    }\n    T ret\
    \ = DirectedCountSpanningTree<T>(G, n - 1);\n    rep(v, 0, n) ret *= Fact<T>(out[v]\
    \ - 1);\n    return ret;\n}\n\n/**\n * @brief Counting Eulerian Circuits\n */\n"
  code: "#pragma once\n#include \"Graph/countspanning.hpp\"\n\ntemplate <typename\
    \ T, typename U>\nT CountEulerianCircuits(vector<vector<pair<int, U>>> &g) {\n\
    \    int n = SZ(g);\n    vector<int> vs;\n    rep(u, 0, n) for (auto &[v, _] :\
    \ g[u]) {\n        vs.push_back(u);\n        vs.push_back(v);\n    }\n    UNIQUE(vs);\n\
    \    vector<vector<pair<int, U>>> G(SZ(vs));\n    rep(u, 0, n) for (auto &[v,\
    \ mul] : g[u]) {\n        G[LB(vs, u)].push_back({LB(vs, v), mul});\n    }\n \
    \   n = SZ(vs);\n    vector<U> in(n), out(n);\n    rep(u, 0, n) for (auto &[v,\
    \ mul] : G[u]) {\n        in[u] += mul;\n        out[v] += mul;\n    }\n    rep(v,\
    \ 0, n) if (in[v] != out[v]) {\n        return 0;\n    }\n    T ret = DirectedCountSpanningTree<T>(G,\
    \ n - 1);\n    rep(v, 0, n) ret *= Fact<T>(out[v] - 1);\n    return ret;\n}\n\n\
    /**\n * @brief Counting Eulerian Circuits\n */"
  dependsOn:
  - Graph/countspanning.hpp
  - Math/matrix.hpp
  isVerificationFile: false
  path: Graph/counteuler.hpp
  requiredBy: []
  timestamp: '2024-06-14 02:46:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/counteuler.hpp
layout: document
redirect_from:
- /library/Graph/counteuler.hpp
- /library/Graph/counteuler.hpp.html
title: Counting Eulerian Circuits
---
