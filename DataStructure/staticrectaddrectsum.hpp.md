---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: DataStructure/staticrectsum.hpp
    title: Static Rectangle Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
    title: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Static Rectangle Add Rectangle Sum
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct\
    \ BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\
    \n    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\
    \n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
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
    \ d, u, i, 1});\n            qs.push_back({r, d, u, i, -1});\n        }\n    \
    \    sort(ALL(plus), [](P &p, P &q) { return p.x < q.x; });\n        sort(ALL(qs),\
    \ [](Q &p, Q &q) { return p.x < q.x; });\n        vector<T> res(q);\n        int\
    \ k = 0;\n        BIT<T> bit(ys.size());\n        for (auto &q : qs) {\n     \
    \       while (k < n and plus[k].x < q.x) {\n                bit.add(plus[k].y,\
    \ plus[k].w);\n                k++;\n            }\n            res[q.id] += bit.sum(q.u,\
    \ q.d) * q.inv;\n        }\n        return res;\n    }\n};\n\n/**\n * @brief Static\
    \ Rectangle Sum\n */\n#line 3 \"DataStructure/staticrectaddrectsum.hpp\"\n\ntemplate\
    \ <typename XY, typename T> struct StaticRectangleAddRectangleSum {\n    StaticRectangleSum<XY,\
    \ T> bit[4]; // XY,X,Y,Const\n    struct Rect {\n        XY l, d, r, u;\n    };\n\
    \    vector<Rect> que;\n    StaticRectangleAddRectangleSum() {}\n    void add(XY\
    \ x, XY y, T w) {\n        bit[0].add(x, y, w);\n        bit[1].add(x, y, w *\
    \ -y);\n        bit[2].add(x, y, w * -x);\n        bit[3].add(x, y, w * x * y);\n\
    \    }\n    void add(XY l, XY d, XY r, XY u, T w) {\n        add(l, d, w);\n \
    \       add(l, u, -w);\n        add(r, d, -w);\n        add(r, u, w);\n    }\n\
    \    void query(XY l, XY d, XY r, XY u) {\n        que.push_back({l, d, r, u});\n\
    \    }\n    vector<T> run() {\n        int q = que.size();\n        for (auto\
    \ &[l, d, r, u] : que) {\n            rep(j, 0, 4) {\n                bit[j].query(0,\
    \ 0, l, d);\n                bit[j].query(0, 0, l, u);\n                bit[j].query(0,\
    \ 0, r, d);\n                bit[j].query(0, 0, r, u);\n            }\n      \
    \  }\n        auto both = bit[0].run();\n        auto X = bit[1].run();\n    \
    \    auto Y = bit[2].run();\n        auto Const = bit[3].run();\n        vector<T>\
    \ res(q);\n        rep(i, 0, q) {\n            auto [l, d, r, u] = que[i];\n \
    \           res[i] += both[4 * i] * l * d;\n            res[i] += X[4 * i] * l;\n\
    \            res[i] += Y[4 * i] * d;\n            res[i] += Const[4 * i];\n\n\
    \            res[i] -= both[4 * i + 1] * l * u;\n            res[i] -= X[4 * i\
    \ + 1] * l;\n            res[i] -= Y[4 * i + 1] * u;\n            res[i] -= Const[4\
    \ * i + 1];\n\n            res[i] -= both[4 * i + 2] * r * d;\n            res[i]\
    \ -= X[4 * i + 2] * r;\n            res[i] -= Y[4 * i + 2] * d;\n            res[i]\
    \ -= Const[4 * i + 2];\n\n            res[i] += both[4 * i + 3] * r * u;\n   \
    \         res[i] += X[4 * i + 3] * r;\n            res[i] += Y[4 * i + 3] * u;\n\
    \            res[i] += Const[4 * i + 3];\n        }\n        return res;\n   \
    \ }\n};\n\n/**\n * @brief Static Rectangle Add Rectangle Sum\n */\n"
  code: "#pragma once\n#include \"DataStructure/staticrectsum.hpp\"\n\ntemplate <typename\
    \ XY, typename T> struct StaticRectangleAddRectangleSum {\n    StaticRectangleSum<XY,\
    \ T> bit[4]; // XY,X,Y,Const\n    struct Rect {\n        XY l, d, r, u;\n    };\n\
    \    vector<Rect> que;\n    StaticRectangleAddRectangleSum() {}\n    void add(XY\
    \ x, XY y, T w) {\n        bit[0].add(x, y, w);\n        bit[1].add(x, y, w *\
    \ -y);\n        bit[2].add(x, y, w * -x);\n        bit[3].add(x, y, w * x * y);\n\
    \    }\n    void add(XY l, XY d, XY r, XY u, T w) {\n        add(l, d, w);\n \
    \       add(l, u, -w);\n        add(r, d, -w);\n        add(r, u, w);\n    }\n\
    \    void query(XY l, XY d, XY r, XY u) {\n        que.push_back({l, d, r, u});\n\
    \    }\n    vector<T> run() {\n        int q = que.size();\n        for (auto\
    \ &[l, d, r, u] : que) {\n            rep(j, 0, 4) {\n                bit[j].query(0,\
    \ 0, l, d);\n                bit[j].query(0, 0, l, u);\n                bit[j].query(0,\
    \ 0, r, d);\n                bit[j].query(0, 0, r, u);\n            }\n      \
    \  }\n        auto both = bit[0].run();\n        auto X = bit[1].run();\n    \
    \    auto Y = bit[2].run();\n        auto Const = bit[3].run();\n        vector<T>\
    \ res(q);\n        rep(i, 0, q) {\n            auto [l, d, r, u] = que[i];\n \
    \           res[i] += both[4 * i] * l * d;\n            res[i] += X[4 * i] * l;\n\
    \            res[i] += Y[4 * i] * d;\n            res[i] += Const[4 * i];\n\n\
    \            res[i] -= both[4 * i + 1] * l * u;\n            res[i] -= X[4 * i\
    \ + 1] * l;\n            res[i] -= Y[4 * i + 1] * u;\n            res[i] -= Const[4\
    \ * i + 1];\n\n            res[i] -= both[4 * i + 2] * r * d;\n            res[i]\
    \ -= X[4 * i + 2] * r;\n            res[i] -= Y[4 * i + 2] * d;\n            res[i]\
    \ -= Const[4 * i + 2];\n\n            res[i] += both[4 * i + 3] * r * u;\n   \
    \         res[i] += X[4 * i + 3] * r;\n            res[i] += Y[4 * i + 3] * u;\n\
    \            res[i] += Const[4 * i + 3];\n        }\n        return res;\n   \
    \ }\n};\n\n/**\n * @brief Static Rectangle Add Rectangle Sum\n */"
  dependsOn:
  - DataStructure/staticrectsum.hpp
  - DataStructure/bit.hpp
  isVerificationFile: false
  path: DataStructure/staticrectaddrectsum.hpp
  requiredBy: []
  timestamp: '2025-02-04 02:11:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
documentation_of: DataStructure/staticrectaddrectsum.hpp
layout: document
redirect_from:
- /library/DataStructure/staticrectaddrectsum.hpp
- /library/DataStructure/staticrectaddrectsum.hpp.html
title: Static Rectangle Add Rectangle Sum
---
