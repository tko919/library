#pragma once
#include "Convolution/ntt.hpp"

template <typename T, void (*ntt)(vector<T> &, bool)>
vector<T> MultivariateConvolution(const vector<T> &f, const vector<T> &g,
                                  vector<int> &a) {
    int n = f.size(), k = a.size(), m = 1 << __lg(4 * n - 1);
    if (k == 0)
        return vector<T>({f[0] * g[0]});

    vector<int> chi(n);
    rep(x, 0, n) {
        int t = x;
        rep(i, 0, k - 1) {
            t /= a[i];
            chi[x] += t;
        }
        chi[x] %= k;
    }

    vector F(k, vector<T>(m)), G(k, vector<T>(m));
    rep(i, 0, n) {
        F[chi[i]][i] = f[i];
        G[chi[i]][i] = g[i];
    }

    for (auto &v : F)
        ntt(v, 0);
    for (auto &v : G)
        ntt(v, 0);
    vector<T> tmp(k * 2);
    rep(x, 0, m) {
        fill(ALL(tmp), 0);
        rep(i, 0, k) rep(j, 0, k) {
            tmp[i + j] += F[i][x] * G[j][x];
        }
        rep(i, 0, k) F[i][x] = tmp[i] + tmp[i + k];
    }
    for (auto &v : F)
        ntt(v, 1);
    vector<T> res(n);
    rep(i, 0, n) res[i] = F[chi[i]][i];
    return res;
}

/**
 * @brief Multivariate Convolution
 */