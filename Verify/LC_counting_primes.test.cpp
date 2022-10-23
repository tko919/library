#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "Template/template.hpp"
#include "Math/primesum.hpp"

ll F(ll x){return x;}

int main(){
    ll n;
    cin>>n;
    PrimeSum<ll,F> pc(n);
    cout<<pc[n]<<'\n';
    return 0;
}