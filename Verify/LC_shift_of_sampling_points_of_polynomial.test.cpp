#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
using Fp=fp<998244353>;
NTT<Fp,3> ntt;
template<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return ntt.ntt(v,inv);}

#include "FPS/samplepointshift.hpp"

FastIO io;
int main(){
    int n,m;
    Fp c;
    io.read(n,m,c.v);
    vector<Fp> a(n);
    rep(i,0,n)io.read(a[i].v);

    auto ret=SamplePointsShift(a,c,m);
    rep(i,0,m)io.write(ret[i].v);
    return 0;
}