#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "Template/template.hpp"
#include "Algorithm/mo.hpp"
#include "DataStructure/bit.hpp"

int a[101010];
ll ret[101010],cur=0;
BIT<int> bit(101010);

void Mo::addl(int i){
    cur+=bit.sum(a[i]);
    bit.add(a[i],1);
}
void Mo::addr(int i){
    cur+=bit.all-bit.sum(a[i]);
    bit.add(a[i],1);
}
void Mo::dell(int i){
    bit.add(a[i],-1);
    cur-=bit.sum(a[i]);
}
void Mo::delr(int i){
    bit.add(a[i],-1);
    cur-=bit.all-bit.sum(a[i]);
}
void Mo::out(int i){
    ret[i]=cur;
}

int main(){
    int n,q;
    cin>>n>>q;
    using P=pair<int,int>;
    vector<P> vs(n);
    rep(i,0,n){
        cin>>vs[i].first;
        vs[i].second=i;
    }
    sort(ALL(vs));
    rep(i,0,n)a[vs[i].second]=i;
    Mo mo(n);
    rep(i,0,q){
        int L,R;
        cin>>L>>R;
        mo.add(L,R);
    }
    mo.run();
    rep(i,0,q)cout<<ret[i]<<'\n';
    return 0;
}