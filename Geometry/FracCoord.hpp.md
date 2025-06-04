---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/fraction.hpp
    title: Fraction
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Geometry(Fraction Coordinates)
    links: []
  bundledCode: "#line 2 \"Math/fraction.hpp\"\n\r\ntemplate <typename T> struct Frac\
    \ {\r\n    T a, b;\r\n    Frac(T _a = 0) {\r\n        init(_a, 1);\r\n    }\r\n\
    \    Frac(T _a, T _b) {\r\n        init(_a, _b);\r\n    }\r\n    template <typename\
    \ V> V get() const {\r\n        return V(a) / b;\r\n    }\r\n    Frac &init(T\
    \ _a, T _b) {\r\n        T g = gcd(_a, _b);\r\n        a = _a / g, b = _b / g;\r\
    \n        if (b < 0)\r\n            a = -a, b = -b;\r\n        return *this;\r\
    \n    }\r\n    Frac inv() const {\r\n        return Frac(b, a);\r\n    }\r\n \
    \   Frac operator-() const {\r\n        return Frac(-a, b);\r\n    }\r\n    Frac\
    \ &operator+=(const Frac &x) {\r\n        return init(a * x.b + x.a * b, b * x.b);\r\
    \n    }\r\n    Frac &operator-=(const Frac &x) {\r\n        return init(a * x.b\
    \ - x.a * b, b * x.b);\r\n    }\r\n    Frac &operator*=(const Frac &x) {\r\n \
    \       return init(a * x.a, b * x.b);\r\n    }\r\n    Frac &operator/=(const\
    \ Frac &x) {\r\n        return init(a * x.b, b * x.a);\r\n    }\r\n    Frac operator+(const\
    \ Frac &x) const {\r\n        return Frac(*this) += x;\r\n    }\r\n    Frac operator-(const\
    \ Frac &x) const {\r\n        return Frac(*this) -= x;\r\n    }\r\n    Frac operator*(const\
    \ Frac &x) const {\r\n        return Frac(*this) *= x;\r\n    }\r\n    Frac operator/(const\
    \ Frac &x) const {\r\n        return Frac(*this) /= x;\r\n    }\r\n    bool operator<(const\
    \ Frac &x) const {\r\n        return a * x.b < b * x.a;\r\n    }\r\n    bool operator>(const\
    \ Frac &x) const {\r\n        return x < *this;\r\n    }\r\n    bool operator<=(const\
    \ Frac &x) const {\r\n        return !(x < *this);\r\n    }\r\n    bool operator>=(const\
    \ Frac &x) const {\r\n        return !(*this < x);\r\n    }\r\n    bool operator==(const\
    \ Frac &x) const {\r\n        return (*this <= x and x <= *this);\r\n    }\r\n\
    \    bool operator!=(const Frac &x) const {\r\n        return !(*this == x);\r\
    \n    }\r\n\r\n    friend istream &operator>>(istream &is, Frac &x) {\r\n    \
    \    return is >> x.a >> x.b;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Frac &x) {\r\n        return os << x.a << '/' << x.b;\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Fraction\r\n * @docs docs/fraction.md\r\n */\n#line\
    \ 3 \"Geometry/FracCoord.hpp\"\n \nstruct Point{\n    Frac X,Y;\n    Point():X(0),Y(0){}\n\
    \    Point(Frac _X,Frac _Y):X(_X),Y(_Y){}\n    int pos()const{\n        if(Y<0)return\
    \ -1;\n        if(Y==0 and X>=0)return 0;\n        return 1;\n    }\n    Point&\
    \ operator+=(const Point& p){\n        X+=p.X;\n        Y+=p.Y;\n        return\
    \ *this;\n    }\n    Point& operator-=(const Point& p){\n        X-=p.X;\n   \
    \     Y-=p.Y;\n        return *this;\n    }\n    Point& operator*=(const Frac&\
    \ t){\n        X*=t,Y*=t;\n        return *this;\n    }\n    Point& operator*=(const\
    \ Point& p){\n        Frac NX=X*p.X-Y*p.Y,NY=X*p.Y+Y*p.X;\n        X=NX,Y=NY;\n\
    \        return *this;\n    }\n    Point operator+(const Point &p) const { return\
    \ Point(*this) += p; }\n    Point operator-(const Point &p) const { return Point(*this)\
    \ -= p; }\n    Point operator*(const Frac &p) const { return Point(*this) *= p;\
    \ }\n    Point operator*(const Point &p) const { return Point(*this) *= p; }\n\
    \    Point operator-() const { return Point(-X, -Y); }\n    bool operator==(const\
    \ Point &p) const { return X == p.X && Y == p.Y; }\n    bool operator!=(const\
    \ Point &p) const { return X != p.X || Y != p.Y; }\n    bool operator<(const Point\
    \ &p) const { return X == p.X ? Y < p.Y : X < p.X; }\n};\nstruct Line{\n    Point\
    \ a,b;\n    Line(){}\n    Line(Point _a,Point _b):a(_a),b(_b){}\n};\nstruct Segment:Line{\n\
    \    Segment(){}\n    Segment(Point _a,Point _b):Line(_a,_b){}\n};\nusing Poly=vector<Point>;\n\
    \ \nFrac dot(const Point &a, const Point &b) { return a.X * b.X + a.Y * b.Y; }\n\
    Frac cross(const Point &a, const Point &b) { return a.X * b.Y - a.Y * b.X; }\n\
    Frac norm(const Point& a){return a.X*a.X+a.Y*a.Y;}\nbool cmp(const Point& a,const\
    \ Point& b){\n    if(a.pos()!=b.pos())return a.pos()<b.pos();\n    return a.Y*b.X<a.X*b.Y;\n\
    }\n \nPoint Projection(const Line&l,const Point& p){\n    Frac t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\n\
    \    return l.a+(l.a-l.b)*t;\n}\nPoint Projection(const Segment&l,const Point&\
    \ p){\n    Frac t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\n    return l.a+(l.a-l.b)*t;\n\
    }\nPoint Reflection(const Line& l,const Point& p){\n    return p+(Projection(l,p)-p)*2.;\n\
    }\nint ccw(const Point& a,Point b,Point c){\n    b-=a; c-=a;\n    Frac C=cross(b,c);\n\
    \    if(C>0)return 1; //ccw\n    if(C<0)return -1; //cw\n    if(dot(b,c)<0)return\
    \ 2; //c,a,b\n    if(dot(b,b)<dot(c,c))return -2; //a,b,c\n    return 0; //a,c,b\n\
    }\n \n \nbool isOrthogonal(const Line& a,const Line& b){\n    return dot(a.b-a.a,b.b-b.a)==0;\n\
    }\nbool isParallel(const Line& a,const Line& b){\n    return cross(a.b-a.a,b.b-b.a)==0;\n\
    }\nbool isIntersect(const Segment& a,const Segment& b){\n    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0\
    \ and\n        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;\n}\nPoint Intersection(const\
    \ Line& a,const Line& b){\n    Frac d1=cross(a.b-a.a,b.b-b.a);\n    Frac d2=cross(a.b-a.a,a.b-b.a);\n\
    \    if(d1==0 and d2==0)return b.a;\n    return b.a+(b.b-b.a)*(d2/d1);\n}\n \n\
    Frac Area(const Poly& a){\n    Frac res=0;\n    int n=a.size();\n    rep(i,0,n)res+=cross(a[i],a[(i+1)%n]);\n\
    \    return res/2;\n}\nint isContained(const Poly& a,const Point& b){ // 0:not\
    \ contain,1:on edge,2:contain\n    bool res=0;\n    int n=a.size();\n    rep(i,0,n){\n\
    \        Point p=a[i]-b,q=a[(i+1)%n]-b;\n        if(p.Y>q.Y)swap(p,q);\n     \
    \   if(p.Y<=0 and q.Y>0 and cross(p,q)>0)res^=1;\n        if(cross(p,q)==0 and\
    \ dot(p,q)<=0)return 1;\n    }\n    return (res?2:0);\n}\nPoly ConvexHull(Poly&\
    \ a){\n    int n=a.size(),k=0;\n    if(n<=2)return a;\n    sort(ALL(a),[](const\
    \ Point& p,const Point& q){\n        return (p.Y==q.Y?p.X<q.X:p.Y<q.Y);\n    });\n\
    \    Poly res(n*2);\n    for(int i=0;i<n;res[k++]=a[i++]){\n        while(k>=2\
    \ and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){\n\
    \        while(k>=t and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n\
    \    res.resize(k-1); return res;\n}\nPoly Cut(const Poly& a,const Line& l){\n\
    \    int n=a.size(); Poly res;\n    rep(i,0,n){\n        Point p=a[i],q=a[(i+1)%n];\n\
    \        if(ccw(l.a,l.b,p)!=-1)res.push_back(p);\n        if(ccw(l.a,l.b,p)*ccw(l.a,l.b,q)<0)res.push_back(Intersection(Line(p,q),l));\n\
    \    }\n    return res;\n}\n \n/**\n * @brief Geometry(Fraction Coordinates)\n\
    \ */\n"
  code: "#pragma once\n#include \"Math/fraction.hpp\"\n \nstruct Point{\n    Frac\
    \ X,Y;\n    Point():X(0),Y(0){}\n    Point(Frac _X,Frac _Y):X(_X),Y(_Y){}\n  \
    \  int pos()const{\n        if(Y<0)return -1;\n        if(Y==0 and X>=0)return\
    \ 0;\n        return 1;\n    }\n    Point& operator+=(const Point& p){\n     \
    \   X+=p.X;\n        Y+=p.Y;\n        return *this;\n    }\n    Point& operator-=(const\
    \ Point& p){\n        X-=p.X;\n        Y-=p.Y;\n        return *this;\n    }\n\
    \    Point& operator*=(const Frac& t){\n        X*=t,Y*=t;\n        return *this;\n\
    \    }\n    Point& operator*=(const Point& p){\n        Frac NX=X*p.X-Y*p.Y,NY=X*p.Y+Y*p.X;\n\
    \        X=NX,Y=NY;\n        return *this;\n    }\n    Point operator+(const Point\
    \ &p) const { return Point(*this) += p; }\n    Point operator-(const Point &p)\
    \ const { return Point(*this) -= p; }\n    Point operator*(const Frac &p) const\
    \ { return Point(*this) *= p; }\n    Point operator*(const Point &p) const { return\
    \ Point(*this) *= p; }\n    Point operator-() const { return Point(-X, -Y); }\n\
    \    bool operator==(const Point &p) const { return X == p.X && Y == p.Y; }\n\
    \    bool operator!=(const Point &p) const { return X != p.X || Y != p.Y; }\n\
    \    bool operator<(const Point &p) const { return X == p.X ? Y < p.Y : X < p.X;\
    \ }\n};\nstruct Line{\n    Point a,b;\n    Line(){}\n    Line(Point _a,Point _b):a(_a),b(_b){}\n\
    };\nstruct Segment:Line{\n    Segment(){}\n    Segment(Point _a,Point _b):Line(_a,_b){}\n\
    };\nusing Poly=vector<Point>;\n \nFrac dot(const Point &a, const Point &b) { return\
    \ a.X * b.X + a.Y * b.Y; }\nFrac cross(const Point &a, const Point &b) { return\
    \ a.X * b.Y - a.Y * b.X; }\nFrac norm(const Point& a){return a.X*a.X+a.Y*a.Y;}\n\
    bool cmp(const Point& a,const Point& b){\n    if(a.pos()!=b.pos())return a.pos()<b.pos();\n\
    \    return a.Y*b.X<a.X*b.Y;\n}\n \nPoint Projection(const Line&l,const Point&\
    \ p){\n    Frac t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\n    return l.a+(l.a-l.b)*t;\n\
    }\nPoint Projection(const Segment&l,const Point& p){\n    Frac t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\n\
    \    return l.a+(l.a-l.b)*t;\n}\nPoint Reflection(const Line& l,const Point& p){\n\
    \    return p+(Projection(l,p)-p)*2.;\n}\nint ccw(const Point& a,Point b,Point\
    \ c){\n    b-=a; c-=a;\n    Frac C=cross(b,c);\n    if(C>0)return 1; //ccw\n \
    \   if(C<0)return -1; //cw\n    if(dot(b,c)<0)return 2; //c,a,b\n    if(dot(b,b)<dot(c,c))return\
    \ -2; //a,b,c\n    return 0; //a,c,b\n}\n \n \nbool isOrthogonal(const Line& a,const\
    \ Line& b){\n    return dot(a.b-a.a,b.b-b.a)==0;\n}\nbool isParallel(const Line&\
    \ a,const Line& b){\n    return cross(a.b-a.a,b.b-b.a)==0;\n}\nbool isIntersect(const\
    \ Segment& a,const Segment& b){\n    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0\
    \ and\n        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;\n}\nPoint Intersection(const\
    \ Line& a,const Line& b){\n    Frac d1=cross(a.b-a.a,b.b-b.a);\n    Frac d2=cross(a.b-a.a,a.b-b.a);\n\
    \    if(d1==0 and d2==0)return b.a;\n    return b.a+(b.b-b.a)*(d2/d1);\n}\n \n\
    Frac Area(const Poly& a){\n    Frac res=0;\n    int n=a.size();\n    rep(i,0,n)res+=cross(a[i],a[(i+1)%n]);\n\
    \    return res/2;\n}\nint isContained(const Poly& a,const Point& b){ // 0:not\
    \ contain,1:on edge,2:contain\n    bool res=0;\n    int n=a.size();\n    rep(i,0,n){\n\
    \        Point p=a[i]-b,q=a[(i+1)%n]-b;\n        if(p.Y>q.Y)swap(p,q);\n     \
    \   if(p.Y<=0 and q.Y>0 and cross(p,q)>0)res^=1;\n        if(cross(p,q)==0 and\
    \ dot(p,q)<=0)return 1;\n    }\n    return (res?2:0);\n}\nPoly ConvexHull(Poly&\
    \ a){\n    int n=a.size(),k=0;\n    if(n<=2)return a;\n    sort(ALL(a),[](const\
    \ Point& p,const Point& q){\n        return (p.Y==q.Y?p.X<q.X:p.Y<q.Y);\n    });\n\
    \    Poly res(n*2);\n    for(int i=0;i<n;res[k++]=a[i++]){\n        while(k>=2\
    \ and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){\n\
    \        while(k>=t and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n\
    \    res.resize(k-1); return res;\n}\nPoly Cut(const Poly& a,const Line& l){\n\
    \    int n=a.size(); Poly res;\n    rep(i,0,n){\n        Point p=a[i],q=a[(i+1)%n];\n\
    \        if(ccw(l.a,l.b,p)!=-1)res.push_back(p);\n        if(ccw(l.a,l.b,p)*ccw(l.a,l.b,q)<0)res.push_back(Intersection(Line(p,q),l));\n\
    \    }\n    return res;\n}\n \n/**\n * @brief Geometry(Fraction Coordinates)\n\
    \ */\n"
  dependsOn:
  - Math/fraction.hpp
  isVerificationFile: false
  path: Geometry/FracCoord.hpp
  requiredBy: []
  timestamp: '2025-06-05 05:40:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/FracCoord.hpp
layout: document
redirect_from:
- /library/Geometry/FracCoord.hpp
- /library/Geometry/FracCoord.hpp.html
title: Geometry(Fraction Coordinates)
---
