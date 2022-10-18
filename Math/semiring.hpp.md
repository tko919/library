---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Semiring
    links: []
  bundledCode: "#line 2 \"Math/semiring.hpp\"\n\r\ntemplate<typename T,T (*add)(T,\
    \ T),T (*mul)(T, T),T (*e0)(),T (*e1)()>struct Semiring{\r\n    T v;\r\n    Semiring(T\
    \ _v=e0()):v(_v){}\r\n    static T id0(){return e0();}\r\n    static T id1(){return\
    \ e1();}    \r\n    Semiring& operator+=(const Semiring& x){return *this=add(v,x.v);}\r\
    \n    Semiring& operator*=(const Semiring& x){return *this=mul(v,x.v);}\r\n  \
    \  Semiring operator+(const Semiring& x)const{return Semiring(*this)+=x;}\r\n\
    \    Semiring operator*(const Semiring& x)const{return Semiring(*this)*=x;}\r\n\
    \    bool operator==(const Semiring &x)const{return v==x.v;}\r\n    bool operator!=(const\
    \ Semiring &x)const{return v!=x.v;}\r\n};\r\n\r\ntemplate<class T>struct Matrix{\r\
    \n    int h,w;\r\n    vector<vector<T>> val;\r\n    Matrix(){}\r\n    Matrix(int\
    \ n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m,T::id0()))){}\r\n   \
    \ vector<T>& operator[](const int i){return val[i];}\r\n    Matrix& operator+=(const\
    \ Matrix& m){\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\n     \
    \   return *this;\r\n    }\r\n    Matrix& operator*=(const Matrix& m){\r\n   \
    \     Matrix<T> res(h,m.w);\r\n        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];\r\
    \n        *this=res; return *this;\r\n    }\r\n    Matrix operator+(const Matrix&\
    \ m)const{return Matrix(*this)+=m;}\r\n    Matrix operator*(const Matrix& m)const{return\
    \ Matrix(*this)*=m;}\r\n    Matrix pow(ll k){\r\n        Matrix<T> res(h,h),c=*this;\r\
    \n        rep(i,0,h)res.val[i][i]=T::id1();\r\n        while(k){\r\n         \
    \   if(k&1)res*=c;\r\n            c*=c;\r\n            k>>=1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Semiring\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T (*add)(T, T),T (*mul)(T, T),T (*e0)(),T\
    \ (*e1)()>struct Semiring{\r\n    T v;\r\n    Semiring(T _v=e0()):v(_v){}\r\n\
    \    static T id0(){return e0();}\r\n    static T id1(){return e1();}    \r\n\
    \    Semiring& operator+=(const Semiring& x){return *this=add(v,x.v);}\r\n   \
    \ Semiring& operator*=(const Semiring& x){return *this=mul(v,x.v);}\r\n    Semiring\
    \ operator+(const Semiring& x)const{return Semiring(*this)+=x;}\r\n    Semiring\
    \ operator*(const Semiring& x)const{return Semiring(*this)*=x;}\r\n    bool operator==(const\
    \ Semiring &x)const{return v==x.v;}\r\n    bool operator!=(const Semiring &x)const{return\
    \ v!=x.v;}\r\n};\r\n\r\ntemplate<class T>struct Matrix{\r\n    int h,w;\r\n  \
    \  vector<vector<T>> val;\r\n    Matrix(){}\r\n    Matrix(int n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m,T::id0()))){}\r\
    \n    vector<T>& operator[](const int i){return val[i];}\r\n    Matrix& operator+=(const\
    \ Matrix& m){\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\n     \
    \   return *this;\r\n    }\r\n    Matrix& operator*=(const Matrix& m){\r\n   \
    \     Matrix<T> res(h,m.w);\r\n        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];\r\
    \n        *this=res; return *this;\r\n    }\r\n    Matrix operator+(const Matrix&\
    \ m)const{return Matrix(*this)+=m;}\r\n    Matrix operator*(const Matrix& m)const{return\
    \ Matrix(*this)*=m;}\r\n    Matrix pow(ll k){\r\n        Matrix<T> res(h,h),c=*this;\r\
    \n        rep(i,0,h)res.val[i][i]=T::id1();\r\n        while(k){\r\n         \
    \   if(k&1)res*=c;\r\n            c*=c;\r\n            k>>=1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Semiring\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/semiring.hpp
  requiredBy: []
  timestamp: '2022-10-18 18:02:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/semiring.hpp
layout: document
redirect_from:
- /library/Math/semiring.hpp
- /library/Math/semiring.hpp.html
title: Semiring
---
