#pragma once
#include "Convolution/divisor.hpp"

vector<int> phitable(int n) {
    vector<int> ret(n + 1);
    iota(ALL(ret), 0);
    DivisorTransform::mobius(ret);
    return ret;
}

/**
 * @brief lpf table
 */