#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"

using Fp=fp<998244353>;
NTT<Fp,3> ntt;
void F(vector<Fp>& a,bool f){ntt.ntt(a,f);}
using poly=Poly<Fp,F>;

int main(){
    int n,c;
    cin>>n>>c;
    poly a(n);
    for(auto& x:a)cin>>x;
    a=a.shift(c);
    rep(i,0,n)cout<<a[i]<<'\n';
    return 0;
}