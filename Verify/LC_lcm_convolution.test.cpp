#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "Convolution/divisor.hpp"

using Fp=fp<998244353>;

FastIO io;
int main(){
    int n;
    io.read(n);
    vector<Fp> a(n+1),b(n+1);
    rep(i,1,n+1)io.read(a[i].v);
    rep(i,1,n+1)io.read(b[i].v);

    DivisorTransform::zeta(a);
    DivisorTransform::zeta(b);
    rep(i,1,n+1)a[i]*=b[i];
    DivisorTransform::mobius(a);
    rep(i,1,n+1)io.write(a[i].v);
    return 0;
}