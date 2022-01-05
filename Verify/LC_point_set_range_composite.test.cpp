#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "DataStructure/segtree.hpp"

using Fp=fp<998244353>;
using P=array<Fp,2>;
P f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}
P g(P a,P b){return b;}
P e(){return P{1,0};}

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> a(N),b(N);
    rep(i,0,N)cin>>a[i]>>b[i];

    SegmentTree<P,P,f,g,e> seg(N);
    rep(i,0,N)seg.set(i,P{a[i],b[i]});
    while(Q--){
        int t;
        cin>>t;
        if(t==0){
            int p,c,d;
            cin>>p>>c>>d;
            seg.set(p,P{c,d});
        }
        else{
            int L,R,x;
            cin>>L>>R>>x;
            P ret=seg.query(L,R);
            cout<<ret[0]*x+ret[1]<<'\n';
        }
    }
    return 0;
}