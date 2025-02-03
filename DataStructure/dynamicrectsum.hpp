#pragma once
#include "DataStructure/staticrectsum.hpp"

template <typename XY, typename T> struct DynamicPointAddRectangleSum {
    using Point = tuple<XY, XY, T>;
    using Query = tuple<XY, XY, XY, XY>;
    vector<variant<Point, Query>> que;
    DynamicPointAddRectangleSum() {}
    void add(XY x, XY y, T w) {
        que.push_back(Point{x, y, w});
    }
    void query(XY L, XY D, XY R, XY U) {
        que.push_back(Query{L, D, R, U});
    }
    vector<T> run() {
        int Q = SZ(que);
        vector<int> isq(Q);
        vector<int> pos(Q);
        int ptr = 0;
        rep(i, 0, Q) if (holds_alternative<Query>(que[i])) {
            isq[i] = 1;
            pos[i] = ptr++;
        }
        vector<T> ret(ptr);
        auto rec = [&](auto &rec, int L, int R) -> void {
            if (L + 1 >= R)
                return;
            int mid = (L + R) >> 1;
            rec(rec, L, mid);
            rec(rec, mid, R);
            StaticRectangleSum<XY, T> buf;
            rep(k, L, mid) if (!isq[k]) {
                XY x, y;
                T w;
                tie(x, y, w) = get<Point>(que[k]);
                buf.add(x, y, w);
            }
            rep(k, mid, R) if (isq[k]) {
                XY L, D, R, U;
                tie(L, D, R, U) = get<Query>(que[k]);
                buf.query(L, D, R, U);
            }
            auto sub = buf.run();
            ptr = 0;
            rep(k, mid, R) if (isq[k]) {
                ret[pos[k]] += sub[ptr++];
            }
        };
        rec(rec, 0, Q);
        return ret;
    }
};

/**
 * @brief Dynamic Point Add Rectangle Sum
 */