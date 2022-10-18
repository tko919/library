#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/contour.hpp"

ll f(ll a,ll b){return a+b;}
ll g(ll a,ll b){return a+b;}
ll m1(){return 0;}

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<ll> a(n);
    io.read(a);
    ContourQuery<ll,ll,f,g,m1> buf(n);
    rep(_,0,n-1){
        int u,v;
        io.read(u,v);
        buf.add_edge(u,v);
    }
    buf.run();
    rep(i,0,n)buf.update(i,a[i]);
    while(q--){
        int t;
        io.read(t);
        if(t==0){
            int v,x;
            io.read(v,x);
            buf.update(v,x);
        }
        else{
            int v,L,R;
            io.read(v,L,R);
            io.write(buf.query(v,L,R));
        }
    }
    return 0;
}