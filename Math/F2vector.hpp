#pragma once

vector<int> Intersection(vector<int> &X, vector<int> &Y) {
    vector<int> Xb, Yb;
    for (auto x : X) {
        for (auto &b : Xb)
            chmin(x, x ^ b);
        if (x)
            Xb.push_back(x);
    }
    for (auto y : Y) {
        for (auto &b : Yb)
            chmin(y, y ^ b);
        if (y)
            Yb.push_back(y);
    }

    vector<ll> A(SZ(Xb) + SZ(Yb));
    rep(i, 0, SZ(Xb)) A[i] = ll(Xb[i]) << 30 | Xb[i];
    rep(i, 0, SZ(Yb)) A[SZ(Xb) + i] = ll(Yb[i]);
    int rank = 0;
    rep(k, 0, 30) {
        if (rank == SZ(A))
            break;
        rep(i, rank, SZ(A)) {
            if (A[i] >> k & 1) {
                swap(A[rank], A[i]);
                break;
            }
        }
        if (!(A[rank] >> k & 1))
            continue;
        rep(j, 0, SZ(A)) if (j != rank) {
            if (A[j] >> k & 1)
                A[j] ^= A[rank];
        }
        rank++;
    }
    vector<int> ret;
    rep(i, rank, SZ(A)) {
        int add = A[i] >> 30;
        if (add)
            ret.push_back(add);
    }
    return ret;
}

template <typename T> vector<T> inverse(vector<T> &a) {
    int n = SZ(a);
    vector<T> b(n);
    rep(i, 0, n) b[i][i] = 1;

    rep(i, 0, n) {
        rep(k, i + 1, n) if (a[k][i]) {
            swap(a[k], a[i]);
            swap(b[k], b[i]);
        }
        if (!a[i][i]) {
            print(-1);
            return 0;
        }
        rep(k, 0, n) if (k != i and a[k][i]) {
            a[k] ^= a[i];
            b[k] ^= b[i];
        }
    }
    return b;
}

/**
 * @brief $\mathbb{F}_2$ vector
 */