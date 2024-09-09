#pragma once
#include "Graph/euler.hpp"

struct EdgeColoring {
    typedef array<int, 2> P;
    typedef array<int, 3> T;
    int n;
    vector<P> _es, es;
    EdgeColoring() {}
    void add_edge(int u, int v) {
        _es.push_back({u, v});
    }
    array<vector<int>, 2> divide(vector<P> tmp) { // divide eulerian trail
        EulerianTrail<0> euler(n * 2);
        for (auto &[x, y] : tmp)
            euler.add_edge(x, y);
        auto piece = euler.run().second;
        vector<int> p;
        for (auto &v : piece)
            p.insert(p.end(), ALL(v));
        array<vector<int>, 2> res;
        rep(i, 0, p.size()) res[i & 1].push_back(p[i]);
        return res;
    }
    vector<int> find(vector<int> ids) { // find perfect matching
        int k = (int)ids.size() / n;
        assert(n * k == (int)ids.size());
        int t = 0;
        while ((1 << t) < n * k)
            t++;
        int x = (1 << t) / k, y = (1 << t) % k;
        vector<int> ori(ids.size(), x), dum(n, y);
        while (t--) {
            vector<P> tmp;
            vector<int> add;
            int cnt = 0;
            rep(i, 0, ids.size()) {
                if (ori[i] & 1) {
                    tmp.push_back({es[ids[i]][0], es[ids[i]][1]});
                    add.push_back(i);
                    cnt++;
                }
                ori[i] >>= 1;
            }
            rep(i, 0, n) {
                if (dum[i] & 1) {
                    tmp.push_back({i, n + i});
                    add.push_back(i);
                }
                dum[i] >>= 1;
            }
            array<vector<int>, 2> w = divide(tmp);
            int dum_cnt[2] = {};
            rep(i, 0, 2) for (int x : w[i]) if (x >= cnt) dum_cnt[i]++;
            for (int i : w[dum_cnt[0] > dum_cnt[1]]) {
                if (i < cnt)
                    ori[add[i]]++;
                else
                    dum[add[i]]++;
            }
        }
        vector<int> res;
        rep(i, 0, ids.size()) if (ori[i]) res.push_back(ids[i]);
        assert((int)res.size() == n);
        return res;
    }
    vector<int> used;
    vector<vector<int>>
    colorize(vector<int> ids) { // must be regular bipartite graph
        int k = (int)ids.size() / n;
        assert(n * k == (int)ids.size());
        if (k == 0)
            return {};
        if (k == 1)
            return {ids};
        vector<vector<int>> res;
        if (k & 1) {
            auto add = find(ids);
            for (int x : add)
                used[x] = 1;
            vector<int> rem;
            for (int x : ids)
                if (!used[x])
                    rem.push_back(x);
            for (int x : add)
                used[x] = 0;
            res = colorize(rem);
            res.push_back(add);
        } else {
            vector<P> tmp;
            for (int i : ids)
                tmp.push_back({es[i][0], es[i][1]});
            array<vector<int>, 2> p = divide(tmp);
            rep(i, 0, 2) for (auto &x : p[i]) x = ids[x];
            res = colorize(p[0]);
            int cur = k >> 1;
            while (__builtin_popcount(cur) != 1) {
                auto add = res.back();
                res.pop_back();
                p[1].insert(p[1].end(), ALL(add));
                cur++;
            }
            auto add = colorize(p[1]);
            res.insert(res.end(), ALL(add));
        }
        return res;
    }
    int run(vector<int> &res) {
        // normalize
        int LR[2] = {};
        for (auto e : _es)
            rep(j, 0, 2) chmax(LR[j], e[j] + 1);
        vector<int> deg[2], kind[2], sz[2];
        rep(i, 0, 2) deg[i].resize(LR[i]), kind[i].resize(LR[i]);
        for (auto e : _es)
            rep(j, 0, 2) deg[j][e[j]]++;
        int k = 0;
        rep(i, 0, 2) rep(j, 0, LR[i]) chmax(k, deg[i][j]);
        rep(j, 0, 2) {
            for (int i = 0; i < LR[j];) {
                int add = 0;
                while (i < LR[j] and deg[j][i] + add <= k) {
                    kind[j][i] = (int)sz[j].size();
                    add += deg[j][i++];
                }
                sz[j].push_back(add);
            }
        }
        rep(i, 0, 2) while (sz[i].size() < sz[i ^ 1].size()) sz[i].push_back(0);
        n = (int)sz[0].size();
        for (auto e : _es)
            es.push_back({kind[0][e[0]], n + kind[1][e[1]]});
        int nxt = 0;
        rep(i, 0, n) while (sz[0][i] < k) {
            while (sz[1][nxt] == k)
                nxt++;
            es.push_back({i, n + nxt});
            sz[0][i]++;
            sz[1][nxt]++;
        }
        res.resize(_es.size());
        used.resize(n * k, 0);
        vector<int> tmp(n * k);
        iota(ALL(tmp), 0);
        auto ret = colorize(tmp);
        rep(i, 0, ret.size()) for (int idx : ret[i]) {
            if (idx < (int)_es.size())
                res[idx] = i;
        }
        return k;
    }
};

/**
 * @brief Edge Coloring
 */