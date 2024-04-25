#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "DataStructure/sortablesegtree.hpp"
#include "Math/modint.hpp"

using Fp=fp<998244353>;
using P=pair<Fp,Fp>;

P f(P a,P b){
    return {a.first*b.first,b.first*a.second+b.second};
}
P g(P a,P b){return b;}
P m1(){return {1,0};}

int main(){
    int n,q;
    read(n,q);
    vector<int> ps(n);
    vector<P> vs(n);
    rep(i,0,n)read(ps[i],vs[i].first.v,vs[i].second.v);
    SortableSegmentTree<P,P,f,g,m1> seg(ps,vs);

    while(q--){
        int t;
        read(t);
        if(t==0){
            int i,p,a,b;
            read(i,p,a,b);
            seg.update(i,p,P{a,b});
        }
        if(t==1){
            int L,R,x;
            read(L,R,x);
            auto ab=seg.query(L,R);
            Fp res=Fp(x)*ab.first+ab.second;
            print(res.v);
        }
        if(t==2){
            int L,R;
            read(L,R);
            seg.sort(L,R);
        }
        if(t==3){
            int L,R;
            read(L,R);
            seg.sort(L,R,1);
        }
    }
    return 0;
}