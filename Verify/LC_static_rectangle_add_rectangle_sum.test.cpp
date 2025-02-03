#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
using Fp = fp<998244353>;

#include "DataStructure/staticrectaddrectsum.hpp"

int main() {
    int n, q;
    read(n, q);

    StaticRectangleAddRectangleSum<int, Fp> buf;
    rep(i, 0, n) {
        int L, D, R, U, w;
        read(L, D, R, U, w);
        buf.add(L, D, R, U, w);
    }
    rep(i, 0, q) {
        int L, D, R, U;
        read(L, D, R, U);
        buf.query(L, D, R, U);
    }
    auto ret = buf.run();
    rep(i, 0, q) print(ret[i].v);
    return 0;
}