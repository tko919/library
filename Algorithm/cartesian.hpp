#pragma once

template <typename T> vector<int> Cartesian(const vector<T> &a) {
    const int n = a.size();
    vector<int> res(n, -1);
    int cur;
    rep(i, 1, n) {
        cur = i - 1;
        if (a[cur] > a[i]) {
            int pre = cur;
            while (cur != -1 and a[cur] > a[i])
                pre = cur, cur = res[cur];
            if (cur == -1) {
                res[i] = -1;
                res[pre] = i;
            } else {
                res[i] = cur;
                res[pre] = i;
            }
        } else
            res[i] = cur;
    }
    return res;
}

/**
 * @brief Cartesian Tree
 * @docs docs/cartesian.md
 */