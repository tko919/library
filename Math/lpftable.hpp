#pragma once
#include "Math/sieve.hpp"

vector<int> lpftable(ll n) {
    auto ps = sieve(n);
    vector<int> ret(n + 1, -1);
    reverse(ALL(ps));
    for (auto &p : ps) {
        for (ll q = p; q <= n; q += p)
            ret[q] = p;
    }
    return ret;
}

/**
 * @brief lpf table
 */