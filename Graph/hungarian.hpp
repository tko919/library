#pragma once

template <typename T, T MX> vector<int> Hungarian(int n, vector<vector<T>> &A) {
    vector<int> u(n + 1), v(n + 1), q(n + 1, n), way(n + 1, n);
    for (int i = 0; i < n; ++i) {
        q[n] = i;
        int j0 = n;
        vector<T> minv(n + 1, MX);
        vector<bool> used(n + 1, false);
        do {
            used[j0] = true;
            int i0 = q[j0], j1 = n;
            T delta = MX;
            for (int j = 0; j < n; ++j)
                if (!used[j]) {
                    T cur = A[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for (int j = 0; j <= n; ++j)
                if (used[j])
                    u[q[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (q[j0] != n);
        do {
            int j1 = way[j0];
            q[j0] = q[j1];
            j0 = j1;
        } while (j0 != n);
    }
    vector<int> p(n);
    rep(i, 0, n) p[q[i]] = i;
    return p;
}

/**
 * @brief Hungarian algorithm
 */