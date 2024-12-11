#pragma once

template <typename M, typename N, M (*f)(M, M), M (*g)(M, N, int), N (*h)(N, N),
          M (*m1)(), N (*n1)()>
class LazyKdTree {
    using P = pair<int, int>;
    using T = pair<pair<int, int>, pair<M, int>>; // {{x,y},{w,id}}
    struct Node {
        int L, R, D, U;
        int sz;
        M val;
        N lazy;
        Node()
            : L(inf), R(-inf), D(inf), U(-inf), sz(0), val(m1()), lazy(n1()) {}
        Node(P &p, M v)
            : L(p.first), R(p.first), D(p.second), U(p.second), val(v),
              lazy(n1()) {}
    };

    int n, height;
    vector<Node> data;
    vector<int> pos;
    void update(int k) {
        data[k].sz += data[k * 2].sz + data[k * 2 + 1].sz;
        data[k].L = min(data[k * 2].L, data[k * 2 + 1].L);
        data[k].R = max(data[k * 2].R, data[k * 2 + 1].R);
        data[k].D = min(data[k * 2].D, data[k * 2 + 1].D);
        data[k].U = max(data[k * 2].U, data[k * 2 + 1].U);
        data[k].val = f(data[k * 2].val, data[k * 2 + 1].val);
    }
    void apply(int k, N x) {
        data[k].val = g(data[k].val, x, data[k].sz);
        data[k].lazy = h(data[k].lazy, x);
    }
    void down(int k) {
        apply(k * 2, data[k].lazy);
        apply(k * 2 + 1, data[k].lazy);
        data[k].lazy = n1();
    }
    void build(vector<T> &ps, int L, int R, bool dir) {
        if (R - L == 1) {
            data[n + L] = Node(ps[L].first, ps[L].second.first);
            if (ps[L].second.second != n)
                pos[ps[L].second.second] = L;
            return;
        }
        int mid = (L + R) >> 1;
        if (dir) {
            nth_element(ps.begin() + L, ps.begin() + mid, ps.begin() + R,
                        [&](const auto &a, const auto &b) {
                            return a.first.first < b.first.first;
                        });
        } else {
            nth_element(ps.begin() + L, ps.begin() + mid, ps.begin() + R,
                        [&](const auto &a, const auto &b) {
                            return a.first.second < b.first.second;
                        });
        }
        build(ps, L, mid, !dir);
        build(ps, mid, R, !dir);
    }

  public:
    LazyKdTree() {}
    LazyKdTree(const vector<int> &xs, const vector<int> &ys,
               const vector<M> &ws) {
        height = 0;
        while ((1 << height) < SZ(xs))
            height++;
        n = 1 << height;
        data.resize(n * 2);
        vector<T> ps(n, {{inf, inf}, {m1(), n}});
        rep(i, 0, SZ(xs)) {
            ps[i] = T{{xs[i], ys[i]}, {ws[i], i}};
        }
        pos.resize(n, -1);
        build(ps, 0, n, 0);
        rrep(i, 1, n) update(i);
    }
    void set(int k, M x) {
        k = n + pos[k];
        rrep(i, 1, height + 1) down(k >> i);
        data[k].val = x;
        rep(i, 1, height + 1) update(k >> i);
    }
    void update(int L, int R, int D, int U, N x, int k = 1) {
        if (data[k].R < L or R <= data[k].L or data[k].U < D or U <= data[k].D)
            return;
        if (L <= data[k].L and data[k].R < R and D <= data[k].D and
            data[k].U < U) {
            apply(k, x);
            return;
        }
        down(k);
        update(L, R, D, U, x, k * 2);
        update(L, R, D, U, x, k * 2 + 1);
        update(k);
    }
    M query(int L, int R, int D, int U, int k = 1) {
        if (data[k].R < L or R <= data[k].L or data[k].U < D or U <= data[k].D)
            return m1();
        if (L <= data[k].L and data[k].R < R and D <= data[k].D and
            data[k].U < U) {
            return data[k].val;
        }
        down(k);
        return f(query(L, R, D, U, k * 2), query(L, R, D, U, k * 2 + 1));
    }
};

/**
 * @brief Kd Tree
 */