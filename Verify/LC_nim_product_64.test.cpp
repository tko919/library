#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "Template/template.hpp"
#include "Math/nimber.hpp"

int main(){
    int t;
    cin>>t;
    while(t--){
        Nimber a,b;
        cin>>a>>b;
        cout<<a*b<<'\n';
    }
    return 0;
}