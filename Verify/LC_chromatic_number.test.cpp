#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "Template/template.hpp"
#include "Graph/chromatic.hpp"

int main(){
    int n,m;
    cin>>n>>m;
    vector a(n,vector<int>(n));
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    cout<<Chromatic(a)<<'\n';
    return 0;
}