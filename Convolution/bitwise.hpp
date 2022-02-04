#pragma once

template<typename T>void zeta(vector<T>& a){
    int n=__lg(a.size());
    rep(k,0,n)rep(mask,0,1<<n){
        if(mask>>k&1)a[mask]+=a[mask^(1<<k)];
    }
}
template<typename T>void mobius(vector<T>& a){
    int n=__lg(a.size());
    rep(k,0,n)rep(mask,0,1<<n){
        if(mask>>k&1)a[mask]-=a[mask^(1<<k)];
    }
}
template<typename T>void fwt(vector<T>& a){
    int n=__lg(a.size());
    rep(k,0,n)rep(mask,0,1<<n){
        if(!(mask>>k&1)){
            T x=a[mask],y=a[mask|(1<<k)];
            a[mask]=x+y,a[mask|(1<<k)]=x-y;
        }
    }
}

/**
 * @brief Bitwise Convolution
 * @docs docs/bitwise.md
 */