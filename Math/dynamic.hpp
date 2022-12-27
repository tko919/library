#pragma once
#include "Math/fastdiv.hpp"

struct Fp{
    using u64=uint64_t;
    int v;
    static int get_mod(){return _getmod();}
    static void set_mod(int _m){bar=FastDiv(_m);}
    Fp inv() const{
        int tmp,a=v,b=get_mod(),x=1,y=0;
        while(b){
            tmp=a/b,a-=tmp*b;
            swap(a,b);
            x-=tmp*y;
            swap(x,y);
        }
        if(x<0){x+=get_mod();}
        return x;
    }
    Fp():v(0){}
    Fp(ll x){
        v=x%get_mod();
        if(v<0)v+=get_mod();
    }
    Fp operator-()const{return Fp()-*this;}
    Fp pow(ll t){
        assert(t>=0);
        Fp res=1,b=*this;
        while(t){
            if(t&1)res*=b;
            b*=b;
            t>>=1;
        }
        return res;
    }
    Fp& operator+=(const Fp& x){
        v+=x.v;
        if(v>=get_mod())v-=get_mod();
        return *this;
    }
    Fp& operator-=(const Fp& x){
        v+=get_mod()-x.v;
        if(v>=get_mod())v-=get_mod();
        return *this;
    }
    Fp& operator*=(const Fp& x){
        v=(u64(v)*x.v)%bar;
        return *this;
    }
    Fp& operator/=(const Fp& x){
        (*this)*=x.inv();
        return *this;
    }
    Fp operator+(const Fp& x)const{return Fp(*this)+=x;}
    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}
    Fp operator*(const Fp& x)const{return Fp(*this)*=x;}
    Fp operator/(const Fp& x)const{return Fp(*this)/=x;}
    bool operator==(const Fp& x)const{return v==x.v;}
    bool operator!=(const Fp& x)const{return v!=x.v;}
private:
    static FastDiv bar;
    static int _getmod(){return bar.get();}
};
FastDiv Fp::bar(998244353);

template<typename T>struct factorial {
    vector<T> Fact,Finv,Inv;
    factorial(int maxx){
        Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);
        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;
        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();
        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}
    }
    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}
    T inv(int n){if(n<0)return 0; return Inv[n];}
    T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}
    T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}
    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}
};

/**
 * @brief Dynamic Modint
 */