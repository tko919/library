---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/fft.hpp
    title: Fast Fourier Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Big Integer(Float)
    links: []
  bundledCode: "#line 2 \"Convolution/fft.hpp\"\n\r\nnamespace FFT{\r\n    struct\
    \ C{\r\n        double x,y;\r\n        C(double _x=0,double _y=0):x(_x),y(_y){}\r\
    \n        C operator~()const{return C(x,-y);}\r\n        C operator*(const C&\
    \ c)const{return C(x*c.x-y*c.y,x*c.y+y*c.x);}\r\n        C operator+(const C&\
    \ c)const{return C(x+c.x,y+c.y);}\r\n        C operator-(const C& c)const{return\
    \ C(x-c.x,y-c.y);}\r\n    };\r\n    vector<vector<C>> w(1,vector<C>(1,1));\r\n\
    \    void init(int lg){\r\n        for(int d=1,m=1;d<=lg;d++,m<<=1)if(d>=(int)w.size()){\r\
    \n             w.emplace_back(m);\r\n             const double th=M_PI/m;\r\n\
    \             for(int i=0;i<m;i++)w[d][i]=(i&1?C(cos(th*i),sin(th*i)):w[d-1][i>>1]);\r\
    \n        }\r\n    }\r\n    void fft(vector<C>& f,bool inv){\r\n        const\
    \ int n=f.size(); const int lg=__lg(n);\r\n        if(lg>=(int)w.size())init(lg);\r\
    \n        if(inv){\r\n            for(int k=1;k<=lg;k++){\r\n                const\
    \ int d=1<<(k-1);\r\n                for(int s=0;s<n;s+=2*d){\r\n            \
    \        for(int i=s;i<s+d;i++){\r\n                        C x=f[i],y=~w[k][i-s]*f[d+i];\r\
    \n                        f[i]=x+y; f[d+i]=x-y;\r\n                    }\r\n \
    \               }\r\n            }\r\n         }\r\n         else{\r\n       \
    \      for(int k=lg;k;k--){\r\n                 const int d=1<<(k-1);\r\n    \
    \             for(int s=0;s<n;s+=2*d){\r\n                     for(int i=s;i<s+d;i++){\r\
    \n                         C x=f[i],y=f[d+i];\r\n                         f[i]=x+y;\
    \ f[d+i]=w[k][i-s]*(x-y);\r\n                     }\r\n                 }\r\n\
    \             }\r\n         }\r\n    }\r\n    template<typename T>vector<T> mult(const\
    \ vector<T>& a,const vector<T>& b){\r\n        const int as=a.size(); const int\
    \ bs=b.size(); \r\n        if(!as or !bs)return {};\r\n        const int cs=as+bs-1;\
    \ vector<T> c(cs);\r\n        if(max(as,bs)<16){\r\n            for(int i=0;i<as;i++)for(int\
    \ j=0;j<bs;j++){\r\n                c[i+j]+=(int)a[i]*b[j];\r\n            }\r\
    \n            return c;\r\n        }\r\n        const int n=1<<__lg(2*cs-1); vector<C>\
    \ f(n);\r\n        for(int i=0;i<as;i++)f[i].x=a[i];\r\n        for(int i=0;i<bs;i++)f[i].y=b[i];\r\
    \n        fft(f,0); static const C rad(0,-.25);\r\n        for(int i=0;i<n;i++){\r\
    \n            int j=i?i^((1<<__lg(i))-1):0;\r\n            if(i>j)continue;\r\n\
    \            C x=f[i]+~f[j],y=f[i]-~f[j];\r\n            f[i]=x*y*rad; f[j]=~f[i];\r\
    \n        }\r\n        fft(f,1); for(int i=0;i<cs;i++)c[i]=round(f[i].x/n);\r\n\
    \        return c;\r\n    }\r\n    template<typename T>vector<T> square(const\
    \ vector<T>& a){\r\n        const int as=a.size(); if(!as)return {};\r\n     \
    \   const int cs=as*2-1; vector<T> c(cs);\r\n        if(as<16){\r\n          \
    \  for(int i=0;i<as;i++)for(int j=0;j<as;j++){\r\n                c[i+j]+=(int)a[i]*a[j];\r\
    \n            }\r\n            return c;\r\n        }\r\n        const int n=1<<__lg(cs*2-1);\
    \ vector<C> f(n);\r\n        for(int i=0;i<as;i++)f[i].x=a[i];\r\n        fft(f,0);\
    \ for(int i=0;i<n;i++)f[i]=f[i]*f[i];\r\n        fft(f,1); for(int i=0;i<cs;i++)c[i]=round(f[i].x/n);\r\
    \n        return c;\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Fast Fourier Transform\r\
    \n */\n#line 3 \"Math/bigint.hpp\"\n\r\ntemplate<int D>struct bigint{\r\n   static\
    \ const int B=pow(10,D);\r\n   int sign=0; vector<ll> v;\r\n   static int get_D(){return\
    \ D;}\r\n   static int get_B(){return B;}\r\n   bigint(ll x=0){\r\n      if(x<0)x*=-1,sign=1;\r\
    \n      while(x){v.push_back(x%B); x/=B;}\r\n   }\r\n   bigint(string s){\r\n\
    \      if(s[0]=='-')s.erase(s.begin()),sign=1;\r\n      int add=0,cnt=0,base=1;\r\
    \n      while(s.size()){\r\n         if(cnt==D){\r\n            v.push_back(add);\r\
    \n            cnt=0; add=0; base=1;\r\n         }\r\n         add=(s.back()-'0')*base+add;\r\
    \n         cnt++; base*=10; s.pop_back();\r\n      } if(add)v.push_back(add);\r\
    \n   }\r\n   bigint operator-()const{bigint res=*this; res.sign^=1;return res;}\r\
    \n   bigint abs()const{bigint res=*this; res.sign=0; return res;}\r\n   ll& operator[](const\
    \ int i){return v[i];}\r\n   int size()const{return v.size();}\r\n   void norm(){\r\
    \n      rep(i,0,v.size()-1){\r\n         if(v[i]>=0){v[i+1]+=v[i]/B; v[i]%=B;}\r\
    \n         else{int c=(-v[i]+B-1)/B; v[i]+=c*B; v[i+1]-=c;}\r\n      }\r\n   \
    \   while(!v.empty() and v.back()>=B){\r\n         int c=v.back()/B;\r\n     \
    \    v.back()%=B; v.push_back(c);\r\n      }\r\n      while(!v.empty() and v.back()==0)v.pop_back();\r\
    \n   }\r\n   string to_str()const{\r\n      string res;\r\n      if(v.empty())return\
    \ \"0\";\r\n      if(sign)res+='-';\r\n      res+=to_string(v.back());\r\n   \
    \   for(int i=v.size()-2;i>=0;i--){\r\n         string add; int w=v[i];\r\n  \
    \       rep(_,0,D){\r\n            add+=('0'+(w%10)); w/=10;\r\n         } reverse(ALL(add));\
    \ res+=add;\r\n      } return res;\r\n   }\r\n   friend istream& operator>>(istream&\
    \ is,bigint<D>& x){\r\n      string tmp; is>>tmp; x=bigint(tmp); return is;\r\n\
    \   }\r\n   friend ostream& operator<<(ostream& os,bigint<D> x){\r\n      os<<x.to_str();\
    \ return os;\r\n   }\r\n   bigint& operator<<=(const int& x){\r\n      if(!v.empty()){\r\
    \n         vector<ll> add(x,0);\r\n         v.insert(v.begin(),ALL(add));\r\n\
    \      } return *this;\r\n   }\r\n   bigint& operator>>=(const int& x){\r\n  \
    \    v=vector<ll>(v.begin()+min(x,(int)v.size()),v.end());\r\n      return *this;\r\
    \n   }\r\n   bigint& operator+=(const bigint& x){\r\n      if(sign!=x.sign){*this-=(-x);\
    \ return *this;}\r\n      if((int)v.size()<(int)x.size())v.resize(x.size(),0);\r\
    \n      rep(i,0,x.size()){v[i]+=x.v[i];} norm(); return *this;\r\n   }\r\n   bigint&\
    \ operator-=(const bigint& x){\r\n      if(sign!=x.sign){*this+=(-x); return *this;}\r\
    \n      if(abs()<x.abs()){*this=x-(*this); sign^=1; return *this;}\r\n      rep(i,0,x.size()){v[i]-=x.v[i];}\
    \ norm(); return *this;\r\n   }\r\n   bigint& operator*=(const bigint& x){\r\n\
    \      sign^=x.sign;\r\n      auto v1=FFT::mult(v,x.v);\r\n      v.assign(v1.size(),0);\r\
    \n      rep(i,0,v1.size()){\r\n         ll val=v1[i];\r\n         for(int j=i;val;j++){\r\
    \n            if(j==(int)v.size())v.push_back(0);\r\n            v[j]+=val%B;\
    \ val/=B;\r\n         }\r\n      } norm(); return *this;\r\n   }\r\n   bigint&\
    \ operator/=(const bigint& x){  \r\n      bigint a=abs(),b=x.abs(); sign^=x.sign;\r\
    \n      if(a<b)return *this=bigint();\r\n      int d=a.size()-b.size()+1;\r\n\
    \      bigint inv(1LL*B*B/b.v.back()),pre;\r\n      int cur=2,bcur=1; pre=bigint(0);\r\
    \n      while(inv!=pre or bcur<b.size()){\r\n         bcur=min(bcur<<1,b.size());\r\
    \n         bigint c; c.v=vector<ll>(b.v.end()-bcur,b.v.end());\r\n         pre=inv;\
    \ inv*=((bigint(2)<<(cur+bcur-1))-inv*c);\r\n         cur=min(cur<<1,d);\r\n \
    \        inv.v=vector<ll>(inv.v.end()-cur,inv.v.end());\r\n      }\r\n      inv.v=vector<ll>(inv.v.end()-d,inv.v.end());\r\
    \n      bigint res=a*inv; res>>=(a.size());\r\n      bigint mul=res*b; while(mul+b<=a){res+=bigint(1);\
    \ mul+=b;}\r\n      v=res.v; return *this;\r\n   }\r\n   bigint& operator%=(const\
    \ bigint& x){\r\n      bigint div=(*this)/x; (*this)-=div*x; return *this;\r\n\
    \   }\r\n   bigint square(){\r\n      bigint res=*this; res.sign=0;\r\n      auto\
    \ v1=FFT::mult(v,v);\r\n      res.v.assign(v1.size(),0);\r\n      rep(i,0,v1.size()){\r\
    \n         ll val=v1[i];\r\n         for(int j=i;val;j++){\r\n            if(j==(int)res.v.size())res.v.push_back(0);\r\
    \n            res.v[j]+=val%B; val/=B;\r\n         }\r\n      } res.norm(); return\
    \ res;\r\n   }\r\n   bigint mul(ll x){\r\n      bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n      for(int i=res.v.size()-1;i>=0;i--)res.v[i]*=x;\r\n      res.norm(); return\
    \ res;\r\n   }\r\n   bigint div(ll x){\r\n      bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n      for(int i=res.v.size()-1;i>=0;i--){\r\n         if(res.v[i]%x!=0 and i!=0){res.v[i-1]+=B*(res.v[i]%x);}\
    \ res.v[i]/=x;\r\n      } res.norm(); return res;\r\n   }\r\n   bigint operator<<(const\
    \ int& x)const{return bigint(*this)<<=x;}\r\n   bigint operator>>(const int& x)const{return\
    \ bigint(*this)>>=x;}\r\n   bigint operator+(const bigint& x)const{return bigint(*this)+=x;}\r\
    \n   bigint operator-(const bigint& x)const{return bigint(*this)-=x;}\r\n   bigint\
    \ operator*(const bigint& x)const{return bigint(*this)*=x;}\r\n   bigint operator/(const\
    \ bigint& x)const{return bigint(*this)/=x;}\r\n   bigint operator%(const bigint&\
    \ x)const{return bigint(*this)%=x;}\r\n   bool operator<(const bigint& x)const{\r\
    \n      if(sign!=x.sign)return sign>x.sign;\r\n      if((int)v.size()!=(int)x.size()){\r\
    \n         if(sign)return (int)x.size()<(int)v.size();\r\n         else return\
    \ (int)v.size()<(int)x.size();\r\n      }\r\n      for(int i=v.size()-1;i>=0;i--)if(v[i]!=x.v[i]){\r\
    \n         if(sign)return x.v[i]<v[i];\r\n         else return v[i]<x.v[i];\r\n\
    \      }\r\n      return false;\r\n   }\r\n   bool operator>(const bigint& x)const{return\
    \ x<*this;}\r\n   bool operator<=(const bigint& x)const{return !(*this>x);}\r\n\
    \   bool operator>=(const bigint& x)const{return !(*this<x);}\r\n   bool operator==(const\
    \ bigint& x)const{return !(*this<x) and !(*this>x);}\r\n   bool operator!=(const\
    \ bigint& x)const{return !(*this==x);}\r\n};\r\ntypedef bigint<4> Bigint;\r\n\
    \ \r\nstruct Bigfloat{\r\n   Bigint v; int p=0;\r\n   Bigfloat(){}\r\n   Bigfloat(const\
    \ ll& _v){v=Bigint(_v);}\r\n   Bigfloat(const Bigint& _v,int _p=0):v(_v),p(_p){}\r\
    \n   void set(int _p){if(p<_p){v>>=(_p-p);} else{v<<=(p-_p);} p=_p;}\r\n   Bigint\
    \ to_int()const{if(p<0)return v>>(-p); else return v<<p;}\r\n   Bigfloat& operator+=(const\
    \ Bigfloat& x){\r\n      if(p>x.p)set(x.p),v+=x.v;\r\n      else v+=x.v<<(x.p-p);\r\
    \n      return *this;\r\n   }\r\n   Bigfloat& operator-=(const Bigfloat& x){\r\
    \n      if(p>x.p)set(x.p),v-=x.v;\r\n      else v-=x.v<<(x.p-p);\r\n      return\
    \ *this;\r\n   }\r\n   Bigfloat square(){Bigfloat res=*this; res.p*=2; res.v=res.v.square();\
    \ return res;}\r\n   Bigfloat mul(ll x){Bigfloat res=*this; res.v=v.mul(x); return\
    \ res;}\r\n   Bigfloat div(ll x){Bigfloat res=*this; res.v=v.div(x); return res;}\r\
    \n   Bigfloat& operator*=(const Bigfloat& x){p+=x.p; v*=x.v; return *this;}\r\n\
    \   Bigfloat& operator/=(const Bigfloat& x){p-=x.p; v/=x.v; return *this;}\r\n\
    \   Bigfloat operator+(const Bigfloat& x)const{return Bigfloat(*this)+=x;}\r\n\
    \   Bigfloat operator-(const Bigfloat& x)const{return Bigfloat(*this)-=x;}\r\n\
    \   Bigfloat operator*(const Bigfloat& x)const{return Bigfloat(*this)*=x;}\r\n\
    \   Bigfloat operator/(const Bigfloat& x)const{return Bigfloat(*this)/=x;}\r\n\
    \   string to_str(){\r\n      string res=v.abs().to_str(); int d=Bigint::get_D();\r\
    \n      if(p*d>0)res+=string(p*d,'0');\r\n      else if(-p*d>=1 and -p*d<(int)res.size()){\r\
    \n         res=res.substr(0,(int)res.size()+p*d)+'.'+res.substr((int)res.size()+p*d);\r\
    \n      }\r\n      else if(-p*d>=(int)res.size())res=\"0.\"+string(-p*d-(int)res.size(),'0')+res;\r\
    \n      if(v.sign){res.insert(res.begin(),'-');} return res;\r\n   }\r\n   friend\
    \ ostream& operator<<(ostream& os,Bigfloat x){\r\n      os<<x.to_str(); return\
    \ os;\r\n   }\r\n};\r\n \r\nBigfloat sqrt(ll n,int d){\r\n   Bigfloat res(Bigint((ll)sqrt(1LL*Bigint::get_B()*Bigint::get_B()/n)),-1),pre;\r\
    \n   int cur=1;\r\n   while(pre.v!=res.v){\r\n      cur=min(cur<<1,d);\r\n   \
    \   pre=res; Bigfloat add=Bigfloat(1)-res.square().mul(n);\r\n      add.set(-cur);\
    \ res+=(res*add).div(2); res.set(-cur);\r\n   } return res.mul(n);\r\n}\r\n\r\n\
    /**\r\n * @brief Big Integer(Float)\r\n */\n"
  code: "#pragma once\r\n#include \"Convolution/fft.hpp\"\r\n\r\ntemplate<int D>struct\
    \ bigint{\r\n   static const int B=pow(10,D);\r\n   int sign=0; vector<ll> v;\r\
    \n   static int get_D(){return D;}\r\n   static int get_B(){return B;}\r\n   bigint(ll\
    \ x=0){\r\n      if(x<0)x*=-1,sign=1;\r\n      while(x){v.push_back(x%B); x/=B;}\r\
    \n   }\r\n   bigint(string s){\r\n      if(s[0]=='-')s.erase(s.begin()),sign=1;\r\
    \n      int add=0,cnt=0,base=1;\r\n      while(s.size()){\r\n         if(cnt==D){\r\
    \n            v.push_back(add);\r\n            cnt=0; add=0; base=1;\r\n     \
    \    }\r\n         add=(s.back()-'0')*base+add;\r\n         cnt++; base*=10; s.pop_back();\r\
    \n      } if(add)v.push_back(add);\r\n   }\r\n   bigint operator-()const{bigint\
    \ res=*this; res.sign^=1;return res;}\r\n   bigint abs()const{bigint res=*this;\
    \ res.sign=0; return res;}\r\n   ll& operator[](const int i){return v[i];}\r\n\
    \   int size()const{return v.size();}\r\n   void norm(){\r\n      rep(i,0,v.size()-1){\r\
    \n         if(v[i]>=0){v[i+1]+=v[i]/B; v[i]%=B;}\r\n         else{int c=(-v[i]+B-1)/B;\
    \ v[i]+=c*B; v[i+1]-=c;}\r\n      }\r\n      while(!v.empty() and v.back()>=B){\r\
    \n         int c=v.back()/B;\r\n         v.back()%=B; v.push_back(c);\r\n    \
    \  }\r\n      while(!v.empty() and v.back()==0)v.pop_back();\r\n   }\r\n   string\
    \ to_str()const{\r\n      string res;\r\n      if(v.empty())return \"0\";\r\n\
    \      if(sign)res+='-';\r\n      res+=to_string(v.back());\r\n      for(int i=v.size()-2;i>=0;i--){\r\
    \n         string add; int w=v[i];\r\n         rep(_,0,D){\r\n            add+=('0'+(w%10));\
    \ w/=10;\r\n         } reverse(ALL(add)); res+=add;\r\n      } return res;\r\n\
    \   }\r\n   friend istream& operator>>(istream& is,bigint<D>& x){\r\n      string\
    \ tmp; is>>tmp; x=bigint(tmp); return is;\r\n   }\r\n   friend ostream& operator<<(ostream&\
    \ os,bigint<D> x){\r\n      os<<x.to_str(); return os;\r\n   }\r\n   bigint& operator<<=(const\
    \ int& x){\r\n      if(!v.empty()){\r\n         vector<ll> add(x,0);\r\n     \
    \    v.insert(v.begin(),ALL(add));\r\n      } return *this;\r\n   }\r\n   bigint&\
    \ operator>>=(const int& x){\r\n      v=vector<ll>(v.begin()+min(x,(int)v.size()),v.end());\r\
    \n      return *this;\r\n   }\r\n   bigint& operator+=(const bigint& x){\r\n \
    \     if(sign!=x.sign){*this-=(-x); return *this;}\r\n      if((int)v.size()<(int)x.size())v.resize(x.size(),0);\r\
    \n      rep(i,0,x.size()){v[i]+=x.v[i];} norm(); return *this;\r\n   }\r\n   bigint&\
    \ operator-=(const bigint& x){\r\n      if(sign!=x.sign){*this+=(-x); return *this;}\r\
    \n      if(abs()<x.abs()){*this=x-(*this); sign^=1; return *this;}\r\n      rep(i,0,x.size()){v[i]-=x.v[i];}\
    \ norm(); return *this;\r\n   }\r\n   bigint& operator*=(const bigint& x){\r\n\
    \      sign^=x.sign;\r\n      auto v1=FFT::mult(v,x.v);\r\n      v.assign(v1.size(),0);\r\
    \n      rep(i,0,v1.size()){\r\n         ll val=v1[i];\r\n         for(int j=i;val;j++){\r\
    \n            if(j==(int)v.size())v.push_back(0);\r\n            v[j]+=val%B;\
    \ val/=B;\r\n         }\r\n      } norm(); return *this;\r\n   }\r\n   bigint&\
    \ operator/=(const bigint& x){  \r\n      bigint a=abs(),b=x.abs(); sign^=x.sign;\r\
    \n      if(a<b)return *this=bigint();\r\n      int d=a.size()-b.size()+1;\r\n\
    \      bigint inv(1LL*B*B/b.v.back()),pre;\r\n      int cur=2,bcur=1; pre=bigint(0);\r\
    \n      while(inv!=pre or bcur<b.size()){\r\n         bcur=min(bcur<<1,b.size());\r\
    \n         bigint c; c.v=vector<ll>(b.v.end()-bcur,b.v.end());\r\n         pre=inv;\
    \ inv*=((bigint(2)<<(cur+bcur-1))-inv*c);\r\n         cur=min(cur<<1,d);\r\n \
    \        inv.v=vector<ll>(inv.v.end()-cur,inv.v.end());\r\n      }\r\n      inv.v=vector<ll>(inv.v.end()-d,inv.v.end());\r\
    \n      bigint res=a*inv; res>>=(a.size());\r\n      bigint mul=res*b; while(mul+b<=a){res+=bigint(1);\
    \ mul+=b;}\r\n      v=res.v; return *this;\r\n   }\r\n   bigint& operator%=(const\
    \ bigint& x){\r\n      bigint div=(*this)/x; (*this)-=div*x; return *this;\r\n\
    \   }\r\n   bigint square(){\r\n      bigint res=*this; res.sign=0;\r\n      auto\
    \ v1=FFT::mult(v,v);\r\n      res.v.assign(v1.size(),0);\r\n      rep(i,0,v1.size()){\r\
    \n         ll val=v1[i];\r\n         for(int j=i;val;j++){\r\n            if(j==(int)res.v.size())res.v.push_back(0);\r\
    \n            res.v[j]+=val%B; val/=B;\r\n         }\r\n      } res.norm(); return\
    \ res;\r\n   }\r\n   bigint mul(ll x){\r\n      bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n      for(int i=res.v.size()-1;i>=0;i--)res.v[i]*=x;\r\n      res.norm(); return\
    \ res;\r\n   }\r\n   bigint div(ll x){\r\n      bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n      for(int i=res.v.size()-1;i>=0;i--){\r\n         if(res.v[i]%x!=0 and i!=0){res.v[i-1]+=B*(res.v[i]%x);}\
    \ res.v[i]/=x;\r\n      } res.norm(); return res;\r\n   }\r\n   bigint operator<<(const\
    \ int& x)const{return bigint(*this)<<=x;}\r\n   bigint operator>>(const int& x)const{return\
    \ bigint(*this)>>=x;}\r\n   bigint operator+(const bigint& x)const{return bigint(*this)+=x;}\r\
    \n   bigint operator-(const bigint& x)const{return bigint(*this)-=x;}\r\n   bigint\
    \ operator*(const bigint& x)const{return bigint(*this)*=x;}\r\n   bigint operator/(const\
    \ bigint& x)const{return bigint(*this)/=x;}\r\n   bigint operator%(const bigint&\
    \ x)const{return bigint(*this)%=x;}\r\n   bool operator<(const bigint& x)const{\r\
    \n      if(sign!=x.sign)return sign>x.sign;\r\n      if((int)v.size()!=(int)x.size()){\r\
    \n         if(sign)return (int)x.size()<(int)v.size();\r\n         else return\
    \ (int)v.size()<(int)x.size();\r\n      }\r\n      for(int i=v.size()-1;i>=0;i--)if(v[i]!=x.v[i]){\r\
    \n         if(sign)return x.v[i]<v[i];\r\n         else return v[i]<x.v[i];\r\n\
    \      }\r\n      return false;\r\n   }\r\n   bool operator>(const bigint& x)const{return\
    \ x<*this;}\r\n   bool operator<=(const bigint& x)const{return !(*this>x);}\r\n\
    \   bool operator>=(const bigint& x)const{return !(*this<x);}\r\n   bool operator==(const\
    \ bigint& x)const{return !(*this<x) and !(*this>x);}\r\n   bool operator!=(const\
    \ bigint& x)const{return !(*this==x);}\r\n};\r\ntypedef bigint<4> Bigint;\r\n\
    \ \r\nstruct Bigfloat{\r\n   Bigint v; int p=0;\r\n   Bigfloat(){}\r\n   Bigfloat(const\
    \ ll& _v){v=Bigint(_v);}\r\n   Bigfloat(const Bigint& _v,int _p=0):v(_v),p(_p){}\r\
    \n   void set(int _p){if(p<_p){v>>=(_p-p);} else{v<<=(p-_p);} p=_p;}\r\n   Bigint\
    \ to_int()const{if(p<0)return v>>(-p); else return v<<p;}\r\n   Bigfloat& operator+=(const\
    \ Bigfloat& x){\r\n      if(p>x.p)set(x.p),v+=x.v;\r\n      else v+=x.v<<(x.p-p);\r\
    \n      return *this;\r\n   }\r\n   Bigfloat& operator-=(const Bigfloat& x){\r\
    \n      if(p>x.p)set(x.p),v-=x.v;\r\n      else v-=x.v<<(x.p-p);\r\n      return\
    \ *this;\r\n   }\r\n   Bigfloat square(){Bigfloat res=*this; res.p*=2; res.v=res.v.square();\
    \ return res;}\r\n   Bigfloat mul(ll x){Bigfloat res=*this; res.v=v.mul(x); return\
    \ res;}\r\n   Bigfloat div(ll x){Bigfloat res=*this; res.v=v.div(x); return res;}\r\
    \n   Bigfloat& operator*=(const Bigfloat& x){p+=x.p; v*=x.v; return *this;}\r\n\
    \   Bigfloat& operator/=(const Bigfloat& x){p-=x.p; v/=x.v; return *this;}\r\n\
    \   Bigfloat operator+(const Bigfloat& x)const{return Bigfloat(*this)+=x;}\r\n\
    \   Bigfloat operator-(const Bigfloat& x)const{return Bigfloat(*this)-=x;}\r\n\
    \   Bigfloat operator*(const Bigfloat& x)const{return Bigfloat(*this)*=x;}\r\n\
    \   Bigfloat operator/(const Bigfloat& x)const{return Bigfloat(*this)/=x;}\r\n\
    \   string to_str(){\r\n      string res=v.abs().to_str(); int d=Bigint::get_D();\r\
    \n      if(p*d>0)res+=string(p*d,'0');\r\n      else if(-p*d>=1 and -p*d<(int)res.size()){\r\
    \n         res=res.substr(0,(int)res.size()+p*d)+'.'+res.substr((int)res.size()+p*d);\r\
    \n      }\r\n      else if(-p*d>=(int)res.size())res=\"0.\"+string(-p*d-(int)res.size(),'0')+res;\r\
    \n      if(v.sign){res.insert(res.begin(),'-');} return res;\r\n   }\r\n   friend\
    \ ostream& operator<<(ostream& os,Bigfloat x){\r\n      os<<x.to_str(); return\
    \ os;\r\n   }\r\n};\r\n \r\nBigfloat sqrt(ll n,int d){\r\n   Bigfloat res(Bigint((ll)sqrt(1LL*Bigint::get_B()*Bigint::get_B()/n)),-1),pre;\r\
    \n   int cur=1;\r\n   while(pre.v!=res.v){\r\n      cur=min(cur<<1,d);\r\n   \
    \   pre=res; Bigfloat add=Bigfloat(1)-res.square().mul(n);\r\n      add.set(-cur);\
    \ res+=(res*add).div(2); res.set(-cur);\r\n   } return res.mul(n);\r\n}\r\n\r\n\
    /**\r\n * @brief Big Integer(Float)\r\n */"
  dependsOn:
  - Convolution/fft.hpp
  isVerificationFile: false
  path: Math/bigint.hpp
  requiredBy: []
  timestamp: '2022-10-25 10:01:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/bigint.hpp
layout: document
redirect_from:
- /library/Math/bigint.hpp
- /library/Math/bigint.hpp.html
title: Big Integer(Float)
---
