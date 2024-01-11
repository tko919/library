---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: FPS/berlekampmassey.hpp
    title: Berlekamp Massey Algorithm
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"Verify/LC_find_linear_recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define\
    \ SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v)\
    \ *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
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
    \ constexpr int get_mod() { return mod; }\r\n    constexpr int inv() const {\r\
    \n        int tmp, a = v, b = mod, x = 1, y = 0;\r\n        while (b)\r\n    \
    \        tmp = a / b, a -= tmp * b, swap(a, b), x -= tmp * y, swap(x, y);\r\n\
    \        if (x < 0) {\r\n            x += mod;\r\n        }\r\n        return\
    \ x;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x)\
    \ % mod) % mod) {}\r\n    fp operator-() const { return fp() - *this; }\r\n  \
    \  fp pow(ll t) {\r\n        assert(t >= 0);\r\n        fp res = 1, b = *this;\r\
    \n        while (t) {\r\n            if (t & 1)\r\n                res *= b;\r\
    \n            b *= b;\r\n            t >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n    fp &operator+=(const fp &x) {\r\n        if ((v += x.v) >= mod)\r\
    \n            v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator-=(const\
    \ fp &x) {\r\n        if ((v += mod - x.v) >= mod)\r\n            v -= mod;\r\n\
    \        return *this;\r\n    }\r\n    fp &operator*=(const fp &x) {\r\n     \
    \   v = ll(v) * x.v % mod;\r\n        return *this;\r\n    }\r\n    fp &operator/=(const\
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
    \ - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\n */\n#line 2 \"FPS/berlekampmassey.hpp\"\
    \n\r\ntemplate<typename T>vector<T> BerlekampMassey(vector<T>& a){\r\n   int n=a.size();\
    \ T d=1;\r\n   vector<T> b(1),c(1);\r\n   b[0]=c[0]=1;\r\n   rep(j,1,n+1){\r\n\
    \      int l=c.size(),m=b.size();\r\n      T x=0;\r\n      rep(i,0,l)x+=c[i]*a[j-l+i];\r\
    \n      b.push_back(0);\r\n      m++;\r\n      if(x==0)continue;\r\n      T coeff=-x/d;\r\
    \n      if(l<m){\r\n         auto tmp=c;\r\n         c.insert(c.begin(),m-l,0);\r\
    \n         rep(i,0,m)c[m-1-i]+=coeff*b[m-1-i];\r\n         b=tmp; d=x;\r\n   \
    \   }\r\n      else rep(i,0,m)c[l-1-i]+=coeff*b[m-1-i];\r\n   }\r\n   return c;\r\
    \n}\r\n\r\n/**\r\n * @brief Berlekamp Massey Algorithm\r\n */\n#line 6 \"Verify/LC_find_linear_recurrence.test.cpp\"\
    \n\r\nusing Fp=fp<998244353>;\r\n\r\nint main(){\r\n    int n;\r\n    cin>>n;\r\
    \n    vector<Fp> a(n);\r\n    rep(i,0,n)cin>>a[i];\r\n\r\n    auto ret=BerlekampMassey(a);\r\
    \n    ret.pop_back();\r\n    reverse(ALL(ret));\r\n    for(auto& x:ret)x=-x;\r\
    \n\r\n    int m=ret.size();\r\n    cout<<m<<'\\n';\r\n    rep(i,0,m)cout<<ret[i]<<(i==m-1?'\\\
    n':' ');\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"FPS/berlekampmassey.hpp\"\r\n\r\nusing Fp=fp<998244353>;\r\n\r\nint\
    \ main(){\r\n    int n;\r\n    cin>>n;\r\n    vector<Fp> a(n);\r\n    rep(i,0,n)cin>>a[i];\r\
    \n\r\n    auto ret=BerlekampMassey(a);\r\n    ret.pop_back();\r\n    reverse(ALL(ret));\r\
    \n    for(auto& x:ret)x=-x;\r\n\r\n    int m=ret.size();\r\n    cout<<m<<'\\n';\r\
    \n    rep(i,0,m)cout<<ret[i]<<(i==m-1?'\\n':' ');\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - FPS/berlekampmassey.hpp
  isVerificationFile: true
  path: Verify/LC_find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 05:13:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_find_linear_recurrence.test.cpp
- /verify/Verify/LC_find_linear_recurrence.test.cpp.html
title: Verify/LC_find_linear_recurrence.test.cpp
---
