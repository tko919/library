#pragma once
#include "FPS/prodofpolys.hpp"

template<typename T>vector<T> SumOfPowers(vector<T>& a,int m){//0<=i<=m,sum_k a_k^i
    int n=a.size();
    vector<Poly<T>> fs(n);
    rep(i,0,n)fs[i]=Poly<T>({T(1),T(-a[i])});
    auto ret=ProdOfPolys(fs);
    ret.resize(m+1);
    ret=ret.log();
    rep(i,0,m+1)ret[i]=-ret[i]*i;
    ret[0]=a.size();
    return ret;
}

/**
 * @brief Enumerate $\sum_k a_k^i$
*/