#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
#include "FPS/relax.hpp"

using Fp=fp<998244353>;
NTT<Fp,3> ntt;
template<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return ntt.ntt(v,inv);}

FastIO io;
int main(){
    int n,m;
    io.read(n,m);
    vector<Fp> _f(n),_g(m);
    rep(i,0,n)io.read(_f[i].v);
    rep(i,0,m)io.read(_g[i].v);
    RelaxedConvolution<Fp> buf(n+m-1);
    rep(i,0,n+m-1){
        if(i<n)buf.f[i]=_f[i];
        if(i<m)buf.g[i]=_g[i];
        Fp ret=buf.next();
        io.write(ret.v);
    }
    return 0;
}
