#pragma once
#include "Math/sieve.hpp"

template <typename T, T (*pe)(int, int), T (*psum)(ll)>
struct MultiplicativeSum {
    ll N, SQ, sz;
    vector<ll> quo;
    vector<T> dat, add, rui;
    MultiplicativeSum(ll n = 0)
        : N(n), SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(sz), dat(sz), add(sz),
          rui(sz) {
        iota(ALL(quo), 1);
        for (ll i = SQ, x = N / (SQ + 1); x; x--, i++)
            quo[i] = n / x;
        rep(i, 0, sz) rui[i] = dat[i] = psum(quo[i]);

        auto ps = sieve(SQ);
        reverse(ALL(ps));
        for (auto &p : ps) {
            T pc = pe(p, 1);
            for (ll pw = p, c = 1; N / p >= pw; pw *= p, c++) {
                T nxt = pe(p, c + 1);
                rrep(j, 0, sz) {
                    if (quo[j] < pw * p)
                        break;
                    add[j] += pc * (dat[idx(quo[j] / pw)] - rui[p - 1]) + nxt;
                }
                pc = nxt;
            }
            rrep(j, 0, sz) {
                if (quo[j] < ll(p) * p)
                    break;
                dat[j] += add[j];
                add[j] = 0;
            }
        }
        rep(i, 0, sz) dat[i] += 1;
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
 * @brief Multiplicative Sum
 * @docs docs/multiplicative.md
 */