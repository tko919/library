#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
using Fp = fp<998244353>;
#include "Math/dirichlet.hpp"

int main() {
    ll n;
    read(n);

    Dirichlet<Fp, 1> phi(n), one(n);
    rep(d, 1, phi.P + 1) phi.a[d] = d;
    rep(d, 1, phi.Q + 1) {
        Fp x = n / d;
        phi.A[d] = x * (x + 1) / 2;
    }
    rep(d, 1, one.P + 1) one.a[d] = 1;
    rep(d, 1, one.Q + 1) one.A[d] = n / d;
    phi.ruith();
    one.ruith();

    phi = phi / one;
    cout << phi[n] << '\n';
    return 0;
}