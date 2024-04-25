#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Graph/rerooting.hpp"

int f(int a, int b) {
    return a + b;
}
int g(int a, int v) {
    return a;
}
int h(int a, int b) {
    return max(a, b);
}
int e() {
    return 0;
}

int main() {
    int n;
    read(n);
    Rerooting<int, int, f, g, h, e> tree(n);
    rep(_, 0, n - 1) {
        int x, y;
        io.read(x, y);
        x--;
        y--;
        tree.add_edge(x, y, 1);
    }
    auto ret = tree.run();
    rep(i, 0, n) {
        print(2 * (n - 1) - ret[i]);
    }
    return 0;
}