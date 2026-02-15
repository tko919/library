#pragma once
#include "Convolution/ntt.hpp"
#include "Math/modint.hpp"

using M1 = fp<469762049>;  // 2^26
using M2 = fp<1811939329>; // 2^26
using M3 = fp<2013265921>; // 2^27
NTT<M1> N1;
NTT<M2> N2;
NTT<M3> N3;
constexpr uint r_12 = M2(M1::get_mod()).inv();
constexpr uint r_13 = M3(M1::get_mod()).inv();
constexpr uint r_23 = M3(M2::get_mod()).inv();
constexpr uint r_1323 = M3(ll(r_13) * r_23).v;
constexpr ll w1 = M1::get_mod();
constexpr ll w2 = ll(w1) * M2::get_mod();
template <typename T> vector<T> ArbitraryMultll(vector<ll> a, vector<ll> b) {
    if (a.empty() or b.empty())
        return vector<T>();
    int n = a.size() + b.size() - 1;
    vector<T> res(n);
    if (min(a.size(), b.size()) <= 60) {
        rep(i, 0, a.size()) rep(j, 0, b.size()) res[i + j] += T(a[i]) * b[j];
        return res;
    }
    ll ami = MIN(a), bmi = MIN(b);
    for (auto &x : a)
        x -= ami;
    for (auto &x : b)
        x -= bmi;
    vector<ll> ruia(SZ(a) + 1), ruib(SZ(b) + 1);
    rep(i, 0, SZ(a)) ruia[i + 1] = ruia[i] + a[i];
    rep(i, 0, SZ(b)) ruib[i + 1] = ruib[i] + b[i];
    rep(k, 0, SZ(res)) {
        ll l = max(0, k - SZ(b) + 1), r = min(SZ(a), k + 1);
        res[k] += ll(r - l) * ami * bmi;
        res[k] += ami * (ruib[k - l + 1] - ruib[k - r + 1]);
        res[k] += bmi * (ruia[r] - ruia[l]);
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
        res[i] += (T(r) * w2 + T(q) * w1 + p);
    }
    return res;
}

template <typename T>
vector<T> ArbitraryMult(const vector<T> &a, const vector<T> &b) {
    vector<ll> A, B;
    for (auto &x : a)
        A.push_back(x.v);
    for (auto &x : b)
        B.push_back(x.v);
    return ArbitraryMultll<T>(A, B);
}

/**
 * @brief Arbitrary Mod Convolution
 */