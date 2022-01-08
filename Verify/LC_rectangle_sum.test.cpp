#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

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

    SegmentTree2D<ll,ll,f,g,e> seg;
    rep(i,0,n)seg.push(x[i],y[i]);
    seg.init();
    rep(i,0,n)seg.update(x[i],y[i],w[i]);
    while(q--){
        int l,r,d,u;
        cin>>l>>d>>r>>u;
        cout<<seg.query(l,r,d,u)<<'\n';
    }
    return 0;
}