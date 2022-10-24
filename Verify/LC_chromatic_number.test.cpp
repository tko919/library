#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "Template/template.hpp"
#include "Graph/chromatic.hpp"

int main(){
    int n,m;
    cin>>n>>m;
    Chromatic g(n);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        g.add_edge(x,y);
    }
    cout<<g.run()<<'\n';
    return 0;
}