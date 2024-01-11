#pragma once

template<typename T,int LG=20>struct SubsetConvolution{
    using POL=array<T,LG+1>;
    vector<int> bpc;
    vector<T> inv;
    SubsetConvolution():bpc(1<<LG),inv(LG+1){
        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;
        rep(i,1,LG+1)inv[i]=T(1)/i;
    }
    void zeta(vector<POL>& a){
        int n=a.size();
        for(int w=1;w<n;w<<=1){
            for(int k=0;k<n;k+=w*2)rep(i,0,w){
                rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];
            }
        }
    }
    void mobius(vector<POL>& a){
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
        vector<POL> A(n),B(n);
        rep(i,0,n){
            A[i][bpc[i]]=a[i];
            B[i][bpc[i]]=b[i];
        }
        zeta(A);
        if(same)B=A;
        else zeta(B);
        rep(i,0,n){
            POL c={};
            rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];
            swap(A[i],c);
        }
        mobius(A);
        vector<T> ret(n);
        rep(i,0,n)ret[i]=A[i][bpc[i]];
        return ret;
    }
    vector<T> exp(vector<T>& a){
        int n=a.size(),m=__lg(n);
        vector<POL> A(n);
        rep(i,0,n)A[i][bpc[i]]=a[i];
        zeta(A);
        rep(i,0,n){
            POL ret={};
            ret[0]=1;
            rep(j,1,m+1){
                rep(k,1,j+1)ret[j]+=ret[j-k]*A[i][k]*k;
                ret[j]*=inv[j];
            }
            swap(A[i],ret);
        }
        mobius(A);
        vector<T> ret(n);
        rep(i,0,n)ret[i]=A[i][bpc[i]];
        return ret;
    }
    vector<T> log(vector<T>& a){
        int n=a.size(),m=__lg(n);
        vector<POL> A(n);
        rep(i,0,n)A[i][bpc[i]]=a[i];
        zeta(A);
        rep(i,0,n){
            POL ret={};
            rep(j,1,m+1){
                ret[j]=A[i][j]*j;
                rep(k,1,j)ret[j]-=ret[k]*A[i][j-k]*k;
                ret[j]*=inv[j];
            }
            swap(A[i],ret);
        }
        mobius(A);
        vector<T> ret(n);
        rep(i,0,n)ret[i]=A[i][bpc[i]];
        return ret;
    }
    vector<T> sqrt(vector<T>& a){
        int n=a.size(),m=__lg(n);
        vector<POL> A(n);
        rep(i,0,n)A[i][bpc[i]]=a[i];
        zeta(A);
        rep(i,0,n){
            POL ret={};
            ret[0]=1;
            rep(j,1,m+1){
                ret[j]=A[i][j];
                rep(k,1,j)ret[j]-=ret[k]*ret[j-k];
                ret[j]*=inv[2];
            }
            swap(A[i],ret);
        }
        mobius(A);
        vector<T> ret(n);
        rep(i,0,n)ret[i]=A[i][bpc[i]];
        return ret;
    }
};

/**
 * @brief Subset Convolution
 */