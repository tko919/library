#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/sieve.hpp"

FastIO io;
int main(){
    int N,A,B;
    io.read(N,A,B);
    
    auto base=sieve<501010101>(N);
    int pi=0;
    vector<int> ret;
    for(auto& p:base){
        if(pi%A==B)ret.push_back(p);
        pi++;
    }
    io.write(pi,(int)ret.size());
    io.write(ret);
    return 0;
}