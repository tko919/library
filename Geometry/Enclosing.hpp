#pragma once
#include "Geometry/geometry.hpp"
#include "Utility/random.hpp"

Circle Enclosing(vector<Point> ps) {
    Random::shuffle(ALL(ps));
    auto make2 = [&](Point p, Point q) {
        return Circle((p + q) * .5, abs(p - q) * .5);
    };
    Circle ret = make2(ps[0], ps[1]);
    rep(i, 2, SZ(ps)) {
        if (abs(ret.p - ps[i]) > ret.r + eps) {
            ret = make2(ps[0], ps[i]);
            rep(j, 1, i) {
                if (abs(ret.p - ps[j]) > ret.r + eps) {
                    ret = make2(ps[i], ps[j]);
                    rep(k, 0, j) {
                        if (abs(ret.p - ps[k]) > ret.r + eps) {
                            ret = Circumcircle(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return ret;
}

/**
 * @brief Enclosing Circle
 */