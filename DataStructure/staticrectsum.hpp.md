---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct\
    \ BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\
    \n    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\
    \n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 3 \"DataStructure/staticrectsum.hpp\"\
    \n\ntemplate<class T>struct StaticRectangleSum{\n    struct P{\n        ll x,y;\
    \ T w;\n    };\n    struct Rect{\n        ll l,d,r,u;\n    };\n    struct Q{\n\
    \        ll x,d,u,id,inv;\n    };\n    vector<P> plus;\n    vector<Rect> que;\n\
    \    StaticRectangleSum(){}\n    void add(ll x,ll y,T w){\n        plus.push_back({x,y,w});\n\
    \    }\n    void query(ll l,ll d,ll r,ll u){\n        que.push_back({l,d,r,u});\n\
    \    }\n    vector<T> run(){\n        ll n=plus.size(),q=que.size();\n       \
    \ sort(ALL(plus),[](P& p,P& q){return p.y<q.y;});\n        vector<ll> ys;\n  \
    \      rep(i,0,n)ys.push_back(plus[i].y);\n        ys.erase(unique(ALL(ys)),ys.end());\n\
    \        rep(i,0,n)plus[i].y=lower_bound(ALL(ys),plus[i].y)-ys.begin();\n    \
    \    vector<Q> qs;\n        rep(i,0,q){\n            auto& [l,d,r,u]=que[i];\n\
    \            d=lower_bound(ALL(ys),d)-ys.begin();\n            u=lower_bound(ALL(ys),u)-ys.begin();\n\
    \            qs.push_back({l,d,u,i,1});\n            qs.push_back({r,d,u,i,-1});\n\
    \        }\n        sort(ALL(plus),[](P& p,P& q){return p.x<q.x;});\n        sort(ALL(qs),[](Q&\
    \ p,Q& q){return p.x<q.x;});\n        vector<T> res(q);\n        ll k=0;\n   \
    \     BIT<T> bit(ys.size());\n        for(auto& q:qs){\n            while(k<n\
    \ and plus[k].x<q.x){\n                bit.add(plus[k].y,plus[k].w);\n       \
    \         k++;\n            }\n            res[q.id]+=bit.sum(q.u,q.d)*q.inv;\n\
    \        }\n        return res;\n    }\n};\n\n/**\n * Static Rectangle Sum\n*/\n"
  code: "#pragma once\n#include \"DataStructure/bit.hpp\"\n\ntemplate<class T>struct\
    \ StaticRectangleSum{\n    struct P{\n        ll x,y; T w;\n    };\n    struct\
    \ Rect{\n        ll l,d,r,u;\n    };\n    struct Q{\n        ll x,d,u,id,inv;\n\
    \    };\n    vector<P> plus;\n    vector<Rect> que;\n    StaticRectangleSum(){}\n\
    \    void add(ll x,ll y,T w){\n        plus.push_back({x,y,w});\n    }\n    void\
    \ query(ll l,ll d,ll r,ll u){\n        que.push_back({l,d,r,u});\n    }\n    vector<T>\
    \ run(){\n        ll n=plus.size(),q=que.size();\n        sort(ALL(plus),[](P&\
    \ p,P& q){return p.y<q.y;});\n        vector<ll> ys;\n        rep(i,0,n)ys.push_back(plus[i].y);\n\
    \        ys.erase(unique(ALL(ys)),ys.end());\n        rep(i,0,n)plus[i].y=lower_bound(ALL(ys),plus[i].y)-ys.begin();\n\
    \        vector<Q> qs;\n        rep(i,0,q){\n            auto& [l,d,r,u]=que[i];\n\
    \            d=lower_bound(ALL(ys),d)-ys.begin();\n            u=lower_bound(ALL(ys),u)-ys.begin();\n\
    \            qs.push_back({l,d,u,i,1});\n            qs.push_back({r,d,u,i,-1});\n\
    \        }\n        sort(ALL(plus),[](P& p,P& q){return p.x<q.x;});\n        sort(ALL(qs),[](Q&\
    \ p,Q& q){return p.x<q.x;});\n        vector<T> res(q);\n        ll k=0;\n   \
    \     BIT<T> bit(ys.size());\n        for(auto& q:qs){\n            while(k<n\
    \ and plus[k].x<q.x){\n                bit.add(plus[k].y,plus[k].w);\n       \
    \         k++;\n            }\n            res[q.id]+=bit.sum(q.u,q.d)*q.inv;\n\
    \        }\n        return res;\n    }\n};\n\n/**\n * Static Rectangle Sum\n*/"
  dependsOn:
  - DataStructure/bit.hpp
  isVerificationFile: false
  path: DataStructure/staticrectsum.hpp
  requiredBy: []
  timestamp: '2022-12-26 23:10:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/staticrectsum.hpp
layout: document
redirect_from:
- /library/DataStructure/staticrectsum.hpp
- /library/DataStructure/staticrectsum.hpp.html
title: DataStructure/staticrectsum.hpp
---