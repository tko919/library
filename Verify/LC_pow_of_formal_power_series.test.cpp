#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"

using Fp=fp<998244353>;
NTT<Fp,3> ntt;
void F(vector<Fp>& a,bool f){ntt.ntt(a,f);}
using poly=Poly<Fp,F>;

int main(){
    int n;
    cin>>n;
    ll k;
    cin>>k;
    poly a(n);
    rep(i,0,n)cin>>a[i];
    a=a.pow(k);
    rep(i,0,n)cout<<a[i]<<'\n';
    return 0;
}