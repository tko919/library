#pragma once

template<typename T>struct QBinom{
    int ord;
    vector<T> fact,ifact;
    QBinom(T q,int sz){
        vector<T> base;
        T x=1;
        rep(i,0,sz){
            base.push_back(x);
            x=x*q+1;
            if(x==0)break;
        }
        ord=SZ(base);
        fact.push_back(1);
        rep(i,0,ord){
            fact.push_back(fact.back()*base[i]);
        }
        ifact.push_back(T(1)/fact.back());
        rrep(i,0,ord){
            ifact.push_back(ifact.back()*base[i]);
        }
        reverse(ALL(ifact));
        ord++;
        show(fact,ifact,ord);
    }  
    T binom(int n,int r){
        if(r<0 or n<r)return 0;
        if(n<ord)return fact[n]*ifact[r]*ifact[n-r];
        
        int n1=n/ord,n2=n%ord;
        int r1=r/ord,r2=r%ord;
        return nCr<T>(n1, r1) * binom(n2, r2);
    }
};

/**
 * @brief $q$-binomial
 */