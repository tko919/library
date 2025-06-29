#pragma once

template <typename T, T (*pe)(int, int), T (*psum)(ll)>
struct MultiplicativeSum {
    ll N, SQ, sz;
    vector<ll> quo;
    vector<T> dat;
    MultiplicativeSum() {}
    MultiplicativeSum(ll n, vector<ll> &_quo, vector<int> &ps)
        : N(n), SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(_quo), dat(sz) {
        rep(i, 0, sz) dat[i] = psum(quo[i]);

        reverse(ALL(ps));
        vector<T> ndat = dat;
        for (auto &p : ps) {
            T pc = pe(p, 1);
            T rui = psum(p);
            int L = sz;
            for (ll pw = p, c = 1; N / p >= pw; pw *= p, c++) {
                T nxt = pe(p, c + 1);
                rrep(j, 0, sz) {
                    if (quo[j] < pw * p) {
                        chmin(L, j + 1);
                        break;
                    }
                    ndat[j] += pc * (dat[idx(quo[j] / pw)] - rui) + nxt;
                }
                pc = nxt;
            }
            copy(ndat.begin() + L, ndat.end(), dat.begin() + L);
        }
        rep(i, 0, sz) dat[i] += 1;
    }
    T operator[](ll x) {
        return dat[idx(x)];
    }

  private:
    int idx(ll x) const {
        if (x <= SQ)
            return x - 1;
        else
            return sz - N / x;
    }
};

/**
 * @brief Multiplicative Sum
 * @docs docs/multiplicative.md
 */