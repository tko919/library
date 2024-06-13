---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: DataStructure/2dsegtree.hpp
    title: 2D Segment Tree
  - icon: ':x:'
    path: DataStructure/sortablesegtree.hpp
    title: Sortable Segment Tree
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_point_add_rectangle_sum.test.cpp
    title: Verify/LC_point_add_rectangle_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_point_set_range_composite.test.cpp
    title: Verify/LC_point_set_range_composite.test.cpp
  - icon: ':x:'
    path: Verify/LC_point_set_range_sort_range_composite.test.cpp
    title: Verify/LC_point_set_range_sort_range_composite.test.cpp
  - icon: ':x:'
    path: Verify/LC_rectangle_sum.test.cpp
    title: Verify/LC_rectangle_sum.test.cpp
  - icon: ':x:'
    path: Verify/LC_staticrmq.test.cpp
    title: Verify/LC_staticrmq.test.cpp
  - icon: ':x:'
    path: Verify/LC_vertex_set_path_composite.test.cpp
    title: Verify/LC_vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate <typename M, typename\
    \ N, M (*f)(M, M), M (*g)(M, N), M (*m1)()>\r\nstruct SegmentTree {\r\n    int\
    \ n;\r\n    vector<M> data;\r\n    SegmentTree(int _n = 0) {\r\n        n = 1;\r\
    \n        while (n < _n)\r\n            n <<= 1;\r\n        data.assign(2 * n,\
    \ m1());\r\n    }\r\n    void run(vector<M> &v) {\r\n        for (int i = 0; i\
    \ < (int)v.size(); i++)\r\n            data[i + n] = v[i];\r\n        for (int\
    \ k = n - 1; k > 0; k--)\r\n            data[k] = f(data[2 * k], data[2 * k +\
    \ 1]);\r\n    }\r\n    void set(int k, const M &x) {\r\n        k += n;\r\n  \
    \      data[k] = x;\r\n        while (k >>= 1)\r\n            data[k] = f(data[2\
    \ * k], data[2 * k + 1]);\r\n    }\r\n    void update(int k, const N &x) {\r\n\
    \        k += n;\r\n        data[k] = g(data[k], x);\r\n        while (k >>= 1)\r\
    \n            data[k] = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    M query(int\
    \ a, int b) {\r\n        M L = m1(), R = m1();\r\n        for (a += n, b += n;\
    \ a < b; a >>= 1, b >>= 1) {\r\n            if (a & 1)\r\n                L =\
    \ f(L, data[a++]);\r\n            if (b & 1)\r\n                R = f(data[--b],\
    \ R);\r\n        }\r\n        return f(L, R);\r\n    }\r\n    M operator[](const\
    \ int &k) const {\r\n        return data[k + n];\r\n    }\r\n\r\n    template\
    \ <class F> int max_right(int L, F ch) const {\r\n        int l = n + L, w = 1;\r\
    \n        M ansL = m1();\r\n        for (; L + w <= n; l >>= 1, w <<= 1)\r\n \
    \           if (l & 1) {\r\n                if (not ch(f(ansL, data[l])))\r\n\
    \                    break;\r\n                ansL = f(ansL, data[l++]);\r\n\
    \                L += w;\r\n            }\r\n        while (l <<= 1, w >>= 1)\
    \ {\r\n            if (L + w <= n && ch(f(ansL, data[l]))) {\r\n             \
    \   ansL = f(ansL, data[l++]);\r\n                L += w;\r\n            }\r\n\
    \        }\r\n        return L;\r\n    }\r\n\r\n    template <class F> int min_left(int\
    \ R, F ch) const {\r\n        int r = n + R, w = 1;\r\n        M ansR = m1();\r\
    \n        for (; R - w >= 0; r >>= 1, w <<= 1)\r\n            if (r & 1) {\r\n\
    \                if (not ch(f(data[r - 1], ansR)))\r\n                    break;\r\
    \n                ansR = f(data[--r], ansR);\r\n                R -= w;\r\n  \
    \          }\r\n        while (r <<= 1, w >>= 1) {\r\n            if (R - w >=\
    \ 0 && ch(f(data[r - 1], ansR))) {\r\n                ansR = f(data[--r], ansR);\r\
    \n                R -= w;\r\n            }\r\n        }\r\n        return R;\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename M, typename N, M (*f)(M, M), M (*g)(M,\
    \ N), M (*m1)()>\r\nstruct SegmentTree {\r\n    int n;\r\n    vector<M> data;\r\
    \n    SegmentTree(int _n = 0) {\r\n        n = 1;\r\n        while (n < _n)\r\n\
    \            n <<= 1;\r\n        data.assign(2 * n, m1());\r\n    }\r\n    void\
    \ run(vector<M> &v) {\r\n        for (int i = 0; i < (int)v.size(); i++)\r\n \
    \           data[i + n] = v[i];\r\n        for (int k = n - 1; k > 0; k--)\r\n\
    \            data[k] = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    void set(int\
    \ k, const M &x) {\r\n        k += n;\r\n        data[k] = x;\r\n        while\
    \ (k >>= 1)\r\n            data[k] = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\
    \n    void update(int k, const N &x) {\r\n        k += n;\r\n        data[k] =\
    \ g(data[k], x);\r\n        while (k >>= 1)\r\n            data[k] = f(data[2\
    \ * k], data[2 * k + 1]);\r\n    }\r\n    M query(int a, int b) {\r\n        M\
    \ L = m1(), R = m1();\r\n        for (a += n, b += n; a < b; a >>= 1, b >>= 1)\
    \ {\r\n            if (a & 1)\r\n                L = f(L, data[a++]);\r\n    \
    \        if (b & 1)\r\n                R = f(data[--b], R);\r\n        }\r\n \
    \       return f(L, R);\r\n    }\r\n    M operator[](const int &k) const {\r\n\
    \        return data[k + n];\r\n    }\r\n\r\n    template <class F> int max_right(int\
    \ L, F ch) const {\r\n        int l = n + L, w = 1;\r\n        M ansL = m1();\r\
    \n        for (; L + w <= n; l >>= 1, w <<= 1)\r\n            if (l & 1) {\r\n\
    \                if (not ch(f(ansL, data[l])))\r\n                    break;\r\
    \n                ansL = f(ansL, data[l++]);\r\n                L += w;\r\n  \
    \          }\r\n        while (l <<= 1, w >>= 1) {\r\n            if (L + w <=\
    \ n && ch(f(ansL, data[l]))) {\r\n                ansL = f(ansL, data[l++]);\r\
    \n                L += w;\r\n            }\r\n        }\r\n        return L;\r\
    \n    }\r\n\r\n    template <class F> int min_left(int R, F ch) const {\r\n  \
    \      int r = n + R, w = 1;\r\n        M ansR = m1();\r\n        for (; R - w\
    \ >= 0; r >>= 1, w <<= 1)\r\n            if (r & 1) {\r\n                if (not\
    \ ch(f(data[r - 1], ansR)))\r\n                    break;\r\n                ansR\
    \ = f(data[--r], ansR);\r\n                R -= w;\r\n            }\r\n      \
    \  while (r <<= 1, w >>= 1) {\r\n            if (R - w >= 0 && ch(f(data[r - 1],\
    \ ansR))) {\r\n                ansR = f(data[--r], ansR);\r\n                R\
    \ -= w;\r\n            }\r\n        }\r\n        return R;\r\n    }\r\n};\r\n\r\
    \n/**\r\n * @brief Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree.hpp
  requiredBy:
  - DataStructure/sortablesegtree.hpp
  - DataStructure/2dsegtree.hpp
  timestamp: '2024-04-29 21:46:51+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_staticrmq.test.cpp
  - Verify/LC_point_add_rectangle_sum.test.cpp
  - Verify/LC_point_set_range_sort_range_composite.test.cpp
  - Verify/LC_rectangle_sum.test.cpp
  - Verify/LC_point_set_range_composite.test.cpp
  - Verify/LC_vertex_set_path_composite.test.cpp
documentation_of: DataStructure/segtree.hpp
layout: document
redirect_from:
- /library/DataStructure/segtree.hpp
- /library/DataStructure/segtree.hpp.html
title: Segment Tree
---
