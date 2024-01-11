#pragma once
#include "Graph/maxflow.hpp"

// yosupo orz
template <class Cap, class Cost> struct MinCostFlow {
    struct X {
        int from, to;
        Cap lb, ub, flow;
        Cost cost;
    };
    struct Edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };
    using P = pair<int, int>;
    int n, m;
    vector<X> es;
    vector<Cap> exc;
    vector<Cost> dual;
    vector<vector<Edge>> g;
    Cost MX;
    MinCostFlow(int _n) : n(_n), m(0), exc(n), dual(n), g(n), MX(0) {}
    void add_edge(int from, int to, Cap lb, Cap ub, Cost cost) {
        m++;
        chmax(MX, cost);
        chmax(MX, -cost);
        es.push_back({from, to, lb, ub, 0, cost});
    }
    void add_excess(int v, Cap c) { exc[v] += c; }
    pair<bool, Cost> run() {
        MaxFlow mf(n + 2);
        int S = n, T = n + 1;
        Cap psum = 0, nsum = 0;
        for (auto &e : es) {
            exc[e.to] += e.lb;
            exc[e.from] -= e.lb;
            mf.add_edge(e.from, e.to, e.ub - e.lb);
        }
        rep(i, 0, n) {
            if (exc[i] > 0) {
                psum += exc[i];
                mf.add_edge(S, i, exc[i]);
            }
            if (exc[i] < 0) {
                nsum += -exc[i];
                mf.add_edge(i, T, -exc[i]);
            }
        }

        if (psum != nsum or mf.run(S, T) != psum)
            return {false, 0};

        using P = pair<int, int>;
        vector<P> pos;
        rep(i, 0, m) {
            auto e = mf.get_edge(i);
            Cost cost = es[i].cost * n;
            int fid = SZ(g[e.from]), tid = SZ(g[e.to]);
            if (e.from == e.to)
                tid++;
            pos.push_back({e.from, fid});
            g[e.from].push_back({e.to, tid, e.cap, cost});
            g[e.to].push_back({e.from, fid, e.recap, -cost});
        }

        // solve
        Cost eps = MX * n + 1;
        while (eps > 1) {
            eps = max<Cost>(eps >> 2, 1);
            refine(eps);
        }

        Cost ret = 0;
        rep(i, 0, m) {
            auto [from, fid] = pos[i];
            es[i].flow = es[i].ub - g[from][fid].cap;
            ret += es[i].flow * es[i].cost;
        }
        dual.assign(n, 0);
        for (;;) {
            bool upd = 0;
            rep(i, 0, n) {
                for (auto &e : g[i])
                    if (e.cap) {
                        auto cost = dual[i] + e.cost / n;
                        if (chmin(dual[e.to], cost)) {
                            upd = 1;
                        }
                    }
            }
            if (!upd)
                break;
        }
        return {true, ret};
    }
    Cap get_flow(int i) const { return es[i].flow; }

  private:
    void refine(Cost &eps) {
        exc.assign(n, 0);
        vector<int> used(n);
        queue<int> que;
        vector<int> iter(n);

        auto cost = [&](int from, const Edge &e) {
            return e.cost + dual[from] - dual[e.to];
        };
        auto push = [&](int from, Edge &e, Cap cap) {
            exc[from] -= cap;
            exc[e.to] += cap;
            g[e.to][e.rev].cap += cap;
            e.cap -= cap;
        };
        auto relabel = [&](int v) {
            iter[v] = 0;
            Cost down = MX * (n + 1);
            for (auto &e : g[v])
                if (e.cap) {
                    chmin(down, eps + cost(v, e));
                }
            dual[v] -= down;
            que.push(v);
            used[v] = 1;
        };

        rep(i, 0, n) {
            for (auto &e : g[i])
                if (e.cap and cost(i, e) < 0) {
                    push(i, e, e.cap);
                }
        }
        rep(i, 0, n) if (exc[i] > 0) {
            used[i] = 1;
            que.push(i);
        }
        while (!que.empty()) {
            auto v = que.front();
            que.pop();
            used[v] = 0;
            for (int &i = iter[v]; i < SZ(g[v]); i++) {
                auto &e = g[v][i];
                if (e.cap and cost(v, e) < 0) {
                    push(v, e, min(exc[v], e.cap));
                    if (!used[e.to] and exc[e.to] > 0) {
                        used[e.to] = 1;
                        que.push(e.to);
                    }
                    if (exc[v] == 0)
                        break;
                }
            }
            if (exc[v] > 0) {
                relabel(v);
            }
        }
        eps = 0;
        rep(i, 0, n) {
            for (auto &e : g[i])
                if (e.cap) {
                    chmax(eps, -cost(i, e));
                }
        }
    }
};

/**
 * @brief Minimum Cost b-flow
 */