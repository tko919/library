#pragma once
#include "Math/sieve.hpp"

template <typename T, T (*F)(ll)> struct LucyDP {
    ll N, SQ, sz;
    vector<ll> quo;
    vector<T> dat;
    static inline pair<vector<ll>, vector<int>> gen(ll n) {
        ll sq = sqrtl(n);
        vector<ll> quo(sq + n / (sq + 1));
        iota(ALL(quo), 1);
        for (ll i = sq, x = n / (sq + 1); x; x--, i++)
            quo[i] = n / x;
        auto ps = sieve(sq);
        return {quo, ps};
    }
    LucyDP() {}
    LucyDP(ll n, vector<ll> &_quo, vector<int> &ps)
        : N(n), SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(_quo), dat(sz) {
        rep(i, 0, sz) dat[i] = F(quo[i]) - 1;
        for (auto &p : ps) {
            T coe = dat[p - 1] - dat[p - 2];
            for (int i = sz - 1;; i--) {
                if (quo[i] < ll(p) * p)
                    break;
                dat[i] -= (dat[idx(quo[i] / p)] - dat[p - 2]) * coe;
            }
        }
    }
    T operator[](ll x) {
        return dat[idx(x)];
    }

  private:
    int idx(ll x) const {
        if (x <= SQ)
            return x - 1;
        else
            return sz - N / x;
    }
};

/**
 * @brief Prime Sum
 * @docs docs/primesum.md
 */