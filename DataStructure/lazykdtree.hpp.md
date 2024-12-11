---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Kd Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/lazykdtree.hpp\"\n\ntemplate <typename M,\
    \ typename N, M (*f)(M, M), M (*g)(M, N, int), N (*h)(N, N),\n          M (*m1)(),\
    \ N (*n1)()>\nclass LazyKdTree {\n    using P = pair<int, int>;\n    using T =\
    \ pair<pair<int, int>, pair<M, int>>; // {{x,y},{w,id}}\n    struct Node {\n \
    \       int L, R, D, U;\n        int sz;\n        M val;\n        N lazy;\n  \
    \      Node()\n            : L(inf), R(-inf), D(inf), U(-inf), sz(0), val(m1()),\
    \ lazy(n1()) {}\n        Node(P &p, M v)\n            : L(p.first), R(p.first),\
    \ D(p.second), U(p.second), val(v),\n              lazy(n1()) {}\n    };\n\n \
    \   int n, height;\n    vector<Node> data;\n    vector<int> pos;\n    void update(int\
    \ k) {\n        data[k].sz += data[k * 2].sz + data[k * 2 + 1].sz;\n        data[k].L\
    \ = min(data[k * 2].L, data[k * 2 + 1].L);\n        data[k].R = max(data[k * 2].R,\
    \ data[k * 2 + 1].R);\n        data[k].D = min(data[k * 2].D, data[k * 2 + 1].D);\n\
    \        data[k].U = max(data[k * 2].U, data[k * 2 + 1].U);\n        data[k].val\
    \ = f(data[k * 2].val, data[k * 2 + 1].val);\n    }\n    void apply(int k, N x)\
    \ {\n        data[k].val = g(data[k].val, x, data[k].sz);\n        data[k].lazy\
    \ = h(data[k].lazy, x);\n    }\n    void down(int k) {\n        apply(k * 2, data[k].lazy);\n\
    \        apply(k * 2 + 1, data[k].lazy);\n        data[k].lazy = n1();\n    }\n\
    \    void build(vector<T> &ps, int L, int R, bool dir) {\n        if (R - L ==\
    \ 1) {\n            data[n + L] = Node(ps[L].first, ps[L].second.first);\n   \
    \         if (ps[L].second.second != n)\n                pos[ps[L].second.second]\
    \ = L;\n            return;\n        }\n        int mid = (L + R) >> 1;\n    \
    \    if (dir) {\n            nth_element(ps.begin() + L, ps.begin() + mid, ps.begin()\
    \ + R,\n                        [&](const auto &a, const auto &b) {\n        \
    \                    return a.first.first < b.first.first;\n                 \
    \       });\n        } else {\n            nth_element(ps.begin() + L, ps.begin()\
    \ + mid, ps.begin() + R,\n                        [&](const auto &a, const auto\
    \ &b) {\n                            return a.first.second < b.first.second;\n\
    \                        });\n        }\n        build(ps, L, mid, !dir);\n  \
    \      build(ps, mid, R, !dir);\n    }\n\n  public:\n    LazyKdTree() {}\n   \
    \ LazyKdTree(const vector<int> &xs, const vector<int> &ys,\n               const\
    \ vector<M> &ws) {\n        height = 0;\n        while ((1 << height) < SZ(xs))\n\
    \            height++;\n        n = 1 << height;\n        data.resize(n * 2);\n\
    \        vector<T> ps(n, {{inf, inf}, {m1(), n}});\n        rep(i, 0, SZ(xs))\
    \ {\n            ps[i] = T{{xs[i], ys[i]}, {ws[i], i}};\n        }\n        pos.resize(n,\
    \ -1);\n        build(ps, 0, n, 0);\n        rrep(i, 1, n) update(i);\n    }\n\
    \    void set(int k, M x) {\n        k = n + pos[k];\n        rrep(i, 1, height\
    \ + 1) down(k >> i);\n        data[k].val = x;\n        rep(i, 1, height + 1)\
    \ update(k >> i);\n    }\n    void update(int L, int R, int D, int U, N x, int\
    \ k = 1) {\n        if (data[k].R < L or R <= data[k].L or data[k].U < D or U\
    \ <= data[k].D)\n            return;\n        if (L <= data[k].L and data[k].R\
    \ < R and D <= data[k].D and\n            data[k].U < U) {\n            apply(k,\
    \ x);\n            return;\n        }\n        down(k);\n        update(L, R,\
    \ D, U, x, k * 2);\n        update(L, R, D, U, x, k * 2 + 1);\n        update(k);\n\
    \    }\n    M query(int L, int R, int D, int U, int k = 1) {\n        if (data[k].R\
    \ < L or R <= data[k].L or data[k].U < D or U <= data[k].D)\n            return\
    \ m1();\n        if (L <= data[k].L and data[k].R < R and D <= data[k].D and\n\
    \            data[k].U < U) {\n            return data[k].val;\n        }\n  \
    \      down(k);\n        return f(query(L, R, D, U, k * 2), query(L, R, D, U,\
    \ k * 2 + 1));\n    }\n};\n\n/**\n * @brief Kd Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename M, typename N, M (*f)(M, M), M (*g)(M,\
    \ N, int), N (*h)(N, N),\n          M (*m1)(), N (*n1)()>\nclass LazyKdTree {\n\
    \    using P = pair<int, int>;\n    using T = pair<pair<int, int>, pair<M, int>>;\
    \ // {{x,y},{w,id}}\n    struct Node {\n        int L, R, D, U;\n        int sz;\n\
    \        M val;\n        N lazy;\n        Node()\n            : L(inf), R(-inf),\
    \ D(inf), U(-inf), sz(0), val(m1()), lazy(n1()) {}\n        Node(P &p, M v)\n\
    \            : L(p.first), R(p.first), D(p.second), U(p.second), val(v),\n   \
    \           lazy(n1()) {}\n    };\n\n    int n, height;\n    vector<Node> data;\n\
    \    vector<int> pos;\n    void update(int k) {\n        data[k].sz += data[k\
    \ * 2].sz + data[k * 2 + 1].sz;\n        data[k].L = min(data[k * 2].L, data[k\
    \ * 2 + 1].L);\n        data[k].R = max(data[k * 2].R, data[k * 2 + 1].R);\n \
    \       data[k].D = min(data[k * 2].D, data[k * 2 + 1].D);\n        data[k].U\
    \ = max(data[k * 2].U, data[k * 2 + 1].U);\n        data[k].val = f(data[k * 2].val,\
    \ data[k * 2 + 1].val);\n    }\n    void apply(int k, N x) {\n        data[k].val\
    \ = g(data[k].val, x, data[k].sz);\n        data[k].lazy = h(data[k].lazy, x);\n\
    \    }\n    void down(int k) {\n        apply(k * 2, data[k].lazy);\n        apply(k\
    \ * 2 + 1, data[k].lazy);\n        data[k].lazy = n1();\n    }\n    void build(vector<T>\
    \ &ps, int L, int R, bool dir) {\n        if (R - L == 1) {\n            data[n\
    \ + L] = Node(ps[L].first, ps[L].second.first);\n            if (ps[L].second.second\
    \ != n)\n                pos[ps[L].second.second] = L;\n            return;\n\
    \        }\n        int mid = (L + R) >> 1;\n        if (dir) {\n            nth_element(ps.begin()\
    \ + L, ps.begin() + mid, ps.begin() + R,\n                        [&](const auto\
    \ &a, const auto &b) {\n                            return a.first.first < b.first.first;\n\
    \                        });\n        } else {\n            nth_element(ps.begin()\
    \ + L, ps.begin() + mid, ps.begin() + R,\n                        [&](const auto\
    \ &a, const auto &b) {\n                            return a.first.second < b.first.second;\n\
    \                        });\n        }\n        build(ps, L, mid, !dir);\n  \
    \      build(ps, mid, R, !dir);\n    }\n\n  public:\n    LazyKdTree() {}\n   \
    \ LazyKdTree(const vector<int> &xs, const vector<int> &ys,\n               const\
    \ vector<M> &ws) {\n        height = 0;\n        while ((1 << height) < SZ(xs))\n\
    \            height++;\n        n = 1 << height;\n        data.resize(n * 2);\n\
    \        vector<T> ps(n, {{inf, inf}, {m1(), n}});\n        rep(i, 0, SZ(xs))\
    \ {\n            ps[i] = T{{xs[i], ys[i]}, {ws[i], i}};\n        }\n        pos.resize(n,\
    \ -1);\n        build(ps, 0, n, 0);\n        rrep(i, 1, n) update(i);\n    }\n\
    \    void set(int k, M x) {\n        k = n + pos[k];\n        rrep(i, 1, height\
    \ + 1) down(k >> i);\n        data[k].val = x;\n        rep(i, 1, height + 1)\
    \ update(k >> i);\n    }\n    void update(int L, int R, int D, int U, N x, int\
    \ k = 1) {\n        if (data[k].R < L or R <= data[k].L or data[k].U < D or U\
    \ <= data[k].D)\n            return;\n        if (L <= data[k].L and data[k].R\
    \ < R and D <= data[k].D and\n            data[k].U < U) {\n            apply(k,\
    \ x);\n            return;\n        }\n        down(k);\n        update(L, R,\
    \ D, U, x, k * 2);\n        update(L, R, D, U, x, k * 2 + 1);\n        update(k);\n\
    \    }\n    M query(int L, int R, int D, int U, int k = 1) {\n        if (data[k].R\
    \ < L or R <= data[k].L or data[k].U < D or U <= data[k].D)\n            return\
    \ m1();\n        if (L <= data[k].L and data[k].R < R and D <= data[k].D and\n\
    \            data[k].U < U) {\n            return data[k].val;\n        }\n  \
    \      down(k);\n        return f(query(L, R, D, U, k * 2), query(L, R, D, U,\
    \ k * 2 + 1));\n    }\n};\n\n/**\n * @brief Kd Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/lazykdtree.hpp
  requiredBy: []
  timestamp: '2024-12-12 04:28:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/lazykdtree.hpp
layout: document
redirect_from:
- /library/DataStructure/lazykdtree.hpp
- /library/DataStructure/lazykdtree.hpp.html
title: Kd Tree
---
