#pragma once

template <typename T> struct WeightedUnionFind {
    int n;
    vector<int> par;
    vector<T> pot;
    WeightedUnionFind(int _n = 0) : n(_n), par(n, -1), pot(n) {}
    int root(int x) {
        if (par[x] < 0)
            return x;
        else {
            int r = root(par[x]);
            pot[x] = pot[par[x]] + pot[x];
            return par[x] = r;
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return -par[root(x)];
    }
    T diff(int x, int y) {
        root(x);
        root(y);
        return -pot[y] + pot[x];
    }
    bool unite(int x, int y, T w) {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        if (par[rx] < par[ry])
            swap(x, y), swap(rx, ry), w = -w;
        par[ry] += par[rx];
        par[rx] = ry;
        pot[rx] = pot[y] + w - pot[x];
        n--;
        return true;
    }
};

/**
 * @brief Weighted Union Find
 */