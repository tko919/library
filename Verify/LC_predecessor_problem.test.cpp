#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/rbstset.hpp"

FastIO io;
int main(){
    int n,q;
    string s;
    io.read(n,q,s);
    RBSTset<int> tree;
    rep(i,0,n)if(s[i]=='1'){
        tree.insert(i);
    }
    while(q--){
        //tree.dump();
        int t,x;
        io.read(t,x);
        if(t==0){
            if(!tree.find(x))tree.insert(x);
        }
        if(t==1){
            if(tree.find(x))tree.erase(x);
        }
        if(t==2){
            io.write((int)tree.find(x));
        }
        if(t==3){
            io.write(tree.kth_element(tree.lower_bound(x)));
        }
        if(t==4){
            io.write(tree.kth_element(tree.upper_bound(x)-1));
        }
    }
    return 0;
}