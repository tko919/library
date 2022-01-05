#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "Template/template.hpp"
#include "DataStructure/segtree.hpp"

int f(int a,int b){return min(a,b);}
int g(int a,int b){return b;}
int e(){return inf;}

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> a(N);
    rep(i,0,N)cin>>a[i];

    SegmentTree<int,int,f,g,e> seg(N);
    seg.run(a);
    while(Q--){
        int L,R;
        cin>>L>>R;
        cout<<seg.query(L,R)<<'\n';
    }
    return 0;
}