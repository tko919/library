#pragma once
#include "Graph/bimatching.hpp"
#include "Graph/scc.hpp"

vector<vector<int>> DMdecomposition(int n, int m, vector<vector<int>> &g,
                                    vector<int> match) {
    if (match.empty())
        match = BiMatching(n, m, g);
    vector G(n + m, vector<int>()), REV(n + m, vector<int>());
    rep(i, 0, n) for (auto &j : g[i]) {
        G[i].push_back(j + n);
        REV[j + n].push_back(i);
    }
    vector<int> R(m, -1);
    rep(i, 0, n) if (match[i] != -1) {
        G[match[i] + n].push_back(i);
        REV[i].push_back(match[i] + n);
        R[match[i]] = i;
    }

    vector<int> V0, Vinf;
    queue<int> que;
    vector<int> used(n + m);
    rep(i, 0, n) if (match[i] == -1) {
        used[i] = 1;
        que.push(i);
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        Vinf.push_back(v);
        for (auto &to : G[v])
            if (!used[to]) {
                used[to] = 1;
                que.push(to);
            }
    }
    rep(i, 0, m) if (R[i] == -1) {
        used[i + n] = 1;
        que.push(i + n);
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        V0.push_back(v);
        for (auto &to : REV[v])
            if (!used[to]) {
                used[to] = 1;
                que.push(to);
            }
    }

    SCC scc(n + m);
    rep(i, 0, n + m) for (auto &to : G[i]) {
        if (!used[i] and !used[to])
            scc.add_edge(i, to);
    }
    scc.run();
    vector group(scc.m, vector<int>());
    rep(i, 0, n + m) if (!used[i]) group[scc.id[i]].push_back(i);

    vector<vector<int>> ret;
    ret.push_back(V0);
    for (auto &v : group)
        ret.push_back(v);
    ret.push_back(Vinf);
    return ret;
}

/**
 * @brief DM decomposition
 */