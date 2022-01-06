---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Formal Power Series (Arbitrary mod)
    links: []
  bundledCode: "#line 2 \"FPS/arbitraryfps.hpp\"\n\r\ntemplate<typename T,vector<T>\
    \ (*mult)(vector<T>&,vector<T>&,bool)>struct Poly:vector<T>{\r\n    Poly(int n=0){this->assign(n,T());}\r\
    \n    Poly(const vector<T>& f){this->assign(ALL(f));}\r\n    T eval(const T& x){\r\
    \n        T res;\r\n        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);\r\
    \n        return res;\r\n    }\r\n    Poly rev()const{Poly res=*this; reverse(ALL(res));\
    \ return res;}\r\n    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}\r\
    \n    Poly inv()const{\r\n        assert(this->front()!=0); const int n=this->size();\r\
    \n        Poly res(1); res.front()=T(1)/this->front();\r\n        for(int k=1;k<n;k<<=1){\r\
    \n            Poly g=res,h=*this; h.resize(k*2); res.resize(k*2);\r\n        \
    \    g=(g.square()*h); g.resize(k*2);\r\n            rep(i,k,min(k*2,n))res[i]-=g[i];\r\
    \n        }\r\n        res.resize(n); return res;\r\n    }\r\n    Poly square()const{return\
    \ Poly(mult(*this,*this,1));}\r\n    Poly operator+(const Poly& g)const{return\
    \ Poly(*this)+=g;}\r\n    Poly operator-(const Poly& g)const{return Poly(*this)-=g;}\r\
    \n    Poly operator*(const Poly& g)const{return Poly(*this)*=g;}\r\n    Poly operator/(const\
    \ Poly& g)const{return Poly(*this)/=g;}\r\n    Poly operator%(const Poly& g)const{return\
    \ Poly(*this)%=g;}\r\n    Poly& operator+=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]+=g[i];} shrink(); return *this;\r\n   \
    \ }\r\n    Poly& operator-=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]-=g[i];} shrink(); return *this;\r\n   \
    \ }\r\n    Poly& operator*=(const Poly& g){\r\n        *this=mult(*this,g,0);\r\
    \n        shrink(); return *this;\r\n    }\r\n    Poly& operator/=(const Poly&\
    \ g){\r\n        if(g.size()>this->size()){\r\n            this->clear(); return\
    \ *this;\r\n        }\r\n        Poly g2=g;\r\n        reverse(ALL(*this));\r\n\
    \        reverse(ALL(g2));\r\n        int n=this->size()-g2.size()+1;\r\n    \
    \    this->resize(n); g2.resize(n);\r\n        *this*=g2.inv(); this->resize(n);\
    \ \r\n        reverse(ALL(*this));\r\n        shrink(); return *this;\r\n    }\r\
    \n    Poly& operator%=(const Poly& g){*this-=*this/g*g; shrink(); return *this;}\r\
    \n    Poly diff()const{\r\n        Poly res(this->size()-1);\r\n        rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);\r\
    \n        return res;\r\n    }\r\n    Poly inte()const{\r\n        Poly res(this->size()+1);\r\
    \n        for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;\r\n        return\
    \ res;\r\n    }\r\n    Poly log()const{\r\n        assert(this->front()==1); const\
    \ int n=this->size();\r\n        Poly res=diff()*inv(); res=res.inte(); \r\n \
    \       res.resize(n); return res;\r\n    }\r\n    Poly exp()const{\r\n      \
    \  assert(this->front()==0); const int n=this->size();\r\n        Poly res(1),g(1);\
    \ res.front()=g.front()=1;\r\n        for(int k=1;k<n;k<<=1){\r\n            g=(g+g-g.square()*res);\
    \ g.resize(k);\r\n            Poly q=*this; q.resize(k); q=q.diff();\r\n     \
    \       Poly w=(q+g*(res.diff()-res*q)),t=*this;\r\n            w.resize(k*2-1);\
    \ t.resize(k*2);\r\n            res=(res+res*(t-w.inte())); res.resize(k*2);\r\
    \n        } res.resize(n); return res;\r\n    }\r\n    Poly shift(const int& c)const{\r\
    \n        const int n=this->size();\r\n        Poly res=*this,g(n); g[0]=1; rep(i,1,n)g[i]=g[i-1]*c/i;\r\
    \n        vector<T> fact(n,1);\r\n        rep(i,0,n){\r\n            if(i)fact[i]=fact[i-1]*i;\r\
    \n            res[i]*=fact[i];\r\n        }\r\n        res=res.rev();\r\n    \
    \    res*=g;\r\n        res.resize(n);\r\n        res=res.rev();\r\n        rep(i,0,n)res[i]/=fact[i];\r\
    \n        return res;\r\n    }\r\n    Poly pow(ll t){\r\n        int n=this->size(),k=0;\
    \ while(k<n and (*this)[k]==0)k++;\r\n        Poly res(n); if(t*k>=n)return res;\r\
    \n        n-=t*k; Poly g(n); T c=(*this)[k],ic=T(1)/c;\r\n        rep(i,0,n)g[i]=(*this)[i+k]*ic;\r\
    \n        g=g.log(); for(auto& x:g)x*=t; g=g.exp(); \r\n        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c;\
    \ return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series (Arbitrary\
    \ mod)\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,vector<T> (*mult)(vector<T>&,vector<T>&,bool)>struct\
    \ Poly:vector<T>{\r\n    Poly(int n=0){this->assign(n,T());}\r\n    Poly(const\
    \ vector<T>& f){this->assign(ALL(f));}\r\n    T eval(const T& x){\r\n        T\
    \ res;\r\n        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);\r\
    \n        return res;\r\n    }\r\n    Poly rev()const{Poly res=*this; reverse(ALL(res));\
    \ return res;}\r\n    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}\r\
    \n    Poly inv()const{\r\n        assert(this->front()!=0); const int n=this->size();\r\
    \n        Poly res(1); res.front()=T(1)/this->front();\r\n        for(int k=1;k<n;k<<=1){\r\
    \n            Poly g=res,h=*this; h.resize(k*2); res.resize(k*2);\r\n        \
    \    g=(g.square()*h); g.resize(k*2);\r\n            rep(i,k,min(k*2,n))res[i]-=g[i];\r\
    \n        }\r\n        res.resize(n); return res;\r\n    }\r\n    Poly square()const{return\
    \ Poly(mult(*this,*this,1));}\r\n    Poly operator+(const Poly& g)const{return\
    \ Poly(*this)+=g;}\r\n    Poly operator-(const Poly& g)const{return Poly(*this)-=g;}\r\
    \n    Poly operator*(const Poly& g)const{return Poly(*this)*=g;}\r\n    Poly operator/(const\
    \ Poly& g)const{return Poly(*this)/=g;}\r\n    Poly operator%(const Poly& g)const{return\
    \ Poly(*this)%=g;}\r\n    Poly& operator+=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]+=g[i];} shrink(); return *this;\r\n   \
    \ }\r\n    Poly& operator-=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]-=g[i];} shrink(); return *this;\r\n   \
    \ }\r\n    Poly& operator*=(const Poly& g){\r\n        *this=mult(*this,g,0);\r\
    \n        shrink(); return *this;\r\n    }\r\n    Poly& operator/=(const Poly&\
    \ g){\r\n        if(g.size()>this->size()){\r\n            this->clear(); return\
    \ *this;\r\n        }\r\n        Poly g2=g;\r\n        reverse(ALL(*this));\r\n\
    \        reverse(ALL(g2));\r\n        int n=this->size()-g2.size()+1;\r\n    \
    \    this->resize(n); g2.resize(n);\r\n        *this*=g2.inv(); this->resize(n);\
    \ \r\n        reverse(ALL(*this));\r\n        shrink(); return *this;\r\n    }\r\
    \n    Poly& operator%=(const Poly& g){*this-=*this/g*g; shrink(); return *this;}\r\
    \n    Poly diff()const{\r\n        Poly res(this->size()-1);\r\n        rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);\r\
    \n        return res;\r\n    }\r\n    Poly inte()const{\r\n        Poly res(this->size()+1);\r\
    \n        for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;\r\n        return\
    \ res;\r\n    }\r\n    Poly log()const{\r\n        assert(this->front()==1); const\
    \ int n=this->size();\r\n        Poly res=diff()*inv(); res=res.inte(); \r\n \
    \       res.resize(n); return res;\r\n    }\r\n    Poly exp()const{\r\n      \
    \  assert(this->front()==0); const int n=this->size();\r\n        Poly res(1),g(1);\
    \ res.front()=g.front()=1;\r\n        for(int k=1;k<n;k<<=1){\r\n            g=(g+g-g.square()*res);\
    \ g.resize(k);\r\n            Poly q=*this; q.resize(k); q=q.diff();\r\n     \
    \       Poly w=(q+g*(res.diff()-res*q)),t=*this;\r\n            w.resize(k*2-1);\
    \ t.resize(k*2);\r\n            res=(res+res*(t-w.inte())); res.resize(k*2);\r\
    \n        } res.resize(n); return res;\r\n    }\r\n    Poly shift(const int& c)const{\r\
    \n        const int n=this->size();\r\n        Poly res=*this,g(n); g[0]=1; rep(i,1,n)g[i]=g[i-1]*c/i;\r\
    \n        vector<T> fact(n,1);\r\n        rep(i,0,n){\r\n            if(i)fact[i]=fact[i-1]*i;\r\
    \n            res[i]*=fact[i];\r\n        }\r\n        res=res.rev();\r\n    \
    \    res*=g;\r\n        res.resize(n);\r\n        res=res.rev();\r\n        rep(i,0,n)res[i]/=fact[i];\r\
    \n        return res;\r\n    }\r\n    Poly pow(ll t){\r\n        int n=this->size(),k=0;\
    \ while(k<n and (*this)[k]==0)k++;\r\n        Poly res(n); if(t*k>=n)return res;\r\
    \n        n-=t*k; Poly g(n); T c=(*this)[k],ic=T(1)/c;\r\n        rep(i,0,n)g[i]=(*this)[i+k]*ic;\r\
    \n        g=g.log(); for(auto& x:g)x*=t; g=g.exp(); \r\n        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c;\
    \ return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series (Arbitrary\
    \ mod)\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/arbitraryfps.hpp
  requiredBy: []
  timestamp: '2022-01-06 10:09:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/arbitraryfps.hpp
layout: document
redirect_from:
- /library/FPS/arbitraryfps.hpp
- /library/FPS/arbitraryfps.hpp.html
title: Formal Power Series (Arbitrary mod)
---