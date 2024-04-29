#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"

using Fp = fp<998244353>;
NTT<Fp> ntt;
template <> void Poly<Fp>::NTT(bool inv) {
    ntt.ntt(*this, inv);
}

int main() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    Poly<Fp> a(n);
    rep(i, 0, n) cin >> a[i];
    a = a.pow(k);
    rep(i, 0, n) cout << a[i] << '\n';
    return 0;
}