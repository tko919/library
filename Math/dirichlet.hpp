#pragma once

template <typename T> struct Dir {
    ll n;
    int SQ, sz;
    vector<T> dat;
    Dir() {}
    Dir(ll n) : n(n), SQ(sqrtl(n)), sz(SQ + n / (SQ + 1) + 1), dat(sz) {}
    T &operator[](int i) {
        return dat[i];
    }
    const T &operator[](int i) const {
        return dat[i];
    }
    void pref() {
        rep(i, 0, sz - 1) dat[i + 1] += dat[i];
    }
    void diff() {
        rrep(i, 0, sz - 1) dat[i + 1] -= dat[i];
    }
    int idx(ll x) const {
        return (x <= SQ ? x : sz - n / x);
    }
    ll val(int id) const {
        return (id <= SQ ? id : n / (sz - id));
    }
    // Index of floor(n / d), avoiding the second division in idx(n / d).
    int quotient_idx(ll d) const {
        return (d <= SQ ? sz - d : n / d);
    }
};

template <typename T> Dir<T> mult(ll n, const Dir<T> &a, const Dir<T> &b) {
    Dir<T> c(n);
    const int SQ = c.SQ;
    int thre = a.idx(max<ll>(1, pow(n, 2. / 3)));
    auto get = [&](const Dir<T> &A,
                   const Dir<T> &B) -> vector<pair<ll, T>> {
        vector<pair<ll, T>> ret;
        rep(i, 1, SQ + 1) if (A[i - 1] != A[i]) {
            T x = A[i] - A[i - 1];
            ret.push_back({i, x});
            // j = sz-d represents floor(n/d), hence
            // floor(val(j)/i) = floor(n/(d*i)).
            for (int d = 1; d < c.sz - thre; d++) {
                int j = c.sz - d;
                int to = B.quotient_idx(ll(d) * i);
                if (to < i)
                    break;
                c[j] += x * B[to];
            }
        }
        rep(i, SQ + 1, thre + 1) {
            if (A[i - 1] != A[i]) {
                T x = A[i] - A[i - 1];
                ret.push_back({A.val(i), x});
            }
        }
        return ret;
    };
    auto posA = get(a, b);
    auto posB = get(b, a);
    for (auto &[v, x] : posA) {
        for (auto &[w, y] : posB) {
            int to = c.idx(v * w);
            if (to > thre)
                break;
            c[to] += x * y;
        }
    }
    rep(i, 1, thre + 1) {
        c[i] += c[i - 1];
    }

    rrep(i, thre + 1, c.sz) {
        ll x = c.val(i);
        int j = sqrtl(x);
        c[i] -= a[j] * b[j];
    }

    return c;
}

template <typename T> Dir<T> div(ll n, Dir<T> c, Dir<T> a) {
    T coe = T(1) / a[1];
    for (auto &x : a.dat)
        x *= coe;

    int SQ = sqrtl(n);
    int thre = a.idx(max<int>(1, pow(n, 2. / 3)));
    Dir<T> dc = c, da = a, db(n), b(n);
    dc.diff();
    da.diff();

    db[1] = c[1];
    rep(i, 2, thre + 1) {
        db[i] = dc[i] - da[i] * db[1];
        ll x = a.val(i);
        if (x <= n / x) {
            int j = a.idx(x * x);
            if (j <= thre)
                dc[j] -= da[i] * db[i];
        }
        rep(j, 2, i) {
            ll y = a.val(j);
            if (x > n / y)
                break;
            int k = a.idx(x * y);
            if (k > thre)
                break;
            dc[k] -= da[i] * db[j] + da[j] * db[i];
        }
    }
    rep(i, 1, thre + 1) {
        b[i] = db[i] + b[i - 1];
    }
    rep(i, thre + 1, a.sz) {
        b[i] = c[i] - a[i] * b[1];
        ll x = a.val(i);
        {
            int j = sqrtl(x);
            b[i] += a[j] * b[j];
        }
        ll d = a.sz - i;
        rep(j, 2, i + 1) {
            int k = a.quotient_idx(d * j);
            if (j > k)
                break;
            b[i] -= da[j] * b[k] + a[k] * db[j];
        }
    }

    for (auto &x : b.dat)
        x *= coe;
    return b;
}

/**
 * @brief Dirichlet series
 */
