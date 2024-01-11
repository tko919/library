#pragma once
#include "Math/fraction.hpp"
 
struct Point{
    Frac X,Y;
    Point():X(0),Y(0){}
    Point(Frac _X,Frac _Y):X(_X),Y(_Y){}
    int pos()const{
        if(Y<0)return -1;
        if(Y==0 and X>=0)return 0;
        return 1;
    }
    Point& operator+=(const Point& p){
        X+=p.X;
        Y+=p.Y;
        return *this;
    }
    Point& operator-=(const Point& p){
        X-=p.X;
        Y-=p.Y;
        return *this;
    }
    Point& operator*=(const Frac& t){
        X*=t,Y*=t;
        return *this;
    }
    Point& operator*=(const Point& p){
        Frac NX=X*p.X-Y*p.Y,NY=X*p.Y+Y*p.X;
        X=NX,Y=NY;
        return *this;
    }
    Point operator+(const Point &p) const { return Point(*this) += p; }
    Point operator-(const Point &p) const { return Point(*this) -= p; }
    Point operator*(const Frac &p) const { return Point(*this) *= p; }
    Point operator*(const Point &p) const { return Point(*this) *= p; }
    Point operator-() const { return Point(-X, -Y); }
    bool operator==(const Point &p) const { return X == p.X && Y == p.Y; }
    bool operator!=(const Point &p) const { return X != p.X || Y != p.Y; }
    bool operator<(const Point &p) const { return X == p.X ? Y < p.Y : X < p.X; }
};
struct Line{
    Point a,b;
    Line(){}
    Line(Point _a,Point _b):a(_a),b(_b){}
};
struct Segment:Line{
    Segment(){}
    Segment(Point _a,Point _b):Line(_a,_b){}
};
using Poly=vector<Point>;
 
Frac dot(const Point &a, const Point &b) { return a.X * b.X + a.Y * b.Y; }
Frac cross(const Point &a, const Point &b) { return a.X * b.Y - a.Y * b.X; }
Frac norm(const Point& a){return a.X*a.X+a.Y*a.Y;}
bool cmp(const Point& a,const Point& b){
    if(a.pos()!=b.pos())return a.pos()<b.pos();
    return a.Y*b.X<a.X*b.Y;
}
 
Point Projection(const Line&l,const Point& p){
    Frac t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);
    return l.a+(l.a-l.b)*t;
}
Point Projection(const Segment&l,const Point& p){
    Frac t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);
    return l.a+(l.a-l.b)*t;
}
Point Reflection(const Line& l,const Point& p){
    return p+(Projection(l,p)-p)*2.;
}
int ccw(const Point& a,Point b,Point c){
    b-=a; c-=a;
    Frac C=cross(b,c);
    if(C>0)return 1; //ccw
    if(C<0)return -1; //cw
    if(dot(b,c)<0)return 2; //c,a,b
    if(dot(b,b)<dot(c,c))return -2; //a,b,c
    return 0; //a,c,b
}
 
 
bool isOrthogonal(const Line& a,const Line& b){
    return dot(a.b-a.a,b.b-b.a)==0;
}
bool isParallel(const Line& a,const Line& b){
    return cross(a.b-a.a,b.b-b.a)==0;
}
bool isIntersect(const Segment& a,const Segment& b){
    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0 and
        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;
}
Point Intersection(const Line& a,const Line& b){
    Frac d1=cross(a.b-a.a,b.b-b.a);
    Frac d2=cross(a.b-a.a,a.b-b.a);
    if(d1==0 and d2==0)return b.a;
    return b.a+(b.b-b.a)*(d2/d1);
}
 
Frac Area(const Poly& a){
    Frac res=0;
    int n=a.size();
    rep(i,0,n)res+=cross(a[i],a[(i+1)%n]);
    return res/2;
}
int isContained(const Poly& a,const Point& b){ // 0:not contain,1:on edge,2:contain
    bool res=0;
    int n=a.size();
    rep(i,0,n){
        Point p=a[i]-b,q=a[(i+1)%n]-b;
        if(p.Y>q.Y)swap(p,q);
        if(p.Y<=0 and q.Y>0 and cross(p,q)>0)res^=1;
        if(cross(p,q)==0 and dot(p,q)<=0)return 1;
    }
    return (res?2:0);
}
Poly ConvexHull(Poly& a){
    int n=a.size(),k=0;
    if(n<=2)return a;
    sort(ALL(a),[](const Point& p,const Point& q){
        return (p.Y==q.Y?p.X<q.X:p.Y<q.Y);
    });
    Poly res(n*2);
    for(int i=0;i<n;res[k++]=a[i++]){
        while(k>=2 and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;
    }
    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){
        while(k>=t and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;
    }
    res.resize(k-1); return res;
}
Poly Cut(const Poly& a,const Line& l){
    int n=a.size(); Poly res;
    rep(i,0,n){
        Point p=a[i],q=a[(i+1)%n];
        if(ccw(l.a,l.b,p)!=-1)res.push_back(p);
        if(ccw(l.a,l.b,p)*ccw(l.a,l.b,q)<0)res.push_back(Intersection(Line(p,q),l));
    }
    return res;
}
 
/**
 * @brief Geometry(Fraction Coordinates)
 */
