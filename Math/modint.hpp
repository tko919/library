#pragma once

template <int mod = 1000000007> struct fp {
    int v;
    static constexpr int get_mod() { return mod; }
    constexpr int inv() noexcept {
        assert(v != 0);
        int x = v, y = mod, u = 1, v = 0, t = 0, tmp = 0;
        while (y > 0) {
            t = x / y;
            x -= t * y, u -= t * v;
            tmp = x, x = y, y = tmp;
            tmp = u, u = v, v = tmp;
        }
        return u;
    }
    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}
    fp operator-() const { return fp() - *this; }
    fp pow(ll t) {
        assert(t >= 0);
        fp res = 1, b = *this;
        while (t) {
            if (t & 1)
                res *= b;
            b *= b;
            t >>= 1;
        }
        return res;
    }
    fp &operator+=(const fp &x) {
        if ((v += x.v) >= mod)
            v -= mod;
        return *this;
    }
    fp &operator-=(const fp &x) {
        if ((v += mod - x.v) >= mod)
            v -= mod;
        return *this;
    }
    fp &operator*=(const fp &x) {
        v = ll(v) * x.v % mod;
        return *this;
    }
    fp &operator/=(const fp &x) {
        v = ll(v) * x.inv() % mod;
        return *this;
    }
    fp operator+(const fp &x) const { return fp(*this) += x; }
    fp operator-(const fp &x) const { return fp(*this) -= x; }
    fp operator*(const fp &x) const { return fp(*this) *= x; }
    fp operator/(const fp &x) const { return fp(*this) /= x; }
    bool operator==(const fp &x) const { return v == x.v; }
    bool operator!=(const fp &x) const { return v != x.v; }
    friend istream &operator>>(istream &is, fp &x) { return is >> x.v; }
    friend ostream &operator<<(ostream &os, const fp &x) { return os << x.v; }
};

template <typename T> T Inv(ll n) {
    static const int md = T::get_mod();
    static vector<T> buf({0, 1});
    assert(n > 0);
    n %= md;
    while (SZ(buf) <= n) {
        int k = SZ(buf), q = (md + k - 1) / k;
        buf.push_back(buf[k * q - md] * q);
    }
    return buf[n];
}

template <typename T> T Fact(ll n, bool inv = 0) {
    static const int md = T::get_mod();
    static vector<T> buf({1, 1}), ibuf({1, 1});
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
template <typename T> T nHr(int n, int r, bool inv = 0) {
    return nCr<T>(n + r - 1, r, inv);
}

/**
 * @brief Modint
 */