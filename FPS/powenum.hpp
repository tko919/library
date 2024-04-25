#pragma once
#include "Convolution/2D.hpp"

template <typename T>
vector<T> PowEnumerate(Poly<T> &f, Poly<T> &g) { // [x^n]f^i g (n=deg f,i=0..n)
    assert(f[0] == 0);
    int n = f.deg();
    int k = 1;
    // vector P(n + 1, Poly<T>(k + 1));
    // vector Q(n + 1, Poly<T>(k + 1));
    Poly<T> P((n + 1) * (k * 2 + 1)), Q((n + 1) * (k * 2 + 1));
    rep(i, 0, n + 1) P[i * (k * 2 + 1)] = g[i];
    Q[0] = 1;
    rep(i, 1, n + 1) Q[i * (k * 2 + 1) + 1] = -f[i];

    while (n) {
        auto R = Q;
        for (int i = 1; i <= n; i += 2)
            rep(j, 0, k + 1) R[i * (k * 2 + 1) + j] = -R[i * (k * 2 + 1) + j];
        P *= R;
        Q *= R;
        Poly<T> nP((n / 2 + 1) * (k * 4 + 1)), nQ((n / 2 + 1) * (k * 4 + 1));
        for (int i = 0, x = n & 1; x <= n; i++, x += 2)
            rep(j, 0, k * 2 + 1) nP[i * (k * 4 + 1) + j] =
                P[x * (k * 2 + 1) + j];
        for (int i = 0, x = 0; x <= n; i++, x += 2)
            rep(j, 0, k * 2 + 1) nQ[i * (k * 4 + 1) + j] =
                Q[x * (k * 2 + 1) + j];
        swap(P, nP);
        swap(Q, nQ);
        n >>= 1;
        k <<= 1;
    }
    vector<T> ret(SZ(f));
    rep(i, 0, SZ(f)) ret[i] = P[i];
    return ret;
}

/**
 * @brief Pow Enumerate
 */