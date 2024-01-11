#pragma once
#include "Convolution/arbitrary.hpp"

template <int D> struct bigint {
    using u128 = __uint128_t;
    static const int B = pow(10, D);
    int sign = 0;
    vector<int> v;
    static int get_D() { return D; }
    static int get_B() { return B; }
    bigint() {}
    bigint(const vector<int> &_v, bool _s = false) : sign(_s), v(_v) {}
    bigint(ll x) {
        if (x < 0)
            x *= -1, sign = 1;
        while (x) {
            v.push_back(x % B);
            x /= B;
        }
    }
    bigint(string s) {
        if (s[0] == '-')
            s.erase(s.begin()), sign = 1;
        int add = 0, cnt = 0, base = 1;
        while (s.size()) {
            if (cnt == D) {
                v.push_back(add);
                cnt = 0;
                add = 0;
                base = 1;
            }
            add = (s.back() - '0') * base + add;
            cnt++;
            base *= 10;
            s.pop_back();
        }
        if (add)
            v.push_back(add);
    }
    bigint operator-() const {
        bigint res = *this;
        res.sign ^= 1;
        return res;
    }
    bigint abs() const {
        bigint res = *this;
        res.sign = 0;
        return res;
    }
    int &operator[](const int i) { return v[i]; }
    int size() const { return v.size(); }
    void norm() {
        rep(i, 0, v.size() - 1) {
            if (v[i] >= 0) {
                v[i + 1] += v[i] / B;
                v[i] %= B;
            } else {
                int c = (-v[i] + B - 1) / B;
                v[i] += c * B;
                v[i + 1] -= c;
            }
        }
        while (!v.empty() and v.back() >= B) {
            int c = v.back() / B;
            v.back() %= B;
            v.push_back(c);
        }
        while (!v.empty() and v.back() == 0)
            v.pop_back();
    }
    string to_str() const {
        string res;
        if (v.empty())
            return "0";
        if (sign)
            res += '-';
        res += to_string(v.back());
        for (int i = v.size() - 2; i >= 0; i--) {
            string add;
            int w = v[i];
            rep(_, 0, D) {
                add += ('0' + (w % 10));
                w /= 10;
            }
            reverse(ALL(add));
            res += add;
        }
        return res;
    }
    friend istream &operator>>(istream &is, bigint<D> &x) {
        string tmp;
        is >> tmp;
        x = bigint(tmp);
        return is;
    }
    friend ostream &operator<<(ostream &os, bigint<D> x) {
        os << x.to_str();
        return os;
    }
    bigint &operator<<=(const int &x) {
        if (!v.empty()) {
            vector<int> add(x, 0);
            v.insert(v.begin(), ALL(add));
        }
        return *this;
    }
    bigint &operator>>=(const int &x) {
        v = vector<int>(v.begin() + min(x, (int)v.size()), v.end());
        return *this;
    }
    bigint &operator+=(const bigint &x) {
        if (sign != x.sign) {
            *this -= (-x);
            return *this;
        }
        if ((int)v.size() < (int)x.size())
            v.resize(x.size(), 0);
        rep(i, 0, x.size()) { v[i] += x.v[i]; }
        norm();
        return *this;
    }
    bigint &operator-=(const bigint &x) {
        if (sign != x.sign) {
            *this += (-x);
            return *this;
        }
        if (abs() < x.abs()) {
            *this = x - (*this);
            sign ^= 1;
            return *this;
        }
        rep(i, 0, x.size()) { v[i] -= x.v[i]; }
        norm();
        return *this;
    }
    bigint &operator*=(const bigint &x) {
        sign ^= x.sign;
        auto v1 = ArbitraryMult<u128>(v, x.v);
        u128 add = 0;
        v.clear();
        v.reserve(v1.size() + 3);
        for (int i = 0;; i++) {
            if (i >= int(v1.size()) and add == 0)
                break;
            if (i < int(v1.size()))
                add += v1[i];
            v.push_back(add % B);
            add /= B;
        }
        norm();
        return *this;
    }
    bigint div_naive(const bigint &a, const bigint &b) {
        if (SZ(b) == 1)
            return a.div(b.v.back());
        if (a < b)
            return bigint();
        int norm = B / (b.v.back() + 1);
        bigint x = a.mul(norm), y = b.mul(norm);
        int yb = y.v.back();
        bigint quo, rem;
        quo.v.resize(x.size() - y.size() + 1);
        rem.v = {x.v.end() - y.size(), x.v.end()};
        for (int i = x.size() - y.size(); i >= 0; i--) {
            if (rem.size() == y.size()) {
                if (rem >= y) {
                    quo[i] = 1;
                    rem -= y;
                }
            } else if (rem.size() > y.size()) {
                ll rb = ll(rem.v.back()) * B + rem[rem.size() - 2];
                int q = rb / yb;
                bigint yq = y.mul(q);
                while (rem < yq) {
                    q--;
                    yq -= y;
                }
                rem -= yq;
                while (rem >= y) {
                    q++;
                    rem -= y;
                }
                quo[i] = q;
            }
            if (i)
                rem.v.insert(rem.v.begin(), x[i - 1]);
        }
        return quo;
    }
    bigint &operator/=(const bigint &x) {
        bigint a = abs(), b = x.abs();
        sign ^= x.sign;
        if (a < b)
            return *this = bigint();
        if (b.size() == 1)
            return *this = a.div(b.v.back());

        int deg = a.size() - b.size() + 2, k = deg;
        while (k > 64)
            k = (k + 1) >> 1;
        bigint base(1);
        base <<= (b.size() + k);
        bigint inv(div_naive(base, b));

        while (k < deg) {
            bigint y = inv.square();
            y.v.insert(y.v.begin(), 0);
            int l = min(SZ(b), k * 2 + 1);
            bigint pref;
            pref.v = {b.v.end() - l, b.v.end()};
            y *= pref;
            y >>= l;
            inv = inv + inv;
            inv <<= k + 1;
            inv -= y;
            inv.v.erase(inv.v.begin());
            k <<= 1;
        }
        inv >>= (k - deg);

        (*this) = a * inv;
        (*this) >>= int(a.size() + 2);
        bigint mul = (*this) * b;
        while (mul + b <= a) {
            (*this) += bigint(1);
            mul += b;
        }
        while (mul > a) {
            (*this) -= bigint(1);
            mul -= b;
        }
        return *this;
    }
    bigint &operator%=(const bigint &x) {
        bigint div = (*this) / x;
        (*this) -= div * x;
        return *this;
    }
    bigint square() const {
        bigint ret;
        auto v1 = ArbitraryMult<u128>(v, v);
        u128 add = 0;
        ret.v.reserve(v1.size() + 3);
        for (int i = 0;; i++) {
            if (i >= int(v1.size()) and add == 0)
                break;
            if (i < int(v1.size()))
                add += v1[i];
            ret.v.push_back(add % B);
            add /= B;
        }
        return ret;
    }
    bigint mul(ll x) const {
        bigint res;
        if (x < 0)
            res.sign ^= 1, x *= -1;
        u128 add = 0;
        res.v.reserve(v.size() + 3);
        for (int i = 0;; i++) {
            if (i >= int(v.size()) and add == 0)
                break;
            if (i < int(v.size()))
                add += ll(v[i]) * x;
            res.v.push_back(add % B);
            add /= B;
        }
        return res;
    }
    bigint div(ll x) const {
        bigint res = *this;
        if (x < 0)
            res.sign ^= 1, x *= -1;
        ll add = 0;
        for (int i = res.v.size() - 1; i >= 0; i--) {
            add = add * B + res.v[i];
            int q = add / x, r = add % x;
            res.v[i] = q, add = r;
        }
        res.norm();
        return res;
    }
    bigint operator<<(const int &x) const { return bigint(*this) <<= x; }
    bigint operator>>(const int &x) const { return bigint(*this) >>= x; }
    bigint operator+(const bigint &x) const { return bigint(*this) += x; }
    bigint operator-(const bigint &x) const { return bigint(*this) -= x; }
    bigint operator*(const bigint &x) const { return bigint(*this) *= x; }
    bigint operator/(const bigint &x) const { return bigint(*this) /= x; }
    bigint operator%(const bigint &x) const { return bigint(*this) %= x; }
    bool operator<(const bigint &x) const {
        if (sign != x.sign)
            return sign > x.sign;
        if ((int)v.size() != (int)x.size()) {
            if (sign)
                return (int)x.size() < (int)v.size();
            else
                return (int)v.size() < (int)x.size();
        }
        for (int i = v.size() - 1; i >= 0; i--)
            if (v[i] != x.v[i]) {
                if (sign)
                    return x.v[i] < v[i];
                else
                    return v[i] < x.v[i];
            }
        return false;
    }
    bool operator>(const bigint &x) const { return x < *this; }
    bool operator<=(const bigint &x) const { return !(*this > x); }
    bool operator>=(const bigint &x) const { return !(*this < x); }
    bool operator==(const bigint &x) const {
        return !(*this < x) and !(*this > x);
    }
    bool operator!=(const bigint &x) const { return !(*this == x); }
};
typedef bigint<9> Bigint;

