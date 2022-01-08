#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "Template/template.hpp"
#include "Math/modint.hpp"
#include "DataStructure/swag.hpp"
#include "Utility/fastio.hpp"

using Fp=fp<998244353>;
using P=array<Fp,2>;
P f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}
P e(){return P{1,0};}

int main(){
    FastIO io;
    int q;
    io.read(q);

    SWAG<P,f,e> swag;
    int t,a,b,x;
    while(q--){
        io.read(t);
        if(t==0){
            io.read(a,b);
            swag.push({a,b});
        }
        else if(t==1)swag.pop();
        else{
            io.read(x);
            P ret=swag.fold();
            cout<<ret[0]*x+ret[1]<<'\n';
        }
    }
    return 0;
}