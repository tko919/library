#pragma once
#include "Utility/random.hpp"

struct RollingHash {
    using ull = unsigned long long;
    const ull MOD = 0x1fffffffffffffff;
    const ull base;
    vector<ull> hashed, power;

    static constexpr ull mask(ll a) {
        return (1ULL << a) - 1;
    }

    inline ull mul(ull a, ull b) const {
        __uint128_t ans = __uint128_t(a) * b;
        ans = (ans >> 61) + (ans & MOD);
        if (ans >= MOD)
            ans -= MOD;
        return ans;
    }

    static inline ull genbase() {
        return Random::get(ull(0x1fffffffffffffff));
    }
    RollingHash() = default;

    template <typename STR> RollingHash(const STR &s, ull base) : base(base) {
        ll n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for (ll i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= MOD)
                hashed[i + 1] -= MOD;
        }
    }

    ull get(ll l, ll r) const {
        ull ret = hashed[r] + MOD - mul(hashed[l], power[r - l]);
        if (ret >= MOD)
            ret -= MOD;
        return ret;
    }

    ull connect(ull h1, ull h2, ll h2len) const {
        ull ret = mul(h1, power[h2len]) + h2;
        if (ret >= MOD)
            ret -= MOD;
        return ret;
    }

    template <typename STR> void connect(const STR &s) {
        ll n = hashed.size() - 1, m = s.size();
        hashed.resize(n + m + 1);
        power.resize(n + m + 1);
        for (ll i = n; i < n + m; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i - n];
            if (hashed[i + 1] >= MOD)
                hashed[i + 1] -= MOD;
        }
    }

    ll LCP(const RollingHash &b, ll l1, ll r1, ll l2, ll r2) {
        ll len = min(r1 - l1, r2 - l2);
        ll low = -1, high = len + 1;
        while (high - low > 1) {
            ll mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};

/**
 * @brief Rolling Hash
 */