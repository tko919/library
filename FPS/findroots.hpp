#pragma once
#include "Utility/random.hpp"
#include "FPS/halfgcd.hpp"
#include "FPS/prodofpolys.hpp"

namespace FindRoots {
template <typename T> Poly<T> powmod(Poly<T> &f, ll n, Poly<T> &g) {
    Poly<T> ret({1}), base = f;
    while (n != 0) {
        if (n & 1) {
            ret *= base;
            ret %= g;
        }
        base *= base;
        base %= g;
        n /= 2;
    }
    return ret;
}
template <typename T> vector<Poly<T>> EDF(Poly<T> &f) {
    if (f.deg() < 1)
        return {};
    if (f.deg() == 1)
        return {f};
    Poly<T> base(2);
    base[0] = Random::get(T::get_mod() - 1);
    base[1] = 1;
    ll pw = (T::get_mod() - 1) / 2;
    auto rem = powmod(base, pw, f);
    if (rem.empty())
        return EDF(f);
    rem -= Poly<T>({1});
    auto h = HalfGCD::gcd(rem, f);
    auto ret = EDF(h);
    auto fh = f / h;
    auto add = EDF(fh);
    ret.insert(ret.end(), ALL(add));
    return ret;
}
template <typename T> vector<Poly<T>> SquarefreeDecomposition(Poly<T> f) {
    if (f.deg() == 0)
        return {f};
    auto g = HalfGCD::gcd(f, f.diff());
    auto base = SquarefreeDecomposition(g);
    g *= ProdOfPolys(base);
    f /= g;
    base.insert(base.begin(), f);
    return base;
}
template <typename T> Poly<T> select(Poly<T> &f) {
    Poly<T> X({0, 1});
    auto xpmf = powmod(X, T::get_mod(), f);
    xpmf -= X;
    return HalfGCD::gcd(xpmf, f);
}
template <typename T> vector<T> run(Poly<T> &f) {
    auto dec = SquarefreeDecomposition(f);
    vector<T> ret;
    rep(i, 0, SZ(dec)) {
        auto g = select(dec[i]);
        auto add = EDF(g);
        for (auto &h : add) {
            assert(h.deg() == 1);
            rep(_, 0, i + 1) ret.push_back(-h[0]);
        }
    }
    return ret;
}
}; // namespace FindRoots

/**
 * @brief Find roots
 */