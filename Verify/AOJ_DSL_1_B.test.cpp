#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/weightedunionfind.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    WeightedUnionFind<int> uni(n);
    while(q--){
        int t;
        io.read(t);
        if(t==0){
            int x,y,z;
            io.read(x,y,z);
            uni.unite(x,y,z);
        }
        else{
            int x,y;
            io.read(x,y);
            if(uni.same(x,y))io.write(uni.diff(x,y));
            else io.write('?');
        }
    }
    return 0;
}