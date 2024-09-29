#pragma once

vector<pair<int, int>> GeneralMatch(int n, vector<pair<int, int>> &es) {
    mt19937 rnd;
    vector<vector<int>> g(n + 1);
    for (auto &[u, v] : es) {
        g[u + 1].push_back(v + 1);
        g[v + 1].push_back(u + 1);
    }
    vector<int> used(n + 1), mate(n + 1);
    int T;
    auto dfs = [&](auto &dfs, int v) -> bool {
        used[v] = T;
        shuffle(ALL(g[v]), rnd);
        for (auto &u : g[v]) {
            int w = mate[u];
            if (used[w] < T) {
                mate[v] = u, mate[u] = v, mate[w] = 0;
                if (!w or dfs(dfs, w))
                    return 1;
                mate[u] = w, mate[w] = u, mate[v] = 0;
            }
        }
        return 0;
    };
    rep(_, 0, 10) {
        used.assign(n + 1, 0);
        rep(v, 1, n + 1) if (!mate[v]) {
            T++;
            dfs(dfs, v);
        }
    }
    vector<pair<int, int>> ret;
    rep(v, 1, n + 1) if (v < mate[v]) ret.push_back({v - 1, mate[v] - 1});
    return ret;
}

/**
 * @brief General Matching
 */