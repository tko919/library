#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
#include "FPS/multieval.hpp"

using Fp=fp<998244353>;
NTT<Fp,3> ntt;
template<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return ntt.ntt(v,inv);}

int main(){
    int n,m;
    cin>>n>>m;
    vector<Fp> a(n),b(m);
    for(auto& x:a)cin>>x;
    for(auto& x:b)cin>>x;
    MultiEval<Fp> multi(b);
    auto ret=multi.run(a);
    rep(i,0,m)cout<<ret[i]<<'\n';
    return 0;
}