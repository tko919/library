#pragma once
#include "Math/sieve.hpp"

template<typename T,T (*pe)(int,int),T (*psum)(ll)>T MultiplicativeSum(ll N){
    ll SQ=sqrtl(N);
    auto ps=sieve(SQ);
    
    T ret=psum(N)+1;
    auto dfs=[&](auto& dfs,ll x,int i,int e,T cur,T pre)->void{
        T nxt=pre*pe(ps[i],e+1);
        ret+=cur*(psum(double(N)/x)-psum(ps[i]));
        ret+=nxt;
        ll L=sqrtl(double(N)/x);
        if(ps[i]<=L)dfs(dfs,x*ps[i],i,e+1,nxt,pre);
        rep(j,i+1,ps.size()){
            if(ps[j]>L)break;
            dfs(dfs,x*ps[j],j,1,cur*pe(ps[j],1),cur);
        }
    };
    rep(i,0,ps.size())dfs(dfs,ps[i],i,1,pe(ps[i],1),1);
    return ret;
}

/**
 * @brief Multiplicative Sum
 * @docs docs/multiplicative.md
 */