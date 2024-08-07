#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "DataStructure/dequeswag.hpp"

using Fp=fp<998244353>;
using P=pair<Fp,Fp>;
P f(P a,P b){return {a.first*b.first,a.second*b.first+b.second};}
P e0(){return {1,0};}

int main(){
    int Q;
    read(Q);
    SWAGdeque<P,f,e0> swag;
    while(Q--){
        int t;
        read(t);
        if(t==0){
            int a,b;
            read(a,b);
            swag.push_front({a,b});
        }
        if(t==1){
            int a,b;
            read(a,b);
            swag.push_back({a,b});
        }
        if(t==2)swag.pop_front();
        if(t==3)swag.pop_back();
        if(t==4){
            int x;
            read(x);
            auto [p,q]=swag.fold();
            print((p*x+q).v);
        }
    }
    return 0;
}
