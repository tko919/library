#pragma once

vector<int> hungarian(int n, const vector<vector<ll>> &a) {
    int p, q;
    vector<ll> fx(n, inf), fy(n, 0);
    vector<int> x(n, -1), y(n, -1);
    for (int i = 0; i < n;) {
        vector<ll> t(n, -1), s(n + 1, i);
        for (p = q = 0; p <= q && x[i] < 0; p++) {
            for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {
                if (fx[k] + fy[j] == a[k][j] && t[j] < 0) {
                    s[++q] = y[j], t[j] = k;
                    if (s[q] < 0)
                        for (p = j; p >= 0; j = p) {
                            y[j] = k = t[j], p = x[k], x[k] = j;
                        }
                }
            }
        }
        if (x[i] < 0) {
            ll d = INF;
            rep(k, 0, q + 1) rep(j, 0, n) if (t[j] < 0)
                chmin(d, fx[s[k]] + fy[j] - a[s[k]][j]);
            rep(j, 0, n) fy[j] += (t[j] < 0 ? 0 : d);
            rep(k, 0, q + 1) fx[s[k]] -= d;
        } else
            i++;
    }
    return x;
}

/**
 * @brief Hungarian algorithm
 */