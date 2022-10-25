---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/linearequation.hpp
    title: Linear Equation
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"Verify/LC_system_of_linear_equations.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\r\n\r\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int\
    \ mod=1000000007>struct fp {\r\n    int v; static int get_mod(){return mod;}\r\
    \n    int inv() const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(ll x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
    \ return res;}\r\n    fp& operator+=(const fp& x){return init(v+x.v);}\r\n   \
    \ fp& operator-=(const fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const\
    \ fp& x){v=ll(v)*x.v%mod; return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod;\
    \ return *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\
    \n    fp operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\ntemplate<typename T>struct factorial\
    \ {\r\n    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Modint\r\n */\n#line 2 \"Math/matrix.hpp\"\n\r\ntemplate<class T>struct\
    \ Matrix{\r\n    int h,w; vector<vector<T>> val; T det;\r\n    Matrix(){}\r\n\
    \    Matrix(int n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m))){}\r\n\
    \    vector<T>& operator[](const int i){return val[i];}\r\n    Matrix& operator+=(const\
    \ Matrix& m){\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\n     \
    \   return *this;\r\n    }\r\n    Matrix& operator-=(const Matrix& m){\r\n   \
    \     rep(i,0,h)rep(j,0,w)val[i][j]-=m.val[i][j];\r\n        return *this;\r\n\
    \    }\r\n    Matrix& operator*=(const Matrix& m){\r\n        Matrix<T> res(h,m.w);\r\
    \n        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];\r\
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
    \     }\r\n        return res;\r\n    }\r\n    Matrix inv(){\r\n        Matrix\
    \ base(h,h*2),res(h,h);\r\n        rep(i,0,h)rep(j,0,h)base[i][j]=val[i][j];\r\
    \n        rep(i,0,h)base[i][h+i]=1;\r\n        base.gauss(h);\r\n        rep(i,0,h)rep(j,0,h)res[i][j]=base[i][h+j]/base[i][i];\r\
    \n        return res;\r\n    }\r\n    friend istream& operator>>(istream& is,Matrix&\
    \ m){\r\n        rep(i,0,m.h)rep(j,0,m.w)is>>m[i][j];\r\n        return is;\r\n\
    \    }\r\n    friend ostream& operator<<(ostream& os,Matrix& m){\r\n        rep(i,0,m.h){\r\
    \n            rep(j,0,m.w)os<<m[i][j]<<(j==m.w-1 and i!=m.h-1?'\\n':' ');\r\n\
    \        }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Matrix\r\
    \n */\n#line 3 \"Math/linearequation.hpp\"\n\r\ntemplate<typename T>pair<vector<T>,Matrix<T>>\
    \ LinearEquation(Matrix<T> a,vector<T> b){\r\n   int h=a.h,w=a.w;\r\n   rep(i,0,h)a[i].push_back(b[i]);\r\
    \n   a.w++;\r\n   vector<int> idx=a.gauss(w);\r\n   rep(i,idx.size(),h)if(a[i][w]!=0)return\
    \ {{},{}};\r\n   vector<T> res(w);\r\n   rep(i,0,idx.size())res[idx[i]]=a[i][w]/a[i][idx[i]];\r\
    \n   Matrix<T> d(w,h+w);\r\n   rep(i,0,h)rep(j,0,w)d[j][i]=a[i][j];\r\n   rep(i,0,w)d[i][h+i]=1;\r\
    \n   int r=d.gauss(h).size();\r\n   Matrix<T> basis(w-r,w);\r\n   rep(i,r,w)basis[i-r]={d[i].begin()+h,d[i].end()};\r\
    \n   return {res,basis};\r\n}\r\n\r\n/**\r\n * @brief Linear Equation\r\n */\n\
    #line 7 \"Verify/LC_system_of_linear_equations.test.cpp\"\n\r\nusing Fp=fp<998244353>;\r\
    \n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    Matrix<Fp> a(n,m);\r\
    \n    vector<Fp> b(n);\r\n    rep(i,0,n)rep(j,0,m)cin>>a[i][j];\r\n    rep(i,0,n)cin>>b[i];\r\
    \n\r\n    auto [ret,basis]=LinearEquation(a,b);\r\n    if(ret.empty()){\r\n  \
    \      puts(\"-1\");\r\n        return 0;\r\n    }\r\n    cout<<basis.h<<'\\n';\r\
    \n    rep(i,0,m)cout<<ret[i]<<(i==m-1?'\\n':' ');\r\n    rep(i,0,basis.h){\r\n\
    \        rep(j,0,m)cout<<basis[i][j]<<(j==m-1?'\\n':' ');\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"Math/matrix.hpp\"\r\n#include \"Math/linearequation.hpp\"\r\n\r\nusing\
    \ Fp=fp<998244353>;\r\n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n \
    \   Matrix<Fp> a(n,m);\r\n    vector<Fp> b(n);\r\n    rep(i,0,n)rep(j,0,m)cin>>a[i][j];\r\
    \n    rep(i,0,n)cin>>b[i];\r\n\r\n    auto [ret,basis]=LinearEquation(a,b);\r\n\
    \    if(ret.empty()){\r\n        puts(\"-1\");\r\n        return 0;\r\n    }\r\
    \n    cout<<basis.h<<'\\n';\r\n    rep(i,0,m)cout<<ret[i]<<(i==m-1?'\\n':' ');\r\
    \n    rep(i,0,basis.h){\r\n        rep(j,0,m)cout<<basis[i][j]<<(j==m-1?'\\n':'\
    \ ');\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - Math/matrix.hpp
  - Math/linearequation.hpp
  isVerificationFile: true
  path: Verify/LC_system_of_linear_equations.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_system_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_system_of_linear_equations.test.cpp
- /verify/Verify/LC_system_of_linear_equations.test.cpp.html
title: Verify/LC_system_of_linear_equations.test.cpp
---
