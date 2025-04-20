---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/lca.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Undirected Shortest Path (remove one Edge)
    links: []
  bundledCode: "#line 2 \"Graph/lca.hpp\"\n\r\nstruct LCA{\r\n    LCA(int _n=0):n(_n),g(_n),depth(_n+1,inf),start(_n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    void run(int root=0){\r\n        depth[root]=0;\r\n        dfs(root,-1);\r\
    \n        N=1;\r\n        while(N<int(euler.size()))N<<=1;\r\n        tree.resize(N*2,n);\r\
    \n        rep(i,0,euler.size())tree[N+i]=euler[i];\r\n        for(int i=N-1;i>0;i--)tree[i]=op(tree[i*2],tree[i*2+1]);\r\
    \n    }\r\n    int lca(int u,int v){\r\n        int a=start[u],b=start[v];\r\n\
    \        if(a>b)swap(a,b);\r\n        b++;\r\n        int res=n;\r\n        for(int\
    \ T=b-a;T>=1;T=b-a){\r\n            int x=a|((1U<<31)>>__builtin_clz(T));\r\n\
    \            int y=x&-x,k=__builtin_ctz(x);\r\n            res=op(res,tree[(N|a)>>k]);\r\
    \n            a+=y;\r\n        }\r\n        return res;\r\n    }\r\nprivate:\r\
    \n    int n,N;\r\n    vector<vector<int>> g;\r\n    vector<int> depth,start,euler,tree;\r\
    \n    void dfs(int v,int p){\r\n        start[v]=euler.size();\r\n        euler.push_back(v);\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n            depth[to]=depth[v]+1;\r\n\
    \            dfs(to,v);\r\n            euler.push_back(v);\r\n        }\r\n  \
    \  }\r\n    int op(int u,int v){\r\n        if(depth[u]<depth[v])return u;\r\n\
    \        else return v;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Lowest Common Ancestor\r\
    \n */\n#line 3 \"Graph/shortestpathremedge.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ UndirectedShortestPathRemoveEdge(int n,\n                                  \
    \         vector<tuple<int, int, T>> &es,\n                                  \
    \         int s, int t) {\n    using P = pair<T, int>;\n    vector g(n, vector<tuple<int,\
    \ T, int>>());\n    rep(i, 0, SZ(es)) {\n        auto [u, v, w] = es[i];\n   \
    \     assert(w > 0);\n        g[u].push_back({v, w, i});\n        g[v].push_back({u,\
    \ w, i});\n    }\n\n    auto dijk = [&](int st, vector<int> &etrace,\n       \
    \             vector<int> &vtrace) -> pair<vector<T>, vector<int>> {\n       \
    \ vector<T> dist(n, INF);\n        vector<int> pre(n, -1); // id\n\n        priority_queue<P,\
    \ vector<P>, greater<P>> pq;\n        dist[st] = 0;\n        pq.push({0, st});\n\
    \        if (SZ(etrace)) {\n            int cur = st;\n            T cost = 0;\n\
    \            rep(i, 0, SZ(etrace)) {\n                cur = vtrace[i + 1];\n \
    \               pre[cur] = etrace[i];\n                cost += get<2>(es[etrace[i]]);\n\
    \                dist[cur] = cost;\n                pq.push({cost, cur});\n  \
    \          }\n        }\n\n        while (!pq.empty()) {\n            auto [d,\
    \ v] = pq.top();\n            pq.pop();\n            if (dist[v] != d)\n     \
    \           continue;\n            for (auto &[to, cost, id] : g[v])\n       \
    \         if (chmin(dist[to], dist[v] + cost)) {\n                    pq.push({dist[to],\
    \ to});\n                    pre[to] = id;\n                }\n        }\n   \
    \     return {dist, pre};\n    };\n    vector<int> etrace, vtrace;\n    auto [ds,\
    \ ps] = dijk(s, etrace, vtrace);\n    vector<int> ord(n, -1);\n    {\n       \
    \ int cur = t;\n        vtrace.push_back(t);\n        for (;;) {\n           \
    \ if (cur == s)\n                break;\n            int id = ps[cur];\n     \
    \       etrace.push_back(id);\n            cur = (get<0>(es[id]) == cur ? get<1>(es[id])\
    \ : get<0>(es[id]));\n            vtrace.push_back(cur);\n        }\n    }\n \
    \   auto [dt, pt] = dijk(t, etrace, vtrace);\n    reverse(ALL(etrace));\n    reverse(ALL(vtrace));\n\
    \    rep(i, 0, SZ(vtrace)) ord[vtrace[i]] = i;\n\n    vector<T> ret(SZ(es), ds[t]);\n\
    \    for (auto &id : etrace)\n        ret[id] = INF;\n\n    LCA lca1(n), lca2(n);\n\
    \    rep(v, 0, n) if (ps[v] != -1) {\n        auto [x, y, _] = es[ps[v]];\n  \
    \      int u = (x == v ? y : x);\n        lca1.add_edge(v, u);\n    }\n    rep(v,\
    \ 0, n) if (pt[v] != -1) {\n        auto [x, y, _] = es[pt[v]];\n        int u\
    \ = (x == v ? y : x);\n        lca2.add_edge(v, u);\n    }\n    lca1.run(s);\n\
    \    lca2.run(t);\n\n    vector add(n, vector<pair<T, ll>>());\n    vector rem(n,\
    \ vector<pair<T, ll>>());\n    for (auto &[u, v, w] : es) {\n        if (ds[u]\
    \ + w + dt[v] == ds[t] or ds[v] + w + dt[u] == ds[t])\n            continue;\n\
    \        rep(_, 0, 2) {\n            int x = lca1.lca(t, u);\n            int\
    \ y = lca2.lca(s, v);\n            if (x != y) {\n                if (ord[x] >\
    \ ord[y])\n                    swap(x, y);\n                add[x].push_back({ds[u]\
    \ + dt[v] + w, u * n + v});\n                rem[y].push_back({ds[u] + dt[v] +\
    \ w, u * n + v});\n            }\n            swap(u, v);\n        }\n    }\n\
    \    set<P> st;\n    rep(i, 0, SZ(etrace)) {\n        for (auto &[cand, id] :\
    \ add[vtrace[i]]) {\n            st.insert({cand, id});\n        }\n        for\
    \ (auto &[cand, id] : rem[vtrace[i]]) {\n            st.erase({cand, id});\n \
    \       }\n        if (SZ(st)) {\n            chmin(ret[etrace[i]], (*st.begin()).first);\n\
    \        }\n    }\n\n    return ret;\n}\n\n/**\n * @brief Undirected Shortest\
    \ Path (remove one Edge)\n */\n"
  code: "#pragma once\n#include \"Graph/lca.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ UndirectedShortestPathRemoveEdge(int n,\n                                  \
    \         vector<tuple<int, int, T>> &es,\n                                  \
    \         int s, int t) {\n    using P = pair<T, int>;\n    vector g(n, vector<tuple<int,\
    \ T, int>>());\n    rep(i, 0, SZ(es)) {\n        auto [u, v, w] = es[i];\n   \
    \     assert(w > 0);\n        g[u].push_back({v, w, i});\n        g[v].push_back({u,\
    \ w, i});\n    }\n\n    auto dijk = [&](int st, vector<int> &etrace,\n       \
    \             vector<int> &vtrace) -> pair<vector<T>, vector<int>> {\n       \
    \ vector<T> dist(n, INF);\n        vector<int> pre(n, -1); // id\n\n        priority_queue<P,\
    \ vector<P>, greater<P>> pq;\n        dist[st] = 0;\n        pq.push({0, st});\n\
    \        if (SZ(etrace)) {\n            int cur = st;\n            T cost = 0;\n\
    \            rep(i, 0, SZ(etrace)) {\n                cur = vtrace[i + 1];\n \
    \               pre[cur] = etrace[i];\n                cost += get<2>(es[etrace[i]]);\n\
    \                dist[cur] = cost;\n                pq.push({cost, cur});\n  \
    \          }\n        }\n\n        while (!pq.empty()) {\n            auto [d,\
    \ v] = pq.top();\n            pq.pop();\n            if (dist[v] != d)\n     \
    \           continue;\n            for (auto &[to, cost, id] : g[v])\n       \
    \         if (chmin(dist[to], dist[v] + cost)) {\n                    pq.push({dist[to],\
    \ to});\n                    pre[to] = id;\n                }\n        }\n   \
    \     return {dist, pre};\n    };\n    vector<int> etrace, vtrace;\n    auto [ds,\
    \ ps] = dijk(s, etrace, vtrace);\n    vector<int> ord(n, -1);\n    {\n       \
    \ int cur = t;\n        vtrace.push_back(t);\n        for (;;) {\n           \
    \ if (cur == s)\n                break;\n            int id = ps[cur];\n     \
    \       etrace.push_back(id);\n            cur = (get<0>(es[id]) == cur ? get<1>(es[id])\
    \ : get<0>(es[id]));\n            vtrace.push_back(cur);\n        }\n    }\n \
    \   auto [dt, pt] = dijk(t, etrace, vtrace);\n    reverse(ALL(etrace));\n    reverse(ALL(vtrace));\n\
    \    rep(i, 0, SZ(vtrace)) ord[vtrace[i]] = i;\n\n    vector<T> ret(SZ(es), ds[t]);\n\
    \    for (auto &id : etrace)\n        ret[id] = INF;\n\n    LCA lca1(n), lca2(n);\n\
    \    rep(v, 0, n) if (ps[v] != -1) {\n        auto [x, y, _] = es[ps[v]];\n  \
    \      int u = (x == v ? y : x);\n        lca1.add_edge(v, u);\n    }\n    rep(v,\
    \ 0, n) if (pt[v] != -1) {\n        auto [x, y, _] = es[pt[v]];\n        int u\
    \ = (x == v ? y : x);\n        lca2.add_edge(v, u);\n    }\n    lca1.run(s);\n\
    \    lca2.run(t);\n\n    vector add(n, vector<pair<T, ll>>());\n    vector rem(n,\
    \ vector<pair<T, ll>>());\n    for (auto &[u, v, w] : es) {\n        if (ds[u]\
    \ + w + dt[v] == ds[t] or ds[v] + w + dt[u] == ds[t])\n            continue;\n\
    \        rep(_, 0, 2) {\n            int x = lca1.lca(t, u);\n            int\
    \ y = lca2.lca(s, v);\n            if (x != y) {\n                if (ord[x] >\
    \ ord[y])\n                    swap(x, y);\n                add[x].push_back({ds[u]\
    \ + dt[v] + w, u * n + v});\n                rem[y].push_back({ds[u] + dt[v] +\
    \ w, u * n + v});\n            }\n            swap(u, v);\n        }\n    }\n\
    \    set<P> st;\n    rep(i, 0, SZ(etrace)) {\n        for (auto &[cand, id] :\
    \ add[vtrace[i]]) {\n            st.insert({cand, id});\n        }\n        for\
    \ (auto &[cand, id] : rem[vtrace[i]]) {\n            st.erase({cand, id});\n \
    \       }\n        if (SZ(st)) {\n            chmin(ret[etrace[i]], (*st.begin()).first);\n\
    \        }\n    }\n\n    return ret;\n}\n\n/**\n * @brief Undirected Shortest\
    \ Path (remove one Edge)\n */"
  dependsOn:
  - Graph/lca.hpp
  isVerificationFile: false
  path: Graph/shortestpathremedge.hpp
  requiredBy: []
  timestamp: '2025-01-28 06:32:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/shortestpathremedge.hpp
layout: document
redirect_from:
- /library/Graph/shortestpathremedge.hpp
- /library/Graph/shortestpathremedge.hpp.html
title: Undirected Shortest Path (remove one Edge)
---
