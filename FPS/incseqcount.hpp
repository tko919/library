#pragma once
#include "Math/comb.hpp"

template <typename T>
T NumberofIncreasingSequencesBetweenTwoSequences(int n, vector<int> a,
                                                 vector<int> b) {
    auto step = [&](int n, vector<int> a, vector<T> &init) -> vector<T> {
        auto rec = [&](auto &self, int L, int R, vector<T> &dp) -> vector<T> {
            assert(SZ(dp) == R - L);
            if (R - L == 1) {
                vector<T> ret(a[L], dp[0]);
                return ret;
            }
            int mid = (L + R) >> 1;
            int offset = a[mid - 1];
            vector<T> Ldp = {dp.begin(), dp.begin() + mid - L};
            vector<T> Lret = self(self, L, mid, Ldp);

            int sz = a[R - 1];
            vector<T> ret(sz);
            vector<T> Rdp(R - mid);
            if (offset == 0) {
                rep(i, 0, R - mid) Rdp[i] = dp[i + mid - L];
            } else {
                {
                    Poly<T> X(offset), Y(R - mid + offset);
                    rep(j, 0, offset) X[j] =
                        Lret[j] * Fact<T>(offset - 1 - j, 1);
                    rep(k, 0, R - mid + offset) Y[k] = Fact<T>(k);
                    X *= Y;
                    rep(i, 0, R - mid) Rdp[i] +=
                        X[i + offset - 1] * Fact<T>(i, 1);
                }
                {
                    Poly<T> X(offset), Y(offset);
                    rep(j, 0, offset) X[j] = Lret[j];
                    rep(k, 0, offset) Y[k] = nCr<T>(R - mid - 1 + k, k);
                    X *= Y;
                    rep(i, 0, offset) ret[i] += X[i];
                }
                {
                    Poly<T> X(R - mid), Y(R - mid);
                    rep(j, 0, R - mid) X[j] = dp[j + mid - L];
                    rep(j, 0, R - mid) Y[j] = nCr<T>(j + offset - 1, j);
                    X *= Y;
                    rep(i, 0, R - mid) Rdp[i] += X[i];
                }
                {
                    Poly<T> X(R - mid), Y(offset + R - mid);
                    rep(j, 0, R - mid) X[j] =
                        dp[j + mid - L] * Fact<T>(R - mid - 1 - j, 1);
                    rep(k, 0, offset + R - mid) Y[k] = Fact<T>(k);
                    X *= Y;
                    rep(i, 0, offset) ret[i] +=
                        X[R - mid - 1 + i] * Fact<T>(i, 1);
                }
            }
            rep(j, mid, R) a[j] -= offset;
            vector<T> Rret = self(self, mid, R, Rdp);
            rep(j, offset, sz) ret[j] = Rret[j - offset];
            return ret;
        };
        auto ret = rec(rec, 0, n, init);
        rrep(j, 0, SZ(ret) - 1) ret[j + 1] -= ret[j];
        return ret;
    };

    rep(i, 0, n - 1) chmax(a[i + 1], a[i]);
    rrep(i, 0, n - 1) chmin(b[i], b[i + 1]);
    rep(i, 0, n) if (a[i] >= b[i]) {
        return 0;
    }
    int offset = a.front();
    for (auto &x : a)
        x -= offset;
    for (auto &x : b)
        x -= offset + 1;
    a.insert(a.begin(), 0);
    b.push_back(b.back());

    bool vert = 1;
    vector<T> dp(b[0] + 1);
    dp[0] = 1;
    int x = 0, y = 0;
    for (;;) {
        if (x == n and y == b.back())
            break;
        if (vert) {
            // up
            vector<int> H;
            for (;;) {
                int add = UB(a, y) - x;
                H.push_back(add);
                if (y == b[x])
                    break;
                y++;
            }
            assert(SZ(dp) == SZ(H));
            auto nxt = step(SZ(H), H, dp);
            swap(dp, nxt);
        } else {
            // right
            vector<int> H;
            for (;;) {
                int add = b[x] - y + 1;
                H.push_back(add);
                if (x == n or y < a[x + 1])
                    break;
                x++;
            }
            assert(SZ(dp) == SZ(H));
            auto nxt = step(SZ(H), H, dp);
            swap(dp, nxt);
        }
        vert ^= 1;
    }
    return accumulate(ALL(dp), T(0));
}

/**
 * @brief Number of Increasing Sequences Between Two Sequences
 */