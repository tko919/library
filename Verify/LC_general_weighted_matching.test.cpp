#define PROBLEM "https://judge.yosupo.jp/problem/general_weighted_matching"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/generalweightedmatching.hpp"


FastIO io;
int main(){
    int n,m;
    io.read(n,m);
    GeneralWeightedMatching solver(n);
    vector g(n,vector<ll>(n));
    rep(_,0,m){
        int u,v,w;
        io.read(u,v,w);
        g[u][v]=g[v][u]=w;
        solver.add_edge(u,v,w);
    }
    auto res=solver.run();
    ll r1=0,r2=0;
    rep(i,0,n)if(res[i]>i){
        r1++;
        r2+=g[res[i]][i];
    }
    io.write(r1,r2);
    rep(i,0,n)if(res[i]>i)io.write(res[i],i);
    return 0;
}