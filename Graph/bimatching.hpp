#pragma once

vector<int> BiMatching(int n, int m, vector<vector<int>> &g) {
    vector<int> L(n, -1), R(m, -1), d(n);
    auto dfs = [&](auto &dfs, int v) -> bool {
        int nd = exchange(d[v], 0) + 1;
        for (auto &u : g[v]) {
            if (R[u] == -1 or (d[R[u]] == nd and dfs(dfs, R[u]))) {
                L[v] = u, R[u] = v;
                return 1;
            }
        }
        return 0;
    };
    for (;;) {
        d.assign(n, 0);
        queue<int> que;
        bool ch = 0;
        rep(i, 0, n) if (L[i] == -1) {
            que.push(i);
            d[i] = 1;
        }
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &u : g[v]) {
                if (R[u] == -1)
                    ch = 1;
                else if (!d[R[u]]) {
                    d[R[u]] = d[v] + 1;
                    que.push(R[u]);
                }
            }
        }
        if (!ch)
            break;
        rep(i, 0, n) if (L[i] == -1) dfs(dfs, i);
    }
    return L;
}

/**
 * @brief Bipartite Matching
 */