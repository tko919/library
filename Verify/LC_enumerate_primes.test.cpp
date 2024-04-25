#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "Math/sieve.hpp"

int main(){
    int N,A,B;
    read(N,A,B);
    
    auto base=sieve<501010101>(N);
    int pi=0;
    vector<int> ret;
    for(auto& p:base){
        if(pi%A==B)ret.push_back(p);
        pi++;
    }
    print(pi,(int)ret.size());
    print(ret);
    return 0;
}