#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/binomquery.hpp"

FastIO io;
int main(){
    int q,m;
    io.read(q,m);
    BinomialQuery buf(m);
    while(q--){
        ll n,r;
        io.read(n,r);
        io.write(buf.nCr(n,r));
    }
    return 0;
}