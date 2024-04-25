#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/cycledetect.hpp"

int main(){
    int n,m;
    read(n,m);
    
    CycleDetect<1> g(n);
    rep(_,0,m){
        int u,v;
        read(u,v);
        g.add_edge(u,v);
    }
    g.run();

    if(g.cycle.empty()){print(-1); return 0;}
    int k=g.cycle.size();
    print(k);
    rep(i,0,k)print(g.cycle[i].second);
    return 0;
}