#pragma once

template <typename T> struct Gauss {
    T x, y;
    Gauss() {}
    Gauss(T _x, T _y) : x(_x), y(_y) {}
    T norm() const {
        return x * x + y * y;
    }
    Gauss conj() const {
        return Gauss(x, -y);
    }
    Gauss operator-() const {
        return Gauss(-x, -y);
    }
    Gauss pow(ll n) const {
        assert(n >= 0);
        Gauss ret(1), mul(*this);
        while (n) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    Gauss &operator+=(const Gauss &a) {
        x += a.x, y += a.y;
        return *this;
    }
    Gauss &operator-=(const Gauss &a) {
        x -= a.x, y -= a.y;
        return *this;
    }
    Gauss &operator*=(const Gauss &a) {
        T nx = x * a.x - y * a.y, ny = x * a.y + y * a.x;
        x = nx, y = ny;
        return *this;
    }
    Gauss &operator/=(const Gauss &a) {
        (*this) *= a.conj();
        T n = a.norm();
        x = floor(x + n / 2, n), y = floor(y + n / 2, n);
        return *this;
    }
    Gauss &operator%=(const Gauss &a) {
        (*this) -= (Gauss(*this) / a) * a;
        return *this;
    }
    Gauss operator+(const Gauss &a) const {
        return Gauss(*this) += a;
    }
    Gauss operator-(const Gauss &a) const {
        return Gauss(*this) -= a;
    }
    Gauss operator*(const Gauss &a) const {
        return Gauss(*this) *= a;
    }
    Gauss operator/(const Gauss &a) const {
        return Gauss(*this) /= a;
    }
    Gauss operator%(const Gauss &a) const {
        return Gauss(*this) %= a;
    }
    bool operator==(const Gauss &a) {
        return (x == a.x and y == a.y);
    }
    bool operator!=(const Gauss &a) {
        return (x != a.x or y != a.y);
    }
};

template <typename T> Gauss<T> gcd(Gauss<T> a, Gauss<T> b) {
    while (b != Gauss<T>(0, 0)) {
        a %= b;
        swap(a, b);
    }
    return a;
}

/**
 * @brief Gaussaussian Integer
 */