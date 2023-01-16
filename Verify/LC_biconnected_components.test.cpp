#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Graph/bc.hpp"

FastIO io;
int main(){
    int n,m;
    io.read(n,m);
    BiconnectedComponents bc(n);
    using P=pair<int,int>;
    vector<P> es(m);
    rep(_,0,m){
        int x,y;
        io.read(x,y);
        bc.add_edge(x,y);
        es[_]={x,y};
    }
    bc.run();
    auto ret=bc.bc;
    vector<int> used(n,0);
    vector<vector<int>> res;
    for(auto& v:ret){
        vector<int> w;
        for(auto& id:v){
            w.push_back(es[id].first);
            w.push_back(es[id].second);
        }
        sort(ALL(w));
        w.erase(unique(ALL(w)),w.end());
        for(auto& x:w)used[x]=1;
        res.push_back(w);
    }
    rep(i,0,n)if(!used[i])res.push_back({i});
    io.write((int)res.size());
    for(auto& v:res){
        io.write((int)v.size(),v);
    }
    return 0;
}
