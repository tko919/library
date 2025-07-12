#pragma once
#include "Convolution/ntt.hpp"
#include "Math/modint.hpp"

using M1 = fp<167772161>;
using M2 = fp<469762049>;
using M3 = fp<1107296257>;
NTT<M1> N1;
NTT<M2> N2;
NTT<M3> N3;
constexpr int r_12 = M2(M1::get_mod()).inv();
constexpr int r_13 = M3(M1::get_mod()).inv();
constexpr int r_23 = M3(M2::get_mod()).inv();
constexpr int r_1323 = M3(ll(r_13) * r_23).v;
constexpr ll w1 = M1::get_mod();
constexpr ll w2 = ll(w1) * M2::get_mod();
template <typename T>
vector<T> ArbitraryMultint(const vector<int> &a, const vector<int> &b) {
    if (a.empty() or b.empty())
        return vector<T>();
    int n = a.size() + b.size() - 1;
    vector<T> res(n);
    if (min(a.size(), b.size()) <= 60) {
        rep(i, 0, a.size()) rep(j, 0, b.size()) res[i + j] += T(a[i]) * b[j];
        return res;
    }
    vector<ll> vals[3];
    vector<M1> a1(ALL(a)), b1(ALL(b)), c1 = N1.mult(a1, b1);
    vector<M2> a2(ALL(a)), b2(ALL(b)), c2 = N2.mult(a2, b2);
    vector<M3> a3(ALL(a)), b3(ALL(b)), c3 = N3.mult(a3, b3);
    for (M1 x : c1)
        vals[0].push_back(x.v);
    for (M2 x : c2)
        vals[1].push_back(x.v);
    for (M3 x : c3)
        vals[2].push_back(x.v);
    rep(i, 0, n) {
        ll p = vals[0][i];
        ll q = (vals[1][i] + M2::get_mod() - p) * r_12 % M2::get_mod();
        ll r = ((vals[2][i] + M3::get_mod() - p) * r_1323 +
                (M3::get_mod() - q) * r_23) %
               M3::get_mod();
        res[i] = (T(r) * w2 + q * w1 + p);
    }
    return res;
}

template <typename T>
vector<T> ArbitraryMult(const vector<T> &a, const vector<T> &b) {
    vector<int> A, B;
    for (auto &x : a)
        A.push_back(x.v);
    for (auto &x : b)
        B.push_back(x.v);
    return ArbitraryMultint<T>(A, B);
}

/**
 * @brief Arbitrary Mod Convolution
 */