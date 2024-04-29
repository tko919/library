#pragma once
#include "Graph/maxflow.hpp"

template <typename Cost> struct ProjectSelection {
    using C1 = array<Cost, 2>;
    using C2 = array<C1, 2>;
    using P = pair<int, Cost>;
    int orig, n, S, T;
    vector<vector<P>> es;
    Cost offset;
    vector<C1> base;

    ProjectSelection() {}
    ProjectSelection(int _n)
        : orig(_n), n(_n + 2), S(_n), T(_n + 1), es(n), offset(0), base(n) {}

    void add_cost(Cost cost) {
        offset += cost;
    }
    void add_profit(Cost profit) {
        add_cost(-profit);
    }

    void add_cost(int i, C1 cost) {
        base[i][0] += cost[0];
        base[i][1] += cost[1];
    }
    void add_profit(int i, C1 profit) {
        base[i][0] -= profit[0];
        base[i][1] -= profit[1];
    }
    void add_cost_0(int i, Cost cost) {
        add_cost(i, C1{cost, 0});
    }
    void add_cost_1(int i, Cost cost) {
        add_cost(i, C1{0, cost});
    }
    void add_profit_0(int i, Cost profit) {
        add_cost(i, C1{-profit, 0});
    }
    void add_profit_1(int i, Cost profit) {
        add_cost(i, C1{0, -profit});
    }

    void add_cost(int i, int j, C2 cost) {
        Cost A = cost[0][0], B = cost[0][1];
        Cost C = cost[1][0], D = cost[1][1];
        assert(B + C >= A + D);
        add_cost(A);
        add_cost(i, C1{0, B - A});
        add_cost(j, C1{0, D - C});
        add_cost_01(i, j, (B + C) - (A + D));
    }
    void add_profit(int i, int j, C2 profit) {
        rep(x, 0, 2) rep(y, 0, 2) profit[x][y] = -profit[x][y];
        add_cost(i, j, profit);
    }
    void add_cost_01(int i, int j, Cost cost) {
        assert(cost >= 0);
        if (cost)
            es[i].push_back({j, cost});
    }
    void add_cost_10(int i, int j, Cost cost) {
        add_cost_01(j, i, cost);
    }
    void add_profit_00(int i, int j, Cost profit) {
        add_cost(i, j, C2{-profit, 0, 0, 0});
    }
    void add_profit_11(int i, int j, Cost profit) {
        add_cost(i, j, C2{0, 0, 0, -profit});
    }

    void add_profit_all0(vector<int> &xs, Cost profit) {
        assert(profit >= 0);
        if (profit == 0)
            return;
        add_profit(profit);
        es.push_back({});
        es[S].push_back({n, profit});
        for (auto &i : xs)
            es[n].push_back({i, profit});
        n++;
    }
    void add_profit_all1(vector<int> &xs, Cost profit) {
        assert(profit >= 0);
        if (profit == 0)
            return;
        add_profit(profit);
        es.push_back({});
        es[n].push_back({T, profit});
        for (auto &i : xs)
            es[i].push_back({n, profit});
        n++;
    }

    pair<Cost, vector<int>> minCost() {
        MaxFlow mf(n);
        rep(i, 0, orig) {
            C1 &cost = base[i];
            if (cost[0] <= cost[1]) {
                add_cost(cost[0]);
                if (cost[1] > cost[0])
                    es[S].push_back({i, cost[1] - cost[0]});
            } else {
                add_cost(cost[1]);
                es[i].push_back({T, cost[0] - cost[1]});
            }
        }
        rep(v, 0, n) for (auto &[u, cost] : es[v]) {
            mf.add_edge(v, u, cost);
        }
        Cost ret = offset + mf.run(S, T);
        vector<int> cut = mf.cut();
        cut.resize(orig);
        return {ret, cut};
    }
    pair<Cost, vector<int>> maxProfit() {
        auto ret = minCost();
        ret.first = -ret.first;
        return ret;
    }
};

/**
 * @brief Project Selection
 */