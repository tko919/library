#pragma once
#include "Math/primitive.hpp"

template<typename T>vector<T> MultivariateCyclic
    (vector<T> f,vector<T> g,vector<int>& a){
    int MO=T::get_mod();
    int k=a.size(),n=1;
    for(auto& x:a)n*=x;
    T pr=getPrimitiveRoot(MO),ipr=T(pr).inv();

    int offset=1;
    rep(x,0,k){
        assert((MO-1)%a[x]==0);
        T w=pr.pow((MO-1)/a[x]);
        rep(i,0,n)if(i%(offset*a[x])<offset){
            vector<T> na(a[x]),nb(a[x]);
            rep(j,0,a[x]){
                na[j]=f[i+offset*j];
                nb[j]=g[i+offset*j];
            }
            na=MultievalGeomSeq(na,T(1),w,a[x]);
            nb=MultievalGeomSeq(nb,T(1),w,a[x]);
            rep(j,0,a[x]){
                f[i+offset*j]=na[j];
                g[i+offset*j]=nb[j];
            }
        }
        offset*=a[x];
    }

    rep(i,0,n)f[i]*=g[i];
    
    offset=1;
    rep(x,0,k){
        T iw=ipr.pow((MO-1)/a[x]);
        rep(i,0,n)if(i%(offset*a[x])<offset){
            vector<T> na(a[x]);
            rep(j,0,a[x])na[j]=f[i+offset*j];
            na=MultievalGeomSeq(na,T(1),iw,a[x]);
            rep(j,0,a[x])f[i+offset*j]=na[j];
        }
        offset*=a[x];
    }
    T ninv=T(n).inv();
    rep(i,0,n)f[i]*=ninv;
    return f;
}

/**
 * @brief Multivarate Convolution Cyclic
*/