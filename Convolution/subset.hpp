#pragma once

template <typename T, int LG = 20> struct SubsetConvolution {
    using POL = array<T, LG + 1>;
    vector<int> bpc;
    SubsetConvolution() : bpc(1 << LG) {
        rep(i, 1, 1 << LG) bpc[i] = bpc[i - (i & -i)] + 1;
    }
    void zeta(vector<POL> &a) {
        int n = topbit(SZ(a));
        rep(d, 0, n) {
            rep(i, 0, 1 << n) if (i >> d & 1) {
                const int pc = bpc[i];
                rep(j, 0, pc) a[i][j] += a[i ^ (1 << d)][j];
            }
        }
    }
    void mobius(vector<POL> &a) {
        int n = topbit(SZ(a));
        rep(d, 0, n) {
            rep(i, 0, 1 << n) if (i >> d & 1) {
                const int pc = bpc[i];
                rep(j, pc, n + 1) a[i][j] -= a[i ^ (1 << d)][j];
            }
        }
    }
    vector<T> mult(vector<T> &a, vector<T> &b) {
        assert(a.size() == b.size());
        int n = SZ(a), m = topbit(n);
        vector<POL> A(n), B(n);
        rep(i, 0, n) {
            A[i][bpc[i]] = a[i];
            B[i][bpc[i]] = b[i];
        }
        zeta(A);
        zeta(B);
        rep(i, 0, n) {
            POL c = {};
            rep(j, 0, m + 1) rep(k, 0, m + 1 - j) c[j + k] += A[i][j] * B[i][k];
            swap(A[i], c);
        }
        mobius(A);
        vector<T> ret(n);
        rep(i, 0, n) ret[i] = A[i][bpc[i]];
        return ret;
    }
    vector<T> TransposeMult(vector<T> &a, vector<T> &b) {
        auto ret = a;
        reverse(ALL(ret));
        ret = mult(ret, b);
        reverse(ALL(ret));
        return ret;
    }
    vector<T> exp(vector<T> &f) {
        int n = topbit(SZ(f));
        vector<T> ret(1 << n);
        ret[0] = 1;
        rep(i, 0, n) {
            vector<T> a = {ret.begin(), ret.begin() + (1 << i)};
            vector<T> b = {f.begin() + (1 << i), f.begin() + (2 << i)};
            a = mult(a, b);
            copy(ALL(a), ret.begin() + (1 << i));
        }
        return ret;
    }
    vector<T> CompositionEGF(vector<T> &s, vector<T> &f) {
        int n = topbit(SZ(s));
        f.resize(n + 1);
        vector<T> dp(1);
        dp[0] = f.back();
        rrep(d, 0, n) {
            vector<T> ndp(1 << (n - d));
            ndp[0] = f[d];
            rep(i, 0, n - d) {
                vector<T> a = {dp.begin(), dp.begin() + (1 << i)};
                vector<T> b = {s.begin() + (1 << i), s.begin() + (2 << i)};
                a = mult(a, b);
                copy(ALL(a), ndp.begin() + (1 << i));
            }
            swap(dp, ndp);
        }
        return dp;
    }
    vector<T> Composition(vector<T> &s, vector<T> &f) {
        int n = topbit(SZ(s));
        T c = s[0];
        s[0] = 0;
        // taylor shift
        vector<T> pw(n + 1), g(n + 1);
        pw[0] = 1;
        rep(i, 0, SZ(f)) {
            rep(j, 0, n + 1) g[j] += f[i] * pw[j];
            rrep(j, 0, n + 1) {
                if (j != n)
                    pw[j + 1] += pw[j];
                pw[j] *= c;
            }
        }
        // to EGF
        T fact = 1;
        rep(i, 1, n + 1) {
            fact *= i;
            g[i] *= fact;
        }
        return CompositionEGF(s, g);
    }
    vector<T> TransposeCompositionEGF(vector<T> &s, vector<T> &t) {
        int n = topbit(SZ(s));
        vector<T> dp = t, ret(n + 1);
        ret[0] = dp[0];
        rep(d, 0, n) {
            vector<T> ndp(1 << (n - d - 1), 0);
            rrep(i, 0, n - d) {
                vector<T> a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};
                vector<T> b = {s.begin() + (1 << i), s.begin() + (2 << i)};
                a = TransposeMult(a, b);
                rep(k, 0, SZ(a)) ndp[k] += a[k];
            }
            swap(dp, ndp);
            ret[d + 1] = dp[0];
        }
        return ret;
    }
    vector<T> TransposeComposition(vector<T> &s, vector<T> &t, int m) {
        int n = topbit(SZ(s));
        T c = s[0];
        s[0] = 0;

        auto g = TransposeCompositionEGF(s, t);
        vector<T> coe(m);
        T pw = 1;
        rep(i, 0, m) {
            coe[i] = pw * Fact<T>(i, 1);
            pw *= c;
        }
        vector<T> f(m);
        rep(i, 0, m) rep(j, 0, n + 1) if (i + j < m) {
            f[i + j] += coe[i] * g[j];
        }
        rep(i, 0, m) f[i] *= Fact<T>(i);
        return f;
    }
};

/**
 * @brief Subset Convolution
 */