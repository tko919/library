#pragma once

struct BlockCut {
    using P = pair<int, int>;
    int n;
    vector<vector<int>> g;
    vector<int> low, ord, st, used;
    int nxt, k;
    vector<P> es;
    BlockCut() {}
    BlockCut(int n) : n(n), g(n), low(n), ord(n), used(n), nxt(n), k(0) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> run() {
        rep(v, 0, n) if (!used[v]) {
            dfs(v, -1);
            for (auto &x : st)
                es.push_back({nxt, x});
            nxt++;
            st.clear();
        }
        vector ret(nxt, vector<int>());
        for (auto &[u, v] : es) {
            ret[u].push_back(v);
            ret[v].push_back(u);
        }
        return ret;
    }
    void dfs(int v, int p) {
        st.push_back(v);
        used[v] = 1;
        low[v] = ord[v] = k++;
        int ch = 0;
        for (auto &to : g[v])
            if (to != p) {
                if (!used[to]) {
                    ch++;
                    int s = SZ(st);
                    dfs(to, v);
                    chmin(low[v], low[to]);
                    if ((p == -1 and ch > 1) or
                        (p != -1 and low[to] >= ord[v])) {
                        es.push_back({nxt, v});
                        while (SZ(st) > s) {
                            es.push_back({nxt, st.back()});
                            st.pop_back();
                        }
                        nxt++;
                    }
                } else {
                    chmin(low[v], ord[to]);
                }
            }
    }
};

/**
 * @brief Block Cut Tree
 */