#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "Convolution/ntt.hpp"
#include "Math/modint.hpp"
#include "Template/template.hpp"

using Fp = fp<998244353>;
NTT<Fp> ntt;

int main() {
    int n, m;
    cin >> n >> m;
    vector<Fp> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    auto ret = ntt.mult(a, b);
    for (auto &x : ret)
        cout << x << '\n';
    return 0;
}