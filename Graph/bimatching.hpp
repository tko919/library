#pragma once
#include "Utility/random.hpp"

vector<int> BiMatching(int n, int m, vector<vector<int>> &g) {
    rep(v, 0, n) Random::shuffle(ALL(g[v]));
    vector<int> L(n, -1), R(m, -1);
    for (;;) {
        vector<int> par(n, -1), root(n, -1);
        queue<int> que;
        rep(i, 0, n) if (L[i] == -1) {
            que.push(i);
            root[i] = i;
        }
        bool upd = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (L[root[v]] != -1)
                continue;
            for (auto u : g[v]) {
                if (R[u] == -1) {
                    while (u != -1) {
                        R[u] = v;
                        swap(L[v], u);
                        v = par[v];
                    }
                    upd = 1;
                    break;
                }
                int to = R[u];
                if (par[to] == -1) {
                    root[to] = root[v];
                    par[to] = v;
                    que.push(to);
                }
            }
        }
        if (!upd)
            break;
    }
    return L;
}

/**
 * @brief Bipartite Matching
 */