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

/**
 * @brief Modint
 */