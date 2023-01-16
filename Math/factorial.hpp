#pragma once

template<typename T>struct factorial {
    vector<T> Fact,Finv,Inv;
    factorial(int maxx){
        Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);
        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;
        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=T(1)/Fact[maxx-1];
        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}
    }
    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}
    T inv(int n){if(n<0)return 0; return Inv[n];}
    T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}
    T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}
    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}
};

/**
 * @brief Factorial
*/