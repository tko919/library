#pragma once
#include "Convolution/subset.hpp"

template <typename T>
vector<T> ChromaticPolynomial(int n,
                              vector<ull> &g) { // v-th bit of g[u]:has u-v edge
    vector<T> base(1 << n);
    rep(mask, 1, 1 << n) {
        base[mask] = 1;
        rep(u, 0, n) if (mask >> u & 1) {
            rep(v, 0, n) if (mask >> v & 1) {
                if (g[u] >> v & 1) {
                    base[mask] = 0;
                    break;
                }
            }
            if (base[mask] == 0)
                break;
        }
    }

    vector<T> t(1 << n);
    t.back() = 1;
    SubsetConvolution<T> buf;
    auto ways = buf.TransposeCompositionEGF(base, t);
    vector<T> ret(n + 1);
    rep(i, 0, n + 1) {
        vector<T> add(1, 1);
        rep(j, 0, i) {
            vector<T> nxt(SZ(add) + 1);
            rep(k, 0, SZ(add)) {
                nxt[k + 1] += add[k];
                nxt[k] -= add[k] * j;
            }
            swap(add, nxt);
        }
        rep(k, 0, SZ(add)) ret[k] += ways[i] * add[k];
    }
    return ret;
}

/**
 * @brief Chromatic Number
 */