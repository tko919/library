#pragma once

template <typename T> void mult2D(vector<Poly<T>> &f, vector<Poly<T>> g) {
    int H1 = SZ(f), W1 = SZ(f[0]);
    int H2 = SZ(g), W2 = SZ(g[0]);
    int H = H1 + H2 - 1, W = W1 + W2 - 1;

    Poly<T> ff(H1 * W), gg(H2 * W);

    rep(i, 0, H1) rep(j, 0, W1) ff[i * W + j] = f[i][j];
    rep(i, 0, H2) rep(j, 0, W2) gg[i * W + j] = g[i][j];
    ff *= gg;

    f.resize(H);
    rep(i, 0, H) {
        f[i].resize(W);
        rep(j, 0, W) f[i][j] = ff[i * W + j];
    }
    return;
}

/**
 * @brief 2D Convolution
 */