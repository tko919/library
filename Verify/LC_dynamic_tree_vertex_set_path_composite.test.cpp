#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/linkcut.hpp"
#include "Math/modint.hpp"
using Fp = fp<998244353>;
using P = pair<Fp, Fp>;

using Key = P;
struct Monoid {
    P base, inv;
    Monoid() : base({1, 0}), inv({1, 0}) {}
    void inverse() {
        swap(base, inv);
    }
    void merge(Key val, Monoid p, Monoid c) {
        auto f = [&](P x, P y) {
            return P{x.first * y.first, x.second * y.first + y.second};
        };
        base = f(f(p.base, val), c.base);
        inv = f(c.inv, f(val, p.inv));
    }
    void add(Monoid v) {}
    void sub(Monoid v) {}
};
P f(P x, P y) {
    return y;
}
using V = LCT<Monoid, Key, f>::Node *;

FastIO io;
int main() {
    int n, q;
    io.read(n, q);
    LCT<Monoid, Key, f> tree;
    vector<V> vs(n);
    rep(i, 0, n) {
        int a, b;
        io.read(a, b);
        vs[i] = tree.make(i, P{a, b});
    }
    rep(i, 0, n - 1) {
        int x, y;
        io.read(x, y);
        tree.link(vs[x], vs[y]);
    }
    while (q--) {
        int t;
        io.read(t);
        if (t == 0) {
            int x, y;
            io.read(x, y);
            tree.cut(vs[x], vs[y]);
            io.read(x, y);
            tree.link(vs[x], vs[y]);
        }
        if (t == 1) {
            int v, a, b;
            io.read(v, a, b);
            tree.update(vs[v], P{a, b});
        }
        if (t == 2) {
            int u, v, x;
            io.read(u, v, x);
            auto base = tree.query(vs[u], vs[v]).base;
            Fp ret = base.first * x + base.second;
            io.write(ret.v);
        }
    }
    return 0;
}