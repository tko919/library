#pragma once
#include "Math/comb.hpp"

template <typename T> Poly<T> comp_ApBx(const Poly<T> &f, T a, T b) { // f(a+bx)
    auto g = f.shift(a.v);
    T pw = 1;
    for (auto &x : g) {
        x *= pw;
        pw *= b;
    }
    return g;
}

template <typename T>
Poly<T> Mobius(const Poly<T> &f, T a, T b, T c, T d) { // f((a+bx)/(c+dx))
    assert(c != 0 or d != 0);
    if (d == 0) {
        T a_c = a / c, b_c = b / c;
        return comp_ApBx(f, a_c, b_c);
    }
    T p = b / d, q = a - b * c / d;
    auto g = comp_ApBx(f, p, q);
    reverse(ALL(g));
    g = comp_ApBx(g, c, d);
    int n = g.size();
    Poly<T> den(n);
    T cpw = c.pow(n - 1), dpw = 1, cinv = c.inv();
    rep(i, 0, n) {
        den[i] = cpw * dpw * nCr<T>(n - 1, i);
        cpw *= cinv, dpw *= d;
    }
    g *= den.inv();
    g.resize(n);
    return g;
}

/**
 * @brief Mobius Transform
 */