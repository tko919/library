#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

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

#include "FPS/samplepointshift.hpp"

int main() {
    int n, m;
    Fp c;
    read(n, m, c.v);
    vector<Fp> a(n);
    rep(i, 0, n) read(a[i].v);

    auto ret = SamplePointsShift(a, c, m);
    rep(i, 0, m) print(ret[i].v);
    return 0;
}