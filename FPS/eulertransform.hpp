#pragma once

template <typename T> Poly<T> EulerTransform(Poly<T> &f) {
    int n = SZ(f);
    Poly<Fp> g(n);
    rep(d, 1, n) {
        for (int k = d; k < n; k += d)
            g[k] += f[d] * d;
    }
    rep(d, 1, n) g[d] /= d;
    return g.exp();
}

/**
 * @brief Euler Transform
 */