#pragma once
#include "Math/fraction.hpp"

namespace SternBrocotTree {
static pair<vector<int>, pair<Frac<ll>, Frac<ll>>> getinfo(Frac<ll> &x);
// R start
static vector<int> encode(Frac<ll> x) {
    return getinfo(x).first;
}
static Frac<ll> decode(vector<int> &v) {
    Frac<ll> L(0, 1), R(1, 0);
    rep(i, 0, v.size()) {
        if (i & 1)
            R = Frac<ll>(L.a * v[i] + R.a, L.b * v[i] + R.b);
        else
            L = Frac<ll>(R.a * v[i] + L.a, R.b * v[i] + L.b);
    }
    return Frac<ll>(L.a + R.a, L.b + R.b);
}
static Frac<ll> lca(Frac<ll> x, Frac<ll> y) {
    auto px = encode(x), py = encode(y);
    vector<int> q;
    rep(i, 0, min(px.size(), py.size())) {
        q.push_back(min(px[i], py[i]));
        if (q.back() != px[i] or q.back() != py[i])
            break;
    }
    return decode(q);
}
static pair<Frac<ll>, Frac<ll>> subtree(Frac<ll> x) {
    return getinfo(x).second;
}
static pair<Frac<ll>, Frac<ll>> child(Frac<ll> x) {
    auto [L, R] = subtree(x);
    Frac<ll> lb(L.a + x.a, L.b + x.b), rb(R.a + x.a, R.b + x.b);
    return {lb, rb};
}
static Frac<ll> la(Frac<ll> x, ll k) {
    auto path = encode(x);
    for (;;) {
        if (path.empty())
            return Frac<ll>(-1, 1);
        if (k <= path.back()) {
            path.back() -= k;
            break;
        } else {
            k = path.back();
            path.pop_back();
        }
    }
    return decode(path);
}
static pair<vector<int>, pair<Frac<ll>, Frac<ll>>> getinfo(Frac<ll> &x) {
    Frac<ll> L(0, 1), R(1, 0), mid(1, 1);
    vector<int> path;
    for (;;) {
        if (mid == x)
            break;
        ll k = ceil<ll>(x.a * L.b - x.b * L.a, x.b * R.a - x.a * R.b) - 1;
        L = Frac<ll>(L.a + k * R.a, L.b + k * R.b);
        mid = Frac<ll>(L.a + R.a, L.b + R.b);
        path.push_back(k);
        if (mid == x)
            break;
        k = ceil<ll>(x.b * R.a - x.a * R.b, x.a * L.b - x.b * L.a) - 1;
        R = Frac<ll>(R.a + k * L.a, R.b + k * L.b);
        mid = Frac<ll>(L.a + R.a, L.b + R.b);
        path.push_back(k);
    }
    return {path, {L, R}};
}
}; // namespace SternBrocotTree

/**
 * @brief Stern-Brocot Tree
 */
