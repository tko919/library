#pragma once
#include "Math/factorial.hpp"

template<typename T>vector<T> Bernoulli(int n){
    factorial<T> fact(n+2);
    Poly<T> f(n+1);
    rep(i,0,n+1)f[i]=fact.fact(i+1,1);
    f=f.inv();
    rep(i,0,n+1)f[i]*=fact.fact(i);
    return f;
}

template<typename T>vector<T> Partition(int n){
    Poly<T> f(n+1);
    f[0]=1;
    rep(k,1,n+1){
        if(1LL*k*(3*k+1)/2<=n)f[1LL*k*(3*k+1)/2]+=(k&1?-1:1);
        if(1LL*k*(3*k-1)/2<=n)f[1LL*k*(3*k-1)/2]+=(k&1?-1:1);
    }
    return f.inv();
}

template<typename T>vector<T> StirlingNumber1st(int n){
    if(n==0)return Poly<T>({T(1)});
    Poly<T> f({T(0),T(1)});
    for(int LG=topbit(n)-1;LG>=0;LG--){
        int m=n>>LG;
        f*=f.shift(m>>1);
        if(m&1)f=(f<<1)+f*T(m-1);
    }
    rep(i,0,n+1)if((n-i)&1)f[i]=-f[i];
    return f;
}

template<typename T>vector<T> StirlingNumber2nd(int n){
    if(n==0)return Poly<T>({T(1)});
    factorial<T> fact(n+1);
    Poly<T> f(n+1),g(n+1);
    rep(i,0,n+1){
        f[i]=Fp(i).pow(n)*fact.fact(i,1);
        g[i]=fact.fact(i,1);
        if(i&1)g[i]=-g[i];
    }
    f*=g;
    f.resize(n+1);
    return f;
}

template<typename T>vector<T> Bell(int n){
    Poly<T> f(n+1);
    if(n)f[1]=1;
    rep(i,2,n+1)f[i]=f[i-1]/i;
    f=f.exp();
    T fac=1;
    rep(i,2,n+1)fac*=i,f[i]*=fac;
    return f;
}

/**
 * @brief Famous Sequence
*/