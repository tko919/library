#pragma once

template <typename T> struct BIT {
    int n;
    T all = 0;
    vector<T> val;
    BIT(int _n = 0) : n(_n), val(_n + 10) {}
    void clear() {
        val.assign(n + 10, 0);
        all = T();
    }
    void add(int i, T x) {
        for (i++; i <= n; i += (i & -i))
            val[i] = val[i] + x;
        all += x;
    }
    T sum(int i) {
        i = clamp(i, 0, n);
        T res = 0;
        for (; i; i -= (i & -i))
            res += val[i];
        return res;
    }
    // [L,R)
    T sum(int L, int R) {
        if (L > R)
            return T(0);
        return sum(R) - sum(L);
    }
    int lower_bound(T x) {
        int ret = 0, len = 1;
        while (2 * len <= n)
            len <<= 1;
        for (; len >= 1; len >>= 1) {
            if (ret + len <= n and val[ret + len] < x) {
                ret += len;
                x -= val[ret];
            }
        }
        return ret;
    }
};

/**
 * @brief Binary Indexed Tree
 */