struct Bigfloat {
    Bigint v;
    int p = 0;
    Bigfloat() {}
    Bigfloat(const ll &_v) { v = Bigint(_v); }
    Bigfloat(const Bigint &_v, int _p = 0) : v(_v), p(_p) {}
    void set(int _p) {
        if (p < _p) {
            v >>= (_p - p);
        } else {
            v <<= (p - _p);
        }
        p = _p;
    }
    Bigint to_int() const {
        if (p < 0)
            return v >> (-p);
        else
            return v << p;
    }
    Bigfloat &operator+=(const Bigfloat &x) {
        if (p > x.p)
            set(x.p), v += x.v;
        else
            v += x.v << (x.p - p);
        return *this;
    }
    Bigfloat &operator-=(const Bigfloat &x) {
        if (p > x.p)
            set(x.p), v -= x.v;
        else
            v -= x.v << (x.p - p);
        return *this;
    }
    Bigfloat square() {
        Bigfloat res = *this;
        res.p *= 2;
        res.v = res.v.square();
        return res;
    }
    Bigfloat mul(ll x) {
        Bigfloat res = *this;
        res.v = v.mul(x);
        return res;
    }
    Bigfloat div(ll x) {
        Bigfloat res = *this;
        res.v = v.div(x);
        return res;
    }
    Bigfloat &operator*=(const Bigfloat &x) {
        p += x.p;
        v *= x.v;
        return *this;
    }
    Bigfloat &operator/=(const Bigfloat &x) {
        p -= x.p;
        v /= x.v;
        return *this;
    }
    Bigfloat operator+(const Bigfloat &x) const { return Bigfloat(*this) += x; }
    Bigfloat operator-(const Bigfloat &x) const { return Bigfloat(*this) -= x; }
    Bigfloat operator*(const Bigfloat &x) const { return Bigfloat(*this) *= x; }
    Bigfloat operator/(const Bigfloat &x) const { return Bigfloat(*this) /= x; }
    string to_str() {
        string res = v.abs().to_str();
        int d = Bigint::get_D();
        if (p * d > 0)
            res += string(p * d, '0');
        else if (-p * d >= 1 and -p * d < (int)res.size()) {
            res = res.substr(0, (int)res.size() + p * d) + '.' +
                  res.substr((int)res.size() + p * d);
        } else if (-p * d >= (int)res.size())
            res = "0." + string(-p * d - (int)res.size(), '0') + res;
        if (v.sign) {
            res.insert(res.begin(), '-');
        }
        return res;
    }
    friend ostream &operator<<(ostream &os, Bigfloat x) {
        os << x.to_str();
        return os;
    }
};

Bigfloat sqrt(ll n, int d) {
    Bigfloat res(Bigint((ll)sqrt(1LL * Bigint::get_B() * Bigint::get_B() / n)),
                 -1),
        pre;
    int cur = 1;
    while (pre.v != res.v) {
        cur = min(cur << 1, d);
        pre = res;
        Bigfloat add = Bigfloat(1) - res.square().mul(n);
        add.set(-cur);
        res += (res * add).div(2);
        res.set(-cur);
    }
    return res.mul(n);
}

/**
 * @brief Big Integer(Float)
 */