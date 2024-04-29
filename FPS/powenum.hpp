#pragma once

template <typename T>
vector<T> PowEnumerate(Poly<T> &f, Poly<T> &g,
                       int m) { // [x^{deg f}]g f^i (i=0..m)
    assert(f[0] == 0);
    int n = 1;
    while (n < SZ(f))
        n <<= 1;
    int k = 1;
    Poly<T> P(n * 2), Q(n * 2);
    f.resize(n);
    g.resize(n);
    reverse(ALL(g));
    rep(i, 0, n) P[i] = g[i];
    rep(i, 1, n) Q[i] = -f[i];

    while (n > 1) {
        auto R = Q;
        rep(i, 0, SZ(R)) if (i & 1) R[i] = -R[i];
        auto PR = P * R;
        auto QR = Q * R;
        PR.resize(4 * n * k);
        QR.resize(4 * n * k);
        rep(i, 0, n * k * 2) {
            PR[2 * n * k + i] += P[i];
            QR[2 * n * k + i] += Q[i] + R[i];
        }
        P.assign(n * 2 * k, 0);
        Q.assign(n * 2 * k, 0);
        rep(j, 0, k * 2) rep(i, 0, n / 2) {
            P[j * n + i] = PR[j * 2 * n + i * 2 + 1];
            Q[j * n + i] = QR[j * 2 * n + i * 2];
        }
        n >>= 1;
        k <<= 1;
    }
    vector<T> ret(k);
    rep(i, 0, k) ret[i] = P[i * 2];
    reverse(ALL(ret));
    ret.resize(m + 1);
    return ret;
}

/**
 * @brief Pow Enumerate
 */