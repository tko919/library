#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
#include "Math/bbla.hpp"
using Fp = fp<998244353>;
NTT<Fp> ntt;
template <> void Poly<Fp>::NTT(bool inv) {
    ntt.ntt(*this, inv);
}

int main() {
    int n, k;
    read(n, k);
    SparseMatrix<Fp> mat(n);
    int a, b, c;
    rep(_, 0, k) {
        read(a, b, c);
        mat.add(a, b, c);
    }
    Fp ret = FastDet(mat);
    print(ret.v);
    return 0;
}