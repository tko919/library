---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/unionfind.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Optimal Topological sort
    links: []
  bundledCode: "#line 2 \"DataStructure/unionfind.hpp\"\n\r\nstruct UnionFind{\r\n\
    \    vector<int> par; int n;\r\n    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\
    \n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    bool unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return\
    \ false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y;\
    \ n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */\n\
    #line 3 \"Graph/opttoposort.hpp\"\n\n// root:0, minimize sum_{i<j} w1[q_i]*w0[q_j]\n\
    pair<ll, vector<int>> OptimalToposort(int n, vector<int> &p, vector<ll> &w0,\n\
    \                                      vector<ll> &w1) {\n    struct Node {\n\
    \        ll zero, one, inv;\n        Node(ll z = 0, ll o = 0, ll i = 0) : zero(z),\
    \ one(o), inv(i) {}\n        bool operator<(const Node &other) const {\n     \
    \       if (other.zero == 0 and other.one == 0)\n                return 1;\n \
    \           if (zero == 0 and one == 0)\n                return 0;\n         \
    \   return zero * other.one < one * other.zero;\n        }\n        bool operator!=(const\
    \ Node &other) const {\n            return zero != other.zero or one != other.one;\n\
    \        }\n    };\n    using P = pair<Node, int>;\n    priority_queue<P> pq;\n\
    \    UnionFind uni(n);\n    vector<Node> info(n);\n    rep(i, 0, n) {\n      \
    \  info[i] = Node{w0[i], w1[i], 0};\n        if (i)\n            pq.push({info[i],\
    \ i});\n    }\n    vector<int> head(n);\n    iota(ALL(head), 0);\n    vector<list<int>>\
    \ buf(n);\n    rep(i, 0, n) buf[i] = {i};\n    while (!pq.empty()) {\n       \
    \ auto [pre, x] = pq.top();\n        pq.pop();\n        if (uni.root(x) != x or\
    \ pre != info[x])\n            continue;\n        int par = p[head[x]];\n    \
    \    if (par == -1)\n            continue;\n        assert(par != -1);\n     \
    \   par = uni.root(par);\n        uni.unite(x, par);\n        buf[par].splice(buf[par].end(),\
    \ buf[x]);\n        int nxt = uni.root(x);\n        head[nxt] = head[par];\n \
    \       Node X = info[par], Y = info[x];\n        Node cur = {X.zero + Y.zero,\
    \ X.one + Y.one,\n                    X.inv + Y.inv + X.one * Y.zero};\n     \
    \   info[nxt] = cur;\n        if (uni.root(0) != nxt) {\n            pq.push({info[nxt],\
    \ nxt});\n        }\n        swap(buf[nxt], buf[par]);\n    }\n    vector<int>\
    \ ord;\n    for (auto &x : buf[uni.root(0)])\n        ord.push_back(x);\n    return\
    \ {info[uni.root(0)].inv, ord};\n};\n\n/**\n * @brief Optimal Topological sort\n\
    \ */\n"
  code: "#pragma once\n#include \"DataStructure/unionfind.hpp\"\n\n// root:0, minimize\
    \ sum_{i<j} w1[q_i]*w0[q_j]\npair<ll, vector<int>> OptimalToposort(int n, vector<int>\
    \ &p, vector<ll> &w0,\n                                      vector<ll> &w1) {\n\
    \    struct Node {\n        ll zero, one, inv;\n        Node(ll z = 0, ll o =\
    \ 0, ll i = 0) : zero(z), one(o), inv(i) {}\n        bool operator<(const Node\
    \ &other) const {\n            if (other.zero == 0 and other.one == 0)\n     \
    \           return 1;\n            if (zero == 0 and one == 0)\n             \
    \   return 0;\n            return zero * other.one < one * other.zero;\n     \
    \   }\n        bool operator!=(const Node &other) const {\n            return\
    \ zero != other.zero or one != other.one;\n        }\n    };\n    using P = pair<Node,\
    \ int>;\n    priority_queue<P> pq;\n    UnionFind uni(n);\n    vector<Node> info(n);\n\
    \    rep(i, 0, n) {\n        info[i] = Node{w0[i], w1[i], 0};\n        if (i)\n\
    \            pq.push({info[i], i});\n    }\n    vector<int> head(n);\n    iota(ALL(head),\
    \ 0);\n    vector<list<int>> buf(n);\n    rep(i, 0, n) buf[i] = {i};\n    while\
    \ (!pq.empty()) {\n        auto [pre, x] = pq.top();\n        pq.pop();\n    \
    \    if (uni.root(x) != x or pre != info[x])\n            continue;\n        int\
    \ par = p[head[x]];\n        if (par == -1)\n            continue;\n        assert(par\
    \ != -1);\n        par = uni.root(par);\n        uni.unite(x, par);\n        buf[par].splice(buf[par].end(),\
    \ buf[x]);\n        int nxt = uni.root(x);\n        head[nxt] = head[par];\n \
    \       Node X = info[par], Y = info[x];\n        Node cur = {X.zero + Y.zero,\
    \ X.one + Y.one,\n                    X.inv + Y.inv + X.one * Y.zero};\n     \
    \   info[nxt] = cur;\n        if (uni.root(0) != nxt) {\n            pq.push({info[nxt],\
    \ nxt});\n        }\n        swap(buf[nxt], buf[par]);\n    }\n    vector<int>\
    \ ord;\n    for (auto &x : buf[uni.root(0)])\n        ord.push_back(x);\n    return\
    \ {info[uni.root(0)].inv, ord};\n};\n\n/**\n * @brief Optimal Topological sort\n\
    \ */"
  dependsOn:
  - DataStructure/unionfind.hpp
  isVerificationFile: false
  path: Graph/opttoposort.hpp
  requiredBy: []
  timestamp: '2025-02-02 04:09:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/opttoposort.hpp
layout: document
redirect_from:
- /library/Graph/opttoposort.hpp
- /library/Graph/opttoposort.hpp.html
title: Optimal Topological sort
---
