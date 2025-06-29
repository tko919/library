#define PROBLEM "https://yukicoder.me/problems/no/1781"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/multiplicative.hpp"
#include "Math/modint.hpp"
#include "Math/lucydp.hpp"

ll F(ll x) {
    return x;
}
LucyDP<ll, F> buf;

using Fp = fp<998244353>;
Fp memo[50];
Fp pe(int p, int e) {
    return memo[e];
}
Fp psum(ll x) {
    return memo[1] * buf[x];
}

int main() {
    ll n, m;
    read(n, m);

    rep(e, 0, 45) memo[e] = Fp(e + 1).pow(n);
    buf = LucyDP<ll, F>(m);

    auto ret = MultiplicativeSum<Fp, pe, psum>(m);
    print(ret[m].v);
    return 0;
}