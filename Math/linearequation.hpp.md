---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_system_of_linear_equations.test.cpp
    title: Verify/LC_system_of_linear_equations.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Linear Equation
    links: []
  bundledCode: "#line 2 \"Math/matrix.hpp\"\n\r\ntemplate<class T>struct Matrix{\r\
    \n    int h,w; vector<vector<T>> val; T det;\r\n    Matrix(){}\r\n    Matrix(int\
    \ n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m))){}\r\n    vector<T>&\
    \ operator[](const int i){return val[i];}\r\n    Matrix& operator+=(const Matrix&\
    \ m){\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\n        return\
    \ *this;\r\n    }\r\n    Matrix& operator-=(const Matrix& m){\r\n        rep(i,0,h)rep(j,0,w)val[i][j]-=m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix& operator*=(const Matrix& m){\r\
    \n        Matrix<T> res(h,m.w);\r\n        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];\r\
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
    \     }\r\n        return res;\r\n    }\r\n    friend istream& operator>>(istream&\
    \ is,Matrix& m){\r\n        rep(i,0,m.h)rep(j,0,m.w)is>>m[i][j];\r\n        return\
    \ is;\r\n    }\r\n    friend ostream& operator<<(ostream& os,Matrix& m){\r\n \
    \       rep(i,0,m.h){\r\n            rep(j,0,m.w)os<<m[i][j]<<(j==m.w-1 and i!=m.h-1?'\\\
    n':' ');\r\n        }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Matrix\r\n */\n#line 3 \"Math/linearequation.hpp\"\n\r\ntemplate<typename T>pair<vector<T>,Matrix<T>>\
    \ LinearEquation(Matrix<T> a,vector<T> b){\r\n   int h=a.h,w=a.w;\r\n   rep(i,0,h)a[i].push_back(b[i]);\r\
    \n   vector<int> idx=a.gauss(w);\r\n   rep(i,idx.size(),h)if(a[i][w]!=0)return\
    \ {{},{}};\r\n   vector<T> res(w);\r\n   rep(i,0,idx.size())res[idx[i]]=a[i][w]/a[i][idx[i]];\r\
    \n   Matrix<T> d(w,h+w);\r\n   rep(i,0,h)rep(j,0,w)d[j][i]=a[i][j];\r\n   rep(i,0,w)d[i][h+i]=1;\r\
    \n   int r=d.gauss(h).size();\r\n   Matrix<T> basis(w-r,w);\r\n   rep(i,r,w)basis[i-r]={d[i].begin()+h,d[i].end()};\r\
    \n   return {res,basis};\r\n}\r\n\r\n/**\r\n * @brief Linear Equation\r\n */\n"
  code: "#pragma once\r\n#include \"Math/matrix.hpp\"\r\n\r\ntemplate<typename T>pair<vector<T>,Matrix<T>>\
    \ LinearEquation(Matrix<T> a,vector<T> b){\r\n   int h=a.h,w=a.w;\r\n   rep(i,0,h)a[i].push_back(b[i]);\r\
    \n   vector<int> idx=a.gauss(w);\r\n   rep(i,idx.size(),h)if(a[i][w]!=0)return\
    \ {{},{}};\r\n   vector<T> res(w);\r\n   rep(i,0,idx.size())res[idx[i]]=a[i][w]/a[i][idx[i]];\r\
    \n   Matrix<T> d(w,h+w);\r\n   rep(i,0,h)rep(j,0,w)d[j][i]=a[i][j];\r\n   rep(i,0,w)d[i][h+i]=1;\r\
    \n   int r=d.gauss(h).size();\r\n   Matrix<T> basis(w-r,w);\r\n   rep(i,r,w)basis[i-r]={d[i].begin()+h,d[i].end()};\r\
    \n   return {res,basis};\r\n}\r\n\r\n/**\r\n * @brief Linear Equation\r\n */"
  dependsOn:
  - Math/matrix.hpp
  isVerificationFile: false
  path: Math/linearequation.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_system_of_linear_equations.test.cpp
documentation_of: Math/linearequation.hpp
layout: document
redirect_from:
- /library/Math/linearequation.hpp
- /library/Math/linearequation.hpp.html
title: Linear Equation
---
