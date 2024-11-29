#pragma once

struct StaticTopTree {
    using T = array<int, 4>;
    vector<vector<int>> g;
    vector<T> tree; // {par,L,R,type 0:rake,1:compress,2:vertex}
    int n, rt;
    StaticTopTree() {}
    StaticTopTree(int n) : n(n), g(n), tree(n) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void run(int base = 0) {
        dfs(base, -1);
        rt = build(base).first;
    }
    void dump() {
        rep(v, 0, SZ(tree)) {
            auto [par, L, R, type] = tree[v];
            show(v, par, L, R, type);
        }
    }

  private:
    int dfs(int v, int p) {
        rep(i, 0, SZ(g[v])) if (g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
            break;
        }
        int sz = 1, best = 0;
        for (auto &to : g[v]) {
            int add = dfs(to, v);
            sz += add;
            if (chmax(best, add))
                swap(to, g[v].front());
        }
        return sz;
    }
    using P = pair<int, int>; // {ID,size}
    int make(int v, int L, int R, int type) {
        if (v == -1) {
            v = SZ(tree);
            tree.push_back({-1, L, R, type});
        } else {
            tree[v] = {-1, L, R, type};
        }
        if (L != -1)
            tree[L][0] = v;
        if (R != -1)
            tree[R][0] = v;
        return v;
    }
    P merge(vector<P> a, int type) {
        if (SZ(a) == 1)
            return a[0];
        int sum = 0;
        for (auto &[_, sz] : a)
            sum += sz;
        vector<P> L, R;
        for (auto &[v, sz] : a) {
            if (sum > sz)
                L.push_back({v, sz});
            else
                R.push_back({v, sz});
            sum -= sz * 2;
        }
        auto [lb, ls] = merge(L, type);
        auto [rb, rs] = merge(R, type);
        return P{make(-1, lb, rb, type), ls + rs};
    }
    P build(int v) {
        int cur = v, pre = -1;
        vector<P> a;
        for (;;) {
            // rake
            vector<P> b;
            b.push_back({make(cur, -1, -1, 2), 1});
            if (pre != -1) {
                assert(g[pre][0] == cur);
                for (auto &to : g[pre])
                    if (to != cur) {
                        b.push_back(build(to));
                    }
            }
            a.push_back(merge(b, 0));
            if (SZ(g[cur]) == 0)
                break;
            pre = cur, cur = g[cur][0];
        }
        return merge(a, 1);
    }
};

/**
 * rake: (a<-b], (a<-c] -> (a<-b].
 * compress: (a<-b], (b<-c] -> (a<-c].
 */
template <typename M, M (*rake)(M, M), M (*compress)(M, M)>
struct DynamicTreeDP {
    int n, sz;
    StaticTopTree stt;
    vector<M> dat;
    DynamicTreeDP() {}
    template <typename F>
    DynamicTreeDP(int n, StaticTopTree _stt, F vertex)
        : n(n), sz(SZ(_stt.tree)), stt(_stt), dat(sz) {
        rep(i, 0, n) dat[i] = vertex(i);
        rep(i, n, sz) update(i);
    }
    void set(int v, M x) {
        dat[v] = x;
        for (int p = stt.tree[v][0]; p != -1; p = stt.tree[p][0])
            update(p);
    }
    M get() {
        return dat.back();
    }

  private:
    void update(int v) {
        auto L = dat[stt.tree[v][1]];
        auto R = dat[stt.tree[v][2]];
        if (stt.tree[v][3]) {
            dat[v] = compress(L, R);
        } else {
            dat[v] = rake(L, R);
        }
    }
};

/**
 * rake1: (a<-b], (a<-c] -> (a<-b].
 * rake2: (a->b], (a<-c] -> (a->b].
 * compress: (a<-b], (b<-c] -> (a<-c].
 */
template <typename M, M (*rake1)(M, M), M (*rake2)(M, M), M (*compress)(M, M),
          M (*e)()>
struct DynamicRerootingDP {
    int n, sz;
    StaticTopTree stt;
    using P = pair<M, M>;
    vector<P> dat; // {ord,rev}
    DynamicRerootingDP() {}
    template <typename F>
    DynamicRerootingDP(int n, StaticTopTree _stt, F vertex)
        : n(n), sz(SZ(_stt.tree)), stt(_stt), dat(sz) {
        dat[0] = {e(), e()};
        rep(i, 1, n) dat[i] = vertex(i);
        rep(i, n, sz) update(i);
    }
    void set(int v, P x) {
        dat[v] = x;
        for (int p = stt.tree[v][0]; p != -1; p = stt.tree[p][0])
            update(p);
    }
    M get(int v) {
        // a: expose cur to v (down)
        // b: expose from cur (down)
        // c: expose to cur (up)
        int cur = v;
        M a = dat[cur].second, b = e(), c = e();
        for (;;) {
            int p = stt.tree[cur][0];
            if (p == -1)
                break;
            int L = stt.tree[p][1], R = stt.tree[p][2];
            if (stt.tree[p][3]) {
                if (L == cur)
                    b = compress(b, dat[R].first);
                else
                    a = compress(a, dat[L].second);
            } else {
                if (L == cur) {
                    a = rake2(a, dat[R].first);
                } else {
                    c = compress(c, rake1(a, b));
                    a = e();
                    b = dat[L].first;
                }
            }
            cur = p;
        }
        return compress(c, rake1(a, b));
    }

  private:
    void update(int v) {
        auto [L, Lre] = dat[stt.tree[v][1]];
        auto [R, Rre] = dat[stt.tree[v][2]];
        if (stt.tree[v][3]) {
            dat[v] = P{compress(L, R), compress(Rre, Lre)};
        } else {
            dat[v] = P{rake1(L, R), rake2(Lre, R)};
        }
    }
};

/**
 * @brief Static TopTree
 */