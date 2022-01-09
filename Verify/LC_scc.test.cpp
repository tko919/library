#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "Template/template.hpp"
#include "Graph/scc.hpp"

int main(){
    int n,m;
    cin>>n>>m;
    SCC scc(n);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        scc.add_edge(x,y);
    }
    scc.run();
    vector g(scc.m,vector<int>());
    rep(i,0,n)g[scc.id[i]].push_back(i);
    cout<<g.size()<<'\n';
    rep(i,0,g.size()){
        cout<<g[i].size()<<' ';
        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\n':' ');
    }
    return 0;
}