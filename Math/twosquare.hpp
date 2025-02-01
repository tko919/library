#pragma once
#include "Math/primitive.hpp"
#include "Math/gaussian.hpp"
#include "Math/pollard.hpp"

vector<pair<ll, ll>> RepresentTwoSquare(ll n) {
    auto find = [&](ll p) -> Gauss<ll> {
        assert(p % 4 == 1);
        ll g = 1, x = -1;
        for (;;) {
            g++;
            x = mpow(g, (p - 1) / 4, p);
            if ((__int128_t(x) * x) % p == p - 1)
                break;
        }
        Gauss<ll> a(p, 0), b(x, 1);
        a = gcd(a, b);
        assert(a.norm() == p);
        return a;
    };
    auto subtask = [&](ll p, int e) -> vector<Gauss<ll>> {
        if (p == 2) {
            Gauss<ll> ret(1, 0), b(1, 1);
            rep(_, 0, e) ret *= b;
            return {ret};
        } else if (p % 4 == 1) {
            auto base = find(p);
            vector<Gauss<ll>> pws(e + 1), ret(e + 1);
            pws[0] = Gauss<ll>(1, 0);
            rep(i, 0, e) pws[i + 1] = pws[i] * base;
            rep(i, 0, e + 1) ret[i] = pws[i] * pws[e - i].conj();
            return ret;
        } else {
            if (e & 1)
                return {};
            ll q = 1;
            rep(_, 0, e / 2) q *= p;
            return {Gauss<ll>(q, 0)};
        }
    };

    if (n == 0) {
        return {{0, 0}};
    }
    auto ps = Pollard(n);
    map<ll, int> pe;
    for (auto &p : ps)
        pe[p]++;
    vector<Gauss<ll>> ret;
    ret.push_back(Gauss<ll>(1, 0));
    for (auto &[p, e] : pe) {
        auto add = subtask(p, e);
        vector<Gauss<ll>> nxt;
        for (auto &x : ret) {
            for (auto &y : add) {
                nxt.push_back(x * y);
            }
        }
        swap(ret, nxt);
    }
    vector<pair<ll, ll>> out;
    for (auto x : ret) {
        rep(_, 0, 4) {
            swap(x.x, x.y);
            x.x *= -1;
            if (x.x >= 0 and x.y >= 0) {
                out.push_back({x.x, x.y});
            }
        }
    }
    return out;
}

/**
 * @brief Represent A Number As Two Square Sum
 */