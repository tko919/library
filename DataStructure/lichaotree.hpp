#pragma once

template <typename T, T MX> struct CHT {
    using Line = pair<T, T>;
    int n;
    vector<T> xs;
    vector<Line> ls;
    CHT() {}
    CHT(vector<T> &ps) {
        xs = ps;
        UNIQUE(xs);
        n = 1;
        while (n < (int)xs.size())
            n <<= 1;
        xs.resize(n, xs.back());
        ls.resize(2 * n - 1, Line(0, MX));
    }
    T eval(Line &f, T x) {
        return f.first * x + f.second;
    }
    void add(T a, T b, int k = 0, int L = 0, int R = -1) {
        if (R == -1)
            R = n;
        Line f = {a, b};
        while (L != R) {
            int mid = (L + R) >> 1;
            T lx = xs[L], mx = xs[mid], rx = xs[R - 1];
            Line &g = ls[k];
            if (eval(f, lx) < eval(g, lx) and eval(f, rx) < eval(g, rx)) {
                g = f;
                return;
            }
            if (eval(f, lx) >= eval(g, lx) and eval(f, rx) >= eval(g, rx))
                return;
            if (eval(f, mx) < eval(g, mx))
                swap(f, g);
            if (eval(f, lx) < eval(g, lx)) {
                k = k * 2 + 1;
                R = mid;
            } else {
                k = k * 2 + 2;
                L = mid;
            }
        }
    }
    void add_segment(T a, T b, T L, T R) {
        int l = lower_bound(ALL(xs), L) - xs.begin(),
            r = lower_bound(ALL(xs), R) - xs.begin();
        int a0 = l, b0 = r;
        l += n, r += n;
        int sz = 1;
        while (l < r) {
            if (r & 1) {
                r--;
                b0 -= sz;
                add(a, b, r - 1, b0, b0 + sz);
            }
            if (l & 1) {
                add(a, b, l - 1, a0, a0 + sz);
                l++;
                a0 += sz;
            }
            l >>= 1;
            r >>= 1;
            sz <<= 1;
        }
    }
    T getmin(T x) {
        int k = lower_bound(ALL(xs), x) - xs.begin() + n - 1;
        T res = eval(ls[k], x);
        while (k) {
            k = (k - 1) >> 1;
            chmin(res, eval(ls[k], x));
        }
        return res;
    }
};

/**
 * @brief Convex Hull Trick (Li Chao Tree)
 * @docs docs/lichaotree.md
 */