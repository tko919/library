---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mobius Transform
    links: []
  bundledCode: "#line 2 \"FPS/mobius.hpp\"\n\ntemplate<typename T>Poly<T> comp_ApBx(const\
    \ Poly<T>& f,T a,T b){ // f(a+bx)\n    auto g=f.shift(a.v);\n    T pw=1;\n   \
    \ for(auto& x:g){\n        x*=pw;\n        pw*=b;\n    }\n    return g;\n}\n\n\
    template<typename T>Poly<T> Mobius(const Poly<T>& f,T a,T b,T c,T d){ // f((a+bx)/(c+dx))\n\
    \    assert(c!=0 or d!=0);\n    if(d==0){\n        T a_c=a/c,b_c=b/c;\n      \
    \  return comp_ApBx(f,a_c,b_c);\n    }\n    T p=b/d,q=a-b*c/d;\n    auto g=comp_ApBx(f,p,q);\n\
    \    reverse(ALL(g));\n    g=comp_ApBx(g,c,d);\n    int n=g.size();\n    Poly<T>\
    \ den(n);\n    T cpw=c.pow(n-1),dpw=1,cinv=c.inv();\n    rep(i,0,n){\n       \
    \ den[i]=cpw*dpw*nCr<T>(n-1,i);\n        cpw*=cinv,dpw*=d;\n    }\n    g*=den.inv();\n\
    \    g.resize(n);\n    return g;\n}\n\n/**\n * @brief Mobius Transform\n*/\n"
  code: "#pragma once\n\ntemplate<typename T>Poly<T> comp_ApBx(const Poly<T>& f,T\
    \ a,T b){ // f(a+bx)\n    auto g=f.shift(a.v);\n    T pw=1;\n    for(auto& x:g){\n\
    \        x*=pw;\n        pw*=b;\n    }\n    return g;\n}\n\ntemplate<typename\
    \ T>Poly<T> Mobius(const Poly<T>& f,T a,T b,T c,T d){ // f((a+bx)/(c+dx))\n  \
    \  assert(c!=0 or d!=0);\n    if(d==0){\n        T a_c=a/c,b_c=b/c;\n        return\
    \ comp_ApBx(f,a_c,b_c);\n    }\n    T p=b/d,q=a-b*c/d;\n    auto g=comp_ApBx(f,p,q);\n\
    \    reverse(ALL(g));\n    g=comp_ApBx(g,c,d);\n    int n=g.size();\n    Poly<T>\
    \ den(n);\n    T cpw=c.pow(n-1),dpw=1,cinv=c.inv();\n    rep(i,0,n){\n       \
    \ den[i]=cpw*dpw*nCr<T>(n-1,i);\n        cpw*=cinv,dpw*=d;\n    }\n    g*=den.inv();\n\
    \    g.resize(n);\n    return g;\n}\n\n/**\n * @brief Mobius Transform\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/mobius.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/mobius.hpp
layout: document
redirect_from:
- /library/FPS/mobius.hpp
- /library/FPS/mobius.hpp.html
title: Mobius Transform
---
