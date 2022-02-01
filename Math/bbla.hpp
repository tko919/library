#pragma once

#include "FPS/berlekampmassey.hpp"
#include "Utility/random.hpp"

Random genBBLA;
template<typename T>Poly<T> RandPoly(int n){
    Poly<T> ret(n);
    for(auto& x:ret)x=genBBLA.get(1,T::get_mod()-1);
    return ret;
}
template<typename T>struct SparseMatrix{
    vector<T> base;
    vector<map<int,T>> extra;
    SparseMatrix(int n,T v=0):base(n,v),extra(n){}
    int size()const{return base.size();}
    inline void add(int i,int j,T x){extra[i][j]+=x;}
    friend Poly<T> operator*(const SparseMatrix<T>& A,const Poly<T>& b){
        int n=A.size();
        Poly<T> ret(n);
        T sum;
        for(auto& v:b)sum+=v;
        rep(i,0,n){
            T add=sum;
            for(auto& [j,v]:A.extra[i]){
                ret[i]+=v*b[j];
                add-=b[j];
            }
            ret[i]+=add*A.base[i];
        }
        return ret;
    }
    void mul(int i,T x){
        base[i]*=x;
        for(auto& [_,v]:extra[i])v*=x;
    }
};

template<typename T>Poly<T> MinPolyforVector(const vector<Poly<T>>& b){
    int n=b.size(),m=b[0].size();
    Poly<T> base=RandPoly<T>(m),a(n);
    rep(i,0,n)rep(j,0,m)a[i]+=base[j]*b[i][j];
    return Poly<T>(BerlekampMassey(a)).rev();
}
template<typename T>Poly<T> MinPolyforMatrix(const SparseMatrix<T>& A){
    int n=A.size();
    Poly<T> base=RandPoly<T>(n);
    vector<Poly<T>> b(n*2+1);
    rep(i,0,n*2+1)b[i]=base,base=A*base;
    return MinPolyforVector(b);
}
template<typename T>Poly<T> FastPow(const SparseMatrix<T>& A,Poly<T> b,ll t){
    int n=A.size();
    auto mp=MinPolyforMatrix(A).rev();
    Poly<T> cs({T(1)}),base({T(0),T(1)});
    while(t){
        if(t&1){
            cs*=base;
            cs%=mp;
        }
        base=base.square();
        base%=mp;
        t>>=1;
    }
    Poly<T> ret(n);
    for(auto& c:cs)ret+=b*c,b=A*b;
    return ret;
}
template<typename T>T FastDet(const SparseMatrix<T>& A){
    int n=A.size();
    for(;;){
        Poly<T> d=RandPoly<T>(n);
        SparseMatrix<T> AD=A;
        rep(i,0,n)AD.mul(i,d[i]);
        auto mp=MinPolyforMatrix(AD);
        if(mp.back()==0)return 0;
        if(int(mp.size())!=n+1)continue;
        T ret=mp.back(),base=1;
        if(n&1)ret=-ret;
        for(auto& v:d)base*=v;
        return ret/base;
    }
}

/**
 * @brief Black Box Linear Algebra
 */