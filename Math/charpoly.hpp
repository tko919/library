#pragma once
#include "Math/matrix.hpp"

template<typename T>vector<T> CharPoly(Matrix<T> a){
    // to Hessenberg
    //reference:http://www.oishi.info.waseda.ac.jp/~samukawa/eigvieta.pdf
    int n=a.h;
    rep(s,0,n-2){
        rep(j,s+1,n)if(a[j][s]!=0){
            swap(a[j],a[s+1]);
            rep(i,0,n)swap(a[i][j],a[i][s+1]);
            break;
        }
        if(a[s+1][s]==0)continue;
        T X=T(1)/a[s+1][s];
        rep(i,s+2,n){
            T base=a[i][s]*X;
            rep(j,0,n)a[i][j]-=a[s+1][j]*base;
            rep(j,0,n)a[j][s+1]+=a[j][i]*base;
        }
    }
    vector dp(n+1,vector<T>(n+1));
    dp[0][0]=1;
    rep(i,0,n){
        rep(k,0,i+1){
            dp[i+1][k+1]+=dp[i][k];
            dp[i+1][k]-=dp[i][k]*a[i][i];
        }
        T prod=1;
        for(int j=i-1;j>=0;j--){
            prod*=a[j+1][j];
            T base=prod*a[j][i];
            rep(k,0,i+1)dp[i+1][k]-=dp[j][k]*base;
        }
    }
    return dp[n];
}

/**
 * @brief Characteristic Polynomial
*/