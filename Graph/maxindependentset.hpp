#pragma once
#include "Utility/random.hpp"

struct MaxIndependentSet {
    const int n;
    vector<ll> es;
    MaxIndependentSet(int _n) : n(_n), es(n) {}
    void add_edge(int u, int v) {
        es[u] |= 1LL << v;
        es[v] |= 1LL << u;
    }
    pair<ll, ll> run(vector<ll> &cost, int _rot = 1e6) {
        vector<int> ord(n);
        iota(ALL(ord), 0);
        ll ret = 0;
        ll cur = 0;
        rep(_, 0, _rot) {
            Random::shuffle(ALL(ord));
            ll add = 0;
            ll used = 0;
            for (auto &v : ord)
                if (!(used & es[v])) {
                    used |= (1LL << v);
                    add += cost[v];
                }
            if (chmax(ret, add))
                cur = used;
        }
        return {ret, cur};
    }
};

/**
 * @brief Maximum Independent Set
 */