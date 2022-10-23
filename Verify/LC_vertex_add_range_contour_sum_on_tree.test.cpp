#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Graph/contour.hpp"
#include "DataStructure/bit.hpp"


FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<ll> a(n);
    io.read(a);
    ContourQuery buf(n);
    rep(_,0,n-1){
        int u,v;
        io.read(u,v);
        buf.add_edge(u,v);
    }
    auto len=buf.run();
    vector<BIT<ll>> seg(len.size());
    rep(i,0,len.size())seg[i]=BIT<ll>(len[i]);
    rep(v,0,n){
        for(auto& [i,p]:buf.point(v))seg[i].add(p,a[v]);
    }

    while(q--){
        int t;
        io.read(t);
        if(t==0){
            int v,x;
            io.read(v,x);
            for(auto& [i,p]:buf.point(v))seg[i].add(p,x);
        }
        else{
            int v,L,R;
            io.read(v,L,R);
            ll ret=0;
            for(auto& [i,LR]:buf.range(v,L,R)){
                auto [lb,rb]=LR;
                ret+=seg[i].sum(lb,rb);
            }
            io.write(ret);
        }
    }
    return 0;
}