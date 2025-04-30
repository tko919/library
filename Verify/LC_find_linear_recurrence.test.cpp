#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "FPS/berlekampmassey.hpp"

using Fp = fp<998244353>;

int main() {
    int n;
    cin >> n;
    vector<Fp> a(n);
    rep(i, 0, n) cin >> a[i];

    auto ret = BerlekampMassey(a);
    ret.pop_back();
    for (auto &x : ret)
        x = -x;

    int m = ret.size();
    cout << m << '\n';
    rep(i, 0, m) cout << ret[i] << (i == m - 1 ? '\n' : ' ');
    return 0;
}