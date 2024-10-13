#pragma once

template <typename T>
vector<T> InterpolateGeomSeq(int n, T a, T w, vector<T> &y) {
    if (n == 0)
        return {};
    auto listinv = [&](vector<T> a) -> vector<T> {
        int N = a.size();
        vector<T> rui(N + 1, 1);
        rep(i, 0, N) rui[i + 1] = rui[i] * a[i];
        T c = rui.back().inv();
        rui.pop_back();
        for (int i = N - 1; i >= 0; i--) {
            rui[i] *= c;
            c *= a[i];
        }
        return rui;
    };
    vector<T> pw(n + 1, 1), tri(n + 1, 1), ttri(n + 1, 1), s(n, 1), W(n, 1);
    rep(i, 0, n) pw[i + 1] = pw[i] * w;
    rep(i, 0, n) {
        tri[i + 1] = tri[i] * pw[i];
        if (i != n - 1) {
            ttri[i + 1] = ttri[i] * pw[n - i - 2];
            s[i + 1] = s[i] * (-pw[i + 1] + 1);
        }
    }
    T sn = s[n - 1] * (-pw[n] + 1);
    auto ittri = listinv(ttri), is = listinv(s);
    rep(i, 0, n) {
        T den = ittri[i] * is[i] * is[n - i - 1];
        if (i & 1)
            den = -den;
        W[i] = y[i] * den;
    }

    // prod (1-w^i x)
    Poly<T> f(n);
    f[0] = 1;
    rep(k, 1, n) {
        f[k] = tri[k] * sn * (is[k] * is[n - k]);
        if (k & 1)
            f[k] = -f[k];
    }

    // sum W_i/(1-w^i x)
    Poly<T> g = MultievalGeomSeq(W, T(1), w, n);

    f *= g;
    f.resize(n);
    reverse(ALL(f));
    T ia = a.inv(), c = 1;
    rep(i, 0, n) {
        f[i] *= c;
        c *= ia;
    }
    return f;
}

/**
 * Polynomial Interpolation on Geometric Sequence
 */