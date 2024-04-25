#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
using Fp=fp<998244353>;

#include "Math/hafnian.hpp"

int main(){
    int n;
    read(n);
    Matrix<Fp> mat(n);
    rep(i,0,n)rep(j,0,n)read(mat[i][j].v);

    auto ret=Hafnian(mat);
    print(ret.v);
    return 0;
}