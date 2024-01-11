#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "Convolution/multivariate.hpp"

using Fp = fp<998244353>;
NTT<Fp> ntt;
void F(vector<Fp> &a, bool f) { ntt.ntt(a, f); }

int main() {
    int k, n = 1;
    cin >> k;
    vector<int> a(k);
    rep(i, 0, k) {
        cin >> a[i];
        n *= a[i];
    }
    vector<Fp> f(n), g(n);
    rep(i, 0, n) cin >> f[i];
    rep(i, 0, n) cin >> g[i];

    auto res = MultivariateConvolution<Fp, F>(f, g, a);
    for (auto &x : res)
        cout << x << '\n';
    return 0;
}