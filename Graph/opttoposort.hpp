#pragma once
#include "DataStructure/unionfind.hpp"

// root:0, minimize sum_{i<j} w1[q_i]*w0[q_j]
ll OptimalToposort(int n, vector<int> &p, vector<ll> &w0, vector<ll> &w1) {
    struct Node {
        ll zero, one, inv;
        Node(ll z = 0, ll o = 0, ll i = 0) : zero(z), one(o), inv(i) {}
        bool operator<(const Node &other) const {
            return zero * other.one < one * other.zero;
        }
        bool operator!=(const Node &other) const {
            return zero != other.zero or one != other.one;
        }
    };
    using P = pair<Node, int>;
    priority_queue<P> pq;
    UnionFind uni(n);
    vector<Node> info(n);
    rep(i, 0, n) {
        info[i] = Node{w0[i], w1[i], 0};
        if (i)
            pq.push({info[i], i});
    }
    vector<int> head(n);
    iota(ALL(head), 0);
    while (!pq.empty()) {
        auto [pre, x] = pq.top();
        pq.pop();
        if (uni.root(x) != x or pre != info[x])
            continue;
        int par = p[head[x]];
        assert(par != -1);
        par = uni.root(par);
        uni.unite(x, par);
        int nxt = uni.root(x);
        head[nxt] = head[par];
        Node X = info[par], Y = info[x];
        Node cur = {X.zero + Y.zero, X.one + Y.one,
                    X.inv + Y.inv + X.one * Y.zero};
        info[nxt] = cur;
        if (uni.root(0) != nxt) {
            pq.push({info[nxt], nxt});
        }
    }
    return info[uni.root(0)].inv;
};

/**
 * @brief Optimal Topological sort
 */