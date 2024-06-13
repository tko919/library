---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Multipoint Evaluation on Geometric Sequence
    links: []
  bundledCode: "#line 2 \"FPS/multievalgeom.hpp\"\n\ntemplate<typename T>vector<T>\
    \ MultievalGeomSeq(vector<T>& f,T a,T w,int m){\n    int n=f.size();\n    vector<T>\
    \ ret(m);\n    if(w==0){\n        T base=1;\n        rep(i,0,n)ret[0]+=base*f[i],base*=a;\n\
    \        rep(i,1,m)ret[i]=f[0];\n        return ret;\n    }\n    vector<T> tri(n+m-1),itri(n+m-1);\n\
    \    tri[0]=itri[0]=1;\n    T iw=w.inv(),pww=1,pwiw=1;\n    for(int i=1;i<n+m-1;i++,pww*=w,pwiw*=iw){\n\
    \        tri[i]=tri[i-1]*pww;\n        itri[i]=itri[i-1]*pwiw;\n    }\n\n    Poly<T>\
    \ y(n),v(n+m-1);\n    T pwa=1;\n    for(int i=0;i<n;i++,pwa*=a){\n        y[i]=f[i]*itri[i]*pwa;\n\
    \    }\n    rep(i,0,n+m-1)v[i]=tri[i];\n    reverse(ALL(y));\n    y*=v;\n    rep(i,0,m)ret[i]=y[n-1+i]*itri[i];\n\
    \    return ret;\n}\n\n/**\n * @brief Multipoint Evaluation on Geometric Sequence\n\
    */\n"
  code: "#pragma once\n\ntemplate<typename T>vector<T> MultievalGeomSeq(vector<T>&\
    \ f,T a,T w,int m){\n    int n=f.size();\n    vector<T> ret(m);\n    if(w==0){\n\
    \        T base=1;\n        rep(i,0,n)ret[0]+=base*f[i],base*=a;\n        rep(i,1,m)ret[i]=f[0];\n\
    \        return ret;\n    }\n    vector<T> tri(n+m-1),itri(n+m-1);\n    tri[0]=itri[0]=1;\n\
    \    T iw=w.inv(),pww=1,pwiw=1;\n    for(int i=1;i<n+m-1;i++,pww*=w,pwiw*=iw){\n\
    \        tri[i]=tri[i-1]*pww;\n        itri[i]=itri[i-1]*pwiw;\n    }\n\n    Poly<T>\
    \ y(n),v(n+m-1);\n    T pwa=1;\n    for(int i=0;i<n;i++,pwa*=a){\n        y[i]=f[i]*itri[i]*pwa;\n\
    \    }\n    rep(i,0,n+m-1)v[i]=tri[i];\n    reverse(ALL(y));\n    y*=v;\n    rep(i,0,m)ret[i]=y[n-1+i]*itri[i];\n\
    \    return ret;\n}\n\n/**\n * @brief Multipoint Evaluation on Geometric Sequence\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/multievalgeom.hpp
  requiredBy:
  - Convolution/multivariatecyclic.hpp
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
documentation_of: FPS/multievalgeom.hpp
layout: document
redirect_from:
- /library/FPS/multievalgeom.hpp
- /library/FPS/multievalgeom.hpp.html
title: Multipoint Evaluation on Geometric Sequence
---
