---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/hafnian.hpp
    title: Hafnian of matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_hafnian_of_matrix.test.cpp
    title: Verify/LC_hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: Verify/LC_subset_convolution.test.cpp
    title: Verify/LC_subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Subset Convolution
    links: []
  bundledCode: "#line 2 \"Convolution/subset.hpp\"\n\r\ntemplate<typename T,int LG=20>struct\
    \ SubsetConvolution{\r\n    using POL=array<T,LG+1>;\r\n    vector<int> bpc;\r\
    \n    vector<T> inv;\r\n    SubsetConvolution():bpc(1<<LG),inv(LG+1){\r\n    \
    \    rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;\r\n        rep(i,1,LG+1)inv[i]=T(1)/i;\r\
    \n    }\r\n    void zeta(vector<POL>& a){\r\n        int n=a.size();\r\n     \
    \   for(int w=1;w<n;w<<=1){\r\n            for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\
    \n                rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];\r\n            }\r\
    \n        }\r\n    }\r\n    void mobius(vector<POL>& a){\r\n        int n=a.size(),m=__lg(n);\r\
    \n        for(int w=n>>1;w;w>>=1){\r\n            for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\
    \n                rep(j,bpc[k+w+i],m+1)a[k+w+i][j]-=a[k+i][j];\r\n           \
    \ }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T>& a,vector<T>& b,bool\
    \ same=0){\r\n        assert(a.size()==b.size());\r\n        int n=a.size(),m=__lg(n);\r\
    \n        vector<POL> A(n),B(n);\r\n        rep(i,0,n){\r\n            A[i][bpc[i]]=a[i];\r\
    \n            B[i][bpc[i]]=b[i];\r\n        }\r\n        zeta(A);\r\n        if(same)B=A;\r\
    \n        else zeta(B);\r\n        rep(i,0,n){\r\n            POL c;\r\n     \
    \       rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];\r\n            swap(A[i],c);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> exp(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    ret[0]=1;\r\n            rep(j,1,m+1){\r\n                rep(k,1,j+1)ret[j]+=ret[j-k]*A[i][k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> log(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    rep(j,1,m+1){\r\n                ret[j]=A[i][j]*j;\r\n                rep(k,1,j)ret[j]-=ret[k]*A[i][j-k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> sqrt(vector<T>& a){\r\n      \
    \  int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    ret[0]=1;\r\n            rep(j,1,m+1){\r\n                ret[j]=A[i][j];\r\
    \n                rep(k,1,j)ret[j]-=ret[k]*ret[j-k];\r\n                ret[j]*=inv[2];\r\
    \n            }\r\n            swap(A[i],ret);\r\n        }\r\n        mobius(A);\r\
    \n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n    \
    \    return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Subset Convolution\r\n\
    \ */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,int LG=20>struct SubsetConvolution{\r\
    \n    using POL=array<T,LG+1>;\r\n    vector<int> bpc;\r\n    vector<T> inv;\r\
    \n    SubsetConvolution():bpc(1<<LG),inv(LG+1){\r\n        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;\r\
    \n        rep(i,1,LG+1)inv[i]=T(1)/i;\r\n    }\r\n    void zeta(vector<POL>& a){\r\
    \n        int n=a.size();\r\n        for(int w=1;w<n;w<<=1){\r\n            for(int\
    \ k=0;k<n;k+=w*2)rep(i,0,w){\r\n                rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];\r\
    \n            }\r\n        }\r\n    }\r\n    void mobius(vector<POL>& a){\r\n\
    \        int n=a.size(),m=__lg(n);\r\n        for(int w=n>>1;w;w>>=1){\r\n   \
    \         for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\n                rep(j,bpc[k+w+i],m+1)a[k+w+i][j]-=a[k+i][j];\r\
    \n            }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T>& a,vector<T>&\
    \ b,bool same=0){\r\n        assert(a.size()==b.size());\r\n        int n=a.size(),m=__lg(n);\r\
    \n        vector<POL> A(n),B(n);\r\n        rep(i,0,n){\r\n            A[i][bpc[i]]=a[i];\r\
    \n            B[i][bpc[i]]=b[i];\r\n        }\r\n        zeta(A);\r\n        if(same)B=A;\r\
    \n        else zeta(B);\r\n        rep(i,0,n){\r\n            POL c;\r\n     \
    \       rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];\r\n            swap(A[i],c);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> exp(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    ret[0]=1;\r\n            rep(j,1,m+1){\r\n                rep(k,1,j+1)ret[j]+=ret[j-k]*A[i][k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> log(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    rep(j,1,m+1){\r\n                ret[j]=A[i][j]*j;\r\n                rep(k,1,j)ret[j]-=ret[k]*A[i][j-k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> sqrt(vector<T>& a){\r\n      \
    \  int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    ret[0]=1;\r\n            rep(j,1,m+1){\r\n                ret[j]=A[i][j];\r\
    \n                rep(k,1,j)ret[j]-=ret[k]*ret[j-k];\r\n                ret[j]*=inv[2];\r\
    \n            }\r\n            swap(A[i],ret);\r\n        }\r\n        mobius(A);\r\
    \n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n    \
    \    return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Subset Convolution\r\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/subset.hpp
  requiredBy:
  - Math/hafnian.hpp
  timestamp: '2022-12-28 03:34:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_subset_convolution.test.cpp
  - Verify/LC_hafnian_of_matrix.test.cpp
documentation_of: Convolution/subset.hpp
layout: document
redirect_from:
- /library/Convolution/subset.hpp
- /library/Convolution/subset.hpp.html
title: Subset Convolution
---
