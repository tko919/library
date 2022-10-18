#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/lca.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    LCA lca(n);
    rep(i,1,n){
        int p;
        io.read(p);
        lca.add_edge(p,i);
    }
    lca.run();
    while(q--){
        int u,v;
        io.read(u,v);
        io.write(lca.lca(u,v));
    }
    return 0;
}