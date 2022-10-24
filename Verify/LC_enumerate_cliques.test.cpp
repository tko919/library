#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/enumcliques.hpp"
#include "Math/modint.hpp"
using Fp=fp<998244353>;

FastIO io;
int main(){
    int n,m;
    io.read(n,m);
    vector<int> x(n);
    io.read(x);
    EnumCliques g(n);
    rep(_,0,m){
        int u,v;
        io.read(u,v);
        g.add_edge(u,v);
    }
    auto cs=g.run();
    Fp res;
    for(auto& clique:cs){
        Fp add=1;
        for(auto& v:clique)add*=x[v];
        res+=add;
    }
    io.write(res.v);
    return 0;
}