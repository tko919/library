#pragma once

template <typename T> Poly<T> Composition(Poly<T> &f, Poly<T> &g) {
    assert(SZ(f) == SZ(g) and g[0] == 0);
    const int N = f.deg();

    auto dfs = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {
        if (n == 0) {
            Poly<T> P(k * 2 + 1);
            rep(i, 0, N + 1) P[i] = f[i];
            return P;
        }
        int n2 = n >> 1, k2 = k << 1;

        auto R = Q;
        for (int i = 1; i <= n; i += 2)
            rep(j, 0, k + 1) R[i * (k * 2 + 1) + j] = -R[i * (k * 2 + 1) + j];
        auto bufQ = Q * R;
        Poly<T> nQ((n2 + 1) * (k2 * 2 + 1));
        for (int i = 0, x = 0; x <= n; i++, x += 2)
            rep(j, 0, k * 2 + 1) nQ[i * (k2 * 2 + 1) + j] =
                bufQ[x * (k * 2 + 1) + j];
        auto nP = dfs(dfs, n2, k2, nQ);

        Poly<T> bufP((n + 1) * (k * 2 + 1));
        for (int i = 0, x = n & 1; x <= n; i++, x += 2)
            rep(j, 0, k * 2 + 1) bufP[x * (k * 2 + 1) + j] =
                nP[i * (k * 4 + 1) + j];

        // middle product
        const int M = R.deg();
        reverse(ALL(R));
        bufP *= R;
        Poly<T> P((n + 1) * (k * 2 + 1));
        rep(i, 0, SZ(P)) P[i] = bufP[i + M];
        return P;
    };
    int k = 1;
    Poly<T> Q((N + 1) * (k * 2 + 1));
    Q[0] = 1;
    rep(i, 1, N + 1) Q[i * (k * 2 + 1) + 1] = -g[i];
    auto P = dfs(dfs, N, 1, Q);
    Poly<T> ret(N + 1);
    rep(i, 0, N + 1) ret[i] = P[i * (k * 2 + 1)];
    reverse(ALL(ret));
    return ret;
};

/**
 * @brief Composition of Formal Power Series
 */