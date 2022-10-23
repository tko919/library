#pragma once

struct Frac{
    ll a,b;
    Frac(ll _a=0){init(_a,1);}
    Frac(ll _a,ll _b){init(_a,_b);}
    Frac& init(ll _a,ll _b){
        ll g=gcd(_a,_b);
        a=_a/g,b=_b/g;
        if(b<0)a=-a,b=-b;
        return *this;
    }
    Frac inv()const{return Frac(b,a);}
    Frac operator-()const{return Frac(-a,b);}
    Frac& operator+=(const Frac& x){return init(a*x.b+x.a*b,b*x.b);}
    Frac& operator-=(const Frac& x){return init(a*x.b-x.a*b,b*x.b);}
    Frac& operator*=(const Frac& x){return init(a*x.a,b*x.b);}
    Frac& operator/=(const Frac& x){return init(a*x.b,b*x.a);}
    Frac operator+(const Frac& x)const{return Frac(*this)+=x;}
    Frac operator-(const Frac& x)const{return Frac(*this)-=x;}
    Frac operator*(const Frac& x)const{return Frac(*this)*=x;}
    Frac operator/(const Frac& x)const{return Frac(*this)/=x;}
    bool operator<(const Frac& x)const{return a*x.b<b*x.a;}
    bool operator>(const Frac& x)const{return x<*this;}
    bool operator<=(const Frac& x)const{return !(x<*this);}
    bool operator>=(const Frac& x)const{return !(*this<x);}
    bool operator==(const Frac& x)const{return (*this<=x and x<=*this);}
    bool operator!=(const Frac& x)const{return !(*this==x);}
};
Frac between(const Frac& x,const Frac& y){
    if(x.a<x.b and y.b<y.a)return Frac(1);
    else if(x.b<=x.a){
        ll add=floor(x.a/x.b);
        return between(x-add,y-add)+add;
    }
    else return between(y.inv(),x.inv()).inv();
}

/**
 * @brief Fraction
 * @docs docs/fraction.md
 */