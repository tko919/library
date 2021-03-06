using T=double;
using P=complex<T>;
using Poly=vector<P>;
#define X real()
#define Y imag()
inline bool eq(const T& a,const T& b){
   return fabs(a-b)<eps;
}
inline bool cmp(const P& a,const P& b){
   return (eq(a.X,b.X)?a.Y<b.Y:a.X<b.X);
}
struct Line{
   P a,b;
   Line(){}
   Line(P _a,P _b):a(_a),b(_b){}
   Line(T A,T B,T C){
      if(eq(A,.0)){
         a=P(0,C/B),b=P(1/C/B);
      }
      else if(eq(B,.0)){
         a=P(C/A,0),b=P(C/A,1);
      }
      else{
         a=P(0,C/B),b=P(C/A,0);
      }
   }
};
struct Segment:Line{
   Segment(){}
   Segment(P _a,P _b):Line(_a,_b){}
};
struct Circle{
   P p; T r;
   Circle(){}
   Circle(P _p,T _r):p(_p),r(_r){}
};

istream& operator>>(istream& is,P& p){
   T x,y; is>>x>>y; p=P(x,y);
   return is;
}
ostream& operator<<(ostream& os,P& p){
   os<<fixed<<setprecision(12)<<p.X<<' '<<p.Y;
   return os;
}
P unit(const P& a){return a/abs(a);}
T dot(const P& a,const P& b){
   return a.X*b.X+a.Y*b.Y;
}
T cross(const P& a,const P& b){
   return a.X*b.Y-a.Y*b.X;
}
P rot(const P& a,const T& theta){
   return P(cos(theta)*a.X-sin(theta)*a.Y,
      sin(theta)*a.X+cos(theta)*a.Y);
}
T arg(const P& a,const P& b,const P& c){
   return acos(dot(a-b,c-b)/abs(a-b)/abs(c-b));
}

