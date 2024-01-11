---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/fft.hpp
    title: Fast Fourier Transform
  - icon: ':question:'
    path: Graph/centroid.hpp
    title: Centroid Decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"Verify/LC_frequency_table_of_tree_distance.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Convolution/fft.hpp\"\
    \n\r\nnamespace FFT{\r\n    struct C{\r\n        double x,y;\r\n        C(double\
    \ _x=0,double _y=0):x(_x),y(_y){}\r\n        C operator~()const{return C(x,-y);}\r\
    \n        C operator*(const C& c)const{return C(x*c.x-y*c.y,x*c.y+y*c.x);}\r\n\
    \        C operator+(const C& c)const{return C(x+c.x,y+c.y);}\r\n        C operator-(const\
    \ C& c)const{return C(x-c.x,y-c.y);}\r\n    };\r\n    vector<vector<C>> w(1,vector<C>(1,1));\r\
    \n    void init(int lg){\r\n        for(int d=1,m=1;d<=lg;d++,m<<=1)if(d>=(int)w.size()){\r\
    \n             w.emplace_back(m);\r\n             const double th=M_PI/m;\r\n\
    \             for(int i=0;i<m;i++)w[d][i]=(i&1?C(cos(th*i),sin(th*i)):w[d-1][i>>1]);\r\
    \n        }\r\n    }\r\n    void fft(vector<C>& f,bool inv){\r\n        const\
    \ int n=f.size(); const int lg=__lg(n);\r\n        if(lg>=(int)w.size())init(lg);\r\
    \n        if(inv){\r\n            for(int k=1;k<=lg;k++){\r\n                const\
    \ int d=1<<(k-1);\r\n                for(int s=0;s<n;s+=2*d){\r\n            \
    \        for(int i=s;i<s+d;i++){\r\n                        C x=f[i],y=~w[k][i-s]*f[d+i];\r\
    \n                        f[i]=x+y; f[d+i]=x-y;\r\n                    }\r\n \
    \               }\r\n            }\r\n         }\r\n         else{\r\n       \
    \      for(int k=lg;k;k--){\r\n                 const int d=1<<(k-1);\r\n    \
    \             for(int s=0;s<n;s+=2*d){\r\n                     for(int i=s;i<s+d;i++){\r\
    \n                         C x=f[i],y=f[d+i];\r\n                         f[i]=x+y;\
    \ f[d+i]=w[k][i-s]*(x-y);\r\n                     }\r\n                 }\r\n\
    \             }\r\n         }\r\n    }\r\n    template<typename T>vector<T> mult(const\
    \ vector<T>& a,const vector<T>& b){\r\n        const int as=a.size(); const int\
    \ bs=b.size(); \r\n        if(!as or !bs)return {};\r\n        const int cs=as+bs-1;\
    \ vector<T> c(cs);\r\n        if(max(as,bs)<16){\r\n            for(int i=0;i<as;i++)for(int\
    \ j=0;j<bs;j++){\r\n                c[i+j]+=(int)a[i]*b[j];\r\n            }\r\
    \n            return c;\r\n        }\r\n        const int n=1<<__lg(2*cs-1); vector<C>\
    \ f(n);\r\n        for(int i=0;i<as;i++)f[i].x=a[i];\r\n        for(int i=0;i<bs;i++)f[i].y=b[i];\r\
    \n        fft(f,0); static const C rad(0,-.25);\r\n        for(int i=0;i<n;i++){\r\
    \n            int j=i?i^((1<<__lg(i))-1):0;\r\n            if(i>j)continue;\r\n\
    \            C x=f[i]+~f[j],y=f[i]-~f[j];\r\n            f[i]=x*y*rad; f[j]=~f[i];\r\
    \n        }\r\n        fft(f,1); for(int i=0;i<cs;i++)c[i]=round(f[i].x/n);\r\n\
    \        return c;\r\n    }\r\n    template<typename T>vector<T> square(const\
    \ vector<T>& a){\r\n        const int as=a.size(); if(!as)return {};\r\n     \
    \   const int cs=as*2-1; vector<T> c(cs);\r\n        if(as<16){\r\n          \
    \  for(int i=0;i<as;i++)for(int j=0;j<as;j++){\r\n                c[i+j]+=(int)a[i]*a[j];\r\
    \n            }\r\n            return c;\r\n        }\r\n        const int n=1<<__lg(cs*2-1);\
    \ vector<C> f(n);\r\n        for(int i=0;i<as;i++)f[i].x=a[i];\r\n        fft(f,0);\
    \ for(int i=0;i<n;i++)f[i]=f[i]*f[i];\r\n        fft(f,1); for(int i=0;i<cs;i++)c[i]=round(f[i].x/n);\r\
    \n        return c;\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Fast Fourier Transform\r\
    \n */\n#line 2 \"Graph/centroid.hpp\"\n\r\nclass CentroidDecomposition{\r\n  \
    \  void get(int v,int p){\r\n        sz[v]=1;\r\n        for(auto& to:g[v])if(to!=p\
    \ and !used[to]){\r\n            get(to,v);\r\n            sz[v]+=sz[to];\r\n\
    \        }\r\n    }\r\n    int dfs(int v,int p,int rt){\r\n        for(auto& to:g[v])if(to!=p\
    \ and !used[to]){\r\n            if(sz[to]>(sz[rt]>>1))return dfs(to,v,rt);\r\n\
    \        }\r\n        return v;\r\n    }\r\npublic:\r\n    int n;\r\n    vector<vector<int>>\
    \ g;\r\n    vector<int> sz,used;\r\n    CentroidDecomposition(int n_):n(n_),g(n),sz(n),used(n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    int find(int rt){\r\n        get(rt,-1);\r\n        int res=dfs(rt,-1,rt);\r\
    \n        used[res]=1;\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n *\
    \ @brief Centroid Decomposition\r\n */\n#line 6 \"Verify/LC_frequency_table_of_tree_distance.test.cpp\"\
    \n\r\nint main(){\r\n    int n;\r\n    cin>>n;\r\n    CentroidDecomposition cd(n);\r\
    \n    rep(i,0,n-1){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        cd.add_edge(x,y);\r\
    \n    }\r\n    vector<ll> ret(n);\r\n\r\n    auto rec=[&](auto& _rec,int rt)->void{\r\
    \n        int cen=cd.find(rt);\r\n        for(auto& to:cd.g[cen])if(!cd.used[to])_rec(_rec,to);\r\
    \n        vector<ll> sum,cur;\r\n        auto dfs=[&](auto& f,int v,int p,int\
    \ d)->void{\r\n            if((int)cur.size()<=d)cur.resize(d+1);\r\n        \
    \    cur[d]++;\r\n            for(auto& to:cd.g[v])if(to!=p and !cd.used[to])f(f,to,v,d+1);\r\
    \n        };\r\n        for(auto& to:cd.g[cen])if(!cd.used[to]){\r\n         \
    \   cur.clear();\r\n            dfs(dfs,to,cen,1);\r\n            auto sub=FFT::square(cur);\r\
    \n            rep(i,0,min((int)sub.size(),n))ret[i]-=sub[i];\r\n            if(sum.size()<cur.size())sum.resize(cur.size());\r\
    \n            rep(i,0,cur.size())sum[i]+=cur[i];\r\n        }\r\n        rep(i,0,min((int)sum.size(),n))ret[i]+=sum[i]*2;\r\
    \n        auto add=FFT::square(sum);\r\n        rep(i,0,min((int)add.size(),n))ret[i]+=add[i];\r\
    \n        cd.used[cen]=0;\r\n    };\r\n    rec(rec,0);\r\n    rep(i,1,n){\r\n\
    \        ret[i]>>=1;\r\n        cout<<ret[i]<<'\\n';\r\n    }\r\n    return 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Convolution/fft.hpp\"\
    \r\n#include \"Graph/centroid.hpp\"\r\n\r\nint main(){\r\n    int n;\r\n    cin>>n;\r\
    \n    CentroidDecomposition cd(n);\r\n    rep(i,0,n-1){\r\n        int x,y;\r\n\
    \        cin>>x>>y;\r\n        cd.add_edge(x,y);\r\n    }\r\n    vector<ll> ret(n);\r\
    \n\r\n    auto rec=[&](auto& _rec,int rt)->void{\r\n        int cen=cd.find(rt);\r\
    \n        for(auto& to:cd.g[cen])if(!cd.used[to])_rec(_rec,to);\r\n        vector<ll>\
    \ sum,cur;\r\n        auto dfs=[&](auto& f,int v,int p,int d)->void{\r\n     \
    \       if((int)cur.size()<=d)cur.resize(d+1);\r\n            cur[d]++;\r\n  \
    \          for(auto& to:cd.g[v])if(to!=p and !cd.used[to])f(f,to,v,d+1);\r\n \
    \       };\r\n        for(auto& to:cd.g[cen])if(!cd.used[to]){\r\n           \
    \ cur.clear();\r\n            dfs(dfs,to,cen,1);\r\n            auto sub=FFT::square(cur);\r\
    \n            rep(i,0,min((int)sub.size(),n))ret[i]-=sub[i];\r\n            if(sum.size()<cur.size())sum.resize(cur.size());\r\
    \n            rep(i,0,cur.size())sum[i]+=cur[i];\r\n        }\r\n        rep(i,0,min((int)sum.size(),n))ret[i]+=sum[i]*2;\r\
    \n        auto add=FFT::square(sum);\r\n        rep(i,0,min((int)add.size(),n))ret[i]+=add[i];\r\
    \n        cd.used[cen]=0;\r\n    };\r\n    rec(rec,0);\r\n    rep(i,1,n){\r\n\
    \        ret[i]>>=1;\r\n        cout<<ret[i]<<'\\n';\r\n    }\r\n    return 0;\r\
    \n}"
  dependsOn:
  - Template/template.hpp
  - Convolution/fft.hpp
  - Graph/centroid.hpp
  isVerificationFile: true
  path: Verify/LC_frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_frequency_table_of_tree_distance.test.cpp
- /verify/Verify/LC_frequency_table_of_tree_distance.test.cpp.html
title: Verify/LC_frequency_table_of_tree_distance.test.cpp
---
