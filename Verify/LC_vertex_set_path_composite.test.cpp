#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/modint.hpp"
#include "Graph/hld.hpp"
#include "DataStructure/segtree.hpp"

using Fp=fp<998244353>;
using P=array<Fp,2>;
P f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}
struct X{
    P base,rev;
    X(Fp a=1,Fp b=0):base({a,b}),rev({a,b}){}
};
X f(X a,X b){
    X ret;
    ret.base=f(a.base,b.base);
    ret.rev=f(b.rev,a.rev);
    return ret; 
}
X g(X a,X b){return b;}
X e(){return X();}

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<X> A(N);
    rep(i,0,N){
        int a,b;
        cin>>a>>b;
        A[i]=X(a,b);
    }
    HLD hld(N);
    rep(_,0,N-1){
        int x,y;
        cin>>x>>y;
        hld.add_edge(x,y);
    }
    hld.run();

    SegmentTree<X,X,f,g,e> seg(N);
    rep(i,0,N)seg.update(hld.in[i],A[i]);
    while(Q--){
        int t;
        cin>>t;
        if(t==0){
            int p,c,d;
            cin>>p>>c>>d;
            seg.update(hld.in[p],X{c,d});
        }
        else{
            int u,v,x;
            cin>>u>>v>>x;
            int lca=hld.lca(u,v);
            auto ps=hld.get(u,lca);
            P ret=P{1,0},add=P{1,0};
            for(auto& [L,R]:ps)ret=f(ret,seg.query(L,R).rev);
            ps=hld.get(v,lca,1);
            for(auto& [L,R]:ps)add=f(seg.query(L,R).base,add);
            ret=f(ret,add);
            cout<<ret[0]*x+ret[1]<<'\n';
        }
    }
    return 0;
}