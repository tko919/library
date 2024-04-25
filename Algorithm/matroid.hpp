#pragma once
#include "Graph/bimatching.hpp"
#include "Graph/dmdecomp.hpp"

struct GraphicMatroid {
    using P = pair<int, int>;
    int n;
    vector<P> E;
    vector<vector<P>> G;
    vector<int> allow;
    GraphicMatroid() {}
    GraphicMatroid(int n, vector<P> &E) : n(n), E(E), G(n) {
        rep(i, 0, SZ(E)) {
            auto [u, v] = E[i];
            G[u].push_back({v, i});
            G[v].push_back({u, i});
        }
    }
    void set(vector<int> &I) {
        allow = I;
    }
    vector<int> circuit(int e) {
        auto [x, y] = E[e];
        vector<int> ret;
        ret.push_back(e);
        auto dfs = [&](auto &dfs, int v, int p) -> bool {
            if (v == y)
                return true;
            for (auto &[to, i] : G[v])
                if (allow[i] and to != p) {
                    ret.push_back(i);
                    if (dfs(dfs, to, v))
                        return true;
                    ret.pop_back();
                }
            return false;
        };
        if (dfs(dfs, x, -1))
            return ret;
        else
            return {};
    }
};

struct PartitionMatroid {
    vector<int> grp; // -1:not assign
    vector<int> lim;
    vector<vector<int>> cnt;
    PartitionMatroid() {}
    PartitionMatroid(vector<int> &grp, vector<int> lim) : grp(grp), lim(lim) {}
    void set(vector<int> &I) {
        cnt.assign(SZ(lim), {});
        rep(i, 0, SZ(grp)) if (I[i] != 0 and grp[i] != -1) {
            cnt[grp[i]].push_back(i);
        }
    }
    vector<int> circuit(int e) {
        if (grp[e] == -1)
            return {};
        if (SZ(cnt[grp[e]]) + 1 > lim[grp[e]]) {
            vector<int> ret = cnt[grp[e]];
            ret.push_back(e);
            return ret;
        } else
            return {};
    }
};

struct TransversalMatroid {
    using P = pair<int, int>;
    int n, m;
    vector<vector<int>> G, aug;
    vector<int> match, fixed;
    TransversalMatroid() {}
    TransversalMatroid(int n, int m, vector<P> &E)
        : n(n), m(m), G(n), aug(n), fixed(n) {
        for (auto &[u, v] : E)
            G[u].push_back(v);
    }
    void set(vector<int> &I) {
        vector g(n, vector<int>());
        rep(e, 0, n) if (I[e]) {
            for (auto &to : G[e])
                g[e].push_back(to);
        }
        auto match = BiMatching(n, m, g);
        auto dm = DMdecomposition(n, m, g, match);
        fixed.assign(m, 1);
        for (auto &v : dm.front())
            if (v >= n)
                fixed[v - n] = 0;
        aug.assign(n + m, {});
        rep(e, 0, n) {
            for (auto &to : G[e])
                aug[e].push_back(to + n);
        }
        rep(i, 0, n) if (match[i] != -1) aug[match[i] + n].push_back(i);
    }
    vector<int> circuit(int e) {
        for (auto &to : G[e])
            if (!fixed[to]) {
                return {};
            }

        vector<int> used(n + m);
        queue<int> que;
        used[e] = 1;
        que.push(e);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &to : aug[v])
                if (!used[to]) {
                    used[to] = 1;
                    que.push(to);
                }
        }
        vector<int> ret;
        rep(i, 0, n) if (used[i]) ret.push_back(i);
        return ret;
    }
};

template <typename M1, typename M2, typename Val>
pair<vector<Val>, vector<vector<int>>>
MinimumMatroidIntersection(M1 &m1, M2 &m2, vector<Val> &ws) {
    using P = pair<Val, int>;
    int n = SZ(ws);

    vector<Val> ret1;
    vector<vector<int>> ret2;

    Val profit = 0;
    vector<int> I(n);
    ret1.push_back(profit);
    ret2.push_back(I);

    for (;;) {
        vector G(n + 2, vector<P>());
        int S = n, T = n + 1;
        m1.set(I);
        m2.set(I);

        rep(e, 0, n) {
            if (I[e])
                continue;
            auto c1 = m1.circuit(e);
            if (c1.empty())
                G[S].push_back({ws[e] * (n + 1) + 1, e});
            else
                for (auto &to : c1)
                    if (e != to) {
                        G[to].push_back({ws[e] * (n + 1) + 1, e});
                    }
            auto c2 = m2.circuit(e);
            if (c2.empty())
                G[e].push_back({Val(0), T});
            else
                for (auto &to : c2)
                    if (e != to) {
                        G[e].push_back({-ws[to] * (n + 1) + 1, to});
                    }
        }

        vector<ll> dist(n + 2, INF);
        dist[S] = 0;
        vector<int> pre(n + 2, -1);
        for (;;) {
            bool upd = 0;
            rep(v, 0, n + 2) if (dist[v] != INF) {
                for (auto &[cost, to] : G[v]) {
                    if (chmin(dist[to], dist[v] + cost)) {
                        pre[to] = v;
                        upd = 1;
                    }
                }
            }
            if (!upd)
                break;
        }

        if (dist[T] == INF)
            break;
        int cur = T;
        while (cur != S) {
            cur = pre[cur];
            if (cur != S) {
                I[cur] ^= 1;
                if (I[cur])
                    profit += ws[cur];
                else
                    profit -= ws[cur];
            }
        }
        ret1.push_back(profit);
        ret2.push_back(I);
    }
    return {ret1, ret2};
}

/**
 * @brief Matroid
 */