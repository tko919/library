---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Geometry
    links: []
  bundledCode: "#line 2 \"Geometry/geometry.hpp\"\n\r\nusing T=double;\r\nconst T\
    \ eps=1e-12;\r\nusing Point=complex<T>;\r\nusing Poly=vector<Point>;\r\n#define\
    \ X real()\r\n#define Y imag()\r\ninline bool eq(const T& a,const T& b){\r\n \
    \   return fabs(a-b)<eps;\r\n}\r\nbool cmp(const Point& a,const Point& b){\r\n\
    \    auto sub=[&](Point a){return (a.Y<0?-1:(a.Y==0&&a.X>=0?0:1));};\r\n    if(sub(a)!=sub(b))return\
    \ sub(a)<sub(b);\r\n    return a.Y*b.X<a.X*b.Y;\r\n}\r\nstruct Line{\r\n    Point\
    \ a,b;\r\n    Line(){}\r\n    Line(Point _a,Point _b):a(_a),b(_b){}\r\n    Line(T\
    \ A,T B,T C){\r\n        if(eq(A,.0)){\r\n            a=Point(0,C/B),b=Point(1/C/B);\r\
    \n        }\r\n        else if(eq(B,.0)){\r\n            a=Point(C/A,0),b=Point(C/A,1);\r\
    \n        }\r\n        else{\r\n            a=Point(0,C/B),b=Point(C/A,0);\r\n\
    \        }\r\n    }\r\n};\r\nstruct Segment:Line{\r\n    Segment(){}\r\n    Segment(Point\
    \ _a,Point _b):Line(_a,_b){}\r\n};\r\nstruct Circle{\r\n    Point p; T r;\r\n\
    \    Circle(){}\r\n    Circle(Point _p,T _r):p(_p),r(_r){}\r\n};\r\n\r\nistream&\
    \ operator>>(istream& is,Point& p){\r\n    T x,y; is>>x>>y; p=Point(x,y);\r\n\
    \    return is;\r\n}\r\nostream& operator<<(ostream& os,Point& p){\r\n    os<<fixed<<setprecision(12)<<p.X<<'\
    \ '<<p.Y;\r\n    return os;\r\n}\r\nPoint unit(const Point& a){return a/abs(a);}\r\
    \nT dot(const Point& a,const Point& b){\r\n    return a.X*b.X+a.Y*b.Y;\r\n}\r\n\
    T cross(const Point& a,const Point& b){\r\n    return a.X*b.Y-a.Y*b.X;\r\n}\r\n\
    Point rot(const Point& a,const T& theta){\r\n    return Point(cos(theta)*a.X-sin(theta)*a.Y,\r\
    \n        sin(theta)*a.X+cos(theta)*a.Y);\r\n}\r\nT arg(const Point& a,const Point&\
    \ b,const Point& c){\r\n    return acos(dot(a-b,c-b)/abs(a-b)/abs(c-b));\r\n}\r\
    \n\r\nPoint Projection(const Line&l,const Point& p){\r\n    T t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\r\
    \n    return l.a+(l.a-l.b)*t;\r\n}\r\nPoint Projection(const Segment&l,const Point&\
    \ p){\r\n    T t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\r\n    return l.a+(l.a-l.b)*t;\r\
    \n}\r\nPoint Reflection(const Line& l,const Point& p){\r\n    return p+(Projection(l,p)-p)*2.;\r\
    \n}\r\nint ccw(const Point& a,Point b,Point c){\r\n    b-=a; c-=a;\r\n    if(cross(b,c)>eps)return\
    \ 1; //ccw\r\n    if(cross(b,c)<-eps)return -1; //cw\r\n    if(dot(b,c)<0)return\
    \ 2; //c,a,b\r\n    if(norm(b)<norm(c))return -2; //a,b,c\r\n    return 0; //a,c,b\r\
    \n}\r\nbool isOrthogonal(const Line& a,const Line& b){\r\n    return eq(dot(a.b-a.a,b.b-b.a),.0);\r\
    \n}\r\nbool isParallel(const Line& a,const Line& b){\r\n    return eq(cross(a.b-a.a,b.b-b.a),.0);\r\
    \n}\r\nbool isIntersect(const Segment& a,const Segment& b){\r\n    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0\
    \ and\r\n        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;\r\n}\r\nint isIntersect(const\
    \ Circle& a,const Circle& b){\r\n    T d=abs(a.p-b.p);\r\n    if(d>a.r+b.r+eps)return\
    \ 4;\r\n    if(eq(d,a.r+b.r))return 3;\r\n    if(eq(d,abs(a.r-b.r)))return 1;\r\
    \n    if(d<abs(a.r-b.r)-eps)return 0;\r\n    return 2;\r\n}\r\nT Dist(const Line&\
    \ a,const Point& b){\r\n    Point c=Projection(a,b);\r\n    return abs(c-b);\r\
    \n}\r\nT Dist(const Segment& a,const Point& b){\r\n    if(dot(a.b-a.a,b-a.a)<eps)return\
    \ abs(b-a.a);\r\n    if(dot(a.a-a.b,b-a.b)<eps)return abs(b-a.b);\r\n    return\
    \ abs(cross(a.b-a.a,b-a.a))/abs(a.b-a.a);\r\n}\r\nT Dist(const Segment& a,const\
    \ Segment& b){\r\n    if(isIntersect(a,b))return .0;\r\n    T res=min({Dist(a,b.a),Dist(a,b.b),Dist(b,a.a),Dist(b,a.b)});\r\
    \n    return res;\r\n}\r\nPoint Intersection(const Line& a,const Line& b){\r\n\
    \    T d1=cross(a.b-a.a,b.b-b.a);\r\n    T d2=cross(a.b-a.a,a.b-b.a);\r\n    if(eq(d1,0)\
    \ and eq(d2,0))return b.a;\r\n    return b.a+(b.b-b.a)*(d2/d1);\r\n}\r\nPoly Intersection(const\
    \ Circle& a,const Line& b){\r\n    Poly res;\r\n    T d=Dist(b,a.p);\r\n    if(d>a.r+eps)return\
    \ res;\r\n    Point h=Projection(b,a.p);\r\n    if(eq(d,a.r)){\r\n        res.push_back(h);\r\
    \n        return res;\r\n    }\r\n    Point e=unit(b.b-b.a);\r\n    T ph=sqrt(a.r*a.r-d*d);\r\
    \n    res.push_back(h-e*ph);\r\n    res.push_back(h+e*ph);\r\n    return res;\r\
    \n}\r\nPoly Intersection(const Circle& a,const Segment& b){\r\n    Line c(b.a,b.b);\r\
    \n    Poly sub=Intersection(a,c);\r\n    double xmi=min(b.a.X,b.b.X),xma=max(b.a.X,b.b.X);\r\
    \n    double ymi=min(b.a.Y,b.b.Y),yma=max(b.a.Y,b.b.Y);\r\n    Poly res;\r\n \
    \   rep(i,0,sub.size()){\r\n        if(xmi<=sub[i].X+eps and sub[i].X-eps<=xma\
    \ and\r\n            ymi<=sub[i].Y+eps and sub[i].Y-eps<=yma){\r\n           \
    \ res.push_back(sub[i]);\r\n        }\r\n    }\r\n    return res;\r\n}\r\nPoly\
    \ Intersection(const Circle& a,const Circle& b){\r\n    Poly res;\r\n    int mode=isIntersect(a,b);\r\
    \n    T d=abs(a.p-b.p);\r\n    if(mode==4 or mode==0)return res;\r\n    if(mode==3){\r\
    \n        T t=a.r/(a.r+b.r);\r\n        res.push_back(a.p+(b.p-a.p)*t);\r\n  \
    \      return res;\r\n    }\r\n    if(mode==1){\r\n        if(b.r<a.r-eps){\r\n\
    \            res.push_back(a.p+(b.p-a.p)*(a.r/d));\r\n        }\r\n        else{\r\
    \n            res.push_back(b.p+(a.p-b.p)*(b.r/d));\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    T rc=(a.r*a.r+d*d-b.r*b.r)/d/2.;\r\n    T rs=sqrt(a.r*a.r-rc*rc);\r\
    \n    if(a.r-abs(rc)<eps)rs=0;\r\n    Point e=unit(b.p-a.p);\r\n    res.push_back(a.p+rc*e+rs*e*Point(0,1));\r\
    \n    res.push_back(a.p+rc*e+rs*e*Point(0,-1));\r\n    return res;\r\n}\r\nT Area(const\
    \ Poly& a){\r\n    T res=0;\r\n    int n=a.size();\r\n    rep(i,0,n)res+=cross(a[i],a[(i+1)%n]);\r\
    \n    return fabs(res/2.);\r\n}\r\nT Area(const Poly& a,const Circle& b){\r\n\
    \    int n=a.size();\r\n    if(n<3)return .0;\r\n    auto rec=[&](auto self,const\
    \ Circle& c,const Point& p1,const Point& p2){\r\n        Point va=c.p-p1,vb=c.p-p2;\r\
    \n        T f=cross(va,vb),res=.0;\r\n        if(eq(f,.0))return res;\r\n    \
    \    if(max(abs(va),abs(vb))<c.r+eps)return f;\r\n        if(Dist(Segment(p1,p2),c.p)>c.r-eps)return\
    \ c.r*c.r*arg(vb*conj(va));\r\n        auto u=Intersection(c,Segment(p1,p2));\r\
    \n        Poly sub;\r\n        sub.push_back(p1);\r\n        for(auto& x:u)sub.push_back(x);\r\
    \n        sub.push_back(p2);\r\n        rep(i,0,sub.size()-1)res+=self(self,c,sub[i],sub[i+1]);\r\
    \n        return res;\r\n    };\r\n    T res=.0;\r\n    rep(i,0,n)res+=rec(rec,b,a[i],a[(i+1)%n]);\r\
    \n    return fabs(res/2.);\r\n}\r\nT Area(const Circle& a,const Circle& b){\r\n\
    \    T d=abs(a.p-b.p);\r\n    if(d>=a.r+b.r-eps)return .0;\r\n    if(d<=abs(a.r-b.r)+eps){\r\
    \n        T r=min(a.r,b.r);\r\n        return M_PI*r*r;\r\n    }\r\n    T ath=acos((a.r*a.r+d*d-b.r*b.r)/d/a.r/2.);\r\
    \n    T res=a.r*a.r*(ath-sin(ath*2)/2.);\r\n    T bth=acos((b.r*b.r+d*d-a.r*a.r)/d/b.r/2.);\r\
    \n    res+=b.r*b.r*(bth-sin(bth*2)/2.);\r\n    return fabs(res);\r\n}\r\nbool\
    \ isConvex(const Poly& a){\r\n    int n=a.size();\r\n    int cur,pre,nxt;\r\n\
    \    rep(i,0,n){\r\n        pre=(i-1+n)%n;\r\n        nxt=(i+1)%n;\r\n       \
    \ cur=i;\r\n        if(ccw(a[pre],a[cur],a[nxt])==-1)return 0;\r\n    }\r\n  \
    \  return 1;\r\n}\r\nint isContained(const Poly& a,const Point& b){\r\n    bool\
    \ res=0;\r\n    int n=a.size();\r\n    rep(i,0,n){\r\n        Point p=a[i]-b,q=a[(i+1)%n]-b;\r\
    \n        if(p.Y>q.Y)swap(p,q);\r\n        if(p.Y<eps and eps<q.Y and cross(p,q)>eps)res^=1;\r\
    \n        if(eq(cross(p,q),.0) and dot(p,q)<eps)return 1;\r\n    }\r\n    return\
    \ (res?2:0);\r\n}\r\nPoly ConvexHull(Poly& a){\r\n    int n=a.size(),k=0;\r\n\
    \    sort(ALL(a),[](const Point& p,const Point& q){\r\n        return (eq(p.Y,q.Y)?p.X<q.X:p.Y<q.Y);\r\
    \n    });\r\n    Poly res(n*2);\r\n    for(int i=0;i<n;res[k++]=a[i++]){\r\n \
    \       while(k>=2 and cross(res[k-1]-res[k-2],a[i]-res[k-1])<-eps)k--;\r\n  \
    \  }\r\n    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){\r\n        while(k>=t and\
    \ cross(res[k-1]-res[k-2],a[i]-res[k-1])<-eps)k--;\r\n    }\r\n    res.resize(k-1);\
    \ return res;\r\n}\r\nT Diam(const Poly& a){\r\n    int n=a.size();\r\n    int\
    \ x=0,y=0;\r\n    rep(i,1,n){\r\n        if(a[i].Y>a[x].Y)x=i;\r\n        if(a[i].Y<a[y].Y)y=i;\r\
    \n    }\r\n    T res=abs(a[x]-a[y]);\r\n    int i=x,j=y;\r\n    do{\r\n      \
    \  if(cross(a[(i+1)%n]-a[i],a[(j+1)%n]-a[j])<0)i=(i+1)%n;\r\n        else j=(j+1)%n;\r\
    \n        chmax(res,abs(a[i]-a[j]));\r\n    }while(i!=x or j!=y);\r\n    return\
    \ res;\r\n}\r\nPoly Cut(const Poly& a,const Line& l){\r\n    int n=a.size(); Poly\
    \ res;\r\n    rep(i,0,n){\r\n        Point p=a[i],q=a[(i+1)%n];\r\n        if(ccw(l.a,l.b,p)!=-1)res.push_back(p);\r\
    \n        if(ccw(l.a,l.b,p)*ccw(l.a,l.b,q)<0)res.push_back(Intersection(Line(p,q),l));\r\
    \n    }\r\n    return res;\r\n}\r\n\r\nT Closest(Poly& a){\r\n    int n=a.size();\r\
    \n    if(n<=1)return 0;\r\n    sort(ALL(a),[&](Point a,Point b){return (eq(a.X,b.X)?a.Y<b.Y:a.X<b.X);});\r\
    \n    Poly buf(n);\r\n    auto rec=[&](auto self,int lb,int rb)->T{\r\n      \
    \  if(rb-lb<=1)return (T)INF;\r\n        int mid=(lb+rb)>>1;\r\n        auto x=a[mid].X;\r\
    \n        T res=min(self(self,lb,mid),self(self,mid,rb));\r\n        inplace_merge(a.begin()+lb,a.begin()+mid,a.begin()+rb,\r\
    \n            [&](auto p,auto q){return p.Y<q.Y;});\r\n        int ptr=0;\r\n\
    \        rep(i,lb,rb){\r\n            if(abs(a[i].X-x)>=res)continue;\r\n    \
    \        rep(j,0,ptr){\r\n            auto sub=a[i]-buf[ptr-1-j];\r\n        \
    \    if(sub.Y>=res)break;\r\n            chmin(res,abs(sub));\r\n            }\r\
    \n            buf[ptr++]=a[i];\r\n        }\r\n        return res;\r\n    };\r\
    \n    return rec(rec,0,n);\r\n}\r\n\r\nCircle Incircle(const Point& a,const Point&\
    \ b,const Point& c){\r\n    T A=abs(b-c),B=abs(c-a),C=abs(a-b);\r\n    Point p(A*a.X+B*b.X+C*c.X,A*a.Y+B*b.Y+C*c.Y);\r\
    \n    p/=(A+B+C);\r\n    T r=Dist(Line(a,b),p);\r\n    return Circle(p,r);\r\n\
    }\r\nCircle Circumcircle(const Point& a,const Point& b,const Point& c){\r\n  \
    \  Line l1((a+b)/2.,(a+b)/2.+(b-a)*Point(0,1));\r\n    Line l2((b+c)/2.,(b+c)/2.+(c-b)*Point(0,1));\r\
    \n    Point p=Intersection(l1,l2);\r\n    return Circle(p,abs(p-a));\r\n}\r\n\
    Poly tangent(const Point& a,const Circle& b){\r\n    return Intersection(b,Circle(a,sqrt(norm(b.p-a)-b.r*b.r)));\r\
    \n}\r\nvector<Line> tangent(const Circle& a,const Circle& b){\r\n    vector<Line>\
    \ res;\r\n    T d=abs(a.p-b.p);\r\n    if(eq(d,0))return res;\r\n    Point u=unit(b.p-a.p);\r\
    \n    Point v=u*Point(0,1);\r\n    for(int t:{-1,1}){\r\n        T h=(a.r+b.r*t)/d;\r\
    \n        if(eq(h*h,1)){\r\n            res.push_back(Line(a.p+(h>0?u:-u)*a.r,\r\
    \n            a.p+(h>0?u:-u)*a.r+v));\r\n        }\r\n        else if(1>h*h){\r\
    \n            Point U=u*h,V=v*sqrt(1-h*h);\r\n            res.push_back(Line(a.p+(U+V)*a.r,b.p-(U+V)*(b.r*t)));\r\
    \n            res.push_back(Line(a.p+(U-V)*a.r,b.p-(U-V)*(b.r*t)));\r\n      \
    \  }\r\n    }\r\n    return res;\r\n}\r\n\r\n/**\r\n * @brief Geometry\r\n */\n"
  code: "#pragma once\r\n\r\nusing T=double;\r\nconst T eps=1e-12;\r\nusing Point=complex<T>;\r\
    \nusing Poly=vector<Point>;\r\n#define X real()\r\n#define Y imag()\r\ninline\
    \ bool eq(const T& a,const T& b){\r\n    return fabs(a-b)<eps;\r\n}\r\nbool cmp(const\
    \ Point& a,const Point& b){\r\n    auto sub=[&](Point a){return (a.Y<0?-1:(a.Y==0&&a.X>=0?0:1));};\r\
    \n    if(sub(a)!=sub(b))return sub(a)<sub(b);\r\n    return a.Y*b.X<a.X*b.Y;\r\
    \n}\r\nstruct Line{\r\n    Point a,b;\r\n    Line(){}\r\n    Line(Point _a,Point\
    \ _b):a(_a),b(_b){}\r\n    Line(T A,T B,T C){\r\n        if(eq(A,.0)){\r\n   \
    \         a=Point(0,C/B),b=Point(1/C/B);\r\n        }\r\n        else if(eq(B,.0)){\r\
    \n            a=Point(C/A,0),b=Point(C/A,1);\r\n        }\r\n        else{\r\n\
    \            a=Point(0,C/B),b=Point(C/A,0);\r\n        }\r\n    }\r\n};\r\nstruct\
    \ Segment:Line{\r\n    Segment(){}\r\n    Segment(Point _a,Point _b):Line(_a,_b){}\r\
    \n};\r\nstruct Circle{\r\n    Point p; T r;\r\n    Circle(){}\r\n    Circle(Point\
    \ _p,T _r):p(_p),r(_r){}\r\n};\r\n\r\nistream& operator>>(istream& is,Point& p){\r\
    \n    T x,y; is>>x>>y; p=Point(x,y);\r\n    return is;\r\n}\r\nostream& operator<<(ostream&\
    \ os,Point& p){\r\n    os<<fixed<<setprecision(12)<<p.X<<' '<<p.Y;\r\n    return\
    \ os;\r\n}\r\nPoint unit(const Point& a){return a/abs(a);}\r\nT dot(const Point&\
    \ a,const Point& b){\r\n    return a.X*b.X+a.Y*b.Y;\r\n}\r\nT cross(const Point&\
    \ a,const Point& b){\r\n    return a.X*b.Y-a.Y*b.X;\r\n}\r\nPoint rot(const Point&\
    \ a,const T& theta){\r\n    return Point(cos(theta)*a.X-sin(theta)*a.Y,\r\n  \
    \      sin(theta)*a.X+cos(theta)*a.Y);\r\n}\r\nT arg(const Point& a,const Point&\
    \ b,const Point& c){\r\n    return acos(dot(a-b,c-b)/abs(a-b)/abs(c-b));\r\n}\r\
    \n\r\nPoint Projection(const Line&l,const Point& p){\r\n    T t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\r\
    \n    return l.a+(l.a-l.b)*t;\r\n}\r\nPoint Projection(const Segment&l,const Point&\
    \ p){\r\n    T t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\r\n    return l.a+(l.a-l.b)*t;\r\
    \n}\r\nPoint Reflection(const Line& l,const Point& p){\r\n    return p+(Projection(l,p)-p)*2.;\r\
    \n}\r\nint ccw(const Point& a,Point b,Point c){\r\n    b-=a; c-=a;\r\n    if(cross(b,c)>eps)return\
    \ 1; //ccw\r\n    if(cross(b,c)<-eps)return -1; //cw\r\n    if(dot(b,c)<0)return\
    \ 2; //c,a,b\r\n    if(norm(b)<norm(c))return -2; //a,b,c\r\n    return 0; //a,c,b\r\
    \n}\r\nbool isOrthogonal(const Line& a,const Line& b){\r\n    return eq(dot(a.b-a.a,b.b-b.a),.0);\r\
    \n}\r\nbool isParallel(const Line& a,const Line& b){\r\n    return eq(cross(a.b-a.a,b.b-b.a),.0);\r\
    \n}\r\nbool isIntersect(const Segment& a,const Segment& b){\r\n    return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0\
    \ and\r\n        ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;\r\n}\r\nint isIntersect(const\
    \ Circle& a,const Circle& b){\r\n    T d=abs(a.p-b.p);\r\n    if(d>a.r+b.r+eps)return\
    \ 4;\r\n    if(eq(d,a.r+b.r))return 3;\r\n    if(eq(d,abs(a.r-b.r)))return 1;\r\
    \n    if(d<abs(a.r-b.r)-eps)return 0;\r\n    return 2;\r\n}\r\nT Dist(const Line&\
    \ a,const Point& b){\r\n    Point c=Projection(a,b);\r\n    return abs(c-b);\r\
    \n}\r\nT Dist(const Segment& a,const Point& b){\r\n    if(dot(a.b-a.a,b-a.a)<eps)return\
    \ abs(b-a.a);\r\n    if(dot(a.a-a.b,b-a.b)<eps)return abs(b-a.b);\r\n    return\
    \ abs(cross(a.b-a.a,b-a.a))/abs(a.b-a.a);\r\n}\r\nT Dist(const Segment& a,const\
    \ Segment& b){\r\n    if(isIntersect(a,b))return .0;\r\n    T res=min({Dist(a,b.a),Dist(a,b.b),Dist(b,a.a),Dist(b,a.b)});\r\
    \n    return res;\r\n}\r\nPoint Intersection(const Line& a,const Line& b){\r\n\
    \    T d1=cross(a.b-a.a,b.b-b.a);\r\n    T d2=cross(a.b-a.a,a.b-b.a);\r\n    if(eq(d1,0)\
    \ and eq(d2,0))return b.a;\r\n    return b.a+(b.b-b.a)*(d2/d1);\r\n}\r\nPoly Intersection(const\
    \ Circle& a,const Line& b){\r\n    Poly res;\r\n    T d=Dist(b,a.p);\r\n    if(d>a.r+eps)return\
    \ res;\r\n    Point h=Projection(b,a.p);\r\n    if(eq(d,a.r)){\r\n        res.push_back(h);\r\
    \n        return res;\r\n    }\r\n    Point e=unit(b.b-b.a);\r\n    T ph=sqrt(a.r*a.r-d*d);\r\
    \n    res.push_back(h-e*ph);\r\n    res.push_back(h+e*ph);\r\n    return res;\r\
    \n}\r\nPoly Intersection(const Circle& a,const Segment& b){\r\n    Line c(b.a,b.b);\r\
    \n    Poly sub=Intersection(a,c);\r\n    double xmi=min(b.a.X,b.b.X),xma=max(b.a.X,b.b.X);\r\
    \n    double ymi=min(b.a.Y,b.b.Y),yma=max(b.a.Y,b.b.Y);\r\n    Poly res;\r\n \
    \   rep(i,0,sub.size()){\r\n        if(xmi<=sub[i].X+eps and sub[i].X-eps<=xma\
    \ and\r\n            ymi<=sub[i].Y+eps and sub[i].Y-eps<=yma){\r\n           \
    \ res.push_back(sub[i]);\r\n        }\r\n    }\r\n    return res;\r\n}\r\nPoly\
    \ Intersection(const Circle& a,const Circle& b){\r\n    Poly res;\r\n    int mode=isIntersect(a,b);\r\
    \n    T d=abs(a.p-b.p);\r\n    if(mode==4 or mode==0)return res;\r\n    if(mode==3){\r\
    \n        T t=a.r/(a.r+b.r);\r\n        res.push_back(a.p+(b.p-a.p)*t);\r\n  \
    \      return res;\r\n    }\r\n    if(mode==1){\r\n        if(b.r<a.r-eps){\r\n\
    \            res.push_back(a.p+(b.p-a.p)*(a.r/d));\r\n        }\r\n        else{\r\
    \n            res.push_back(b.p+(a.p-b.p)*(b.r/d));\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    T rc=(a.r*a.r+d*d-b.r*b.r)/d/2.;\r\n    T rs=sqrt(a.r*a.r-rc*rc);\r\
    \n    if(a.r-abs(rc)<eps)rs=0;\r\n    Point e=unit(b.p-a.p);\r\n    res.push_back(a.p+rc*e+rs*e*Point(0,1));\r\
    \n    res.push_back(a.p+rc*e+rs*e*Point(0,-1));\r\n    return res;\r\n}\r\nT Area(const\
    \ Poly& a){\r\n    T res=0;\r\n    int n=a.size();\r\n    rep(i,0,n)res+=cross(a[i],a[(i+1)%n]);\r\
    \n    return fabs(res/2.);\r\n}\r\nT Area(const Poly& a,const Circle& b){\r\n\
    \    int n=a.size();\r\n    if(n<3)return .0;\r\n    auto rec=[&](auto self,const\
    \ Circle& c,const Point& p1,const Point& p2){\r\n        Point va=c.p-p1,vb=c.p-p2;\r\
    \n        T f=cross(va,vb),res=.0;\r\n        if(eq(f,.0))return res;\r\n    \
    \    if(max(abs(va),abs(vb))<c.r+eps)return f;\r\n        if(Dist(Segment(p1,p2),c.p)>c.r-eps)return\
    \ c.r*c.r*arg(vb*conj(va));\r\n        auto u=Intersection(c,Segment(p1,p2));\r\
    \n        Poly sub;\r\n        sub.push_back(p1);\r\n        for(auto& x:u)sub.push_back(x);\r\
    \n        sub.push_back(p2);\r\n        rep(i,0,sub.size()-1)res+=self(self,c,sub[i],sub[i+1]);\r\
    \n        return res;\r\n    };\r\n    T res=.0;\r\n    rep(i,0,n)res+=rec(rec,b,a[i],a[(i+1)%n]);\r\
    \n    return fabs(res/2.);\r\n}\r\nT Area(const Circle& a,const Circle& b){\r\n\
    \    T d=abs(a.p-b.p);\r\n    if(d>=a.r+b.r-eps)return .0;\r\n    if(d<=abs(a.r-b.r)+eps){\r\
    \n        T r=min(a.r,b.r);\r\n        return M_PI*r*r;\r\n    }\r\n    T ath=acos((a.r*a.r+d*d-b.r*b.r)/d/a.r/2.);\r\
    \n    T res=a.r*a.r*(ath-sin(ath*2)/2.);\r\n    T bth=acos((b.r*b.r+d*d-a.r*a.r)/d/b.r/2.);\r\
    \n    res+=b.r*b.r*(bth-sin(bth*2)/2.);\r\n    return fabs(res);\r\n}\r\nbool\
    \ isConvex(const Poly& a){\r\n    int n=a.size();\r\n    int cur,pre,nxt;\r\n\
    \    rep(i,0,n){\r\n        pre=(i-1+n)%n;\r\n        nxt=(i+1)%n;\r\n       \
    \ cur=i;\r\n        if(ccw(a[pre],a[cur],a[nxt])==-1)return 0;\r\n    }\r\n  \
    \  return 1;\r\n}\r\nint isContained(const Poly& a,const Point& b){\r\n    bool\
    \ res=0;\r\n    int n=a.size();\r\n    rep(i,0,n){\r\n        Point p=a[i]-b,q=a[(i+1)%n]-b;\r\
    \n        if(p.Y>q.Y)swap(p,q);\r\n        if(p.Y<eps and eps<q.Y and cross(p,q)>eps)res^=1;\r\
    \n        if(eq(cross(p,q),.0) and dot(p,q)<eps)return 1;\r\n    }\r\n    return\
    \ (res?2:0);\r\n}\r\nPoly ConvexHull(Poly& a){\r\n    int n=a.size(),k=0;\r\n\
    \    sort(ALL(a),[](const Point& p,const Point& q){\r\n        return (eq(p.Y,q.Y)?p.X<q.X:p.Y<q.Y);\r\
    \n    });\r\n    Poly res(n*2);\r\n    for(int i=0;i<n;res[k++]=a[i++]){\r\n \
    \       while(k>=2 and cross(res[k-1]-res[k-2],a[i]-res[k-1])<-eps)k--;\r\n  \
    \  }\r\n    for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){\r\n        while(k>=t and\
    \ cross(res[k-1]-res[k-2],a[i]-res[k-1])<-eps)k--;\r\n    }\r\n    res.resize(k-1);\
    \ return res;\r\n}\r\nT Diam(const Poly& a){\r\n    int n=a.size();\r\n    int\
    \ x=0,y=0;\r\n    rep(i,1,n){\r\n        if(a[i].Y>a[x].Y)x=i;\r\n        if(a[i].Y<a[y].Y)y=i;\r\
    \n    }\r\n    T res=abs(a[x]-a[y]);\r\n    int i=x,j=y;\r\n    do{\r\n      \
    \  if(cross(a[(i+1)%n]-a[i],a[(j+1)%n]-a[j])<0)i=(i+1)%n;\r\n        else j=(j+1)%n;\r\
    \n        chmax(res,abs(a[i]-a[j]));\r\n    }while(i!=x or j!=y);\r\n    return\
    \ res;\r\n}\r\nPoly Cut(const Poly& a,const Line& l){\r\n    int n=a.size(); Poly\
    \ res;\r\n    rep(i,0,n){\r\n        Point p=a[i],q=a[(i+1)%n];\r\n        if(ccw(l.a,l.b,p)!=-1)res.push_back(p);\r\
    \n        if(ccw(l.a,l.b,p)*ccw(l.a,l.b,q)<0)res.push_back(Intersection(Line(p,q),l));\r\
    \n    }\r\n    return res;\r\n}\r\n\r\nT Closest(Poly& a){\r\n    int n=a.size();\r\
    \n    if(n<=1)return 0;\r\n    sort(ALL(a),[&](Point a,Point b){return (eq(a.X,b.X)?a.Y<b.Y:a.X<b.X);});\r\
    \n    Poly buf(n);\r\n    auto rec=[&](auto self,int lb,int rb)->T{\r\n      \
    \  if(rb-lb<=1)return (T)INF;\r\n        int mid=(lb+rb)>>1;\r\n        auto x=a[mid].X;\r\
    \n        T res=min(self(self,lb,mid),self(self,mid,rb));\r\n        inplace_merge(a.begin()+lb,a.begin()+mid,a.begin()+rb,\r\
    \n            [&](auto p,auto q){return p.Y<q.Y;});\r\n        int ptr=0;\r\n\
    \        rep(i,lb,rb){\r\n            if(abs(a[i].X-x)>=res)continue;\r\n    \
    \        rep(j,0,ptr){\r\n            auto sub=a[i]-buf[ptr-1-j];\r\n        \
    \    if(sub.Y>=res)break;\r\n            chmin(res,abs(sub));\r\n            }\r\
    \n            buf[ptr++]=a[i];\r\n        }\r\n        return res;\r\n    };\r\
    \n    return rec(rec,0,n);\r\n}\r\n\r\nCircle Incircle(const Point& a,const Point&\
    \ b,const Point& c){\r\n    T A=abs(b-c),B=abs(c-a),C=abs(a-b);\r\n    Point p(A*a.X+B*b.X+C*c.X,A*a.Y+B*b.Y+C*c.Y);\r\
    \n    p/=(A+B+C);\r\n    T r=Dist(Line(a,b),p);\r\n    return Circle(p,r);\r\n\
    }\r\nCircle Circumcircle(const Point& a,const Point& b,const Point& c){\r\n  \
    \  Line l1((a+b)/2.,(a+b)/2.+(b-a)*Point(0,1));\r\n    Line l2((b+c)/2.,(b+c)/2.+(c-b)*Point(0,1));\r\
    \n    Point p=Intersection(l1,l2);\r\n    return Circle(p,abs(p-a));\r\n}\r\n\
    Poly tangent(const Point& a,const Circle& b){\r\n    return Intersection(b,Circle(a,sqrt(norm(b.p-a)-b.r*b.r)));\r\
    \n}\r\nvector<Line> tangent(const Circle& a,const Circle& b){\r\n    vector<Line>\
    \ res;\r\n    T d=abs(a.p-b.p);\r\n    if(eq(d,0))return res;\r\n    Point u=unit(b.p-a.p);\r\
    \n    Point v=u*Point(0,1);\r\n    for(int t:{-1,1}){\r\n        T h=(a.r+b.r*t)/d;\r\
    \n        if(eq(h*h,1)){\r\n            res.push_back(Line(a.p+(h>0?u:-u)*a.r,\r\
    \n            a.p+(h>0?u:-u)*a.r+v));\r\n        }\r\n        else if(1>h*h){\r\
    \n            Point U=u*h,V=v*sqrt(1-h*h);\r\n            res.push_back(Line(a.p+(U+V)*a.r,b.p-(U+V)*(b.r*t)));\r\
    \n            res.push_back(Line(a.p+(U-V)*a.r,b.p-(U-V)*(b.r*t)));\r\n      \
    \  }\r\n    }\r\n    return res;\r\n}\r\n\r\n/**\r\n * @brief Geometry\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/geometry.hpp
  requiredBy: []
  timestamp: '2022-01-06 10:09:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/geometry.hpp
layout: document
redirect_from:
- /library/Geometry/geometry.hpp
- /library/Geometry/geometry.hpp.html
title: Geometry
---