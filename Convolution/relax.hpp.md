---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Relaxed Convolution
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
    \ + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 3 \"Convolution/relax.hpp\"\
    \n\r\ntemplate <typename T> class RelaxedConvolution {\r\n    using P = array<int,\
    \ 2>;\r\n    using Q = array<P, 2>;\r\n    int N, pos;\r\n    Poly<T> f, g, buf;\r\
    \n    vector<vector<Q>> event;\r\n    void dfs1(int L, int R) {\r\n        if\
    \ (R - L == 1) {\r\n            event[L].push_back({P{L, L + 1}, P{0, 1}});\r\n\
    \            return;\r\n        }\r\n        int mid = (L + R) >> 1;\r\n     \
    \   event[mid].push_back({P{L, mid}, P{mid - L, R - L}});\r\n        event[R].push_back({P{mid,\
    \ R}, P{mid - L, R - L}});\r\n        dfs1(L, mid);\r\n        dfs1(mid, R);\r\
    \n    }\r\n    void dfs2(int L, int R) {\r\n        if (R - L == 1) {\r\n    \
    \        event[L].push_back({P{0, 1}, P{L, L + 1}});\r\n            return;\r\n\
    \        }\r\n        int mid = (L + R) >> 1;\r\n        event[mid].push_back({P{mid\
    \ - L, R - L}, P{L, mid}});\r\n        event[R].push_back({P{mid - L, R - L},\
    \ P{mid, R}});\r\n        dfs2(L, mid);\r\n        dfs2(mid, R);\r\n    }\r\n\
    \    void dfs(int len) {\r\n        if (len == 1) {\r\n            event[0].push_back({P{0,\
    \ 1}, P{0, 1}});\r\n            return;\r\n        }\r\n        int mid = len\
    \ >> 1;\r\n        event[len].push_back({P{mid, len}, P{mid, len}});\r\n     \
    \   dfs(mid);\r\n        dfs1(mid, len);\r\n        dfs2(mid, len);\r\n    }\r\
    \n\r\n  public:\r\n    RelaxedConvolution(int n) {\r\n        N = 1, pos = 0;\r\
    \n        while (N < n)\r\n            N <<= 1;\r\n        f.resize(N);\r\n  \
    \      g.resize(N);\r\n        buf.resize(N);\r\n        event.resize(N + 1);\r\
    \n        dfs(N);\r\n    }\r\n    T next(T x, T y) {\r\n        f[pos] = x, g[pos]\
    \ = y;\r\n        for (auto &[ft, gt] : event[pos]) {\r\n            auto [fL,\
    \ fR] = ft;\r\n            auto [gL, gR] = gt;\r\n            Poly<T> _f({f.begin()\
    \ + fL, f.begin() + fR});\r\n            Poly<T> _g({g.begin() + gL, g.begin()\
    \ + gR});\r\n            auto add = _f * _g;\r\n            rep(i, 0, add.size())\
    \ {\r\n                if (i + fL + gL >= N)\r\n                    break;\r\n\
    \                buf[i + fL + gL] += add[i];\r\n            }\r\n        }\r\n\
    \        return buf[pos++];\r\n    }\r\n};\r\n\r\ntemplate <typename T> struct\
    \ RelaxedInv {\r\n    RelaxedInv() {}\r\n    RelaxedInv(int _n) : n(_n), pos(0),\
    \ g(n), buf(n) {}\r\n    T next(T x) {\r\n        if (pos == 0) {\r\n        \
    \    assert(x != 0);\r\n            g[pos] = x.inv();\r\n        } else {\r\n\
    \            g[pos] = -g[0] * buf.next(x, g[pos - 1]);\r\n        }\r\n      \
    \  return g[pos++];\r\n    }\r\n    T operator[](int i) const {\r\n        return\
    \ g[i];\r\n    }\r\n\r\n  private:\r\n    int n, pos;\r\n    vector<T> g;\r\n\
    \    RelaxedConvolution<T> buf;\r\n};\r\n\r\ntemplate <typename T> struct RelaxedExp\
    \ {\r\n    RelaxedExp() {}\r\n    RelaxedExp(int _n) : n(_n), pos(0), g(n), buf(n)\
    \ {}\r\n    T next(T x) {\r\n        if (pos == 0) {\r\n            assert(x ==\
    \ 0);\r\n            g[pos] = 1;\r\n        } else {\r\n            g[pos] = buf.next(x\
    \ * pos, g[pos - 1]) * Inv<T>(pos);\r\n        }\r\n        return g[pos++];\r\
    \n    }\r\n    T operator[](int i) const {\r\n        return g[i];\r\n    }\r\n\
    \r\n  private:\r\n    int n, pos;\r\n    vector<T> g;\r\n    RelaxedConvolution<T>\
    \ buf;\r\n};\r\n\r\ntemplate <typename T> struct RelaxedLog {\r\n    RelaxedLog()\
    \ {}\r\n    RelaxedLog(int _n) : n(_n), pos(0), g(n), buf(n), invf(n) {}\r\n \
    \   T next(T x) {\r\n        invf.next(x);\r\n        if (pos == 0) {\r\n    \
    \        assert(x == 1);\r\n            g[pos] = 0;\r\n        } else {\r\n  \
    \          g[pos] = buf.next(x * pos, invf[pos - 1]) * Inv<T>(pos);\r\n      \
    \  }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i) const {\r\
    \n        return g[i];\r\n    }\r\n\r\n  private:\r\n    int n, pos;\r\n    vector<T>\
    \ g;\r\n    RelaxedConvolution<T> buf;\r\n    RelaxedInv<T> invf;\r\n};\r\n\r\n\
    /**\r\n * @brief Relaxed Convolution\r\n */\n"
  code: "#pragma once\r\n#include \"Math/comb.hpp\"\r\n\r\ntemplate <typename T> class\
    \ RelaxedConvolution {\r\n    using P = array<int, 2>;\r\n    using Q = array<P,\
    \ 2>;\r\n    int N, pos;\r\n    Poly<T> f, g, buf;\r\n    vector<vector<Q>> event;\r\
    \n    void dfs1(int L, int R) {\r\n        if (R - L == 1) {\r\n            event[L].push_back({P{L,\
    \ L + 1}, P{0, 1}});\r\n            return;\r\n        }\r\n        int mid =\
    \ (L + R) >> 1;\r\n        event[mid].push_back({P{L, mid}, P{mid - L, R - L}});\r\
    \n        event[R].push_back({P{mid, R}, P{mid - L, R - L}});\r\n        dfs1(L,\
    \ mid);\r\n        dfs1(mid, R);\r\n    }\r\n    void dfs2(int L, int R) {\r\n\
    \        if (R - L == 1) {\r\n            event[L].push_back({P{0, 1}, P{L, L\
    \ + 1}});\r\n            return;\r\n        }\r\n        int mid = (L + R) >>\
    \ 1;\r\n        event[mid].push_back({P{mid - L, R - L}, P{L, mid}});\r\n    \
    \    event[R].push_back({P{mid - L, R - L}, P{mid, R}});\r\n        dfs2(L, mid);\r\
    \n        dfs2(mid, R);\r\n    }\r\n    void dfs(int len) {\r\n        if (len\
    \ == 1) {\r\n            event[0].push_back({P{0, 1}, P{0, 1}});\r\n         \
    \   return;\r\n        }\r\n        int mid = len >> 1;\r\n        event[len].push_back({P{mid,\
    \ len}, P{mid, len}});\r\n        dfs(mid);\r\n        dfs1(mid, len);\r\n   \
    \     dfs2(mid, len);\r\n    }\r\n\r\n  public:\r\n    RelaxedConvolution(int\
    \ n) {\r\n        N = 1, pos = 0;\r\n        while (N < n)\r\n            N <<=\
    \ 1;\r\n        f.resize(N);\r\n        g.resize(N);\r\n        buf.resize(N);\r\
    \n        event.resize(N + 1);\r\n        dfs(N);\r\n    }\r\n    T next(T x,\
    \ T y) {\r\n        f[pos] = x, g[pos] = y;\r\n        for (auto &[ft, gt] : event[pos])\
    \ {\r\n            auto [fL, fR] = ft;\r\n            auto [gL, gR] = gt;\r\n\
    \            Poly<T> _f({f.begin() + fL, f.begin() + fR});\r\n            Poly<T>\
    \ _g({g.begin() + gL, g.begin() + gR});\r\n            auto add = _f * _g;\r\n\
    \            rep(i, 0, add.size()) {\r\n                if (i + fL + gL >= N)\r\
    \n                    break;\r\n                buf[i + fL + gL] += add[i];\r\n\
    \            }\r\n        }\r\n        return buf[pos++];\r\n    }\r\n};\r\n\r\
    \ntemplate <typename T> struct RelaxedInv {\r\n    RelaxedInv() {}\r\n    RelaxedInv(int\
    \ _n) : n(_n), pos(0), g(n), buf(n) {}\r\n    T next(T x) {\r\n        if (pos\
    \ == 0) {\r\n            assert(x != 0);\r\n            g[pos] = x.inv();\r\n\
    \        } else {\r\n            g[pos] = -g[0] * buf.next(x, g[pos - 1]);\r\n\
    \        }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i) const\
    \ {\r\n        return g[i];\r\n    }\r\n\r\n  private:\r\n    int n, pos;\r\n\
    \    vector<T> g;\r\n    RelaxedConvolution<T> buf;\r\n};\r\n\r\ntemplate <typename\
    \ T> struct RelaxedExp {\r\n    RelaxedExp() {}\r\n    RelaxedExp(int _n) : n(_n),\
    \ pos(0), g(n), buf(n) {}\r\n    T next(T x) {\r\n        if (pos == 0) {\r\n\
    \            assert(x == 0);\r\n            g[pos] = 1;\r\n        } else {\r\n\
    \            g[pos] = buf.next(x * pos, g[pos - 1]) * Inv<T>(pos);\r\n       \
    \ }\r\n        return g[pos++];\r\n    }\r\n    T operator[](int i) const {\r\n\
    \        return g[i];\r\n    }\r\n\r\n  private:\r\n    int n, pos;\r\n    vector<T>\
    \ g;\r\n    RelaxedConvolution<T> buf;\r\n};\r\n\r\ntemplate <typename T> struct\
    \ RelaxedLog {\r\n    RelaxedLog() {}\r\n    RelaxedLog(int _n) : n(_n), pos(0),\
    \ g(n), buf(n), invf(n) {}\r\n    T next(T x) {\r\n        invf.next(x);\r\n \
    \       if (pos == 0) {\r\n            assert(x == 1);\r\n            g[pos] =\
    \ 0;\r\n        } else {\r\n            g[pos] = buf.next(x * pos, invf[pos -\
    \ 1]) * Inv<T>(pos);\r\n        }\r\n        return g[pos++];\r\n    }\r\n   \
    \ T operator[](int i) const {\r\n        return g[i];\r\n    }\r\n\r\n  private:\r\
    \n    int n, pos;\r\n    vector<T> g;\r\n    RelaxedConvolution<T> buf;\r\n  \
    \  RelaxedInv<T> invf;\r\n};\r\n\r\n/**\r\n * @brief Relaxed Convolution\r\n */"
  dependsOn:
  - Math/comb.hpp
  isVerificationFile: false
  path: Convolution/relax.hpp
  requiredBy: []
  timestamp: '2024-10-13 17:29:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_convolution_mod_2.test.cpp
documentation_of: Convolution/relax.hpp
layout: document
redirect_from:
- /library/Convolution/relax.hpp
- /library/Convolution/relax.hpp.html
title: Relaxed Convolution
---
