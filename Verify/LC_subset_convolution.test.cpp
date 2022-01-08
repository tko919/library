#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "Convolution/subset.hpp"

using Fp=fp<998244353>;

int main(){
    int n;
    cin>>n;
    vector<Fp> a(1<<n),b(1<<n);
    for(auto& x:a)cin>>x;
    for(auto& x:b)cin>>x;
    auto ret=SubsetConvolution(a,b);
    for(auto& x:ret)cout<<x<<'\n';
    return 0;
}