#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Math/matrix.hpp"

using Fp=fp<998244353>;

int main(){
    int n;
    cin>>n;
    Matrix<Fp> a(n,n);
    rep(i,0,n)rep(j,0,n)cin>>a[i][j];
    a.gauss();
    cout<<a.det<<'\n';
    return 0;
}