#pragma once

class StirlingNumberQuery{
    const int p;
    vector<vector<int>> binom,F,S;
    ll nCr(ll n,ll k){
        if(n<0 or k<0 or n<k)return 0;
        ll res=1;
        while(n){
            res=(res*binom[n%p][k%p])%p;
            n/=p; k/=p;
        }
        return res;
    }
public:
    StirlingNumberQuery(int _p):p(_p){
        binom.resize(p,vector<int>(p));
        F.resize(p,vector<int>(p));
        S.resize(p,vector<int>(p));
        binom[0][0]=F[0][0]=S[0][0]=1;
        rep(n,1,p)rep(k,0,n+1){
            if(k)binom[n][k]=binom[n-1][k-1];
            binom[n][k]=(binom[n][k]+binom[n-1][k])%p;

            if(k)F[n][k]=F[n-1][k-1];
            F[n][k]=(F[n][k]+ll(p-n+1)*F[n-1][k])%p;
            
            if(k)S[n][k]=S[n-1][k-1];
            S[n][k]=(S[n][k]+ll(k)*S[n-1][k])%p;
        }
    }
    int FirstKind(ll n,ll k){
        if(n<0 or k<0 or k>n)return 0;
        ll i=n/p,j=n%p;
        if(k<i)return 0;
        ll a=(k-i)/(p-1),b=(k-i)%(p-1);
        if(b==0 and j)b+=p-1,a--;
        if(a<0 or a>i or b>j)return 0;
        int res=(nCr(i,a)*F[j][b])%p;
        if((i+a)&1)res=(p-res)%p;
        return res;
    }
    int SecondKind(ll n,ll k){
        if(n<0 or k<0 or k>n)return 0;
        if(n==0)return 1;
        ll i=k/p,j=k%p;
        if(n<i)return 0;
        ll a=(n-i)/(p-1),b=(n-i)%(p-1);
        if(b==0)b+=p-1,a--;
        if(a<0 or b<j)return 0;
        if(b==p-1 and j==0)return nCr(a,i-1);
        else return (nCr(a,i)*S[b][j])%p;
    }
};

/**
 * @brief Stirling Number for query
 */