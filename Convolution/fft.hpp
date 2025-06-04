#pragma once

namespace FFT {
struct C {
    double x, y;
    C(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    C operator~() const {
        return C(x, -y);
    }
    C operator*(const C &c) const {
        return C(x * c.x - y * c.y, x * c.y + y * c.x);
    }
    C operator+(const C &c) const {
        return C(x + c.x, y + c.y);
    }
    C operator-(const C &c) const {
        return C(x - c.x, y - c.y);
    }
};
vector<vector<C>> w(1, vector<C>(1, 1));
void init(int lg) {
    for (int d = 1, m = 1; d <= lg; d++, m <<= 1)
        if (d >= (int)w.size()) {
            w.emplace_back(m);
            const double th = M_PI / m;
            for (int i = 0; i < m; i++)
                w[d][i] =
                    (i & 1 ? C(cos(th * i), sin(th * i)) : w[d - 1][i >> 1]);
        }
}
void fft(vector<C> &f, bool inv) {
    const int n = f.size();
    const int lg = __lg(n);
    if (lg >= (int)w.size())
        init(lg);
    if (inv) {
        for (int k = 1; k <= lg; k++) {
            const int d = 1 << (k - 1);
            for (int s = 0; s < n; s += 2 * d) {
                for (int i = s; i < s + d; i++) {
                    C x = f[i], y = ~w[k][i - s] * f[d + i];
                    f[i] = x + y;
                    f[d + i] = x - y;
                }
            }
        }
    } else {
        for (int k = lg; k; k--) {
            const int d = 1 << (k - 1);
            for (int s = 0; s < n; s += 2 * d) {
                for (int i = s; i < s + d; i++) {
                    C x = f[i], y = f[d + i];
                    f[i] = x + y;
                    f[d + i] = w[k][i - s] * (x - y);
                }
            }
        }
    }
}
template <typename T> vector<T> mult(const vector<T> &a, const vector<T> &b) {
    const int as = a.size();
    const int bs = b.size();
    if (!as or !bs)
        return {};
    const int cs = as + bs - 1;
    vector<T> c(cs);
    if (max(as, bs) < 16) {
        for (int i = 0; i < as; i++)
            for (int j = 0; j < bs; j++) {
                c[i + j] += T(a[i]) * b[j];
            }
        return c;
    }
    const int n = 1 << __lg(2 * cs - 1);
    vector<C> f(n);
    for (int i = 0; i < as; i++)
        f[i].x = a[i];
    for (int i = 0; i < bs; i++)
        f[i].y = b[i];
    fft(f, 0);
    static const C rad(0, -.25);
    for (int i = 0; i < n; i++) {
        int j = i ? i ^ ((1 << __lg(i)) - 1) : 0;
        if (i > j)
            continue;
        C x = f[i] + ~f[j], y = f[i] - ~f[j];
        f[i] = x * y * rad;
        f[j] = ~f[i];
    }
    fft(f, 1);
    for (int i = 0; i < cs; i++) {
        if constexpr (is_same_v<T, int> or is_same_v<T, ll>) {
            c[i] = T(f[i].x / n + .5);
        } else {
            c[i] = T(f[i].x / n);
        }
    }
    return c;
}
template <typename T> vector<T> square(const vector<T> &a) {
    const int as = a.size();
    if (!as)
        return {};
    const int cs = as * 2 - 1;
    vector<T> c(cs);
    if (as < 16) {
        for (int i = 0; i < as; i++)
            for (int j = 0; j < as; j++) {
                c[i + j] += (int)a[i] * a[j];
            }
        return c;
    }
    const int n = 1 << __lg(cs * 2 - 1);
    vector<C> f(n);
    for (int i = 0; i < as; i++)
        f[i].x = a[i];
    fft(f, 0);
    for (int i = 0; i < n; i++)
        f[i] = f[i] * f[i];
    fft(f, 1);
    for (int i = 0; i < cs; i++) {
        if constexpr (is_same_v<T, int> or is_same_v<T, ll>) {
            c[i] = T(f[i].x / n + .5);
        } else {
            c[i] = T(f[i].x / n);
        }
    }
    return c;
}
} // namespace FFT

/**
 * @brief Fast Fourier Transform
 */