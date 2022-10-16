#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "Template/template.hpp"
#include "DataStructure/bit.hpp"

ll ADD(ll a,ll b){return a+b;}
ll SUB(ll a,ll b){return a-b;}

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> a(N);
    rep(i,0,N)cin>>a[i];

    BIT<ll,ADD,SUB> bit(N);
    rep(i,0,N)bit.add(i,a[i]);
    while(Q--){
        int t;
        cin>>t;
        if(t==0){
            int p,x;
            cin>>p>>x;
            bit.add(p,x);
        }
        else{
            int L,R;
            cin>>L>>R;
            cout<<bit.sum(L,R)<<'\n';
        }
    }
    return 0;
}