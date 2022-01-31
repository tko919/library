#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/dualsegtree.hpp"

int f(int a,int b){
    if(b!=INT32_MAX)return b;
    else return a;
}
int e(){return INT32_MAX;}

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    
    DualSegmentTree<int,f,e> seg(n);
    int c,L,R,x;
    while(q--){
        io.read(c);
        if(c==0){
            io.read(L,R,x);
            R++;
            seg.update(L,R,x);
        }
        else{
            io.read(x);
            io.write(seg.query(x));
        }
    }
    return 0;
}