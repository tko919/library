#pragma once

template<int mod=1000000007>struct fp {
    int v;
    static constexpr int get_mod(){return mod;}
    int inv() const{
        int tmp,a=v,b=mod,x=1,y=0;
        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
        if(x<0){x+=mod;} return x;
    }
    fp(ll x=0){init(x%mod+mod);}
    fp& init(ll x){v=(x<mod?x:x-mod); return *this;}
    fp operator-()const{return fp()-*this;}
    fp pow(ll t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return res;}
    fp& operator+=(const fp& x){return init(v+x.v);}
    fp& operator-=(const fp& x){return init(v+mod-x.v);}
    fp& operator*=(const fp& x){v=ll(v)*x.v%mod; return *this;}
    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return *this;}
    fp operator+(const fp& x)const{return fp(*this)+=x;}
    fp operator-(const fp& x)const{return fp(*this)-=x;}
    fp operator*(const fp& x)const{return fp(*this)*=x;}
    fp operator/(const fp& x)const{return fp(*this)/=x;}
    bool operator==(const fp& x)const{return v==x.v;}
    bool operator!=(const fp& x)const{return v!=x.v;}
    friend istream& operator>>(istream& is,fp& x){return is>>x.v;}
    friend ostream& operator<<(ostream& os,const fp& x){return os<<x.v;}
};

/**
 * @brief Modint
 */