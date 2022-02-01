#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
#include "FPS/nthterm.hpp"

using Fp=fp<998244353>;
NTT<Fp,3> ntt;
template<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return ntt.ntt(v,inv);}

int main(){
    int d; ll k;
    cin>>d>>k;
    Poly<Fp> a(d),c(d+1);
    rep(i,0,d)cin>>a[i];
    c[0]=1;
    rep(i,1,d+1){
        cin>>c[i];
        c[i]=-c[i];
    }
    a*=c;
    a.resize(d);
    Fp res=nth<Fp>(a,c,k);
    cout<<res<<'\n';
    return 0;
}