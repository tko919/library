#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
using Fp=fp<998244353>;

#include "Math/hafnian.hpp"

FastIO io;
int main(){
    int n;
    io.read(n);
    Matrix<Fp> mat(n);
    rep(i,0,n)rep(j,0,n)io.read(mat[i][j].v);

    auto ret=Hafnian(mat);
    io.write(ret.v);
    return 0;
}