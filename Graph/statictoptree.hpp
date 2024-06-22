#pragma once

template <typename Path, typename Point, Path (*vertex)(int),
          Path (*compress)(Path, Path), Point (*rake)(Point, Point),
          Point (*add_edge)(Path), Path (*add_vertex)(Point, int)>
struct StaticTopTree {
    enum Type { Vertex, Compress, Rake, AddEdge, AddVertex };
    struct Node {
        int par, lp, rp;
        Type t;
        Node() {}
        Node(int _p, int _l, int _r, Type _t)
            : par(_p), lp(_l), rp(_r), t(_t) {}
    };
    vector<vector<int>> g;
    vector<Node> vs;
    vector<Path> path;
    vector<Point> point;
    int rt;
    StaticTopTree() {}
    StaticTopTree(int n) : g(n), vs(n) {}
    void push(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void run(int base) {
        _dfs(base, -1);
        auto [v, _] = _compress(base);
        rt = v;
        path.resize(SZ(vs));
        point.resize(SZ(vs));
        _calc(rt);
    }
    void update(int v) {
        while (v != -1) {
            _update(v);
            v = vs[v].par;
        }
    }
    Path get_root() const {
        return path[rt];
    }

  private:
    int _make(int k, int L, int R, Type t) {
        Node add(-1, L, R, t);
        if (k == -1) {
            k = SZ(vs);
            vs.push_back(add);
        } else
            vs[k] = add;
        if (L != -1)
            vs[L].par = k;
        if (R != -1)
            vs[R].par = k;
        return k;
    }
    int _dfs(int v, int p) {
        rep(i, 0, SZ(g[v])) if (g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
            break;
        }
        int sz = 1, best = 0;
        for (auto &to : g[v]) {
            int add = _dfs(to, v);
            sz += add;
            if (chmax(best, add))
                swap(to, g[v].front());
        }
        return sz;
    }

    using P = pair<int, int>;
    P _merge(const vector<P> &a, Type t) {
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
        auto [lb, slb] = _merge(L, t);
        auto [rb, srb] = _merge(R, t);
        return {_make(-1, lb, rb, t), slb + srb};
    }
    P _compress(int v) {
        vector<P> cs{_add_vertex(v)};
        while (!g[v].empty())
            cs.push_back(_add_vertex(v = g[v].front()));
        return _merge(cs, Type::Compress);
    }
    P _rake(int v) {
        vector<P> cs;
        rep(j, 1, SZ(g[v])) cs.push_back(_add_edge(g[v][j]));
        return cs.empty() ? P{-1, 0} : _merge(cs, Type::Rake);
    }
    P _add_edge(int v) {
        auto [to, sz] = _compress(v);
        return P{_make(-1, to, -1, Type::AddEdge), sz};
    }
    P _add_vertex(int v) {
        auto [to, sz] = _rake(v);
        return P{_make(v, to, -1, to == -1 ? Type::Vertex : Type::AddVertex),
                 sz + 1};
    }
    void _update(int v) {
        if (vs[v].t == StaticTopTree::Type::Vertex) {
            path[v] = vertex(v);
        }
        if (vs[v].t == StaticTopTree::Type::Compress) {
            path[v] = compress(path[vs[v].lp], path[vs[v].rp]);
        }
        if (vs[v].t == StaticTopTree::Type::Rake) {
            point[v] = rake(point[vs[v].lp], point[vs[v].rp]);
        }
        if (vs[v].t == StaticTopTree::Type::AddVertex) {
            path[v] = add_vertex(point[vs[v].lp], v);
        }
        if (vs[v].t == StaticTopTree::Type::AddEdge) {
            point[v] = add_edge(path[vs[v].lp]);
        }
    }
    void _calc(int v) {
        if (vs[v].lp != -1)
            _calc(vs[v].lp);
        if (vs[v].rp != -1)
            _calc(vs[v].rp);
        _update(v);
    }
};

/**
 * @brief Static TopTree
 */