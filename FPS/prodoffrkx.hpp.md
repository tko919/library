---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/YUKI_2097.test.cpp
    title: Verify/YUKI_2097.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: $\Pi_{k=0}^{m-1} f(r^kx)$
    links: []
  bundledCode: "#line 2 \"FPS/prodoffrkx.hpp\"\n\ntemplate<typename T>Poly<T> ProdOf_f_rk_x(Poly<T>&\
    \ f,T r,int m){ // f(x)f(rx)...f(r^{m-1}x)\n    assert(f[0]==1);\n    T pwr=1,rm=T(r).pow(m),pwrm=1;\n\
    \    auto g=f.log();\n    rep(i,1,g.size()){\n        pwr*=r;\n        pwrm*=rm;\n\
    \        if(pwr==1)g[i]*=m;\n        else g[i]*=(pwrm-1)/(pwr-1);\n    }\n   \
    \ return g.exp();\n}\n\n/**\n * @brief $\\Pi_{k=0}^{m-1} f(r^kx)$\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>Poly<T> ProdOf_f_rk_x(Poly<T>& f,T r,int\
    \ m){ // f(x)f(rx)...f(r^{m-1}x)\n    assert(f[0]==1);\n    T pwr=1,rm=T(r).pow(m),pwrm=1;\n\
    \    auto g=f.log();\n    rep(i,1,g.size()){\n        pwr*=r;\n        pwrm*=rm;\n\
    \        if(pwr==1)g[i]*=m;\n        else g[i]*=(pwrm-1)/(pwr-1);\n    }\n   \
    \ return g.exp();\n}\n\n/**\n * @brief $\\Pi_{k=0}^{m-1} f(r^kx)$\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/prodoffrkx.hpp
  requiredBy: []
  timestamp: '2023-01-17 01:58:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/YUKI_2097.test.cpp
documentation_of: FPS/prodoffrkx.hpp
layout: document
redirect_from:
- /library/FPS/prodoffrkx.hpp
- /library/FPS/prodoffrkx.hpp.html
title: $\Pi_{k=0}^{m-1} f(r^kx)$
---
