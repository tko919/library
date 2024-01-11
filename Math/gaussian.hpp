#pragma once

struct G{
    ll x,y;
    G(){}
    G(ll _x,ll _y):x(_x),y(_y){}
    ll norm()const{return x*x+y*y;}
    G conj()const{return G(x,-y);}
    G operator-()const{return G(-x,-y);}
    G& operator+=(const G& a){x+=a.x,y+=a.y; return *this;}
    G& operator-=(const G& a){x-=a.x,y-=a.y; return *this;}
    G& operator*=(const G& a){
        ll nx=x*a.x-y*a.y,ny=x*a.y+y*a.x;
        x=nx,y=ny;
        return *this;
    }
    G& operator/=(const G& a){
        (*this)*=a.conj();
        ll n=a.norm();
        x=floor(x+n/2,n),y=floor(y+n/2,n);
        return *this;
    }
    G& operator%=(const G& a){
        (*this)-=(G(*this)/a)*a;
        return *this;
    }
    G operator+(const G& a)const{return G(*this)+=a;}
    G operator-(const G& a)const{return G(*this)-=a;}
    G operator*(const G& a)const{return G(*this)*=a;}
    G operator/(const G& a)const{return G(*this)/=a;}
    G operator%(const G& a)const{return G(*this)%=a;}
    bool operator==(const G &a){return (x==a.x and y==a.y);}
    bool operator!=(const G &a){return (x!=a.x or y!=a.y);}
};

G gcd(G a,G b){
    while(b!=G(0,0)){
        a%=b;
        swap(a,b);
    }
    return a;
}

/**
 * @brief Gaussian Integer
*/