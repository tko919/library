#pragma once
#include "Math/miller.hpp"
#include "Utility/random.hpp"

vector<ll> Pollard(ll n) {
    if (n <= 1)
        return {};
    if (Miller(n))
        return {n};
    if ((n & 1) == 0) {
        vector<ll> v = Pollard(n >> 1);
        v.push_back(2);
        return v;
    }
    for (ll x = 2, y = 2, d;;) {
        ll c = Random::get(2LL, n - 1);
        do {
            x = (__int128_t(x) * x + c) % n;
            y = (__int128_t(y) * y + c) % n;
            y = (__int128_t(y) * y + c) % n;
            d = __gcd(x - y + n, n);
        } while (d == 1);
        if (d < n) {
            vector<ll> lb = Pollard(d), rb = Pollard(n / d);
            lb.insert(lb.end(), ALL(rb));
            return lb;
        }
    }
}

vector<pair<ll, int>> Pollard2(ll n) {
    auto ps = Pollard(n);
    sort(ALL(ps));
    using P = pair<ll, int>;
    vector<P> pes;
    for (auto &p : ps) {
        if (pes.empty() or pes.back().first != p) {
            pes.push_back({p, 1});
        } else {
            pes.back().second++;
        }
    }
    return pes;
}

vector<ll> EnumDivisors(ll n) {
    auto pes = Pollard2(n);
    vector<ll> ret;
    auto rec = [&](auto &rec, int id, ll d) -> void {
        if (id == SZ(pes)) {
            ret.push_back(d);
            return;
        }
        rec(rec, id + 1, d);
        rep(e, 0, pes[id].second) {
            d *= pes[id].first;
            rec(rec, id + 1, d);
        }
    };
    rec(rec, 0, 1);
    sort(ALL(ret));
    return ret;
}

/**
 * @brief Pollard-Rho
 */