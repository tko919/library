#pragma once

using ull=unsigned long long;
struct NimberManager{
    ull memo[256][256];
    NimberManager(){
        rep(i,0,256)rep(j,0,256)memo[i][j]=256;
        memo[0][0]=memo[0][1]=memo[1][0]=0;
        memo[1][1]=1;
        rep(i,0,256)rep(j,0,256)memo[i][j]=mul(i,j,8);
    }
    ull mul(ull x,ull y,int k=64){
        if(k<=8&&memo[x][y]<256)return memo[x][y];
        k>>=1;
        ull a=x>>k,b=x^(a<<k),c=y>>k,d=y^(c<<k);
        ull ac=mul(a,c,k),bd=mul(b,d,k),abcd=mul(a^b,c^d,k);
        return mul(ac,1ull<<(k-1),k)^(abcd^bd)<<k^bd;
    }
};
NimberManager Nim;
struct Nimber{
    ull v;
    Nimber(ull _v=0):v(_v){}
    Nimber& operator+=(const Nimber& x){v^=x.v; return *this;}
    Nimber& operator-=(const Nimber& x){v^=x.v; return *this;}
    Nimber& operator*=(const Nimber& x){v=Nim.mul(v,x.v); return *this;}
    Nimber operator+(const Nimber& x)const{return Nimber(*this)+=x;}
    Nimber operator-(const Nimber& x)const{return Nimber(*this)-=x;}
    Nimber operator*(const Nimber& x)const{return Nimber(*this)*=x;}
    bool operator==(const Nimber& x)const{return v==x.v;}
    bool operator!=(const Nimber& x)const{return v!=x.v;}
    friend istream& operator>>(istream& is,Nimber& x){return is>>x.v;}
    friend ostream& operator<<(ostream& os,const Nimber& x){return os<<x.v;}
};

/**
 * @brief Nimber
 */