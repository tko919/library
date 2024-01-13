---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Convolution/subset.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_hafnian_of_matrix.test.cpp
    title: Verify/LC_hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Hafnian of matrix
    links: []
  bundledCode: "#line 2 \"Math/hafnian.hpp\"\n\n#line 2 \"Math/matrix.hpp\"\n\r\n\
    template<class T>struct Matrix{\r\n    int h,w; vector<vector<T>> val; T det;\r\
    \n    Matrix(){}\r\n    Matrix(int n):h(n),w(n),val(vector<vector<T>>(n,vector<T>(n))){}\r\
    \n    Matrix(int n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m))){}\r\
    \n    vector<T>& operator[](const int i){return val[i];}\r\n    Matrix& operator+=(const\
    \ Matrix& m){\r\n        assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix& operator-=(const Matrix& m){\r\
    \n        assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)val[i][j]-=m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix& operator*=(const Matrix& m){\r\
    \n        assert(w==m.h);\r\n        Matrix<T> res(h,m.w);\r\n        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];\r\
    \n        *this=res; return *this;\r\n    }\r\n    Matrix operator+(const Matrix&\
    \ m)const{return Matrix(*this)+=m;}\r\n    Matrix operator-(const Matrix& m)const{return\
    \ Matrix(*this)-=m;}\r\n    Matrix operator*(const Matrix& m)const{return Matrix(*this)*=m;}\r\
    \n    Matrix pow(ll k){\r\n        Matrix<T> res(h,h),c=*this; rep(i,0,h)res.val[i][i]=1;\r\
    \n        while(k){if(k&1)res*=c; c*=c; k>>=1;} return res;\r\n    }\r\n    vector<int>\
    \ gauss(int c=-1){\r\n        if(val.empty())return {};\r\n        if(c==-1)c=w;\r\
    \n        int cur=0; vector<int> res; det=1;\r\n        rep(i,0,c){\r\n      \
    \      if(cur==h)break;\r\n            rep(j,cur,h)if(val[j][i]!=0){\r\n     \
    \           swap(val[cur],val[j]);\r\n                if(cur!=j)det*=-1;\r\n \
    \               break;\r\n            }\r\n            det*=val[cur][i];\r\n \
    \           if(val[cur][i]==0)continue;\r\n            rep(j,0,h)if(j!=cur){\r\
    \n                T z=val[j][i]/val[cur][i];\r\n                rep(k,i,w)val[j][k]-=val[cur][k]*z;\r\
    \n            }\r\n            res.push_back(i);\r\n            cur++;\r\n   \
    \     }\r\n        return res;\r\n    }\r\n    Matrix inv(){\r\n        assert(h==w);\r\
    \n        Matrix base(h,h*2),res(h,h);\r\n        rep(i,0,h)rep(j,0,h)base[i][j]=val[i][j];\r\
    \n        rep(i,0,h)base[i][h+i]=1;\r\n        base.gauss(h);\r\n        det=base.det;\r\
    \n        rep(i,0,h)rep(j,0,h)res[i][j]=base[i][h+j]/base[i][i];\r\n        return\
    \ res;\r\n    }\r\n    bool operator==(const Matrix& m){\r\n        assert(h==m.h\
    \ and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)if(val[i][j]!=m.val[i][j])return\
    \ false;\r\n        return true;\r\n    }\r\n    bool operator!=(const Matrix&\
    \ m){\r\n        assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)if(val[i][j]==m.val[i][j])return\
    \ false;\r\n        return true;\r\n    }\r\n    friend istream& operator>>(istream&\
    \ is,Matrix& m){\r\n        rep(i,0,m.h)rep(j,0,m.w)is>>m[i][j];\r\n        return\
    \ is;\r\n    }\r\n    friend ostream& operator<<(ostream& os,Matrix& m){\r\n \
    \       rep(i,0,m.h){\r\n            rep(j,0,m.w)os<<m[i][j]<<(j==m.w-1 and i!=m.h-1?'\\\
    n':' ');\r\n        }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Matrix\r\n */\n#line 2 \"Convolution/subset.hpp\"\n\r\ntemplate<typename T,int\
    \ LG=20>struct SubsetConvolution{\r\n    using POL=array<T,LG+1>;\r\n    vector<int>\
    \ bpc;\r\n    vector<T> inv;\r\n    SubsetConvolution():bpc(1<<LG),inv(LG+1){\r\
    \n        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;\r\n        rep(i,1,LG+1)inv[i]=T(1)/i;\r\
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
    \n        else zeta(B);\r\n        rep(i,0,n){\r\n            POL c={};\r\n  \
    \          rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];\r\n            swap(A[i],c);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> exp(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret={};\r\n     \
    \       ret[0]=1;\r\n            rep(j,1,m+1){\r\n                rep(k,1,j+1)ret[j]+=ret[j-k]*A[i][k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> log(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret={};\r\n     \
    \       rep(j,1,m+1){\r\n                ret[j]=A[i][j]*j;\r\n               \
    \ rep(k,1,j)ret[j]-=ret[k]*A[i][j-k]*k;\r\n                ret[j]*=inv[j];\r\n\
    \            }\r\n            swap(A[i],ret);\r\n        }\r\n        mobius(A);\r\
    \n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n    \
    \    return ret;\r\n    }\r\n    vector<T> sqrt(vector<T>& a){\r\n        int\
    \ n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret={};\r\n     \
    \       ret[0]=1;\r\n            rep(j,1,m+1){\r\n                ret[j]=A[i][j];\r\
    \n                rep(k,1,j)ret[j]-=ret[k]*ret[j-k];\r\n                ret[j]*=inv[2];\r\
    \n            }\r\n            swap(A[i],ret);\r\n        }\r\n        mobius(A);\r\
    \n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n    \
    \    return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Subset Convolution\r\n\
    \ */\n#line 5 \"Math/hafnian.hpp\"\n\ntemplate<typename T>T Hafnian(Matrix<T>&\
    \ a){\n    int n=a.h;\n    assert(n%2==0);\n    n>>=1;\n\n    vector<T> cycle(1<<n);\n\
    \    vector dp(1<<n,vector<T>(n*2));\n    rep(base,0,n)dp[1<<base][base*2]=1;\n\
    \    rep(mask,0,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)if(mask>>(base>>1)&1){\n            T add=dp[mask][base];\n\
    \            rep(nxt,0,top)if(!(mask>>nxt&1)){\n                dp[mask|(1<<nxt)][nxt*2+1]+=add*a[base][nxt*2];\n\
    \                dp[mask|(1<<nxt)][nxt*2]+=add*a[base][nxt*2+1];\n           \
    \ }\n        }\n    }\n    rep(mask,1,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)cycle[mask]+=dp[mask][base]*a[base][top*2+1];\n    }\n\
    \    \n    SubsetConvolution<T> buf;\n    auto ret=buf.exp(cycle);\n    return\
    \ ret[(1<<n)-1];\n}\n\n/**\n * @brief Hafnian of matrix\n*/\n"
  code: "#pragma once\n\n#include \"Math/matrix.hpp\"\n#include \"Convolution/subset.hpp\"\
    \n\ntemplate<typename T>T Hafnian(Matrix<T>& a){\n    int n=a.h;\n    assert(n%2==0);\n\
    \    n>>=1;\n\n    vector<T> cycle(1<<n);\n    vector dp(1<<n,vector<T>(n*2));\n\
    \    rep(base,0,n)dp[1<<base][base*2]=1;\n    rep(mask,0,1<<n){\n        int top=-1;\n\
    \        rep(i,0,n)if(mask>>i&1)top=i;\n        rep(base,0,n*2)if(mask>>(base>>1)&1){\n\
    \            T add=dp[mask][base];\n            rep(nxt,0,top)if(!(mask>>nxt&1)){\n\
    \                dp[mask|(1<<nxt)][nxt*2+1]+=add*a[base][nxt*2];\n           \
    \     dp[mask|(1<<nxt)][nxt*2]+=add*a[base][nxt*2+1];\n            }\n       \
    \ }\n    }\n    rep(mask,1,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)cycle[mask]+=dp[mask][base]*a[base][top*2+1];\n    }\n\
    \    \n    SubsetConvolution<T> buf;\n    auto ret=buf.exp(cycle);\n    return\
    \ ret[(1<<n)-1];\n}\n\n/**\n * @brief Hafnian of matrix\n*/"
  dependsOn:
  - Math/matrix.hpp
  - Convolution/subset.hpp
  isVerificationFile: false
  path: Math/hafnian.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_hafnian_of_matrix.test.cpp
documentation_of: Math/hafnian.hpp
layout: document
redirect_from:
- /library/Math/hafnian.hpp
- /library/Math/hafnian.hpp.html
title: Hafnian of matrix
---
