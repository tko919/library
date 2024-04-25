#pragma once
#include "Utility/random.hpp"
#include "FPS/halfgcd.hpp"

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

namespace FactorizePoly {
template <typename T> Poly<T> powmod(Poly<T> &f, Bint &n, Poly<T> &g) {
    Poly<T> ret({1}), base = f;
    while (n != 0) {
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
        Bint pw = 1;
        rep(_, 0, d) pw *= T::get_mod();
        pw = (pw - 1) / 2;
        auto rem = powmod(base, pw, f);
        rem[0] -= 1;
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
    auto base = Poly<T>({0, 1});
    auto cur = f;
    vector<Poly<T>> ret;
    int d = 1;
    Bint k = 1, md = T::get_mod();
    for (;;) {
        if (cur.deg() < d * 2) {
            if (cur.deg())
                ret.push_back(cur);
            break;
        }
        k *= md;
        auto rem = powmod(base, k, cur);
        rem -= base;
        auto g = HalfGCD::gcd(rem, cur);
        auto add = EDF(g, d);
        ret.insert(ret.end(), ALL(add));
        cur /= g;
        d++;
    }
    return ret;
}
template <typename T> vector<Poly<T>> SquarefreeDecomposition(Poly<T> f) {
    if (f.deg() == 0)
        return {f};
    auto g = HalfGCD::gcd(f, f.diff());
    auto base = SquarefreeDecomposition(g);
    for (auto &b : base)
        g *= b;
    f /= g;
    base.insert(base.begin(), f);
    return base;
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