#pragma once

#include "Math/matrix.hpp"
#include "Convolution/subset.hpp"

template<typename T>void F(vector<T>& a){ // exp
    static factorial<T> fact(30);
    vector<T> ret(a.size());
    ret[0]=1;
    rep(i,1,a.size()){
        rep(j,1,i+1)ret[i]+=ret[i-j]*a[j]*j;
        ret[i]*=fact.inv(i);
    }
    swap(a,ret);
}

template<typename T>T Hafnian(Matrix<T>& a){
    int n=a.h;
    assert(n%2==0);
    n>>=1;

    vector<Fp> cycle(1<<n);
    vector dp(1<<n,vector<Fp>(n*2));
    rep(base,0,n)dp[1<<base][base*2]=1;
    rep(mask,0,1<<n){
        rep(base,0,n*2)if(mask>>(base>>1)&1){
            T add=dp[mask][base];
            int top=-1;
            rep(i,0,n)if(mask>>i&1)top=i;
            rep(nxt,0,top)if(!(mask>>nxt&1)){
                dp[mask|(1<<nxt)][nxt*2+1]+=add*a[base][nxt*2];
                dp[mask|(1<<nxt)][nxt*2]+=add*a[base][nxt*2+1];
            }
        }
    }
    rep(base,0,n*2)rep(mask,1,1<<n){
        int top=-1;
        rep(i,0,n)if(mask>>i&1)top=i;
        cycle[mask]+=dp[mask][base]*a[base][top*2+1];
    }
    
    SubsetConvolution<Fp> buf;
    auto ret=buf.execute<F>(cycle);
    return ret[(1<<n)-1];
}

/**
 * @brief Hafnian of matrix
*/