---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/bimatching.hpp
    title: Bipartite Matching
  - icon: ':warning:'
    path: Graph/dmdecomp.hpp
    title: DM decomposition
  - icon: ':x:'
    path: Graph/scc.hpp
    title: Strongly Connected Components
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Matroid
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
    \ Random\r\n */\n#line 3 \"Graph/bimatching.hpp\"\n\r\nvector<int> BiMatching(int\
    \ n, int m, vector<vector<int>> &g) {\r\n    rep(v, 0, n) Random::shuffle(ALL(g[v]));\r\
    \n    vector<int> L(n, -1), R(m, -1);\r\n    for (;;) {\r\n        vector<int>\
    \ par(n, -1), root(n, -1);\r\n        queue<int> que;\r\n        rep(i, 0, n)\
    \ if (L[i] == -1) {\r\n            que.push(i);\r\n            root[i] = i;\r\n\
    \        }\r\n        bool upd = 0;\r\n        while (!que.empty()) {\r\n    \
    \        int v = que.front();\r\n            que.pop();\r\n            if (L[root[v]]\
    \ != -1)\r\n                continue;\r\n            for (auto u : g[v]) {\r\n\
    \                if (R[u] == -1) {\r\n                    while (u != -1) {\r\n\
    \                        R[u] = v;\r\n                        swap(L[v], u);\r\
    \n                        v = par[v];\r\n                    }\r\n           \
    \         upd = 1;\r\n                    break;\r\n                }\r\n    \
    \            int to = R[u];\r\n                if (par[to] == -1) {\r\n      \
    \              root[to] = root[v];\r\n                    par[to] = v;\r\n   \
    \                 que.push(to);\r\n                }\r\n            }\r\n    \
    \    }\r\n        if (!upd)\r\n            break;\r\n    }\r\n    return L;\r\n\
    }\r\n\r\n/**\r\n * @brief Bipartite Matching\r\n */\n#line 2 \"Graph/scc.hpp\"\
    \n\r\nstruct SCC{\r\n    int n,m,cur;\r\n    vector<vector<int>> g;\r\n    vector<int>\
    \ low,ord,id;\r\n    SCC(int _n=0):n(_n),m(0),cur(0),g(_n),low(_n),ord(_n,-1),id(_n){}\r\
    \n    void resize(int _n){\r\n        n=_n;\r\n        g.resize(n);\r\n      \
    \  low.resize(n);\r\n        ord.resize(n,-1);\r\n        id.resize(n);\r\n  \
    \  }\r\n    void add_edge(int u,int v){g[u].emplace_back(v);}\r\n    void dfs(int\
    \ v,vector<int>& used){\r\n        ord[v]=low[v]=cur++;\r\n        used.emplace_back(v);\r\
    \n        for(auto& nxt:g[v]){\r\n            if(ord[nxt]==-1){\r\n          \
    \      dfs(nxt,used); chmin(low[v],low[nxt]);\r\n            }\r\n           \
    \ else{\r\n                chmin(low[v],ord[nxt]);\r\n            }\r\n      \
    \  }\r\n        if(ord[v]==low[v]){\r\n            while(1){\r\n             \
    \   int add=used.back(); used.pop_back();\r\n                ord[add]=n; id[add]=m;\r\
    \n                if(v==add)break;\r\n            }\r\n            m++;\r\n  \
    \      }\r\n    }\r\n    void run(){\r\n        vector<int> used;\r\n        rep(v,0,n)if(ord[v]==-1)dfs(v,used);\r\
    \n        for(auto& x:id)x=m-1-x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Strongly\
    \ Connected Components\r\n */\n#line 4 \"Graph/dmdecomp.hpp\"\n\nvector<vector<int>>\
    \ DMdecomposition(int n, int m, vector<vector<int>> &g,\n                    \
    \                vector<int> match) {\n    if (match.empty())\n        match =\
    \ BiMatching(n, m, g);\n    vector G(n + m, vector<int>()), REV(n + m, vector<int>());\n\
    \    rep(i, 0, n) for (auto &j : g[i]) {\n        G[i].push_back(j + n);\n   \
    \     REV[j + n].push_back(i);\n    }\n    vector<int> R(m, -1);\n    rep(i, 0,\
    \ n) if (match[i] != -1) {\n        G[match[i] + n].push_back(i);\n        REV[i].push_back(match[i]\
    \ + n);\n        R[match[i]] = i;\n    }\n\n    vector<int> V0, Vinf;\n    queue<int>\
    \ que;\n    vector<int> used(n + m);\n    rep(i, 0, n) if (match[i] == -1) {\n\
    \        used[i] = 1;\n        que.push(i);\n    }\n    while (!que.empty()) {\n\
    \        int v = que.front();\n        que.pop();\n        Vinf.push_back(v);\n\
    \        for (auto &to : G[v])\n            if (!used[to]) {\n               \
    \ used[to] = 1;\n                que.push(to);\n            }\n    }\n    rep(i,\
    \ 0, m) if (R[i] == -1) {\n        used[i + n] = 1;\n        que.push(i + n);\n\
    \    }\n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        V0.push_back(v);\n        for (auto &to : REV[v])\n            if (!used[to])\
    \ {\n                used[to] = 1;\n                que.push(to);\n          \
    \  }\n    }\n\n    SCC scc(n + m);\n    rep(i, 0, n + m) for (auto &to : G[i])\
    \ {\n        if (!used[i] and !used[to])\n            scc.add_edge(i, to);\n \
    \   }\n    scc.run();\n    vector group(scc.m, vector<int>());\n    rep(i, 0,\
    \ n + m) if (!used[i]) group[scc.id[i]].push_back(i);\n\n    vector<vector<int>>\
    \ ret;\n    ret.push_back(V0);\n    for (auto &v : group)\n        ret.push_back(v);\n\
    \    ret.push_back(Vinf);\n    return ret;\n}\n\n/**\n * @brief DM decomposition\n\
    \ */\n#line 4 \"Algorithm/matroid.hpp\"\n\nstruct GraphicMatroid {\n    using\
    \ P = pair<int, int>;\n    int n;\n    vector<P> E;\n    vector<vector<P>> G;\n\
    \    vector<int> allow;\n    GraphicMatroid() {}\n    GraphicMatroid(int n, vector<P>\
    \ &E) : n(n), E(E), G(n) {\n        rep(i, 0, SZ(E)) {\n            auto [u, v]\
    \ = E[i];\n            G[u].push_back({v, i});\n            G[v].push_back({u,\
    \ i});\n        }\n    }\n    void set(vector<int> &I) {\n        allow = I;\n\
    \    }\n    vector<int> circuit(int e) {\n        auto [x, y] = E[e];\n      \
    \  vector<int> ret;\n        ret.push_back(e);\n        auto dfs = [&](auto &dfs,\
    \ int v, int p) -> bool {\n            if (v == y)\n                return true;\n\
    \            for (auto &[to, i] : G[v])\n                if (allow[i] and to !=\
    \ p) {\n                    ret.push_back(i);\n                    if (dfs(dfs,\
    \ to, v))\n                        return true;\n                    ret.pop_back();\n\
    \                }\n            return false;\n        };\n        if (dfs(dfs,\
    \ x, -1))\n            return ret;\n        else\n            return {};\n   \
    \ }\n};\n\nstruct PartitionMatroid {\n    vector<int> grp; // -1:not assign\n\
    \    vector<int> lim;\n    vector<vector<int>> cnt;\n    PartitionMatroid() {}\n\
    \    PartitionMatroid(vector<int> &grp, vector<int> lim) : grp(grp), lim(lim)\
    \ {}\n    void set(vector<int> &I) {\n        cnt.assign(SZ(lim), {});\n     \
    \   rep(i, 0, SZ(grp)) if (I[i] != 0 and grp[i] != -1) {\n            cnt[grp[i]].push_back(i);\n\
    \        }\n    }\n    vector<int> circuit(int e) {\n        if (grp[e] == -1)\n\
    \            return {};\n        if (SZ(cnt[grp[e]]) + 1 > lim[grp[e]]) {\n  \
    \          vector<int> ret = cnt[grp[e]];\n            ret.push_back(e);\n   \
    \         return ret;\n        } else\n            return {};\n    }\n};\n\nstruct\
    \ TransversalMatroid {\n    using P = pair<int, int>;\n    int n, m;\n    vector<vector<int>>\
    \ G, aug;\n    vector<int> match, fixed;\n    TransversalMatroid() {}\n    TransversalMatroid(int\
    \ n, int m, vector<P> &E)\n        : n(n), m(m), G(n), aug(n), fixed(n) {\n  \
    \      for (auto &[u, v] : E)\n            G[u].push_back(v);\n    }\n    void\
    \ set(vector<int> &I) {\n        vector g(n, vector<int>());\n        rep(e, 0,\
    \ n) if (I[e]) {\n            for (auto &to : G[e])\n                g[e].push_back(to);\n\
    \        }\n        auto match = BiMatching(n, m, g);\n        auto dm = DMdecomposition(n,\
    \ m, g, match);\n        fixed.assign(m, 1);\n        for (auto &v : dm.front())\n\
    \            if (v >= n)\n                fixed[v - n] = 0;\n        aug.assign(n\
    \ + m, {});\n        rep(e, 0, n) {\n            for (auto &to : G[e])\n     \
    \           aug[e].push_back(to + n);\n        }\n        rep(i, 0, n) if (match[i]\
    \ != -1) aug[match[i] + n].push_back(i);\n    }\n    vector<int> circuit(int e)\
    \ {\n        for (auto &to : G[e])\n            if (!fixed[to]) {\n          \
    \      return {};\n            }\n\n        vector<int> used(n + m);\n       \
    \ queue<int> que;\n        used[e] = 1;\n        que.push(e);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (auto &to : aug[v])\n                if (!used[to]) {\n                    used[to]\
    \ = 1;\n                    que.push(to);\n                }\n        }\n    \
    \    vector<int> ret;\n        rep(i, 0, n) if (used[i]) ret.push_back(i);\n \
    \       return ret;\n    }\n};\n\ntemplate <typename M1, typename M2, typename\
    \ Val>\npair<vector<Val>, vector<vector<int>>>\nMinimumMatroidIntersection(M1\
    \ &m1, M2 &m2, vector<Val> &ws) {\n    using P = pair<Val, int>;\n    int n =\
    \ SZ(ws);\n\n    vector<Val> ret1;\n    vector<vector<int>> ret2;\n\n    Val profit\
    \ = 0;\n    vector<int> I(n);\n    ret1.push_back(profit);\n    ret2.push_back(I);\n\
    \n    for (;;) {\n        vector G(n + 2, vector<P>());\n        int S = n, T\
    \ = n + 1;\n        m1.set(I);\n        m2.set(I);\n\n        rep(e, 0, n) {\n\
    \            if (I[e])\n                continue;\n            auto c1 = m1.circuit(e);\n\
    \            if (c1.empty())\n                G[S].push_back({ws[e] * (n + 1)\
    \ + 1, e});\n            else\n                for (auto &to : c1)\n         \
    \           if (e != to) {\n                        G[to].push_back({ws[e] * (n\
    \ + 1) + 1, e});\n                    }\n            auto c2 = m2.circuit(e);\n\
    \            if (c2.empty())\n                G[e].push_back({Val(0), T});\n \
    \           else\n                for (auto &to : c2)\n                    if\
    \ (e != to) {\n                        G[e].push_back({-ws[to] * (n + 1) + 1,\
    \ to});\n                    }\n        }\n\n        vector<ll> dist(n + 2, INF);\n\
    \        dist[S] = 0;\n        vector<int> pre(n + 2, -1);\n        for (;;) {\n\
    \            bool upd = 0;\n            rep(v, 0, n + 2) if (dist[v] != INF) {\n\
    \                for (auto &[cost, to] : G[v]) {\n                    if (chmin(dist[to],\
    \ dist[v] + cost)) {\n                        pre[to] = v;\n                 \
    \       upd = 1;\n                    }\n                }\n            }\n  \
    \          if (!upd)\n                break;\n        }\n\n        if (dist[T]\
    \ == INF)\n            break;\n        int cur = T;\n        while (cur != S)\
    \ {\n            cur = pre[cur];\n            if (cur != S) {\n              \
    \  I[cur] ^= 1;\n                if (I[cur])\n                    profit += ws[cur];\n\
    \                else\n                    profit -= ws[cur];\n            }\n\
    \        }\n        ret1.push_back(profit);\n        ret2.push_back(I);\n    }\n\
    \    return {ret1, ret2};\n}\n\n/**\n * @brief Matroid\n */\n"
  code: "#pragma once\n#include \"Graph/bimatching.hpp\"\n#include \"Graph/dmdecomp.hpp\"\
    \n\nstruct GraphicMatroid {\n    using P = pair<int, int>;\n    int n;\n    vector<P>\
    \ E;\n    vector<vector<P>> G;\n    vector<int> allow;\n    GraphicMatroid() {}\n\
    \    GraphicMatroid(int n, vector<P> &E) : n(n), E(E), G(n) {\n        rep(i,\
    \ 0, SZ(E)) {\n            auto [u, v] = E[i];\n            G[u].push_back({v,\
    \ i});\n            G[v].push_back({u, i});\n        }\n    }\n    void set(vector<int>\
    \ &I) {\n        allow = I;\n    }\n    vector<int> circuit(int e) {\n       \
    \ auto [x, y] = E[e];\n        vector<int> ret;\n        ret.push_back(e);\n \
    \       auto dfs = [&](auto &dfs, int v, int p) -> bool {\n            if (v ==\
    \ y)\n                return true;\n            for (auto &[to, i] : G[v])\n \
    \               if (allow[i] and to != p) {\n                    ret.push_back(i);\n\
    \                    if (dfs(dfs, to, v))\n                        return true;\n\
    \                    ret.pop_back();\n                }\n            return false;\n\
    \        };\n        if (dfs(dfs, x, -1))\n            return ret;\n        else\n\
    \            return {};\n    }\n};\n\nstruct PartitionMatroid {\n    vector<int>\
    \ grp; // -1:not assign\n    vector<int> lim;\n    vector<vector<int>> cnt;\n\
    \    PartitionMatroid() {}\n    PartitionMatroid(vector<int> &grp, vector<int>\
    \ lim) : grp(grp), lim(lim) {}\n    void set(vector<int> &I) {\n        cnt.assign(SZ(lim),\
    \ {});\n        rep(i, 0, SZ(grp)) if (I[i] != 0 and grp[i] != -1) {\n       \
    \     cnt[grp[i]].push_back(i);\n        }\n    }\n    vector<int> circuit(int\
    \ e) {\n        if (grp[e] == -1)\n            return {};\n        if (SZ(cnt[grp[e]])\
    \ + 1 > lim[grp[e]]) {\n            vector<int> ret = cnt[grp[e]];\n         \
    \   ret.push_back(e);\n            return ret;\n        } else\n            return\
    \ {};\n    }\n};\n\nstruct TransversalMatroid {\n    using P = pair<int, int>;\n\
    \    int n, m;\n    vector<vector<int>> G, aug;\n    vector<int> match, fixed;\n\
    \    TransversalMatroid() {}\n    TransversalMatroid(int n, int m, vector<P> &E)\n\
    \        : n(n), m(m), G(n), aug(n), fixed(n) {\n        for (auto &[u, v] : E)\n\
    \            G[u].push_back(v);\n    }\n    void set(vector<int> &I) {\n     \
    \   vector g(n, vector<int>());\n        rep(e, 0, n) if (I[e]) {\n          \
    \  for (auto &to : G[e])\n                g[e].push_back(to);\n        }\n   \
    \     auto match = BiMatching(n, m, g);\n        auto dm = DMdecomposition(n,\
    \ m, g, match);\n        fixed.assign(m, 1);\n        for (auto &v : dm.front())\n\
    \            if (v >= n)\n                fixed[v - n] = 0;\n        aug.assign(n\
    \ + m, {});\n        rep(e, 0, n) {\n            for (auto &to : G[e])\n     \
    \           aug[e].push_back(to + n);\n        }\n        rep(i, 0, n) if (match[i]\
    \ != -1) aug[match[i] + n].push_back(i);\n    }\n    vector<int> circuit(int e)\
    \ {\n        for (auto &to : G[e])\n            if (!fixed[to]) {\n          \
    \      return {};\n            }\n\n        vector<int> used(n + m);\n       \
    \ queue<int> que;\n        used[e] = 1;\n        que.push(e);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (auto &to : aug[v])\n                if (!used[to]) {\n                    used[to]\
    \ = 1;\n                    que.push(to);\n                }\n        }\n    \
    \    vector<int> ret;\n        rep(i, 0, n) if (used[i]) ret.push_back(i);\n \
    \       return ret;\n    }\n};\n\ntemplate <typename M1, typename M2, typename\
    \ Val>\npair<vector<Val>, vector<vector<int>>>\nMinimumMatroidIntersection(M1\
    \ &m1, M2 &m2, vector<Val> &ws) {\n    using P = pair<Val, int>;\n    int n =\
    \ SZ(ws);\n\n    vector<Val> ret1;\n    vector<vector<int>> ret2;\n\n    Val profit\
    \ = 0;\n    vector<int> I(n);\n    ret1.push_back(profit);\n    ret2.push_back(I);\n\
    \n    for (;;) {\n        vector G(n + 2, vector<P>());\n        int S = n, T\
    \ = n + 1;\n        m1.set(I);\n        m2.set(I);\n\n        rep(e, 0, n) {\n\
    \            if (I[e])\n                continue;\n            auto c1 = m1.circuit(e);\n\
    \            if (c1.empty())\n                G[S].push_back({ws[e] * (n + 1)\
    \ + 1, e});\n            else\n                for (auto &to : c1)\n         \
    \           if (e != to) {\n                        G[to].push_back({ws[e] * (n\
    \ + 1) + 1, e});\n                    }\n            auto c2 = m2.circuit(e);\n\
    \            if (c2.empty())\n                G[e].push_back({Val(0), T});\n \
    \           else\n                for (auto &to : c2)\n                    if\
    \ (e != to) {\n                        G[e].push_back({-ws[to] * (n + 1) + 1,\
    \ to});\n                    }\n        }\n\n        vector<ll> dist(n + 2, INF);\n\
    \        dist[S] = 0;\n        vector<int> pre(n + 2, -1);\n        for (;;) {\n\
    \            bool upd = 0;\n            rep(v, 0, n + 2) if (dist[v] != INF) {\n\
    \                for (auto &[cost, to] : G[v]) {\n                    if (chmin(dist[to],\
    \ dist[v] + cost)) {\n                        pre[to] = v;\n                 \
    \       upd = 1;\n                    }\n                }\n            }\n  \
    \          if (!upd)\n                break;\n        }\n\n        if (dist[T]\
    \ == INF)\n            break;\n        int cur = T;\n        while (cur != S)\
    \ {\n            cur = pre[cur];\n            if (cur != S) {\n              \
    \  I[cur] ^= 1;\n                if (I[cur])\n                    profit += ws[cur];\n\
    \                else\n                    profit -= ws[cur];\n            }\n\
    \        }\n        ret1.push_back(profit);\n        ret2.push_back(I);\n    }\n\
    \    return {ret1, ret2};\n}\n\n/**\n * @brief Matroid\n */"
  dependsOn:
  - Graph/bimatching.hpp
  - Utility/random.hpp
  - Graph/dmdecomp.hpp
  - Graph/scc.hpp
  isVerificationFile: false
  path: Algorithm/matroid.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/matroid.hpp
layout: document
redirect_from:
- /library/Algorithm/matroid.hpp
- /library/Algorithm/matroid.hpp.html
title: Matroid
---
