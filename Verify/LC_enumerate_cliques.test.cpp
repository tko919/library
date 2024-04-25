#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/enumcliques.hpp"
#include "Math/modint.hpp"
using Fp=fp<998244353>;

int main(){
    int n,m;
    read(n,m);
    vector<int> x(n);
    read(x);
    EnumCliques g(n);
    rep(_,0,m){
        int u,v;
        read(u,v);
        g.add_edge(u,v);
    }
    auto cs=g.run();
    Fp res;
    for(auto& clique:cs){
        Fp add=1;
        for(auto& v:clique)add*=x[v];
        res+=add;
    }
    print(res.v);
    return 0;
}