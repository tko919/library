#pragma once
#include "Math/comb.hpp"

// f(0),..,f(d) -> f(t)
template <typename T> T Interpolate(vector<T> &ys, ll t) {
    int d = ys.size() - 1;
    if (t <= d)
        return ys[t];
    vector<T> L(d + 1, 1), R(d + 1, 1);
    rep(i, 0, d) L[i + 1] = L[i] * (t - i);
    for (int i = d; i; i--)
        R[i - 1] = R[i] * (t - i);
    T ret;
    rep(i, 0, d + 1) {
        T add = ys[i] * L[i] * R[i] * Fact<T>(i, 1) * Fact<T>(d - i, 1);
        if ((d - i) & 1)
            ret -= add;
        else
            ret += add;
    }
    return ret;
}

/**
 * @brief interpolate (one point)
 */