#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "Template/template.hpp"
#include "DataStructure/2dsegtree.hpp"

ll f(ll a,ll b){return a+b;}
ll g(ll a,ll b){return a+b;}
ll e(){return 0;}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> x(n),y(n),w(n);
    rep(i,0,n)cin>>x[i]>>y[i]>>w[i];
    vector<int> t(q);
    using P=array<int,4>;
    vector<P> que(q);
    rep(i,0,q){
        cin>>t[i];
        if(t[i]==0)rep(j,0,3)cin>>que[i][j];
        else rep(j,0,4)cin>>que[i][j];
    }

    SegmentTree2D<ll,ll,f,g,e> seg;
    rep(i,0,n)seg.push(x[i],y[i]);
    rep(i,0,q)if(t[i]==0)seg.push(que[i][0],que[i][1]);
    seg.init();
    rep(i,0,n)seg.update(x[i],y[i],w[i]);
    rep(i,0,q){
        if(t[i]==0)seg.update(que[i][0],que[i][1],que[i][2]);
        else cout<<seg.query(que[i][0],que[i][2],que[i][1],que[i][3])<<'\n';
    }
    return 0;
}