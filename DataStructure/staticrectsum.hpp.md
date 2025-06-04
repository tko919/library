---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/dynamicrectsum.hpp
    title: Dynamic Point Add Rectangle Sum
  - icon: ':x:'
    path: DataStructure/staticrectaddrectsum.hpp
    title: Static Rectangle Add Rectangle Sum
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
    title: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Static Rectangle Sum
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate <typename T> struct\
    \ BIT {\r\n    int n;\r\n    T all = 0;\r\n    vector<T> val;\r\n    BIT(int _n\
    \ = 0) : n(_n), val(_n + 10) {}\r\n    void clear() {\r\n        val.assign(n\
    \ + 10, 0);\r\n        all = T();\r\n    }\r\n    void add(int i, T x) {\r\n \
    \       for (i++; i <= n; i += (i & -i))\r\n            val[i] = val[i] + x;\r\
    \n        all += x;\r\n    }\r\n    T sum(int i) {\r\n        i = clamp(i, 0,\
    \ n);\r\n        T res = 0;\r\n        for (; i; i -= (i & -i))\r\n          \
    \  res += val[i];\r\n        return res;\r\n    }\r\n    // [L,R)\r\n    T sum(int\
    \ L, int R) {\r\n        if (L > R)\r\n            return T(0);\r\n        return\
    \ sum(R) - sum(L);\r\n    }\r\n    int lower_bound(T x) {\r\n        int ret =\
    \ 0, len = 1;\r\n        while (2 * len <= n)\r\n            len <<= 1;\r\n  \
    \      for (; len >= 1; len >>= 1) {\r\n            if (ret + len <= n and val[ret\
    \ + len] < x) {\r\n                ret += len;\r\n                x -= val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 3 \"DataStructure/staticrectsum.hpp\"\
    \n\ntemplate <typename XY, typename T> struct StaticRectangleSum {\n    struct\
    \ P {\n        XY x, y;\n        T w;\n    };\n    struct Rect {\n        XY l,\
    \ d, r, u;\n    };\n    struct Q {\n        XY x, d, u;\n        int id, inv;\n\
    \    };\n    vector<P> plus;\n    vector<Rect> que;\n    StaticRectangleSum()\
    \ {}\n    void add(XY x, XY y, T w) {\n        plus.push_back({x, y, w});\n  \
    \  }\n    void query(XY l, XY d, XY r, XY u) {\n        que.push_back({l, d, r,\
    \ u});\n    }\n    vector<T> run() {\n        ll n = plus.size(), q = que.size();\n\
    \        sort(ALL(plus), [](P &p, P &q) { return p.y < q.y; });\n        vector<XY>\
    \ ys;\n        rep(i, 0, n) ys.push_back(plus[i].y);\n        ys.erase(unique(ALL(ys)),\
    \ ys.end());\n        rep(i, 0, n) plus[i].y = lower_bound(ALL(ys), plus[i].y)\
    \ - ys.begin();\n        vector<Q> qs;\n        rep(i, 0, q) {\n            auto\
    \ &[l, d, r, u] = que[i];\n            d = lower_bound(ALL(ys), d) - ys.begin();\n\
    \            u = lower_bound(ALL(ys), u) - ys.begin();\n            qs.push_back({l,\
    \ d, u, i, -1});\n            qs.push_back({r, d, u, i, 1});\n        }\n    \
    \    sort(ALL(plus), [](P &p, P &q) { return p.x < q.x; });\n        sort(ALL(qs),\
    \ [](Q &p, Q &q) { return p.x < q.x; });\n        vector<T> res(q);\n        int\
    \ k = 0;\n        BIT<T> bit(ys.size());\n        for (auto &q : qs) {\n     \
    \       while (k < n and plus[k].x < q.x) {\n                bit.add(plus[k].y,\
    \ plus[k].w);\n                k++;\n            }\n            res[q.id] += bit.sum(q.d,\
    \ q.u) * q.inv;\n        }\n        return res;\n    }\n};\n\n/**\n * @brief Static\
    \ Rectangle Sum\n */\n"
  code: "#pragma once\n#include \"DataStructure/bit.hpp\"\n\ntemplate <typename XY,\
    \ typename T> struct StaticRectangleSum {\n    struct P {\n        XY x, y;\n\
    \        T w;\n    };\n    struct Rect {\n        XY l, d, r, u;\n    };\n   \
    \ struct Q {\n        XY x, d, u;\n        int id, inv;\n    };\n    vector<P>\
    \ plus;\n    vector<Rect> que;\n    StaticRectangleSum() {}\n    void add(XY x,\
    \ XY y, T w) {\n        plus.push_back({x, y, w});\n    }\n    void query(XY l,\
    \ XY d, XY r, XY u) {\n        que.push_back({l, d, r, u});\n    }\n    vector<T>\
    \ run() {\n        ll n = plus.size(), q = que.size();\n        sort(ALL(plus),\
    \ [](P &p, P &q) { return p.y < q.y; });\n        vector<XY> ys;\n        rep(i,\
    \ 0, n) ys.push_back(plus[i].y);\n        ys.erase(unique(ALL(ys)), ys.end());\n\
    \        rep(i, 0, n) plus[i].y = lower_bound(ALL(ys), plus[i].y) - ys.begin();\n\
    \        vector<Q> qs;\n        rep(i, 0, q) {\n            auto &[l, d, r, u]\
    \ = que[i];\n            d = lower_bound(ALL(ys), d) - ys.begin();\n         \
    \   u = lower_bound(ALL(ys), u) - ys.begin();\n            qs.push_back({l, d,\
    \ u, i, -1});\n            qs.push_back({r, d, u, i, 1});\n        }\n       \
    \ sort(ALL(plus), [](P &p, P &q) { return p.x < q.x; });\n        sort(ALL(qs),\
    \ [](Q &p, Q &q) { return p.x < q.x; });\n        vector<T> res(q);\n        int\
    \ k = 0;\n        BIT<T> bit(ys.size());\n        for (auto &q : qs) {\n     \
    \       while (k < n and plus[k].x < q.x) {\n                bit.add(plus[k].y,\
    \ plus[k].w);\n                k++;\n            }\n            res[q.id] += bit.sum(q.d,\
    \ q.u) * q.inv;\n        }\n        return res;\n    }\n};\n\n/**\n * @brief Static\
    \ Rectangle Sum\n */"
  dependsOn:
  - DataStructure/bit.hpp
  isVerificationFile: false
  path: DataStructure/staticrectsum.hpp
  requiredBy:
  - DataStructure/staticrectaddrectsum.hpp
  - DataStructure/dynamicrectsum.hpp
  timestamp: '2025-05-11 13:37:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
documentation_of: DataStructure/staticrectsum.hpp
layout: document
redirect_from:
- /library/DataStructure/staticrectsum.hpp
- /library/DataStructure/staticrectsum.hpp.html
title: Static Rectangle Sum
---
