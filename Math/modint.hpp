#pragma once

template <unsigned mod = 1000000007> struct fp {
    unsigned v;
    static constexpr int get_mod() {
        return mod;
    }
    constexpr unsigned inv() const {
        assert(v != 0);
        int x = v, y = mod, p = 1, q = 0, t = 0, tmp = 0;
        while (y > 0) {
            t = x / y;
            x -= t * y, p -= t * q;
            tmp = x, x = y, y = tmp;
            tmp = p, p = q, q = tmp;
        }
        if (p < 0)
            p += mod;
        return p;
    }
    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}
    fp operator-() const {
        return fp() - *this;
    }
    fp pow(ull t) {
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
        v = ull(v) * x.v % mod;
        return *this;
    }
    fp &operator/=(const fp &x) {
        v = ull(v) * x.inv() % mod;
        return *this;
    }
    fp operator+(const fp &x) const {
        return fp(*this) += x;
    }
    fp operator-(const fp &x) const {
        return fp(*this) -= x;
    }
    fp operator*(const fp &x) const {
        return fp(*this) *= x;
    }
    fp operator/(const fp &x) const {
        return fp(*this) /= x;
    }
    bool operator==(const fp &x) const {
        return v == x.v;
    }
    bool operator!=(const fp &x) const {
        return v != x.v;
    }
    friend istream &operator>>(istream &is, fp &x) {
        return is >> x.v;
    }
    friend ostream &operator<<(ostream &os, const fp &x) {
        return os << x.v;
    }
};

template <unsigned mod> void rd(fp<mod> &x) {
    fastio::rd(x.v);
}
template <unsigned mod> void wt(fp<mod> x) {
    fastio::wt(x.v);
}

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
// sum = n, r tuples
template <typename T> T nHr(int n, int r, bool inv = 0) {
    return nCr<T>(n + r - 1, r, inv);
}
// sum = n, a nonzero tuples and b tuples
template <typename T> T choose(int n, int a, int b) {
    if (n == 0)
        return !a;
    return nCr<T>(n + b - 1, a + b - 1);
}

/**
 * @brief Modint
 */