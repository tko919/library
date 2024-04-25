#pragma once

namespace Random {
mt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());
using u64 = unsigned long long;
u64 get() {
    return randgen();
}
template <typename T> T get(T L) { // [0,L]
    return get() % (L + 1);
}
template <typename T> T get(T L, T R) { // [L,R]
    return get(R - L) + L;
}
double uniform() {
    return double(get(1000000000)) / 1000000000;
}
string str(int n) {
    string ret;
    rep(i, 0, n) ret += get('a', 'z');
    return ret;
}
template <typename Iter> void shuffle(Iter first, Iter last) {
    if (first == last)
        return;
    int len = 1;
    for (auto it = first + 1; it != last; it++) {
        len++;
        int j = get(0, len - 1);
        if (j != len - 1)
            iter_swap(it, first + j);
    }
}
template <typename T> vector<T> select(int n, T L, T R) { // [L,R]
    if (n * 2 >= R - L + 1) {
        vector<T> ret(R - L + 1);
        iota(ALL(ret), L);
        shuffle(ALL(ret));
        ret.resize(n);
        return ret;
    } else {
        unordered_set<T> used;
        vector<T> ret;
        while (SZ(used) < n) {
            T x = get(L, R);
            if (!used.count(x)) {
                used.insert(x);
                ret.push_back(x);
            }
        }
        return ret;
    }
}

void relabel(int n, vector<pair<int, int>> &es) {
    shuffle(ALL(es));
    vector<int> ord(n);
    iota(ALL(ord), 0);
    shuffle(ALL(ord));
    for (auto &[u, v] : es)
        u = ord[u], v = ord[v];
}
template <bool directed, bool simple> vector<pair<int, int>> genGraph(int n) {
    vector<pair<int, int>> cand, es;
    rep(u, 0, n) rep(v, 0, n) {
        if (simple and u == v)
            continue;
        if (!directed and u > v)
            continue;
        cand.push_back({u, v});
    }
    int m = get(SZ(cand));
    vector<int> ord;
    if (simple)
        ord = select(m, 0, SZ(cand) - 1);
    else {
        rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));
    }
    for (auto &i : ord)
        es.push_back(cand[i]);
    relabel(n, es);
    return es;
}
vector<pair<int, int>> genTree(int n) {
    vector<pair<int, int>> es;
    rep(i, 1, n) es.push_back({get(i - 1), i});
    relabel(n, es);
    return es;
}
}; // namespace Random

/**
 * @brief Random
 */