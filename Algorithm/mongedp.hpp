#pragma once
#include "Algorithm/fibonacci.hpp"

template <typename T, T wmx, typename F> T MongeShortestPath(int n, F f) {
    vector<T> dp(n, wmx);
    dp[0] = 0;
    vector<int> amin(n);

    auto check = [&](int i, int j) {
        T val = dp[j] + f(j, i);
        if (chmin(dp[i], val))
            amin[i] = j;
    };
    auto rec = [&](auto &rec, int L, int R) {
        if (R - L == 1)
            return;
        int mid = (L + R) >> 1;
        rep(k, amin[L], amin[R] + 1) check(mid, k);
        rec(rec, L, mid);
        rep(k, L + 1, mid + 1) check(R, k);
        rec(rec, mid, R);
    };

    rec(rec, 0, n - 1);
    return dp.back();
}

template <typename T, T wmx, typename F>
T dEdgeMongeShortestPath(int n, int d, F f) {
    auto calc = [&](T lamb) -> T {
        T ret = MongeShortestPath<T, wmx>(
                    n, [&](int i, int j) { return f(i, j) + lamb; }) -
                lamb * d;
        return ret;
    };
    ll lambda = FibonacciSearch<ll>(-wmx * 3, wmx * 3, calc);
    return calc(lambda);
}

/**
 * @brief Monge Shortest Path
 */