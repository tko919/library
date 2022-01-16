#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/persistentunionfind.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<PersistentUnionFind> buf;
    buf.push_back(PersistentUnionFind(n));
    while(q--){
        int t,k,u,v;
        io.read(t,k,u,v);
        k++;
        if(t==0){
            buf.push_back(buf[k]);
            buf.back().unite(u,v);
        }
        else{
            buf.push_back(buf[k]);
            io.write((int)buf.back().same(u,v));
        }
    }
    return 0;
}