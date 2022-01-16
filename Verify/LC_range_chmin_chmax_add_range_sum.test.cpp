#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/segtreebeats.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<ll> a(n);
    io.read(a);
    Segtreebeats seg(a);

    int t,L,R,x;
    while(q--){
        io.read(t);
        if(t==0){
            io.read(L,R,x);
            seg.range_chmin(L,R,x);
        }
        if(t==1){
            io.read(L,R,x);
            seg.range_chmax(L,R,x);
        }   
        if(t==2){
            io.read(L,R,x);
            seg.range_add(L,R,x);
        }
        if(t==3){
            io.read(L,R);
            io.write(seg.query_sum(L,R));
        }
    }
    return 0;
}