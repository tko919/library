#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"

using Fp = fp<998244353>;
NTT<Fp> ntt;
template <> void Poly<Fp>::NTT(vector<Fp> &v, bool inv) const {
    return ntt.ntt(v, inv);
}

int main() {
    int n, c;
    cin >> n >> c;
    Poly<Fp> a(n);
    for (auto &x : a)
        cin >> x;
    a = a.shift(c);
    rep(i, 0, n) cout << a[i] << '\n';
    return 0;
}