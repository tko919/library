---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1781.test.cpp
    title: Verify/YUKI_1781.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative.md
    document_title: Multiplicative Sum
    links: []
  bundledCode: "#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=1010101>vector<int>\
    \ sieve(int N){\r\n    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int\
    \ z=1;z<=5;z+=4){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for(int x=1;x<=sq\
    \ and (n=4*x*x+y*y)<=N;++x){\r\n                isp[n].flip();\r\n           \
    \ }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\n       \
    \         isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n    for(int\
    \ z=2;z<=4;z+=2){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for (int\
    \ x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){\r\n                isp[n].flip();\r\n\
    \            }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\
    \n                isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n  \
    \  for(int y=3;y<=sq;y+=6){\r\n        for(int z=1;z<=2;++z){\r\n            for(int\
    \ x=z;x<=sq and (n=4*x*x+y*y)<=N;x+=3){\r\n                isp[n].flip();\r\n\
    \            }\r\n        }\r\n    }\r\n    for(int n=5;n<=sq;++n)if(isp[n]){\r\
    \n        for(int k=n*n;k<=N;k+=n*n){\r\n            isp[k]=false;\r\n       \
    \ }\r\n    }\r\n    isp[2]=isp[3]=true;\r\n\r\n    vector<int> ret;\r\n    for(int\
    \ i=2;i<=N;i++)if(isp[i]){\r\n        ret.push_back(i);\r\n    }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/multiplicative.hpp\"\
    \n\r\ntemplate<typename T,T (*pe)(int,int),T (*psum)(ll)>T MultiplicativeSum(ll\
    \ N){\r\n    ll SQ=sqrtl(N);\r\n    auto ps=sieve(SQ);\r\n    \r\n    T ret=psum(N)+1;\r\
    \n    auto dfs=[&](auto& dfs,ll x,int i,int e,T cur,T pre)->void{\r\n        T\
    \ nxt=pre*pe(ps[i],e+1);\r\n        ret+=cur*(psum(double(N)/x)-psum(ps[i]));\r\
    \n        ret+=nxt;\r\n        ll L=sqrtl(double(N)/x);\r\n        if(ps[i]<=L)dfs(dfs,x*ps[i],i,e+1,nxt,pre);\r\
    \n        rep(j,i+1,ps.size()){\r\n            if(ps[j]>L)break;\r\n         \
    \   dfs(dfs,x*ps[j],j,1,cur*pe(ps[j],1),cur);\r\n        }\r\n    };\r\n    rep(i,0,ps.size())dfs(dfs,ps[i],i,1,pe(ps[i],1),1);\r\
    \n    return ret;\r\n}\r\n\r\ntemplate<typename T,T (*pe)(int,int),ll (*pcnt)(ll),T\
    \ (*psum)(ll)>T AdditiveSum(ll N){\r\n    ll SQ=sqrtl(N);\r\n    auto ps=sieve(SQ);\r\
    \n    \r\n    T ret=psum(N);\r\n    auto dfs=[&](auto& dfs,ll x,int i,int e,T\
    \ cur,T pre)->void{\r\n        T nxt=pre+pe(ps[i],e+1);\r\n        ret+=cur*(pcnt(double(N)/x)-pcnt(ps[i]))+(psum(double(N)/x)-psum(ps[i]));\r\
    \n        ret+=nxt;\r\n        ll L=sqrtl(double(N)/x);\r\n        if(ps[i]<=L)dfs(dfs,x*ps[i],i,e+1,nxt,pre);\r\
    \n        rep(j,i+1,ps.size()){\r\n            if(ps[j]>L)break;\r\n         \
    \   dfs(dfs,x*ps[j],j,1,cur+pe(ps[j],1),cur);\r\n        }\r\n    };\r\n    rep(i,0,ps.size())dfs(dfs,ps[i],i,1,pe(ps[i],1),0);\r\
    \n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs\
    \ docs/multiplicative.md\r\n */\n"
  code: "#pragma once\r\n#include \"Math/sieve.hpp\"\r\n\r\ntemplate<typename T,T\
    \ (*pe)(int,int),T (*psum)(ll)>T MultiplicativeSum(ll N){\r\n    ll SQ=sqrtl(N);\r\
    \n    auto ps=sieve(SQ);\r\n    \r\n    T ret=psum(N)+1;\r\n    auto dfs=[&](auto&\
    \ dfs,ll x,int i,int e,T cur,T pre)->void{\r\n        T nxt=pre*pe(ps[i],e+1);\r\
    \n        ret+=cur*(psum(double(N)/x)-psum(ps[i]));\r\n        ret+=nxt;\r\n \
    \       ll L=sqrtl(double(N)/x);\r\n        if(ps[i]<=L)dfs(dfs,x*ps[i],i,e+1,nxt,pre);\r\
    \n        rep(j,i+1,ps.size()){\r\n            if(ps[j]>L)break;\r\n         \
    \   dfs(dfs,x*ps[j],j,1,cur*pe(ps[j],1),cur);\r\n        }\r\n    };\r\n    rep(i,0,ps.size())dfs(dfs,ps[i],i,1,pe(ps[i],1),1);\r\
    \n    return ret;\r\n}\r\n\r\ntemplate<typename T,T (*pe)(int,int),ll (*pcnt)(ll),T\
    \ (*psum)(ll)>T AdditiveSum(ll N){\r\n    ll SQ=sqrtl(N);\r\n    auto ps=sieve(SQ);\r\
    \n    \r\n    T ret=psum(N);\r\n    auto dfs=[&](auto& dfs,ll x,int i,int e,T\
    \ cur,T pre)->void{\r\n        T nxt=pre+pe(ps[i],e+1);\r\n        ret+=cur*(pcnt(double(N)/x)-pcnt(ps[i]))+(psum(double(N)/x)-psum(ps[i]));\r\
    \n        ret+=nxt;\r\n        ll L=sqrtl(double(N)/x);\r\n        if(ps[i]<=L)dfs(dfs,x*ps[i],i,e+1,nxt,pre);\r\
    \n        rep(j,i+1,ps.size()){\r\n            if(ps[j]>L)break;\r\n         \
    \   dfs(dfs,x*ps[j],j,1,cur+pe(ps[j],1),cur);\r\n        }\r\n    };\r\n    rep(i,0,ps.size())dfs(dfs,ps[i],i,1,pe(ps[i],1),0);\r\
    \n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Multiplicative Sum\r\n * @docs\
    \ docs/multiplicative.md\r\n */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/multiplicative.hpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/YUKI_1781.test.cpp
documentation_of: Math/multiplicative.hpp
layout: document
redirect_from:
- /library/Math/multiplicative.hpp
- /library/Math/multiplicative.hpp.html
title: Multiplicative Sum
---
## 使い方

`T MultiplicativeSum(ll N)`: **乗法的関数** $f$ について $\sum_{k=1}^N f(k)$ を計算する。テンプレートには
* `T`: 返り値の型
* `T (*pe)(int p,int e)`: $f(p^e)$ を返す関数
* `T (*psum)(ll x)`: $\sum_{p \leq x:\mbox{prime}} f(p)$ を返す関数 ( $x$ は $\lfloor N/d \rfloor$ の形に限られる)

`T AdditiveSum(ll n)`: 上の $f$ が **加法的関数** である場合。