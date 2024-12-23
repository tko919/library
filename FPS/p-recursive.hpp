#pragma once
#include "FPS/samplepointshift.hpp"
#include "Math/matrix.hpp"
#include "Math/linearequation.hpp"

template <typename T>
Matrix<T> PrefixProdOfPolyMatrix(Matrix<Poly<T>> &m, ll K) {
    using Mat = Matrix<T>;

    int n = m.val.size();
    int deg = 1;
    rep(i, 0, n) rep(j, 0, n) chmax(deg, (int)m[i][j].size() - 1);
    ll SQ = 1;
    while (SQ * SQ * deg < K)
        SQ <<= 1;
    T iSQ = T(SQ).inv();

    vector<Mat> G(deg + 1);
    rep(k, 0, deg + 1) {
        G[k] = Mat(n, n);
        rep(i, 0, n) rep(j, 0, n) G[k][i][j] = m[i][j].eval(SQ * k);
    }

    auto process = [&](vector<Mat> &base, T x) -> vector<Mat> {
        int D = base.size();
        vector ret(D, Mat(n, n));
        rep(i, 0, n) rep(j, 0, n) {
            vector<T> val(D);
            rep(k, 0, D) val[k] = base[k][i][j];
            auto add = SamplePointsShift<T>(val, x);
            rep(k, 0, D) ret[k][i][j] = add[k];
        }
        return ret;
    };

    for (ll w = 1; w < SQ; w <<= 1) {
        auto G1 = process(G, iSQ * w);
        auto G2 = process(G, w * deg + 1);
        auto G3 = process(G, iSQ * w + w * deg + 1);
        rep(i, 0, w * deg + 1) G1[i] *= G[i], G3[i] *= G2[i];
        G1.insert(G1.end(), ALL(G3));
        G1.pop_back();
        swap(G, G1);
    }

    Mat ret(n, n);
    rep(i, 0, n) ret[i][i] = 1;
    ll k = 0;
    while (k * SQ + SQ <= K)
        ret = G[k++] * ret;
    k *= SQ;
    while (k < K) {
        Mat mul(n, n);
        rep(i, 0, n) rep(j, 0, n) mul[i][j] = m[i][j].eval(k);
        ret = mul * ret;
        k++;
    }
    return ret;
}

// a_{n+i}*f_n(i)+...+a_i*f_0(i)=0
// {f_r}:dec order!!!
template <typename T> vector<Poly<T>> FindPRecursive(vector<T> &a, int d) {
    int n = a.size();
    int k = (n + 2) / (d + 2) - 1;
    if (k <= 0)
        return {};
    int m = (d + 1) * (k + 1);
    Matrix<T> mat(m - 1, m);
    rep(i, 0, m - 1) rep(j, 0, k + 1) {
        T base = 1;
        rep(deg, 0, d + 1) {
            mat[i][(d + 1) * j + deg] = a[i + j] * base;
            base *= (i + j);
        }
    }
    auto basis = LinearEquation(mat, vector<T>(m - 1)).second;
    if (basis.val.empty())
        return {};
    auto c = basis[0];
    vector<Poly<T>> ret;
    for (int i = 0; i * (d + 1) < (int)c.size(); i++) {
        Poly<T> add, base({T(i), T(1)});
        for (int j = d; j >= 0; j--) {
            add *= base;
            if (c[i * (d + 1) + j] != 0)
                add += c[i * (d + 1) + j];
        }
        ret.push_back(add);
    }
    while (ret.back().empty())
        ret.pop_back();
    reverse(ALL(ret));
    return ret;
}

template <typename T>
vector<T> EnumPRecursive(vector<T> &a, vector<Poly<T>> fs, int n) {
    int sz = SZ(fs) - 1;
    reverse(ALL(fs));
    vector<T> ret = a;
    ret.resize(n);
    rep(i, SZ(a), n) {
        int x = i - sz;
        Fp sum;
        rep(j, 0, sz) if (x + j >= 0) {
            sum -= fs[j].eval(x) * ret[x + j];
        }
        ret[i] = sum / fs[sz].eval(x);
    }
    return ret;
}

template <typename T>
T KthtermOfPRecursive(vector<T> &a, vector<Poly<T>> &fs, ll k) {
    int n = fs.size() - 1;
    assert(int(a.size()) >= n);
    if (k < int(a.size()))
        return a[k];

    Matrix<Poly<T>> m(n), den(1);
    Matrix<T> base(n);
    rep(i, 0, n) m[0][i] = -fs[i + 1];
    rep(i, 1, n) m[i][i - 1] = fs[0];
    den[0][0] = fs[0];
    rep(i, 0, n) base[i][0] = a[n - 1 - i];
    T ret = (PrefixProdOfPolyMatrix(m, k - n + 1) * base)[0][0];
    ret /= PrefixProdOfPolyMatrix(den, k - n + 1)[0][0];
    return ret;
}

template <typename T> T KthtermEsper(vector<T> &a, ll k) {
    if (k < (int)a.size())
        return a[k];
    int n = a.size() - 1;
    vector<Fp> b = a;
    b.pop_back();

    for (int d = 0;; d++) {
        if ((n + 2) / (d + 2) <= 1)
            break;
        auto fs = FindPRecursive(b, d);
        if (KthtermOfPRecursive(b, fs, n) == a.back()) {
            show(fs, SZ(fs));
            return KthtermOfPRecursive(a, fs, k);
        }
    }
    cerr << "esper Failed" << '\n';
    assert(0);
}

/**
 * @brief P-recursive
 */