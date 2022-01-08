#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
#include "FPS/multieval.hpp"

using Fp=fp<998244353>;
NTT<Fp,3> ntt;
void F(vector<Fp>& a,bool f){ntt.ntt(a,f);}
using poly=Poly<Fp,F>;

int main(){
    int n;
    cin>>n;
    vector<Fp> a(n),b(n);
    for(auto& x:a)cin>>x;
    for(auto& x:b)cin>>x;
    MultiEval<Fp,poly> multi(a);
    auto ret=multi.build(b);
    rep(i,0,n)cout<<ret[i]<<'\n';
    return 0;
}