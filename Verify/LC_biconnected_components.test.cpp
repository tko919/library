#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Graph/bc.hpp"

FastIO io;
int main(){
    int n,m;
    io.read(n,m);
    BiconnectedComponents bc(n);
    rep(_,0,m){
        int x,y;
        io.read(x,y);
        bc.add_edge(x,y);
    }
    bc.run();
    auto ret=bc.bc;
    io.write(int(ret.size()));
    for(auto& v:ret){
        io.write(int(v.size()));
        io.write(v);
    }
    return 0;
}