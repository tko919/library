#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "Template/template.hpp"
#include "Graph/hld.hpp"

int main(){
    int n,q;
    cin>>n>>q;
    HLD hld(n);
    rep(i,1,n){
        int p;
        cin>>p;
        hld.add_edge(i,p);
    }
    hld.run();
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<hld.lca(x,y)<<'\n';
    }
    return 0;
}