#pragma once

struct Hash {
    static constexpr ull mod = 0x1fffffffffffffff;
    ull v;
    static constexpr ull get_mod() {
        return mod;
    }
    constexpr ull inv() const {
        assert(v != 0);
        ull x = v, y = mod, p = 1, q = 0, t = 0, tmp = 0;
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
    constexpr Hash(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}
    Hash operator-() const {
        return Hash() - *this;
    }
    Hash pow(ull t) {
        Hash res = 1, b = *this;
        while (t) {
            if (t & 1)
                res *= b;
            b *= b;
            t >>= 1;
        }
        return res;
    }
    Hash &operator+=(const Hash &x) {
        if ((v += x.v) >= mod)
            v -= mod;
        return *this;
    }
    Hash &operator-=(const Hash &x) {
        if ((v += mod - x.v) >= mod)
            v -= mod;
        return *this;
    }
    Hash &operator*=(const Hash &x) {
        u128 ans = u128(v) * x.v;
        ans = (ans >> 61) + (ans & mod);
        if (ans >= mod)
            ans -= mod;
        v = ans;
        return *this;
    }
    Hash &operator/=(const Hash &x) {
        v = ull(v) * x.inv() % mod;
        return *this;
    }
    Hash operator+(const Hash &x) const {
        return Hash(*this) += x;
    }
    Hash operator-(const Hash &x) const {
        return Hash(*this) -= x;
    }
    Hash operator*(const Hash &x) const {
        return Hash(*this) *= x;
    }
    Hash operator/(const Hash &x) const {
        return Hash(*this) /= x;
    }
    bool operator==(const Hash &x) const {
        return v == x.v;
    }
    bool operator!=(const Hash &x) const {
        return v != x.v;
    }
    // mapに載せる時用
    bool operator<(const Hash &x) const {
        return v < x.v;
    }
    bool operator<=(const Hash &x) const {
        return v <= x.v;
    }
    bool operator>(const Hash &x) const {
        return v > x.v;
    }
    bool operator>=(const Hash &x) const {
        return v >= x.v;
    }
    friend istream &operator>>(istream &is, Hash &x) {
        return is >> x.v;
    }
    friend ostream &operator<<(ostream &os, const Hash &x) {
        return os << x.v;
    }
};

void rd(Hash &x) {
    fastio::rd(x.v);
}

/**
 * @brief Hash
 */