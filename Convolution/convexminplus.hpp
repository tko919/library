#pragma once
#include "Algorithm/monotoneminima.hpp"

template <typename T>
vector<T> ConvexMinPlusConvolution(vector<T> &a, vector<T> &b) {
    int n = a.size(), m = b.size();
    auto cmp = [&](int i, int j, int k) -> bool {
        if (i < k)
            return false;
        if (i - j >= m)
            return true;
        return a[j] + b[i - j] >= a[k] + b[i - k];
    };
    auto arg = MonotoneMinima(n + m - 1, n, cmp);
    vector<ll> ret(n + m - 1);
    rep(i, 0, n + m - 1) ret[i] = a[arg[i]] + b[i - arg[i]];
    return ret;
}

template <typename T>
vector<T> Convex2MinPlusConvolution(vector<T> &a, vector<T> &b) {
    int n = SZ(a), m = SZ(b);
    // rep(i, 2, n) assert(a[i - 1] - a[i - 2] <= a[i] - a[i - 1]);
    // rep(i, 2, m) assert(b[i - 1] - b[i - 2] <= b[i] - b[i - 1]);

    vector<T> c(n + m - 1);
    c[0] = a[0] + b[0];
    for (int k = 0, i = 0; k < n + m - 2; k++) {
        int j = k - i;
        if (j == m - 1 or (i < n - 1 and a[i + 1] + b[j] < a[i] + b[j + 1])) {
            c[k + 1] = a[++i] + b[j];
        } else {
            c[k + 1] = a[i] + b[++j];
        }
    }
    return c;
}

/**
 * @brief Convex Min Plus Convolution
 * @docs docs/convexminplus.md
 */