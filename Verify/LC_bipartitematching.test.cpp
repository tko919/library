#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "Template/template.hpp"
#include "Graph/bimatching.hpp"

int main(){
    int L,R,m;
    cin>>L>>R>>m;
    BiMatching buf(L,R);
    rep(_,0,m){
        int x,y;
        cin>>x>>y;
        buf.add_edge(x,y);
    }
    int ret=buf.run();
    
    cout<<ret<<'\n';
    rep(i,0,L)if(buf.nxt[i]!=-1){
        cout<<i<<' '<<buf.nxt[i]<<'\n';
    }
    return 0;
}