#pragma once
#include "Algorithm/projectselection.hpp"

template <typename Cost> struct KProjectSelection {
    static constexpr Cost LIM = std::numeric_limits<Cost>::max() / 2;
    int n;
    vector<int> Ks;
    vector<vector<int>> pos;
    ProjectSelection<Cost> psp;

    KProjectSelection() {}
    KProjectSelection(vector<int> &Ks) : n(SZ(Ks)), Ks(Ks), pos(n) {
        int now = 0;
        rep(i, 0, n) {
            pos[i].resize(Ks[i]);
            rep(j, 1, Ks[i]) pos[i][j] = now++;
        }
        psp = ProjectSelection<Cost>(now);
        rep(i, 0, n) {
            rep(j, 1, Ks[i] - 1) psp.add_cost_10(pos[i][j], pos[i][j + 1], LIM);
        }
    }
    void add_cost(Cost cost) {
        psp.add_cost(cost);
    }
    void add_profit(Cost profit) {
        psp.add_profit(profit);
    }

    void add_cost(int i, vector<Cost> &cost) {
        assert(SZ(cost) == Ks[i]);
        psp.add_cost(cost.back());
        rep(j, 1, Ks[i]) {
            psp.add_cost(pos[i][j], {0, cost[j - 1] - cost[j]});
        }
    }
    void add_profit(int i, vector<Cost> &profit) {
        for (auto &x : profit)
            x = -x;
        add_cost(i, profit);
    }

    void add_cost(int i, int j, vector<vector<Cost>> &cost) {
        assert(SZ(cost) == Ks[i]);
        vector<Cost> ibase(Ks[i]), jbase(Ks[j]);
        rep(x, 0, Ks[i]) {
            assert(SZ(cost[x]) == Ks[j]);
            ibase[x] = cost[x][0];
            rep(y, 0, Ks[j]) cost[x][y] -= ibase[x];
        }
        rep(y, 0, Ks[j]) {
            jbase[y] = cost[0][y];
            rep(x, 0, Ks[i]) cost[x][y] -= jbase[y];
        }
        add_cost(i, ibase);
        add_cost(j, jbase);

        rep(x, 1, Ks[i]) rep(y, 1, Ks[j]) {
            Cost add = cost[x][y] - cost[x][y - 1] - cost[x - 1][y] +
                       cost[x - 1][y - 1];
            assert(add <= 0);
            psp.add_profit_00(pos[i][x], pos[j][y], -add);
        }
    }

    pair<Cost, vector<int>> minCost() {
        auto [ret, ids] = psp.minCost();
        vector<int> xs(n);
        rep(i, 0, n) rep(j, 1, Ks[i]) {
            if (ids[pos[i][j]] == 1)
                break;
            xs[i] = j;
        }
        return {ret, xs};
    }
    pair<Cost, vector<int>> maxProfit() {
        auto ret = minCost();
        ret.first = -ret.first;
        return ret;
    }
};

/**
 * @brief K-Project Selection
 */