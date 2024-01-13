---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Verify/LC_point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\r\n\r\n\
    #line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \ constexpr int get_mod() { return mod; }\r\n    constexpr int inv() noexcept\
    \ {\r\n        assert(v != 0);\r\n        int x = v, y = mod, u = 1, v = 0, t\
    \ = 0, tmp = 0;\r\n        while (y > 0) {\r\n            t = x / y;\r\n     \
    \       x -= t * y, u -= t * v;\r\n            tmp = x, x = y, y = tmp;\r\n  \
    \          tmp = u, u = v, v = tmp;\r\n        }\r\n        return u;\r\n    }\r\
    \n    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod : (mod - (-x) % mod) % mod)\
    \ {}\r\n    fp operator-() const { return fp() - *this; }\r\n    fp pow(ll t)\
    \ {\r\n        assert(t >= 0);\r\n        fp res = 1, b = *this;\r\n        while\
    \ (t) {\r\n            if (t & 1)\r\n                res *= b;\r\n           \
    \ b *= b;\r\n            t >>= 1;\r\n        }\r\n        return res;\r\n    }\r\
    \n    fp &operator+=(const fp &x) {\r\n        if ((v += x.v) >= mod)\r\n    \
    \        v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator-=(const\
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
    \ - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\n */\n#line 2 \"DataStructure/segtree.hpp\"\
    \n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct\
    \ SegmentTree{\r\n    int n; vector<M> data;\r\n    SegmentTree(int _n=0){\r\n\
    \        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\n    }\r\n    void run(vector<M>&\
    \ v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\n        for(int\
    \ k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    void set(int\
    \ k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 6 \"Verify/LC_point_set_range_composite.test.cpp\"\
    \n\r\nusing Fp=fp<998244353>;\r\nusing P=array<Fp,2>;\r\nP f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}\r\
    \nP g(P a,P b){return b;}\r\nP e(){return P{1,0};}\r\n\r\nint main(){\r\n    int\
    \ N,Q;\r\n    cin>>N>>Q;\r\n    vector<int> a(N),b(N);\r\n    rep(i,0,N)cin>>a[i]>>b[i];\r\
    \n\r\n    SegmentTree<P,P,f,g,e> seg(N);\r\n    rep(i,0,N)seg.set(i,P{a[i],b[i]});\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int p,c,d;\r\n            cin>>p>>c>>d;\r\n            seg.set(p,P{c,d});\r\
    \n        }\r\n        else{\r\n            int L,R,x;\r\n            cin>>L>>R>>x;\r\
    \n            P ret=seg.query(L,R);\r\n            cout<<ret[0]*x+ret[1]<<'\\\
    n';\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"DataStructure/segtree.hpp\"\r\n\r\nusing Fp=fp<998244353>;\r\nusing\
    \ P=array<Fp,2>;\r\nP f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}\r\nP g(P\
    \ a,P b){return b;}\r\nP e(){return P{1,0};}\r\n\r\nint main(){\r\n    int N,Q;\r\
    \n    cin>>N>>Q;\r\n    vector<int> a(N),b(N);\r\n    rep(i,0,N)cin>>a[i]>>b[i];\r\
    \n\r\n    SegmentTree<P,P,f,g,e> seg(N);\r\n    rep(i,0,N)seg.set(i,P{a[i],b[i]});\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int p,c,d;\r\n            cin>>p>>c>>d;\r\n            seg.set(p,P{c,d});\r\
    \n        }\r\n        else{\r\n            int L,R,x;\r\n            cin>>L>>R>>x;\r\
    \n            P ret=seg.query(L,R);\r\n            cout<<ret[0]*x+ret[1]<<'\\\
    n';\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Verify/LC_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-01-14 02:07:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_point_set_range_composite.test.cpp
- /verify/Verify/LC_point_set_range_composite.test.cpp.html
title: Verify/LC_point_set_range_composite.test.cpp
---
