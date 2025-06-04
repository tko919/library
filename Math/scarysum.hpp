#pragma once

// f(x)=floor(ax+b/m) path product
template <typename M> M FloorProd(ll n, ll m, ll a, ll b, M x, M y) {
    M pre, suf;
    for (;;) {
        x = M::mul(x, M::pow(y, a / m));
        a %= m;
        pre = M::mul(pre, M::pow(y, b / m));
        b %= m;
        ll c = (a * n + b);
        if (c < m) {
            pre = M::mul(pre, M::pow(x, n));
            break;
        }
        suf = M::mul(y, M::mul(M::pow(x, (c % m) / a), suf));
        n = c / m - 1, b = m - b + a - 1;
        swap(m, a);
        swap(x, y);
    }
    return M::mul(pre, suf);
}

template <typename T, int K, int L> struct FloorPolyMonoid {
    static constexpr int N = max(K, L);
    static inline T C[N + 1][N + 1];
    static void init() {
        rep(i, 0, N + 1) {
            C[i][0] = C[i][i] = 1;
            rep(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    T sum[K + 1][L + 1] = {};
    T dx, dy;
    FloorPolyMonoid() : dx(0), dy(0) {}

    static FloorPolyMonoid mul(FloorPolyMonoid a, FloorPolyMonoid b) {
        array<T, K + 1> pwx;
        array<T, L + 1> pwy;
        pwx[0] = pwy[0] = 1;
        rep(i, 0, K) pwx[i + 1] = pwx[i] * a.dx;
        rep(i, 0, L) pwy[i + 1] = pwy[i] * a.dy;
        rep(i, 0, K + 1) {
            rrep(j, 0, L + 1) {
                rep(k, j + 1, L + 1) b.sum[i][k] +=
                    C[k][j] * pwy[k - j] * b.sum[i][j];
            }
        }
        rep(j, 0, L + 1) {
            rrep(i, 0, K + 1) {
                rep(k, i, K + 1) a.sum[k][j] +=
                    C[k][i] * pwx[k - i] * b.sum[i][j];
            }
        }
        a.dx += b.dx;
        a.dy += b.dy;
        return a;
    }
    static FloorPolyMonoid pow(FloorPolyMonoid a, ll n) {
        FloorPolyMonoid ret, base = a;
        while (n) {
            if (n & 1) {
                ret = mul(ret, base);
            }
            base = mul(base, base);
            n >>= 1;
        }
        return ret;
    }
    static FloorPolyMonoid to_dx() {
        FloorPolyMonoid ret;
        ret.sum[0][0] = 1, ret.dx = 1;
        return ret;
    }
    static FloorPolyMonoid to_dy() {
        FloorPolyMonoid ret;
        ret.dy = 1;
        return ret;
    }
};

template <typename T, int K, int L>
vector<vector<T>> ScarySum(ll n, ll m, ll a, ll b) {
    vector ret(K + 1, vector<T>(L + 1));
    if (n <= 0)
        return ret;
    if (m < 0) {
        m = -m, a = -a, b = -b;
    }
    if (a < 0) {
        b = m - 1 - b;
    }
    ll quo = floor(b, m), rem = b - quo * m;
    using M = FloorPolyMonoid<T, K, L>;
    M::init();
    auto base = FloorProd<M>(n, m, llabs(a), rem, M::to_dx(), M::to_dy());
    M offset;
    offset.dy = quo;
    base = M::mul(offset, base);

    rep(i, 0, K + 1) rep(j, 0, L + 1) ret[i][j] = base.sum[i][j];

    if (a < 0) {
        rep(i, 0, K + 1) rep(j, 0, L + 1) if (j & 1) ret[i][j] = -ret[i][j];
    }
    return ret;
}

/**
 * @brief Scary Sum
 */