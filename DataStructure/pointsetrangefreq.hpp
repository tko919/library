#pragma once
#include "DataStructure/rbstset.hpp"

template <typename T> struct PointSetRangeFrequency {
    vector<T> a;
    unordered_map<T, RBSTset<int>> pos;
    PointSetRangeFrequency() {}
    PointSetRangeFrequency(int n) : PointSetRangeFrequency(vector<T>(n)) {}
    PointSetRangeFrequency(vector<T> &_a) : a(_a) {
        rep(i, 0, SZ(a)) pos[a[i]].insert(i);
    }
    void set(int i, T x) {
        pos[a[i]].erase(i);
        a[i] = x;
        pos[a[i]].insert(i);
    }
    int query(int L, int R, T x) {
        return pos[x].lower_bound(R) - pos[x].lower_bound(L);
    }
};

/**
 * @brief Point Set Range Frequency
 */