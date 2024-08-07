#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Graph/maxflow.hpp"

int main() {
    int n, m;
    read(n, m);
    MaxFlow mf(n);
    rep(i, 0, m) {
        int x, y, w;
        read(x, y, w);
        mf.add_edge(x, y, w);
    }
    auto ret = mf.run(0, n - 1);
    print(ret);
    return 0;
}