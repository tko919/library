---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtreebeats.hpp
    title: Segment Tree Beats
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"Verify/LC_range_chmin_chmax_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\r\
    \n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Utility/fastio.hpp\"\n#include\
    \ <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\n   \
    \ char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
    \n        int len=rdRight-rdLeft;\r\n        memmove(rdbuf,rdbuf+rdLeft,len);\r\
    \n        rdLeft=0,rdRight=len;\r\n        rdRight+=fread(rdbuf+len,1,L-len,stdin);\r\
    \n    }\r\n    inline bool skip(){\r\n        for(;;){\r\n            while(rdLeft!=rdRight\
    \ and rdbuf[rdLeft]<=' ')rdLeft++;\r\n            if(rdLeft==rdRight){\r\n   \
    \             reload();\r\n                if(rdLeft==rdRight)return false;\r\n\
    \            }\r\n            else break;\r\n        }\r\n        return true;\r\
    \n    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0')x=x*10+(rdbuf[rdLeft++]^48);\r\
    \n        if(neg)x=-x;\r\n        return true;\r\n    }\r\n    template<typename\
    \ T,enable_if_t<is_floating_point<T>::value,int> =0>inline bool _read(T& x){\r\
    \n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9')x=x*10+(rdbuf[rdLeft++]^48);\r\n        if(rdbuf[rdLeft]!='.')return\
    \ true;\r\n        rdLeft++;\r\n        T base=.1;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9'){\r\n            x+=base*(rdbuf[rdLeft++]^48);\r\n  \
    \          base*=.1;\r\n        }\r\n        if(neg)x=-x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char& x){\r\n        if(!skip())return false;\r\
    \n        if(rdLeft+1>=rdRight)reload();\r\n        x=rdbuf[rdLeft++];\r\n   \
    \     return true;\r\n    }\r\n    inline bool _read(string& x){\r\n        if(!skip())return\
    \ false;\r\n        for(;;){\r\n            int pos=rdLeft;\r\n            while(pos<rdRight\
    \ and rdbuf[pos]>' ')pos++;\r\n            x.append(rdbuf+rdLeft,pos-rdLeft);\r\
    \n            if(rdLeft==pos)break;\r\n            rdLeft=pos;\r\n           \
    \ if(rdLeft==rdRight)reload();\r\n            else break;\r\n        }\r\n   \
    \     return true;\r\n    }\r\n    template<typename T>inline bool _read(vector<T>&\
    \ v){\r\n        for(auto& x:v){\r\n            if(!_read(x))return false;\r\n\
    \        }\r\n        return true;\r\n    }\r\n\r\n    char wtbuf[L],tmp[50];\r\
    \n    int wtRight=0;\r\n    inline void flush(){\r\n        fwrite(wtbuf,1,wtRight,stdout);\r\
    \n        wtRight=0;\r\n    }\r\n    inline void _write(const char& x){\r\n  \
    \      if(wtRight>L-32)flush();\r\n        wtbuf[wtRight++]=x;\r\n    }\r\n  \
    \  inline void _write(const string& x){\r\n        for(auto& c:x)_write(c);\r\n\
    \    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ void _write(T x){\r\n        if(wtRight>L-32)flush();\r\n        if(x==0){\r\
    \n            _write('0');\r\n            return;\r\n        }\r\n        else\
    \ if(x<0){\r\n            _write('-');\r\n            x=-x;\r\n        }\r\n \
    \       int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
    \n            x/=10;\r\n        }\r\n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\
    \n        wtRight+=pos;\r\n    }\r\n    template<typename T>inline void _write(const\
    \ vector<T>& v){\r\n        rep(i,0,v.size()){\r\n            if(i)_write(' ');\r\
    \n            _write(v[i]);\r\n        }\r\n    }\r\npublic:\r\n    FastIO(){}\r\
    \n    ~FastIO(){flush();}\r\n    inline void read(){}\r\n    template <typename\
    \ Head, typename... Tail>inline void read(Head& head,Tail&... tail){\r\n     \
    \   assert(_read(head));\r\n        read(tail...); \r\n    }\r\n    template<bool\
    \ ln=true,bool space=false>inline void write(){if(ln)_write('\\n');}\r\n    template\
    \ <bool ln=true,bool space=false,typename Head, typename... Tail>inline void write(const\
    \ Head& head,const Tail&... tail){\r\n        if(space)_write(' ');\r\n      \
    \  _write(head);\r\n        write<ln,true>(tail...); \r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/segtreebeats.hpp\"\n\r\nstruct\
    \ Segtreebeats{\r\n    struct state{\r\n        ll maxx=-INF,smax=-INF,cmax=0,lmax=-INF;\r\
    \n        ll minn=INF,smin=INF,cmin=0,lmin=INF;\r\n        ll sum=0,add=0; int\
    \ len=1;\r\n        state(){}\r\n        state(ll val):maxx(val),cmax(1),minn(val),cmin(1),sum(val){}\r\
    \n    };\r\n    int n; vector<state> val;\r\n    Segtreebeats(int _n):Segtreebeats(vector<ll>(_n,0)){}\r\
    \n    Segtreebeats(const vector<ll>& a){\r\n        for(n=1;n<(int)a.size();n<<=1);\r\
    \n        val.assign(2*n,state());\r\n        rep(i,0,a.size())val[i+n]=state(a[i]);\r\
    \n        for(int i=n-1;i;i--)apply(i);\r\n    }\r\n    void apply(int k){\r\n\
    \        state &x=val[k],&lb=val[2*k],&rb=val[2*k+1];\r\n        if(lb.minn<rb.minn)x.minn=lb.minn,x.cmin=lb.cmin,x.smin=min(lb.smin,rb.minn);\r\
    \n        else if(lb.minn>rb.minn)x.minn=rb.minn,x.cmin=rb.cmin,x.smin=min(rb.smin,lb.minn);\r\
    \n        else x.minn=lb.minn,x.cmin=lb.cmin+rb.cmin,x.smin=min(lb.smin,rb.smin);\r\
    \n        if(lb.maxx>rb.maxx)x.maxx=lb.maxx,x.cmax=lb.cmax,x.smax=max(lb.smax,rb.maxx);\r\
    \n        else if(lb.maxx<rb.maxx)x.maxx=rb.maxx,x.cmax=rb.cmax,x.smax=max(rb.smax,lb.maxx);\r\
    \n        else x.maxx=lb.maxx,x.cmax=lb.cmax+rb.cmax,x.smax=max(lb.smax,rb.smax);\r\
    \n        x.len=lb.len+rb.len; x.sum=lb.sum+rb.sum;\r\n    }\r\n    void eval(int\
    \ k){\r\n        state &x=val[k],&lb=(k<n?val[2*k]:val[0]),&rb=(k<n?val[2*k+1]:val[0]);\r\
    \n        if(x.add){\r\n            if(lb.lmax!=-INF)lb.lmax+=x.add;\r\n     \
    \       if(lb.lmin!=INF)lb.lmin+=x.add;\r\n            if(rb.lmax!=-INF)rb.lmax+=x.add;\r\
    \n            if(rb.lmin!=INF)rb.lmin+=x.add;\r\n            lb.add+=x.add; rb.add+=x.add;\r\
    \n            x.minn+=x.add;\r\n            if(x.smin!=INF)x.smin+=x.add;\r\n\
    \            x.maxx+=x.add;\r\n            if(x.smax!=-INF)x.smax+=x.add;\r\n\
    \            x.sum+=x.len*x.add; x.add=0;\r\n        }\r\n        if(x.lmax!=-INF){\r\
    \n            chmax(lb.lmax,x.lmax);\r\n            chmax(lb.lmin,x.lmax);\r\n\
    \            chmax(rb.lmax,x.lmax);\r\n            chmax(rb.lmin,x.lmax);\r\n\
    \            if(x.lmax>=x.smin){eval(k*2); eval(k*2+1); apply(k);}\r\n       \
    \     else if(x.lmax>x.minn){\r\n                x.sum+=x.cmin*(x.lmax-x.minn);\r\
    \n                if(x.smax==x.minn)x.smax=x.lmax;\r\n                if(x.maxx==x.minn)x.maxx=x.lmax;\r\
    \n                x.minn=x.lmax;\r\n            } x.lmax=-INF;\r\n        }\r\n\
    \        if(x.lmin!=INF){\r\n            chmin(lb.lmax,x.lmin);\r\n          \
    \  chmin(lb.lmin,x.lmin);\r\n            chmin(rb.lmax,x.lmin);\r\n          \
    \  chmin(rb.lmin,x.lmin);\r\n            if(x.lmin<=x.smax){eval(k*2); eval(k*2+1);\
    \ apply(k);}\r\n            else if(x.lmin<x.maxx){\r\n                x.sum+=x.cmax*(x.lmin-x.maxx);\r\
    \n                if(x.smin==x.maxx)x.smin=x.lmin;\r\n                if(x.minn==x.maxx)x.minn=x.lmin;\r\
    \n                x.maxx=x.lmin;\r\n            } x.lmin=INF;\r\n        }\r\n\
    \    }\r\n    void range_add(int a,int b,ll c,int k=1,int l=0,int r=-1){\r\n \
    \       if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return;\r\n        if(b>=r&&a<=l){\r\
    \n            val[k].add=c; eval(k);\r\n        }else{\r\n            range_add(a,b,c,k*2,l,(l+r)/2);\r\
    \n            range_add(a,b,c,k*2+1,(l+r)/2,r);\r\n            apply(k);\r\n \
    \       }\r\n    }\r\n    void range_chmin(int a,int b,ll c,int k=1,int l=0,int\
    \ r=-1){\r\n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return;\r\n\
    \        if(b>=r&&a<=l){\r\n            val[k].lmin=c; eval(k);\r\n        }else{\r\
    \n            range_chmin(a,b,c,k*2,l,(l+r)/2);\r\n            range_chmin(a,b,c,k*2+1,(l+r)/2,r);\r\
    \n            apply(k);\r\n        }\r\n    }\r\n    void range_chmax(int a,int\
    \ b,ll c,int k=1,int l=0,int r=-1){\r\n        if(r<0)r=n; eval(k);\r\n      \
    \  if(b<=l||a>=r)return;\r\n        if(b>=r&&a<=l){\r\n            val[k].lmax=c;\
    \ eval(k);\r\n        }else{\r\n            range_chmax(a,b,c,k*2,l,(l+r)/2);\r\
    \n            range_chmax(a,b,c,k*2+1,(l+r)/2,r);\r\n            apply(k);\r\n\
    \        }\r\n    }\r\n    ll query_max(int a,int b,int k=1,int l=0,int r=-1){\r\
    \n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return -INF;\r\n     \
    \   if(b>=r&&a<=l)return val[k].maxx;\r\n        else{\r\n            ll res=max(query_max(a,b,k*2,l,(l+r)/2),query_max(a,b,k*2+1,(l+r)/2,r));\r\
    \n            return res;\r\n        }\r\n    }\r\n    ll query_min(int a,int\
    \ b,int k=1,int l=0,int r=-1){\r\n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return\
    \ INF;\r\n        if(b>=r&&a<=l)return val[k].minn;\r\n        else{\r\n     \
    \       ll res=min(query_min(a,b,k*2,l,(l+r)/2),query_min(a,b,k*2+1,(l+r)/2,r));\r\
    \n            return res;\r\n        }\r\n    }\r\n    ll query_sum(int a,int\
    \ b,int k=1,int l=0,int r=-1){\r\n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return\
    \ 0;\r\n        if(b>=r&&a<=l)return val[k].sum;\r\n        else{\r\n        \
    \    ll res=query_sum(a,b,k*2,l,(l+r)/2)+query_sum(a,b,k*2+1,(l+r)/2,r);\r\n \
    \           return res;\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Segment\
    \ Tree Beats\r\n */\n#line 6 \"Verify/LC_range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n    io.read(n,q);\r\n    vector<ll>\
    \ a(n);\r\n    io.read(a);\r\n    Segtreebeats seg(a);\r\n\r\n    int t,L,R;\r\
    \n    ll x;\r\n    while(q--){\r\n        io.read(t);\r\n        if(t==0){\r\n\
    \            io.read(L,R,x);\r\n            seg.range_chmin(L,R,x);\r\n      \
    \  }\r\n        if(t==1){\r\n            io.read(L,R,x);\r\n            seg.range_chmax(L,R,x);\r\
    \n        }   \r\n        if(t==2){\r\n            io.read(L,R,x);\r\n       \
    \     seg.range_add(L,R,x);\r\n        }\r\n        if(t==3){\r\n            io.read(L,R);\r\
    \n            io.write(seg.query_sum(L,R));\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n#include \"DataStructure/segtreebeats.hpp\"\r\n\r\nFastIO io;\r\nint main(){\r\
    \n    int n,q;\r\n    io.read(n,q);\r\n    vector<ll> a(n);\r\n    io.read(a);\r\
    \n    Segtreebeats seg(a);\r\n\r\n    int t,L,R;\r\n    ll x;\r\n    while(q--){\r\
    \n        io.read(t);\r\n        if(t==0){\r\n            io.read(L,R,x);\r\n\
    \            seg.range_chmin(L,R,x);\r\n        }\r\n        if(t==1){\r\n   \
    \         io.read(L,R,x);\r\n            seg.range_chmax(L,R,x);\r\n        }\
    \   \r\n        if(t==2){\r\n            io.read(L,R,x);\r\n            seg.range_add(L,R,x);\r\
    \n        }\r\n        if(t==3){\r\n            io.read(L,R);\r\n            io.write(seg.query_sum(L,R));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/segtreebeats.hpp
  isVerificationFile: true
  path: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-24 03:48:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
- /verify/Verify/LC_range_chmin_chmax_add_range_sum.test.cpp.html
title: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
---
