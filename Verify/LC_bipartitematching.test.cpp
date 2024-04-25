#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "Template/template.hpp"
#include "Graph/bimatching.hpp"
#include "Utility/fastio.hpp"

int main() {
    int L, R, m;
    read(L, R, m);
    vector g(L, vector<int>());
    rep(_, 0, m) {
        int x, y;
        read(x, y);
        g[x].push_back(y);
    }
    auto ret = BiMatching(L, R, g);

    int sz = 0;
    rep(i, 0, L) if (ret[i] != -1) sz++;
    print(sz);
    rep(i, 0, L) if (ret[i] != -1) {
        print(i, ret[i]);
    }
    return 0;
}