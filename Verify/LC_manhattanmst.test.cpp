#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "DataStructure/manhattanmst.hpp"

int main() {
    int n;
    read(n);
    vector<ll> x(n), y(n);
    rep(i, 0, n) read(x[i], y[i]);
    auto ret = ManhattanMST(x, y);
    print(ret.first);
    for (auto &[u, v] : ret.second)
        print(u, v);
    return 0;
}