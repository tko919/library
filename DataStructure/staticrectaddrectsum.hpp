#pragma once
#include "DataStructure/staticrectsum.hpp"

template <typename XY, typename T> struct StaticRectangleAddRectangleSum {
    StaticRectangleSum<XY, T> bit[4]; // XY,X,Y,Const
    struct Rect {
        XY l, d, r, u;
    };
    vector<Rect> que;
    StaticRectangleAddRectangleSum() {}
    void add(XY x, XY y, T w) {
        bit[0].add(x, y, w);
        bit[1].add(x, y, w * -y);
        bit[2].add(x, y, w * -x);
        bit[3].add(x, y, w * x * y);
    }
    void add(XY l, XY d, XY r, XY u, T w) {
        add(l, d, w);
        add(l, u, -w);
        add(r, d, -w);
        add(r, u, w);
    }
    void query(XY l, XY d, XY r, XY u) {
        que.push_back({l, d, r, u});
    }
    vector<T> run() {
        int q = que.size();
        for (auto &[l, d, r, u] : que) {
            rep(j, 0, 4) {
                bit[j].query(0, 0, l, d);
                bit[j].query(0, 0, l, u);
                bit[j].query(0, 0, r, d);
                bit[j].query(0, 0, r, u);
            }
        }
        auto both = bit[0].run();
        auto X = bit[1].run();
        auto Y = bit[2].run();
        auto Const = bit[3].run();
        vector<T> res(q);
        rep(i, 0, q) {
            auto [l, d, r, u] = que[i];
            res[i] += both[4 * i] * l * d;
            res[i] += X[4 * i] * l;
            res[i] += Y[4 * i] * d;
            res[i] += Const[4 * i];

            res[i] -= both[4 * i + 1] * l * u;
            res[i] -= X[4 * i + 1] * l;
            res[i] -= Y[4 * i + 1] * u;
            res[i] -= Const[4 * i + 1];

            res[i] -= both[4 * i + 2] * r * d;
            res[i] -= X[4 * i + 2] * r;
            res[i] -= Y[4 * i + 2] * d;
            res[i] -= Const[4 * i + 2];

            res[i] += both[4 * i + 3] * r * u;
            res[i] += X[4 * i + 3] * r;
            res[i] += Y[4 * i + 3] * u;
            res[i] += Const[4 * i + 3];
        }
        return res;
    }
};

/**
 * @brief Static Rectangle Add Rectangle Sum
 */