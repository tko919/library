---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_maximum_independent_set.test.cpp
    title: Verify/LC_maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Maximum Independent Set
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
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool simple>\r\nvector<pair<int,\
    \ int>> genGraph(int n, int m) {\r\n    vector<pair<int, int>> cand, es;\r\n \
    \   rep(u, 0, n) rep(v, 0, n) {\r\n        if (simple and u == v)\r\n        \
    \    continue;\r\n        if (!directed and u > v)\r\n            continue;\r\n\
    \        cand.push_back({u, v});\r\n    }\r\n    if (m == -1)\r\n        m = get(SZ(cand));\r\
    \n    chmin(m, SZ(cand));\r\n    vector<int> ord;\r\n    if (simple)\r\n     \
    \   ord = select(m, 0, SZ(cand) - 1);\r\n    else {\r\n        rep(_, 0, m) ord.push_back(get(SZ(cand)\
    \ - 1));\r\n    }\r\n    for (auto &i : ord)\r\n        es.push_back(cand[i]);\r\
    \n    relabel(n, es);\r\n    return es;\r\n}\r\nvector<pair<int, int>> genTree(int\
    \ n) {\r\n    vector<pair<int, int>> es;\r\n    rep(i, 1, n) es.push_back({get(i\
    \ - 1), i});\r\n    relabel(n, es);\r\n    return es;\r\n}\r\n}; // namespace\
    \ Random\r\n\r\n/**\r\n * @brief Random\r\n */\n#line 3 \"Graph/maxindependentset.hpp\"\
    \n\r\nstruct MaxIndependentSet {\r\n    const int n;\r\n    vector<ll> es;\r\n\
    \    MaxIndependentSet(int _n) : n(_n), es(n) {}\r\n    void add_edge(int u, int\
    \ v) {\r\n        es[u] |= 1LL << v;\r\n        es[v] |= 1LL << u;\r\n    }\r\n\
    \    pair<ll, ll> run(vector<ll> &cost, int _rot = 1e6) {\r\n        vector<int>\
    \ ord(n);\r\n        iota(ALL(ord), 0);\r\n        ll ret = 0;\r\n        ll cur\
    \ = 0;\r\n        rep(_, 0, _rot) {\r\n            Random::shuffle(ALL(ord));\r\
    \n            ll add = 0;\r\n            ll used = 0;\r\n            for (auto\
    \ &v : ord)\r\n                if (!(used & es[v])) {\r\n                    used\
    \ |= (1LL << v);\r\n                    add += cost[v];\r\n                }\r\
    \n            if (chmax(ret, add))\r\n                cur = used;\r\n        }\r\
    \n        return {ret, cur};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Independent\
    \ Set\r\n */\n"
  code: "#pragma once\r\n#include \"Utility/random.hpp\"\r\n\r\nstruct MaxIndependentSet\
    \ {\r\n    const int n;\r\n    vector<ll> es;\r\n    MaxIndependentSet(int _n)\
    \ : n(_n), es(n) {}\r\n    void add_edge(int u, int v) {\r\n        es[u] |= 1LL\
    \ << v;\r\n        es[v] |= 1LL << u;\r\n    }\r\n    pair<ll, ll> run(vector<ll>\
    \ &cost, int _rot = 1e6) {\r\n        vector<int> ord(n);\r\n        iota(ALL(ord),\
    \ 0);\r\n        ll ret = 0;\r\n        ll cur = 0;\r\n        rep(_, 0, _rot)\
    \ {\r\n            Random::shuffle(ALL(ord));\r\n            ll add = 0;\r\n \
    \           ll used = 0;\r\n            for (auto &v : ord)\r\n              \
    \  if (!(used & es[v])) {\r\n                    used |= (1LL << v);\r\n     \
    \               add += cost[v];\r\n                }\r\n            if (chmax(ret,\
    \ add))\r\n                cur = used;\r\n        }\r\n        return {ret, cur};\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Independent Set\r\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: Graph/maxindependentset.hpp
  requiredBy: []
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_maximum_independent_set.test.cpp
documentation_of: Graph/maxindependentset.hpp
layout: document
redirect_from:
- /library/Graph/maxindependentset.hpp
- /library/Graph/maxindependentset.hpp.html
title: Maximum Independent Set
---
