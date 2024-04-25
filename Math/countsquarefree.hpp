#pragma once
#include "Math/kthroot.hpp"

ll CountSquarefree(ll n) {
    if (n <= 3)
        return n;
    const int I = Kthroot(n, 5);
    const int D = sqrtl(n / I);
    vector<int> prime(D + 1, 1), mobius(D + 1);
    mobius[1] = 1;
    rep(i, 2, D + 1) if (prime[i]) {
        for (int j = D / i; j >= 1; j--) {
            if (j >= i and prime[j])
                prime[i * j] = 0;
            if (mobius[j])
                mobius[i * j] = -mobius[j];
        }
    }

    ll ret = 0;
    rep(i, 1, D + 1) ret += mobius[i] * (n / (ll(i) * i));

    auto mertens = mobius;
    rep(i, 0, D) mertens[i + 1] += mertens[i];

    vector<ll> Mxi(I);
    for (int i = I - 1; i >= 1; i--) {
        const int xi = sqrtl(n / i);
        const int sqxi = sqrtl(xi);
        Mxi[i] = 1;
        rep(j, 2, sqxi + 1) {
            if (xi / j <= D)
                Mxi[i] -= mertens[xi / j];
            else
                Mxi[i] -= Mxi[i * j * j];
        }
        rep(j, 1, xi / (sqxi + 1) + 1) Mxi[i] -=
            (xi / j - xi / (j + 1)) * mertens[j];
        ret += Mxi[i];
    }
    ret -= ll(I - 1) * mertens[D];
    return ret;
}

/**
 * @brief Count Square-free integers
 */