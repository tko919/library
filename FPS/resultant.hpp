#pragma once

template <typename T> T Resultant(Poly<T> f, Poly<T> g) {
    if (g.empty()) {
        if (SZ(f) == 1)
            return 1;
        else
            return 0;
    }
    bool sign = 0;
    T ret = 1;
    for (;;) {
        auto [q, r] = f.divmod(g);
        if (r.empty()) {
            if (SZ(g) == 1)
                ret *= g[0].pow(f.deg());
            else
                ret = 0;
            break;
        } else {
            if (f.deg() & 1 and g.deg() & 1)
                sign ^= 1;
            ret *= g.back().pow(f.deg() - r.deg());
            swap(f, g);
            g = r;
        }
    }
    if (sign)
        ret = -ret;
    return ret;
}

/**
 * @brief Resultant
 */