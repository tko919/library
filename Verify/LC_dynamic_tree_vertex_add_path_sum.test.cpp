#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/linkcut.hpp"

using Key = ll;
struct Monoid {
    ll sum;
    Monoid() : sum(0) {}
    void inverse() {}
    void merge(Key val, Monoid p, Monoid c) {
        sum = p.sum + c.sum + val;
    }
    void add(Monoid v) {}
    void sub(Monoid v) {}
};
ll f(ll x, ll y) {
    return x + y;
}
using V = LCT<Monoid, Key, f>::Node *;

FastIO io;
int main() {
    int n, q;
    io.read(n, q);
    LCT<Monoid, Key, f> tree;
    vector<V> vs(n);
    rep(i, 0, n) {
        ll x;
        io.read(x);
        vs[i] = tree.make(i, x);
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
            int v, x;
            io.read(v, x);
            tree.update(vs[v], x);
        }
        if (t == 2) {
            int v, p;
            io.read(v, p);
            auto ret = tree.query(vs[p], vs[v]);
            io.write(ret.sum);
        }
    }
    return 0;
}