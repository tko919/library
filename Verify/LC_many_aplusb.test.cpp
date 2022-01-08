#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

int main(){
    FastIO io;
    int t;
    ll a,b;
    io.read(t);
    while(t--){
        io.read(a,b);
        io.write(a+b);
    }
    return 0;
}