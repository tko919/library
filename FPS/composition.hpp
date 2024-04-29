#pragma once

template <typename T> Poly<T> Composition(Poly<T> &f, Poly<T> &g) {
    assert(SZ(f) == SZ(g) and g[0] == 0);

    auto dfs = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {
        if (n == 1) {
            reverse(ALL(f));
            Poly<T> P(k * 2);
            rep(i, 0, k) P[i * 2] = f[i];
            return P;
        }
        int n2 = n >> 1, k2 = k << 1;

        auto R = Q;
        rep(i, 0, 2 * n * k) if (i & 1) R[i] = -R[i];
        auto QR = Q * R;
        QR.resize(4 * n * k);
        rep(i, 0, 2 * n * k) QR[2 * n * k + i] += Q[i] + R[i];
        Poly<T> nQ(2 * n * k);
        rep(i, 0, k2) rep(j, 0, n2) nQ[n * i + j] = QR[2 * n * i + 2 * j];

        auto nP = dfs(dfs, n2, k2, nQ);
        Poly<T> PR(4 * n * k);
        rep(i, 0, k2) rep(j, 0, n2) PR[2 * n * i + 2 * j + 1] = nP[n * i + j];
        Poly<T> P(2 * n * k);
        rep(i, 0, 2 * n * k) P[i] += PR[2 * n * k + i];
        // middle product
        const int M = R.deg();
        reverse(ALL(R));
        PR *= R;
        rep(i, 0, 2 * n * k) P[i] += PR[i + M];
        return P;
    };

    int n = SZ(f), N = 1;
    while (N < n)
        N <<= 1;
    f.resize(N);
    g.resize(N);
    int k = 1;
    Poly<T> Q(N * 2);
    rep(i, 0, n) Q[i] = -g[i];
    auto P = dfs(dfs, N, k, Q);
    Poly<T> ret(n);
    rep(i, 0, n) ret[i] = P[N - 1 - i];
    return ret;
};

/**
 * @brief Composition of Formal Power Series
 */