---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: FPS/berlekampmassey.hpp
    title: Berlekamp Massey Algorithm
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sparse_matrix_det.test.cpp
    title: Verify/LC_sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Black Box Linear Algebra
    links: []
  bundledCode: "#line 2 \"Math/bbla.hpp\"\n\r\n#line 2 \"FPS/berlekampmassey.hpp\"\
    \n\r\ntemplate<typename T>vector<T> BerlekampMassey(vector<T>& a){\r\n   int n=a.size();\
    \ T d=1;\r\n   vector<T> b(1),c(1);\r\n   b[0]=c[0]=1;\r\n   rep(j,1,n+1){\r\n\
    \      int l=c.size(),m=b.size();\r\n      T x=0;\r\n      rep(i,0,l)x+=c[i]*a[j-l+i];\r\
    \n      b.push_back(0);\r\n      m++;\r\n      if(x==0)continue;\r\n      T coeff=-x/d;\r\
    \n      if(l<m){\r\n         auto tmp=c;\r\n         c.insert(c.begin(),m-l,0);\r\
    \n         rep(i,0,m)c[m-1-i]+=coeff*b[m-1-i];\r\n         b=tmp; d=x;\r\n   \
    \   }\r\n      else rep(i,0,m)c[l-1-i]+=coeff*b[m-1-i];\r\n   }\r\n   return c;\r\
    \n}\r\n\r\n/**\r\n * @brief Berlekamp Massey Algorithm\r\n */\n#line 2 \"Utility/random.hpp\"\
    \n\r\nstruct Random{\r\n    random_device rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\
    \n    Random(){}\r\n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n \
    \       x=y,y=z,z=w;\r\n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n\
    \    unsigned get(unsigned L){\r\n        return get()%(L+1);\r\n    }\r\n   \
    \ template<typename T>T get(T L,T R){\r\n        return get(R-L)+L;\r\n    }\r\
    \n    double uniform(){\r\n        return double(get())/UINT_MAX;\r\n    }\r\n\
    \    string str(int n){\r\n        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\
    \n        return ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter\
    \ first,Iter last){\r\n        if(first==last)return;\r\n        int len=1;\r\n\
    \        for(auto it=first+1;it!=last;it++){\r\n            len++;\r\n       \
    \     int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\n\
    \        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 5 \"Math/bbla.hpp\"\n\r\nRandom genBBLA;\r\ntemplate<typename T>Poly<T>\
    \ RandPoly(int n){\r\n    Poly<T> ret(n);\r\n    for(auto& x:ret)x=genBBLA.get(1,T::get_mod()-1);\r\
    \n    return ret;\r\n}\r\ntemplate<typename T>struct SparseMatrix{\r\n    vector<T>\
    \ base;\r\n    vector<map<int,T>> extra;\r\n    SparseMatrix(int n,T v=0):base(n,v),extra(n){}\r\
    \n    int size()const{return base.size();}\r\n    inline void add(int i,int j,T\
    \ x){extra[i][j]+=x;}\r\n    friend Poly<T> operator*(const SparseMatrix<T>& A,const\
    \ Poly<T>& b){\r\n        int n=A.size();\r\n        Poly<T> ret(n);\r\n     \
    \   T sum;\r\n        for(auto& v:b)sum+=v;\r\n        rep(i,0,n){\r\n       \
    \     T add=sum;\r\n            for(auto& [j,v]:A.extra[i]){\r\n             \
    \   ret[i]+=v*b[j];\r\n                add-=b[j];\r\n            }\r\n       \
    \     ret[i]+=add*A.base[i];\r\n        }\r\n        return ret;\r\n    }\r\n\
    \    void mul(int i,T x){\r\n        base[i]*=x;\r\n        for(auto& [_,v]:extra[i])v*=x;\r\
    \n    }\r\n};\r\n\r\ntemplate<typename T>Poly<T> MinPolyforVector(const vector<Poly<T>>&\
    \ b){\r\n    int n=b.size(),m=b[0].size();\r\n    Poly<T> base=RandPoly<T>(m),a(n);\r\
    \n    rep(i,0,n)rep(j,0,m)a[i]+=base[j]*b[i][j];\r\n    return Poly<T>(BerlekampMassey(a)).rev();\r\
    \n}\r\ntemplate<typename T>Poly<T> MinPolyforMatrix(const SparseMatrix<T>& A){\r\
    \n    int n=A.size();\r\n    Poly<T> base=RandPoly<T>(n);\r\n    vector<Poly<T>>\
    \ b(n*2+1);\r\n    rep(i,0,n*2+1)b[i]=base,base=A*base;\r\n    return MinPolyforVector(b);\r\
    \n}\r\ntemplate<typename T>Poly<T> FastPow(const SparseMatrix<T>& A,Poly<T> b,ll\
    \ t){\r\n    int n=A.size();\r\n    auto mp=MinPolyforMatrix(A).rev();\r\n   \
    \ Poly<T> cs({T(1)}),base({T(0),T(1)});\r\n    while(t){\r\n        if(t&1){\r\
    \n            cs*=base;\r\n            cs%=mp;\r\n        }\r\n        base=base.square();\r\
    \n        base%=mp;\r\n        t>>=1;\r\n    }\r\n    Poly<T> ret(n);\r\n    for(auto&\
    \ c:cs)ret+=b*c,b=A*b;\r\n    return ret;\r\n}\r\ntemplate<typename T>T FastDet(const\
    \ SparseMatrix<T>& A){\r\n    int n=A.size();\r\n    for(;;){\r\n        Poly<T>\
    \ d=RandPoly<T>(n);\r\n        SparseMatrix<T> AD=A;\r\n        rep(i,0,n)AD.mul(i,d[i]);\r\
    \n        auto mp=MinPolyforMatrix(AD);\r\n        if(mp.back()==0)return 0;\r\
    \n        if(int(mp.size())!=n+1)continue;\r\n        T ret=mp.back(),base=1;\r\
    \n        if(n&1)ret=-ret;\r\n        for(auto& v:d)base*=v;\r\n        return\
    \ ret/base;\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Black Box Linear Algebra\r\n\
    \ */\n"
  code: "#pragma once\r\n\r\n#include \"FPS/berlekampmassey.hpp\"\r\n#include \"Utility/random.hpp\"\
    \r\n\r\nRandom genBBLA;\r\ntemplate<typename T>Poly<T> RandPoly(int n){\r\n  \
    \  Poly<T> ret(n);\r\n    for(auto& x:ret)x=genBBLA.get(1,T::get_mod()-1);\r\n\
    \    return ret;\r\n}\r\ntemplate<typename T>struct SparseMatrix{\r\n    vector<T>\
    \ base;\r\n    vector<map<int,T>> extra;\r\n    SparseMatrix(int n,T v=0):base(n,v),extra(n){}\r\
    \n    int size()const{return base.size();}\r\n    inline void add(int i,int j,T\
    \ x){extra[i][j]+=x;}\r\n    friend Poly<T> operator*(const SparseMatrix<T>& A,const\
    \ Poly<T>& b){\r\n        int n=A.size();\r\n        Poly<T> ret(n);\r\n     \
    \   T sum;\r\n        for(auto& v:b)sum+=v;\r\n        rep(i,0,n){\r\n       \
    \     T add=sum;\r\n            for(auto& [j,v]:A.extra[i]){\r\n             \
    \   ret[i]+=v*b[j];\r\n                add-=b[j];\r\n            }\r\n       \
    \     ret[i]+=add*A.base[i];\r\n        }\r\n        return ret;\r\n    }\r\n\
    \    void mul(int i,T x){\r\n        base[i]*=x;\r\n        for(auto& [_,v]:extra[i])v*=x;\r\
    \n    }\r\n};\r\n\r\ntemplate<typename T>Poly<T> MinPolyforVector(const vector<Poly<T>>&\
    \ b){\r\n    int n=b.size(),m=b[0].size();\r\n    Poly<T> base=RandPoly<T>(m),a(n);\r\
    \n    rep(i,0,n)rep(j,0,m)a[i]+=base[j]*b[i][j];\r\n    return Poly<T>(BerlekampMassey(a)).rev();\r\
    \n}\r\ntemplate<typename T>Poly<T> MinPolyforMatrix(const SparseMatrix<T>& A){\r\
    \n    int n=A.size();\r\n    Poly<T> base=RandPoly<T>(n);\r\n    vector<Poly<T>>\
    \ b(n*2+1);\r\n    rep(i,0,n*2+1)b[i]=base,base=A*base;\r\n    return MinPolyforVector(b);\r\
    \n}\r\ntemplate<typename T>Poly<T> FastPow(const SparseMatrix<T>& A,Poly<T> b,ll\
    \ t){\r\n    int n=A.size();\r\n    auto mp=MinPolyforMatrix(A).rev();\r\n   \
    \ Poly<T> cs({T(1)}),base({T(0),T(1)});\r\n    while(t){\r\n        if(t&1){\r\
    \n            cs*=base;\r\n            cs%=mp;\r\n        }\r\n        base=base.square();\r\
    \n        base%=mp;\r\n        t>>=1;\r\n    }\r\n    Poly<T> ret(n);\r\n    for(auto&\
    \ c:cs)ret+=b*c,b=A*b;\r\n    return ret;\r\n}\r\ntemplate<typename T>T FastDet(const\
    \ SparseMatrix<T>& A){\r\n    int n=A.size();\r\n    for(;;){\r\n        Poly<T>\
    \ d=RandPoly<T>(n);\r\n        SparseMatrix<T> AD=A;\r\n        rep(i,0,n)AD.mul(i,d[i]);\r\
    \n        auto mp=MinPolyforMatrix(AD);\r\n        if(mp.back()==0)return 0;\r\
    \n        if(int(mp.size())!=n+1)continue;\r\n        T ret=mp.back(),base=1;\r\
    \n        if(n&1)ret=-ret;\r\n        for(auto& v:d)base*=v;\r\n        return\
    \ ret/base;\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Black Box Linear Algebra\r\n\
    \ */"
  dependsOn:
  - FPS/berlekampmassey.hpp
  - Utility/random.hpp
  isVerificationFile: false
  path: Math/bbla.hpp
  requiredBy: []
  timestamp: '2022-02-02 03:30:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_sparse_matrix_det.test.cpp
  - Verify/YUKI_1112.test.cpp
  - Verify/YUKI_310.test.cpp
documentation_of: Math/bbla.hpp
layout: document
redirect_from:
- /library/Math/bbla.hpp
- /library/Math/bbla.hpp.html
title: Black Box Linear Algebra
---
