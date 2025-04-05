#pragma once

template <typename T>
pair<T, vector<int>> MinimumSteinerTree(int n, vector<tuple<int, int, T>> &es,
                                        vector<int> &terminal) {
    vector g(n, vector<tuple<int, T, int>>());
    rep(i, 0, SZ(es)) {
        auto [x, y, w] = es[i];
        g[x].push_back({y, w, i});
        g[y].push_back({x, w, i});
    }
    int t = SZ(terminal);
    using P = pair<ll, int>;
    vector dp(1 << t, vector<T>(n, numeric_limits<T>::max() / 10));
    vector pre(1 << t, vector<P>(n, {-1, -1})); // {subset,-1} or {from,eid}
    rep(i, 0, t) {
        dp[1 << i][terminal[i]] = 0;
    }
    rep(mask, 1, 1 << t) {
        rep(v, 0, n) {
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (chmin(dp[mask][v], dp[sub][v] + dp[mask ^ sub][v]))
                    pre[mask][v] = {sub, -1};
            }
        }
        if (mask == ((1 << t) - 1))
            break;
        priority_queue<P, vector<P>, greater<P>> pq;
        rep(v, 0, n) pq.push({dp[mask][v], v});
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dp[mask][v] != d)
                continue;
            for (auto &[to, cost, id] : g[v])
                if (chmin(dp[mask][to], dp[mask][v] + cost)) {
                    pq.push({dp[mask][to], to});
                    pre[mask][to] = {v, id};
                }
        }
    }
    ll cost = dp[(1 << t) - 1][terminal[0]];
    vector<int> ret;
    {
        queue<P> que;
        que.push({(1 << t) - 1, terminal[0]});
        while (!que.empty()) {
            auto [mask, v] = que.front();
            que.pop();
            auto [a, b] = pre[mask][v];
            if (a == -1)
                continue;
            else if (b == -1) {
                que.push({a, v});
                que.push({mask ^ a, v});
            } else {
                que.push({mask, a});
                ret.push_back(b);
            }
        }
    }
    return {cost, ret};
}

/**
 * @brief Steiner Tree
 */