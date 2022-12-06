---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Geometry(integer Coordinates)
    links: []
  bundledCode: "#line 2 \"Geometry/intCoord.hpp\"\n \nstruct Point{\n    ll X,Y;\n\
    \    Point():X(0),Y(0){}\n    Point(ll _X,ll _Y):X(_X),Y(_Y){}\n    int pos()const{\n\
    \        if(Y<0)return -1;\n        if(Y==0 and X>=0)return 0;\n        return\
    \ 1;\n    }\n    Point& operator+=(const Point& p){\n        X+=p.X;\n       \
    \ Y+=p.Y;\n        return *this;\n    }\n    Point& operator-=(const Point& p){\n\
    \        X-=p.X;\n        Y-=p.Y;\n        return *this;\n    }\n    Point& operator*=(const\
    \ ll& t){\n        X*=t,Y*=t;\n        return *this;\n    }\n    Point& operator*=(const\
    \ Point& p){\n        ll NX=X*p.X-Y*p.Y,NY=X*p.Y+Y*p.X;\n        X=NX,Y=NY;\n\
    \        return *this;\n    }\n    Point operator+(const Point &p) const { return\
    \ Point(*this) += p; }\n    Point operator-(const Point &p) const { return Point(*this)\
    \ -= p; }\n    Point operator*(const ll &p) const { return Point(*this) *= p;\
    \ }\n    Point operator*(const Point &p) const { return Point(*this) *= p; }\n\
    \    Point operator-() const { return Point(-X, -Y); }\n    bool operator==(const\
    \ Point &p) const { return X == p.X && Y == p.Y; }\n    bool operator!=(const\
    \ Point &p) const { return X != p.X || Y != p.Y; }\n    bool operator<(const Point\
    \ &p) const { return X == p.X ? Y < p.Y : X < p.X; }\n};\nstruct Line{\n    Point\
    \ a,b;\n    Line(){}\n    Line(Point _a,Point _b):a(_a),b(_b){}\n};\nstruct Segment:Line{\n\
    \    Segment(){}\n    Segment(Point _a,Point _b):Line(_a,_b){}\n};\nusing Poly=vector<Point>;\n\
    \ \nll dot(const Point &a, const Point &b) { return a.X * b.X + a.Y * b.Y; }\n\
    ll cross(const Point &a, const Point &b) { return a.X * b.Y - a.Y * b.X; }\nll\
    \ norm(const Point& a){return a.X*a.X+a.Y*a.Y;}\nbool cmp(const Point& a,const\
    \ Point& b){\n    if(a.pos()!=b.pos())return a.pos()<b.pos();\n    return a.Y*b.X<a.X*b.Y;\n\
    }\n \nint ccw(const Point& a,Point b,Point c){\n    b-=a; c-=a;\n    ll C=cross(b,c);\n\
    \    if(C>0)return 1; //ccw\n    if(C<0)return -1; //cw\n    if(dot(b,c)<0)return\
    \ 2; //c,a,b\n    if(dot(b,b)<dot(c,c))return -2; //a,b,c\n    return 0; //a,c,b\n\
    }\n \n \nbool isOrthogonal(const Line& a,const Line& b){\n    return dot(a.b-a.a,b.b-b.a)==0;\n\
    }\nbool isParallel(const Line& a,const Line& b){\n    return cross(a.b-a.a,b.b-b.a)==0;\n\
    }\nbool isIntersect(const Segment& a,const Segment& b){\n    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0\
    \ and\n        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;\n}\n \nint isContained(const\
    \ Poly& a,const Point& b){\n    bool res=0;\n    int n=a.size();\n    rep(i,0,n){\n\
    \        Point p=a[i]-b,q=a[(i+1)%n]-b;\n        if(p.Y>q.Y)swap(p,q);\n     \
    \   if(p.Y<=0 and q.Y>0 and cross(p,q)>0)res^=1;\n        if(cross(p,q)==0 and\
    \ dot(p,q)<=0)return 1;\n    }\n    return (res?2:0);\n}\nPoly ConvexHull(Poly&\
    \ a){\n    int n=a.size(),k=0;\n    if(n<=2)return a;\n    sort(ALL(a),[](const\
    \ Point& p,const Point& q){\n        return (p.Y==q.Y?p.X<q.X:p.Y<q.Y);\n    });\n\
    \    Poly res(n*2);\n    for(int i=0;i<n;res[k++]=a[i++]){\n        while(k>=2\
    \ and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){\n\
    \        while(k>=t and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n\
    \    res.resize(k-1); return res;\n}\n \n/**\n * @brief Geometry(integer Coordinates)\n\
    \ */\n"
  code: "#pragma once\n \nstruct Point{\n    ll X,Y;\n    Point():X(0),Y(0){}\n  \
    \  Point(ll _X,ll _Y):X(_X),Y(_Y){}\n    int pos()const{\n        if(Y<0)return\
    \ -1;\n        if(Y==0 and X>=0)return 0;\n        return 1;\n    }\n    Point&\
    \ operator+=(const Point& p){\n        X+=p.X;\n        Y+=p.Y;\n        return\
    \ *this;\n    }\n    Point& operator-=(const Point& p){\n        X-=p.X;\n   \
    \     Y-=p.Y;\n        return *this;\n    }\n    Point& operator*=(const ll& t){\n\
    \        X*=t,Y*=t;\n        return *this;\n    }\n    Point& operator*=(const\
    \ Point& p){\n        ll NX=X*p.X-Y*p.Y,NY=X*p.Y+Y*p.X;\n        X=NX,Y=NY;\n\
    \        return *this;\n    }\n    Point operator+(const Point &p) const { return\
    \ Point(*this) += p; }\n    Point operator-(const Point &p) const { return Point(*this)\
    \ -= p; }\n    Point operator*(const ll &p) const { return Point(*this) *= p;\
    \ }\n    Point operator*(const Point &p) const { return Point(*this) *= p; }\n\
    \    Point operator-() const { return Point(-X, -Y); }\n    bool operator==(const\
    \ Point &p) const { return X == p.X && Y == p.Y; }\n    bool operator!=(const\
    \ Point &p) const { return X != p.X || Y != p.Y; }\n    bool operator<(const Point\
    \ &p) const { return X == p.X ? Y < p.Y : X < p.X; }\n};\nstruct Line{\n    Point\
    \ a,b;\n    Line(){}\n    Line(Point _a,Point _b):a(_a),b(_b){}\n};\nstruct Segment:Line{\n\
    \    Segment(){}\n    Segment(Point _a,Point _b):Line(_a,_b){}\n};\nusing Poly=vector<Point>;\n\
    \ \nll dot(const Point &a, const Point &b) { return a.X * b.X + a.Y * b.Y; }\n\
    ll cross(const Point &a, const Point &b) { return a.X * b.Y - a.Y * b.X; }\nll\
    \ norm(const Point& a){return a.X*a.X+a.Y*a.Y;}\nbool cmp(const Point& a,const\
    \ Point& b){\n    if(a.pos()!=b.pos())return a.pos()<b.pos();\n    return a.Y*b.X<a.X*b.Y;\n\
    }\n \nint ccw(const Point& a,Point b,Point c){\n    b-=a; c-=a;\n    ll C=cross(b,c);\n\
    \    if(C>0)return 1; //ccw\n    if(C<0)return -1; //cw\n    if(dot(b,c)<0)return\
    \ 2; //c,a,b\n    if(dot(b,b)<dot(c,c))return -2; //a,b,c\n    return 0; //a,c,b\n\
    }\n \n \nbool isOrthogonal(const Line& a,const Line& b){\n    return dot(a.b-a.a,b.b-b.a)==0;\n\
    }\nbool isParallel(const Line& a,const Line& b){\n    return cross(a.b-a.a,b.b-b.a)==0;\n\
    }\nbool isIntersect(const Segment& a,const Segment& b){\n    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0\
    \ and\n        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;\n}\n \nint isContained(const\
    \ Poly& a,const Point& b){\n    bool res=0;\n    int n=a.size();\n    rep(i,0,n){\n\
    \        Point p=a[i]-b,q=a[(i+1)%n]-b;\n        if(p.Y>q.Y)swap(p,q);\n     \
    \   if(p.Y<=0 and q.Y>0 and cross(p,q)>0)res^=1;\n        if(cross(p,q)==0 and\
    \ dot(p,q)<=0)return 1;\n    }\n    return (res?2:0);\n}\nPoly ConvexHull(Poly&\
    \ a){\n    int n=a.size(),k=0;\n    if(n<=2)return a;\n    sort(ALL(a),[](const\
    \ Point& p,const Point& q){\n        return (p.Y==q.Y?p.X<q.X:p.Y<q.Y);\n    });\n\
    \    Poly res(n*2);\n    for(int i=0;i<n;res[k++]=a[i++]){\n        while(k>=2\
    \ and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){\n\
    \        while(k>=t and cross(res[k-1]-res[k-2],a[i]-res[k-1])<0)k--;\n    }\n\
    \    res.resize(k-1); return res;\n}\n \n/**\n * @brief Geometry(integer Coordinates)\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/intCoord.hpp
  requiredBy: []
  timestamp: '2022-12-07 05:58:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/intCoord.hpp
layout: document
redirect_from:
- /library/Geometry/intCoord.hpp
- /library/Geometry/intCoord.hpp.html
title: Geometry(integer Coordinates)
---
