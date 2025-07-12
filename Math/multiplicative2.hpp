#pragma once
#include "Math/sieve.hpp"

template <typename T> struct Dir {
    ll n;
    int SQ, sz;
    vector<T> dat;
    Dir() {}
    Dir(ll n) : n(n), SQ(sqrtl(n)), sz(SQ + n / (SQ + 1) + 1), dat(sz) {}
    T &operator[](int i) {
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
};

template <typename T> Dir<T> mult(ll n, Dir<T> &a, Dir<T> &b) {
    int SQ = sqrtl(n);
    Dir<T> c(n);
    int thre = a.idx(max<int>(1, pow(n, 2. / 3)));
    auto get = [&](Dir<T> &A, Dir<T> &B) -> vector<pair<int, T>> {
        vector<pair<int, T>> ret;
        rep(i, 1, SQ + 1) if (A[i - 1] != A[i]) {
            T x = A[i] - A[i - 1];
            ret.push_back({i, x});
            rrep(j, thre + 1, c.sz) {
                ll k = c.val(j);
                int to = B.idx(k / i);
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
            int to = c.idx(ll(v) * w);
            if (to > thre)
                break;
            c[c.idx(v * w)] += x * y;
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

template <typename T, T (*F)(ll)> Dir<T> getLarge(ll n) {
    Dir<T> base(n);
    int SQ = sqrtl(n);
    auto ps = sieve(SQ);
    vector<T> small(SQ + 10);
    rep(x, 1, SQ + 10) small[x] = F(x);
    rrep(i, 1, SQ + 10) small[i] -= small[i - 1];
    Dir<T> den(n), lg(n);

    int SQ6 = max<int>(1, pow(n, 1. / 6));
    for (auto &p : ps)
        if (SQ6 < p) {
            T f_p = small[p];
            T X[10] = {}, base[10] = {};
            rep(i, 1, 10) {
                base[i] = POW<T>(f_p, i);
            }
            rep(i, 1, 10) {
                T tmp = base[i] * i;
                rep(j, 1, i + 1) tmp -= base[j] * X[i - j];
                X[i] = tmp;
            }
            rep(i, 1, 10) X[i] /= i;

            for (ll x = 1, i = 0;; x *= p, i++) {
                lg[den.idx(x)] += X[i];
                if (x > n / p)
                    break;
            }
        }
    lg.pref();

    // exp
    {
        Dir<T> add(n);
        rep(i, 1, add.sz) add[i] = den[i] = 1;
        rep(e, 1, 5 + 1) {
            add = mult(n, add, lg);
            rep(i, 1, add.sz) den[i] += add[i] * Fact<T>(e, 1);
        }
    }

    for (auto &p : ps)
        if (p <= SQ6) {
            T f_p = small[p];
            rep(i, 1, den.sz) {
                ll x = den.val(i);
                den[i] += den[den.idx(x / p)] * f_p;
            }
        }

    Dir<T> ret(n);
    rrep(i, 1, SQ + 1) if (n / i > SQ) {
        int id = den.idx(n / i);
        T tmp = F(n / i) - den[id];
        for (int j = 2; i * j <= SQ; j++)
            tmp -= small[j] * ret[ret.idx(n / i / j)];
        ret[id] = tmp;
    }

    ret.diff();
    return ret;
}

template <typename T, T (*pe)(int p, int e)>
Dir<T> MultiplicativeSum(ll n, Dir<T> &large) {
    Dir<T> base(n), lg(n);
    int SQ = sqrtl(n);
    auto ps = sieve(SQ);

    int SQ6 = max<int>(1, pow(n, 1. / 6));
    for (auto &p : ps) {
        if (p <= SQ6)
            continue;
        T X[10] = {}, base[10] = {};
        rep(i, 1, 10) {
            base[i] = pe(p, i);
        }
        rep(i, 1, 10) {
            T tmp = base[i] * i;
            rep(j, 1, i + 1) tmp -= base[j] * X[i - j];
            X[i] = tmp;
        }
        rep(i, 1, 10) X[i] /= i;
        for (ll x = 1, i = 0;; x *= p, i++) {
            lg[lg.idx(x)] += X[i];
            if (x > n / p)
                break;
        }
    }
    lg.pref();

    // exp
    {
        Dir<T> add(n);
        rep(i, 1, add.sz) add[i] = base[i] = 1;
        rep(e, 1, 5 + 1) {
            add = mult(n, add, lg);
            rep(i, 1, add.sz) base[i] += add[i] * Fact<T>(e, 1);
        }
    }

    rrep(x, 1, SQ + 1) {
        int i = base.idx(n / x);
        for (int y = 1; x * y <= SQ; y++)
            if (base[y - 1] != base[y]) {
                base[i] +=
                    (base[y] - base[y - 1]) * large[large.idx(n / x / y)];
            }
    }

    for (auto &p : ps) {
        if (p > SQ6)
            break;
        T buf[65];
        rep(e, 0, 65) buf[e] = pe(p, e);
        rrep(i, 1, base.sz) {
            ll x = base.val(i) / p;
            for (int e = 1;; e++) {
                base[i] += base[base.idx(x)] * buf[e];
                x /= p;
                if (x == 0)
                    break;
            }
        }
    }

    return base;
}

/**
 * @brief Multiplicative Sum $O(n^{2/3}(\log n)^{-1})$
 * @ref
 * https://scrapbox.io/nachia-cp/%E4%B9%97%E6%B3%95%E7%9A%84%E9%96%A2%E6%95%B0%E7%B4%AF%E7%A9%8D%E5%92%8C-%E4%B8%AD%E5%9B%BD%E3%82%B3%E3%83%9F%E3%83%A5%E3%83%8B%E3%83%86%E3%82%A3%E3%81%AE%E6%96%B9%E6%B3%95
 */