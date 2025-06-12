#pragma once

double digamma(double x) {
    double res = 0;
    while (x < 50)
        res -= 1. / x, x += 1;
    double xx = 1. / x;
    double xx2 = xx * xx;
    double xx4 = xx2 * xx2;
    res += log(x) - 0.5 * xx - xx2 / 12.0 + xx4 / 120 - xx4 * xx2 / 252;
    return res;
}
// 1/l + 1/(l + 1) + ... + 1/(r - 1)
double inv_sum(double l, double r) {
    return digamma(r) - digamma(l);
}

/**
 * @brief Inverse Sum
 */