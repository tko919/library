#define PROBLEM "https://judge.yosupo.jp/problem/many_factorials"

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
#include "FPS/factlarge.hpp"

FastIO io;
void solve(int _rot) {
    // io.write<false>("Case #"+to_string(_rot)+": ");
    int n;
    io.read(n);
    Fp ret = FactLarge<Fp>::fact(n);
    io.write(ret.v);
}

int main() {
    int t;
    io.read(t);
    rep(rot, 0, t) solve(rot + 1);
    return 0;
}