---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/maxflow.hpp
    title: Maximum Flow
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_min_cost_b_flow.test.cpp
    title: Verify/LC_min_cost_b_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Minimum Cost b-flow
    links: []
  bundledCode: "#line 2 \"Graph/maxflow.hpp\"\n\r\nstruct MaxFlow {\r\n    struct\
    \ Edge {\r\n        int to, rev;\r\n        ll cap;\r\n    };\r\n    int V;\r\n\
    \    vector<vector<Edge>> G;\r\n    vector<int> itr, level;\r\n    using P = pair<int,\
    \ int>;\r\n    vector<P> es;\r\n\r\n  public:\r\n    MaxFlow() {}\r\n    MaxFlow(int\
    \ V) : V(V) { G.assign(V, vector<Edge>()); }\r\n    int add_vertex() {\r\n   \
    \     G.push_back(vector<Edge>());\r\n        return V++;\r\n    }\r\n    void\
    \ add_edge(int from, int to, ll cap) {\r\n        int fid = SZ(G[from]), tid =\
    \ SZ(G[to]);\r\n        if (from == to)\r\n            tid++;\r\n        es.push_back({from,\
    \ fid});\r\n        G[from].push_back({to, tid, cap});\r\n        G[to].push_back({from,\
    \ fid, 0});\r\n    }\r\n    struct Type {\r\n        int from, to;\r\n       \
    \ ll cap, recap;\r\n    };\r\n    Type get_edge(int i) {\r\n        auto [from,\
    \ pos] = es[i];\r\n        auto e = G[from][pos];\r\n        auto re = G[e.to][e.rev];\r\
    \n        return Type{from, e.to, e.cap, re.cap};\r\n    }\r\n    void bfs(int\
    \ s) {\r\n        level.assign(V, -1);\r\n        queue<int> q;\r\n        level[s]\
    \ = 0;\r\n        q.push(s);\r\n        while (!q.empty()) {\r\n            int\
    \ v = q.front();\r\n            q.pop();\r\n            for (auto &e : G[v]) {\r\
    \n                if (e.cap > 0 && level[e.to] < 0) {\r\n                    level[e.to]\
    \ = level[v] + 1;\r\n                    q.push(e.to);\r\n                }\r\n\
    \            }\r\n        }\r\n    }\r\n    ll dfs(int v, int t, ll f) {\r\n \
    \       if (v == t)\r\n            return f;\r\n        for (int &i = itr[v];\
    \ i < (int)G[v].size(); i++) {\r\n            Edge &e = G[v][i];\r\n         \
    \   if (e.cap > 0 && level[v] < level[e.to]) {\r\n                ll d = dfs(e.to,\
    \ t, min(f, e.cap));\r\n                if (d > 0) {\r\n                    e.cap\
    \ -= d, G[e.to][e.rev].cap += d;\r\n                    return d;\r\n        \
    \        }\r\n            }\r\n        }\r\n        return 0;\r\n    }\r\n   \
    \ ll run(int s, int t) {\r\n        ll ret = 0, f;\r\n        while (bfs(s), level[t]\
    \ >= 0) {\r\n            itr.assign(V, 0);\r\n            while ((f = dfs(s, t,\
    \ INF)) > 0)\r\n                ret += f;\r\n        }\r\n        return ret;\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Flow\r\n */\n#line 3 \"Graph/mincostflow.hpp\"\
    \n\r\n// yosupo orz\r\ntemplate <class Cap, class Cost> struct MinCostFlow {\r\
    \n    struct X {\r\n        int from, to;\r\n        Cap lb, ub, flow;\r\n   \
    \     Cost cost;\r\n    };\r\n    struct Edge {\r\n        int to, rev;\r\n  \
    \      Cap cap;\r\n        Cost cost;\r\n    };\r\n    using P = pair<int, int>;\r\
    \n    int n, m;\r\n    vector<X> es;\r\n    vector<Cap> exc;\r\n    vector<Cost>\
    \ dual;\r\n    vector<vector<Edge>> g;\r\n    Cost MX;\r\n    MinCostFlow(int\
    \ _n) : n(_n), m(0), exc(n), dual(n), g(n), MX(0) {}\r\n    void add_edge(int\
    \ from, int to, Cap lb, Cap ub, Cost cost) {\r\n        m++;\r\n        chmax(MX,\
    \ cost);\r\n        chmax(MX, -cost);\r\n        es.push_back({from, to, lb, ub,\
    \ 0, cost});\r\n    }\r\n    void add_excess(int v, Cap c) { exc[v] += c; }\r\n\
    \    pair<bool, Cost> run() {\r\n        MaxFlow mf(n + 2);\r\n        int S =\
    \ n, T = n + 1;\r\n        Cap psum = 0, nsum = 0;\r\n        for (auto &e : es)\
    \ {\r\n            exc[e.to] += e.lb;\r\n            exc[e.from] -= e.lb;\r\n\
    \            mf.add_edge(e.from, e.to, e.ub - e.lb);\r\n        }\r\n        rep(i,\
    \ 0, n) {\r\n            if (exc[i] > 0) {\r\n                psum += exc[i];\r\
    \n                mf.add_edge(S, i, exc[i]);\r\n            }\r\n            if\
    \ (exc[i] < 0) {\r\n                nsum += -exc[i];\r\n                mf.add_edge(i,\
    \ T, -exc[i]);\r\n            }\r\n        }\r\n\r\n        if (psum != nsum or\
    \ mf.run(S, T) != psum)\r\n            return {false, 0};\r\n\r\n        using\
    \ P = pair<int, int>;\r\n        vector<P> pos;\r\n        rep(i, 0, m) {\r\n\
    \            auto e = mf.get_edge(i);\r\n            Cost cost = es[i].cost *\
    \ n;\r\n            int fid = SZ(g[e.from]), tid = SZ(g[e.to]);\r\n          \
    \  if (e.from == e.to)\r\n                tid++;\r\n            pos.push_back({e.from,\
    \ fid});\r\n            g[e.from].push_back({e.to, tid, e.cap, cost});\r\n   \
    \         g[e.to].push_back({e.from, fid, e.recap, -cost});\r\n        }\r\n\r\
    \n        // solve\r\n        Cost eps = MX * n + 1;\r\n        while (eps > 1)\
    \ {\r\n            eps = max<Cost>(eps >> 2, 1);\r\n            refine(eps);\r\
    \n        }\r\n\r\n        Cost ret = 0;\r\n        rep(i, 0, m) {\r\n       \
    \     auto [from, fid] = pos[i];\r\n            es[i].flow = es[i].ub - g[from][fid].cap;\r\
    \n            ret += es[i].flow * es[i].cost;\r\n        }\r\n        dual.assign(n,\
    \ 0);\r\n        for (;;) {\r\n            bool upd = 0;\r\n            rep(i,\
    \ 0, n) {\r\n                for (auto &e : g[i])\r\n                    if (e.cap)\
    \ {\r\n                        auto cost = dual[i] + e.cost / n;\r\n         \
    \               if (chmin(dual[e.to], cost)) {\r\n                           \
    \ upd = 1;\r\n                        }\r\n                    }\r\n         \
    \   }\r\n            if (!upd)\r\n                break;\r\n        }\r\n    \
    \    return {true, ret};\r\n    }\r\n    Cap get_flow(int i) const { return es[i].flow;\
    \ }\r\n\r\n  private:\r\n    void refine(Cost &eps) {\r\n        exc.assign(n,\
    \ 0);\r\n        vector<int> used(n);\r\n        queue<int> que;\r\n        vector<int>\
    \ iter(n);\r\n\r\n        auto cost = [&](int from, const Edge &e) {\r\n     \
    \       return e.cost + dual[from] - dual[e.to];\r\n        };\r\n        auto\
    \ push = [&](int from, Edge &e, Cap cap) {\r\n            exc[from] -= cap;\r\n\
    \            exc[e.to] += cap;\r\n            g[e.to][e.rev].cap += cap;\r\n \
    \           e.cap -= cap;\r\n        };\r\n        auto relabel = [&](int v) {\r\
    \n            iter[v] = 0;\r\n            Cost down = MX * (n + 1);\r\n      \
    \      for (auto &e : g[v])\r\n                if (e.cap) {\r\n              \
    \      chmin(down, eps + cost(v, e));\r\n                }\r\n            dual[v]\
    \ -= down;\r\n            que.push(v);\r\n            used[v] = 1;\r\n       \
    \ };\r\n\r\n        rep(i, 0, n) {\r\n            for (auto &e : g[i])\r\n   \
    \             if (e.cap and cost(i, e) < 0) {\r\n                    push(i, e,\
    \ e.cap);\r\n                }\r\n        }\r\n        rep(i, 0, n) if (exc[i]\
    \ > 0) {\r\n            used[i] = 1;\r\n            que.push(i);\r\n        }\r\
    \n        while (!que.empty()) {\r\n            auto v = que.front();\r\n    \
    \        que.pop();\r\n            used[v] = 0;\r\n            for (int &i = iter[v];\
    \ i < SZ(g[v]); i++) {\r\n                auto &e = g[v][i];\r\n             \
    \   if (e.cap and cost(v, e) < 0) {\r\n                    push(v, e, min(exc[v],\
    \ e.cap));\r\n                    if (!used[e.to] and exc[e.to] > 0) {\r\n   \
    \                     used[e.to] = 1;\r\n                        que.push(e.to);\r\
    \n                    }\r\n                    if (exc[v] == 0)\r\n          \
    \              break;\r\n                }\r\n            }\r\n            if\
    \ (exc[v] > 0) {\r\n                relabel(v);\r\n            }\r\n        }\r\
    \n        eps = 0;\r\n        rep(i, 0, n) {\r\n            for (auto &e : g[i])\r\
    \n                if (e.cap) {\r\n                    chmax(eps, -cost(i, e));\r\
    \n                }\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Minimum\
    \ Cost b-flow\r\n */\n"
  code: "#pragma once\r\n#include \"Graph/maxflow.hpp\"\r\n\r\n// yosupo orz\r\ntemplate\
    \ <class Cap, class Cost> struct MinCostFlow {\r\n    struct X {\r\n        int\
    \ from, to;\r\n        Cap lb, ub, flow;\r\n        Cost cost;\r\n    };\r\n \
    \   struct Edge {\r\n        int to, rev;\r\n        Cap cap;\r\n        Cost\
    \ cost;\r\n    };\r\n    using P = pair<int, int>;\r\n    int n, m;\r\n    vector<X>\
    \ es;\r\n    vector<Cap> exc;\r\n    vector<Cost> dual;\r\n    vector<vector<Edge>>\
    \ g;\r\n    Cost MX;\r\n    MinCostFlow(int _n) : n(_n), m(0), exc(n), dual(n),\
    \ g(n), MX(0) {}\r\n    void add_edge(int from, int to, Cap lb, Cap ub, Cost cost)\
    \ {\r\n        m++;\r\n        chmax(MX, cost);\r\n        chmax(MX, -cost);\r\
    \n        es.push_back({from, to, lb, ub, 0, cost});\r\n    }\r\n    void add_excess(int\
    \ v, Cap c) { exc[v] += c; }\r\n    pair<bool, Cost> run() {\r\n        MaxFlow\
    \ mf(n + 2);\r\n        int S = n, T = n + 1;\r\n        Cap psum = 0, nsum =\
    \ 0;\r\n        for (auto &e : es) {\r\n            exc[e.to] += e.lb;\r\n   \
    \         exc[e.from] -= e.lb;\r\n            mf.add_edge(e.from, e.to, e.ub -\
    \ e.lb);\r\n        }\r\n        rep(i, 0, n) {\r\n            if (exc[i] > 0)\
    \ {\r\n                psum += exc[i];\r\n                mf.add_edge(S, i, exc[i]);\r\
    \n            }\r\n            if (exc[i] < 0) {\r\n                nsum += -exc[i];\r\
    \n                mf.add_edge(i, T, -exc[i]);\r\n            }\r\n        }\r\n\
    \r\n        if (psum != nsum or mf.run(S, T) != psum)\r\n            return {false,\
    \ 0};\r\n\r\n        using P = pair<int, int>;\r\n        vector<P> pos;\r\n \
    \       rep(i, 0, m) {\r\n            auto e = mf.get_edge(i);\r\n           \
    \ Cost cost = es[i].cost * n;\r\n            int fid = SZ(g[e.from]), tid = SZ(g[e.to]);\r\
    \n            if (e.from == e.to)\r\n                tid++;\r\n            pos.push_back({e.from,\
    \ fid});\r\n            g[e.from].push_back({e.to, tid, e.cap, cost});\r\n   \
    \         g[e.to].push_back({e.from, fid, e.recap, -cost});\r\n        }\r\n\r\
    \n        // solve\r\n        Cost eps = MX * n + 1;\r\n        while (eps > 1)\
    \ {\r\n            eps = max<Cost>(eps >> 2, 1);\r\n            refine(eps);\r\
    \n        }\r\n\r\n        Cost ret = 0;\r\n        rep(i, 0, m) {\r\n       \
    \     auto [from, fid] = pos[i];\r\n            es[i].flow = es[i].ub - g[from][fid].cap;\r\
    \n            ret += es[i].flow * es[i].cost;\r\n        }\r\n        dual.assign(n,\
    \ 0);\r\n        for (;;) {\r\n            bool upd = 0;\r\n            rep(i,\
    \ 0, n) {\r\n                for (auto &e : g[i])\r\n                    if (e.cap)\
    \ {\r\n                        auto cost = dual[i] + e.cost / n;\r\n         \
    \               if (chmin(dual[e.to], cost)) {\r\n                           \
    \ upd = 1;\r\n                        }\r\n                    }\r\n         \
    \   }\r\n            if (!upd)\r\n                break;\r\n        }\r\n    \
    \    return {true, ret};\r\n    }\r\n    Cap get_flow(int i) const { return es[i].flow;\
    \ }\r\n\r\n  private:\r\n    void refine(Cost &eps) {\r\n        exc.assign(n,\
    \ 0);\r\n        vector<int> used(n);\r\n        queue<int> que;\r\n        vector<int>\
    \ iter(n);\r\n\r\n        auto cost = [&](int from, const Edge &e) {\r\n     \
    \       return e.cost + dual[from] - dual[e.to];\r\n        };\r\n        auto\
    \ push = [&](int from, Edge &e, Cap cap) {\r\n            exc[from] -= cap;\r\n\
    \            exc[e.to] += cap;\r\n            g[e.to][e.rev].cap += cap;\r\n \
    \           e.cap -= cap;\r\n        };\r\n        auto relabel = [&](int v) {\r\
    \n            iter[v] = 0;\r\n            Cost down = MX * (n + 1);\r\n      \
    \      for (auto &e : g[v])\r\n                if (e.cap) {\r\n              \
    \      chmin(down, eps + cost(v, e));\r\n                }\r\n            dual[v]\
    \ -= down;\r\n            que.push(v);\r\n            used[v] = 1;\r\n       \
    \ };\r\n\r\n        rep(i, 0, n) {\r\n            for (auto &e : g[i])\r\n   \
    \             if (e.cap and cost(i, e) < 0) {\r\n                    push(i, e,\
    \ e.cap);\r\n                }\r\n        }\r\n        rep(i, 0, n) if (exc[i]\
    \ > 0) {\r\n            used[i] = 1;\r\n            que.push(i);\r\n        }\r\
    \n        while (!que.empty()) {\r\n            auto v = que.front();\r\n    \
    \        que.pop();\r\n            used[v] = 0;\r\n            for (int &i = iter[v];\
    \ i < SZ(g[v]); i++) {\r\n                auto &e = g[v][i];\r\n             \
    \   if (e.cap and cost(v, e) < 0) {\r\n                    push(v, e, min(exc[v],\
    \ e.cap));\r\n                    if (!used[e.to] and exc[e.to] > 0) {\r\n   \
    \                     used[e.to] = 1;\r\n                        que.push(e.to);\r\
    \n                    }\r\n                    if (exc[v] == 0)\r\n          \
    \              break;\r\n                }\r\n            }\r\n            if\
    \ (exc[v] > 0) {\r\n                relabel(v);\r\n            }\r\n        }\r\
    \n        eps = 0;\r\n        rep(i, 0, n) {\r\n            for (auto &e : g[i])\r\
    \n                if (e.cap) {\r\n                    chmax(eps, -cost(i, e));\r\
    \n                }\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Minimum\
    \ Cost b-flow\r\n */"
  dependsOn:
  - Graph/maxflow.hpp
  isVerificationFile: false
  path: Graph/mincostflow.hpp
  requiredBy: []
  timestamp: '2024-01-12 05:39:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_min_cost_b_flow.test.cpp
documentation_of: Graph/mincostflow.hpp
layout: document
redirect_from:
- /library/Graph/mincostflow.hpp
- /library/Graph/mincostflow.hpp.html
title: Minimum Cost b-flow
---
