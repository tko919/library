---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
    title: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Segment Tree Beats
    links: []
  bundledCode: "#line 2 \"DataStructure/segtreebeats.hpp\"\n\r\nstruct Segtreebeats{\r\
    \n    struct state{\r\n        ll maxx=-INF,smax=-INF,cmax=0,lmax=-INF;\r\n  \
    \      ll minn=INF,smin=INF,cmin=0,lmin=INF;\r\n        ll sum=0,add=0; int len=1;\r\
    \n        state(){}\r\n        state(ll val):maxx(val),cmax(1),minn(val),cmin(1),sum(val){}\r\
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
    \ Tree Beats\r\n */\n"
  code: "#pragma once\r\n\r\nstruct Segtreebeats{\r\n    struct state{\r\n       \
    \ ll maxx=-INF,smax=-INF,cmax=0,lmax=-INF;\r\n        ll minn=INF,smin=INF,cmin=0,lmin=INF;\r\
    \n        ll sum=0,add=0; int len=1;\r\n        state(){}\r\n        state(ll\
    \ val):maxx(val),cmax(1),minn(val),cmin(1),sum(val){}\r\n    };\r\n    int n;\
    \ vector<state> val;\r\n    Segtreebeats(int _n):Segtreebeats(vector<ll>(_n,0)){}\r\
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
    \ Tree Beats\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtreebeats.hpp
  requiredBy: []
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
documentation_of: DataStructure/segtreebeats.hpp
layout: document
redirect_from:
- /library/DataStructure/segtreebeats.hpp
- /library/DataStructure/segtreebeats.hpp.html
title: Segment Tree Beats
---
