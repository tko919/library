#pragma once
#include "Math/matrix.hpp"

template <typename T> T Pfaffian(Matrix<T> &a) {
    int n = a.h;
    assert(n == a.w and n % 2 == 0);
    T ret = 1;
    for (int i = 1; i < n; i += 2) {
        rep(j, i, n) if (a[j][i - 1] != 0) {
            swap(a[j], a[i]);
            for (auto &v : a.val)
                swap(v[j], v[i]);
            if (i != j)
                ret = -ret;
            break;
        }
        if (a[i][i - 1] == 0)
            return 0;
        ret *= -a[i][i - 1];
        T inv = T(1) / a[i][i - 1];
        rep(j, i + 1, n) {
            T z = a[j][i - 1] * inv;
            rep(k, 0, n) a[j][k] -= z * a[i][k];
        }
        inv = T(1) / a[i - 1][i];
        rep(j, i + 1, n) {
            T z = a[i - 1][j] * inv;
            rep(k, 0, n) a[k][j] -= z * a[k][i];
        }
    }
    return ret;
}

/**
 * @brief Pfaffian
 */