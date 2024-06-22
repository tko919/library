---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Static TopTree
    links: []
  bundledCode: "#line 2 \"Graph/statictoptree.hpp\"\n\ntemplate <typename Path, typename\
    \ Point, Path (*vertex)(int),\n          Path (*compress)(Path, Path), Point (*rake)(Point,\
    \ Point),\n          Point (*add_edge)(Path), Path (*add_vertex)(Point, int)>\n\
    struct StaticTopTree {\n    enum Type { Vertex, Compress, Rake, AddEdge, AddVertex\
    \ };\n    struct Node {\n        int par, lp, rp;\n        Type t;\n        Node()\
    \ {}\n        Node(int _p, int _l, int _r, Type _t)\n            : par(_p), lp(_l),\
    \ rp(_r), t(_t) {}\n    };\n    vector<vector<int>> g;\n    vector<Node> vs;\n\
    \    vector<Path> path;\n    vector<Point> point;\n    int rt;\n    StaticTopTree()\
    \ {}\n    StaticTopTree(int n) : g(n), vs(n) {}\n    void push(int u, int v) {\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    void run(int\
    \ base) {\n        _dfs(base, -1);\n        auto [v, _] = _compress(base);\n \
    \       rt = v;\n        path.resize(SZ(vs));\n        point.resize(SZ(vs));\n\
    \        _calc(rt);\n    }\n    void update(int v) {\n        while (v != -1)\
    \ {\n            _update(v);\n            v = vs[v].par;\n        }\n    }\n \
    \   Path get_root() const {\n        return path[rt];\n    }\n\n  private:\n \
    \   int _make(int k, int L, int R, Type t) {\n        Node add(-1, L, R, t);\n\
    \        if (k == -1) {\n            k = SZ(vs);\n            vs.push_back(add);\n\
    \        } else\n            vs[k] = add;\n        if (L != -1)\n            vs[L].par\
    \ = k;\n        if (R != -1)\n            vs[R].par = k;\n        return k;\n\
    \    }\n    int _dfs(int v, int p) {\n        rep(i, 0, SZ(g[v])) if (g[v][i]\
    \ == p) {\n            g[v].erase(g[v].begin() + i);\n            break;\n   \
    \     }\n        int sz = 1, best = 0;\n        for (auto &to : g[v]) {\n    \
    \        int add = _dfs(to, v);\n            sz += add;\n            if (chmax(best,\
    \ add))\n                swap(to, g[v].front());\n        }\n        return sz;\n\
    \    }\n\n    using P = pair<int, int>;\n    P _merge(const vector<P> &a, Type\
    \ t) {\n        if (SZ(a) == 1)\n            return a[0];\n        int sum = 0;\n\
    \        for (auto &[_, sz] : a)\n            sum += sz;\n        vector<P> L,\
    \ R;\n        for (auto &[v, sz] : a) {\n            if (sum > sz)\n         \
    \       L.push_back({v, sz});\n            else\n                R.push_back({v,\
    \ sz});\n            sum -= sz * 2;\n        }\n        auto [lb, slb] = _merge(L,\
    \ t);\n        auto [rb, srb] = _merge(R, t);\n        return {_make(-1, lb, rb,\
    \ t), slb + srb};\n    }\n    P _compress(int v) {\n        vector<P> cs{_add_vertex(v)};\n\
    \        while (!g[v].empty())\n            cs.push_back(_add_vertex(v = g[v].front()));\n\
    \        return _merge(cs, Type::Compress);\n    }\n    P _rake(int v) {\n   \
    \     vector<P> cs;\n        rep(j, 1, SZ(g[v])) cs.push_back(_add_edge(g[v][j]));\n\
    \        return cs.empty() ? P{-1, 0} : _merge(cs, Type::Rake);\n    }\n    P\
    \ _add_edge(int v) {\n        auto [to, sz] = _compress(v);\n        return P{_make(-1,\
    \ to, -1, Type::AddEdge), sz};\n    }\n    P _add_vertex(int v) {\n        auto\
    \ [to, sz] = _rake(v);\n        return P{_make(v, to, -1, to == -1 ? Type::Vertex\
    \ : Type::AddVertex),\n                 sz + 1};\n    }\n    void _update(int\
    \ v) {\n        if (vs[v].t == StaticTopTree::Type::Vertex) {\n            path[v]\
    \ = vertex(v);\n        }\n        if (vs[v].t == StaticTopTree::Type::Compress)\
    \ {\n            path[v] = compress(path[vs[v].lp], path[vs[v].rp]);\n       \
    \ }\n        if (vs[v].t == StaticTopTree::Type::Rake) {\n            point[v]\
    \ = rake(point[vs[v].lp], point[vs[v].rp]);\n        }\n        if (vs[v].t ==\
    \ StaticTopTree::Type::AddVertex) {\n            path[v] = add_vertex(point[vs[v].lp],\
    \ v);\n        }\n        if (vs[v].t == StaticTopTree::Type::AddEdge) {\n   \
    \         point[v] = add_edge(path[vs[v].lp]);\n        }\n    }\n    void _calc(int\
    \ v) {\n        if (vs[v].lp != -1)\n            _calc(vs[v].lp);\n        if\
    \ (vs[v].rp != -1)\n            _calc(vs[v].rp);\n        _update(v);\n    }\n\
    };\n\n/**\n * @brief Static TopTree\n */\n"
  code: "#pragma once\n\ntemplate <typename Path, typename Point, Path (*vertex)(int),\n\
    \          Path (*compress)(Path, Path), Point (*rake)(Point, Point),\n      \
    \    Point (*add_edge)(Path), Path (*add_vertex)(Point, int)>\nstruct StaticTopTree\
    \ {\n    enum Type { Vertex, Compress, Rake, AddEdge, AddVertex };\n    struct\
    \ Node {\n        int par, lp, rp;\n        Type t;\n        Node() {}\n     \
    \   Node(int _p, int _l, int _r, Type _t)\n            : par(_p), lp(_l), rp(_r),\
    \ t(_t) {}\n    };\n    vector<vector<int>> g;\n    vector<Node> vs;\n    vector<Path>\
    \ path;\n    vector<Point> point;\n    int rt;\n    StaticTopTree() {}\n    StaticTopTree(int\
    \ n) : g(n), vs(n) {}\n    void push(int u, int v) {\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    void run(int base) {\n        _dfs(base,\
    \ -1);\n        auto [v, _] = _compress(base);\n        rt = v;\n        path.resize(SZ(vs));\n\
    \        point.resize(SZ(vs));\n        _calc(rt);\n    }\n    void update(int\
    \ v) {\n        while (v != -1) {\n            _update(v);\n            v = vs[v].par;\n\
    \        }\n    }\n    Path get_root() const {\n        return path[rt];\n   \
    \ }\n\n  private:\n    int _make(int k, int L, int R, Type t) {\n        Node\
    \ add(-1, L, R, t);\n        if (k == -1) {\n            k = SZ(vs);\n       \
    \     vs.push_back(add);\n        } else\n            vs[k] = add;\n        if\
    \ (L != -1)\n            vs[L].par = k;\n        if (R != -1)\n            vs[R].par\
    \ = k;\n        return k;\n    }\n    int _dfs(int v, int p) {\n        rep(i,\
    \ 0, SZ(g[v])) if (g[v][i] == p) {\n            g[v].erase(g[v].begin() + i);\n\
    \            break;\n        }\n        int sz = 1, best = 0;\n        for (auto\
    \ &to : g[v]) {\n            int add = _dfs(to, v);\n            sz += add;\n\
    \            if (chmax(best, add))\n                swap(to, g[v].front());\n\
    \        }\n        return sz;\n    }\n\n    using P = pair<int, int>;\n    P\
    \ _merge(const vector<P> &a, Type t) {\n        if (SZ(a) == 1)\n            return\
    \ a[0];\n        int sum = 0;\n        for (auto &[_, sz] : a)\n            sum\
    \ += sz;\n        vector<P> L, R;\n        for (auto &[v, sz] : a) {\n       \
    \     if (sum > sz)\n                L.push_back({v, sz});\n            else\n\
    \                R.push_back({v, sz});\n            sum -= sz * 2;\n        }\n\
    \        auto [lb, slb] = _merge(L, t);\n        auto [rb, srb] = _merge(R, t);\n\
    \        return {_make(-1, lb, rb, t), slb + srb};\n    }\n    P _compress(int\
    \ v) {\n        vector<P> cs{_add_vertex(v)};\n        while (!g[v].empty())\n\
    \            cs.push_back(_add_vertex(v = g[v].front()));\n        return _merge(cs,\
    \ Type::Compress);\n    }\n    P _rake(int v) {\n        vector<P> cs;\n     \
    \   rep(j, 1, SZ(g[v])) cs.push_back(_add_edge(g[v][j]));\n        return cs.empty()\
    \ ? P{-1, 0} : _merge(cs, Type::Rake);\n    }\n    P _add_edge(int v) {\n    \
    \    auto [to, sz] = _compress(v);\n        return P{_make(-1, to, -1, Type::AddEdge),\
    \ sz};\n    }\n    P _add_vertex(int v) {\n        auto [to, sz] = _rake(v);\n\
    \        return P{_make(v, to, -1, to == -1 ? Type::Vertex : Type::AddVertex),\n\
    \                 sz + 1};\n    }\n    void _update(int v) {\n        if (vs[v].t\
    \ == StaticTopTree::Type::Vertex) {\n            path[v] = vertex(v);\n      \
    \  }\n        if (vs[v].t == StaticTopTree::Type::Compress) {\n            path[v]\
    \ = compress(path[vs[v].lp], path[vs[v].rp]);\n        }\n        if (vs[v].t\
    \ == StaticTopTree::Type::Rake) {\n            point[v] = rake(point[vs[v].lp],\
    \ point[vs[v].rp]);\n        }\n        if (vs[v].t == StaticTopTree::Type::AddVertex)\
    \ {\n            path[v] = add_vertex(point[vs[v].lp], v);\n        }\n      \
    \  if (vs[v].t == StaticTopTree::Type::AddEdge) {\n            point[v] = add_edge(path[vs[v].lp]);\n\
    \        }\n    }\n    void _calc(int v) {\n        if (vs[v].lp != -1)\n    \
    \        _calc(vs[v].lp);\n        if (vs[v].rp != -1)\n            _calc(vs[v].rp);\n\
    \        _update(v);\n    }\n};\n\n/**\n * @brief Static TopTree\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/statictoptree.hpp
  requiredBy: []
  timestamp: '2024-06-23 06:04:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/statictoptree.hpp
layout: document
redirect_from:
- /library/Graph/statictoptree.hpp
- /library/Graph/statictoptree.hpp.html
title: Static TopTree
---
