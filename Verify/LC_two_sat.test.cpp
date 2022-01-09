#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "Template/template.hpp"
#include "Math/twosat.hpp"

int main(){
    string tmp;
    int n,m; cin>>tmp>>tmp>>n>>m;
    TwoSat ts(n+1);
    rep(i,0,m){
        int a,b; cin>>a>>b>>tmp;
        ts.either(abs(a),a>0,abs(b),b>0);
    }
    if(!ts.satisfiable()){
        puts("s UNSATISFIABLE");
        return 0;
    }
    puts("s SATISFIABLE");
    cout<<"v ";
    auto res=ts.res;
    rep(i,1,n+1){
        if(res[i])cout<<i<<' ';
        else cout<<-i<<' ';
    }
    puts("0");
    return 0;
}