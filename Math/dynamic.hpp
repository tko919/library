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
    return nCr<T>(n + r - 1, r, inv);
}
// sum = n, a nonzero tuples and b tuples
template <typename T> T choose(int n, int a, int b) {
    if (n == 0)
        return !a;
    return nCr<T>(n + b - 1, a + b - 1);
}

/**
 * @brief Dynamic Modint
 */