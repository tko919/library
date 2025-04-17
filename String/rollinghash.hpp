#pragma once
#include "Utility/random.hpp"
#include "Math/hash.hpp"

struct RollingHash {
    using ull = unsigned long long;
    const Hash base;
    vector<Hash> hashed, power;

    static inline ull genbase() {
        return Random::get(ull(0x1fffffffffffffff));
    }
    RollingHash(Hash base) : base(base) {}

    template <typename STR> void build(const STR &s) {
        int n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for (ll i = 0; i < n; i++) {
            power[i + 1] = power[i] * base;
            hashed[i + 1] = hashed[i] * base + s[i];
        }
    }

    Hash get(ll l, ll r) const {
        return hashed[r] - hashed[l] * power[r - l];
    }

    Hash connect(Hash h1, Hash h2, ll h2len) const {
        return h1 * power[h2len] + h2;
    }

    template <typename STR> void connect(const STR &s) {
        ll n = hashed.size() - 1, m = s.size();
        hashed.resize(n + m + 1);
        power.resize(n + m + 1);
        for (ll i = n; i < n + m; i++) {
            power[i + 1] = power[i] * base;
            hashed[i + 1] = hashed[i] * base + s[i - n];
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