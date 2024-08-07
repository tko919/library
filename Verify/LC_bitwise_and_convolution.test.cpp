#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "Convolution/bitwise.hpp"

using Fp = fp<998244353>;

int main() {
    int n;
    cin >> n;
    vector<Fp> a(1 << n), b(1 << n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<Fp> ret(1 << n);
    reverse(ALL(a));
    reverse(ALL(b));
    Bitwise::zeta(a);
    Bitwise::zeta(b);
    rep(i, 0, 1 << n) ret[i] = a[i] * b[i];
    Bitwise::mobius(ret);
    reverse(ALL(ret));
    for (auto &x : ret)
        cout << x << '\n';
    return 0;
}