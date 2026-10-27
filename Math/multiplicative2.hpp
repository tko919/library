#pragma once
#include "Math/comb.hpp"
#include "Math/dirichlet.hpp"

inline const vector<int> &multiplicative_primes(int n) {
    static int cached_n = 1;
    static vector<int> primes;
    if (n <= cached_n)
        return primes;

    cached_n = n;
    primes.clear();
    vector<int> least(n + 1);
    for (int i = 2; i <= n; i++) {
        if (least[i] == 0) {
            least[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > least[i] or ll(i) * p > n)
                break;
            least[i * p] = p;
        }
    }
    return primes;
}

template <typename T, T (*F)(ll)> Dir<T> getLarge(ll n) {
    int SQ = sqrtl(n);
    const auto &ps = multiplicative_primes(SQ);
    vector<T> small(SQ + 1);
    rep(x, 1, SQ + 1) small[x] = F(x);
    rrep(i, 1, SQ + 1) small[i] -= small[i - 1];
    Dir<T> den(n), lg(n);

    int SQ6 = max<int>(1, pow(n, 1. / 6));
    for (auto &p : ps) {
        if (p > SQ)
            break;
        if (SQ6 < p) {
            T f_p = small[p];
            T X[6] = {}, base[6] = {};
            rep(i, 1, 6) {
                base[i] = POW<T>(f_p, i);
            }
            rep(i, 1, 6) {
                T tmp = base[i] * i;
                rep(j, 1, i + 1) tmp -= base[j] * X[i - j];
                X[i] = tmp;
            }
            rep(i, 1, 6) X[i] /= i;

            for (ll x = 1, i = 0;; x *= p, i++) {
                lg[den.idx(x)] += X[i];
                if (x > n / p)
                    break;
            }
        }
    }
    lg.pref();

    // exp
    {
        Dir<T> add(n);
        rep(i, 1, add.sz) add[i] = den[i] = 1;
        rep(e, 1, 5 + 1) {
            add = mult(n, add, lg);
            T inv_fact = Fact<T>(e, 1);
            rep(i, 1, add.sz) den[i] += add[i] * inv_fact;
        }
    }

    for (auto &p : ps)
        if (p > SQ)
            break;
        else if (p <= SQ6) {
            T f_p = small[p];
            rep(i, 1, den.sz) {
                int to = i <= SQ ? i / p
                                 : den.quotient_idx(ll(den.sz - i) * p);
                den[i] += den[to] * f_p;
            }
        }

    Dir<T> ret(n);
    int lim = n / (SQ + 1);
    rrep(i, 1, lim + 1) {
        int id = den.sz - i;
        T tmp = F(n / i) - den[id];
        for (int j = 2; i * j <= SQ; j++)
            tmp -= small[j] * ret[ret.sz - i * j];
        ret[id] = tmp;
    }

    ret.diff();
    return ret;
}

template <typename T, T (*pe)(int p, int e)>
Dir<T> MultiplicativeSum(ll n, Dir<T> &large) {
    Dir<T> base(n), lg(n);
    int SQ = sqrtl(n);
    const auto &ps = multiplicative_primes(SQ);

    int SQ6 = max<int>(1, pow(n, 1. / 6));
    for (auto &p : ps) {
        if (p > SQ)
            break;
        if (p <= SQ6)
            continue;
        T X[6] = {}, prime_power[6] = {};
        rep(i, 1, 6) {
            prime_power[i] = pe(p, i);
        }
        rep(i, 1, 6) {
            T tmp = prime_power[i] * i;
            rep(j, 1, i + 1) tmp -= prime_power[j] * X[i - j];
            X[i] = tmp;
        }
        rep(i, 1, 6) X[i] /= i;
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
            T inv_fact = Fact<T>(e, 1);
            rep(i, 1, add.sz) base[i] += add[i] * inv_fact;
        }
    }

    rrep(x, 1, SQ + 1) {
        int i = base.sz - x;
        for (int y = 1; x * y <= SQ; y++)
            if (base[y - 1] != base[y])
                base[i] +=
                    (base[y] - base[y - 1]) * large[large.sz - x * y];
    }

    for (auto &p : ps) {
        if (p > SQ6 or p > SQ)
            break;
        T buf[65] = {};
        int max_e = 0;
        for (ll pw = p;; pw *= p) {
            ++max_e;
            buf[max_e] = pe(p, max_e);
            if (pw > n / p)
                break;
        }
        rrep(i, 1, base.sz) {
            if (i <= SQ) {
                ll x = i / p;
                for (int e = 1; x; e++, x /= p)
                    base[i] += base[x] * buf[e];
            } else {
                ll d = base.sz - i, den = d * p;
                for (int e = 1; den <= n; e++) {
                    base[i] += base[base.quotient_idx(den)] * buf[e];
                    if (den > n / p)
                        break;
                    den *= p;
                }
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
