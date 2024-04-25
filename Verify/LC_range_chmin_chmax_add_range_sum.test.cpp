#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/segtreebeats.hpp"

int main(){
    int n,q;
    read(n,q);
    vector<ll> a(n);
    read(a);
    Segtreebeats seg(a);

    int t,L,R;
    ll x;
    while(q--){
        read(t);
        if(t==0){
            read(L,R,x);
            seg.range_chmin(L,R,x);
        }
        if(t==1){
            read(L,R,x);
            seg.range_chmax(L,R,x);
        }   
        if(t==2){
            read(L,R,x);
            seg.range_add(L,R,x);
        }
        if(t==3){
            read(L,R);
            print(seg.query_sum(L,R));
        }
    }
    return 0;
}