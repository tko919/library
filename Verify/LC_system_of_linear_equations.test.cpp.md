---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/linearequation.hpp
    title: Linear Equation
  - icon: ':question:'
    path: Math/matrix.hpp
    title: Matrix
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"Verify/LC_system_of_linear_equations.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\r\n\r\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
    \n#define UB(v,x) int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long\
    \ long int;\r\nusing ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing\
    \ u128=__uint128_t;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Math/modint.hpp\"\
    \n\r\ntemplate <int mod = 1000000007> struct fp {\r\n    int v;\r\n    static\
    \ constexpr int get_mod() { return mod; }\r\n    int inv() const {\r\n       \
    \ int tmp, a = v, b = mod, x = 1, y = 0;\r\n        while (b)\r\n            tmp\
    \ = a / b, a -= tmp * b, swap(a, b), x -= tmp * y, swap(x, y);\r\n        if (x\
    \ < 0) {\r\n            x += mod;\r\n        }\r\n        return x;\r\n    }\r\
    \n    fp(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\r\n   \
    \ fp operator-() const { return fp() - *this; }\r\n    fp pow(ll t) {\r\n    \
    \    assert(t >= 0);\r\n        fp res = 1, b = *this;\r\n        while (t) {\r\
    \n            if (t & 1)\r\n                res *= b;\r\n            b *= b;\r\
    \n            t >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    fp\
    \ &operator+=(const fp &x) {\r\n        if ((v += x.v) >= mod)\r\n           \
    \ v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator-=(const fp &x)\
    \ {\r\n        if ((v += mod - x.v) >= mod)\r\n            v -= mod;\r\n     \
    \   return *this;\r\n    }\r\n    fp &operator*=(const fp &x) {\r\n        v =\
    \ ll(v) * x.v % mod;\r\n        return *this;\r\n    }\r\n    fp &operator/=(const\
    \ fp &x) {\r\n        v = ll(v) * x.inv() % mod;\r\n        return *this;\r\n\
    \    }\r\n    fp operator+(const fp &x) const { return fp(*this) += x; }\r\n \
    \   fp operator-(const fp &x) const { return fp(*this) -= x; }\r\n    fp operator*(const\
    \ fp &x) const { return fp(*this) *= x; }\r\n    fp operator/(const fp &x) const\
    \ { return fp(*this) /= x; }\r\n    bool operator==(const fp &x) const { return\
    \ v == x.v; }\r\n    bool operator!=(const fp &x) const { return v != x.v; }\r\
    \n    friend istream &operator>>(istream &is, fp &x) { return is >> x.v; }\r\n\
    \    friend ostream &operator<<(ostream &os, const fp &x) { return os << x.v;\
    \ }\r\n};\r\n\r\ntemplate <typename T> T Inv(ll n) {\r\n    static const int md\
    \ = T::get_mod();\r\n    static vector<T> buf({0, 1});\r\n    assert(n > 0);\r\
    \n    n %= md;\r\n    while (SZ(buf) <= n) {\r\n        int k = SZ(buf), q = (md\
    \ + k - 1) / k;\r\n        buf.push_back(buf[k * q - md] * q);\r\n    }\r\n  \
    \  return buf[n];\r\n}\r\n\r\ntemplate <typename T> T Fact(ll n, bool inv = 0)\
    \ {\r\n    static const int md = T::get_mod();\r\n    static vector<T> buf({1,\
    \ 1}), ibuf({1, 1});\r\n    assert(n >= 0 and n < md);\r\n    while (SZ(buf) <=\
    \ n) {\r\n        buf.push_back(buf.back() * SZ(buf));\r\n        ibuf.push_back(ibuf.back()\
    \ * Inv<T>(SZ(ibuf)));\r\n    }\r\n    return inv ? ibuf[n] : buf[n];\r\n}\r\n\
    \r\ntemplate <typename T> T nPr(int n, int r, bool inv = 0) {\r\n    if (n < 0\
    \ || n < r || r < 0)\r\n        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(n\
    \ - r, inv ^ 1);\r\n}\r\ntemplate <typename T> T nCr(int n, int r, bool inv =\
    \ 0) {\r\n    if (n < 0 || n < r || r < 0)\r\n        return 0;\r\n    return\
    \ Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n - r, inv ^ 1);\r\n}\r\ntemplate\
    \ <typename T> T nHr(int n, int r, bool inv = 0) {\r\n    return nCr<T>(n + r\
    \ - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\n */\n#line 2 \"Math/matrix.hpp\"\
    \n\r\ntemplate<class T>struct Matrix{\r\n    int h,w; vector<vector<T>> val; T\
    \ det;\r\n    Matrix(){}\r\n    Matrix(int n):h(n),w(n),val(vector<vector<T>>(n,vector<T>(n))){}\r\
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
    \ Matrix\r\n */\n#line 3 \"Math/linearequation.hpp\"\n\r\ntemplate<typename T>pair<vector<T>,Matrix<T>>\
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
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_system_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_system_of_linear_equations.test.cpp
- /verify/Verify/LC_system_of_linear_equations.test.cpp.html
title: Verify/LC_system_of_linear_equations.test.cpp
---
