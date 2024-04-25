#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/lca.hpp"

int main(){
    int n,q;
    read(n,q);
    LCA lca(n);
    rep(i,1,n){
        int p;
        read(p);
        lca.add_edge(p,i);
    }
    lca.run();
    while(q--){
        int u,v;
        read(u,v);
        print(lca.lca(u,v));
    }
    return 0;
}