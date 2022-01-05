#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "Template/template.hpp"
#include "DataStructure/lichaotree.hpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<ll> a(N),b(N);
    rep(i,0,N)cin>>a[i]>>b[i];
    vector<ll> t(Q),c(Q),d(Q);
    vector<ll> xs;
    rep(i,0,Q){
        cin>>t[i];
        if(t[i]==0)cin>>c[i]>>d[i];
        else{
            cin>>c[i];
            xs.push_back(c[i]);
        }
    }
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)),xs.end());

    CHT<ll,INF> cht(xs);
    rep(i,0,N)cht.add(a[i],b[i]);
    rep(i,0,Q){
        if(t[i]==0)cht.add(c[i],d[i]);
        else cout<<cht.getmin(c[i])<<'\n';
    }
    return 0;
}