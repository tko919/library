#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

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

#include "FPS/famous.hpp"

int main() {
    int n;
    read(n);

    auto ret = Partition<Fp>(n);
    rep(i, 0, ret.size()) print(ret[i].v);
    return 0;
}