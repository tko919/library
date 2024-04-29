#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

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
#include "Convolution/relax.hpp"

int main() {
    int n, m;
    read(n, m);
    vector<Fp> _f(n), _g(m);
    rep(i, 0, n) read(_f[i].v);
    rep(i, 0, m) read(_g[i].v);
    RelaxedConvolution<Fp> buf(n + m - 1);
    rep(i, 0, n + m - 1) {
        Fp x, y;
        if (i < n)
            x = _f[i];
        if (i < m)
            y = _g[i];
        Fp ret = buf.next(x, y);
        print(ret.v);
    }
    return 0;
}
