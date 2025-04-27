---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dynamic Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/dynamicsegtree.hpp\"\n\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)()> class DynamicSegmenttree {\n  public:\n    DynamicSegmenttree(size_t\
    \ n) : n(n), root(nullptr) {}\n\n    void set(size_t p, S x) {\n        assert(p\
    \ < n);\n        set(root, 0, n, p, x);\n    }\n\n    S get(size_t p) const {\n\
    \        assert(p < n);\n        return get(root, 0, n, p);\n    }\n\n    S query(size_t\
    \ l, size_t r) const {\n        assert(l <= r && r <= n);\n        return prod(root,\
    \ 0, n, l, r);\n    }\n\n    S query() const {\n        return root ? root->product\
    \ : e();\n    }\n\n    void reset(size_t l, size_t r) {\n        assert(l <= r\
    \ && r <= n);\n        return reset(root, 0, n, l, r);\n    }\n\n    template\
    \ <bool (*f)(S)> size_t max_right(size_t l) const {\n        return max_right(l,\
    \ [](S x) { return f(x); });\n    }\n\n    template <class F> size_t max_right(size_t\
    \ l, const F &f) const {\n        assert(l <= n);\n        S product = e();\n\
    \        assert(f(product));\n        return max_right(root, 0, n, l, f, product);\n\
    \    }\n\n    template <bool (*f)(S)> size_t min_left(size_t r) const {\n    \
    \    return min_left(r, [](S x) { return f(x); });\n    }\n\n    template <class\
    \ F> size_t min_left(size_t r, const F &f) const {\n        assert(r <= n);\n\
    \        S product = e();\n        assert(f(product));\n        return min_left(root,\
    \ 0, n, r, f, product);\n    }\n\n  private:\n    struct node;\n    using node_ptr\
    \ = std::unique_ptr<node>;\n\n    struct node {\n        size_t index;\n     \
    \   S value, product;\n        node_ptr left, right;\n\n        node(size_t index,\
    \ S value)\n            : index(index), value(value), product(value), left(nullptr),\n\
    \              right(nullptr) {}\n\n        void update() {\n            product\
    \ = op(op(left ? left->product : e(), value),\n                         right\
    \ ? right->product : e());\n        }\n    };\n\n    const size_t n;\n    node_ptr\
    \ root;\n\n    void set(node_ptr &t, size_t a, size_t b, size_t p, S x) const\
    \ {\n        if (!t) {\n            t = std::make_unique<node>(p, x);\n      \
    \      return;\n        }\n        if (t->index == p) {\n            t->value\
    \ = x;\n            t->update();\n            return;\n        }\n        size_t\
    \ c = (a + b) >> 1;\n        if (p < c) {\n            if (t->index < p)\n   \
    \             std::swap(t->index, p), std::swap(t->value, x);\n            set(t->left,\
    \ a, c, p, x);\n        } else {\n            if (p < t->index)\n            \
    \    std::swap(p, t->index), std::swap(x, t->value);\n            set(t->right,\
    \ c, b, p, x);\n        }\n        t->update();\n    }\n\n    S get(const node_ptr\
    \ &t, size_t a, size_t b, size_t p) const {\n        if (!t)\n            return\
    \ e();\n        if (t->index == p)\n            return t->value;\n        size_t\
    \ c = (a + b) >> 1;\n        if (p < c)\n            return get(t->left, a, c,\
    \ p);\n        else\n            return get(t->right, c, b, p);\n    }\n\n   \
    \ S prod(const node_ptr &t, size_t a, size_t b, size_t l, size_t r) const {\n\
    \        if (!t || b <= l || r <= a)\n            return e();\n        if (l <=\
    \ a && b <= r)\n            return t->product;\n        size_t c = (a + b) >>\
    \ 1;\n        S result = prod(t->left, a, c, l, r);\n        if (l <= t->index\
    \ && t->index < r)\n            result = op(result, t->value);\n        return\
    \ op(result, prod(t->right, c, b, l, r));\n    }\n\n    void reset(node_ptr &t,\
    \ size_t a, size_t b, size_t l, size_t r) const {\n        if (!t || b <= l ||\
    \ r <= a)\n            return;\n        if (l <= a && b <= r) {\n            t.reset();\n\
    \            return;\n        }\n        size_t c = (a + b) >> 1;\n        reset(t->left,\
    \ a, c, l, r);\n        reset(t->right, c, b, l, r);\n        t->update();\n \
    \   }\n\n    template <class F>\n    size_t max_right(const node_ptr &t, size_t\
    \ a, size_t b, size_t l,\n                     const F &f, S &product) const {\n\
    \        if (!t || b <= l)\n            return n;\n        if (f(op(product, t->product)))\
    \ {\n            product = op(product, t->product);\n            return n;\n \
    \       }\n        size_t c = (a + b) >> 1;\n        size_t result = max_right(t->left,\
    \ a, c, l, f, product);\n        if (result != n)\n            return result;\n\
    \        if (l <= t->index) {\n            product = op(product, t->value);\n\
    \            if (!f(product))\n                return t->index;\n        }\n \
    \       return max_right(t->right, c, b, l, f, product);\n    }\n\n    template\
    \ <class F>\n    size_t min_left(const node_ptr &t, size_t a, size_t b, size_t\
    \ r, const F &f,\n                    S &product) const {\n        if (!t || r\
    \ <= a)\n            return 0;\n        if (f(op(t->product, product))) {\n  \
    \          product = op(t->product, product);\n            return 0;\n       \
    \ }\n        size_t c = (a + b) >> 1;\n        size_t result = min_left(t->right,\
    \ c, b, r, f, product);\n        if (result != 0)\n            return result;\n\
    \        if (t->index < r) {\n            product = op(t->value, product);\n \
    \           if (!f(product))\n                return t->index + 1;\n        }\n\
    \        return min_left(t->left, a, c, r, f, product);\n    }\n};\n\n/**\n *\
    \ @brief Dynamic Segment Tree\n */\n"
  code: "#pragma once\n\ntemplate <class S, S (*op)(S, S), S (*e)()> class DynamicSegmenttree\
    \ {\n  public:\n    DynamicSegmenttree(size_t n) : n(n), root(nullptr) {}\n\n\
    \    void set(size_t p, S x) {\n        assert(p < n);\n        set(root, 0, n,\
    \ p, x);\n    }\n\n    S get(size_t p) const {\n        assert(p < n);\n     \
    \   return get(root, 0, n, p);\n    }\n\n    S query(size_t l, size_t r) const\
    \ {\n        assert(l <= r && r <= n);\n        return prod(root, 0, n, l, r);\n\
    \    }\n\n    S query() const {\n        return root ? root->product : e();\n\
    \    }\n\n    void reset(size_t l, size_t r) {\n        assert(l <= r && r <=\
    \ n);\n        return reset(root, 0, n, l, r);\n    }\n\n    template <bool (*f)(S)>\
    \ size_t max_right(size_t l) const {\n        return max_right(l, [](S x) { return\
    \ f(x); });\n    }\n\n    template <class F> size_t max_right(size_t l, const\
    \ F &f) const {\n        assert(l <= n);\n        S product = e();\n        assert(f(product));\n\
    \        return max_right(root, 0, n, l, f, product);\n    }\n\n    template <bool\
    \ (*f)(S)> size_t min_left(size_t r) const {\n        return min_left(r, [](S\
    \ x) { return f(x); });\n    }\n\n    template <class F> size_t min_left(size_t\
    \ r, const F &f) const {\n        assert(r <= n);\n        S product = e();\n\
    \        assert(f(product));\n        return min_left(root, 0, n, r, f, product);\n\
    \    }\n\n  private:\n    struct node;\n    using node_ptr = std::unique_ptr<node>;\n\
    \n    struct node {\n        size_t index;\n        S value, product;\n      \
    \  node_ptr left, right;\n\n        node(size_t index, S value)\n            :\
    \ index(index), value(value), product(value), left(nullptr),\n              right(nullptr)\
    \ {}\n\n        void update() {\n            product = op(op(left ? left->product\
    \ : e(), value),\n                         right ? right->product : e());\n  \
    \      }\n    };\n\n    const size_t n;\n    node_ptr root;\n\n    void set(node_ptr\
    \ &t, size_t a, size_t b, size_t p, S x) const {\n        if (!t) {\n        \
    \    t = std::make_unique<node>(p, x);\n            return;\n        }\n     \
    \   if (t->index == p) {\n            t->value = x;\n            t->update();\n\
    \            return;\n        }\n        size_t c = (a + b) >> 1;\n        if\
    \ (p < c) {\n            if (t->index < p)\n                std::swap(t->index,\
    \ p), std::swap(t->value, x);\n            set(t->left, a, c, p, x);\n       \
    \ } else {\n            if (p < t->index)\n                std::swap(p, t->index),\
    \ std::swap(x, t->value);\n            set(t->right, c, b, p, x);\n        }\n\
    \        t->update();\n    }\n\n    S get(const node_ptr &t, size_t a, size_t\
    \ b, size_t p) const {\n        if (!t)\n            return e();\n        if (t->index\
    \ == p)\n            return t->value;\n        size_t c = (a + b) >> 1;\n    \
    \    if (p < c)\n            return get(t->left, a, c, p);\n        else\n   \
    \         return get(t->right, c, b, p);\n    }\n\n    S prod(const node_ptr &t,\
    \ size_t a, size_t b, size_t l, size_t r) const {\n        if (!t || b <= l ||\
    \ r <= a)\n            return e();\n        if (l <= a && b <= r)\n          \
    \  return t->product;\n        size_t c = (a + b) >> 1;\n        S result = prod(t->left,\
    \ a, c, l, r);\n        if (l <= t->index && t->index < r)\n            result\
    \ = op(result, t->value);\n        return op(result, prod(t->right, c, b, l, r));\n\
    \    }\n\n    void reset(node_ptr &t, size_t a, size_t b, size_t l, size_t r)\
    \ const {\n        if (!t || b <= l || r <= a)\n            return;\n        if\
    \ (l <= a && b <= r) {\n            t.reset();\n            return;\n        }\n\
    \        size_t c = (a + b) >> 1;\n        reset(t->left, a, c, l, r);\n     \
    \   reset(t->right, c, b, l, r);\n        t->update();\n    }\n\n    template\
    \ <class F>\n    size_t max_right(const node_ptr &t, size_t a, size_t b, size_t\
    \ l,\n                     const F &f, S &product) const {\n        if (!t ||\
    \ b <= l)\n            return n;\n        if (f(op(product, t->product))) {\n\
    \            product = op(product, t->product);\n            return n;\n     \
    \   }\n        size_t c = (a + b) >> 1;\n        size_t result = max_right(t->left,\
    \ a, c, l, f, product);\n        if (result != n)\n            return result;\n\
    \        if (l <= t->index) {\n            product = op(product, t->value);\n\
    \            if (!f(product))\n                return t->index;\n        }\n \
    \       return max_right(t->right, c, b, l, f, product);\n    }\n\n    template\
    \ <class F>\n    size_t min_left(const node_ptr &t, size_t a, size_t b, size_t\
    \ r, const F &f,\n                    S &product) const {\n        if (!t || r\
    \ <= a)\n            return 0;\n        if (f(op(t->product, product))) {\n  \
    \          product = op(t->product, product);\n            return 0;\n       \
    \ }\n        size_t c = (a + b) >> 1;\n        size_t result = min_left(t->right,\
    \ c, b, r, f, product);\n        if (result != 0)\n            return result;\n\
    \        if (t->index < r) {\n            product = op(t->value, product);\n \
    \           if (!f(product))\n                return t->index + 1;\n        }\n\
    \        return min_left(t->left, a, c, r, f, product);\n    }\n};\n\n/**\n *\
    \ @brief Dynamic Segment Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/dynamicsegtree.hpp
  requiredBy: []
  timestamp: '2025-04-27 22:54:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/dynamicsegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/dynamicsegtree.hpp
- /library/DataStructure/dynamicsegtree.hpp.html
title: Dynamic Segment Tree
---
