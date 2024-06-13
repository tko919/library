#pragma once
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"

vector<int> WildcardPatternMatching(string &s, string &t, char wild) {
    using Fp = fp<998244353>;
    NTT<Fp> ntt;

    int n = SZ(s), m = SZ(t);
    vector<Fp> a(n), a2(n), a3(n);
    vector<Fp> b(m), b2(m), b3(m);
    rep(i, 0, n) {
        Fp x = (s[i] == wild ? 0 : 1);
        Fp y = (s[i] == wild ? 0 : (s[i] - 'a' + 1));
        a[i] = x;
        a2[i] = x * y;
        a3[i] = x * y * y;
    }
    reverse(ALL(t));
    rep(i, 0, m) {
        Fp x = (t[i] == wild ? 0 : 1);
        Fp y = (t[i] == wild ? 0 : (t[i] - 'a' + 1));
        b[i] = x;
        b2[i] = x * y;
        b3[i] = x * y * y;
    }

    auto ab3 = ntt.mult(a, b3);
    auto a2b2 = ntt.mult(a2, b2);
    auto a3b = ntt.mult(a3, b);

    vector<int> ret;
    rep(i, m - 1, n) {
        Fp val = ab3[i] + a3b[i] - a2b2[i] * 2;
        if (val == 0)
            ret.push_back(1);
        else
            ret.push_back(0);
    }
    return ret;
}