#pragma once
#include "DataStructure/unionfind.hpp"

struct RangeParallelUF {
    vector<UnionFind> buf;
    RangeParallelUF(int n) {
        int lg = topbit(n) + 2;
        buf.resize(lg);
        rep(i, 0, lg) buf[i] = UnionFind(n);
    }
    template <typename F> void unite(int x, int y, int len, F f) {
        if (len == 0)
            return;
        if (len == 1) {
            inner(x, y, 0, f);
            return;
        }
        int k = topbit(len - 1);
        inner(x, y, k, f);
        inner(x + len - (1 << k), y + len - (1 << k), k, f);
    }

  private:
    template <typename F> void inner(int x, int y, int k, F f) {
        if (k == 0) {
            int a = buf[0].root(x);
            int b = buf[0].root(y);
            if (a == b)
                return;
            buf[0].unite(a, b);
            int c = buf[0].root(x);
            f(c, a ^ b ^ c);
            return;
        }
        if (!buf[k].unite(x, y))
            return;
        inner(x, y, k - 1, f);
        inner(x + (1 << (k - 1)), y + (1 << (k - 1)), k - 1, f);
    }
};

/**
 * @brief Range Parallel UnionFind
 */