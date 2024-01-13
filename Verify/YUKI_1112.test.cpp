#define PROBLEM "https://yukicoder.me/problems/no/1112"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "Convolution/arbitrary.hpp"
#include "FPS/arbitraryfps.hpp"
#include "Math/bbla.hpp"
using Fp = fp<>;
template <>
vector<Fp> Poly<Fp>::mult(const vector<Fp> &a, const vector<Fp> &b) const {
    return ArbitraryMult(a, b);
}

FastIO io;
int main() {
    int k, m;
    ll n;
    io.read(k, m, n);
    SparseMatrix<Fp> mat(k * k);
    int p, q, r;
    rep(_, 0, m) {
        io.read(p, q, r);
        p--;
        q--;
        r--;
        mat.add(p * k + q, q * k + r, 1);
    }
    Poly<Fp> b(k * k);
    rep(i, 0, k) b[i * k] = 1;
    auto c = FastPow(mat, b, n - 2);
    Fp ret;
    rep(i, 0, k) ret += c[i];
    io.write(ret.v);
    return 0;
}