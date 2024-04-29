#pragma once
#include "FPS/powenum.hpp"

template <typename T> Poly<T> CompositionInv(Poly<T> &f) {
    assert(SZ(f) >= 2 and f[0] == 0 and f[1] != 0);
    const int n = f.deg();
    const T c = f[1];
    const T invc = c.inv();
    for (auto &x : f)
        x *= invc;
    Poly<T> g(n + 1);
    g[n] = 1;
    auto ret = Poly<Fp>{PowEnumerate(f, g, n)};
    rep(i, 1, n + 1) ret[i] *= T(n) * Inv<T>(i);
    reverse(ALL(ret));
    ret[0] = 1;
    ret = ret.log();
    const T invn = T(1) / -n;
    for (auto &x : ret)
        x *= invn;
    ret = (ret.exp()) << 1;
    ret.resize(n + 1);
    T buf = 1;
    for (auto &x : ret) {
        x *= buf;
        buf *= invc;
    }
    return ret;
}

/**
 * @brief Compositional Inverse
 */