#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

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

#include "FPS/famous.hpp"

FastIO io;
int main() {
    int n;
    io.read(n);

    auto ret = Bernoulli<Fp>(n);
    rep(i, 0, ret.size()) io.write(ret[i].v);
    return 0;
}