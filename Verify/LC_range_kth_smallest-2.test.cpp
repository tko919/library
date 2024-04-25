#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/persistentrbstset.hpp"

const int LIM=201010*20*5;
using np=PRBSTset<int,LIM>::np;

int main(){
    int n,q;
    read(n,q);
    vector<int> a(n);
    read(a);

    vector<int> zip;
    rep(i,0,n)zip.push_back(a[i]);
    sort(ALL(zip));
    zip.erase(unique(ALL(zip)),zip.end());
    rep(i,0,n)a[i]=lower_bound(ALL(zip),a[i])-zip.begin();

    PRBSTset<int,LIM> manager;
    vector<np> buf(1,nullptr);
    rep(i,0,n)buf.push_back(manager.insert(buf.back(),a[i]));
    int L,R,k;
    
    while(q--){
        read(L,R,k);
        int lb=0,rb=zip.size();
        while(rb-lb>1){
            int mid=(lb+rb)>>1;
            int cnt=manager.upper_bound(buf[R],mid)-manager.upper_bound(buf[L],mid);
            if(cnt<=k)lb=mid;
            else rb=mid;
        }
        print(zip[lb]);
    }
    return 0;
}