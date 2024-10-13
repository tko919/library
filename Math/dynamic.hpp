#pragma once
#include "Math/fastdiv.hpp"

struct Fp {
    using u64 = uint64_t;
    uint v;
    static int get_mod() {
        return _getmod();
    }
    static void set_mod(int _m) {
        bar = FastDiv(_m);
    }
    Fp inv() const {
        int tmp, a = v, b = get_mod(), x = 1, y = 0;
        while (b) {
            tmp = a / b, a -= tmp * b;
            swap(a, b);
            x -= tmp * y;
            swap(x, y);
        }
        if (x < 0) {
            x += get_mod();
        }
        return x;
    }
    Fp() : v(0) {}
    Fp(ll x) {
        v = x % get_mod();
        if (v < 0)
            v += get_mod();
    }
    Fp operator-() const {
        return Fp() - *this;
    }
    Fp pow(ll t) {
        assert(t >= 0);
        Fp res = 1, b = *this;
        while (t) {
            if (t & 1)
                res *= b;
            b *= b;
            t >>= 1;
        }
        return res;
    }
    Fp &operator+=(const Fp &x) {
        v += x.v;
        if (v >= get_mod())
            v -= get_mod();
        return *this;
    }
    Fp &operator-=(const Fp &x) {
        v += get_mod() - x.v;
        if (v >= get_mod())
            v -= get_mod();
        return *this;
    }
    Fp &operator*=(const Fp &x) {
        v = (u64(v) * x.v) % bar;
        return *this;
    }
    Fp &operator/=(const Fp &x) {
        (*this) *= x.inv();
        return *this;
    }
    Fp operator+(const Fp &x) const {
        return Fp(*this) += x;
    }
    Fp operator-(const Fp &x) const {
        return Fp(*this) -= x;
    }
    Fp operator*(const Fp &x) const {
        return Fp(*this) *= x;
    }
    Fp operator/(const Fp &x) const {
        return Fp(*this) /= x;
    }
    bool operator==(const Fp &x) const {
        return v == x.v;
    }
    bool operator!=(const Fp &x) const {
        return v != x.v;
    }
    friend istream &operator>>(istream &is, Fp &x) {
        return is >> x.v;
    }
    friend ostream &operator<<(ostream &os, const Fp &x) {
        return os << x.v;
    }

  private:
    static FastDiv bar;
    static int _getmod() {
        return bar.get();
    }
};
FastDiv Fp::bar(998244353);

void rd(Fp &x) {
    fastio::rd(x.v);
}
void wt(Fp x) {
    fastio::wt(x.v);
}

/**
 * @brief Dynamic Modint
 */