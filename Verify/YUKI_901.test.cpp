#define PROBLEM "https://yukicoder.me/problems/no/901"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/lca.hpp"
#include "Graph/auxiliarytree.hpp"

FastIO io;
int main(){
    int n;
    io.read(n);
    AuxiliaryTree g(n);
    LCA lca(n);
    using P=pair<int,int>;
    vector tree(n,vector<P>());
    rep(_,0,n-1){
        int u,v,w;
        io.read(u,v,w);
        g.add_edge(u,v);
        lca.add_edge(u,v);
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    g.run();
    lca.run();

    vector<ll> dep(n);
    auto dfs=[&](auto& dfs,int v,int p)->void{
        for(auto& [to,w]:tree[v])if(to!=p){
            dep[to]=dep[v]+w;
            dfs(dfs,to,v);
        }
    };
    dfs(dfs,0,-1);
    auto dist=[&](int u,int v)->ll{
        return dep[u]+dep[v]-2*dep[lca.lca(u,v)];
    };

    int q;
    io.read(q);
    while(q--){
        int k;
        io.read(k);
        vector<int> vs(k);
        io.read(vs);
        g.query(vs);
        ll ret=0;
        for(auto& v:vs)for(auto& to:g.g[v])ret+=dist(v,to);
        ret/=2;
        io.write(ret);
        g.clear(vs);
    }
    return 0;
}