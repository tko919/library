#pragma once

// query(u,v,w,i,j,k): vertex {u,v,w}, edge {i,j,k}
template <typename F>
void EnumTriangle(int n, vector<pair<int, int>> &es, F query) {
    using P = pair<int, int>;
    vector<int> deg(n);
    for (auto &[x, y] : es)
        deg[x]++, deg[y]++;
    vector H(n, vector<P>());
    rep(i, 0, SZ(es)) {
        auto [x, y] = es[i];
        if (P{deg[x], x} < P{deg[y], y})
            H[x].push_back({y, i});
        else
            H[y].push_back({x, i});
    }
    vector<int> used(n, -1);
    rep(u, 0, n) {
        for (auto &[v, i] : H[u])
            used[v] = i;
        for (auto &[v, j] : H[u]) {
            for (auto &[w, k] : H[v])
                if (used[w] != -1) {
                    query(u, v, w, used[w], j, k);
                }
        }
        for (auto &[v, i] : H[u])
            used[v] = -1;
    }
}

/**
 * @brief Enumerate Triangle
 */