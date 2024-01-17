#pragma once
#include "DataStructure/bit.hpp"

template <typename T> struct PrefixSubstringLCS {
    using P = pair<int, int>;
    T s, t;
    int pos;
    vector<vector<vector<P>>> que;
    PrefixSubstringLCS() {
    }
    PrefixSubstringLCS(T &_s, T &_t)
        : s(_s), t(_t), pos(0), que(s.size(), vector(t.size(), vector<P>())) {
    }
    void add(int a, int b, int c) {
        if (a == 0 or c == 0) {
            pos++;
            return;
        }
        que[a - 1][c - 1].push_back({b, pos++});
    }
    vector<int> run() {
        vector<int> h(t.size()), ret(pos);
        iota(ALL(h), 0);
        rep(a, 0, s.size()) {
            int pre = -1;
            rep(c, 0, t.size()) {
                if (s[a] == t[c] or h[c] < pre)
                    swap(h[c], pre);
            }
            BIT<int> bit(t.size() + 1);
            rep(c, 0, t.size()) {
                if (h[c] != -1)
                    bit.add(h[c], 1);
                for (auto &[b, id] : que[a][c]) {
                    ret[id] = (c - b + 1) - (bit.all - bit.sum(b));
                }
            }
        }
        return ret;
    }
};

/**
 * @brief Prefix Substring LCS
 */