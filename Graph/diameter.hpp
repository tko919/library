#pragma once

template <typename T>
pair<T, vector<int>> Diameter(vector<vector<pair<int, T>>> &g) {
    int n = SZ(g);
    vector<T> dist(n, INF);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &[to, c] : g[v])
            if (dist[to] == INF) {
                dist[to] = dist[v] + c;
                que.push(to);
            }
    }
    int v1 = -1;
    {
        T mx = -INF;
        rep(v, 0, n) if (chmax(mx, dist[v])) v1 = v;
    }
    dist.assign(n, INF);
    dist[v1] = 0;
    que.push(v1);
    vector<int> par(n);
    par[v1] = -1;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &[to, c] : g[v])
            if (dist[to] == INF) {
                dist[to] = dist[v] + c;
                par[to] = v;
                que.push(to);
            }
    }
    int v2 = -1;
    T diam = -INF;
    rep(v, 0, n) if (chmax(diam, dist[v])) v2 = v;
    vector<int> path;
    int cur = v2;
    path.push_back(cur);
    while (cur != v1) {
        cur = par[cur];
        path.push_back(cur);
    }
    return {diam, path};
}

/**
 * @brief Diameter
 */