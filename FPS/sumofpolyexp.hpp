#pragma once
#include "Math/factorial.hpp"
#include "FPS/interpolate.hpp"

template<typename T>T LimitSumOfPolyExp(vector<T>& f,T r){ //sum_{k=0}^inf r^k*f(k)
    assert(r!=1);
    int d=f.size()-1;
    factorial<T> fact(d+5);
    vector<T> rs(d+1);
    rs[0]=1;
    rep(i,0,d)rs[i+1]=rs[i]*r;
    T c,add;
    rep(i,0,d+1){
        add+=rs[i]*f[i];
        if((d-i)&1)c-=fact.nCr(d+1,i+1)*rs[d-i]*add;
        else c+=fact.nCr(d+1,i+1)*rs[d-i]*add;
    }
    c/=(-r+1).pow(d+1);
    return c;
}

template<typename T>T SumOfPolyExp(vector<T>& f,T r,ll n){ //sum_{k=0}^{n-1} r^k*f(k)
    n--;
    if(n<0)return 0;
    int d=f.size()-1;
    vector<T> rs(d+1),rui(d+1);
    rs[0]=1;
    rep(i,0,d)rs[i+1]=rs[i]*r;
    rep(i,0,d+1)rui[i]=rs[i]*f[i];
    rep(i,0,d)rui[i+1]+=rui[i];
    if(r==1)return Interpolate(rui,n);
    else{
        factorial<T> fact(d+2);
        T c;
        rep(i,0,d+1)c+=fact.nCr(d+1,i+1)*rs[d-i]*rui[i]*((d-i)&1?-1:1);
        c/=T(-r+1).pow(d+1);
        vector<T> ys(d+1);
        T pwr=1,invr=T(r).inv();
        rep(i,0,d+1)ys[i]=(rui[i]-c)*pwr,pwr*=invr;
        return T(r).pow(n)*Interpolate(ys,n)+c;
    }
}

/**
 * @brief $\sum_{k} r^k\cdot poly(k)$
*/