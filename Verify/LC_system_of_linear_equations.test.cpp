#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Math/matrix.hpp"
#include "Math/linearequation.hpp"

using Fp=fp<998244353>;

int main(){
    int n,m;
    cin>>n>>m;
    Matrix<Fp> a(n,m);
    vector<Fp> b(n);
    rep(i,0,n)rep(j,0,m)cin>>a[i][j];
    rep(i,0,n)cin>>b[i];

    auto [ret,basis]=LinearEquation(a,b);
    if(ret.empty()){
        puts("-1");
        return 0;
    }
    cout<<basis.h<<'\n';
    rep(i,0,m)cout<<ret[i]<<(i==m-1?'\n':' ');
    rep(i,0,basis.h){
        rep(j,0,m)cout<<basis[i][j]<<(j==m-1?'\n':' ');
    }
    return 0;
}