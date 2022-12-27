#pragma once
#include "Math/fastdiv.hpp"
#include "Math/primitive.hpp"

struct BinomialQuery{
    struct X{ // for m=p^q
        int p,q,m,delta;
        vector<int> fact,ifac;
        FastDiv im,ip;
        X(){}
        X(int _p,int _q):p(_p),q(_q),ip(p){
            m=1;
            while(_q--)m*=p;
            im=FastDiv(m);
            fact.resize(m);
            ifac.resize(m);
            fact[0]=fact[1]=ifac[0]=ifac[1]=1;
            rep(i,2,m){
                if(i%ip==0)fact[i]=fact[i-1];
                else fact[i]=(ll(fact[i-1])*i)%im;
            }
            ifac[m-1]=minv(fact[m-1],m);
            for(int i=m-2;i>1;i--){
                if(i%ip==p-1)ifac[i]=ifac[i+1];
                else ifac[i]=(ll(ifac[i+1])*(i+1))%im;
            }
            delta=(p==2 and q>=3?0:1);
        }
        int nCr(ll n,ll r){
            if(n<0 or r<0 or n<r)return 0;
            ll s=n-r,ret=1;
            int e0=0,em=0;
            for(int i=1;n;i++){
                ret=(ret*fact[n%m])%im;
                ret=(ret*ifac[r%m])%im;
                ret=(ret*ifac[s%m])%im;
                n=n/ip,r=r/ip,s=s/ip;
                int add=n-r-s;
                e0+=add;
                if(e0>=q)return 0;
                if(i>=q)em^=add;
            }
            if(delta and em&1)ret=m-ret;
            ret=(ret*mpow(p,e0,m))%im;
            return ret;
        }
    };
    int mod;
    vector<ll> ms;
    vector<X> Xs;
    BinomialQuery(int M):mod(M){
        for(int p=2;p*p<=M;p++)if(M%p==0){
            int e=0,base=1;
            while(M%p==0)M/=p,e++,base*=p;
            ms.push_back(base);
            Xs.push_back(X(p,e));
        }
        if(M!=1){
            ms.push_back(M);
            Xs.push_back(X(M,1));
        }
    }
    int nCr(ll n,ll r){
        if(mod==1)return 0;
        vector<ll> ret;
        for(auto& buf:Xs)ret.push_back(buf.nCr(n,r));
        return crt(ret,ms).first;
    }
};

/**
 * @brief Binomial Coefficient for query
*/