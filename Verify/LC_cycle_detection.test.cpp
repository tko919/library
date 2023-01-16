#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/cycledetect.hpp"

FastIO io;
int main(){
    int n,m;
    io.read(n,m);
    
    CycleDetect<1> g(n);
    rep(_,0,m){
        int u,v;
        io.read(u,v);
        g.add_edge(u,v);
    }
    g.run();

    if(g.cycle.empty()){io.write(-1); return 0;}
    int k=g.cycle.size();
    io.write(k);
    rep(i,0,k)io.write(g.cycle[i].second);
    return 0;
}