---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/unionfind.hpp
    title: Union Find
  - icon: ':warning:'
    path: Graph/euler.hpp
    title: Eulerian Trail
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Edge Coloring
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
    \        return ret;\n    }\n};\n\n/**\n * @brief Eulerian Trail\n */\n#line 3\
    \ \"Graph/edgecoloring.hpp\"\n\nstruct EdgeColoring {\n    typedef array<int,\
    \ 2> P;\n    typedef array<int, 3> T;\n    int n;\n    vector<P> _es, es;\n  \
    \  EdgeColoring() {}\n    void add_edge(int u, int v) {\n        _es.push_back({u,\
    \ v});\n    }\n    array<vector<int>, 2> divide(vector<P> tmp) { // divide eulerian\
    \ trail\n        EulerianTrail<0> euler(n * 2);\n        for (auto &[x, y] : tmp)\n\
    \            euler.add_edge(x, y);\n        auto piece = euler.run().second;\n\
    \        vector<int> p;\n        for (auto &v : piece)\n            p.insert(p.end(),\
    \ ALL(v));\n        array<vector<int>, 2> res;\n        rep(i, 0, p.size()) res[i\
    \ & 1].push_back(p[i]);\n        return res;\n    }\n    vector<int> find(vector<int>\
    \ ids) { // find perfect matching\n        int k = (int)ids.size() / n;\n    \
    \    assert(n * k == (int)ids.size());\n        int t = 0;\n        while ((1\
    \ << t) < n * k)\n            t++;\n        int x = (1 << t) / k, y = (1 << t)\
    \ % k;\n        vector<int> ori(ids.size(), x), dum(n, y);\n        while (t--)\
    \ {\n            vector<P> tmp;\n            vector<int> add;\n            int\
    \ cnt = 0;\n            rep(i, 0, ids.size()) {\n                if (ori[i] &\
    \ 1) {\n                    tmp.push_back({es[ids[i]][0], es[ids[i]][1]});\n \
    \                   add.push_back(i);\n                    cnt++;\n          \
    \      }\n                ori[i] >>= 1;\n            }\n            rep(i, 0,\
    \ n) {\n                if (dum[i] & 1) {\n                    tmp.push_back({i,\
    \ n + i});\n                    add.push_back(i);\n                }\n       \
    \         dum[i] >>= 1;\n            }\n            array<vector<int>, 2> w =\
    \ divide(tmp);\n            int dum_cnt[2] = {};\n            rep(i, 0, 2) for\
    \ (int x : w[i]) if (x >= cnt) dum_cnt[i]++;\n            for (int i : w[dum_cnt[0]\
    \ > dum_cnt[1]]) {\n                if (i < cnt)\n                    ori[add[i]]++;\n\
    \                else\n                    dum[add[i]]++;\n            }\n   \
    \     }\n        vector<int> res;\n        rep(i, 0, ids.size()) if (ori[i]) res.push_back(ids[i]);\n\
    \        assert((int)res.size() == n);\n        return res;\n    }\n    vector<int>\
    \ used;\n    vector<vector<int>>\n    colorize(vector<int> ids) { // must be regular\
    \ bipartite graph\n        int k = (int)ids.size() / n;\n        assert(n * k\
    \ == (int)ids.size());\n        if (k == 0)\n            return {};\n        if\
    \ (k == 1)\n            return {ids};\n        vector<vector<int>> res;\n    \
    \    if (k & 1) {\n            auto add = find(ids);\n            for (int x :\
    \ add)\n                used[x] = 1;\n            vector<int> rem;\n         \
    \   for (int x : ids)\n                if (!used[x])\n                    rem.push_back(x);\n\
    \            for (int x : add)\n                used[x] = 0;\n            res\
    \ = colorize(rem);\n            res.push_back(add);\n        } else {\n      \
    \      vector<P> tmp;\n            for (int i : ids)\n                tmp.push_back({es[i][0],\
    \ es[i][1]});\n            array<vector<int>, 2> p = divide(tmp);\n          \
    \  rep(i, 0, 2) for (auto &x : p[i]) x = ids[x];\n            res = colorize(p[0]);\n\
    \            int cur = k >> 1;\n            while (__builtin_popcount(cur) !=\
    \ 1) {\n                auto add = res.back();\n                res.pop_back();\n\
    \                p[1].insert(p[1].end(), ALL(add));\n                cur++;\n\
    \            }\n            auto add = colorize(p[1]);\n            res.insert(res.end(),\
    \ ALL(add));\n        }\n        return res;\n    }\n    int run(vector<int> &res)\
    \ {\n        // normalize\n        int LR[2] = {};\n        for (auto e : _es)\n\
    \            rep(j, 0, 2) chmax(LR[j], e[j] + 1);\n        vector<int> deg[2],\
    \ kind[2], sz[2];\n        rep(i, 0, 2) deg[i].resize(LR[i]), kind[i].resize(LR[i]);\n\
    \        for (auto e : _es)\n            rep(j, 0, 2) deg[j][e[j]]++;\n      \
    \  int k = 0;\n        rep(i, 0, 2) rep(j, 0, LR[i]) chmax(k, deg[i][j]);\n  \
    \      rep(j, 0, 2) {\n            for (int i = 0; i < LR[j];) {\n           \
    \     int add = 0;\n                while (i < LR[j] and deg[j][i] + add <= k)\
    \ {\n                    kind[j][i] = (int)sz[j].size();\n                   \
    \ add += deg[j][i++];\n                }\n                sz[j].push_back(add);\n\
    \            }\n        }\n        rep(i, 0, 2) while (sz[i].size() < sz[i ^ 1].size())\
    \ sz[i].push_back(0);\n        n = (int)sz[0].size();\n        for (auto e : _es)\n\
    \            es.push_back({kind[0][e[0]], n + kind[1][e[1]]});\n        int nxt\
    \ = 0;\n        rep(i, 0, n) while (sz[0][i] < k) {\n            while (sz[1][nxt]\
    \ == k)\n                nxt++;\n            es.push_back({i, n + nxt});\n   \
    \         sz[0][i]++;\n            sz[1][nxt]++;\n        }\n        res.resize(_es.size());\n\
    \        used.resize(n * k, 0);\n        vector<int> tmp(n * k);\n        iota(ALL(tmp),\
    \ 0);\n        auto ret = colorize(tmp);\n        rep(i, 0, ret.size()) for (int\
    \ idx : ret[i]) {\n            if (idx < (int)_es.size())\n                res[idx]\
    \ = i;\n        }\n        return k;\n    }\n};\n\n/**\n * @brief Edge Coloring\n\
    \ */\n"
  code: "#pragma once\n#include \"Graph/euler.hpp\"\n\nstruct EdgeColoring {\n   \
    \ typedef array<int, 2> P;\n    typedef array<int, 3> T;\n    int n;\n    vector<P>\
    \ _es, es;\n    EdgeColoring() {}\n    void add_edge(int u, int v) {\n       \
    \ _es.push_back({u, v});\n    }\n    array<vector<int>, 2> divide(vector<P> tmp)\
    \ { // divide eulerian trail\n        EulerianTrail<0> euler(n * 2);\n       \
    \ for (auto &[x, y] : tmp)\n            euler.add_edge(x, y);\n        auto piece\
    \ = euler.run().second;\n        vector<int> p;\n        for (auto &v : piece)\n\
    \            p.insert(p.end(), ALL(v));\n        array<vector<int>, 2> res;\n\
    \        rep(i, 0, p.size()) res[i & 1].push_back(p[i]);\n        return res;\n\
    \    }\n    vector<int> find(vector<int> ids) { // find perfect matching\n   \
    \     int k = (int)ids.size() / n;\n        assert(n * k == (int)ids.size());\n\
    \        int t = 0;\n        while ((1 << t) < n * k)\n            t++;\n    \
    \    int x = (1 << t) / k, y = (1 << t) % k;\n        vector<int> ori(ids.size(),\
    \ x), dum(n, y);\n        while (t--) {\n            vector<P> tmp;\n        \
    \    vector<int> add;\n            int cnt = 0;\n            rep(i, 0, ids.size())\
    \ {\n                if (ori[i] & 1) {\n                    tmp.push_back({es[ids[i]][0],\
    \ es[ids[i]][1]});\n                    add.push_back(i);\n                  \
    \  cnt++;\n                }\n                ori[i] >>= 1;\n            }\n \
    \           rep(i, 0, n) {\n                if (dum[i] & 1) {\n              \
    \      tmp.push_back({i, n + i});\n                    add.push_back(i);\n   \
    \             }\n                dum[i] >>= 1;\n            }\n            array<vector<int>,\
    \ 2> w = divide(tmp);\n            int dum_cnt[2] = {};\n            rep(i, 0,\
    \ 2) for (int x : w[i]) if (x >= cnt) dum_cnt[i]++;\n            for (int i :\
    \ w[dum_cnt[0] > dum_cnt[1]]) {\n                if (i < cnt)\n              \
    \      ori[add[i]]++;\n                else\n                    dum[add[i]]++;\n\
    \            }\n        }\n        vector<int> res;\n        rep(i, 0, ids.size())\
    \ if (ori[i]) res.push_back(ids[i]);\n        assert((int)res.size() == n);\n\
    \        return res;\n    }\n    vector<int> used;\n    vector<vector<int>>\n\
    \    colorize(vector<int> ids) { // must be regular bipartite graph\n        int\
    \ k = (int)ids.size() / n;\n        assert(n * k == (int)ids.size());\n      \
    \  if (k == 0)\n            return {};\n        if (k == 1)\n            return\
    \ {ids};\n        vector<vector<int>> res;\n        if (k & 1) {\n           \
    \ auto add = find(ids);\n            for (int x : add)\n                used[x]\
    \ = 1;\n            vector<int> rem;\n            for (int x : ids)\n        \
    \        if (!used[x])\n                    rem.push_back(x);\n            for\
    \ (int x : add)\n                used[x] = 0;\n            res = colorize(rem);\n\
    \            res.push_back(add);\n        } else {\n            vector<P> tmp;\n\
    \            for (int i : ids)\n                tmp.push_back({es[i][0], es[i][1]});\n\
    \            array<vector<int>, 2> p = divide(tmp);\n            rep(i, 0, 2)\
    \ for (auto &x : p[i]) x = ids[x];\n            res = colorize(p[0]);\n      \
    \      int cur = k >> 1;\n            while (__builtin_popcount(cur) != 1) {\n\
    \                auto add = res.back();\n                res.pop_back();\n   \
    \             p[1].insert(p[1].end(), ALL(add));\n                cur++;\n   \
    \         }\n            auto add = colorize(p[1]);\n            res.insert(res.end(),\
    \ ALL(add));\n        }\n        return res;\n    }\n    int run(vector<int> &res)\
    \ {\n        // normalize\n        int LR[2] = {};\n        for (auto e : _es)\n\
    \            rep(j, 0, 2) chmax(LR[j], e[j] + 1);\n        vector<int> deg[2],\
    \ kind[2], sz[2];\n        rep(i, 0, 2) deg[i].resize(LR[i]), kind[i].resize(LR[i]);\n\
    \        for (auto e : _es)\n            rep(j, 0, 2) deg[j][e[j]]++;\n      \
    \  int k = 0;\n        rep(i, 0, 2) rep(j, 0, LR[i]) chmax(k, deg[i][j]);\n  \
    \      rep(j, 0, 2) {\n            for (int i = 0; i < LR[j];) {\n           \
    \     int add = 0;\n                while (i < LR[j] and deg[j][i] + add <= k)\
    \ {\n                    kind[j][i] = (int)sz[j].size();\n                   \
    \ add += deg[j][i++];\n                }\n                sz[j].push_back(add);\n\
    \            }\n        }\n        rep(i, 0, 2) while (sz[i].size() < sz[i ^ 1].size())\
    \ sz[i].push_back(0);\n        n = (int)sz[0].size();\n        for (auto e : _es)\n\
    \            es.push_back({kind[0][e[0]], n + kind[1][e[1]]});\n        int nxt\
    \ = 0;\n        rep(i, 0, n) while (sz[0][i] < k) {\n            while (sz[1][nxt]\
    \ == k)\n                nxt++;\n            es.push_back({i, n + nxt});\n   \
    \         sz[0][i]++;\n            sz[1][nxt]++;\n        }\n        res.resize(_es.size());\n\
    \        used.resize(n * k, 0);\n        vector<int> tmp(n * k);\n        iota(ALL(tmp),\
    \ 0);\n        auto ret = colorize(tmp);\n        rep(i, 0, ret.size()) for (int\
    \ idx : ret[i]) {\n            if (idx < (int)_es.size())\n                res[idx]\
    \ = i;\n        }\n        return k;\n    }\n};\n\n/**\n * @brief Edge Coloring\n\
    \ */"
  dependsOn:
  - Graph/euler.hpp
  - DataStructure/unionfind.hpp
  isVerificationFile: false
  path: Graph/edgecoloring.hpp
  requiredBy: []
  timestamp: '2024-09-10 03:26:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/edgecoloring.hpp
layout: document
redirect_from:
- /library/Graph/edgecoloring.hpp
- /library/Graph/edgecoloring.hpp.html
title: Edge Coloring
---
