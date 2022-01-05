#pragma once

template<typename T>struct BIT{
    int n; T all=0; vector<T> val;
    BIT(int _n):n(_n),val(_n+10){}
    void clear(){val.assign(n+10,0); all=T();}
    void add(int i,T x){
        for(i++;i<=n;i+=(i&-i))val[i]+=x;
        all+=x;
    }
    T sum(int i){
        T res=0;
        for(;i;i-=(i&-i))res+=val[i];
        return res;
    }
    T sum(int L,int R){return sum(R)-sum(L);} // [L,R)
};

/**
 * @brief Binary Indexed Tree
 */