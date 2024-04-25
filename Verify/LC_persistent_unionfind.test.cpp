#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/persistentunionfind.hpp"

int main(){
    int n,q;
    read(n,q);
    vector<PersistentUnionFind> buf;
    buf.push_back(PersistentUnionFind(n));
    while(q--){
        int t,k,u,v;
        read(t,k,u,v);
        k++;
        if(t==0){
            buf.push_back(buf[k]);
            buf.back().unite(u,v);
        }
        else{
            buf.push_back(buf[k]);
            print((int)buf.back().same(u,v));
        }
    }
    return 0;
}