#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/blockcut.hpp"

int main() {
    int n, m;
    read(n, m);
    BlockCut buf(n);
    rep(_, 0, m) {
        int u, v;
        read(u, v);
        buf.add_edge(u, v);
    }

    auto ret = buf.run();
    int k = SZ(ret) - n;
    print(k);
    rep(i, 0, k) {
        print(SZ(ret[i + n]));
        print(ret[i + n]);
    }
    return 0;
}