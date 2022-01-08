#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "Template/template.hpp"
#include "Math/floorsum.hpp"

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        cout<<FloorSum(n,a,b,m)<<'\n';
    }
    return 0;
}