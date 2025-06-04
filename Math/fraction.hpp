#pragma once

template <typename T> struct Frac {
    T a, b;
    Frac(T _a = 0) {
        init(_a, 1);
    }
    Frac(T _a, T _b) {
        init(_a, _b);
    }
    template <typename V> V get() const {
        return V(a) / b;
    }
    Frac &init(T _a, T _b) {
        T g = gcd(_a, _b);
        a = _a / g, b = _b / g;
        if (b < 0)
            a = -a, b = -b;
        return *this;
    }
    Frac inv() const {
        return Frac(b, a);
    }
    Frac operator-() const {
        return Frac(-a, b);
    }
    Frac &operator+=(const Frac &x) {
        return init(a * x.b + x.a * b, b * x.b);
    }
    Frac &operator-=(const Frac &x) {
        return init(a * x.b - x.a * b, b * x.b);
    }
    Frac &operator*=(const Frac &x) {
        return init(a * x.a, b * x.b);
    }
    Frac &operator/=(const Frac &x) {
        return init(a * x.b, b * x.a);
    }
    Frac operator+(const Frac &x) const {
        return Frac(*this) += x;
    }
    Frac operator-(const Frac &x) const {
        return Frac(*this) -= x;
    }
    Frac operator*(const Frac &x) const {
        return Frac(*this) *= x;
    }
    Frac operator/(const Frac &x) const {
        return Frac(*this) /= x;
    }
    bool operator<(const Frac &x) const {
        return a * x.b < b * x.a;
    }
    bool operator>(const Frac &x) const {
        return x < *this;
    }
    bool operator<=(const Frac &x) const {
        return !(x < *this);
    }
    bool operator>=(const Frac &x) const {
        return !(*this < x);
    }
    bool operator==(const Frac &x) const {
        return (*this <= x and x <= *this);
    }
    bool operator!=(const Frac &x) const {
        return !(*this == x);
    }

    friend istream &operator>>(istream &is, Frac &x) {
        return is >> x.a >> x.b;
    }
    friend ostream &operator<<(ostream &os, const Frac &x) {
        return os << x.a << '/' << x.b;
    }
};

/**
 * @brief Fraction
 * @docs docs/fraction.md
 */