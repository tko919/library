---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"Verify/LC_vertex_set_path_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\r\n\r\n\
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
    \ constexpr int get_mod() { return mod; }\r\n    constexpr int inv() const {\r\
    \n        assert(v != 0);\r\n        int x = v, y = mod, u = 1, v = 0, t = 0,\
    \ tmp = 0;\r\n        while (y > 0) {\r\n            t = x / y;\r\n          \
    \  x -= t * y, u -= t * v;\r\n            tmp = x, x = y, y = tmp;\r\n       \
    \     tmp = u, u = v, v = tmp;\r\n        }\r\n        if (u < 0)\r\n        \
    \    u += mod;\r\n        return u;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x\
    \ >= 0 ? x % mod : (mod - (-x) % mod) % mod) {}\r\n    fp operator-() const {\
    \ return fp() - *this; }\r\n    fp pow(ll t) {\r\n        assert(t >= 0);\r\n\
    \        fp res = 1, b = *this;\r\n        while (t) {\r\n            if (t &\
    \ 1)\r\n                res *= b;\r\n            b *= b;\r\n            t >>=\
    \ 1;\r\n        }\r\n        return res;\r\n    }\r\n    fp &operator+=(const\
    \ fp &x) {\r\n        if ((v += x.v) >= mod)\r\n            v -= mod;\r\n    \
    \    return *this;\r\n    }\r\n    fp &operator-=(const fp &x) {\r\n        if\
    \ ((v += mod - x.v) >= mod)\r\n            v -= mod;\r\n        return *this;\r\
    \n    }\r\n    fp &operator*=(const fp &x) {\r\n        v = ll(v) * x.v % mod;\r\
    \n        return *this;\r\n    }\r\n    fp &operator/=(const fp &x) {\r\n    \
    \    v = ll(v) * x.inv() % mod;\r\n        return *this;\r\n    }\r\n    fp operator+(const\
    \ fp &x) const { return fp(*this) += x; }\r\n    fp operator-(const fp &x) const\
    \ { return fp(*this) -= x; }\r\n    fp operator*(const fp &x) const { return fp(*this)\
    \ *= x; }\r\n    fp operator/(const fp &x) const { return fp(*this) /= x; }\r\n\
    \    bool operator==(const fp &x) const { return v == x.v; }\r\n    bool operator!=(const\
    \ fp &x) const { return v != x.v; }\r\n    friend istream &operator>>(istream\
    \ &is, fp &x) { return is >> x.v; }\r\n    friend ostream &operator<<(ostream\
    \ &os, const fp &x) { return os << x.v; }\r\n};\r\n\r\ntemplate <typename T> T\
    \ Inv(ll n) {\r\n    static const int md = T::get_mod();\r\n    static vector<T>\
    \ buf({0, 1});\r\n    assert(n > 0);\r\n    n %= md;\r\n    while (SZ(buf) <=\
    \ n) {\r\n        int k = SZ(buf), q = (md + k - 1) / k;\r\n        buf.push_back(buf[k\
    \ * q - md] * q);\r\n    }\r\n    return buf[n];\r\n}\r\n\r\ntemplate <typename\
    \ T> T Fact(ll n, bool inv = 0) {\r\n    static const int md = T::get_mod();\r\
    \n    static vector<T> buf({1, 1}), ibuf({1, 1});\r\n    assert(n >= 0 and n <\
    \ md);\r\n    while (SZ(buf) <= n) {\r\n        buf.push_back(buf.back() * SZ(buf));\r\
    \n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\r\n    }\r\n    return\
    \ inv ? ibuf[n] : buf[n];\r\n}\r\n\r\ntemplate <typename T> T nPr(int n, int r,\
    \ bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\n        return 0;\r\n\
    \    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\r\n}\r\ntemplate <typename\
    \ T> T nCr(int n, int r, bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\
    \n        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n\
    \ - r, inv ^ 1);\r\n}\r\ntemplate <typename T> T nHr(int n, int r, bool inv =\
    \ 0) {\r\n    return nCr<T>(n + r - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\
    \n */\n#line 2 \"Graph/hld.hpp\"\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\
    \n    vector<vector<int>> g; vector<int> sz,in,out,rev,hs,par,dist;\r\n    void\
    \ dfs(int v,int p){\r\n        par[v]=p; sz[v]=1;\r\n        if(p!=-1)dist[v]=dist[p]+1;\r\
    \n        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\n     \
    \   for(auto& to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\n \
    \          if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\n        }\r\n    }\r\n \
    \   void dfs2(int v,int p,int& k){\r\n        in[v]=k++; rev[in[v]]=v;\r\n   \
    \     for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
    \n            dfs2(to,v,k);\r\n        }\r\n        out[v]=k;\r\n    }\r\n   \
    \ HLD(int _n):g(_n),sz(_n),in(_n),out(_n),rev(_n),hs(_n),par(_n),dist(_n){}\r\n\
    \    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n    }\r\n    void run(int rt=0){dfs(rt,-1); hs[rt]=rt; int k=0; dfs2(rt,-1,k);}\r\
    \n    int lca(int u,int v){\r\n        for(;;v=par[hs[v]]){\r\n            if(in[u]>in[v])swap(u,v);\r\
    \n            if(hs[u]==hs[v])return u;\r\n        }\r\n    }\r\n    vector<P>\
    \ get(int u,int p,bool es=0){\r\n        assert(in[p]<=in[u] and out[u]<=out[p]);\r\
    \n        vector<P> res;\r\n        while(hs[u]!=hs[p]){\r\n            res.push_back({in[hs[u]],in[u]+1});\r\
    \n            u=par[hs[u]];\r\n        }\r\n        res.push_back({in[p]+es,in[u]+1});\r\
    \n        return res;\r\n    }\r\n    int jump(int u,int v,int k){\r\n       \
    \ if(k<0)return -1;\r\n        int g=lca(u,v);\r\n        int d0=dist[u]+dist[v]-dist[g]*2;\r\
    \n        if(d0<k)return -1;\r\n        int st=u;\r\n        if(dist[u]-dist[g]<k)st=v,k=d0-k;\r\
    \n        for(;;){\r\n            int to=hs[st];\r\n            if(in[st]-k>=in[to])return\
    \ rev[in[st]-k];\r\n            k-=in[st]-in[to]+1; st=par[to];\r\n        }\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\n */\n#line\
    \ 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate<typename M,typename N,M (*f)(M,M),M\
    \ (*g)(M,N),M (*m1)()>struct SegmentTree{\r\n    int n; vector<M> data;\r\n  \
    \  SegmentTree(int _n=0){\r\n        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\
    \n    }\r\n    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\
    \n        for(int k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 7 \"Verify/LC_vertex_set_path_composite.test.cpp\"\
    \n\r\nusing Fp=fp<998244353>;\r\nusing P=array<Fp,2>;\r\nP f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}\r\
    \nstruct X{\r\n    P base,rev;\r\n    X(Fp a=1,Fp b=0):base({a,b}),rev({a,b}){}\r\
    \n};\r\nX f(X a,X b){\r\n    X ret;\r\n    ret.base=f(a.base,b.base);\r\n    ret.rev=f(b.rev,a.rev);\r\
    \n    return ret; \r\n}\r\nX g(X a,X b){return b;}\r\nX e(){return X();}\r\n\r\
    \nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<X> A(N);\r\n   \
    \ rep(i,0,N){\r\n        int a,b;\r\n        cin>>a>>b;\r\n        A[i]=X(a,b);\r\
    \n    }\r\n    HLD hld(N);\r\n    rep(_,0,N-1){\r\n        int x,y;\r\n      \
    \  cin>>x>>y;\r\n        hld.add_edge(x,y);\r\n    }\r\n    hld.run();\r\n\r\n\
    \    SegmentTree<X,X,f,g,e> seg(N);\r\n    rep(i,0,N)seg.update(hld.in[i],A[i]);\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int p,c,d;\r\n            cin>>p>>c>>d;\r\n            seg.update(hld.in[p],X{c,d});\r\
    \n        }\r\n        else{\r\n            int u,v,x;\r\n            cin>>u>>v>>x;\r\
    \n            int lca=hld.lca(u,v);\r\n            auto ps=hld.get(u,lca);\r\n\
    \            P ret=P{1,0},add=P{1,0};\r\n            for(auto& [L,R]:ps)ret=f(ret,seg.query(L,R).rev);\r\
    \n            ps=hld.get(v,lca,1);\r\n            for(auto& [L,R]:ps)add=f(seg.query(L,R).base,add);\r\
    \n            ret=f(ret,add);\r\n            cout<<ret[0]*x+ret[1]<<'\\n';\r\n\
    \        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"Graph/hld.hpp\"\r\n#include \"DataStructure/segtree.hpp\"\r\n\r\nusing\
    \ Fp=fp<998244353>;\r\nusing P=array<Fp,2>;\r\nP f(P a,P b){return P{a[0]*b[0],a[1]*b[0]+b[1]};}\r\
    \nstruct X{\r\n    P base,rev;\r\n    X(Fp a=1,Fp b=0):base({a,b}),rev({a,b}){}\r\
    \n};\r\nX f(X a,X b){\r\n    X ret;\r\n    ret.base=f(a.base,b.base);\r\n    ret.rev=f(b.rev,a.rev);\r\
    \n    return ret; \r\n}\r\nX g(X a,X b){return b;}\r\nX e(){return X();}\r\n\r\
    \nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<X> A(N);\r\n   \
    \ rep(i,0,N){\r\n        int a,b;\r\n        cin>>a>>b;\r\n        A[i]=X(a,b);\r\
    \n    }\r\n    HLD hld(N);\r\n    rep(_,0,N-1){\r\n        int x,y;\r\n      \
    \  cin>>x>>y;\r\n        hld.add_edge(x,y);\r\n    }\r\n    hld.run();\r\n\r\n\
    \    SegmentTree<X,X,f,g,e> seg(N);\r\n    rep(i,0,N)seg.update(hld.in[i],A[i]);\r\
    \n    while(Q--){\r\n        int t;\r\n        cin>>t;\r\n        if(t==0){\r\n\
    \            int p,c,d;\r\n            cin>>p>>c>>d;\r\n            seg.update(hld.in[p],X{c,d});\r\
    \n        }\r\n        else{\r\n            int u,v,x;\r\n            cin>>u>>v>>x;\r\
    \n            int lca=hld.lca(u,v);\r\n            auto ps=hld.get(u,lca);\r\n\
    \            P ret=P{1,0},add=P{1,0};\r\n            for(auto& [L,R]:ps)ret=f(ret,seg.query(L,R).rev);\r\
    \n            ps=hld.get(v,lca,1);\r\n            for(auto& [L,R]:ps)add=f(seg.query(L,R).base,add);\r\
    \n            ret=f(ret,add);\r\n            cout<<ret[0]*x+ret[1]<<'\\n';\r\n\
    \        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - Graph/hld.hpp
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Verify/LC_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-01-14 02:40:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_vertex_set_path_composite.test.cpp
- /verify/Verify/LC_vertex_set_path_composite.test.cpp.html
title: Verify/LC_vertex_set_path_composite.test.cpp
---
