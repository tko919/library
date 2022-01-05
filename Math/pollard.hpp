#pragma once
#include "Math/miller.hpp"

mt19937 RND(1341398);
vector<ll> pollard(ll n){
    if(n<=1)return {};
    if(Miller(n))return {n};
    if((n&1)==0){
        vector<ll> v=pollard(n>>1); v.push_back(2);
        return v;
    }
    for(ll x=2,y=2,d;;){
        ll c=RND()%(n-2)+2;
        do{
            x=(__int128_t(x)*x+c)%n;
            y=(__int128_t(y)*y+c)%n;
            y=(__int128_t(y)*y+c)%n;
            d=__gcd(x-y+n,n);
        }while(d==1);
        if(d<n){
            vector<ll> lb=pollard(d),rb=pollard(n/d);
            lb.insert(lb.end(),ALL(rb)); return lb;
        }
    }
}

/**
 * @brief Pollard-Rho
 */