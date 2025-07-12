#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Utility/random.hpp"

#include "Math/multiplicative2.hpp"

#include "Math/modint.hpp"
using Fp = fp<469762049>;

Fp A, B;
Fp F(ll x) {
    return Fp(x);
}
Fp G(ll x) {
    return Fp(x) * (x + 1) / 2;
}
Fp pe(int p, int e) {
    return A * e + B * p;
}

int main() {
    int T;
    read(T);
    while (T--) {
        ll n;
        read(n, A, B);
        int SQ = sqrtl(n);

        auto cnt = getLarge<Fp, F>(n);
        auto sum = getLarge<Fp, G>(n);
        Dir<Fp> large(n);
        rep(i, SQ + 1, large.sz) large[i] = A * cnt[i] + B * sum[i];
        large.pref();
        auto ret = MultiplicativeSum<Fp, pe>(n, large);
        print(ret[ret.idx(n)]);
    }
    return 0;
}