P Projection(const Line&l,const P& p){
   T t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);
   return l.a+(l.a-l.b)*t;
}
P Projection(const Segment&l,const P& p){
   T t=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);
   return l.a+(l.a-l.b)*t;
}
P Reflection(const Line& l,const P& p){
   return p+(Projection(l,p)-p)*2.;
}
int ccw(const P& a,P b,P c){
   b-=a; c-=a;
   if(cross(b,c)>eps)return 1; //ccw
   if(cross(b,c)<-eps)return -1; //cw
   if(dot(b,c)<0)return 2; //c,a,b
   if(norm(b)<norm(c))return -2; //a,b,c
   return 0; //a,c,b
}
bool isOrthogonal(const Line& a,const Line& b){
   return eq(dot(a.b-a.a,b.b-b.a),.0);
}
bool isParallel(const Line& a,const Line& b){
   return eq(cross(a.b-a.a,b.b-b.a),.0);
}
bool isIntersect(const Segment& a,const Segment& b){
   return ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b)<=0 and
      ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b)<=0;
}
int isIntersect(const Circle& a,const Circle& b){
   T d=abs(a.p-b.p);
   if(d>a.r+b.r+eps)return 4;
   if(eq(d,a.r+b.r))return 3;
   if(eq(d,abs(a.r-b.r)))return 1;
   if(d<abs(a.r-b.r)-eps)return 0;
   return 2;
}
T Dist(const Line& a,const P& b){
   P c=Projection(a,b);
   return abs(c-b);
}
T Dist(const Segment& a,const P& b){
   if(dot(a.b-a.a,b-a.a)<eps)return abs(b-a.a);
   if(dot(a.a-a.b,b-a.b)<eps)return abs(b-a.b);
   return abs(cross(a.b-a.a,b-a.a))/abs(a.b-a.a);
}
T Dist(const Segment& a,const Segment& b){
   if(isIntersect(a,b))return .0;
   T res=min({Dist(a,b.a),Dist(a,b.b),Dist(b,a.a),Dist(b,a.b)});
   return res;
}
P Intersection(const Line& a,const Line& b){
   T d1=cross(a.b-a.a,b.b-b.a);
   T d2=cross(a.b-a.a,a.b-b.a);
   if(eq(d1,0) and eq(d2,0))return b.a;
   return b.a+(b.b-b.a)*(d2/d1);
}
Poly Intersection(const Circle& a,const Line& b){
   Poly res;
   T d=Dist(b,a.p);
   if(d>a.r+eps)return res;
   P h=Projection(b,a.p);
   if(eq(d,a.r)){
      res.push_back(h);
      return res;
   }
   P e=unit(b.b-b.a);
   T ph=sqrt(a.r*a.r-d*d);
   res.push_back(h-e*ph);
   res.push_back(h+e*ph);
   return res;
}
Poly Intersection(const Circle& a,const Segment& b){
   Line c(b.a,b.b);
   Poly sub=Intersection(a,c);
   double xmi=min(b.a.X,b.b.X),xma=max(b.a.X,b.b.X);
   double ymi=min(b.a.Y,b.b.Y),yma=max(b.a.Y,b.b.Y);
   Poly res;
   rep(i,0,sub.size()){
      if(xmi<=sub[i].X+eps and sub[i].X-eps<=xma and
         ymi<=sub[i].Y+eps and sub[i].Y-eps<=yma){
         res.push_back(sub[i]);
      }
   }
   return res;
}
Poly Intersection(const Circle& a,const Circle& b){
   Poly res;
   int mode=isIntersect(a,b);
   T d=abs(a.p-b.p);
   if(mode==4 or mode==0)return res;
   if(mode==3){
      T t=a.r/(a.r+b.r);
      res.push_back(a.p+(b.p-a.p)*t);
      return res;
   }
   if(mode==1){
      if(b.r<a.r-eps){
         res.push_back(a.p+(b.p-a.p)*(a.r/d));
      }
      else{
         res.push_back(b.p+(a.p-b.p)*(b.r/d));
      }
      return res;
   }
   T rc=(a.r*a.r+d*d-b.r*b.r)/d/2.;
   T rs=sqrt(a.r*a.r-rc*rc);
   if(a.r-abs(rc)<eps)rs=0;
   P e=unit(b.p-a.p);
   res.push_back(a.p+rc*e+rs*e*P(0,1));
   res.push_back(a.p+rc*e+rs*e*P(0,-1));
   return res;
}
T Area(const Poly& a){
   T res=0;
   int n=a.size();
   rep(i,0,n)res+=cross(a[i],a[(i+1)%n]);
   return res/2.;
}
T Area(const Poly& a,const Circle& b){
   int n=a.size();
   if(n<3)return .0;
   auto rec=[&](auto self,const Circle& c,const P& p1,const P& p2){
      P va=c.p-p1,vb=c.p-p2;
      T f=cross(va,vb),res=.0;
      if(eq(f,.0))return res;
      if(max(abs(va),abs(vb))<c.r+eps)return f;
      if(Dist(Segment(p1,p2),c.p)>c.r-eps)return c.r*c.r*arg(vb*conj(va));
      auto u=Intersection(c,Segment(p1,p2));
      Poly sub;
      sub.push_back(p1);
      for(auto& x:u)sub.push_back(x);
      sub.push_back(p2);
      rep(i,0,sub.size()-1)res+=self(self,c,sub[i],sub[i+1]);
      return res;
   };
   T res=.0;
   rep(i,0,n)res+=rec(rec,b,a[i],a[(i+1)%n]);
   return res/2.;
}
T Area(const Circle& a,const Circle& b){
   T d=abs(a.p-b.p);
   if(d>=a.r+b.r-eps)return .0;
   if(d<=abs(a.r-b.r)+eps){
      T r=min(a.r,b.r);
      return M_PI*r*r;
   }
   T ath=acos((a.r*a.r+d*d-b.r*b.r)/d/a.r/2.);
   T res=a.r*a.r*(ath-sin(ath*2)/2.);
   T bth=acos((b.r*b.r+d*d-a.r*a.r)/d/b.r/2.);
   res+=b.r*b.r*(bth-sin(bth*2)/2.);
   return res;
}
bool isConvex(const Poly& a){
   int n=a.size();
   int cur,pre,nxt;
   rep(i,0,n){
      pre=(i-1+n)%n;
      nxt=(i+1)%n;
      cur=i;
      if(ccw(a[pre],a[cur],a[nxt])==-1)return 0;
   }
   return 1;
}
int isContained(const Poly& a,const P& b){
   bool res=0;
   int n=a.size();
   rep(i,0,n){
      P p=a[i]-b,q=a[(i+1)%n]-b;
      if(p.Y>q.Y)swap(p,q);
      if(p.Y<eps and eps<q.Y and cross(p,q)>eps)res^=1;
      if(eq(cross(p,q),.0) and dot(p,q)<eps)return 1;
   }
   return (res?2:0);
}
Poly ConvexHull(Poly& a){
   int n=a.size(),k=0;
   sort(ALL(a),[](const P& p,const P& q){
      return (eq(p.Y,q.Y)?p.X<q.X:p.Y<q.Y);
   });
   Poly res(n*2);
   for(int i=0;i<n;res[k++]=a[i++]){
      while(k>=2 and cross(res[k-1]-res[k-2],a[i]-res[k-1])<-eps)k--;
   }
   for(int i=n-2,t=k+1;i>=0;res[k++]=a[i--]){
      while(k>=t and cross(res[k-1]-res[k-2],a[i]-res[k-1])<-eps)k--;
   }
   res.resize(k-1); return res;
}
T Diam(const Poly& a){
   int n=a.size();
   int x=0,y=0;
   rep(i,1,n){
      if(a[i].Y>a[x].Y)x=i;
      if(a[i].Y<a[y].Y)y=i;
   }
   T res=abs(a[x]-a[y]);
   int i=x,j=y;
   do{
      if(cross(a[(i+1)%n]-a[i],a[(j+1)%n]-a[j])<0)i=(i+1)%n;
      else j=(j+1)%n;
      chmax(res,abs(a[i]-a[j]));
   }while(i!=x or j!=y);
   return res;
}
Poly Cut(const Poly& a,const Line& l){
   int n=a.size(); Poly res;
   rep(i,0,n){
      P p=a[i],q=a[(i+1)%n];
      if(ccw(l.a,l.b,p)!=-1)res.push_back(p);
      if(ccw(l.a,l.b,p)*ccw(l.a,l.b,q)<0)res.push_back(Intersection(Line(p,q),l));
   }
   return res;
}

