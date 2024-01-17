#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/linkcut.hpp"

using Key = ll;
struct Monoid {
    ll sum, psum, csum, light;
    Monoid() : sum(0), psum(0), csum(0), light(0) {}
    void inverse() {
        swap(psum, csum);
    }
    void merge(Key val, Monoid p, Monoid c) {
        sum = p.sum + c.sum + val + light;
        psum = p.psum + val + light;
        csum = c.csum + val + light;
    }
    void add(Monoid v) {
        light += v.sum;
    }
    void sub(Monoid v) {
        light -= v.sum;
    }
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
            io.write(ret.csum);
        }
    }
    return 0;
}