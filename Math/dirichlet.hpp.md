---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_sum_of_totient_function.test.cpp
    title: Verify/LC_sum_of_totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Dirichlet series
    links: []
  bundledCode: "#line 2 \"Math/dirichlet.hpp\"\n\r\ntemplate<typename T,bool multi,unsigned\
    \ L=1010101010>struct Dirichlet{\r\n    ll N,P,Q;\r\n    vector<T> a,rui,A;\r\n\
    \    vector<ll> ps;\r\n    bool done=0;\r\n    Dirichlet(ll n):N(n),P(min<ll>(L,cbrt(n)*cbrt(n))),Q((n+P-1)/P),\r\
    \n        a(P+1),rui(P+1),A(Q+1),done(0){}\r\n    const Dirichlet ident(){\r\n\
    \        Dirichlet res(N);\r\n        res.a.assign(P+1,0);\r\n        res.a[1]=1;\r\
    \n        res.rui.assign(P+1,1);\r\n        res.A.assign(Q+1,1);\r\n        res.done=1;\r\
    \n        return res;\r\n    }\r\n    void sieve(){\r\n        if(!ps.empty())return;\r\
    \n        static bitset<L> isp;\r\n        rep(p,2,P+1)isp[p]=1;\r\n        for(ll\
    \ p=2;p*p<=P;p++)if(isp[p]){\r\n            for(ll q=p*p;q<=P;q+=p)isp[q]=0;\r\
    \n        }\r\n        rep(p,2,P+1)if(isp[p])ps.push_back(p);\r\n    }\r\n   \
    \ void reset(){\r\n        a.assign(P+1,0);\r\n        rui.assign(P+1,0);\r\n\
    \        A.assign(Q+1,0);\r\n        done=0;\r\n    }\r\n    void ruith(){\r\n\
    \        rui.assign(P+1,0);\r\n        rep(i,1,P+1)rui[i]=rui[i-1]+a[i];\r\n \
    \       done=1;\r\n    }\r\n    Dirichlet operator*(const Dirichlet& x){\r\n \
    \       assert(done and x.done);\r\n        Dirichlet res(N);\r\n        if(multi){\r\
    \n            sieve();\r\n            res.a=a;\r\n            for(auto& p:ps){\r\
    \n                for(ll i=P/p;i>0;i--){\r\n                    ll n=p*i,q=p,m=i;\r\
    \n                    for(;;){\r\n                        res.a[n]+=x.a[q]*res.a[m];\r\
    \n                        if(m%p)break;\r\n                        q*=p,m/=p;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        else{\r\n            rep(i,1,P+1)rep(j,1,P/i+1){\r\n                res.a[i*j]+=a[i]*x.a[j];\r\
    \n            }\r\n        }\r\n        res.ruith();\r\n        rep(i,1,Q+1){\r\
    \n            ll n=N/i,M=int(sqrt(n));\r\n            rep(j,1,M+1){\r\n      \
    \          if(n/j<=P)res.A[i]+=a[j]*x.rui[n/j]+x.a[j]*rui[n/j];\r\n          \
    \      else res.A[i]+=a[j]*x.A[i*j]+x.a[j]*A[i*j];\r\n                if(M<=P)res.A[i]-=x.a[j]*rui[M];\r\
    \n                else res.A[i]-=x.a[j]*A[N/M];\r\n            }\r\n        }\r\
    \n        return res;\r\n    }\r\n    Dirichlet operator/(const Dirichlet& x){\r\
    \n        assert(done and x.done);\r\n        Dirichlet res=*this;\r\n       \
    \ if(multi){\r\n            sieve();\r\n            for(auto& p:ps){\r\n     \
    \           rep(i,1,P/p+1){\r\n                    int n=p*i,q=p,m=i;\r\n    \
    \                for(;;){\r\n                        res.a[n]-=x.a[q]*res.a[m];\r\
    \n                        if(m%p)break;\r\n                        q*=p,m/=p;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        else{\r\n            rep(i,1,P)rep(j,2,P/i+1){\r\n                res.a[i*j]-=res.a[i]*x.a[j];\r\
    \n            }\r\n        }\r\n        res.ruith();\r\n        for(int i=Q;i>0;i--){\r\
    \n            ll n=N/i,M=int(sqrt(n));\r\n            rep(j,1,M+1){\r\n      \
    \          if(n/j<=P){\r\n                    if(j!=1)res.A[i]-=x.a[j]*res.rui[n/j];\r\
    \n                    res.A[i]-=res.a[j]*x.rui[n/j];\r\n                }\r\n\
    \                else{\r\n                    if(j!=1)res.A[i]-=x.a[j]*res.A[i*j];\r\
    \n                    res.A[i]-=res.a[j]*x.A[i*j];\r\n                }\r\n  \
    \              if(M<=P)res.A[i]+=res.a[j]*x.rui[M];\r\n                else res.A[i]+=res.a[j]*x.A[N/M];\r\
    \n            }\r\n        }\r\n        return res;\r\n    }\r\n    Dirichlet\
    \ pow(ll t){\r\n        assert(done);\r\n        Dirichlet res=ident(),b=*this;\r\
    \n        while(t){\r\n           if(t&1)res=res*b;\r\n           b=b*b;\r\n \
    \          t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    const T&\
    \ operator[](ll x){\r\n        assert(done);\r\n        if(x<=P)return rui[x];\r\
    \n        else return A[N/x];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Dirichlet\
    \ series\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,bool multi,unsigned L=1010101010>struct\
    \ Dirichlet{\r\n    ll N,P,Q;\r\n    vector<T> a,rui,A;\r\n    vector<ll> ps;\r\
    \n    bool done=0;\r\n    Dirichlet(ll n):N(n),P(min<ll>(L,cbrt(n)*cbrt(n))),Q((n+P-1)/P),\r\
    \n        a(P+1),rui(P+1),A(Q+1),done(0){}\r\n    const Dirichlet ident(){\r\n\
    \        Dirichlet res(N);\r\n        res.a.assign(P+1,0);\r\n        res.a[1]=1;\r\
    \n        res.rui.assign(P+1,1);\r\n        res.A.assign(Q+1,1);\r\n        res.done=1;\r\
    \n        return res;\r\n    }\r\n    void sieve(){\r\n        if(!ps.empty())return;\r\
    \n        static bitset<L> isp;\r\n        rep(p,2,P+1)isp[p]=1;\r\n        for(ll\
    \ p=2;p*p<=P;p++)if(isp[p]){\r\n            for(ll q=p*p;q<=P;q+=p)isp[q]=0;\r\
    \n        }\r\n        rep(p,2,P+1)if(isp[p])ps.push_back(p);\r\n    }\r\n   \
    \ void reset(){\r\n        a.assign(P+1,0);\r\n        rui.assign(P+1,0);\r\n\
    \        A.assign(Q+1,0);\r\n        done=0;\r\n    }\r\n    void ruith(){\r\n\
    \        rui.assign(P+1,0);\r\n        rep(i,1,P+1)rui[i]=rui[i-1]+a[i];\r\n \
    \       done=1;\r\n    }\r\n    Dirichlet operator*(const Dirichlet& x){\r\n \
    \       assert(done and x.done);\r\n        Dirichlet res(N);\r\n        if(multi){\r\
    \n            sieve();\r\n            res.a=a;\r\n            for(auto& p:ps){\r\
    \n                for(ll i=P/p;i>0;i--){\r\n                    ll n=p*i,q=p,m=i;\r\
    \n                    for(;;){\r\n                        res.a[n]+=x.a[q]*res.a[m];\r\
    \n                        if(m%p)break;\r\n                        q*=p,m/=p;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        else{\r\n            rep(i,1,P+1)rep(j,1,P/i+1){\r\n                res.a[i*j]+=a[i]*x.a[j];\r\
    \n            }\r\n        }\r\n        res.ruith();\r\n        rep(i,1,Q+1){\r\
    \n            ll n=N/i,M=int(sqrt(n));\r\n            rep(j,1,M+1){\r\n      \
    \          if(n/j<=P)res.A[i]+=a[j]*x.rui[n/j]+x.a[j]*rui[n/j];\r\n          \
    \      else res.A[i]+=a[j]*x.A[i*j]+x.a[j]*A[i*j];\r\n                if(M<=P)res.A[i]-=x.a[j]*rui[M];\r\
    \n                else res.A[i]-=x.a[j]*A[N/M];\r\n            }\r\n        }\r\
    \n        return res;\r\n    }\r\n    Dirichlet operator/(const Dirichlet& x){\r\
    \n        assert(done and x.done);\r\n        Dirichlet res=*this;\r\n       \
    \ if(multi){\r\n            sieve();\r\n            for(auto& p:ps){\r\n     \
    \           rep(i,1,P/p+1){\r\n                    int n=p*i,q=p,m=i;\r\n    \
    \                for(;;){\r\n                        res.a[n]-=x.a[q]*res.a[m];\r\
    \n                        if(m%p)break;\r\n                        q*=p,m/=p;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        else{\r\n            rep(i,1,P)rep(j,2,P/i+1){\r\n                res.a[i*j]-=res.a[i]*x.a[j];\r\
    \n            }\r\n        }\r\n        res.ruith();\r\n        for(int i=Q;i>0;i--){\r\
    \n            ll n=N/i,M=int(sqrt(n));\r\n            rep(j,1,M+1){\r\n      \
    \          if(n/j<=P){\r\n                    if(j!=1)res.A[i]-=x.a[j]*res.rui[n/j];\r\
    \n                    res.A[i]-=res.a[j]*x.rui[n/j];\r\n                }\r\n\
    \                else{\r\n                    if(j!=1)res.A[i]-=x.a[j]*res.A[i*j];\r\
    \n                    res.A[i]-=res.a[j]*x.A[i*j];\r\n                }\r\n  \
    \              if(M<=P)res.A[i]+=res.a[j]*x.rui[M];\r\n                else res.A[i]+=res.a[j]*x.A[N/M];\r\
    \n            }\r\n        }\r\n        return res;\r\n    }\r\n    Dirichlet\
    \ pow(ll t){\r\n        assert(done);\r\n        Dirichlet res=ident(),b=*this;\r\
    \n        while(t){\r\n           if(t&1)res=res*b;\r\n           b=b*b;\r\n \
    \          t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    const T&\
    \ operator[](ll x){\r\n        assert(done);\r\n        if(x<=P)return rui[x];\r\
    \n        else return A[N/x];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Dirichlet\
    \ series\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/dirichlet.hpp
  requiredBy: []
  timestamp: '2022-10-24 03:26:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_sum_of_totient_function.test.cpp
documentation_of: Math/dirichlet.hpp
layout: document
redirect_from:
- /library/Math/dirichlet.hpp
- /library/Math/dirichlet.hpp.html
title: Dirichlet series
---
