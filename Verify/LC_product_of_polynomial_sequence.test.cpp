#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

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

#include "FPS/prodofpolys.hpp"

FastIO io;
int main() {
    int n;
    io.read(n);
    vector<Poly<Fp>> fs(n);
    rep(i, 0, n) {
        int m;
        io.read(m);
        fs[i] = Poly<Fp>(m + 1);
        rep(j, 0, m + 1) io.read(fs[i][j].v);
    }

    auto ret = ProdOfPolys(fs);
    rep(i, 0, ret.size()) io.write(ret[i].v);
    return 0;
}