#pragma once
#include "Math/comb.hpp"

template <typename T>
Poly<T> SamplePointsShift(vector<T> &ys, T c, int m = -1) {
    ll n = ys.size() - 1, C = c.v % T::get_mod();
    if (m == -1)
        m = n + 1;
    if (C <= n) {
        Poly<T> res;
        rep(i, C, n + 1) res.push_back(ys[i]);
        if (int(res.size()) >= m) {
            res.resize(m);
            return res;
        }
        auto add = SamplePointsShift<T>(ys, n + 1, m - res.size());
        for (int i = 0; int(res.size()) < m; i++) {
            res.push_back(add[i]);
        }
        return res;
    }
    if (C + m > T::get_mod()) {
        auto res = SamplePointsShift<T>(ys, c, T::get_mod() - c.v);
        auto add = SamplePointsShift<T>(ys, 0, m - res.size());
        rep(i, 0, add.size()) res.push_back(add[i]);
        return res;
    }

    Poly<T> A(n + 1), B(m + n);
    rep(i, 0, n + 1) {
        A[i] = ys[i] * Fact<T>(i, 1) * Fact<T>(n - i, 1);
        if ((n - i) & 1)
            A[i] = -A[i];
    }
    rep(i, 0, m + n) B[i] = Fp(1) / (c - n + i);
    auto AB = A * B;
    vector<T> res(m);
    Fp base = 1;
    rep(x, 0, n + 1) base *= (c - x);
    rep(i, 0, m) {
        res[i] = AB[n + i] * base;
        base *= (c + i + 1);
        base *= B[i];
    }
    return res;
}

/**
 * @brief Shift of Sampling Points of Polynomial
 */