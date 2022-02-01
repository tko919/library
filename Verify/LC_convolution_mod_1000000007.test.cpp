#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/arbitrary.hpp"

using Fp=fp<>;

int main(){
    int n,m;
    cin>>n>>m;
    vector<Fp> a(n),b(m);
    for(auto& x:a)cin>>x;
    for(auto& x:b)cin>>x;
    auto ret=ArbitraryMult(a,b);
    for(auto& x:ret)cout<<x<<'\n';
    return 0;
}