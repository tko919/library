#pragma once
#include "Math/primitive.hpp"
#include "Math/lpftable.hpp"

struct ModFast {
    const int p;
    array<pair<int, int>, (1 << 20) + 1> frac;
    static constexpr int K = 1 << 21;
    array<int, K * 2 + 1> LOG, INV;
    array<ll, (1 << 15) + 1> phi, plo;

    ModFast(int p_, int rt = -1) : p(p_) {
        if (rt == -1) {
            if (p == 998244353)
                rt = 3;
            else if (p == 1000000007)
                rt = 5;
            else
                rt = getPrimitiveRoot(p);
        }
        // build POW,INV
        {
            plo[0] = phi[0] = 1;
            rep(i, 0, 1 << 15) plo[i + 1] = (plo[i] * rt) % p;
            rep(i, 0, 1 << 15) phi[i + 1] = (phi[i] * plo[1 << 15]) % p;
            INV[K + 1] = 1;
            rep(i, 2, K + 1) {
                ll q = (p + i - 1) / i;
                INV[K + i] = ll(INV[K + i * q - p]) * q % p;
            }
            rep(i, 1, K + 1) INV[K - i] = p - INV[K + i];
        }
        // build LOG
        {
            const int S = 1 << 17;
            unordered_map<int, int> mp;
            ll pw = 1;
            rep(k, 0, S) {
                mp[pw] = k;
                pw = (pw * rt) % p;
            }
            auto lpf = lpftable(K);
            rep(i, 2, K + 1) {
                if (lpf[i] < i) {
                    int q = lpf[i];
                    LOG[K + i] = (LOG[K + q] + LOG[K + i / q]) % (p - 1);
                    continue;
                }
                if (ll(i) * i > p) {
                    int q = p / i, r = p - i * q;
                    LOG[K + i] =
                        (ll(LOG[K + r] + (p - 1) / 2) + (p - 1 - LOG[K + q])) %
                        (p - 1);
                    continue;
                }
                if (1) {
                    ll tar = i, add = 0;
                    for (;;) {
                        if (mp.count(tar)) {
                            LOG[K + i] = (add + mp[tar]) % (p - 1);
                            break;
                        }
                        add += p - 1 - S, tar = (tar * pw) % p;
                    }
                    continue;
                }
                for (;;) {
                    int k = Random::get(0, p - 1);
                    ll ret = p - 1 - k, x = (ll(i) * pow_r(k)) % p;
                    for (int q : {2, 3, 5, 7, 11, 13, 17, 19}) {
                        while (x % q == 0) {
                            x /= q;
                            ret += LOG[K + q];
                        }
                    }
                    if (x >= K)
                        continue;
                    while (i < x && x < K && lpf[x] < i) {
                        int q = lpf[x];
                        ret += LOG[K + q];
                        x /= q;
                    }
                    if (1 < x && x < i)
                        ret += LOG[K + x];
                    if (x == 1) {
                        LOG[K + i] = ret % (p - 1);
                        break;
                    }
                }
            }
            rep(i, 1, K + 1) LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1);
        }
        // build frac
        {
            stack<tuple<int, int, int, int>> st;
            st.push({0, 1, 1, 1});
            while (!st.empty()) {
                auto [a, b, c, d] = st.top();
                st.pop();
                if (b + d < 2048) {
                    st.emplace(a, b, a + c, b + d);
                    st.emplace(a + c, b + d, c, d);
                    continue;
                }
                int L = (ll(a) * p) / b / 1024, R = (ll(c) * p) / d / 1024;
                frac[L] = {a, b}, frac[R] = {c, d};
                rep(i, L + 1, R) frac[i] = {min(a, c), min(b, d)};
            }
        }
    }
    pair<int, int> get(int x) {
        auto [a, b] = frac[x >> 10];
        int t = x * b - a * p;
        return {t % p, b % p};
    }
    int inv(int x) {
        auto [t, b] = get(x);
        return ll(INV[K + t]) * b % p;
    }
    int pow(int x, ll t) {
        return pow_r(t * log(x) % (p - 1));
    }
    int pow_r(ll t) {
        return phi[t >> 15] * plo[t & 32767] % p;
    }
    int log(int x) {
        auto [t, b] = get(x);
        return ((LOG[K + t]) + (p - 1) - LOG[K + b]) % (p - 1);
    }
};

/**
 * @brief Mod Fast
 */