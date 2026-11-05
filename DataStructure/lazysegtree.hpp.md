---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/unionrect.hpp
    title: Area of Union of Rectangles
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_area_of_union_of_rectangles.test.cpp
    title: Verify/LC_area_of_union_of_rectangles.test.cpp
  - icon: ':x:'
    path: Verify/LC_range_affine_range_sum.test.cpp
    title: Verify/LC_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/lazysegtree.hpp\"\n\r\ntemplate <typename\
    \ M, typename N, M (*f)(M, M), M (*g)(M, N), N (*h)(N, N),\r\n          M (*m1)(),\
    \ N (*n1)()>\r\nclass LazySegmentTree {\r\n    int n, sz, height;\r\n    vector<M>\
    \ data;\r\n    vector<N> lazy;\r\n    void update(int k) {\r\n        data[k]\
    \ = f(data[k * 2], data[k * 2 + 1]);\r\n    }\r\n    void apply(int k, N x) {\r\
    \n        data[k] = g(data[k], x);\r\n        if (k < sz)\r\n            lazy[k]\
    \ = h(lazy[k], x);\r\n    }\r\n    void down(int k) {\r\n        apply(k * 2,\
    \ lazy[k]);\r\n        apply(k * 2 + 1, lazy[k]);\r\n        lazy[k] = n1();\r\
    \n    }\r\n\r\n  public:\r\n    LazySegmentTree(int n = 0) : LazySegmentTree(vector<M>(n,\
    \ m1())) {}\r\n    LazySegmentTree(const vector<M> &a) : n(SZ(a)) {\r\n      \
    \  sz = 1, height = 0;\r\n        while (sz < (int)a.size())\r\n            sz\
    \ <<= 1, height++;\r\n        data.assign(2 * sz, m1());\r\n        lazy.assign(sz,\
    \ n1());\r\n        rep(i, 0, a.size()) data[sz + i] = a[i];\r\n        for (int\
    \ i = sz - 1; i; i--)\r\n            update(i);\r\n    }\r\n    M operator[](int\
    \ k) const {\r\n        k += sz;\r\n        rrep(i, 1, height + 1) down(k >> i);\r\
    \n        return data[k];\r\n    }\r\n    vector<M> get() {\r\n        rep(k,\
    \ 1, sz) down(k);\r\n        return {data.begin() + sz, data.begin() + sz + n};\r\
    \n    }\r\n    void set(int k, M x) {\r\n        k += sz;\r\n        for (int\
    \ i = height; i; i--)\r\n            down(k >> i);\r\n        data[k] = x;\r\n\
    \        for (int i = 1; i <= height; i++)\r\n            update(k >> i);\r\n\
    \    }\r\n    void update(int L, int R, N x) {\r\n        if (L >= R)\r\n    \
    \        return;\r\n        L += sz, R += sz;\r\n        for (int i = height;\
    \ i; i--) {\r\n            if (((L >> i) << i) != L)\r\n                down(L\
    \ >> i);\r\n            if (((R >> i) << i) != R)\r\n                down((R -\
    \ 1) >> i);\r\n        }\r\n        int lb = L, rb = R;\r\n        while (L <\
    \ R) {\r\n            if (L & 1)\r\n                apply(L++, x);\r\n       \
    \     if (R & 1)\r\n                apply(--R, x);\r\n            L >>= 1;\r\n\
    \            R >>= 1;\r\n        }\r\n        L = lb, R = rb;\r\n        for (int\
    \ i = 1; i <= height; i++) {\r\n            if (((L >> i) << i) != L)\r\n    \
    \            update(L >> i);\r\n            if (((R >> i) << i) != R)\r\n    \
    \            update((R - 1) >> i);\r\n        }\r\n    }\r\n    M query(int L,\
    \ int R) {\r\n        if (L >= R)\r\n            return m1();\r\n        L +=\
    \ sz, R += sz;\r\n        for (int i = height; i; i--) {\r\n            if (((L\
    \ >> i) << i) != L)\r\n                down(L >> i);\r\n            if (((R >>\
    \ i) << i) != R)\r\n                down((R - 1) >> i);\r\n        }\r\n     \
    \   M lb = m1(), rb = m1();\r\n        while (L < R) {\r\n            if (L &\
    \ 1)\r\n                lb = f(lb, data[L++]);\r\n            if (R & 1)\r\n \
    \               rb = f(data[--R], rb);\r\n            L >>= 1;\r\n           \
    \ R >>= 1;\r\n        }\r\n        return f(lb, rb);\r\n    }\r\n    template\
    \ <class F> int max_right(int L, F ch) {\r\n        if (L == n)\r\n          \
    \  return n;\r\n        L += sz;\r\n        rrep(i, 1, height + 1) down(L >> i);\r\
    \n        M sum = m1();\r\n        do {\r\n            while (L % 2 == 0)\r\n\
    \                L >>= 1;\r\n            if (!ch(f(sum, data[L]))) {\r\n     \
    \           while (L < sz) {\r\n                    down(L);\r\n             \
    \       L <<= 1;\r\n                    if (ch(f(sum, data[L])))\r\n         \
    \               sum = f(sum, data[L++]);\r\n                }\r\n            \
    \    return L - sz;\r\n            }\r\n            sum = f(sum, data[L++]);\r\
    \n        } while ((L & -L) != L);\r\n        return n;\r\n    }\r\n    template\
    \ <class F> int min_left(int R, F ch) {\r\n        if (R == 0)\r\n           \
    \ return 0;\r\n        R += sz;\r\n        rrep(i, 1, height + 1) down((R - 1)\
    \ >> i);\r\n        M sum = m1();\r\n        do {\r\n            R--;\r\n    \
    \        while (R > 1 and (R & 1))\r\n                R >>= 1;\r\n           \
    \ if (!ch(f(data[R], sum))) {\r\n                while (R < sz) {\r\n        \
    \            down(R);\r\n                    R = (R * 2 + 1);\r\n            \
    \        if (ch(f(data[R], sum))) {\r\n                        sum = f(data[R--],\
    \ sum);\r\n                    }\r\n                }\r\n                return\
    \ R + 1 - sz;\r\n            }\r\n            sum = f(data[R], sum);\r\n     \
    \   } while ((R & -R) != R);\r\n        return 0;\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Lazy Segment Tree\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename M, typename N, M (*f)(M, M), M (*g)(M,\
    \ N), N (*h)(N, N),\r\n          M (*m1)(), N (*n1)()>\r\nclass LazySegmentTree\
    \ {\r\n    int n, sz, height;\r\n    vector<M> data;\r\n    vector<N> lazy;\r\n\
    \    void update(int k) {\r\n        data[k] = f(data[k * 2], data[k * 2 + 1]);\r\
    \n    }\r\n    void apply(int k, N x) {\r\n        data[k] = g(data[k], x);\r\n\
    \        if (k < sz)\r\n            lazy[k] = h(lazy[k], x);\r\n    }\r\n    void\
    \ down(int k) {\r\n        apply(k * 2, lazy[k]);\r\n        apply(k * 2 + 1,\
    \ lazy[k]);\r\n        lazy[k] = n1();\r\n    }\r\n\r\n  public:\r\n    LazySegmentTree(int\
    \ n = 0) : LazySegmentTree(vector<M>(n, m1())) {}\r\n    LazySegmentTree(const\
    \ vector<M> &a) : n(SZ(a)) {\r\n        sz = 1, height = 0;\r\n        while (sz\
    \ < (int)a.size())\r\n            sz <<= 1, height++;\r\n        data.assign(2\
    \ * sz, m1());\r\n        lazy.assign(sz, n1());\r\n        rep(i, 0, a.size())\
    \ data[sz + i] = a[i];\r\n        for (int i = sz - 1; i; i--)\r\n           \
    \ update(i);\r\n    }\r\n    M operator[](int k) const {\r\n        k += sz;\r\
    \n        rrep(i, 1, height + 1) down(k >> i);\r\n        return data[k];\r\n\
    \    }\r\n    vector<M> get() {\r\n        rep(k, 1, sz) down(k);\r\n        return\
    \ {data.begin() + sz, data.begin() + sz + n};\r\n    }\r\n    void set(int k,\
    \ M x) {\r\n        k += sz;\r\n        for (int i = height; i; i--)\r\n     \
    \       down(k >> i);\r\n        data[k] = x;\r\n        for (int i = 1; i <=\
    \ height; i++)\r\n            update(k >> i);\r\n    }\r\n    void update(int\
    \ L, int R, N x) {\r\n        if (L >= R)\r\n            return;\r\n        L\
    \ += sz, R += sz;\r\n        for (int i = height; i; i--) {\r\n            if\
    \ (((L >> i) << i) != L)\r\n                down(L >> i);\r\n            if (((R\
    \ >> i) << i) != R)\r\n                down((R - 1) >> i);\r\n        }\r\n  \
    \      int lb = L, rb = R;\r\n        while (L < R) {\r\n            if (L & 1)\r\
    \n                apply(L++, x);\r\n            if (R & 1)\r\n               \
    \ apply(--R, x);\r\n            L >>= 1;\r\n            R >>= 1;\r\n        }\r\
    \n        L = lb, R = rb;\r\n        for (int i = 1; i <= height; i++) {\r\n \
    \           if (((L >> i) << i) != L)\r\n                update(L >> i);\r\n \
    \           if (((R >> i) << i) != R)\r\n                update((R - 1) >> i);\r\
    \n        }\r\n    }\r\n    M query(int L, int R) {\r\n        if (L >= R)\r\n\
    \            return m1();\r\n        L += sz, R += sz;\r\n        for (int i =\
    \ height; i; i--) {\r\n            if (((L >> i) << i) != L)\r\n             \
    \   down(L >> i);\r\n            if (((R >> i) << i) != R)\r\n               \
    \ down((R - 1) >> i);\r\n        }\r\n        M lb = m1(), rb = m1();\r\n    \
    \    while (L < R) {\r\n            if (L & 1)\r\n                lb = f(lb, data[L++]);\r\
    \n            if (R & 1)\r\n                rb = f(data[--R], rb);\r\n       \
    \     L >>= 1;\r\n            R >>= 1;\r\n        }\r\n        return f(lb, rb);\r\
    \n    }\r\n    template <class F> int max_right(int L, F ch) {\r\n        if (L\
    \ == n)\r\n            return n;\r\n        L += sz;\r\n        rrep(i, 1, height\
    \ + 1) down(L >> i);\r\n        M sum = m1();\r\n        do {\r\n            while\
    \ (L % 2 == 0)\r\n                L >>= 1;\r\n            if (!ch(f(sum, data[L])))\
    \ {\r\n                while (L < sz) {\r\n                    down(L);\r\n  \
    \                  L <<= 1;\r\n                    if (ch(f(sum, data[L])))\r\n\
    \                        sum = f(sum, data[L++]);\r\n                }\r\n   \
    \             return L - sz;\r\n            }\r\n            sum = f(sum, data[L++]);\r\
    \n        } while ((L & -L) != L);\r\n        return n;\r\n    }\r\n    template\
    \ <class F> int min_left(int R, F ch) {\r\n        if (R == 0)\r\n           \
    \ return 0;\r\n        R += sz;\r\n        rrep(i, 1, height + 1) down((R - 1)\
    \ >> i);\r\n        M sum = m1();\r\n        do {\r\n            R--;\r\n    \
    \        while (R > 1 and (R & 1))\r\n                R >>= 1;\r\n           \
    \ if (!ch(f(data[R], sum))) {\r\n                while (R < sz) {\r\n        \
    \            down(R);\r\n                    R = (R * 2 + 1);\r\n            \
    \        if (ch(f(data[R], sum))) {\r\n                        sum = f(data[R--],\
    \ sum);\r\n                    }\r\n                }\r\n                return\
    \ R + 1 - sz;\r\n            }\r\n            sum = f(data[R], sum);\r\n     \
    \   } while ((R & -R) != R);\r\n        return 0;\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Lazy Segment Tree\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/lazysegtree.hpp
  requiredBy:
  - DataStructure/unionrect.hpp
  timestamp: '2024-08-09 08:04:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_area_of_union_of_rectangles.test.cpp
  - Verify/LC_range_affine_range_sum.test.cpp
documentation_of: DataStructure/lazysegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/lazysegtree.hpp
- /library/DataStructure/lazysegtree.hpp.html
title: Lazy Segment Tree
---
