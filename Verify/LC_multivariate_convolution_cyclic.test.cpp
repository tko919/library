#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/multivariate_convolution_cyclic"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/dynamic.hpp"
#include "Convolution/arbitrary.hpp"
#include "FPS/arbitraryfps.hpp"
template <>
vector<Fp> Poly<Fp>::mult(const vector<Fp> &a, const vector<Fp> &b) const {
    return ArbitraryMult<Fp>(a, b);
}
#include "Convolution/multivariatecyclic.hpp"

FastIO io;
int main() {
    int p, k;
    io.read(p, k);
    Fp::set_mod(p);
    vector<int> a(k);
    io.read(a);
    int n = 1;
    for (auto &x : a)
        n *= x;
    vector<Fp> f(n), g(n);
    rep(i, 0, n) io.read(f[i].v);
    rep(i, 0, n) io.read(g[i].v);

    auto ret = MultivariateCyclic(f, g, a);
    rep(i, 0, n) io.write(ret[i].v);
    return 0;
}
