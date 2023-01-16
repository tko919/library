#pragma once
#include "Math/sieve.hpp"

template<typename T>vector<T> powertable(int n,ll k){ //0^k,1^k,..,n^k
    assert(k>=0);
    auto ps=sieve(n+1);
    vector<T> f(n+1,1);
    if(k)f[0]=0;
    for(auto& p:ps){
        T pk=T(p).pow(k);
        for(ll q=p;q<=n;q*=p){
            for(ll i=q;i<=n;i+=q)f[i]*=pk;
        }
    }
    return f;
}

/**
 * @brief Enumrate n^k
*/