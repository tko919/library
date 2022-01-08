---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazysegtree.hpp
    title: Lazy Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Verify/LC_range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp\
    \ {\r\n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\n\
    \        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
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
    \n * @brief Modint\r\n */\n#line 2 \"DataStructure/lazysegtree.hpp\"\n\r\ntemplate<typename\
    \ M,typename N\r\n    ,M (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>\r\
    \nclass LazySegmentTree{\r\n    int sz,height; vector<M> data; vector<N> lazy;\r\
    \n    M ref(int k){return g(data[k],lazy[k]);}\r\n    void recalc(int k){while(k>>=1)data[k]=f(ref(2*k),ref(2*k+1));}\r\
    \n    void thrust(int k){for(int i=height;i>0;i--)eval(k>>i);}\r\n    void eval(int\
    \ k){\r\n        lazy[2*k]=h(lazy[2*k],lazy[k]); lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\r\
    \n        data[k]=ref(k); lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int\
    \ n){\r\n        sz=1,height=0; while(sz<n)sz<<=1,height++;\r\n        data.assign(2*sz,m1());\
    \ lazy.assign(2*sz,n1());\r\n    }\r\n    void run(vector<M>& v){\r\n        rep(i,0,v.size())data[i+sz]=v[i];\r\
    \n        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int a,M x){thrust(a+=sz); data[a]=x; recalc(a);}\r\n    void update(int\
    \ a,int b,N x){\r\n        if(a>=b)return;\r\n        thrust(a+=sz); thrust(b+=sz-1);\r\
    \n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\r\n            if(l&1)lazy[l]=h(lazy[l],x),++l;\r\
    \n            if(r&1)--r,lazy[r]=h(lazy[r],x);\r\n        }\r\n        recalc(a);\
    \ recalc(b);\r\n    }\r\n    M query(int a,int b){\r\n        if(a>=b)return m1();\r\
    \n        thrust(a+=sz); thrust(b+=sz-1);\r\n        M L=m1(),R=m1();\r\n    \
    \    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\r\n            if(l&1)L=f(L,ref(l++));\r\
    \n            if(r&1)R=f(ref(--r),R);\r\n        } return f(L,R);\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Lazy Segment Tree\r\n */\n#line 6 \"Verify/LC_range_affine_range_sum.test.cpp\"\
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
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_range_affine_range_sum.test.cpp
- /verify/Verify/LC_range_affine_range_sum.test.cpp.html
title: Verify/LC_range_affine_range_sum.test.cpp
---
