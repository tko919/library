#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/hashmap.hpp"

int main(){
    int q,t;
    ll k,v;
    read(q);
    HashMap<ll,ll> mp;
    while(q--){
        read(t,k);
        if(t==0){
            read(v);
            mp[k]=v;
        }
        else{
            print(mp[k]);
        }
    }
    return 0;
}