#pragma once
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"

using F1=fp<167772161>; using F2=fp<469762049>;
NTT<F1,3> ntt1(25); NTT<F2,3> ntt2(25);
const F1 coeff=F1(F2::get_mod()).inv();
template<int D>struct bigint{
    static const int B=pow(10,D);
    int sign=0; vector<ll> v;
    static int get_D(){return D;}
    static int get_B(){return B;}
    bigint(ll x=0){
        if(x<0)x*=-1,sign=1;
        while(x){v.push_back(x%B); x/=B;}
    }
    bigint(string s){
        if(s[0]=='-')s.erase(s.begin()),sign=1;
        int add=0,cnt=0,base=1;
        while(s.size()){
            if(cnt==D){
                v.push_back(add);
                cnt=0; add=0; base=1;
            }
            add=(s.back()-'0')*base+add;
            cnt++; base*=10; s.pop_back();
        } if(add)v.push_back(add);
    }
    bigint operator-()const{bigint res=*this; res.sign^=1;return res;}
    bigint abs()const{bigint res=*this; res.sign=0; return res;}
    ll& operator[](const int i){return v[i];}
    int size()const{return v.size();}
    void norm(){
        rep(i,0,v.size()-1){
            if(v[i]>=0){v[i+1]+=v[i]/B; v[i]%=B;}
            else{int c=(-v[i]+B-1)/B; v[i]+=c*B; v[i+1]-=c;}
        }
        while(!v.empty() and v.back()>=B){
            int c=v.back()/B;
            v.back()%=B; v.push_back(c);
        }
        while(!v.empty() and v.back()==0)v.pop_back();
    }
    string to_str()const{
        string res;
        if(v.empty())return "0";
        if(sign)res+='-';
        res+=to_string(v.back());
        for(int i=v.size()-2;i>=0;i--){
            string add; int w=v[i];
            rep(_,0,D){
                add+=('0'+(w%10)); w/=10;
            } reverse(ALL(add)); res+=add;
        } return res;
    }
    friend istream& operator>>(istream& is,bigint<D>& x){
        string tmp; is>>tmp; x=bigint(tmp); return is;
    }
    friend ostream& operator<<(ostream& os,bigint<D> x){
        os<<x.to_str(); return os;
    }
    bigint& operator<<=(const int& x){
        if(!v.empty()){
            vector<ll> add(x,0);
            v.insert(v.begin(),ALL(add));
        } return *this;
    }
    bigint& operator>>=(const int& x){
        v=vector<ll>(v.begin()+min(x,(int)v.size()),v.end());
        return *this;
    }
    bigint& operator+=(const bigint& x){
        if(sign!=x.sign){*this-=(-x); return *this;}
        if((int)v.size()<(int)x.size())v.resize(x.size(),0);
        rep(i,0,x.size()){v[i]+=x.v[i];} norm(); return *this;
    }
    bigint& operator-=(const bigint& x){
        if(sign!=x.sign){*this+=(-x); return *this;}
        if(abs()<x.abs()){*this=x-(*this); sign^=1; return *this;}
        rep(i,0,x.size()){v[i]-=x.v[i];} norm(); return *this;
    }
    bigint& operator*=(const bigint& x){
        sign^=x.sign;
        auto v1=ntt1.conv<ll>(v,x.v);
        auto v2=ntt2.conv<ll>(v,x.v);
        v.assign(v1.size(),0);
        rep(i,0,v1.size()){
            ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;
            for(int j=i;val;j++){
                if(j==(int)v.size())v.push_back(0);
                v[j]+=val%B; val/=B;
            }
        } norm(); return *this;
    }
    bigint& operator/=(const bigint& x){  
        bigint a=abs(),b=x.abs(); sign^=x.sign;
        if(a<b)return *this=bigint();
        int d=a.size()-b.size()+1;
        bigint inv(1LL*B*B/b.v.back()),pre;
        int cur=2,bcur=1; pre=bigint(0);
        while(inv!=pre or bcur<b.size()){
            bcur=min(bcur<<1,b.size());
            bigint c; c.v=vector<ll>(b.v.end()-bcur,b.v.end());
            pre=inv; inv*=((bigint(2)<<(cur+bcur-1))-inv*c);
            cur=min(cur<<1,d);
            inv.v=vector<ll>(inv.v.end()-cur,inv.v.end());
        }
        inv.v=vector<ll>(inv.v.end()-d,inv.v.end());
        bigint res=a*inv; res>>=(a.size());
        bigint mul=res*b; while(mul+b<=a){res+=bigint(1); mul+=b;}
        v=res.v; return *this;
    }
    bigint& operator%=(const bigint& x){
        bigint div=(*this)/x; (*this)-=div*x; return *this;
    }
    bigint square(){
        bigint res=*this; res.sign=0;
        auto v1=ntt1.conv<ll>(v,v,1);
        auto v2=ntt2.conv<ll>(v,v,1);
        res.v.assign(v1.size(),0);
        rep(i,0,v1.size()){
            ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;
            for(int j=i;val;j++){
                if(j==(int)res.v.size())res.v.push_back(0);
                res.v[j]+=val%B; val/=B;
            }
        } res.norm(); return res;
    }
    bigint mul(ll x){
        bigint res=*this; if(x<0)res.sign^=1,x*=-1;
        for(int i=res.v.size()-1;i>=0;i--)res.v[i]*=x;
        res.norm(); return res;
    }
    bigint div(ll x){
        bigint res=*this; if(x<0)res.sign^=1,x*=-1;
        for(int i=res.v.size()-1;i>=0;i--){
            if(res.v[i]%x!=0 and i!=0){res.v[i-1]+=B*(res.v[i]%x);} res.v[i]/=x;
        } res.norm(); return res;
    }
    bigint operator<<(const int& x)const{return bigint(*this)<<=x;}
    bigint operator>>(const int& x)const{return bigint(*this)>>=x;}
    bigint operator+(const bigint& x)const{return bigint(*this)+=x;}
    bigint operator-(const bigint& x)const{return bigint(*this)-=x;}
    bigint operator*(const bigint& x)const{return bigint(*this)*=x;}
    bigint operator/(const bigint& x)const{return bigint(*this)/=x;}
    bigint operator%(const bigint& x)const{return bigint(*this)%=x;}
    bool operator<(const bigint& x)const{
        if(sign!=x.sign)return sign>x.sign;
        if((int)v.size()!=(int)x.size()){
            if(sign)return (int)x.size()<(int)v.size();
            else return (int)v.size()<(int)x.size();
        }
        for(int i=v.size()-1;i>=0;i--)if(v[i]!=x.v[i]){
            if(sign)return x.v[i]<v[i];
            else return v[i]<x.v[i];
        }
        return false;
    }
    bool operator>(const bigint& x)const{return x<*this;}
    bool operator<=(const bigint& x)const{return !(*this>x);}
    bool operator>=(const bigint& x)const{return !(*this<x);}
    bool operator==(const bigint& x)const{return !(*this<x) and !(*this>x);}
    bool operator!=(const bigint& x)const{return !(*this==x);}
};
typedef bigint<5> Bigint;
 
