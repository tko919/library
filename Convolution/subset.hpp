#pragma once

template<typename T>vector<T> SubsetConvolution(vector<T>& a,vector<T>& b){
    int m=a.size(),n=__lg(m);
    vector aa(n+1,vector<T>(m)),bb(n+1,vector<T>(m)),cc(n+1,vector<T>(m));
    rep(i,0,m){
        aa[__builtin_popcountll(i)][i]=a[i];
        bb[__builtin_popcountll(i)][i]=b[i];
    }
    rep(base,0,n+1){
        rep(i,0,n)rep(mask,0,m)if(!(mask>>i&1)){
            aa[base][mask|(1<<i)]+=aa[base][mask];
            bb[base][mask|(1<<i)]+=bb[base][mask];
        }
    }
    rep(i,0,n+1)rep(j,0,n+1-i)rep(mask,0,m){
        cc[i+j][mask]+=aa[i][mask]*bb[j][mask];
    }
    rep(base,0,n+1){
        rep(i,0,n)rep(mask,0,m)if(mask>>i&1){
            cc[base][mask]-=cc[base][mask^(1<<i)];
        }
    }
    vector<T> ret(m);
    rep(i,0,m){
        ret[i]=cc[__builtin_popcountll(i)][i];
    }
    return ret;
}

/**
 * @brief Subset Convolution
 */