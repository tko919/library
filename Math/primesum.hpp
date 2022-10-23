#pragma once
#include "Math/sieve.hpp"

template<typename T,T (*F)(ll)>struct PrimeSum{
    ll N,SQ;
    vector<T> lo,hi;
    PrimeSum(ll n=0):N(n),SQ(sqrtl(N)),lo(SQ+1),hi(SQ+1){
        rep(i,1,SQ+1){
            lo[i]=F(i)-1;
            hi[i]=F(N/i)-1;
        }
        auto ps=sieve(SQ);
        for(auto& p:ps){
            ll q=ll(p)*p;
            if(q>N)break;
            T sub=lo[p-1],fp=lo[p]-lo[p-1];
            ll L=min(SQ,N/q),M=SQ/p;
            rep(i,1,M+1)hi[i]-=fp*(hi[i*p]-sub);
            rep(i,M+1,L+1)hi[i]-=fp*(lo[double(N)/(i*p)]-sub);
            for(int i=SQ;i>=q;i--)lo[i]-=fp*(lo[double(i)/p]-sub);
        }
    }
    T operator[](ll x) {
        return (x<=SQ?lo[x]:hi[N/x]);
    }
};

/**
 * @brief Prime Count
 * @docs docs/primecount.md
 */