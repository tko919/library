#pragma once

template <typename T> struct BIT {
    int n;
    T all = T();
    vector<T> val;
    BIT(int _n = 0) : n(_n), val(_n + 10) {}
    void clear() {
        val.assign(n + 10, T());
        all = T();
    }
    void add(int i, T x) {
        for (i++; i <= n; i += (i & -i))
            val[i] = val[i] + x;
        all += x;
    }
    T sum(int i) {
        i = clamp(i, 0, n);
        T res = T();
        for (; i; i -= (i & -i))
            res += val[i];
        return res;
    }
    // [L,R)
    T sum(int L, int R) {
        if (L > R)
            return T();
        return sum(R) - sum(L);
    }
    // max index s.t. sum[0,i]<=x
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