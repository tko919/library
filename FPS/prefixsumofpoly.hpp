#pragma once
#include "FPS/famous.hpp"
#include "Math/comb.hpp"

template <typename T> Poly<T> PrefixSum(Poly<T> &f) { // g(x)=sum_{y=0}^{x} f(y)
    if (f.empty())
        return {};
    int n = f.size();
    auto ber = Bernoulli<T>(n - 1);
    if (n >= 2)
        ber[1] = -ber[1];
    Poly<T> base(n);
    rep(i, 0, n) {
        ber[i] *= Fact<T>(i, 1);
        if (i)
            base[i] = f[i] * Fact<T>(i);
    }
    reverse(ALL(ber));
    base *= ber;
    Poly<T> ret(n + 1);
    ret[0] = f[0], ret[1] = f[0];
    rep(i, 1, n + 1) {
        ret[i] += base[i + n - 2] * Fact<T>(i, 1);
    }
    return ret;
}

/**
 * @brief Prefix Sum of Polynomial
 */