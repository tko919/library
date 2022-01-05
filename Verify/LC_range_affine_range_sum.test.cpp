#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "DataStructure/lazysegtree.hpp"

using Fp=fp<998244353>;
using P=array<Fp,2>;
P f(P a,P b){return P{a[0]+b[0],a[1]+b[1]};}
P g(P a,P b){return P{a[0]*b[0]+a[1]*b[1],a[1]};}
P h(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}
P e1(){return P{0,0};}
P e2(){return P{1,0};}

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> a(N);
    rep(i,0,N)cin>>a[i];

    LazySegmentTree<P,P,f,g,h,e1,e2> seg(N);
    rep(i,0,N)seg.set(i,P{a[i],1});
    while(Q--){
        int t;
        cin>>t;
        if(t==0){
            int L,R,c,d;
            cin>>L>>R>>c>>d;
            seg.update(L,R,P{c,d});
        }
        else{
            int L,R;
            cin>>L>>R;
            P ret=seg.query(L,R);
            cout<<ret[0]<<'\n';
        }
    }
    return 0;
}