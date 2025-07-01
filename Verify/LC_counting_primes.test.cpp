#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "Template/template.hpp"
#include "Math/lucydp.hpp"

ll F(ll x) {
    return x;
}

int main() {
    ll n;
    cin >> n;
    auto [quo, ps] = LucyDP<ll, F>::gen(n);
    LucyDP<ll, F> pc(n, quo, ps);
    cout << pc[n] << '\n';
    return 0;
}