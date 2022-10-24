---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Big Integer(Float)
    links: []
  bundledCode: "#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct\
    \ fp {\r\n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\
    \n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(ll x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
    \ return res;}\r\n    fp& operator+=(const fp& x){return init(v+x.v);}\r\n   \
    \ fp& operator-=(const fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const\
    \ fp& x){v=ll(v)*x.v%mod; return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod;\
    \ return *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\
    \n    fp operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\ntemplate<typename T>struct factorial\
    \ {\r\n    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Modint\r\n */\n#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate<typename\
    \ T,unsigned p=3>struct NTT{\r\n    vector<T> rt,irt;\r\n    NTT(int lg=21){\r\
    \n        unsigned m=T::get_mod()-1; T prt=p;\r\n        rt.resize(lg); irt.resize(lg);\r\
    \n        rep(k,0,lg){\r\n            rt[k]=-prt.pow(m>>(k+2));\r\n          \
    \  irt[k]=rt[k].inv();\r\n        }\r\n    }\r\n    void ntt(vector<T>& f,bool\
    \ inv=0){\r\n        int n=f.size();\r\n        if(inv){\r\n            for(int\
    \ m=1;m<n;m<<=1){ T w=1;\r\n                for(int s=0,t=0;s<n;s+=m*2){\r\n \
    \                   for(int i=s,j=s+m;i<s+m;i++,j++){\r\n                    \
    \    auto x=f[i],y=f[j];\r\n                        f[i]=x+y; f[j]=(x-y)*w;\r\n\
    \                    } w*=irt[__builtin_ctz(++t)];\r\n                }\r\n  \
    \           } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;\r\n        }else{\r\n   \
    \         for(int m=n;m>>=1;){ T w=1;\r\n                for(int s=0,t=0;s<n;s+=m*2){\r\
    \n                    for(int i=s,j=s+m;i<s+m;i++,j++){\r\n                  \
    \      auto x=f[i],y=f[j]*w;\r\n                        f[i]=x+y; f[j]=x-y;\r\n\
    \                    } w*=rt[__builtin_ctz(++t)];\r\n                }\r\n   \
    \         }\r\n         }\r\n    }\r\n    vector<T> mult(const vector<T>& a,const\
    \ vector<T>& b,bool same=0){\r\n        if(a.empty() or b.empty())return vector<T>();\r\
    \n        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\n        vector<T> res(m);\
    \ rep(i,0,a.size()){res[i]=a[i];} ntt(res);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\
    \n        else{\r\n            vector<T> c(m); rep(i,0,b.size())c[i]=b[i];\r\n\
    \            ntt(c); rep(i,0,m)res[i]*=c[i];\r\n        } ntt(res,1); res.resize(n);\
    \ return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */\n#line 4 \"Math/bigint.hpp\"\n\r\nusing F1=fp<167772161>; using F2=fp<469762049>;\r\
    \nNTT<F1,3> ntt1(25); NTT<F2,3> ntt2(25);\r\nconst F1 coeff=F1(F2::get_mod()).inv();\r\
    \ntemplate<int D>struct bigint{\r\n    static const int B=pow(10,D);\r\n    int\
    \ sign=0; vector<ll> v;\r\n    static int get_D(){return D;}\r\n    static int\
    \ get_B(){return B;}\r\n    bigint(ll x=0){\r\n        if(x<0)x*=-1,sign=1;\r\n\
    \        while(x){v.push_back(x%B); x/=B;}\r\n    }\r\n    bigint(string s){\r\
    \n        if(s[0]=='-')s.erase(s.begin()),sign=1;\r\n        int add=0,cnt=0,base=1;\r\
    \n        while(s.size()){\r\n            if(cnt==D){\r\n                v.push_back(add);\r\
    \n                cnt=0; add=0; base=1;\r\n            }\r\n            add=(s.back()-'0')*base+add;\r\
    \n            cnt++; base*=10; s.pop_back();\r\n        } if(add)v.push_back(add);\r\
    \n    }\r\n    bigint operator-()const{bigint res=*this; res.sign^=1;return res;}\r\
    \n    bigint abs()const{bigint res=*this; res.sign=0; return res;}\r\n    ll&\
    \ operator[](const int i){return v[i];}\r\n    int size()const{return v.size();}\r\
    \n    void norm(){\r\n        rep(i,0,v.size()-1){\r\n            if(v[i]>=0){v[i+1]+=v[i]/B;\
    \ v[i]%=B;}\r\n            else{int c=(-v[i]+B-1)/B; v[i]+=c*B; v[i+1]-=c;}\r\n\
    \        }\r\n        while(!v.empty() and v.back()>=B){\r\n            int c=v.back()/B;\r\
    \n            v.back()%=B; v.push_back(c);\r\n        }\r\n        while(!v.empty()\
    \ and v.back()==0)v.pop_back();\r\n    }\r\n    string to_str()const{\r\n    \
    \    string res;\r\n        if(v.empty())return \"0\";\r\n        if(sign)res+='-';\r\
    \n        res+=to_string(v.back());\r\n        for(int i=v.size()-2;i>=0;i--){\r\
    \n            string add; int w=v[i];\r\n            rep(_,0,D){\r\n         \
    \       add+=('0'+(w%10)); w/=10;\r\n            } reverse(ALL(add)); res+=add;\r\
    \n        } return res;\r\n    }\r\n    friend istream& operator>>(istream& is,bigint<D>&\
    \ x){\r\n        string tmp; is>>tmp; x=bigint(tmp); return is;\r\n    }\r\n \
    \   friend ostream& operator<<(ostream& os,bigint<D> x){\r\n        os<<x.to_str();\
    \ return os;\r\n    }\r\n    bigint& operator<<=(const int& x){\r\n        if(!v.empty()){\r\
    \n            vector<ll> add(x,0);\r\n            v.insert(v.begin(),ALL(add));\r\
    \n        } return *this;\r\n    }\r\n    bigint& operator>>=(const int& x){\r\
    \n        v=vector<ll>(v.begin()+min(x,(int)v.size()),v.end());\r\n        return\
    \ *this;\r\n    }\r\n    bigint& operator+=(const bigint& x){\r\n        if(sign!=x.sign){*this-=(-x);\
    \ return *this;}\r\n        if((int)v.size()<(int)x.size())v.resize(x.size(),0);\r\
    \n        rep(i,0,x.size()){v[i]+=x.v[i];} norm(); return *this;\r\n    }\r\n\
    \    bigint& operator-=(const bigint& x){\r\n        if(sign!=x.sign){*this+=(-x);\
    \ return *this;}\r\n        if(abs()<x.abs()){*this=x-(*this); sign^=1; return\
    \ *this;}\r\n        rep(i,0,x.size()){v[i]-=x.v[i];} norm(); return *this;\r\n\
    \    }\r\n    bigint& operator*=(const bigint& x){\r\n        sign^=x.sign;\r\n\
    \        auto v1=ntt1.conv<ll>(v,x.v);\r\n        auto v2=ntt2.conv<ll>(v,x.v);\r\
    \n        v.assign(v1.size(),0);\r\n        rep(i,0,v1.size()){\r\n          \
    \  ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;\r\n     \
    \       for(int j=i;val;j++){\r\n                if(j==(int)v.size())v.push_back(0);\r\
    \n                v[j]+=val%B; val/=B;\r\n            }\r\n        } norm(); return\
    \ *this;\r\n    }\r\n    bigint& operator/=(const bigint& x){  \r\n        bigint\
    \ a=abs(),b=x.abs(); sign^=x.sign;\r\n        if(a<b)return *this=bigint();\r\n\
    \        int d=a.size()-b.size()+1;\r\n        bigint inv(1LL*B*B/b.v.back()),pre;\r\
    \n        int cur=2,bcur=1; pre=bigint(0);\r\n        while(inv!=pre or bcur<b.size()){\r\
    \n            bcur=min(bcur<<1,b.size());\r\n            bigint c; c.v=vector<ll>(b.v.end()-bcur,b.v.end());\r\
    \n            pre=inv; inv*=((bigint(2)<<(cur+bcur-1))-inv*c);\r\n           \
    \ cur=min(cur<<1,d);\r\n            inv.v=vector<ll>(inv.v.end()-cur,inv.v.end());\r\
    \n        }\r\n        inv.v=vector<ll>(inv.v.end()-d,inv.v.end());\r\n      \
    \  bigint res=a*inv; res>>=(a.size());\r\n        bigint mul=res*b; while(mul+b<=a){res+=bigint(1);\
    \ mul+=b;}\r\n        v=res.v; return *this;\r\n    }\r\n    bigint& operator%=(const\
    \ bigint& x){\r\n        bigint div=(*this)/x; (*this)-=div*x; return *this;\r\
    \n    }\r\n    bigint square(){\r\n        bigint res=*this; res.sign=0;\r\n \
    \       auto v1=ntt1.conv<ll>(v,v,1);\r\n        auto v2=ntt2.conv<ll>(v,v,1);\r\
    \n        res.v.assign(v1.size(),0);\r\n        rep(i,0,v1.size()){\r\n      \
    \      ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;\r\n \
    \           for(int j=i;val;j++){\r\n                if(j==(int)res.v.size())res.v.push_back(0);\r\
    \n                res.v[j]+=val%B; val/=B;\r\n            }\r\n        } res.norm();\
    \ return res;\r\n    }\r\n    bigint mul(ll x){\r\n        bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n        for(int i=res.v.size()-1;i>=0;i--)res.v[i]*=x;\r\n        res.norm();\
    \ return res;\r\n    }\r\n    bigint div(ll x){\r\n        bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n        for(int i=res.v.size()-1;i>=0;i--){\r\n            if(res.v[i]%x!=0\
    \ and i!=0){res.v[i-1]+=B*(res.v[i]%x);} res.v[i]/=x;\r\n        } res.norm();\
    \ return res;\r\n    }\r\n    bigint operator<<(const int& x)const{return bigint(*this)<<=x;}\r\
    \n    bigint operator>>(const int& x)const{return bigint(*this)>>=x;}\r\n    bigint\
    \ operator+(const bigint& x)const{return bigint(*this)+=x;}\r\n    bigint operator-(const\
    \ bigint& x)const{return bigint(*this)-=x;}\r\n    bigint operator*(const bigint&\
    \ x)const{return bigint(*this)*=x;}\r\n    bigint operator/(const bigint& x)const{return\
    \ bigint(*this)/=x;}\r\n    bigint operator%(const bigint& x)const{return bigint(*this)%=x;}\r\
    \n    bool operator<(const bigint& x)const{\r\n        if(sign!=x.sign)return\
    \ sign>x.sign;\r\n        if((int)v.size()!=(int)x.size()){\r\n            if(sign)return\
    \ (int)x.size()<(int)v.size();\r\n            else return (int)v.size()<(int)x.size();\r\
    \n        }\r\n        for(int i=v.size()-1;i>=0;i--)if(v[i]!=x.v[i]){\r\n   \
    \         if(sign)return x.v[i]<v[i];\r\n            else return v[i]<x.v[i];\r\
    \n        }\r\n        return false;\r\n    }\r\n    bool operator>(const bigint&\
    \ x)const{return x<*this;}\r\n    bool operator<=(const bigint& x)const{return\
    \ !(*this>x);}\r\n    bool operator>=(const bigint& x)const{return !(*this<x);}\r\
    \n    bool operator==(const bigint& x)const{return !(*this<x) and !(*this>x);}\r\
    \n    bool operator!=(const bigint& x)const{return !(*this==x);}\r\n};\r\ntypedef\
    \ bigint<5> Bigint;\r\n \r\nstruct Bigfloat{\r\n    Bigint v; int p=0;\r\n   \
    \ Bigfloat(){}\r\n    Bigfloat(const ll& _v){v=Bigint(_v);}\r\n    Bigfloat(const\
    \ Bigint& _v,int _p=0):v(_v),p(_p){}\r\n    void set(int _p){if(p<_p){v>>=(_p-p);}\
    \ else{v<<=(p-_p);} p=_p;}\r\n    Bigint to_int()const{if(p<0)return v>>(-p);\
    \ else return v<<p;}\r\n    Bigfloat& operator+=(const Bigfloat& x){\r\n     \
    \   if(p>x.p)set(x.p),v+=x.v;\r\n        else v+=x.v<<(x.p-p);\r\n        return\
    \ *this;\r\n    }\r\n    Bigfloat& operator-=(const Bigfloat& x){\r\n        if(p>x.p)set(x.p),v-=x.v;\r\
    \n        else v-=x.v<<(x.p-p);\r\n        return *this;\r\n    }\r\n    Bigfloat\
    \ square(){Bigfloat res=*this; res.p*=2; res.v=res.v.square(); return res;}\r\n\
    \    Bigfloat mul(ll x){Bigfloat res=*this; res.v=v.mul(x); return res;}\r\n \
    \   Bigfloat div(ll x){Bigfloat res=*this; res.v=v.div(x); return res;}\r\n  \
    \  Bigfloat& operator*=(const Bigfloat& x){p+=x.p; v*=x.v; return *this;}\r\n\
    \    Bigfloat& operator/=(const Bigfloat& x){p-=x.p; v/=x.v; return *this;}\r\n\
    \    Bigfloat operator+(const Bigfloat& x)const{return Bigfloat(*this)+=x;}\r\n\
    \    Bigfloat operator-(const Bigfloat& x)const{return Bigfloat(*this)-=x;}\r\n\
    \    Bigfloat operator*(const Bigfloat& x)const{return Bigfloat(*this)*=x;}\r\n\
    \    Bigfloat operator/(const Bigfloat& x)const{return Bigfloat(*this)/=x;}\r\n\
    \    string to_str(){\r\n        string res=v.abs().to_str(); int d=Bigint::get_D();\r\
    \n        if(p*d>0)res+=string(p*d,'0');\r\n        else if(-p*d>=1 and -p*d<(int)res.size()){\r\
    \n            res=res.substr(0,(int)res.size()+p*d)+'.'+res.substr((int)res.size()+p*d);\r\
    \n        }\r\n        else if(-p*d>=(int)res.size())res=\"0.\"+string(-p*d-(int)res.size(),'0')+res;\r\
    \n        if(v.sign){res.insert(res.begin(),'-');} return res;\r\n    }\r\n  \
    \  friend ostream& operator<<(ostream& os,Bigfloat x){\r\n        os<<x.to_str();\
    \ return os;\r\n    }\r\n};\r\n \r\nBigfloat sqrt(ll n,int d){\r\n    Bigfloat\
    \ res(Bigint((ll)sqrt(1LL*Bigint::get_B()*Bigint::get_B()/n)),-1),pre;\r\n   \
    \ int cur=1;\r\n    while(pre.v!=res.v){\r\n        cur=min(cur<<1,d);\r\n   \
    \     pre=res; Bigfloat add=Bigfloat(1)-res.square().mul(n);\r\n        add.set(-cur*1.01);\
    \ res+=(res*add).div(2); res.set(-cur);\r\n    } return res.mul(n);\r\n}\r\n\r\
    \n/**\r\n * @brief Big Integer(Float)\r\n */\n"
  code: "#pragma once\r\n#include \"Math/modint.hpp\"\r\n#include \"Convolution/ntt.hpp\"\
    \r\n\r\nusing F1=fp<167772161>; using F2=fp<469762049>;\r\nNTT<F1,3> ntt1(25);\
    \ NTT<F2,3> ntt2(25);\r\nconst F1 coeff=F1(F2::get_mod()).inv();\r\ntemplate<int\
    \ D>struct bigint{\r\n    static const int B=pow(10,D);\r\n    int sign=0; vector<ll>\
    \ v;\r\n    static int get_D(){return D;}\r\n    static int get_B(){return B;}\r\
    \n    bigint(ll x=0){\r\n        if(x<0)x*=-1,sign=1;\r\n        while(x){v.push_back(x%B);\
    \ x/=B;}\r\n    }\r\n    bigint(string s){\r\n        if(s[0]=='-')s.erase(s.begin()),sign=1;\r\
    \n        int add=0,cnt=0,base=1;\r\n        while(s.size()){\r\n            if(cnt==D){\r\
    \n                v.push_back(add);\r\n                cnt=0; add=0; base=1;\r\
    \n            }\r\n            add=(s.back()-'0')*base+add;\r\n            cnt++;\
    \ base*=10; s.pop_back();\r\n        } if(add)v.push_back(add);\r\n    }\r\n \
    \   bigint operator-()const{bigint res=*this; res.sign^=1;return res;}\r\n   \
    \ bigint abs()const{bigint res=*this; res.sign=0; return res;}\r\n    ll& operator[](const\
    \ int i){return v[i];}\r\n    int size()const{return v.size();}\r\n    void norm(){\r\
    \n        rep(i,0,v.size()-1){\r\n            if(v[i]>=0){v[i+1]+=v[i]/B; v[i]%=B;}\r\
    \n            else{int c=(-v[i]+B-1)/B; v[i]+=c*B; v[i+1]-=c;}\r\n        }\r\n\
    \        while(!v.empty() and v.back()>=B){\r\n            int c=v.back()/B;\r\
    \n            v.back()%=B; v.push_back(c);\r\n        }\r\n        while(!v.empty()\
    \ and v.back()==0)v.pop_back();\r\n    }\r\n    string to_str()const{\r\n    \
    \    string res;\r\n        if(v.empty())return \"0\";\r\n        if(sign)res+='-';\r\
    \n        res+=to_string(v.back());\r\n        for(int i=v.size()-2;i>=0;i--){\r\
    \n            string add; int w=v[i];\r\n            rep(_,0,D){\r\n         \
    \       add+=('0'+(w%10)); w/=10;\r\n            } reverse(ALL(add)); res+=add;\r\
    \n        } return res;\r\n    }\r\n    friend istream& operator>>(istream& is,bigint<D>&\
    \ x){\r\n        string tmp; is>>tmp; x=bigint(tmp); return is;\r\n    }\r\n \
    \   friend ostream& operator<<(ostream& os,bigint<D> x){\r\n        os<<x.to_str();\
    \ return os;\r\n    }\r\n    bigint& operator<<=(const int& x){\r\n        if(!v.empty()){\r\
    \n            vector<ll> add(x,0);\r\n            v.insert(v.begin(),ALL(add));\r\
    \n        } return *this;\r\n    }\r\n    bigint& operator>>=(const int& x){\r\
    \n        v=vector<ll>(v.begin()+min(x,(int)v.size()),v.end());\r\n        return\
    \ *this;\r\n    }\r\n    bigint& operator+=(const bigint& x){\r\n        if(sign!=x.sign){*this-=(-x);\
    \ return *this;}\r\n        if((int)v.size()<(int)x.size())v.resize(x.size(),0);\r\
    \n        rep(i,0,x.size()){v[i]+=x.v[i];} norm(); return *this;\r\n    }\r\n\
    \    bigint& operator-=(const bigint& x){\r\n        if(sign!=x.sign){*this+=(-x);\
    \ return *this;}\r\n        if(abs()<x.abs()){*this=x-(*this); sign^=1; return\
    \ *this;}\r\n        rep(i,0,x.size()){v[i]-=x.v[i];} norm(); return *this;\r\n\
    \    }\r\n    bigint& operator*=(const bigint& x){\r\n        sign^=x.sign;\r\n\
    \        auto v1=ntt1.conv<ll>(v,x.v);\r\n        auto v2=ntt2.conv<ll>(v,x.v);\r\
    \n        v.assign(v1.size(),0);\r\n        rep(i,0,v1.size()){\r\n          \
    \  ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;\r\n     \
    \       for(int j=i;val;j++){\r\n                if(j==(int)v.size())v.push_back(0);\r\
    \n                v[j]+=val%B; val/=B;\r\n            }\r\n        } norm(); return\
    \ *this;\r\n    }\r\n    bigint& operator/=(const bigint& x){  \r\n        bigint\
    \ a=abs(),b=x.abs(); sign^=x.sign;\r\n        if(a<b)return *this=bigint();\r\n\
    \        int d=a.size()-b.size()+1;\r\n        bigint inv(1LL*B*B/b.v.back()),pre;\r\
    \n        int cur=2,bcur=1; pre=bigint(0);\r\n        while(inv!=pre or bcur<b.size()){\r\
    \n            bcur=min(bcur<<1,b.size());\r\n            bigint c; c.v=vector<ll>(b.v.end()-bcur,b.v.end());\r\
    \n            pre=inv; inv*=((bigint(2)<<(cur+bcur-1))-inv*c);\r\n           \
    \ cur=min(cur<<1,d);\r\n            inv.v=vector<ll>(inv.v.end()-cur,inv.v.end());\r\
    \n        }\r\n        inv.v=vector<ll>(inv.v.end()-d,inv.v.end());\r\n      \
    \  bigint res=a*inv; res>>=(a.size());\r\n        bigint mul=res*b; while(mul+b<=a){res+=bigint(1);\
    \ mul+=b;}\r\n        v=res.v; return *this;\r\n    }\r\n    bigint& operator%=(const\
    \ bigint& x){\r\n        bigint div=(*this)/x; (*this)-=div*x; return *this;\r\
    \n    }\r\n    bigint square(){\r\n        bigint res=*this; res.sign=0;\r\n \
    \       auto v1=ntt1.conv<ll>(v,v,1);\r\n        auto v2=ntt2.conv<ll>(v,v,1);\r\
    \n        res.v.assign(v1.size(),0);\r\n        rep(i,0,v1.size()){\r\n      \
    \      ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;\r\n \
    \           for(int j=i;val;j++){\r\n                if(j==(int)res.v.size())res.v.push_back(0);\r\
    \n                res.v[j]+=val%B; val/=B;\r\n            }\r\n        } res.norm();\
    \ return res;\r\n    }\r\n    bigint mul(ll x){\r\n        bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n        for(int i=res.v.size()-1;i>=0;i--)res.v[i]*=x;\r\n        res.norm();\
    \ return res;\r\n    }\r\n    bigint div(ll x){\r\n        bigint res=*this; if(x<0)res.sign^=1,x*=-1;\r\
    \n        for(int i=res.v.size()-1;i>=0;i--){\r\n            if(res.v[i]%x!=0\
    \ and i!=0){res.v[i-1]+=B*(res.v[i]%x);} res.v[i]/=x;\r\n        } res.norm();\
    \ return res;\r\n    }\r\n    bigint operator<<(const int& x)const{return bigint(*this)<<=x;}\r\
    \n    bigint operator>>(const int& x)const{return bigint(*this)>>=x;}\r\n    bigint\
    \ operator+(const bigint& x)const{return bigint(*this)+=x;}\r\n    bigint operator-(const\
    \ bigint& x)const{return bigint(*this)-=x;}\r\n    bigint operator*(const bigint&\
    \ x)const{return bigint(*this)*=x;}\r\n    bigint operator/(const bigint& x)const{return\
    \ bigint(*this)/=x;}\r\n    bigint operator%(const bigint& x)const{return bigint(*this)%=x;}\r\
    \n    bool operator<(const bigint& x)const{\r\n        if(sign!=x.sign)return\
    \ sign>x.sign;\r\n        if((int)v.size()!=(int)x.size()){\r\n            if(sign)return\
    \ (int)x.size()<(int)v.size();\r\n            else return (int)v.size()<(int)x.size();\r\
    \n        }\r\n        for(int i=v.size()-1;i>=0;i--)if(v[i]!=x.v[i]){\r\n   \
    \         if(sign)return x.v[i]<v[i];\r\n            else return v[i]<x.v[i];\r\
    \n        }\r\n        return false;\r\n    }\r\n    bool operator>(const bigint&\
    \ x)const{return x<*this;}\r\n    bool operator<=(const bigint& x)const{return\
    \ !(*this>x);}\r\n    bool operator>=(const bigint& x)const{return !(*this<x);}\r\
    \n    bool operator==(const bigint& x)const{return !(*this<x) and !(*this>x);}\r\
    \n    bool operator!=(const bigint& x)const{return !(*this==x);}\r\n};\r\ntypedef\
    \ bigint<5> Bigint;\r\n \r\nstruct Bigfloat{\r\n    Bigint v; int p=0;\r\n   \
    \ Bigfloat(){}\r\n    Bigfloat(const ll& _v){v=Bigint(_v);}\r\n    Bigfloat(const\
    \ Bigint& _v,int _p=0):v(_v),p(_p){}\r\n    void set(int _p){if(p<_p){v>>=(_p-p);}\
    \ else{v<<=(p-_p);} p=_p;}\r\n    Bigint to_int()const{if(p<0)return v>>(-p);\
    \ else return v<<p;}\r\n    Bigfloat& operator+=(const Bigfloat& x){\r\n     \
    \   if(p>x.p)set(x.p),v+=x.v;\r\n        else v+=x.v<<(x.p-p);\r\n        return\
    \ *this;\r\n    }\r\n    Bigfloat& operator-=(const Bigfloat& x){\r\n        if(p>x.p)set(x.p),v-=x.v;\r\
    \n        else v-=x.v<<(x.p-p);\r\n        return *this;\r\n    }\r\n    Bigfloat\
    \ square(){Bigfloat res=*this; res.p*=2; res.v=res.v.square(); return res;}\r\n\
    \    Bigfloat mul(ll x){Bigfloat res=*this; res.v=v.mul(x); return res;}\r\n \
    \   Bigfloat div(ll x){Bigfloat res=*this; res.v=v.div(x); return res;}\r\n  \
    \  Bigfloat& operator*=(const Bigfloat& x){p+=x.p; v*=x.v; return *this;}\r\n\
    \    Bigfloat& operator/=(const Bigfloat& x){p-=x.p; v/=x.v; return *this;}\r\n\
    \    Bigfloat operator+(const Bigfloat& x)const{return Bigfloat(*this)+=x;}\r\n\
    \    Bigfloat operator-(const Bigfloat& x)const{return Bigfloat(*this)-=x;}\r\n\
    \    Bigfloat operator*(const Bigfloat& x)const{return Bigfloat(*this)*=x;}\r\n\
    \    Bigfloat operator/(const Bigfloat& x)const{return Bigfloat(*this)/=x;}\r\n\
    \    string to_str(){\r\n        string res=v.abs().to_str(); int d=Bigint::get_D();\r\
    \n        if(p*d>0)res+=string(p*d,'0');\r\n        else if(-p*d>=1 and -p*d<(int)res.size()){\r\
    \n            res=res.substr(0,(int)res.size()+p*d)+'.'+res.substr((int)res.size()+p*d);\r\
    \n        }\r\n        else if(-p*d>=(int)res.size())res=\"0.\"+string(-p*d-(int)res.size(),'0')+res;\r\
    \n        if(v.sign){res.insert(res.begin(),'-');} return res;\r\n    }\r\n  \
    \  friend ostream& operator<<(ostream& os,Bigfloat x){\r\n        os<<x.to_str();\
    \ return os;\r\n    }\r\n};\r\n \r\nBigfloat sqrt(ll n,int d){\r\n    Bigfloat\
    \ res(Bigint((ll)sqrt(1LL*Bigint::get_B()*Bigint::get_B()/n)),-1),pre;\r\n   \
    \ int cur=1;\r\n    while(pre.v!=res.v){\r\n        cur=min(cur<<1,d);\r\n   \
    \     pre=res; Bigfloat add=Bigfloat(1)-res.square().mul(n);\r\n        add.set(-cur*1.01);\
    \ res+=(res*add).div(2); res.set(-cur);\r\n    } return res.mul(n);\r\n}\r\n\r\
    \n/**\r\n * @brief Big Integer(Float)\r\n */"
  dependsOn:
  - Math/modint.hpp
  - Convolution/ntt.hpp
  isVerificationFile: false
  path: Math/bigint.hpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/bigint.hpp
layout: document
redirect_from:
- /library/Math/bigint.hpp
- /library/Math/bigint.hpp.html
title: Big Integer(Float)
---
