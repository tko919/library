#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "Template/template.hpp"
#include "Graph/maxindependentset.hpp"

int main(){
    int n,m;
    cin>>n>>m;
    vector a(n,vector<int>(n));
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    vector<int> cost(n,1);
    auto [ret,mask]=MaxIndependentSet(a,cost);
    cout<<__builtin_popcountll(mask)<<'\n';
    rep(i,0,n)if(mask>>i&1)cout<<i<<' ';
    cout<<'\n';
    return 0;
}