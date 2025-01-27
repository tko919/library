#pragma once
#include "Graph/lca.hpp"

template <typename T>
vector<T> UndirectedShortestPathRemoveEdge(int n,
                                           vector<tuple<int, int, T>> &es,
                                           int s, int t) {
    using P = pair<T, int>;
    vector g(n, vector<tuple<int, T, int>>());
    rep(i, 0, SZ(es)) {
        auto [u, v, w] = es[i];
        assert(w > 0);
        g[u].push_back({v, w, i});
        g[v].push_back({u, w, i});
    }

    auto dijk = [&](int st, vector<int> &etrace,
                    vector<int> &vtrace) -> pair<vector<T>, vector<int>> {
        vector<T> dist(n, INF);
        vector<int> pre(n, -1); // id

        priority_queue<P, vector<P>, greater<P>> pq;
        dist[st] = 0;
        pq.push({0, st});
        if (SZ(etrace)) {
            int cur = st;
            T cost = 0;
            rep(i, 0, SZ(etrace)) {
                cur = vtrace[i + 1];
                pre[cur] = etrace[i];
                cost += get<2>(es[etrace[i]]);
                dist[cur] = cost;
                pq.push({cost, cur});
            }
        }

        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[v] != d)
                continue;
            for (auto &[to, cost, id] : g[v])
                if (chmin(dist[to], dist[v] + cost)) {
                    pq.push({dist[to], to});
                    pre[to] = id;
                }
        }
        return {dist, pre};
    };
    vector<int> etrace, vtrace;
    auto [ds, ps] = dijk(s, etrace, vtrace);
    vector<int> ord(n, -1);
    {
        int cur = t;
        vtrace.push_back(t);
        for (;;) {
            if (cur == s)
                break;
            int id = ps[cur];
            etrace.push_back(id);
            cur = (get<0>(es[id]) == cur ? get<1>(es[id]) : get<0>(es[id]));
            vtrace.push_back(cur);
        }
    }
    auto [dt, pt] = dijk(t, etrace, vtrace);
    reverse(ALL(etrace));
    reverse(ALL(vtrace));
    rep(i, 0, SZ(vtrace)) ord[vtrace[i]] = i;

    vector<T> ret(SZ(es), ds[t]);
    for (auto &id : etrace)
        ret[id] = INF;

    LCA lca1(n), lca2(n);
    rep(v, 0, n) if (ps[v] != -1) {
        auto [x, y, _] = es[ps[v]];
        int u = (x == v ? y : x);
        lca1.add_edge(v, u);
    }
    rep(v, 0, n) if (pt[v] != -1) {
        auto [x, y, _] = es[pt[v]];
        int u = (x == v ? y : x);
        lca2.add_edge(v, u);
    }
    lca1.run(s);
    lca2.run(t);

    vector add(n, vector<pair<T, ll>>());
    vector rem(n, vector<pair<T, ll>>());
    for (auto &[u, v, w] : es) {
        if (ds[u] + w + dt[v] == ds[t] or ds[v] + w + dt[u] == ds[t])
            continue;
        rep(_, 0, 2) {
            int x = lca1.lca(t, u);
            int y = lca2.lca(s, v);
            if (x != y) {
                if (ord[x] > ord[y])
                    swap(x, y);
                add[x].push_back({ds[u] + dt[v] + w, u * n + v});
                rem[y].push_back({ds[u] + dt[v] + w, u * n + v});
            }
            swap(u, v);
        }
    }
    set<P> st;
    rep(i, 0, SZ(etrace)) {
        for (auto &[cand, id] : add[vtrace[i]]) {
            st.insert({cand, id});
        }
        for (auto &[cand, id] : rem[vtrace[i]]) {
            st.erase({cand, id});
        }
        if (SZ(st)) {
            chmin(ret[etrace[i]], (*st.begin()).first);
        }
    }

    return ret;
}

/**
 * @brief Undirected Shortest Path (remove one Edge)
 */