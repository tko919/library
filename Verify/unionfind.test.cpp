#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "template.hpp"
#include "unionfind.hpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> t(Q),u(Q),v(Q);
    rep(i,0,Q)cin>>t[i]>>u[i]>>v[i];
    
    UnionFind uni(N);
    rep(i,0,Q){
        if(t[i]==0){
            uni.unite(u[i],v[i]);
        }
        else{
            cout<<uni.same(u[i],v[i])<<'\n';
        }
    }
    return 0;
}