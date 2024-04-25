#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/rbstset.hpp"

int main(){
    int n,q;
    string s;
    read(n,q,s);
    RBSTset<int> tree;
    rep(i,0,n)if(s[i]=='1'){
        tree.insert(i);
    }
    while(q--){
        //tree.dump();
        int t,x;
        read(t,x);
        if(t==0){
            if(!tree.find(x))tree.insert(x);
        }
        if(t==1){
            if(tree.find(x))tree.erase(x);
        }
        if(t==2){
            print((int)tree.find(x));
        }
        if(t==3){
            print(tree.kth_element(tree.lower_bound(x)));
        }
        if(t==4){
            print(tree.kth_element(tree.upper_bound(x)-1));
        }
    }
    return 0;
}