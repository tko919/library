#pragma once
#include "Math/factorial.hpp"

template<typename T>vector<T> PrefixSumOfPowers(ll n,int k){ // 0<=i<=k,sum_n=0^{N-1} n^i
    factorial<T> fact(k+2);
    Poly<T> num(k+1),den(k+1);
    num[0]=n,den[0]=1;
    rep(i,0,k)num[i+1]=num[i]*n;
    rep(i,0,k+1){
        num[i]*=fact.fact(i+1,1);
        den[i]=fact.fact(i+1,1);
    }
    num*=den.inv();
    num.resize(k+1);
    rep(i,0,k+1)num[i]*=fact.fact(i);
    return num;
}

/**
 * @brief Enumerate $\sum_{k=0}^{N-1} k^i$
*/