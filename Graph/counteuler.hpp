#pragma once
#include "Graph/countspanning.hpp"

template <typename T, typename U>
T CountEulerianCircuits(vector<vector<pair<int, U>>> &g) {
    int n = SZ(g);
    vector<int> vs;
    rep(u, 0, n) for (auto &[v, _] : g[u]) {
        vs.push_back(u);
        vs.push_back(v);
    }
    UNIQUE(vs);
    vector<vector<pair<int, U>>> G(SZ(vs));
    rep(u, 0, n) for (auto &[v, mul] : g[u]) {
        G[LB(vs, u)].push_back({LB(vs, v), mul});
    }
    n = SZ(vs);
    vector<U> in(n), out(n);
    rep(u, 0, n) for (auto &[v, mul] : G[u]) {
        in[u] += mul;
        out[v] += mul;
    }
    rep(v, 0, n) if (in[v] != out[v]) {
        return 0;
    }
    T ret = DirectedCountSpanningTree<T>(G, n - 1);
    rep(v, 0, n) ret *= Fact<T>(out[v] - 1);
    return ret;
}

/**
 * @brief Counting Eulerian Circuits
 */