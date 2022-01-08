#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "Template/template.hpp"
#include "Math/primitive.hpp"

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,m;
        cin>>a>>b>>m;
        cout<<ModLog(a,b,m)<<'\n';
    }
    return 0;
}