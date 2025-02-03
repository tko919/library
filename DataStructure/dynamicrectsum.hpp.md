---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: DataStructure/staticrectsum.hpp
    title: Static Rectangle Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dynamic Point Add Rectangle Sum
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
    \ Rectangle Sum\n */\n#line 3 \"DataStructure/dynamicrectsum.hpp\"\n\ntemplate\
    \ <typename XY, typename T> struct DynamicPointAddRectangleSum {\n    using Point\
    \ = tuple<XY, XY, T>;\n    using Query = tuple<XY, XY, XY, XY>;\n    vector<variant<Point,\
    \ Query>> que;\n    DynamicPointAddRectangleSum() {}\n    void add(XY x, XY y,\
    \ T w) {\n        que.push_back(Point{x, y, w});\n    }\n    void query(XY L,\
    \ XY D, XY R, XY U) {\n        que.push_back(Query{L, D, R, U});\n    }\n    vector<T>\
    \ run() {\n        int Q = SZ(que);\n        vector<int> isq(Q);\n        vector<int>\
    \ pos(Q);\n        int ptr = 0;\n        rep(i, 0, Q) if (holds_alternative<Query>(que[i]))\
    \ {\n            isq[i] = 1;\n            pos[i] = ptr++;\n        }\n       \
    \ vector<T> ret(ptr);\n        auto rec = [&](auto &rec, int L, int R) -> void\
    \ {\n            if (L + 1 >= R)\n                return;\n            int mid\
    \ = (L + R) >> 1;\n            rec(rec, L, mid);\n            rec(rec, mid, R);\n\
    \            StaticRectangleSum<XY, T> buf;\n            rep(k, L, mid) if (!isq[k])\
    \ {\n                XY x, y;\n                T w;\n                tie(x, y,\
    \ w) = get<Point>(que[k]);\n                buf.add(x, y, w);\n            }\n\
    \            rep(k, mid, R) if (isq[k]) {\n                XY L, D, R, U;\n  \
    \              tie(L, D, R, U) = get<Query>(que[k]);\n                buf.query(L,\
    \ D, R, U);\n            }\n            auto sub = buf.run();\n            ptr\
    \ = 0;\n            rep(k, mid, R) if (isq[k]) {\n                ret[pos[k]]\
    \ += sub[ptr++];\n            }\n        };\n        rec(rec, 0, Q);\n       \
    \ return ret;\n    }\n};\n\n/**\n * @brief Dynamic Point Add Rectangle Sum\n */\n"
  code: "#pragma once\n#include \"DataStructure/staticrectsum.hpp\"\n\ntemplate <typename\
    \ XY, typename T> struct DynamicPointAddRectangleSum {\n    using Point = tuple<XY,\
    \ XY, T>;\n    using Query = tuple<XY, XY, XY, XY>;\n    vector<variant<Point,\
    \ Query>> que;\n    DynamicPointAddRectangleSum() {}\n    void add(XY x, XY y,\
    \ T w) {\n        que.push_back(Point{x, y, w});\n    }\n    void query(XY L,\
    \ XY D, XY R, XY U) {\n        que.push_back(Query{L, D, R, U});\n    }\n    vector<T>\
    \ run() {\n        int Q = SZ(que);\n        vector<int> isq(Q);\n        vector<int>\
    \ pos(Q);\n        int ptr = 0;\n        rep(i, 0, Q) if (holds_alternative<Query>(que[i]))\
    \ {\n            isq[i] = 1;\n            pos[i] = ptr++;\n        }\n       \
    \ vector<T> ret(ptr);\n        auto rec = [&](auto &rec, int L, int R) -> void\
    \ {\n            if (L + 1 >= R)\n                return;\n            int mid\
    \ = (L + R) >> 1;\n            rec(rec, L, mid);\n            rec(rec, mid, R);\n\
    \            StaticRectangleSum<XY, T> buf;\n            rep(k, L, mid) if (!isq[k])\
    \ {\n                XY x, y;\n                T w;\n                tie(x, y,\
    \ w) = get<Point>(que[k]);\n                buf.add(x, y, w);\n            }\n\
    \            rep(k, mid, R) if (isq[k]) {\n                XY L, D, R, U;\n  \
    \              tie(L, D, R, U) = get<Query>(que[k]);\n                buf.query(L,\
    \ D, R, U);\n            }\n            auto sub = buf.run();\n            ptr\
    \ = 0;\n            rep(k, mid, R) if (isq[k]) {\n                ret[pos[k]]\
    \ += sub[ptr++];\n            }\n        };\n        rec(rec, 0, Q);\n       \
    \ return ret;\n    }\n};\n\n/**\n * @brief Dynamic Point Add Rectangle Sum\n */"
  dependsOn:
  - DataStructure/staticrectsum.hpp
  - DataStructure/bit.hpp
  isVerificationFile: false
  path: DataStructure/dynamicrectsum.hpp
  requiredBy: []
  timestamp: '2025-02-04 02:11:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/dynamicrectsum.hpp
layout: document
redirect_from:
- /library/DataStructure/dynamicrectsum.hpp
- /library/DataStructure/dynamicrectsum.hpp.html
title: Dynamic Point Add Rectangle Sum
---
