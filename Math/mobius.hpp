#pragma once
#include "Convolution/divisor.hpp"

vector<int> Mobius(ll n) {
    vector<int> mu(n + 1);
    mu[1] = 1;
    DivisorTransform::mobius(mu);
    return mu;
}

/**
 * @brief Mobius table
 */