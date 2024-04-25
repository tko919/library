---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/matrix.hpp
    title: Matrix
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/detaplusbx.hpp
    title: $\det(A+Bx)$
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Characteristic Polynomial
    links:
    - http://www.oishi.info.waseda.ac.jp/~samukawa/eigvieta.pdf
  bundledCode: "#line 2 \"Math/matrix.hpp\"\n\r\ntemplate<class T>struct Matrix{\r\
    \n    int h,w; vector<vector<T>> val; T det;\r\n    Matrix(){}\r\n    Matrix(int\
    \ n):h(n),w(n),val(vector<vector<T>>(n,vector<T>(n))){}\r\n    Matrix(int n,int\
    \ m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m))){}\r\n    vector<T>& operator[](const\
    \ int i){return val[i];}\r\n    Matrix& operator+=(const Matrix& m){\r\n     \
    \   assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\
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
    \ Matrix\r\n */\n#line 3 \"Math/charpoly.hpp\"\n\ntemplate<typename T>vector<T>\
    \ CharPoly(Matrix<T> a){\n    // to Hessenberg\n    //reference:http://www.oishi.info.waseda.ac.jp/~samukawa/eigvieta.pdf\n\
    \    int n=a.h;\n    rep(s,0,n-2){\n        rep(j,s+1,n)if(a[j][s]!=0){\n    \
    \        swap(a[j],a[s+1]);\n            rep(i,0,n)swap(a[i][j],a[i][s+1]);\n\
    \            break;\n        }\n        if(a[s+1][s]==0)continue;\n        T X=T(1)/a[s+1][s];\n\
    \        rep(i,s+2,n){\n            T base=a[i][s]*X;\n            rep(j,0,n)a[i][j]-=a[s+1][j]*base;\n\
    \            rep(j,0,n)a[j][s+1]+=a[j][i]*base;\n        }\n    }\n    vector\
    \ dp(n+1,vector<T>(n+1));\n    dp[0][0]=1;\n    rep(i,0,n){\n        rep(k,0,i+1){\n\
    \            dp[i+1][k+1]+=dp[i][k];\n            dp[i+1][k]-=dp[i][k]*a[i][i];\n\
    \        }\n        T prod=1;\n        for(int j=i-1;j>=0;j--){\n            prod*=a[j+1][j];\n\
    \            T base=prod*a[j][i];\n            rep(k,0,i+1)dp[i+1][k]-=dp[j][k]*base;\n\
    \        }\n    }\n    return dp[n];\n}\n\n/**\n * @brief Characteristic Polynomial\n\
    */\n"
  code: "#pragma once\n#include \"Math/matrix.hpp\"\n\ntemplate<typename T>vector<T>\
    \ CharPoly(Matrix<T> a){\n    // to Hessenberg\n    //reference:http://www.oishi.info.waseda.ac.jp/~samukawa/eigvieta.pdf\n\
    \    int n=a.h;\n    rep(s,0,n-2){\n        rep(j,s+1,n)if(a[j][s]!=0){\n    \
    \        swap(a[j],a[s+1]);\n            rep(i,0,n)swap(a[i][j],a[i][s+1]);\n\
    \            break;\n        }\n        if(a[s+1][s]==0)continue;\n        T X=T(1)/a[s+1][s];\n\
    \        rep(i,s+2,n){\n            T base=a[i][s]*X;\n            rep(j,0,n)a[i][j]-=a[s+1][j]*base;\n\
    \            rep(j,0,n)a[j][s+1]+=a[j][i]*base;\n        }\n    }\n    vector\
    \ dp(n+1,vector<T>(n+1));\n    dp[0][0]=1;\n    rep(i,0,n){\n        rep(k,0,i+1){\n\
    \            dp[i+1][k+1]+=dp[i][k];\n            dp[i+1][k]-=dp[i][k]*a[i][i];\n\
    \        }\n        T prod=1;\n        for(int j=i-1;j>=0;j--){\n            prod*=a[j+1][j];\n\
    \            T base=prod*a[j][i];\n            rep(k,0,i+1)dp[i+1][k]-=dp[j][k]*base;\n\
    \        }\n    }\n    return dp[n];\n}\n\n/**\n * @brief Characteristic Polynomial\n\
    */"
  dependsOn:
  - Math/matrix.hpp
  isVerificationFile: false
  path: Math/charpoly.hpp
  requiredBy:
  - Math/detaplusbx.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/charpoly.hpp
layout: document
redirect_from:
- /library/Math/charpoly.hpp
- /library/Math/charpoly.hpp.html
title: Characteristic Polynomial
---
