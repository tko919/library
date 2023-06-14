---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazysegtree.hpp
    title: Lazy Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Verify/LC_range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define\
    \ MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\n#define\
    \ LB(v,x) lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Math/modint.hpp\"\
    \n\r\ntemplate<int mod=1000000007>struct fp {\r\n    int v;\r\n    static constexpr\
    \ int get_mod(){return mod;}\r\n    int inv() const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\
    \n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\n        if(x<0){x+=mod;}\
    \ return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\n    fp& init(ll x){v=(x<mod?x:x-mod);\
    \ return *this;}\r\n    fp operator-()const{return fp()-*this;}\r\n    fp pow(ll\
    \ t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return\
    \ res;}\r\n    fp& operator+=(const fp& x){return init(v+x.v);}\r\n    fp& operator-=(const\
    \ fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const fp& x){v=ll(v)*x.v%mod;\
    \ return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return\
    \ *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\n    fp\
    \ operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\n\r\n/**\r\n * @brief Modint\r\n */\n\
    #line 2 \"DataStructure/lazysegtree.hpp\"\n\r\ntemplate<typename M,typename N,M\
    \ (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>\r\n    class LazySegmentTree{\r\
    \n    int sz,height;\r\n    vector<M> data;\r\n    vector<N> lazy;\r\n    void\
    \ update(int k){data[k]=f(data[k*2],data[k*2+1]);}\r\n    void apply(int k,N x){\r\
    \n        data[k]=g(data[k],x);\r\n        if(k<sz)lazy[k]=h(lazy[k],x);\r\n \
    \   }\r\n    void down(int k){\r\n        apply(k*2,lazy[k]);\r\n        apply(k*2+1,lazy[k]);\r\
    \n        lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int n=0):LazySegmentTree(vector<M>(n,m1())){}\r\
    \n    LazySegmentTree(const vector<M>& a){\r\n        sz=1,height=0;\r\n     \
    \   while(sz<(int)a.size())sz<<=1,height++;\r\n        data.assign(2*sz,m1());\r\
    \n        lazy.assign(sz,n1());\r\n        rep(i,0,a.size())data[sz+i]=a[i];\r\
    \n        for(int i=sz-1;i;i--)update(i);\r\n    }\r\n    void set(int k,M x){\r\
    \n        k+=sz;\r\n        for(int i=height;i;i--)down(k>>i);\r\n        data[k]=x;\r\
    \n        for(int i=1;i<=height;i++)update(k>>i);\r\n    }\r\n    void update(int\
    \ L,int R,N x){\r\n        if(L>=R)return;\r\n        L+=sz,R+=sz;\r\n       \
    \ for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\n  \
    \          if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        int lb=L,rb=R;\r\
    \n        while(L<R){\r\n            if(L&1)apply(L++,x);\r\n            if(R&1)apply(--R,x);\r\
    \n            L>>=1;\r\n            R>>=1;\r\n        }\r\n        L=lb,R=rb;\r\
    \n        for(int i=1;i<=height;i++){\r\n            if(((L>>i)<<i)!=L)update(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)update((R-1)>>i);\r\n        }\r\n    }\r\n  \
    \  M query(int L,int R){\r\n        if(L>=R)return m1();\r\n        L+=sz,R+=sz;\r\
    \n        for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        M lb=m1(),rb=m1();\r\
    \n        while(L<R){\r\n            if(L&1)lb=f(lb,data[L++]);\r\n          \
    \  if(R&1)rb=f(data[--R],rb);\r\n            L>>=1;\r\n            R>>=1;\r\n\
    \        }\r\n        return f(lb,rb);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Lazy Segment Tree\r\n */\n#line 6 \"Verify/LC_range_affine_range_sum.test.cpp\"\
    \n\r\nusing Fp=fp<998244353>;\r\nusing P=array<Fp,2>;\r\nP f(P a,P b){return P{a[0]+b[0],a[1]+b[1]};}\r\
    \nP g(P a,P b){return P{a[0]*b[0]+a[1]*b[1],a[1]};}\r\nP h(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}\r\
    \nP e1(){return P{0,0};}\r\nP e2(){return P{1,0};}\r\n\r\nint main(){\r\n    int\
    \ N,Q;\r\n    cin>>N>>Q;\r\n    vector<int> a(N);\r\n    rep(i,0,N)cin>>a[i];\r\
    \n\r\n    LazySegmentTree<P,P,f,g,h,e1,e2> seg(N);\r\n    rep(i,0,N)seg.set(i,P{a[i],1});\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int L,R,c,d;\r\n            cin>>L>>R>>c>>d;\r\n            seg.update(L,R,P{c,d});\r\
    \n        }\r\n        else{\r\n            int L,R;\r\n            cin>>L>>R;\r\
    \n            P ret=seg.query(L,R);\r\n            cout<<ret[0]<<'\\n';\r\n  \
    \      }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"DataStructure/lazysegtree.hpp\"\r\n\r\nusing Fp=fp<998244353>;\r\n\
    using P=array<Fp,2>;\r\nP f(P a,P b){return P{a[0]+b[0],a[1]+b[1]};}\r\nP g(P\
    \ a,P b){return P{a[0]*b[0]+a[1]*b[1],a[1]};}\r\nP h(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}\r\
    \nP e1(){return P{0,0};}\r\nP e2(){return P{1,0};}\r\n\r\nint main(){\r\n    int\
    \ N,Q;\r\n    cin>>N>>Q;\r\n    vector<int> a(N);\r\n    rep(i,0,N)cin>>a[i];\r\
    \n\r\n    LazySegmentTree<P,P,f,g,h,e1,e2> seg(N);\r\n    rep(i,0,N)seg.set(i,P{a[i],1});\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int L,R,c,d;\r\n            cin>>L>>R>>c>>d;\r\n            seg.update(L,R,P{c,d});\r\
    \n        }\r\n        else{\r\n            int L,R;\r\n            cin>>L>>R;\r\
    \n            P ret=seg.query(L,R);\r\n            cout<<ret[0]<<'\\n';\r\n  \
    \      }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - DataStructure/lazysegtree.hpp
  isVerificationFile: true
  path: Verify/LC_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_range_affine_range_sum.test.cpp
- /verify/Verify/LC_range_affine_range_sum.test.cpp.html
title: Verify/LC_range_affine_range_sum.test.cpp
---
