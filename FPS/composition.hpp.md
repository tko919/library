---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Composition of Formal Power Series
    links: []
  bundledCode: "#line 2 \"FPS/composition.hpp\"\n\ntemplate<typename T>Poly<T> Composition(Poly<T>&\
    \ p,Poly<T>& q){\n    int n=min(p.size(),q.size());\n    int m=1;\n    while(m*m<n)m++;\n\
    \    vector pwb(m+1,Poly<T>()),pwg(m+1,Poly<T>());\n    pwb[0]=pwg[0]=Poly<T>({T(1)});\n\
    \    pwb[1]=q;\n    rep(i,2,m+1){\n        pwb[i]=pwb[i-1]*pwb[1];\n        pwb[i].resize(n);\n\
    \    }\n    pwg[1]=pwb[m];\n    rep(i,2,m+1){\n        pwg[i]=pwg[i-1]*pwg[1];\n\
    \        pwg[i].resize(n);\n    }\n    Poly<T> res(n);\n    rep(i,0,m+1){\n  \
    \      Poly<T> f;\n        rep(j,0,m){\n            if(m*i+j<(int)p.size()){\n\
    \                f+=pwb[j]*p[m*i+j];\n            }\n        }\n        f*=pwg[i];\n\
    \        f.resize(n);\n        res+=f;\n    }\n    return res;\n}\n\n/*\nf(x)-t=0\n\
    \nx_{n+1}=x_n-{f(x_n)-t}/{f'(x_n)}\n*/\n\ntemplate<typename T>Poly<T> CompositionInv(Poly<T>&\
    \ f){\n    assert(f.size()>=2 and f[0]==0 and f[1]!=0);\n    const int n=f.size();\n\
    \    Poly<T> ret(1),df=f.diff();\n    for(int k=1;k<n;k<<=1){\n        ret.resize(k*2);\n\
    \        Poly<T> sub=f;\n        sub.resize(k*2);\n        sub=Composition(sub,ret);\n\
    \        sub[1]-=1;\n        Poly<T> base=df;\n        base.resize(k*2);\n   \
    \     base=Composition(base,ret);\n        sub*=base.inv();\n        sub.resize(k*2);\n\
    \        ret-=sub;\n    }\n    ret.resize(n);\n    return ret;\n}\n\n/**\n * @brief\
    \ Composition of Formal Power Series\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>Poly<T> Composition(Poly<T>& p,Poly<T>&\
    \ q){\n    int n=min(p.size(),q.size());\n    int m=1;\n    while(m*m<n)m++;\n\
    \    vector pwb(m+1,Poly<T>()),pwg(m+1,Poly<T>());\n    pwb[0]=pwg[0]=Poly<T>({T(1)});\n\
    \    pwb[1]=q;\n    rep(i,2,m+1){\n        pwb[i]=pwb[i-1]*pwb[1];\n        pwb[i].resize(n);\n\
    \    }\n    pwg[1]=pwb[m];\n    rep(i,2,m+1){\n        pwg[i]=pwg[i-1]*pwg[1];\n\
    \        pwg[i].resize(n);\n    }\n    Poly<T> res(n);\n    rep(i,0,m+1){\n  \
    \      Poly<T> f;\n        rep(j,0,m){\n            if(m*i+j<(int)p.size()){\n\
    \                f+=pwb[j]*p[m*i+j];\n            }\n        }\n        f*=pwg[i];\n\
    \        f.resize(n);\n        res+=f;\n    }\n    return res;\n}\n\n/*\nf(x)-t=0\n\
    \nx_{n+1}=x_n-{f(x_n)-t}/{f'(x_n)}\n*/\n\ntemplate<typename T>Poly<T> CompositionInv(Poly<T>&\
    \ f){\n    assert(f.size()>=2 and f[0]==0 and f[1]!=0);\n    const int n=f.size();\n\
    \    Poly<T> ret(1),df=f.diff();\n    for(int k=1;k<n;k<<=1){\n        ret.resize(k*2);\n\
    \        Poly<T> sub=f;\n        sub.resize(k*2);\n        sub=Composition(sub,ret);\n\
    \        sub[1]-=1;\n        Poly<T> base=df;\n        base.resize(k*2);\n   \
    \     base=Composition(base,ret);\n        sub*=base.inv();\n        sub.resize(k*2);\n\
    \        ret-=sub;\n    }\n    ret.resize(n);\n    return ret;\n}\n\n/**\n * @brief\
    \ Composition of Formal Power Series\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/composition.hpp
  requiredBy: []
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/composition.hpp
layout: document
redirect_from:
- /library/FPS/composition.hpp
- /library/FPS/composition.hpp.html
title: Composition of Formal Power Series
---
