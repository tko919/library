#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/blockcut.hpp"

FastIO io;
int main() {
    int n, m;
    io.read(n, m);
    BlockCut buf(n);
    rep(_, 0, m) {
        int u, v;
        io.read(u, v);
        buf.add_edge(u, v);
    }

    auto ret = buf.run();
    int k = SZ(ret) - n;
    io.write(k);
    rep(i, 0, k) {
        io.write(SZ(ret[i + n]));
        io.write(ret[i + n]);
    }
    return 0;
}