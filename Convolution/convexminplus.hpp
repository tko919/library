#pragma once
#include "Algorithm/monotoneminima.hpp"

template<typename T>vector<T> ConvexMinPlusConvolution(vector<T>& a,vector<T>& b){
    int n=a.size(),m=b.size();
    auto cmp=[&](int i,int j,int k)->bool{
        if(i<k)return false;
        if(i-j>=m)return true;
        return a[j]+b[i-j]>=a[k]+b[i-k];
    };
    auto arg=MonotoneMinima(n+m-1,n,cmp);
    vector<ll> ret(n+m-1);
    rep(i,0,n+m-1)ret[i]=a[arg[i]]+b[i-arg[i]];
    return ret;
}

/**
 * @brief Convex Min Plus Convolution
 * @docs docs/convexminplus.md
 */