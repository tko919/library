---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/fps.hpp
    title: Formal Power Series (NTT-friendly mod)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Relaxed Convolution
    links: []
  bundledCode: "#line 2 \"FPS/fps.hpp\"\n\r\ntemplate<typename T>struct Poly:vector<T>{\r\
    \n    Poly(int n=0){this->assign(n,T());}\r\n    Poly(const vector<T>& f){this->assign(ALL(f));}\r\
    \n    T eval(const T& x){\r\n        T res;\r\n        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);\r\
    \n        return res;\r\n    }\r\n    Poly rev()const{Poly res=*this; reverse(ALL(res));\
    \ return res;}\r\n    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}\r\
    \n    vector<T> mult(const vector<T>& a,const vector<T>& b,bool same=0){\r\n \
    \       if(a.empty() or b.empty())return vector<T>();\r\n        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\
    \n        vector<T> res(m);\r\n        rep(i,0,a.size())res[i]=a[i];\r\n     \
    \   NTT(res,0);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\n        else{\r\
    \n            vector<T> c(m);\r\n            rep(i,0,b.size())c[i]=b[i];\r\n \
    \           NTT(c,0);\r\n            rep(i,0,m)res[i]*=c[i];\r\n        }\r\n\
    \        NTT(res,1);\r\n        res.resize(n);\r\n        return res;\r\n    }\r\
    \n    Poly square()const{return Poly(mult(*this,*this,1));}\r\n    Poly operator+(const\
    \ Poly& g)const{return Poly(*this)+=g;}\r\n    Poly operator-(const Poly& g)const{return\
    \ Poly(*this)-=g;}\r\n    Poly operator*(const Poly& g)const{return Poly(*this)*=g;}\r\
    \n    Poly operator/(const Poly& g)const{return Poly(*this)/=g;}\r\n    Poly operator%(const\
    \ Poly& g)const{return Poly(*this)%=g;}\r\n    Poly& operator+=(const Poly& g){\r\
    \n        if(g.size()>this->size())this->resize(g.size());\r\n        rep(i,0,g.size()){(*this)[i]+=g[i];}\
    \ return *this;\r\n    }\r\n    Poly& operator-=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]-=g[i];} return *this;\r\n    }\r\n    Poly&\
    \ operator*=(const Poly& g){\r\n        *this=mult(*this,g,0);\r\n        return\
    \ *this;\r\n    }\r\n    Poly& operator/=(const Poly& g){\r\n        if(g.size()>this->size()){\r\
    \n            this->clear(); return *this;\r\n        }\r\n        Poly g2=g;\r\
    \n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\n        int n=this->size()-g2.size()+1;\r\
    \n        this->resize(n); g2.resize(n);\r\n        *this*=g2.inv(); this->resize(n);\
    \ \r\n        reverse(ALL(*this));\r\n        shrink();\r\n        return *this;\r\
    \n    }\r\n    Poly& operator%=(const Poly& g){*this-=*this/g*g; shrink(); return\
    \ *this;}\r\n    Poly diff()const{\r\n        Poly res(this->size()-1);\r\n  \
    \      rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);\r\n        return res;\r\n\
    \    }\r\n    Poly inte()const{\r\n        Poly res(this->size()+1);\r\n     \
    \   for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;\r\n        return res;\r\
    \n    }\r\n    Poly log()const{\r\n        assert(this->front()==1); const int\
    \ n=this->size();\r\n        Poly res=diff()*inv(); res=res.inte(); \r\n     \
    \   res.resize(n); return res;\r\n    }\r\n    Poly shift(const int& c)const{\r\
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
    \ b.resize(n); return b;\r\n    }\r\n    Poly pow(ll t){\r\n        int n=this->size(),k=0;\
    \ while(k<n and (*this)[k]==0)k++;\r\n        Poly res(n); if(t*k>=n)return res;\r\
    \n        n-=t*k; Poly g(n); T c=(*this)[k],ic=T(1)/c;\r\n        rep(i,0,n)g[i]=(*this)[i+k]*ic;\r\
    \n        g=g.log(); for(auto& x:g)x*=t; g=g.exp(); \r\n        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c;\
    \ return res;\r\n    }\r\n    void NTT(vector<T>& a,bool inv)const;\r\n};\r\n\r\
    \n/**\r\n * @brief Formal Power Series (NTT-friendly mod)\r\n */\n#line 3 \"FPS/relax.hpp\"\
    \n\r\ntemplate<typename T>class RelaxedConvolution{\r\n    using P=array<int,2>;\r\
    \n    using Q=array<P,2>;\r\n    int N,pos=0;\r\n    vector<vector<Q>> event;\r\
    \n    void dfs1(int L,int R){\r\n        if(R-L==1){\r\n            event[L].push_back({P{L,L+1},P{0,1}});\r\
    \n            return;\r\n        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{L,mid},P{mid-L,R-L}});\r\
    \n        event[R].push_back({P{mid,R},P{mid-L,R-L}});\r\n        dfs1(L,mid);\r\
    \n        dfs1(mid,R);\r\n    }\r\n    void dfs2(int L,int R){\r\n        if(R-L==1){\r\
    \n            event[L].push_back({P{0,1},P{L,L+1}});\r\n            return;\r\n\
    \        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{mid-L,R-L},P{L,mid}});\r\
    \n        event[R].push_back({P{mid-L,R-L},P{mid,R}});\r\n        dfs2(L,mid);\r\
    \n        dfs2(mid,R);\r\n    }\r\n    void dfs(int len){\r\n        if(len==1){\r\
    \n            event[0].push_back({P{0,1},P{0,1}});\r\n            return;\r\n\
    \        }\r\n        int mid=len>>1;\r\n        event[len].push_back({P{mid,len},P{mid,len}});\r\
    \n        dfs(mid);\r\n        dfs1(mid,len);\r\n        dfs2(mid,len);\r\n  \
    \  }\r\npublic:\r\n    Poly<T> f,g,buf;\r\n    RelaxedConvolution(int n){\r\n\
    \        N=1;\r\n        while(N<n)N<<=1;\r\n        f.resize(N);\r\n        g.resize(N);\r\
    \n        buf.resize(N);\r\n        event.resize(N+1);\r\n        dfs(N);\r\n\
    \    }\r\n    T next(){\r\n        for(auto& [ft,gt]:event[pos]){\r\n        \
    \    auto [fL,fR]=ft;\r\n            auto [gL,gR]=gt;\r\n            Poly<T> _f({f.begin()+fL,f.begin()+fR});\r\
    \n            Poly<T> _g({g.begin()+gL,g.begin()+gR});\r\n            auto add=_f*_g;\r\
    \n            rep(i,0,add.size()){\r\n                if(i+fL+gL>=N)break;\r\n\
    \                buf[i+fL+gL]+=add[i];\r\n            }\r\n        }\r\n     \
    \   return buf[pos++];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Relaxed Convolution\r\
    \n */\n"
  code: "#pragma once\r\n#include \"FPS/fps.hpp\"\r\n\r\ntemplate<typename T>class\
    \ RelaxedConvolution{\r\n    using P=array<int,2>;\r\n    using Q=array<P,2>;\r\
    \n    int N,pos=0;\r\n    vector<vector<Q>> event;\r\n    void dfs1(int L,int\
    \ R){\r\n        if(R-L==1){\r\n            event[L].push_back({P{L,L+1},P{0,1}});\r\
    \n            return;\r\n        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{L,mid},P{mid-L,R-L}});\r\
    \n        event[R].push_back({P{mid,R},P{mid-L,R-L}});\r\n        dfs1(L,mid);\r\
    \n        dfs1(mid,R);\r\n    }\r\n    void dfs2(int L,int R){\r\n        if(R-L==1){\r\
    \n            event[L].push_back({P{0,1},P{L,L+1}});\r\n            return;\r\n\
    \        }\r\n        int mid=(L+R)>>1;\r\n        event[mid].push_back({P{mid-L,R-L},P{L,mid}});\r\
    \n        event[R].push_back({P{mid-L,R-L},P{mid,R}});\r\n        dfs2(L,mid);\r\
    \n        dfs2(mid,R);\r\n    }\r\n    void dfs(int len){\r\n        if(len==1){\r\
    \n            event[0].push_back({P{0,1},P{0,1}});\r\n            return;\r\n\
    \        }\r\n        int mid=len>>1;\r\n        event[len].push_back({P{mid,len},P{mid,len}});\r\
    \n        dfs(mid);\r\n        dfs1(mid,len);\r\n        dfs2(mid,len);\r\n  \
    \  }\r\npublic:\r\n    Poly<T> f,g,buf;\r\n    RelaxedConvolution(int n){\r\n\
    \        N=1;\r\n        while(N<n)N<<=1;\r\n        f.resize(N);\r\n        g.resize(N);\r\
    \n        buf.resize(N);\r\n        event.resize(N+1);\r\n        dfs(N);\r\n\
    \    }\r\n    T next(){\r\n        for(auto& [ft,gt]:event[pos]){\r\n        \
    \    auto [fL,fR]=ft;\r\n            auto [gL,gR]=gt;\r\n            Poly<T> _f({f.begin()+fL,f.begin()+fR});\r\
    \n            Poly<T> _g({g.begin()+gL,g.begin()+gR});\r\n            auto add=_f*_g;\r\
    \n            rep(i,0,add.size()){\r\n                if(i+fL+gL>=N)break;\r\n\
    \                buf[i+fL+gL]+=add[i];\r\n            }\r\n        }\r\n     \
    \   return buf[pos++];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Relaxed Convolution\r\
    \n */"
  dependsOn:
  - FPS/fps.hpp
  isVerificationFile: false
  path: FPS/relax.hpp
  requiredBy: []
  timestamp: '2022-02-02 00:14:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_convolution_mod_2.test.cpp
documentation_of: FPS/relax.hpp
layout: document
redirect_from:
- /library/FPS/relax.hpp
- /library/FPS/relax.hpp.html
title: Relaxed Convolution
---
