#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/hashmap.hpp"

int main(){
    FastIO io;
    int q,t;
    ll k,v;
    io.read(q);
    HashMap<ll,ll> mp;
    while(q--){
        io.read(t,k);
        if(t==0){
            io.read(v);
            mp[k]=v;
        }
        else{
            io.write(mp[k]);
        }
    }
    return 0;
}