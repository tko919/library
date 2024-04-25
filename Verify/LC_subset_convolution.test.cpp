#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "Convolution/subset.hpp"

using Fp=fp<998244353>;

int main(){
    SubsetConvolution<Fp> buf;
    int n;
    read(n);
    vector<Fp> a(1<<n),b(1<<n);
    rep(i,0,1<<n)read(a[i].v);
    rep(i,0,1<<n)read(b[i].v);
    
    auto ret=buf.mult(a,b);
    rep(i,0,1<<n)print(ret[i].v);
    return 0;
}