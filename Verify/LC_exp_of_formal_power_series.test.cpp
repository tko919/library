#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"

using Fp = fp<998244353>;
NTT<Fp> ntt;
template <> void Poly<Fp>::NTT(vector<Fp> &v, bool inv) const {
    return ntt.ntt(v, inv);
}

int main() {
    int n;
    cin >> n;
    Poly<Fp> a(n);
    rep(i, 0, n) cin >> a[i];
    a = a.exp();
    rep(i, 0, n) cout << a[i] << '\n';
    return 0;
}