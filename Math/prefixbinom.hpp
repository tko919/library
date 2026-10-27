#pragma once
#include "Algorithm/mo.hpp"

template <typename T>
vector<T> PrefixSumOfBinomial(const vector<pair<int, int>> &qs) {
    int N = 2;
    for (auto &p : qs)
        N = max(N, p.first);
    int Q = qs.size();
    Mo mo(N);
    for (auto &p : qs) {
        mo.add(p.second, p.first);
    }
    vector<T> ans(Q);
    T cur = 1;
    int n = 0, m = 0;
    auto al = [&](int) { cur -= nCr<T>(n, m--); };
    auto ar = [&](int) { cur += cur - nCr<T>(n++, m); };
    auto el = [&](int) { cur += nCr<T>(n, ++m); };
    auto er = [&](int) { cur = (cur + nCr<T>(--n, m)) * Inv<T>(2); };
    auto q = [&](int i) { ans[i] = cur; };
    mo.run(al, ar, el, er, q);
    return ans;
}

/**
 * @brief Prefix Sum of Binomial Coefficient
 */