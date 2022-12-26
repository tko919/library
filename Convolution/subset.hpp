#pragma once

template<typename T>struct SubsetConvolution{
    const int LG;
    vector<int> bpc;
    SubsetConvolution(int lg=20):LG(lg),bpc(1<<LG){
        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;
    }
    void zeta(vector<vector<T>>& a){
        int n=a.size();
        for(int w=1;w<n;w<<=1){
            for(int k=0;k<n;k+=w*2)rep(i,0,w){ // k+i:wを含まないbitmaskを走査
                rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];
            }
        }
    }
    void mobius(vector<vector<T>>& a){
        int n=a.size(),m=__lg(n);
        for(int w=n>>1;w;w>>=1){
            for(int k=0;k<n;k+=w*2)rep(i,0,w){
                rep(j,bpc[k+w+i],m+1)a[k+w+i][j]-=a[k+i][j];
            }
        }
    }
    vector<T> mult(vector<T>& a,vector<T>& b,bool same=0){
        assert(a.size()==b.size());
        int n=a.size(),m=__lg(n);
        vector A(n,vector<T>(m+1)),B(n,vector<T>(m+1));
        rep(i,0,n){
            A[i][bpc[i]]=a[i];
            B[i][bpc[i]]=b[i];
        }
        zeta(A);
        if(same)B=A;
        else zeta(B);
        rep(i,0,n){
            vector<T> c(m+1);
            rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];
            swap(A[i],c);
        }
        mobius(A);
        vector<T> ret(n);
        rep(i,0,n)ret[i]=A[i][bpc[i]];
        return ret;
    }
    template<void (*F)(vector<T>&)>vector<T> execute(vector<T>& a){
        int n=a.size(),m=__lg(n);
        vector A(n,vector<T>(m+1));
        rep(i,0,n)A[i][bpc[i]]=a[i];
        zeta(A);
        rep(i,0,n)F(A[i]);
        mobius(A);
        vector<T> ret(n);
        rep(i,0,n)ret[i]=A[i][bpc[i]];
        return ret;
    }
};

/**
 * @brief Subset Convolution
 */