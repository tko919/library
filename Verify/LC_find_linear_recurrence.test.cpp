#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "FPS/berlekampmassey.hpp"

using Fp=fp<998244353>;

int main(){
    int n;
    cin>>n;
    vector<Fp> a(n);
    rep(i,0,n)cin>>a[i];

    auto ret=BerlekampMassey(a);
    ret.pop_back();
    reverse(ALL(ret));
    for(auto& x:ret)x=-x;

    cout<<ret.size()<<'\n';
    for(auto& x:ret)cout<<x<<'\n';
    return 0;
}