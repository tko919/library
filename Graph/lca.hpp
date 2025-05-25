#pragma once

struct LCA {
    LCA(int _n = 0) : n(_n), g(_n), depth(_n + 1, inf), start(_n) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void run(int root = 0) {
        depth[root] = 0;
        dfs(root, -1);
        N = 1;
        while (N < int(euler.size()))
            N <<= 1;
        tree.resize(N * 2, n);
        rep(i, 0, euler.size()) tree[N + i] = euler[i];
        for (int i = N - 1; i > 0; i--)
            tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
    }
    int lca(int u, int v) {
        int a = start[u], b = start[v];
        if (a > b)
            swap(a, b);
        b++;
        int res = n;
        for (int T = b - a; T >= 1; T = b - a) {
            int x = a | ((1U << 31) >> __builtin_clz(T));
            int y = x & -x, k = __builtin_ctz(x);
            res = op(res, tree[(N | a) >> k]);
            a += y;
        }
        return res;
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - depth[lca(u, v)] * 2;
    }

  private:
    int n, N;
    vector<vector<int>> g;
    vector<int> depth, start, euler, tree;
    void dfs(int v, int p) {
        start[v] = euler.size();
        euler.push_back(v);
        for (auto &to : g[v])
            if (to != p) {
                depth[to] = depth[v] + 1;
                dfs(to, v);
                euler.push_back(v);
            }
    }
    int op(int u, int v) {
        if (depth[u] < depth[v])
            return u;
        else
            return v;
    }
};

/**
 * @brief Lowest Common Ancestor
 */