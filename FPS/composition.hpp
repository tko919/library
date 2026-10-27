#pragma once

template <typename T> Poly<T> Composition(Poly<T> f, Poly<T> g) {
    assert(SZ(f) == SZ(g));
    f = f.shift(g[0].v);
    g[0] = 0;

    int sz = SZ(f), N = 1;
    while (N < sz)
        N <<= 1;
    f.resize(N);
    g.resize(N);
    reverse(ALL(f));

    static NTT<T> trans;
    const int M = 4 * N;
    assert(M <= (1 << NTT<T>::rank2));

    // The NTT is stored in bit-reversed order.  For R(x) = Q(-x), prepare
    // the permutation and phase that turn NTT(Q) into NTT(reverse(R)).
    const int h = __builtin_ctzll((unsigned int)M);
    vector<int> bitrev(M), reflect(M);
    for (int i = 1; i < M; i++)
        bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (h - 1));

    Poly<T> twist(M);
    T pw = 1, step = -trans.iroot[h];
    for (int e = 0; e < M; e++) {
        int i = bitrev[e];
        reflect[i] = bitrev[((M >> 1) - e) & (M - 1)];
        twist[i] = pw;
        pw *= step;
    }

    auto dfs = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {
        if (n == 1) {
            Poly<T> P(k * 2);
            rep(i, 0, k) P[i * 2] = f[i];
            return P;
        }
        int n2 = n >> 1, k2 = k << 1;
        const int L = 2 * n * k;

        // NTT(Q(-x))[i] is NTT(Q)[i ^ 1] in this ordering, so Q*R needs
        // only one forward transform and one inverse transform.
        Poly<T> qhat = Q;
        qhat.resize(M);
        trans.ntt(qhat);
        {
            Poly<T> QR(M);
            for (int i = 0; i < M; i++)
                QR[i] = qhat[i] * qhat[i ^ 1];
            trans.ntt(QR, 1);

            // Q(x) + Q(-x) contains only the even coefficients.
            for (int i = 0; i < L; i += 2)
                QR[L + i] += Q[i] + Q[i];

            Poly<T> nQ(L);
            rep(i, 0, k2) rep(j, 0, n2) nQ[n * i + j] = QR[2 * n * i + 2 * j];
            Q.swap(nQ);
        }

        // Convert qhat in place to NTT(reverse(Q_old(-x))).  The mapping is
        // an involution, so each pair can be updated without another buffer.
        for (int i = 0; i < M; i++) {
            int j = reflect[i];
            if (i < j) {
                T x = qhat[i], y = qhat[j];
                qhat[i] = y * twist[i];
                qhat[j] = x * twist[j];
            } else if (i == j) {
                qhat[i] *= twist[i];
            }
        }

        auto nP = dfs(dfs, n2, k2, Q);
        Poly<T> PR(M);
        rep(i, 0, k2) rep(j, 0, n2) PR[2 * n * i + 2 * j + 1] = nP[n * i + j];
        Poly<T> P(L);
        rep(i, 0, L) P[i] += PR[L + i];
        // middle product
        const int offset = L - 1;
        trans.ntt(PR);
        rep(i, 0, M) PR[i] *= qhat[i];
        trans.ntt(PR, 1);
        rep(i, 0, L) P[i] += PR[i + offset];
        return P;
    };

    int k = 1;
    Poly<T> Q(N * 2);
    rep(i, 0, sz) Q[i] = -g[i];
    auto P = dfs(dfs, N, k, Q);
    Poly<T> ret(sz);
    rep(i, 0, sz) ret[i] = P[N - 1 - i];
    return ret;
};

/**
 * @brief Composition of Formal Power Series
 */
