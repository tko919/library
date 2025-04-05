---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Algorithm/projectselection.hpp
    title: Project Selection
  - icon: ':question:'
    path: Graph/maxflow.hpp
    title: Maximum Flow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: K-Project Selection
    links: []
  bundledCode: "#line 2 \"Graph/maxflow.hpp\"\n\r\nstruct MaxFlow {\r\n    struct\
    \ Edge {\r\n        int to, rev;\r\n        ll cap;\r\n    };\r\n    int V;\r\n\
    \    vector<vector<Edge>> G;\r\n    vector<int> itr, level;\r\n    using P = pair<int,\
    \ int>;\r\n    vector<P> es;\r\n\r\n  public:\r\n    MaxFlow() {}\r\n    MaxFlow(int\
    \ V) : V(V) {\r\n        G.assign(V, vector<Edge>());\r\n    }\r\n    int add_vertex()\
    \ {\r\n        G.push_back(vector<Edge>());\r\n        return V++;\r\n    }\r\n\
    \    void add_edge(int from, int to, ll cap) {\r\n        int fid = SZ(G[from]),\
    \ tid = SZ(G[to]);\r\n        if (from == to)\r\n            tid++;\r\n      \
    \  es.push_back({from, fid});\r\n        G[from].push_back({to, tid, cap});\r\n\
    \        G[to].push_back({from, fid, 0});\r\n    }\r\n    struct Type {\r\n  \
    \      int from, to;\r\n        ll cap, recap;\r\n    };\r\n    Type get_edge(int\
    \ i) {\r\n        auto [from, pos] = es[i];\r\n        auto e = G[from][pos];\r\
    \n        auto re = G[e.to][e.rev];\r\n        return Type{from, e.to, e.cap,\
    \ re.cap};\r\n    }\r\n    void bfs(int s) {\r\n        level.assign(V, -1);\r\
    \n        queue<int> q;\r\n        level[s] = 0;\r\n        q.push(s);\r\n   \
    \     while (!q.empty()) {\r\n            int v = q.front();\r\n            q.pop();\r\
    \n            for (auto &e : G[v]) {\r\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\r\n                    level[e.to] = level[v] + 1;\r\n              \
    \      q.push(e.to);\r\n                }\r\n            }\r\n        }\r\n  \
    \  }\r\n    ll dfs(int v, int t, ll f) {\r\n        if (v == t)\r\n          \
    \  return f;\r\n        for (int &i = itr[v]; i < (int)G[v].size(); i++) {\r\n\
    \            Edge &e = G[v][i];\r\n            if (e.cap > 0 && level[v] < level[e.to])\
    \ {\r\n                ll d = dfs(e.to, t, min(f, e.cap));\r\n               \
    \ if (d > 0) {\r\n                    e.cap -= d, G[e.to][e.rev].cap += d;\r\n\
    \                    return d;\r\n                }\r\n            }\r\n     \
    \   }\r\n        return 0;\r\n    }\r\n    ll run(int s, int t) {\r\n        ll\
    \ ret = 0, f;\r\n        while (bfs(s), level[t] >= 0) {\r\n            itr.assign(V,\
    \ 0);\r\n            while ((f = dfs(s, t, INF)) > 0)\r\n                ret +=\
    \ f;\r\n        }\r\n        return ret;\r\n    }\r\n    vector<int> cut() {\r\
    \n        vector<int> ret(V);\r\n        rep(v, 0, V) if (level[v] < 0) ret[v]\
    \ = 1;\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Flow\r\
    \n */\n#line 3 \"Algorithm/projectselection.hpp\"\n\ntemplate <typename Cost>\
    \ struct ProjectSelection {\n    using C1 = array<Cost, 2>;\n    using C2 = array<C1,\
    \ 2>;\n    using P = pair<int, Cost>;\n    int orig, n, S, T;\n    vector<vector<P>>\
    \ es;\n    Cost offset;\n    vector<C1> base;\n\n    ProjectSelection() {}\n \
    \   ProjectSelection(int _n)\n        : orig(_n), n(_n + 2), S(_n), T(_n + 1),\
    \ es(n), offset(0), base(n) {}\n\n    void add_cost(Cost cost) {\n        offset\
    \ += cost;\n    }\n    void add_profit(Cost profit) {\n        add_cost(-profit);\n\
    \    }\n\n    void add_cost(int i, C1 cost) {\n        base[i][0] += cost[0];\n\
    \        base[i][1] += cost[1];\n    }\n    void add_profit(int i, C1 profit)\
    \ {\n        base[i][0] -= profit[0];\n        base[i][1] -= profit[1];\n    }\n\
    \    void add_cost_0(int i, Cost cost) {\n        add_cost(i, C1{cost, 0});\n\
    \    }\n    void add_cost_1(int i, Cost cost) {\n        add_cost(i, C1{0, cost});\n\
    \    }\n    void add_profit_0(int i, Cost profit) {\n        add_cost(i, C1{-profit,\
    \ 0});\n    }\n    void add_profit_1(int i, Cost profit) {\n        add_cost(i,\
    \ C1{0, -profit});\n    }\n\n    void add_cost(int i, int j, C2 cost) {\n    \
    \    Cost A = cost[0][0], B = cost[0][1];\n        Cost C = cost[1][0], D = cost[1][1];\n\
    \        assert(B + C >= A + D);\n        add_cost(A);\n        add_cost(i, C1{0,\
    \ B - A});\n        add_cost(j, C1{0, D - C});\n        add_cost_01(i, j, (B +\
    \ C) - (A + D));\n    }\n    void add_profit(int i, int j, C2 profit) {\n    \
    \    rep(x, 0, 2) rep(y, 0, 2) profit[x][y] = -profit[x][y];\n        add_cost(i,\
    \ j, profit);\n    }\n    void add_cost_01(int i, int j, Cost cost) {\n      \
    \  assert(cost >= 0);\n        if (cost)\n            es[i].push_back({j, cost});\n\
    \    }\n    void add_cost_10(int i, int j, Cost cost) {\n        add_cost_01(j,\
    \ i, cost);\n    }\n    void add_profit_00(int i, int j, Cost profit) {\n    \
    \    add_cost(i, j, C2{-profit, 0, 0, 0});\n    }\n    void add_profit_11(int\
    \ i, int j, Cost profit) {\n        add_cost(i, j, C2{0, 0, 0, -profit});\n  \
    \  }\n\n    void add_profit_all0(vector<int> &xs, Cost profit) {\n        assert(profit\
    \ >= 0);\n        if (profit == 0)\n            return;\n        add_profit(profit);\n\
    \        es.push_back({});\n        es[S].push_back({n, profit});\n        for\
    \ (auto &i : xs)\n            es[n].push_back({i, profit});\n        n++;\n  \
    \  }\n    void add_profit_all1(vector<int> &xs, Cost profit) {\n        assert(profit\
    \ >= 0);\n        if (profit == 0)\n            return;\n        add_profit(profit);\n\
    \        es.push_back({});\n        es[n].push_back({T, profit});\n        for\
    \ (auto &i : xs)\n            es[i].push_back({n, profit});\n        n++;\n  \
    \  }\n\n    pair<Cost, vector<int>> minCost() {\n        MaxFlow mf(n);\n    \
    \    rep(i, 0, orig) {\n            C1 &cost = base[i];\n            if (cost[0]\
    \ <= cost[1]) {\n                add_cost(cost[0]);\n                if (cost[1]\
    \ > cost[0])\n                    es[S].push_back({i, cost[1] - cost[0]});\n \
    \           } else {\n                add_cost(cost[1]);\n                es[i].push_back({T,\
    \ cost[0] - cost[1]});\n            }\n        }\n        rep(v, 0, n) for (auto\
    \ &[u, cost] : es[v]) {\n            mf.add_edge(v, u, cost);\n        }\n   \
    \     Cost ret = offset + mf.run(S, T);\n        vector<int> cut = mf.cut();\n\
    \        cut.resize(orig);\n        return {ret, cut};\n    }\n    pair<Cost,\
    \ vector<int>> maxProfit() {\n        auto ret = minCost();\n        ret.first\
    \ = -ret.first;\n        return ret;\n    }\n};\n\n/**\n * @brief Project Selection\n\
    \ */\n#line 3 \"Algorithm/kprojectselection.hpp\"\n\ntemplate <typename Cost>\
    \ struct KProjectSelection {\n    static constexpr Cost LIM = std::numeric_limits<Cost>::max()\
    \ / 2;\n    int n;\n    vector<int> Ks;\n    vector<vector<int>> pos;\n    ProjectSelection<Cost>\
    \ psp;\n\n    KProjectSelection() {}\n    KProjectSelection(vector<int> &Ks) :\
    \ n(SZ(Ks)), Ks(Ks), pos(n) {\n        int now = 0;\n        rep(i, 0, n) {\n\
    \            pos[i].resize(Ks[i]);\n            rep(j, 1, Ks[i]) pos[i][j] = now++;\n\
    \        }\n        psp = ProjectSelection<Cost>(now);\n        rep(i, 0, n) {\n\
    \            rep(j, 1, Ks[i] - 1) psp.add_cost_10(pos[i][j], pos[i][j + 1], LIM);\n\
    \        }\n    }\n    void add_cost(Cost cost) {\n        psp.add_cost(cost);\n\
    \    }\n    void add_profit(Cost profit) {\n        psp.add_profit(profit);\n\
    \    }\n\n    void add_cost(int i, vector<Cost> &cost) {\n        assert(SZ(cost)\
    \ == Ks[i]);\n        psp.add_cost(cost.back());\n        rep(j, 1, Ks[i]) {\n\
    \            psp.add_cost(pos[i][j], {0, cost[j - 1] - cost[j]});\n        }\n\
    \    }\n    void add_profit(int i, vector<Cost> &profit) {\n        for (auto\
    \ &x : profit)\n            x = -x;\n        add_cost(i, profit);\n    }\n\n \
    \   void add_cost(int i, int j, vector<vector<Cost>> &cost) {\n        assert(SZ(cost)\
    \ == Ks[i]);\n        vector<Cost> ibase(Ks[i]), jbase(Ks[j]);\n        rep(x,\
    \ 0, Ks[i]) {\n            assert(SZ(cost[x]) == Ks[j]);\n            ibase[x]\
    \ = cost[x][0];\n            rep(y, 0, Ks[j]) cost[x][y] -= ibase[x];\n      \
    \  }\n        rep(y, 0, Ks[j]) {\n            jbase[y] = cost[0][y];\n       \
    \     rep(x, 0, Ks[i]) cost[x][y] -= jbase[y];\n        }\n        add_cost(i,\
    \ ibase);\n        add_cost(j, jbase);\n\n        rep(x, 1, Ks[i]) rep(y, 1, Ks[j])\
    \ {\n            Cost add = cost[x][y] - cost[x][y - 1] - cost[x - 1][y] +\n \
    \                      cost[x - 1][y - 1];\n            assert(add <= 0);\n  \
    \          psp.add_profit_00(pos[i][x], pos[j][y], -add);\n        }\n    }\n\n\
    \    pair<Cost, vector<int>> minCost() {\n        auto [ret, ids] = psp.minCost();\n\
    \        vector<int> xs(n);\n        rep(i, 0, n) rep(j, 1, Ks[i]) {\n       \
    \     if (ids[pos[i][j]] == 1)\n                break;\n            xs[i] = j;\n\
    \        }\n        return {ret, xs};\n    }\n    pair<Cost, vector<int>> maxProfit()\
    \ {\n        auto ret = minCost();\n        ret.first = -ret.first;\n        return\
    \ ret;\n    }\n};\n\n/**\n * @brief K-Project Selection\n */\n"
  code: "#pragma once\n#include \"Algorithm/projectselection.hpp\"\n\ntemplate <typename\
    \ Cost> struct KProjectSelection {\n    static constexpr Cost LIM = std::numeric_limits<Cost>::max()\
    \ / 2;\n    int n;\n    vector<int> Ks;\n    vector<vector<int>> pos;\n    ProjectSelection<Cost>\
    \ psp;\n\n    KProjectSelection() {}\n    KProjectSelection(vector<int> &Ks) :\
    \ n(SZ(Ks)), Ks(Ks), pos(n) {\n        int now = 0;\n        rep(i, 0, n) {\n\
    \            pos[i].resize(Ks[i]);\n            rep(j, 1, Ks[i]) pos[i][j] = now++;\n\
    \        }\n        psp = ProjectSelection<Cost>(now);\n        rep(i, 0, n) {\n\
    \            rep(j, 1, Ks[i] - 1) psp.add_cost_10(pos[i][j], pos[i][j + 1], LIM);\n\
    \        }\n    }\n    void add_cost(Cost cost) {\n        psp.add_cost(cost);\n\
    \    }\n    void add_profit(Cost profit) {\n        psp.add_profit(profit);\n\
    \    }\n\n    void add_cost(int i, vector<Cost> &cost) {\n        assert(SZ(cost)\
    \ == Ks[i]);\n        psp.add_cost(cost.back());\n        rep(j, 1, Ks[i]) {\n\
    \            psp.add_cost(pos[i][j], {0, cost[j - 1] - cost[j]});\n        }\n\
    \    }\n    void add_profit(int i, vector<Cost> &profit) {\n        for (auto\
    \ &x : profit)\n            x = -x;\n        add_cost(i, profit);\n    }\n\n \
    \   void add_cost(int i, int j, vector<vector<Cost>> &cost) {\n        assert(SZ(cost)\
    \ == Ks[i]);\n        vector<Cost> ibase(Ks[i]), jbase(Ks[j]);\n        rep(x,\
    \ 0, Ks[i]) {\n            assert(SZ(cost[x]) == Ks[j]);\n            ibase[x]\
    \ = cost[x][0];\n            rep(y, 0, Ks[j]) cost[x][y] -= ibase[x];\n      \
    \  }\n        rep(y, 0, Ks[j]) {\n            jbase[y] = cost[0][y];\n       \
    \     rep(x, 0, Ks[i]) cost[x][y] -= jbase[y];\n        }\n        add_cost(i,\
    \ ibase);\n        add_cost(j, jbase);\n\n        rep(x, 1, Ks[i]) rep(y, 1, Ks[j])\
    \ {\n            Cost add = cost[x][y] - cost[x][y - 1] - cost[x - 1][y] +\n \
    \                      cost[x - 1][y - 1];\n            assert(add <= 0);\n  \
    \          psp.add_profit_00(pos[i][x], pos[j][y], -add);\n        }\n    }\n\n\
    \    pair<Cost, vector<int>> minCost() {\n        auto [ret, ids] = psp.minCost();\n\
    \        vector<int> xs(n);\n        rep(i, 0, n) rep(j, 1, Ks[i]) {\n       \
    \     if (ids[pos[i][j]] == 1)\n                break;\n            xs[i] = j;\n\
    \        }\n        return {ret, xs};\n    }\n    pair<Cost, vector<int>> maxProfit()\
    \ {\n        auto ret = minCost();\n        ret.first = -ret.first;\n        return\
    \ ret;\n    }\n};\n\n/**\n * @brief K-Project Selection\n */"
  dependsOn:
  - Algorithm/projectselection.hpp
  - Graph/maxflow.hpp
  isVerificationFile: false
  path: Algorithm/kprojectselection.hpp
  requiredBy: []
  timestamp: '2024-04-29 14:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/kprojectselection.hpp
layout: document
redirect_from:
- /library/Algorithm/kprojectselection.hpp
- /library/Algorithm/kprojectselection.hpp.html
title: K-Project Selection
---
