#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "Template/template.hpp"
#include "Convolution/fft.hpp"
#include "Graph/centroid.hpp"

int main() {
    int n;
    cin >> n;
    CentroidDecomposition cd(n);
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        cd.add_edge(x, y);
    }
    vector<ll> ret(n);

    auto rec = [&](auto &_rec, int rt) -> void {
        int cen = cd.find(rt);
        cd.used[cen] = 1;
        for (auto &to : cd.g[cen])
            if (!cd.used[to])
                _rec(_rec, to);
        vector<ll> sum, cur;
        auto dfs = [&](auto &f, int v, int p, int d) -> void {
            if ((int)cur.size() <= d)
                cur.resize(d + 1);
            cur[d]++;
            for (auto &to : cd.g[v])
                if (to != p and !cd.used[to])
                    f(f, to, v, d + 1);
        };
        for (auto &to : cd.g[cen])
            if (!cd.used[to]) {
                cur.clear();
                dfs(dfs, to, cen, 1);
                auto sub = FFT::square(cur);
                rep(i, 0, min((int)sub.size(), n)) ret[i] -= sub[i];
                if (sum.size() < cur.size())
                    sum.resize(cur.size());
                rep(i, 0, cur.size()) sum[i] += cur[i];
            }
        rep(i, 0, min((int)sum.size(), n)) ret[i] += sum[i] * 2;
        auto add = FFT::square(sum);
        rep(i, 0, min((int)add.size(), n)) ret[i] += add[i];
        cd.used[cen] = 0;
    };
    rec(rec, 0);
    rep(i, 1, n) {
        ret[i] >>= 1;
        cout << ret[i] << '\n';
    }
    return 0;
}