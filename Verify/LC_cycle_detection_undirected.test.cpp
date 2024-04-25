#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/cycledetect.hpp"

int main() {
    int n, m;
    read(n, m);

    CycleDetect<0> g(n);
    rep(_, 0, m) {
        int u, v;
        read(u, v);
        g.add_edge(u, v);
    }
    g.run();

    if (g.cycle.empty()) {
        print(-1);
        return 0;
    }
    int k = g.cycle.size();
    print(k);
    auto ret = g.cycle;
    ret.push_back(ret.front());
    rep(i, 0, k) print(ret[i].first);
    rep(i, 1, k + 1) print(ret[i].second);
    return 0;
}