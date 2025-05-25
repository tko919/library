#pragma once

namespace Prufer {
vector<vector<int>> encode(vector<int> &a) {
    int n = SZ(a) + 1;
    assert(a.back() == n - 1);
    vector tree(n, vector<int>());
    if (n == 1)
        return tree;
    vector<int> deg(n, 1);
    for (auto &v : a)
        deg[v]++;
    int ptr = 0, leaf = -1;
    rep(i, 0, n - 1) {
        if (leaf == -1) {
            while (deg[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
        tree[a[i]].push_back(leaf);
        tree[leaf].push_back(a[i]);
        deg[leaf]--, deg[a[i]]--;
        if (a[i] < ptr and deg[a[i]] == 1)
            leaf = a[i];
        else
            leaf = -1;
    }
    return tree;
}
vector<int> decode(vector<vector<int>> &tree) {
    int n = SZ(tree);
    vector<int> par(n);
    auto dfs = [&](auto &dfs, int v, int p) -> void {
        par[v] = p;
        for (auto &to : tree[v])
            if (to != p) {
                dfs(dfs, to, v);
            }
    };
    dfs(dfs, n - 1, -1);
    vector<int> deg(n);
    rep(v, 0, n) deg[v] = SZ(tree[v]);
    vector<int> ret(n - 1);
    int ptr = 0, leaf = -1;
    rep(i, 0, n - 1) {
        if (leaf == -1) {
            while (deg[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
        ret[i] = par[leaf];
        deg[leaf]--, deg[par[leaf]]--;
        if (deg[par[leaf]] == 1 and par[leaf] < ptr)
            leaf = par[leaf];
        else
            leaf = -1;
    }
    return ret;
}
}; // namespace Prufer

/**
 * @brief Prufer Code
 */