#pragma once
#include "DataStructure/unionfind.hpp"

template <bool directed> struct EulerianTrail {
    using P = pair<int, int>;
    int n, m;
    vector<vector<P>> g;
    UnionFind uni;
    vector<P> es;
    vector<int> used, deg;
    EulerianTrail() {}
    EulerianTrail(int N) : n(N), m(0), g(n), uni(n), deg(n) {}
    void add_edge(int u, int v) {
        es.push_back({u, v});
        g[u].push_back({v, m});
        uni.unite(u, v);
        if (directed) {
            deg[u]++;
            deg[v]--;
        } else {
            g[v].push_back({u, m});
            deg[u]++;
            deg[v]++;
        }
        m++;
    }
    pair<vector<int>, vector<vector<int>>> run() {
        map<int, vector<int>> grps;
        rep(v, 0, n) grps[uni.root(v)].push_back(v);
        vector<int> start;
        vector<vector<int>> ret;
        used.assign(m, 0);
        for (auto &[_, vs] : grps) {
            int S = -1;
            if (directed) {
                for (auto &v : vs) {
                    if (abs(deg[v]) > 1)
                        return {};
                    else if (deg[v] == 1) {
                        if (S == -1)
                            S = v;
                        else
                            return {};
                    }
                }
            } else {
                int odd = 0;
                for (auto &v : vs) {
                    if (deg[v] & 1) {
                        S = v;
                        odd++;
                    }
                }
                if (odd > 2)
                    return {};
            }
            if (S == -1)
                S = vs.front();
            auto add = get(S);
            if (add.size()) {
                start.push_back(S);
                ret.push_back(add);
            }
        }
        return {start, ret};
    }

  private:
    vector<int> get(int s) {
        stack<P> st;
        vector<int> ret;
        st.push({s, -1});
        while (!st.empty()) {
            int v = st.top().first;
            if (g[v].empty()) {
                ret.push_back(st.top().second);
                st.pop();
            } else {
                auto &e = g[v].back();
                g[v].pop_back();
                if (used[e.second])
                    continue;
                used[e.second] = 1;
                st.push(e);
            }
        }
        ret.pop_back();
        reverse(ALL(ret));
        return ret;
    }
};

/**
 * @brief Eulerian Trail
 */