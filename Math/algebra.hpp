#pragma once

template <typename T, T (*add)(T, T), T (*inv)(T), T (*e0)()> struct Group : T {
    Group(T v = e0()) : T(v) {}
    Group operator-() const {
        return Group(inv(*this));
    }
    Group &operator+=(const Group &x) {
        return *this = add(*this, x);
    }
    Group &operator-=(const Group &x) {
        return *this = add(*this, inv(x));
    }
    Group operator+(const Group &x) const {
        return Group(*this) += x;
    }
    Group operator-(const Group &x) const {
        return Group(*this) -= x;
    }
    bool operator==(const Group &x) const {
        return T(*this) == T(x);
    }
    bool operator!=(const Group &x) const {
        return T(*this) != T(x);
    }
};

template <typename T, T (*add)(T, T), T (*mul)(T, T), T (*e0)(), T (*e1)()>
struct Semiring : T {
    Semiring(T v = e0()) : T(v) {}
    static T id1() {
        return e1();
    }
    Semiring &operator+=(const Semiring &x) {
        return *this = add(*this, x);
    }
    Semiring &operator*=(const Semiring &x) {
        return *this = mul(*this, x);
    }
    Semiring operator+(const Semiring &x) const {
        return Semiring(*this) += x;
    }
    Semiring operator*(const Semiring &x) const {
        return Semiring(*this) *= x;
    }
    bool operator==(const Semiring &x) const {
        return T(*this) == T(x);
    }
    bool operator!=(const Semiring &x) const {
        return T(*this) != T(x);
    }
};

template <class T> struct Matrix {
    int h, w;
    vector<vector<T>> val;
    Matrix() {}
    Matrix(int n, int m)
        : h(n), w(m), val(vector<vector<T>>(n, vector<T>(m, T()))) {}
    vector<T> &operator[](const int i) {
        return val[i];
    }
    Matrix &operator+=(const Matrix &m) {
        rep(i, 0, h) rep(j, 0, w) val[i][j] += m.val[i][j];
        return *this;
    }
    Matrix &operator*=(const Matrix &m) {
        Matrix<T> res(h, m.w);
        rep(i, 0, h) rep(j, 0, m.w) rep(k, 0, w) res.val[i][j] +=
            val[i][k] * m.val[k][j];
        *this = res;
        return *this;
    }
    Matrix operator+(const Matrix &m) const {
        return Matrix(*this) += m;
    }
    Matrix operator*(const Matrix &m) const {
        return Matrix(*this) *= m;
    }
    Matrix pow(ll k) {
        Matrix<T> res(h, h), c = *this;
        rep(i, 0, h) res.val[i][i] = T::id1();
        while (k) {
            if (k & 1)
                res *= c;
            c *= c;
            k >>= 1;
        }
        return res;
    }
};

/**
 * @brief Algebra Structure
 */