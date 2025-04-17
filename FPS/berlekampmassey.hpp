#pragma once

template <typename T> vector<T> BerlekampMassey(vector<T> &a) {
    int n = a.size();
    T d = 1;
    vector<T> b(1), c(1);
    b[0] = c[0] = 1;
    rep(j, 1, n + 1) {
        int l = c.size(), m = b.size();
        T x = 0;
        rep(i, 0, l) x += c[i] * a[j - l + i];
        b.push_back(0);
        m++;
        if (x == 0)
            continue;
        T coeff = -x / d;
        if (l < m) {
            auto tmp = c;
            c.insert(c.begin(), m - l, 0);
            rep(i, 0, m) c[m - 1 - i] += coeff * b[m - 1 - i];
            b = tmp;
            d = x;
        } else
            rep(i, 0, m) c[l - 1 - i] += coeff * b[m - 1 - i];
    }
    reverse(ALL(c));
    return c;
}

/**
 * @brief Berlekamp Massey Algorithm
 */