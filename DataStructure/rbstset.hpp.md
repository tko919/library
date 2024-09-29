---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_predecessor_problem.test.cpp
    title: Verify/LC_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Randomized Binary Search Tree (set)
    links: []
  bundledCode: "#line 2 \"DataStructure/rbstset.hpp\"\n\r\n#line 2 \"Utility/random.hpp\"\
    \n\r\nnamespace Random {\r\nmt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
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
    \ Random\r\n */\n#line 4 \"DataStructure/rbstset.hpp\"\n\r\ntemplate <typename\
    \ T> class RBSTset {\r\n    struct Node {\r\n        Node *lp = nullptr, *rp =\
    \ nullptr;\r\n        int size = 1;\r\n        T key;\r\n        Node(T _k = 0)\
    \ : key(_k) {}\r\n        void apply() {\r\n            size = 1;\r\n        \
    \    if (lp)\r\n                size += lp->size;\r\n            if (rp)\r\n \
    \               size += rp->size;\r\n        }\r\n    };\r\n    int size(Node\
    \ *x) {\r\n        return x ? x->size : 0;\r\n    }\r\n    Node *merge(Node *L,\
    \ Node *R) {\r\n        if (!L)\r\n            return R;\r\n        if (!R)\r\n\
    \            return L;\r\n        if ((int)Random::get(size(L) + size(R) - 1)\
    \ < size(L)) {\r\n            L->rp = merge(L->rp, R);\r\n            L->apply();\r\
    \n            return L;\r\n        } else {\r\n            R->lp = merge(L, R->lp);\r\
    \n            R->apply();\r\n            return R;\r\n        }\r\n    }\r\n \
    \   array<Node *, 2> split(Node *x, int k) {\r\n        if (!x)\r\n          \
    \  return {nullptr, nullptr};\r\n        if (k == size(x))\r\n            return\
    \ {x, nullptr};\r\n        if (k <= size(x->lp)) {\r\n            auto [lb, rb]\
    \ = split(x->lp, k);\r\n            Node *L = lb, *R = x;\r\n            x->lp\
    \ = rb;\r\n            x->apply();\r\n            return {L, R};\r\n        }\
    \ else {\r\n            auto [lb, rb] = split(x->rp, k - size(x->lp) - 1);\r\n\
    \            Node *L = x, *R = rb;\r\n            x->rp = lb;\r\n            x->apply();\r\
    \n            return {L, R};\r\n        }\r\n    }\r\n    int lower_bound(Node\
    \ *x, T v) {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key\
    \ >= v)\r\n            return lower_bound(x->lp, v);\r\n        else\r\n     \
    \       return size(x->lp) + 1 + lower_bound(x->rp, v);\r\n    }\r\n    int upper_bound(Node\
    \ *x, T v) {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key\
    \ > v)\r\n            return upper_bound(x->lp, v);\r\n        else\r\n      \
    \      return size(x->lp) + 1 + upper_bound(x->rp, v);\r\n    }\r\n    void _dump(Node\
    \ *cur, int depth) {\r\n        if (!cur)\r\n            return;\r\n        _dump(cur->lp,\
    \ depth + 1);\r\n        rep(_, 0, depth) cerr << ' ';\r\n        cerr << cur->key\
    \ << '\\n';\r\n        _dump(cur->rp, depth + 1);\r\n    }\r\n\r\n  public:\r\n\
    \    Node *root;\r\n    RBSTset(Node *_r = nullptr) : root(_r) {}\r\n    int size()\
    \ {\r\n        return size(root);\r\n    }\r\n    void merge(RBSTset &a) {\r\n\
    \        root = merge(root, a.root);\r\n    }\r\n    RBSTset split(int k) {\r\n\
    \        auto [L, R] = split(root, k);\r\n        root = L;\r\n        return\
    \ RBSTset(R);\r\n    }\r\n    bool find(T x) {\r\n        Node *cur = root;\r\n\
    \        for (;;) {\r\n            if (!cur)\r\n                break;\r\n   \
    \         if (cur->key == x)\r\n                return true;\r\n            else\
    \ if (x < cur->key)\r\n                cur = cur->lp;\r\n            else\r\n\
    \                cur = cur->rp;\r\n        }\r\n        return false;\r\n    }\r\
    \n    void insert(T x) {\r\n        int k = lower_bound(root, x);\r\n        auto\
    \ [L, R] = split(root, k);\r\n        root = merge(merge(L, new Node(x)), R);\r\
    \n    }\r\n    void erase(T x) {\r\n        assert(find(x));\r\n        int k\
    \ = lower_bound(root, x);\r\n        auto [L, t] = split(root, k);\r\n       \
    \ auto [tmp, R] = split(t, 1);\r\n        root = merge(L, R);\r\n    }\r\n   \
    \ T kth_element(int k) {\r\n        if (k >= size(root) or k < 0)\r\n        \
    \    return -1;\r\n        auto [L, R] = split(root, k);\r\n        Node *cur\
    \ = R;\r\n        while (cur->lp)\r\n            cur = cur->lp;\r\n        root\
    \ = merge(L, R);\r\n        return cur->key;\r\n    }\r\n    int lower_bound(T\
    \ v) {\r\n        return lower_bound(root, v);\r\n    }\r\n    int upper_bound(T\
    \ v) {\r\n        return upper_bound(root, v);\r\n    }\r\n    void dump() {\r\
    \n        _dump(root, 1);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
    \ Search Tree (set)\r\n */\n"
  code: "#pragma once\r\n\r\n#include \"Utility/random.hpp\"\r\n\r\ntemplate <typename\
    \ T> class RBSTset {\r\n    struct Node {\r\n        Node *lp = nullptr, *rp =\
    \ nullptr;\r\n        int size = 1;\r\n        T key;\r\n        Node(T _k = 0)\
    \ : key(_k) {}\r\n        void apply() {\r\n            size = 1;\r\n        \
    \    if (lp)\r\n                size += lp->size;\r\n            if (rp)\r\n \
    \               size += rp->size;\r\n        }\r\n    };\r\n    int size(Node\
    \ *x) {\r\n        return x ? x->size : 0;\r\n    }\r\n    Node *merge(Node *L,\
    \ Node *R) {\r\n        if (!L)\r\n            return R;\r\n        if (!R)\r\n\
    \            return L;\r\n        if ((int)Random::get(size(L) + size(R) - 1)\
    \ < size(L)) {\r\n            L->rp = merge(L->rp, R);\r\n            L->apply();\r\
    \n            return L;\r\n        } else {\r\n            R->lp = merge(L, R->lp);\r\
    \n            R->apply();\r\n            return R;\r\n        }\r\n    }\r\n \
    \   array<Node *, 2> split(Node *x, int k) {\r\n        if (!x)\r\n          \
    \  return {nullptr, nullptr};\r\n        if (k == size(x))\r\n            return\
    \ {x, nullptr};\r\n        if (k <= size(x->lp)) {\r\n            auto [lb, rb]\
    \ = split(x->lp, k);\r\n            Node *L = lb, *R = x;\r\n            x->lp\
    \ = rb;\r\n            x->apply();\r\n            return {L, R};\r\n        }\
    \ else {\r\n            auto [lb, rb] = split(x->rp, k - size(x->lp) - 1);\r\n\
    \            Node *L = x, *R = rb;\r\n            x->rp = lb;\r\n            x->apply();\r\
    \n            return {L, R};\r\n        }\r\n    }\r\n    int lower_bound(Node\
    \ *x, T v) {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key\
    \ >= v)\r\n            return lower_bound(x->lp, v);\r\n        else\r\n     \
    \       return size(x->lp) + 1 + lower_bound(x->rp, v);\r\n    }\r\n    int upper_bound(Node\
    \ *x, T v) {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key\
    \ > v)\r\n            return upper_bound(x->lp, v);\r\n        else\r\n      \
    \      return size(x->lp) + 1 + upper_bound(x->rp, v);\r\n    }\r\n    void _dump(Node\
    \ *cur, int depth) {\r\n        if (!cur)\r\n            return;\r\n        _dump(cur->lp,\
    \ depth + 1);\r\n        rep(_, 0, depth) cerr << ' ';\r\n        cerr << cur->key\
    \ << '\\n';\r\n        _dump(cur->rp, depth + 1);\r\n    }\r\n\r\n  public:\r\n\
    \    Node *root;\r\n    RBSTset(Node *_r = nullptr) : root(_r) {}\r\n    int size()\
    \ {\r\n        return size(root);\r\n    }\r\n    void merge(RBSTset &a) {\r\n\
    \        root = merge(root, a.root);\r\n    }\r\n    RBSTset split(int k) {\r\n\
    \        auto [L, R] = split(root, k);\r\n        root = L;\r\n        return\
    \ RBSTset(R);\r\n    }\r\n    bool find(T x) {\r\n        Node *cur = root;\r\n\
    \        for (;;) {\r\n            if (!cur)\r\n                break;\r\n   \
    \         if (cur->key == x)\r\n                return true;\r\n            else\
    \ if (x < cur->key)\r\n                cur = cur->lp;\r\n            else\r\n\
    \                cur = cur->rp;\r\n        }\r\n        return false;\r\n    }\r\
    \n    void insert(T x) {\r\n        int k = lower_bound(root, x);\r\n        auto\
    \ [L, R] = split(root, k);\r\n        root = merge(merge(L, new Node(x)), R);\r\
    \n    }\r\n    void erase(T x) {\r\n        assert(find(x));\r\n        int k\
    \ = lower_bound(root, x);\r\n        auto [L, t] = split(root, k);\r\n       \
    \ auto [tmp, R] = split(t, 1);\r\n        root = merge(L, R);\r\n    }\r\n   \
    \ T kth_element(int k) {\r\n        if (k >= size(root) or k < 0)\r\n        \
    \    return -1;\r\n        auto [L, R] = split(root, k);\r\n        Node *cur\
    \ = R;\r\n        while (cur->lp)\r\n            cur = cur->lp;\r\n        root\
    \ = merge(L, R);\r\n        return cur->key;\r\n    }\r\n    int lower_bound(T\
    \ v) {\r\n        return lower_bound(root, v);\r\n    }\r\n    int upper_bound(T\
    \ v) {\r\n        return upper_bound(root, v);\r\n    }\r\n    void dump() {\r\
    \n        _dump(root, 1);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
    \ Search Tree (set)\r\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: DataStructure/rbstset.hpp
  requiredBy: []
  timestamp: '2024-04-26 04:30:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_predecessor_problem.test.cpp
documentation_of: DataStructure/rbstset.hpp
layout: document
redirect_from:
- /library/DataStructure/rbstset.hpp
- /library/DataStructure/rbstset.hpp.html
title: Randomized Binary Search Tree (set)
---
