#define PROBLEM "https://yukicoder.me/problems/no/1781"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/multiplicative.hpp"
#include "Math/modint.hpp"
#include "Math/primecount.hpp"
ll F(ll x){return x;}
PrimeSum<ll,F> buf;

using Fp=fp<998244353>;
Fp memo[50];
Fp pe(int p,int e){return memo[e];}
Fp psum(ll x){return memo[1]*buf[x];}

FastIO io;
int main(){
    ll n,m;
    io.read(n,m);

    rep(e,0,45)memo[e]=Fp(e+1).pow(n);
    buf=PrimeSum<ll,F>(m);

    auto ret=MultiplicativeSum<Fp,pe,psum>(m);
    io.write(ret.v);
    return 0;
}