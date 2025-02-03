#pragma once
#include "DataStructure/bit.hpp"

template <typename XY, typename T> struct StaticRectangleSum {
    struct P {
        XY x, y;
        T w;
    };
    struct Rect {
        XY l, d, r, u;
    };
    struct Q {
        XY x, d, u;
        int id, inv;
    };
    vector<P> plus;
    vector<Rect> que;
    StaticRectangleSum() {}
    void add(XY x, XY y, T w) {
        plus.push_back({x, y, w});
    }
    void query(XY l, XY d, XY r, XY u) {
        que.push_back({l, d, r, u});
    }
    vector<T> run() {
        ll n = plus.size(), q = que.size();
        sort(ALL(plus), [](P &p, P &q) { return p.y < q.y; });
        vector<XY> ys;
        rep(i, 0, n) ys.push_back(plus[i].y);
        ys.erase(unique(ALL(ys)), ys.end());
        rep(i, 0, n) plus[i].y = lower_bound(ALL(ys), plus[i].y) - ys.begin();
        vector<Q> qs;
        rep(i, 0, q) {
            auto &[l, d, r, u] = que[i];
            d = lower_bound(ALL(ys), d) - ys.begin();
            u = lower_bound(ALL(ys), u) - ys.begin();
            qs.push_back({l, d, u, i, 1});
            qs.push_back({r, d, u, i, -1});
        }
        sort(ALL(plus), [](P &p, P &q) { return p.x < q.x; });
        sort(ALL(qs), [](Q &p, Q &q) { return p.x < q.x; });
        vector<T> res(q);
        int k = 0;
        BIT<T> bit(ys.size());
        for (auto &q : qs) {
            while (k < n and plus[k].x < q.x) {
                bit.add(plus[k].y, plus[k].w);
                k++;
            }
            res[q.id] += bit.sum(q.u, q.d) * q.inv;
        }
        return res;
    }
};

/**
 * @brief Static Rectangle Sum
 */