#pragma once
#include "Math/matrix.hpp"

template <typename T, typename U>
T UndirectedCountSpanningTree(vector<vector<pair<int, U>>> &g) {
    int n = SZ(g);
    Matrix<T> mat(n - 1, n - 1);
    rep(u, 0, n) for (auto &[v, mul] : g[u]) {
        if (u != n - 1)
            mat[u][u] += mul;
        if (v != n - 1)
            mat[v][v] += mul;
        if (u != n - 1 and v != n - 1) {
            mat[u][v] -= mul;
            mat[v][u] -= mul;
        }
    }
    mat.gauss();
    return mat.det;
}

template <typename T, typename U>
T DirectedCountSpanningTree(vector<vector<pair<int, U>>> &g, int r) {
    int n = SZ(g);
    Matrix<T> mat(n - 1, n - 1);
    rep(u, 0, n) for (auto &[v, mul] : g[u]) {
        if (v == r)
            continue;
        if (v > r)
            v--;
        mat[v][v] += mul;
        if (u == r)
            continue;
        if (u > r)
            u--;
        mat[u][v] -= mul;
    }
    mat.gauss();
    return mat.det;
}

/**
 * @brief Counting Spanning Tree
 */