struct Bigfloat{
    Bigint v; int p=0;
    Bigfloat(){}
    Bigfloat(const ll& _v){v=Bigint(_v);}
    Bigfloat(const Bigint& _v,int _p=0):v(_v),p(_p){}
    void set(int _p){if(p<_p){v>>=(_p-p);} else{v<<=(p-_p);} p=_p;}
    Bigint to_int()const{if(p<0)return v>>(-p); else return v<<p;}
    Bigfloat& operator+=(const Bigfloat& x){
        if(p>x.p)set(x.p),v+=x.v;
        else v+=x.v<<(x.p-p);
        return *this;
    }
    Bigfloat& operator-=(const Bigfloat& x){
        if(p>x.p)set(x.p),v-=x.v;
        else v-=x.v<<(x.p-p);
        return *this;
    }
    Bigfloat square(){Bigfloat res=*this; res.p*=2; res.v=res.v.square(); return res;}
    Bigfloat mul(ll x){Bigfloat res=*this; res.v=v.mul(x); return res;}
    Bigfloat div(ll x){Bigfloat res=*this; res.v=v.div(x); return res;}
    Bigfloat& operator*=(const Bigfloat& x){p+=x.p; v*=x.v; return *this;}
    Bigfloat& operator/=(const Bigfloat& x){p-=x.p; v/=x.v; return *this;}
    Bigfloat operator+(const Bigfloat& x)const{return Bigfloat(*this)+=x;}
    Bigfloat operator-(const Bigfloat& x)const{return Bigfloat(*this)-=x;}
    Bigfloat operator*(const Bigfloat& x)const{return Bigfloat(*this)*=x;}
    Bigfloat operator/(const Bigfloat& x)const{return Bigfloat(*this)/=x;}
    string to_str(){
        string res=v.abs().to_str(); int d=Bigint::get_D();
        if(p*d>0)res+=string(p*d,'0');
        else if(-p*d>=1 and -p*d<(int)res.size()){
            res=res.substr(0,(int)res.size()+p*d)+'.'+res.substr((int)res.size()+p*d);
        }
        else if(-p*d>=(int)res.size())res="0."+string(-p*d-(int)res.size(),'0')+res;
        if(v.sign){res.insert(res.begin(),'-');} return res;
    }
    friend ostream& operator<<(ostream& os,Bigfloat x){
        os<<x.to_str(); return os;
    }
};
 
Bigfloat sqrt(ll n,int d){
    Bigfloat res(Bigint((ll)sqrt(1LL*Bigint::get_B()*Bigint::get_B()/n)),-1),pre;
    int cur=1;
    while(pre.v!=res.v){
        cur=min(cur<<1,d);
        pre=res; Bigfloat add=Bigfloat(1)-res.square().mul(n);
        add.set(-cur*1.01); res+=(res*add).div(2); res.set(-cur);
    } return res.mul(n);
}