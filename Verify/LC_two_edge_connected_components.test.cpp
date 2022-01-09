#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "Template/template.hpp"
#include "Graph/lowlink.hpp"

int main(){
    int n,m;
    cin>>n>>m;
    LowLink low(n);
    rep(_,0,m){
        int x,y;
        cin>>x>>y;
        low.add_edge(x,y);
    }
    int ret=low.run();
    vector g(ret,vector<int>());
    rep(i,0,n)g[low.id[i]].push_back(i);

    cout<<ret<<'\n';
    rep(i,0,g.size()){
        cout<<g[i].size()<<' ';
        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\n':' ');
    }
    return 0;
}