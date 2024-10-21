#pragma once

template <typename T> T Inv(ll n) {
    static int md;
    static vector<T> buf({0, 1});
    if (md != T::get_mod()) {
        md = T::get_mod();
        buf = vector<T>({0, 1});
    }
    assert(n > 0);
    n %= md;
    while (SZ(buf) <= n) {
        int k = SZ(buf), q = (md + k - 1) / k;
        buf.push_back(buf[k * q - md] * q);
    }
    return buf[n];
}

template <typename T> T Fact(ll n, bool inv = 0) {
    static int md;
    static vector<T> buf({1, 1}), ibuf({1, 1});
    if (md != T::get_mod()) {
        md = T::get_mod();
        buf = ibuf = vector<T>({1, 1});
    }
    assert(n >= 0 and n < md);
    while (SZ(buf) <= n) {
        buf.push_back(buf.back() * SZ(buf));
        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));
    }
    return inv ? ibuf[n] : buf[n];
}

template <typename T> T nPr(int n, int r, bool inv = 0) {
    if (n < 0 || n < r || r < 0)
        return 0;
    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);
}
template <typename T> T nCr(int n, int r, bool inv = 0) {
    if (n < 0 || n < r || r < 0)
        return 0;
    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n - r, inv ^ 1);
}
// sum = n, r tuples
template <typename T> T nHr(int n, int r, bool inv = 0) {
    return nCr<T>(n + r - 1, r - 1, inv);
}
// sum = n, a nonzero tuples and b tuples
template <typename T> T choose(int n, int a, int b) {
    if (n == 0)
        return !a;
    return nCr<T>(n + b - 1, a + b - 1);
}

/**
 * @brief Combination
 */