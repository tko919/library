---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/nimber.hpp
    title: Nimber
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
    PROBLEM: https://judge.yosupo.jp/problem/nim_product_64
    links:
    - https://judge.yosupo.jp/problem/nim_product_64
  bundledCode: "#line 1 \"Verify/LC_nim_product_64.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/nim_product_64\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i, a, b)\
    \ for (int i = (int)(a); i < (int)(b); i++)\r\n#define rrep(i, a, b) for (int\
    \ i = (int)(b-1); i >= (int)(a); i--)\r\n#define ALL(v) (v).begin(), (v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\r\n#define\
    \ SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v)\
    \ *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())\r\
    \n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\n\r\nusing uint\
    \ = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned long long;\r\
    \nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate <typename T> inline bool\
    \ chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a = b;\r\n        return 1;\r\
    \n    }\r\n    return 0;\r\n}\r\ntemplate <typename T> inline bool chmin(T &a,\
    \ T b) {\r\n    if (a > b) {\r\n        a = b;\r\n        return 1;\r\n    }\r\
    \n    return 0;\r\n}\r\ntemplate <typename T, typename U> T ceil(T x, U y) {\r\
    \n    assert(y != 0);\r\n    if (y < 0)\r\n        x = -x, y = -y;\r\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate <typename T, typename U>\
    \ T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x =\
    \ -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1) / y);\r\n}\r\ntemplate\
    \ <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\n}\r\
    \ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63 - __builtin_clzll(x));\r\
    \n}\r\ntemplate <typename T> int lowbit(T x) {\r\n    return (x == 0 ? -1 : __builtin_ctzll(x));\r\
    \n}\r\n\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename T> void _show(int\
    \ i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename T1, typename T2,\
    \ typename... T3>\r\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c)\
    \ {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\
    \n    cerr << \":\" << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\r\ntemplate\
    \ <class T, class U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p)\
    \ {\r\n    os << \"P(\" << p.first << \", \" << p.second << \")\";\r\n    return\
    \ os;\r\n}\r\ntemplate <typename T, template <class> class C>\r\nostream &operator<<(ostream\
    \ &os, const C<T> &v) {\r\n    os << \"[\";\r\n    for (auto d : v)\r\n      \
    \  os << d << \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"Math/nimber.hpp\"\
    \n\r\nusing ull=unsigned long long;\r\nstruct NimberManager{\r\n    ull memo[256][256];\r\
    \n    NimberManager(){\r\n        rep(i,0,256)rep(j,0,256)memo[i][j]=256;\r\n\
    \        memo[0][0]=memo[0][1]=memo[1][0]=0;\r\n        memo[1][1]=1;\r\n    \
    \    rep(i,0,256)rep(j,0,256)memo[i][j]=mul(i,j,8);\r\n    }\r\n    ull mul(ull\
    \ x,ull y,int k=64){\r\n        if(k<=8&&memo[x][y]<256)return memo[x][y];\r\n\
    \        k>>=1;\r\n        ull a=x>>k,b=x^(a<<k),c=y>>k,d=y^(c<<k);\r\n      \
    \  ull ac=mul(a,c,k),bd=mul(b,d,k),abcd=mul(a^b,c^d,k);\r\n        return mul(ac,1ull<<(k-1),k)^(abcd^bd)<<k^bd;\r\
    \n    }\r\n};\r\nNimberManager Nim;\r\nstruct Nimber{\r\n    ull v;\r\n    Nimber(ull\
    \ _v=0):v(_v){}\r\n    Nimber& operator+=(const Nimber& x){v^=x.v; return *this;}\r\
    \n    Nimber& operator-=(const Nimber& x){v^=x.v; return *this;}\r\n    Nimber&\
    \ operator*=(const Nimber& x){v=Nim.mul(v,x.v); return *this;}\r\n    Nimber operator+(const\
    \ Nimber& x)const{return Nimber(*this)+=x;}\r\n    Nimber operator-(const Nimber&\
    \ x)const{return Nimber(*this)-=x;}\r\n    Nimber operator*(const Nimber& x)const{return\
    \ Nimber(*this)*=x;}\r\n    bool operator==(const Nimber& x)const{return v==x.v;}\r\
    \n    bool operator!=(const Nimber& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,Nimber& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const Nimber& x){return os<<x.v;}\r\n};\r\n\r\n/**\r\n * @brief Nimber\r\n\
    \ */\n#line 5 \"Verify/LC_nim_product_64.test.cpp\"\n\r\nint main(){\r\n    int\
    \ t;\r\n    cin>>t;\r\n    while(t--){\r\n        Nimber a,b;\r\n        cin>>a>>b;\r\
    \n        cout<<a*b<<'\\n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\r\n\r\n\
    #include \"Template/template.hpp\"\r\n#include \"Math/nimber.hpp\"\r\n\r\nint\
    \ main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        Nimber a,b;\r\
    \n        cin>>a>>b;\r\n        cout<<a*b<<'\\n';\r\n    }\r\n    return 0;\r\n\
    }"
  dependsOn:
  - Template/template.hpp
  - Math/nimber.hpp
  isVerificationFile: true
  path: Verify/LC_nim_product_64.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_nim_product_64.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_nim_product_64.test.cpp
- /verify/Verify/LC_nim_product_64.test.cpp.html
title: Verify/LC_nim_product_64.test.cpp
---
