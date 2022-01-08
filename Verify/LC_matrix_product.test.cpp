#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Math/matrix.hpp"

using Fp=fp<998244353>;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    Matrix<Fp> a(n,m),b(m,k);
    rep(i,0,n)rep(j,0,m)cin>>a[i][j];
    rep(i,0,m)rep(j,0,k)cin>>b[i][j];
    a=a*b;
    rep(i,0,n){
        rep(j,0,k)cout<<a[i][j]<<(j==k-1?'\n':' ');
    }   
    return 0;
}