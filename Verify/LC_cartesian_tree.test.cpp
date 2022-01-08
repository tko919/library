#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "Template/template.hpp"
#include "Algorithm/cartesian.hpp"

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n)cin>>a[i];
    auto ret=Cartesian(a);
    rep(i,0,n){
        if(ret[i]==-1)ret[i]=i;
        cout<<ret[i]<<'\n';
    }
    return 0;
}