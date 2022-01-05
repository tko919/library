#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "Template/template.hpp"
#include "DataStructure/bit.hpp"

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> a(N);
    rep(i,0,N)cin>>a[i];

    BIT<ll> bit(N);
    rep(i,0,N)bit.add(i,a[i]);
    while(Q--){
        int L,R;
        cin>>L>>R;
        cout<<bit.sum(L,R)<<'\n';
    }
    return 0;
}