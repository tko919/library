#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "Template/template.hpp"
#include "DataStructure/lichaotree.hpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<ll> l(N),r(N),a(N),b(N);
    rep(i,0,N)cin>>l[i]>>r[i]>>a[i]>>b[i];
    vector<ll> t(Q),L(Q),R(Q),c(Q),d(Q);
    vector<ll> xs;
    rep(i,0,Q){
        cin>>t[i];
        if(t[i]==0)cin>>L[i]>>R[i]>>c[i]>>d[i];
        else{
            cin>>L[i];
            xs.push_back(L[i]);
        }
    }
    xs.push_back(-INF);
    xs.push_back(INF);
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)),xs.end());

    CHT<ll,INF> cht(xs);
    rep(i,0,N)cht.add_segment(a[i],b[i],l[i],r[i]);
    rep(i,0,Q){
        if(t[i]==0)cht.add_segment(c[i],d[i],L[i],R[i]);
        else{
            ll ret=cht.getmin(L[i]);
            if(ret==INF)puts("INFINITY");
            else cout<<ret<<'\n';
        }
    }
    return 0;
}