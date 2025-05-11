#pragma once
#include "Math/dynamic.hpp"
#include "Math/matrix.hpp"
#include "Math/pollard.hpp"

int Pisano(int p) {
    if (p == 2)
        return 3;
    if (p == 5)
        return 20;
    vector<ll> cand;
    if (p % 5 == 1 or p % 5 == 4)
        cand = EnumDivisors(p - 1);
    else
        cand = EnumDivisors(p * 2 + 2);
    auto check = [&](int d, int p) -> bool {
        Fp::set_mod(p);
        Matrix<Fp> mat(2, 2);
        mat[0][1] = mat[1][0] = mat[1][1] = 1;
        mat = mat.pow(d);
        return mat[0][1] == 0 and mat[1][1] == 1;
    };
    for (auto &d : cand)
        if (check(d, p)) {
            return d;
        }
    assert(0);
}

/**
 * @brief Pisano Period
 */