---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: FPS/fps.hpp
    title: Formal Power Series (NTT-friendly mod)
  - icon: ':heavy_check_mark:'
    path: FPS/multieval.hpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation
  bundledCode: "#line 1 \"Verify/LC_multipoint_evaluation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp\
    \ {\r\n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\n\
    \        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
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
    \n */\n#line 2 \"FPS/fps.hpp\"\n\r\ntemplate<typename T>struct Poly:vector<T>{\r\
    \n    Poly(int n=0){this->assign(n,T());}\r\n    Poly(const vector<T>& f){this->assign(ALL(f));}\r\
    \n    T eval(const T& x){\r\n        T res;\r\n        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);\r\
    \n        return res;\r\n    }\r\n    Poly rev()const{Poly res=*this; reverse(ALL(res));\
    \ return res;}\r\n    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}\r\
    \n    vector<T> mult(const vector<T>& a,const vector<T>& b,bool same=0)const{\r\
    \n        if(a.empty() or b.empty())return vector<T>();\r\n        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\
    \n        vector<T> res(m);\r\n        rep(i,0,a.size())res[i]=a[i];\r\n     \
    \   NTT(res,0);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\n        else{\r\
    \n            vector<T> c(m);\r\n            rep(i,0,b.size())c[i]=b[i];\r\n \
    \           NTT(c,0);\r\n            rep(i,0,m)res[i]*=c[i];\r\n        }\r\n\
    \        NTT(res,1);\r\n        res.resize(n);\r\n        return res;\r\n    }\r\
    \n    Poly square()const{return Poly(mult(*this,*this,1));}\r\n    Poly operator+(const\
    \ Poly& g)const{return Poly(*this)+=g;}\r\n    Poly operator+(const T& g)const{return\
    \ Poly(*this)+=g;}\r\n    Poly operator-(const Poly& g)const{return Poly(*this)-=g;}\r\
    \n    Poly operator-(const T& g)const{return Poly(*this)-=g;}\r\n    Poly operator*(const\
    \ Poly& g)const{return Poly(*this)*=g;}\r\n    Poly operator*(const T& g)const{return\
    \ Poly(*this)*=g;}\r\n    Poly operator/(const Poly& g)const{return Poly(*this)/=g;}\r\
    \n    Poly operator%(const Poly& g)const{return Poly(*this)%=g;}\r\n    Poly&\
    \ operator+=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]+=g[i];} return *this;\r\n    }\r\n    Poly&\
    \ operator+=(const T& g){\r\n        if(this->empty())this->push_back(0);\r\n\
    \        (*this)[0]+=g; return *this;\r\n    }\r\n    Poly& operator-=(const Poly&\
    \ g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\n        rep(i,0,g.size()){(*this)[i]-=g[i];}\
    \ return *this;\r\n    }\r\n    Poly& operator-=(const T& g){\r\n        if(this->empty())this->push_back(0);\r\
    \n        (*this)[0]-=g; return *this;\r\n    }\r\n    Poly& operator*=(const\
    \ Poly& g){\r\n        *this=mult(*this,g,0);\r\n        return *this;\r\n   \
    \ }\r\n    Poly& operator*=(const T& g){\r\n        rep(i,0,this->size())(*this)[i]*=g;\r\
    \n        return *this;\r\n    }\r\n    Poly& operator/=(const Poly& g){\r\n \
    \       if(g.size()>this->size()){\r\n            this->clear(); return *this;\r\
    \n        }\r\n        Poly g2=g;\r\n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\
    \n        int n=this->size()-g2.size()+1;\r\n        this->resize(n); g2.resize(n);\r\
    \n        *this*=g2.inv(); this->resize(n); \r\n        reverse(ALL(*this));\r\
    \n        shrink();\r\n        return *this;\r\n    }\r\n    Poly& operator%=(const\
    \ Poly& g){*this-=*this/g*g; shrink(); return *this;}\r\n    Poly diff()const{\r\
    \n        Poly res(this->size()-1);\r\n        rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);\r\
    \n        return res;\r\n    }\r\n    Poly inte()const{\r\n        Poly res(this->size()+1);\r\
    \n        for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;\r\n        return\
    \ res;\r\n    }\r\n    Poly log()const{\r\n        assert(this->front()==1); const\
    \ int n=this->size();\r\n        Poly res=diff()*inv(); res=res.inte(); \r\n \
    \       res.resize(n); return res;\r\n    }\r\n    Poly shift(const int& c)const{\r\
    \n        const int n=this->size();\r\n        Poly res=*this,g(n); g[0]=1; rep(i,1,n)g[i]=g[i-1]*c/i;\r\
    \n        vector<T> fact(n,1);\r\n        rep(i,0,n){\r\n            if(i)fact[i]=fact[i-1]*i;\r\
    \n            res[i]*=fact[i];\r\n        }\r\n        res=res.rev();\r\n    \
    \    res*=g;\r\n        res.resize(n);\r\n        res=res.rev();\r\n        rep(i,0,n)res[i]/=fact[i];\r\
    \n        return res;\r\n    }\r\n    Poly inv()const{\r\n        const int n=this->size();\r\
    \n        Poly res(1); res.front()=T(1)/this->front();\r\n        for(int k=1;k<n;k<<=1){\r\
    \n            Poly f(k*2),g(k*2);\r\n            rep(i,0,min(n,k*2))f[i]=(*this)[i];\r\
    \n            rep(i,0,k)g[i]=res[i];\r\n            NTT(f,0);\r\n            NTT(g,0);\r\
    \n            rep(i,0,k*2)f[i]*=g[i];\r\n            NTT(f,1);\r\n           \
    \ rep(i,0,k){f[i]=0; f[i+k]=-f[i+k];}\r\n            NTT(f,0);\r\n           \
    \ rep(i,0,k*2)f[i]*=g[i];\r\n            NTT(f,1);\r\n            rep(i,0,k)f[i]=res[i];\r\
    \n            swap(res,f);\r\n        } res.resize(n); return res;\r\n    }\r\n\
    \    Poly exp()const{\r\n        const int n=this->size();\r\n        if(n==1)return\
    \ Poly({T(1)});\r\n        Poly b(2),c(1),z1,z2(2);\r\n        b[0]=c[0]=z2[0]=z2[1]=1;\
    \ b[1]=(*this)[1];\r\n        for(int k=2;k<n;k<<=1){\r\n            Poly y=b;\r\
    \n            y.resize(k*2);\r\n            NTT(y,0);\r\n            z1=z2;\r\n\
    \            Poly z(k);\r\n            rep(i,0,k)z[i]=y[i]*z1[i];\r\n        \
    \    NTT(z,1);\r\n            rep(i,0,k>>1)z[i]=0;\r\n            NTT(z,0);\r\n\
    \            rep(i,0,k)z[i]*=-z1[i];\r\n            NTT(z,1);\r\n            c.insert(c.end(),z.begin()+(k>>1),z.end());\r\
    \n            z2=c;\r\n            z2.resize(k*2);\r\n            NTT(z2,0);\r\
    \n            Poly x=*this;\r\n            x.resize(k);\r\n            x=x.diff();x.resize(k);\r\
    \n            NTT(x,0);\r\n            rep(i,0,k)x[i]*=y[i];\r\n            NTT(x,1);\r\
    \n            Poly bb=b.diff();\r\n            rep(i,0,k-1)x[i]-=bb[i];\r\n  \
    \          x.resize(k*2);\r\n            rep(i,0,k-1){x[k+i]=x[i]; x[i]=0;}\r\n\
    \            NTT(x,0);\r\n            rep(i,0,k*2)x[i]*=z2[i];\r\n           \
    \ NTT(x,1);\r\n            x.pop_back();\r\n            x=x.inte();\r\n      \
    \      rep(i,k,min(n,k*2))x[i]+=(*this)[i];\r\n            rep(i,0,k)x[i]=0;\r\
    \n            NTT(x,0);\r\n            rep(i,0,k*2)x[i]*=y[i];\r\n           \
    \ NTT(x,1);\r\n            b.insert(b.end(),x.begin()+k,x.end());\r\n        }\
    \ b.resize(n); return b;\r\n    }\r\n    Poly pow(ll t){\r\n        if(t==0){\r\
    \n            Poly res(this->size()); res[0]=1;\r\n            return res;\r\n\
    \        }\r\n        int n=this->size(),k=0; while(k<n and (*this)[k]==0)k++;\r\
    \n        Poly res(n); if(__int128_t(t)*k>=n)return res;\r\n        n-=t*k; Poly\
    \ g(n); T c=(*this)[k],ic=c.inv();\r\n        rep(i,0,n)g[i]=(*this)[i+k]*ic;\r\
    \n        g=g.log(); for(auto& x:g)x*=t; g=g.exp();\r\n        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c;\
    \ return res;\r\n    }\r\n    void NTT(vector<T>& a,bool inv)const;\r\n};\r\n\r\
    \n/**\r\n * @brief Formal Power Series (NTT-friendly mod)\r\n */\n#line 2 \"FPS/multieval.hpp\"\
    \n\r\ntemplate<typename T>struct MultiEval{\r\n    int m,n; vector<Poly<T>> t;\r\
    \n    MultiEval(vector<T>& v){\r\n        m=v.size(),n=1; while(n<m)n<<=1;\r\n\
    \        t.resize(n<<1);\r\n        rep(i,0,n){\r\n            T w=(i<m?v[i]:0);\r\
    \n            t[n+i]=Poly<T>({-w,T(1)});\r\n        }\r\n        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];\r\
    \n    }\r\n    vector<T> run(const vector<T>& f){\r\n        vector<Poly<T>> c(n*2);\r\
    \n        auto v=t[1].rev();\r\n        v.resize(f.size());\r\n        v=v.inv().rev()*Poly<T>(f);\r\
    \n        v.erase(v.begin(),v.begin()+f.size()-1);\r\n        v.resize(n); reverse(ALL(v));\
    \ c[1]=v;\r\n        rep(i,1,n){\r\n            int d=c[i].size();\r\n       \
    \     rep(k,0,2){\r\n                auto add=t[i*2+(k^1)];\r\n              \
    \  add.resize(d/2+1);\r\n                add=add.rev();\r\n                add*=c[i];\r\
    \n                add.resize(d);\r\n                c[i*2+k]=vector<T>(add.begin()+d/2,add.end());\r\
    \n            }\r\n        }\r\n        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];\r\
    \n        return res;\r\n    }\r\n    vector<T> build(vector<T>& ys){\r\n    \
    \    auto w=t[1].rev();\r\n        w.resize(m+1);\r\n        auto vs=run(w.rev().diff());\r\
    \n        rep(i,0,m)ys[i]/=vs[i];\r\n        vector<Poly<T>> c(n*2);\r\n     \
    \   rep(i,0,n){\r\n            if(i<m)c[n+i]=Poly<T>({ys[i]});\r\n           \
    \ else c[n+i]=Poly<T>({T()});\r\n        }\r\n        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];\r\
    \n        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());\r\n        c[1].resize(m);\r\
    \n       return c[1];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Multipoint Evaluation\r\
    \n */\n#line 8 \"Verify/LC_multipoint_evaluation.test.cpp\"\n\r\nusing Fp=fp<998244353>;\r\
    \nNTT<Fp,3> ntt;\r\ntemplate<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return\
    \ ntt.ntt(v,inv);}\r\n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n  \
    \  vector<Fp> a(n),b(m);\r\n    for(auto& x:a)cin>>x;\r\n    for(auto& x:b)cin>>x;\r\
    \n    MultiEval<Fp> multi(b);\r\n    auto ret=multi.run(a);\r\n    rep(i,0,m)cout<<ret[i]<<'\\\
    n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"Convolution/ntt.hpp\"\r\n#include \"FPS/fps.hpp\"\r\n#include \"FPS/multieval.hpp\"\
    \r\n\r\nusing Fp=fp<998244353>;\r\nNTT<Fp,3> ntt;\r\ntemplate<>void Poly<Fp>::NTT(vector<Fp>&\
    \ v,bool inv)const{return ntt.ntt(v,inv);}\r\n\r\nint main(){\r\n    int n,m;\r\
    \n    cin>>n>>m;\r\n    vector<Fp> a(n),b(m);\r\n    for(auto& x:a)cin>>x;\r\n\
    \    for(auto& x:b)cin>>x;\r\n    MultiEval<Fp> multi(b);\r\n    auto ret=multi.run(a);\r\
    \n    rep(i,0,m)cout<<ret[i]<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - FPS/fps.hpp
  - FPS/multieval.hpp
  isVerificationFile: true
  path: Verify/LC_multipoint_evaluation.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_multipoint_evaluation.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_multipoint_evaluation.test.cpp
- /verify/Verify/LC_multipoint_evaluation.test.cpp.html
title: Verify/LC_multipoint_evaluation.test.cpp
---