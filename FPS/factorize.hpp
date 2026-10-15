#pragma once
#include "FPS/halfgcd.hpp"

namespace FactorizePoly {
template <typename T> Poly<T> powmod(Poly<T> &f, ll n, Poly<T> &g) {
    Poly<T> ret({1}), base = f;
    while (n) {
        if (n & 1) {
            ret *= base;
            ret %= g;
        }
        base *= base;
        base %= g;
        n >>= 1;
    }
    return ret;
}
template <typename T> vector<Poly<T>> EDF(Poly<T> &f, int d) {
    int p = T::get_mod(), half = (p - 1) / 2;
    if (f.deg() < d)
        return {};
    if (f.deg() == d)
        return {f};
    Poly<T> base(SZ(f));
    rep(i, 0, SZ(f)) base[i] = Random::get(T::get_mod() - 1);
    auto g = HalfGCD::gcd(base, f);
    if (g.deg() != 0) {
        auto ret = EDF(g, d);
        auto fg = f / g;
        auto add = EDF(fg, d);
        ret.insert(ret.end(), ALL(add));
        return ret;
    } else {
        Poly<T> b = base, rem;
        if (p == 2) {
            rep(_, 0, d) {
                rem += b;
                rem %= f;
                b = powmod(b, p, f);
            }
        } else {
            rem = Poly<T>({1});
            rep(_, 0, d) {
                auto t = powmod(b, half, f);
                rem *= t;
                rem %= f;
                b = powmod(b, p, f);
            }
            rem[0] -= 1;
        }
        g = HalfGCD::gcd(rem, f);
        if (g.deg() != 0 and g != f) {
            auto ret = EDF(g, d);
            auto fg = f / g;
            auto add = EDF(fg, d);
            ret.insert(ret.end(), ALL(add));
            return ret;
        } else {
            return EDF(f, d);
        }
    }
}
template <typename T> vector<Poly<T>> CantorZassenhaus(Poly<T> &f) {
    auto cur = f;
    vector<Poly<T>> ret;
    ll p = T::get_mod(), d = 1;
    Poly<T> x({0, 1}), xp = x;
    for (;;) {
        if (cur.deg() < d * 2) {
            if (cur.deg())
                ret.push_back(cur);
            break;
        }
        xp = powmod(xp, p, cur);
        auto rem = xp - x;
        auto g = HalfGCD::gcd(rem, cur);
        auto add = EDF(g, d);
        ret.insert(ret.end(), ALL(add));
        cur /= g;
        d++;
    }
    return ret;
}
template <typename T>
vector<Poly<T>> SquarefreeDecomposition(const Poly<T> &f) {
    int p = T::get_mod();
    vector<Poly<T>> ret(SZ(f), Poly<T>({1}));
    auto c = HalfGCD::gcd(f, f.diff());
    auto w = f / c;
    int ptr = 0;
    while (w.deg() > 0) {
        auto y = HalfGCD::gcd(w, c);
        auto z = w / y;
        ret[ptr] *= z;
        w = y;
        c /= y;
        ptr++;
    }

    if (c.deg() > 0) {
        Poly<T> h(c.deg() / p + 1);
        rep(i, 0, SZ(c)) if (i % p == 0) {
            h[i / p] = c[i];
        }
        auto sub = SquarefreeDecomposition(h);
        rep(i, 0, SZ(sub)) ret[(i + 1) * p - 1] *= sub[i];
    }
    return ret;
}
template <typename T> vector<Poly<T>> run(Poly<T> &f) { // f: monic
    auto dec = SquarefreeDecomposition(f);
    vector<Poly<T>> ret;
    rep(i, 0, SZ(dec)) {
        auto add = CantorZassenhaus(dec[i]);
        rep(_, 0, i + 1) ret.insert(ret.end(), ALL(add));
    }
    return ret;
}
}; // namespace FactorizePoly

/**
 * @brief Factorize Polynomial
 */