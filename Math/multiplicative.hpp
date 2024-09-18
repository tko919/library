#pragma once
#include "Math/sieve.hpp"

template <typename T, T (*pe)(int, int), T (*psum)(ll)>
T MultiplicativeSum(ll N) {
    class Array {
        std::vector<T> data;
        std::vector<int> written;

      public:
        int n;
        Array(int n) : data(n), n(n) {}
        void add(int i, T val) {
            data[i] += val;
            written.push_back(i);
        }
        void lazy(vector<T> &base) {
            for (auto i : written) {
                base[i] += data[i];
                data[i] = 0;
            }
            written.clear();
        }
    };

    ll SQ = sqrtl(N);
    vector<T> lo(SQ + 1), hi(SQ + 1);
    rep(i, 1, SQ + 1) {
        lo[i] = psum(i);
        hi[i] = psum(N / i);
    }

    auto ps = sieve(SQ);
    reverse(ALL(ps));
    Array loa(SQ + 1), hia(SQ + 1);
    for (auto &p : ps) {
        if (ll(p) * p > N)
            break;
        ll c = 1, pc = p;
        while (N / p >= pc) {
            T x = pe(p, c), y = pe(p, c + 1), z = psum(p);
            rep(i, 1, SQ + 1) {
                ll k = double(N) / (i * pc);
                if (k < p)
                    break;
                if (k <= SQ)
                    hia.add(i, x * (lo[k] - z) + y);
                else
                    hia.add(i, x * (hi[i * pc] - z) + y);
            }
            rrep(i, 1, SQ + 1) {
                int k = double(i) / pc;
                if (k < p)
                    break;
                loa.add(i, x * (lo[k] - z) + y);
            }
            c++;
            pc *= p;
        }
        loa.lazy(lo);
        hia.lazy(hi);
    }
    return hi[1] + 1;
}

/**
 * @brief Multiplicative Sum
 * @docs docs/multiplicative.md
 */