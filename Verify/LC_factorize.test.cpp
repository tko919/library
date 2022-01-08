#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "Template/template.hpp"
#include "Math/pollard.hpp"

int main(){
    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        auto ps=Pollard(n);
        cout<<ps.size()<<'\n';
        sort(ALL(ps));
        for(auto& p:ps)cout<<p<<'\n';
    }
    return 0;
}