T Closest(Poly& a){
   int n=a.size();
   if(n<=1)return 0;
   sort(ALL(a),cmp);
   Poly buf(n);
   auto rec=[&](auto self,int lb,int rb)->T{
      if(rb-lb<=1)return (T)INF;
      int mid=(lb+rb)>>1;
      auto x=a[mid].X;
      T res=min(self(self,lb,mid),self(self,mid,rb));
      inplace_merge(a.begin()+lb,a.begin()+mid,a.begin()+rb,
         [&](auto p,auto q){return p.Y<q.Y;});
      int ptr=0;
      rep(i,lb,rb){
         if(abs(a[i].X-x)>=res)continue;
         rep(j,0,ptr){
            auto sub=a[i]-buf[ptr-1-j];
            if(sub.Y>=res)break;
            chmin(res,abs(sub));
         }
         buf[ptr++]=a[i];
      }
      return res;
   };
   return rec(rec,0,n);
}

Circle Incircle(const P& a,const P& b,const P& c){
   T A=abs(b-c),B=abs(c-a),C=abs(a-b);
   P p(A*a.X+B*b.X+C*c.X,A*a.Y+B*b.Y+C*c.Y);
   p/=(A+B+C);
   T r=Dist(Line(a,b),p);
   return Circle(p,r);
}
Circle Circumcircle(const P& a,const P& b,const P& c){
   Line l1((a+b)/2.,(a+b)/2.+(b-a)*P(0,1));
   Line l2((b+c)/2.,(b+c)/2.+(c-b)*P(0,1));
   P p=Intersection(l1,l2);
   return Circle(p,abs(p-a));
}
Poly tangent(const P& a,const Circle& b){
   return Intersection(b,Circle(a,sqrt(norm(b.p-a)-b.r*b.r)));
}
vector<Line> tangent(const Circle& a,const Circle& b){
   vector<Line> res;
   T d=abs(a.p-b.p);
   if(eq(d,0))return res;
   P u=unit(b.p-a.p);
   P v=u*P(0,1);
   for(int t:{-1,1}){
      T h=(a.r+b.r*t)/d;
      if(eq(h*h,1)){
         res.push_back(Line(a.p+(h>0?u:-u)*a.r,
            a.p+(h>0?u:-u)*a.r+v));
      }
      else if(1>h*h){
         P U=u*h,V=v*sqrt(1-h*h);
         res.push_back(Line(a.p+(U+V)*a.r,b.p-(U+V)*(b.r*t)));
         res.push_back(Line(a.p+(U-V)*a.r,b.p-(U-V)*(b.r*t)));
      }
   }
   return res;
}
