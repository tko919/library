#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "Template/template.hpp"
#include "Graph/hld.hpp"
#include "DataStructure/bit.hpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> a(N);
    rep(i,0,N)cin>>a[i];
    HLD hld(N);
    BIT<ll> bit(N);
    rep(i,0,N-1){
        int x,y;
        cin>>x>>y;
        hld.add_edge(x,y);
    }
    hld.run();
    rep(i,0,N)bit.add(hld.in[i],a[i]);
    while(Q--){
        int t;
        cin>>t;
        if(t==0){
            int p,x;
            cin>>p>>x;
            bit.add(hld.in[p],x);
        }
        else{
            int u,v;
            cin>>u>>v;
            int lca=hld.lca(u,v);
            auto ps=hld.get(u,lca);
            ll ret=0;
            for(auto& [L,R]:ps)ret+=bit.sum(L,R);
            ps=hld.get(v,lca,1);
            for(auto& [L,R]:ps)ret+=bit.sum(L,R);
            cout<<ret<<'\n';
        }
    }
    return 0;
}