---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_range_kth_smallest-2.test.cpp
    title: Verify/LC_range_kth_smallest-2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Persistent Randomized Binary Search Tree (set)
    links: []
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random {\r\nmt19937_64\
    \ randgen(chrono::steady_clock::now().time_since_epoch().count());\r\nusing u64\
    \ = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n}\r\ntemplate\
    \ <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\n}\r\ntemplate\
    \ <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R - L) + L;\r\n}\r\
    \ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\n}\r\
    \nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a', 'z');\r\
    \n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter first, Iter\
    \ last) {\r\n    if (first == last)\r\n        return;\r\n    int len = 1;\r\n\
    \    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\n     \
    \   int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n            iter_swap(it,\
    \ first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T> select(int n, T\
    \ L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n        vector<T> ret(R\
    \ - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\n  \
    \      ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool multi, bool self>\r\
    \nvector<pair<int, int>> genGraph(int n, int m) {\r\n    vector<pair<int, int>>\
    \ cand, es;\r\n    rep(u, 0, n) rep(v, 0, n) {\r\n        if (!self and u == v)\r\
    \n            continue;\r\n        if (!directed and u > v)\r\n            continue;\r\
    \n        cand.push_back({u, v});\r\n    }\r\n    if (m == -1)\r\n        m =\
    \ get(SZ(cand));\r\n    // chmin(m, SZ(cand));\r\n    vector<int> ord;\r\n   \
    \ if (multi)\r\n        rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n   \
    \ else {\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    }\r\n    for (auto\
    \ &i : ord)\r\n        es.push_back(cand[i]);\r\n    relabel(n, es);\r\n    return\
    \ es;\r\n}\r\nvector<pair<int, int>> genTree(int n) {\r\n    vector<pair<int,\
    \ int>> es;\r\n    rep(i, 1, n) es.push_back({get(i - 1), i});\r\n    relabel(n,\
    \ es);\r\n    return es;\r\n}\r\n}; // namespace Random\r\n\r\n/**\r\n * @brief\
    \ Random\r\n */\n#line 3 \"DataStructure/persistentrbstset.hpp\"\n\r\ntemplate\
    \ <typename T, int LIM = 10101010> struct PRBSTset {\r\n    struct Node {\r\n\
    \        Node *lp = nullptr, *rp = nullptr;\r\n        int sz = 1;\r\n       \
    \ T val;\r\n        Node() {}\r\n        void apply() {\r\n            sz = 1;\r\
    \n            if (lp)\r\n                sz += lp->sz;\r\n            if (rp)\r\
    \n                sz += rp->sz;\r\n        }\r\n    };\r\n    using np = Node\
    \ *;\r\n    Node buf[LIM];\r\n    int pos = 0;\r\n    int sz(np root) { return\
    \ root ? root->sz : 0; }\r\n    np merge(np L, np R) {\r\n        if (!L)\r\n\
    \            return R;\r\n        if (!R)\r\n            return L;\r\n       \
    \ if (Random::uniform() * (sz(L) + sz(R)) < sz(L)) {\r\n            auto rb =\
    \ merge(L->rp, R);\r\n            np ret = make(L->val, L->lp, rb);\r\n      \
    \      return ret;\r\n        } else {\r\n            auto lb = merge(L, R->lp);\r\
    \n            np ret = make(R->val, lb, R->rp);\r\n            return ret;\r\n\
    \        }\r\n    }\r\n    array<np, 2> split(np root, int k) {\r\n        if\
    \ (k <= 0)\r\n            return {nullptr, root};\r\n        if (k >= sz(root))\r\
    \n            return {root, nullptr};\r\n        if (k <= sz(root->lp)) {\r\n\
    \            auto [L, lb] = split(root->lp, k);\r\n            np R = make(root->val,\
    \ lb, root->rp);\r\n            return {L, R};\r\n        } else {\r\n       \
    \     auto [rb, R] = split(root->rp, k - 1 - sz(root->lp));\r\n            np\
    \ L = make(root->val, root->lp, rb);\r\n            return {L, R};\r\n       \
    \ }\r\n    }\r\n    bool find(np root, T v) {\r\n        if (!root)\r\n      \
    \      return false;\r\n        if (root->val == v)\r\n            return true;\r\
    \n        else if (root->val > v)\r\n            return find(root->lp, v);\r\n\
    \        else\r\n            return find(root->rp, v);\r\n    }\r\n    int lower_bound(np\
    \ root, T v) {\r\n        if (!root)\r\n            return 0;\r\n        if (root->val\
    \ > v)\r\n            return lower_bound(root->lp, v);\r\n        else\r\n   \
    \         return sz(root->lp) + 1 + lower_bound(root->rp, v);\r\n    }\r\n   \
    \ int upper_bound(np root, T v) {\r\n        if (!root)\r\n            return\
    \ 0;\r\n        if (root->val >= v)\r\n            return upper_bound(root->lp,\
    \ v);\r\n        else\r\n            return sz(root->lp) + 1 + upper_bound(root->rp,\
    \ v);\r\n    }\r\n    np make(T v, np L = nullptr, np R = nullptr) {\r\n     \
    \   np ret = &buf[pos++];\r\n        ret->val = v;\r\n        ret->lp = L;\r\n\
    \        ret->rp = R;\r\n        ret->apply();\r\n        return ret;\r\n    }\r\
    \n    void dfs(np root, vector<T> &a) {\r\n        if (!root)\r\n            return;\r\
    \n        dfs(root->lp, a);\r\n        a.push_back(root->val);\r\n        dfs(root->rp,\
    \ a);\r\n    }\r\n    np rebuild(np root) {\r\n        if (pos < LIM * .95)\r\n\
    \            return root;\r\n        vector<T> tmp;\r\n        dfs(root, tmp);\r\
    \n        return build(tmp);\r\n    }\r\n    np insert(np root, T v) {\r\n   \
    \     int k = lower_bound(root, v);\r\n        auto [L, R] = split(root, k);\r\
    \n        return merge(merge(L, make(v)), R);\r\n    }\r\n    np erase(np root,\
    \ T v) {\r\n        int k = lower_bound(root, v);\r\n        auto [L, rb] = split(root,\
    \ k);\r\n        auto [tmp, R] = split(rb, 1);\r\n        return merge(L, R);\r\
    \n    }\r\n    T kth_elem(np root, int k) {\r\n        assert(k <= 0 and k < sz(root));\r\
    \n        if (sz(root->lp) == k)\r\n            return root->val;\r\n        else\
    \ if (sz(root->lp) > k)\r\n            return kth_elem(root->lp, k);\r\n     \
    \   else\r\n            return kth_elem(root->rp, k - 1 - sz(root->lp));\r\n \
    \   }\r\n    np build(vector<T> &a) {\r\n        np root = nullptr;\r\n      \
    \  for (auto &x : a)\r\n            root = merge(root, make(x));\r\n        return\
    \ root;\r\n    }\r\n    void dump(np root) {\r\n        if (!root)\r\n       \
    \     return;\r\n        dump(root->lp);\r\n        cerr << root->val << '\\n';\r\
    \n        dump(root->rp);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Persistent Randomized\
    \ Binary Search Tree (set)\r\n */\n"
  code: "#pragma once\r\n#include \"Utility/random.hpp\"\r\n\r\ntemplate <typename\
    \ T, int LIM = 10101010> struct PRBSTset {\r\n    struct Node {\r\n        Node\
    \ *lp = nullptr, *rp = nullptr;\r\n        int sz = 1;\r\n        T val;\r\n \
    \       Node() {}\r\n        void apply() {\r\n            sz = 1;\r\n       \
    \     if (lp)\r\n                sz += lp->sz;\r\n            if (rp)\r\n    \
    \            sz += rp->sz;\r\n        }\r\n    };\r\n    using np = Node *;\r\n\
    \    Node buf[LIM];\r\n    int pos = 0;\r\n    int sz(np root) { return root ?\
    \ root->sz : 0; }\r\n    np merge(np L, np R) {\r\n        if (!L)\r\n       \
    \     return R;\r\n        if (!R)\r\n            return L;\r\n        if (Random::uniform()\
    \ * (sz(L) + sz(R)) < sz(L)) {\r\n            auto rb = merge(L->rp, R);\r\n \
    \           np ret = make(L->val, L->lp, rb);\r\n            return ret;\r\n \
    \       } else {\r\n            auto lb = merge(L, R->lp);\r\n            np ret\
    \ = make(R->val, lb, R->rp);\r\n            return ret;\r\n        }\r\n    }\r\
    \n    array<np, 2> split(np root, int k) {\r\n        if (k <= 0)\r\n        \
    \    return {nullptr, root};\r\n        if (k >= sz(root))\r\n            return\
    \ {root, nullptr};\r\n        if (k <= sz(root->lp)) {\r\n            auto [L,\
    \ lb] = split(root->lp, k);\r\n            np R = make(root->val, lb, root->rp);\r\
    \n            return {L, R};\r\n        } else {\r\n            auto [rb, R] =\
    \ split(root->rp, k - 1 - sz(root->lp));\r\n            np L = make(root->val,\
    \ root->lp, rb);\r\n            return {L, R};\r\n        }\r\n    }\r\n    bool\
    \ find(np root, T v) {\r\n        if (!root)\r\n            return false;\r\n\
    \        if (root->val == v)\r\n            return true;\r\n        else if (root->val\
    \ > v)\r\n            return find(root->lp, v);\r\n        else\r\n          \
    \  return find(root->rp, v);\r\n    }\r\n    int lower_bound(np root, T v) {\r\
    \n        if (!root)\r\n            return 0;\r\n        if (root->val > v)\r\n\
    \            return lower_bound(root->lp, v);\r\n        else\r\n            return\
    \ sz(root->lp) + 1 + lower_bound(root->rp, v);\r\n    }\r\n    int upper_bound(np\
    \ root, T v) {\r\n        if (!root)\r\n            return 0;\r\n        if (root->val\
    \ >= v)\r\n            return upper_bound(root->lp, v);\r\n        else\r\n  \
    \          return sz(root->lp) + 1 + upper_bound(root->rp, v);\r\n    }\r\n  \
    \  np make(T v, np L = nullptr, np R = nullptr) {\r\n        np ret = &buf[pos++];\r\
    \n        ret->val = v;\r\n        ret->lp = L;\r\n        ret->rp = R;\r\n  \
    \      ret->apply();\r\n        return ret;\r\n    }\r\n    void dfs(np root,\
    \ vector<T> &a) {\r\n        if (!root)\r\n            return;\r\n        dfs(root->lp,\
    \ a);\r\n        a.push_back(root->val);\r\n        dfs(root->rp, a);\r\n    }\r\
    \n    np rebuild(np root) {\r\n        if (pos < LIM * .95)\r\n            return\
    \ root;\r\n        vector<T> tmp;\r\n        dfs(root, tmp);\r\n        return\
    \ build(tmp);\r\n    }\r\n    np insert(np root, T v) {\r\n        int k = lower_bound(root,\
    \ v);\r\n        auto [L, R] = split(root, k);\r\n        return merge(merge(L,\
    \ make(v)), R);\r\n    }\r\n    np erase(np root, T v) {\r\n        int k = lower_bound(root,\
    \ v);\r\n        auto [L, rb] = split(root, k);\r\n        auto [tmp, R] = split(rb,\
    \ 1);\r\n        return merge(L, R);\r\n    }\r\n    T kth_elem(np root, int k)\
    \ {\r\n        assert(k <= 0 and k < sz(root));\r\n        if (sz(root->lp) ==\
    \ k)\r\n            return root->val;\r\n        else if (sz(root->lp) > k)\r\n\
    \            return kth_elem(root->lp, k);\r\n        else\r\n            return\
    \ kth_elem(root->rp, k - 1 - sz(root->lp));\r\n    }\r\n    np build(vector<T>\
    \ &a) {\r\n        np root = nullptr;\r\n        for (auto &x : a)\r\n       \
    \     root = merge(root, make(x));\r\n        return root;\r\n    }\r\n    void\
    \ dump(np root) {\r\n        if (!root)\r\n            return;\r\n        dump(root->lp);\r\
    \n        cerr << root->val << '\\n';\r\n        dump(root->rp);\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Persistent Randomized Binary Search Tree (set)\r\n\
    \ */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: DataStructure/persistentrbstset.hpp
  requiredBy: []
  timestamp: '2025-05-25 16:11:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_range_kth_smallest-2.test.cpp
documentation_of: DataStructure/persistentrbstset.hpp
layout: document
redirect_from:
- /library/DataStructure/persistentrbstset.hpp
- /library/DataStructure/persistentrbstset.hpp.html
title: Persistent Randomized Binary Search Tree (set)
---
