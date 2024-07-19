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
    document_title: Eulerian Trail
    links: []
  bundledCode: "#line 2 \"DataStructure/unionfind.hpp\"\n\r\nstruct UnionFind{\r\n\
    \    vector<int> par; int n;\r\n    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\
    \n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    bool unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return\
    \ false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y;\
    \ n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */\n\
    #line 3 \"Graph/euler.hpp\"\n\ntemplate <bool directed> struct EulerianTrail {\n\
    \    using P = pair<int, int>;\n    int n, m;\n    vector<vector<P>> g;\n    UnionFind\
    \ uni;\n    vector<P> es;\n    vector<int> used, deg;\n    EulerianTrail() {}\n\
    \    EulerianTrail(int N) : n(N), m(0), g(n), uni(n), deg(n) {}\n    void add_edge(int\
    \ u, int v) {\n        es.push_back({u, v});\n        g[u].push_back({v, m});\n\
    \        uni.unite(u, v);\n        if (directed) {\n            deg[u]++;\n  \
    \          deg[v]--;\n        } else {\n            g[v].push_back({u, m});\n\
    \            deg[u]++;\n            deg[v]++;\n        }\n        m++;\n    }\n\
    \    pair<vector<int>, vector<vector<int>>> run() {\n        map<int, vector<int>>\
    \ grps;\n        rep(v, 0, n) grps[uni.root(v)].push_back(v);\n        vector<int>\
    \ start;\n        vector<vector<int>> ret;\n        used.assign(m, 0);\n     \
    \   for (auto &[_, vs] : grps) {\n            int S = -1;\n            if (directed)\
    \ {\n                for (auto &v : vs) {\n                    if (abs(deg[v])\
    \ > 1)\n                        return {};\n                    else if (deg[v]\
    \ == 1) {\n                        if (S == -1)\n                            S\
    \ = v;\n                        else\n                            return {};\n\
    \                    }\n                }\n            } else {\n            \
    \    int odd = 0;\n                for (auto &v : vs) {\n                    if\
    \ (deg[v] & 1) {\n                        S = v;\n                        odd++;\n\
    \                    }\n                }\n                if (odd > 2)\n    \
    \                return {};\n            }\n            if (S == -1)\n       \
    \         S = vs.front();\n            auto add = get(S);\n            if (add.size())\
    \ {\n                start.push_back(S);\n                ret.push_back(add);\n\
    \            }\n        }\n        return {start, ret};\n    }\n\n  private:\n\
    \    vector<int> get(int s) {\n        stack<P> st;\n        vector<int> ret;\n\
    \        st.push({s, -1});\n        while (!st.empty()) {\n            int v =\
    \ st.top().first;\n            if (g[v].empty()) {\n                ret.push_back(st.top().second);\n\
    \                st.pop();\n            } else {\n                auto &e = g[v].back();\n\
    \                g[v].pop_back();\n                if (used[e.second])\n     \
    \               continue;\n                used[e.second] = 1;\n             \
    \   st.push(e);\n            }\n        }\n        ret.pop_back();\n        reverse(ALL(ret));\n\
    \        return ret;\n    }\n};\n\n/**\n * @brief Eulerian Trail\n */\n"
  code: "#pragma once\n#include \"DataStructure/unionfind.hpp\"\n\ntemplate <bool\
    \ directed> struct EulerianTrail {\n    using P = pair<int, int>;\n    int n,\
    \ m;\n    vector<vector<P>> g;\n    UnionFind uni;\n    vector<P> es;\n    vector<int>\
    \ used, deg;\n    EulerianTrail() {}\n    EulerianTrail(int N) : n(N), m(0), g(n),\
    \ uni(n), deg(n) {}\n    void add_edge(int u, int v) {\n        es.push_back({u,\
    \ v});\n        g[u].push_back({v, m});\n        uni.unite(u, v);\n        if\
    \ (directed) {\n            deg[u]++;\n            deg[v]--;\n        } else {\n\
    \            g[v].push_back({u, m});\n            deg[u]++;\n            deg[v]++;\n\
    \        }\n        m++;\n    }\n    pair<vector<int>, vector<vector<int>>> run()\
    \ {\n        map<int, vector<int>> grps;\n        rep(v, 0, n) grps[uni.root(v)].push_back(v);\n\
    \        vector<int> start;\n        vector<vector<int>> ret;\n        used.assign(m,\
    \ 0);\n        for (auto &[_, vs] : grps) {\n            int S = -1;\n       \
    \     if (directed) {\n                for (auto &v : vs) {\n                \
    \    if (abs(deg[v]) > 1)\n                        return {};\n              \
    \      else if (deg[v] == 1) {\n                        if (S == -1)\n       \
    \                     S = v;\n                        else\n                 \
    \           return {};\n                    }\n                }\n           \
    \ } else {\n                int odd = 0;\n                for (auto &v : vs) {\n\
    \                    if (deg[v] & 1) {\n                        S = v;\n     \
    \                   odd++;\n                    }\n                }\n       \
    \         if (odd > 2)\n                    return {};\n            }\n      \
    \      if (S == -1)\n                S = vs.front();\n            auto add = get(S);\n\
    \            if (add.size()) {\n                start.push_back(S);\n        \
    \        ret.push_back(add);\n            }\n        }\n        return {start,\
    \ ret};\n    }\n\n  private:\n    vector<int> get(int s) {\n        stack<P> st;\n\
    \        vector<int> ret;\n        st.push({s, -1});\n        while (!st.empty())\
    \ {\n            int v = st.top().first;\n            if (g[v].empty()) {\n  \
    \              ret.push_back(st.top().second);\n                st.pop();\n  \
    \          } else {\n                auto &e = g[v].back();\n                g[v].pop_back();\n\
    \                if (used[e.second])\n                    continue;\n        \
    \        used[e.second] = 1;\n                st.push(e);\n            }\n   \
    \     }\n        ret.pop_back();\n        reverse(ALL(ret));\n        return ret;\n\
    \    }\n};\n\n/**\n * @brief Eulerian Trail\n */"
  dependsOn:
  - DataStructure/unionfind.hpp
  isVerificationFile: false
  path: Graph/euler.hpp
  requiredBy: []
  timestamp: '2024-01-17 06:35:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/euler.hpp
layout: document
redirect_from:
- /library/Graph/euler.hpp
- /library/Graph/euler.hpp.html
title: Eulerian Trail
---
