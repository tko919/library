---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/hafnian.hpp
    title: Hafnian of matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_subset_convolution.test.cpp
    title: Verify/LC_subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Subset Convolution
    links: []
  bundledCode: "#line 2 \"Convolution/subset.hpp\"\n\r\ntemplate<typename T>struct\
    \ SubsetConvolution{\r\n    const int LG;\r\n    vector<int> bpc;\r\n    SubsetConvolution(int\
    \ lg=20):LG(lg),bpc(1<<LG){\r\n        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;\r\
    \n    }\r\n    void zeta(vector<vector<T>>& a){\r\n        int n=a.size();\r\n\
    \        for(int w=1;w<n;w<<=1){\r\n            for(int k=0;k<n;k+=w*2)rep(i,0,w){\
    \ // k+i:w\u3092\u542B\u307E\u306A\u3044bitmask\u3092\u8D70\u67FB\r\n        \
    \        rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];\r\n            }\r\n     \
    \   }\r\n    }\r\n    void mobius(vector<vector<T>>& a){\r\n        int n=a.size(),m=__lg(n);\r\
    \n        for(int w=n>>1;w;w>>=1){\r\n            for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\
    \n                rep(j,bpc[k+w+i],m+1)a[k+w+i][j]-=a[k+i][j];\r\n           \
    \ }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T>& a,vector<T>& b,bool\
    \ same=0){\r\n        assert(a.size()==b.size());\r\n        int n=a.size(),m=__lg(n);\r\
    \n        vector A(n,vector<T>(m+1)),B(n,vector<T>(m+1));\r\n        rep(i,0,n){\r\
    \n            A[i][bpc[i]]=a[i];\r\n            B[i][bpc[i]]=b[i];\r\n       \
    \ }\r\n        zeta(A);\r\n        if(same)B=A;\r\n        else zeta(B);\r\n \
    \       rep(i,0,n){\r\n            vector<T> c(m+1);\r\n            rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];\r\
    \n            swap(A[i],c);\r\n        }\r\n        mobius(A);\r\n        vector<T>\
    \ ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n        return ret;\r\n\
    \    }\r\n    template<void (*F)(vector<T>&)>vector<T> execute(vector<T>& a){\r\
    \n        int n=a.size(),m=__lg(n);\r\n        vector A(n,vector<T>(m+1));\r\n\
    \        rep(i,0,n)A[i][bpc[i]]=a[i];\r\n        zeta(A);\r\n        rep(i,0,n)F(A[i]);\r\
    \n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Subset Convolution\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct SubsetConvolution{\r\n   \
    \ const int LG;\r\n    vector<int> bpc;\r\n    SubsetConvolution(int lg=20):LG(lg),bpc(1<<LG){\r\
    \n        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;\r\n    }\r\n    void zeta(vector<vector<T>>&\
    \ a){\r\n        int n=a.size();\r\n        for(int w=1;w<n;w<<=1){\r\n      \
    \      for(int k=0;k<n;k+=w*2)rep(i,0,w){ // k+i:w\u3092\u542B\u307E\u306A\u3044\
    bitmask\u3092\u8D70\u67FB\r\n                rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];\r\
    \n            }\r\n        }\r\n    }\r\n    void mobius(vector<vector<T>>& a){\r\
    \n        int n=a.size(),m=__lg(n);\r\n        for(int w=n>>1;w;w>>=1){\r\n  \
    \          for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\n                rep(j,bpc[k+w+i],m+1)a[k+w+i][j]-=a[k+i][j];\r\
    \n            }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T>& a,vector<T>&\
    \ b,bool same=0){\r\n        assert(a.size()==b.size());\r\n        int n=a.size(),m=__lg(n);\r\
    \n        vector A(n,vector<T>(m+1)),B(n,vector<T>(m+1));\r\n        rep(i,0,n){\r\
    \n            A[i][bpc[i]]=a[i];\r\n            B[i][bpc[i]]=b[i];\r\n       \
    \ }\r\n        zeta(A);\r\n        if(same)B=A;\r\n        else zeta(B);\r\n \
    \       rep(i,0,n){\r\n            vector<T> c(m+1);\r\n            rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];\r\
    \n            swap(A[i],c);\r\n        }\r\n        mobius(A);\r\n        vector<T>\
    \ ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n        return ret;\r\n\
    \    }\r\n    template<void (*F)(vector<T>&)>vector<T> execute(vector<T>& a){\r\
    \n        int n=a.size(),m=__lg(n);\r\n        vector A(n,vector<T>(m+1));\r\n\
    \        rep(i,0,n)A[i][bpc[i]]=a[i];\r\n        zeta(A);\r\n        rep(i,0,n)F(A[i]);\r\
    \n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Subset Convolution\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/subset.hpp
  requiredBy:
  - Math/hafnian.hpp
  timestamp: '2022-12-26 23:10:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_subset_convolution.test.cpp
documentation_of: Convolution/subset.hpp
layout: document
redirect_from:
- /library/Convolution/subset.hpp
- /library/Convolution/subset.hpp.html
title: Subset Convolution
---
