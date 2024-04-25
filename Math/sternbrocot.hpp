#pragma once
#include "Math/fraction.hpp"

namespace SternBrocotTree {
// R start
static vector<int> encode(Frac x) {
    return get(x).first;
}
static Frac decode(vector<int> &v) {
    Frac L(0, 1), R(1, 0);
    rep(i, 0, v.size()) {
        if (i & 1)
            R = Frac(L.a * v[i] + R.a, L.b * v[i] + R.b);
        else
            L = Frac(R.a * v[i] + L.a, R.b * v[i] + L.b);
    }
    return Frac(L.a + R.a, L.b + R.b);
}
static Frac lca(Frac x, Frac y) {
    auto px = encode(x), py = encode(y);
    vector<int> q;
    rep(i, 0, min(px.size(), py.size())) {
        q.push_back(min(px[i], py[i]));
        if (q.back() != px[i] or q.back() != py[i])
            break;
    }
    return decode(q);
}
static pair<Frac, Frac> child(Frac x) {
    auto [L, R] = subtree(x);
    Frac lb(L.a + x.a, L.b + x.b), rb(R.a + x.a, R.b + x.b);
    return {lb, rb};
}
static Frac la(Frac x, ll k) {
    auto path = encode(x);
    for (;;) {
        if (path.empty())
            return Frac(-1, 1);
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
static pair<Frac, Frac> subtree(Frac x) {
    return get(x).second;
}

private:
static ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}
static pair<vector<int>, pair<Frac, Frac>> get(Frac &x) {
    Frac L(0, 1), R(1, 0), mid(1, 1);
    vector<int> path;
    for (;;) {
        if (mid == x)
            break;
        ll k = ceil(x.a * L.b - x.b * L.a, x.b * R.a - x.a * R.b) - 1;
        L = Frac(L.a + k * R.a, L.b + k * R.b);
        mid = Frac(L.a + R.a, L.b + R.b);
        path.push_back(k);
        if (mid == x)
            break;
        k = ceil(x.b * R.a - x.a * R.b, x.a * L.b - x.b * L.a) - 1;
        R = Frac(R.a + k * L.a, R.b + k * L.b);
        mid = Frac(L.a + R.a, L.b + R.b);
        path.push_back(k);
    }
    return {path, {L, R}};
}
}; // namespace SternBrocotTree

/**
 * @brief Stern-Brocot Tree
 */
