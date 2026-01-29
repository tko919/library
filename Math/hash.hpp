#pragma once

struct Hash {
    static constexpr ull mod = 0x1fffffffffffffff;
    ull v;
    static constexpr ull get_mod() {
        return mod;
    }
    Hash inv() const {
        return pow(mod - 2);
    }
    constexpr Hash(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}
    Hash operator-() const {
        return Hash() - *this;
    }
    Hash pow(ull t) const {
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
        u128 ans = u128(v) * x.inv().v;
        ans = (ans >> 61) + (ans & mod);
        if (ans >= mod)
            ans -= mod;
        v = ans;
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

/**
 * @brief Hash
 */