#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"
#include "FPS/fps.hpp"
#include "Math/bbla.hpp"
using Fp=fp<998244353>;
NTT<Fp,3> ntt;
template<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return ntt.ntt(v,inv);}

FastIO io;
int main(){
    int n,k;
    io.read(n,k);
    SparseMatrix<Fp> mat(n);
    int a,b,c;
    rep(_,0,k){
        io.read(a,b,c);
        mat.add(a,b,c);
    }
    Fp ret=FastDet(mat);
    io.write(ret.v);
    return 0;
}