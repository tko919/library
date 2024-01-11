---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Half GCD
    links: []
  bundledCode: "#line 2 \"FPS/halfgcd.hpp\"\n\nnamespace HalfGCD{\n    template<typename\
    \ T>using P=array<T,2>;\n    template<typename T>using Mat=array<T,4>;\n    template<typename\
    \ T>P<T> operator*(const Mat<T>& a,const P<T>& b){\n        P<T> ret={a[0]*b[0]+a[1]*b[1],a[2]*b[0]+a[3]*b[1]};\n\
    \        rep(i,0,2)ret[i].shrink();\n        return ret;\n    }\n    template<typename\
    \ T>Mat<T> operator*(const Mat<T>& a,const Mat<T>& b){\n        Mat<T> ret={a[0]*b[0]+a[1]*b[2],a[0]*b[1]+a[1]*b[3],\n\
    \            a[2]*b[0]+a[3]*b[2],a[2]*b[1]+a[3]*b[3]};\n        rep(i,0,4)ret[i].shrink();\n\
    \        return ret;\n    }\n    \n    template<typename T>Mat<T> HGCD(P<T> a){\n\
    \        int m=(SZ(a[0])+1)>>1;\n        if(SZ(a[1])<=m){\n            Mat<T>\
    \ ret;\n            ret[0]={1},ret[3]={1};\n            return ret;\n        }\n\
    \        auto R=HGCD(P<T>{a[0]>>m,a[1]>>m});\n        a=R*a;\n        if(SZ(a[1])<=m)return\
    \ R;\n        Mat<T> Q;\n        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);\n      \
    \  R=Q*R,a=Q*a;\n        if(SZ(a[1])<=m)return R;\n        int k=2*m+1-SZ(a[0]);\n\
    \        auto H=HGCD(P<T>{a[0]>>k,a[1]>>k});\n        return H*R;\n    }\n   \
    \ template<typename T>Mat<T> InnerGCD(P<T> a){\n        if(SZ(a[0])<SZ(a[1])){\n\
    \            auto M=InnerGCD(P<T>{a[1],a[0]});\n            swap(M[0],M[1]);\n\
    \            swap(M[2],M[3]);\n            return M;\n        }\n        auto\
    \ m0=HGCD(a);\n        a=m0*a;\n        if(a[1].empty())return m0;\n        Mat<T>\
    \ Q;\n        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);\n        m0=Q*m0,a=Q*a;\n \
    \       if(a[1].empty())return m0;\n        return InnerGCD(a)*m0;\n    }\n  \
    \  template<typename T>T gcd(const T& a,const T& b){\n        P<T> p({a,b});\n\
    \        auto M=InnerGCD(p);\n        p=M*p;\n        if(!p[0].empty()){\n   \
    \         auto coeff=p[0].back().inv();\n            for(auto& x:p[0])x*=coeff;\n\
    \        }\n        return p[0];\n    }\n    template<typename T>pair<bool,T>\
    \ PolyInv(const T& a,const T& b){\n        P<T> p({a,b});\n        auto M=InnerGCD(p);\n\
    \        T g=(M*p)[0];\n        if(g.size()!=1)return {false,{}};\n        P<T>\
    \ x({T({1}),b});\n        auto ret=(M*x)[0]%b;\n        auto coeff=g[0].inv();\n\
    \        for(auto& x:ret)x*=coeff;\n        return {true,ret};\n    }\n}\n\n/**\n\
    \ * @brief Half GCD\n*/\n"
  code: "#pragma once\n\nnamespace HalfGCD{\n    template<typename T>using P=array<T,2>;\n\
    \    template<typename T>using Mat=array<T,4>;\n    template<typename T>P<T> operator*(const\
    \ Mat<T>& a,const P<T>& b){\n        P<T> ret={a[0]*b[0]+a[1]*b[1],a[2]*b[0]+a[3]*b[1]};\n\
    \        rep(i,0,2)ret[i].shrink();\n        return ret;\n    }\n    template<typename\
    \ T>Mat<T> operator*(const Mat<T>& a,const Mat<T>& b){\n        Mat<T> ret={a[0]*b[0]+a[1]*b[2],a[0]*b[1]+a[1]*b[3],\n\
    \            a[2]*b[0]+a[3]*b[2],a[2]*b[1]+a[3]*b[3]};\n        rep(i,0,4)ret[i].shrink();\n\
    \        return ret;\n    }\n    \n    template<typename T>Mat<T> HGCD(P<T> a){\n\
    \        int m=(SZ(a[0])+1)>>1;\n        if(SZ(a[1])<=m){\n            Mat<T>\
    \ ret;\n            ret[0]={1},ret[3]={1};\n            return ret;\n        }\n\
    \        auto R=HGCD(P<T>{a[0]>>m,a[1]>>m});\n        a=R*a;\n        if(SZ(a[1])<=m)return\
    \ R;\n        Mat<T> Q;\n        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);\n      \
    \  R=Q*R,a=Q*a;\n        if(SZ(a[1])<=m)return R;\n        int k=2*m+1-SZ(a[0]);\n\
    \        auto H=HGCD(P<T>{a[0]>>k,a[1]>>k});\n        return H*R;\n    }\n   \
    \ template<typename T>Mat<T> InnerGCD(P<T> a){\n        if(SZ(a[0])<SZ(a[1])){\n\
    \            auto M=InnerGCD(P<T>{a[1],a[0]});\n            swap(M[0],M[1]);\n\
    \            swap(M[2],M[3]);\n            return M;\n        }\n        auto\
    \ m0=HGCD(a);\n        a=m0*a;\n        if(a[1].empty())return m0;\n        Mat<T>\
    \ Q;\n        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);\n        m0=Q*m0,a=Q*a;\n \
    \       if(a[1].empty())return m0;\n        return InnerGCD(a)*m0;\n    }\n  \
    \  template<typename T>T gcd(const T& a,const T& b){\n        P<T> p({a,b});\n\
    \        auto M=InnerGCD(p);\n        p=M*p;\n        if(!p[0].empty()){\n   \
    \         auto coeff=p[0].back().inv();\n            for(auto& x:p[0])x*=coeff;\n\
    \        }\n        return p[0];\n    }\n    template<typename T>pair<bool,T>\
    \ PolyInv(const T& a,const T& b){\n        P<T> p({a,b});\n        auto M=InnerGCD(p);\n\
    \        T g=(M*p)[0];\n        if(g.size()!=1)return {false,{}};\n        P<T>\
    \ x({T({1}),b});\n        auto ret=(M*x)[0]%b;\n        auto coeff=g[0].inv();\n\
    \        for(auto& x:ret)x*=coeff;\n        return {true,ret};\n    }\n}\n\n/**\n\
    \ * @brief Half GCD\n*/"
  dependsOn: []
  isVerificationFile: false
  path: FPS/halfgcd.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/halfgcd.hpp
layout: document
redirect_from:
- /library/FPS/halfgcd.hpp
- /library/FPS/halfgcd.hpp.html
title: Half GCD
---
