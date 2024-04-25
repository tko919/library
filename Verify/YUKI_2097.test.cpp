#define PROBLEM "https://yukicoder.me/problems/no/2097"

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

#include "FPS/prodoffrkx.hpp"

int main() {
    int n, m, L;
    read(n, m, L);

    Fp two = Fp(2).pow(n).inv();
    Poly<Fp> f(L + 1);
    f[0] = 1;
    rep(i, 1, L + 1) f[i] = Fact<Fp>(i, 1) * two;
    auto ret = ProdOf_f_rk_x(f, Fp(2), m);
    two = Fp(2).pow(ll(n) * m);
    rep(i, 1, L + 1) {
        ret[i] *= Fact<Fp>(i) * two;
        print(ret[i].v);
    }
    return 0;
}