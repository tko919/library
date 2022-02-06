---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"Verify/LC_discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Math/primitive.hpp\"\n\r\nll mpow(ll a,ll t,ll m){\r\n    ll\
    \ res=1;\r\n    while(t){\r\n        if(t&1)res=(res*a)%m;\r\n        a=(a*a)%m;\
    \ t>>=1;\r\n    } return res;\r\n}\r\nll minv(ll a,ll m){\r\n    ll b=m,u=1,v=0;\r\
    \n    while(b){\r\n        ll t=a/b;\r\n        a-=t*b; swap(a,b);\r\n       \
    \ u-=t*v; swap(u,v);\r\n    } u=(u%m+m)%m; return u;\r\n}\r\nll getPrimitiveRoot(ll\
    \ p){\r\n    vector<ll> ds;\r\n    for(ll x=1;x*x<=p-1;x++)if((p-1)%x==0){\r\n\
    \        ds.push_back(x);\r\n        if(x*x!=p-1)ds.push_back((p-1)/x);\r\n  \
    \  }\r\n    sort(ALL(ds));\r\n    ds.pop_back();\r\n    for(int x=1;x<p;x++){\r\
    \n        for(auto& d:ds){\r\n            if(mpow(x,d,p)==1)goto fail;\r\n   \
    \     }\r\n        return x;\r\n        fail:;\r\n    } assert(0);\r\n}\r\nll\
    \ extgcd(ll a,ll b,ll& p,ll& q){\r\n    if(b==0){p=1; q=0; return a;}\r\n    ll\
    \ d=extgcd(b,a%b,q,p); q-=a/b*p; return d;\r\n}\r\npair<ll,ll> crt(const vector<ll>&\
    \ vs,const vector<ll>& ms){\r\n    ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\
    \n        ll p,q,v=vs[i],m=ms[i];\r\n        if(M<m)swap(M,m),swap(V,v);\r\n \
    \       ll d=extgcd(M,m,p,q);\r\n        if((v-V)%d!=0)return {0,-1};\r\n    \
    \    ll md=m/d,tmp=(v-V)/d%md*p%md;\r\n        V+=M*tmp; M*=md;\r\n    } V=(V%M+M)%M;\
    \ return {V,M};\r\n}\r\nll ModLog(ll a,ll b,ll p){\r\n    ll g=1;\r\n    for(ll\
    \ t=p;t;t>>=1)g=g*a%p;\r\n    g=__gcd(g,p);\r\n    ll t=1,c=0;\r\n    for(;t%g;c++){\r\
    \n        if(t==b)return c;\r\n        t=t*a%p;\r\n        }\r\n    if(b%g)return\
    \ -1;\r\n    t/=g,b/=g;\r\n    ll n=p/g,h=0,gs=1;\r\n    for(;h*h<n;h++)gs=gs*a%n;\r\
    \n    unordered_map<ll,ll> bs;\r\n    for(ll s=0,e=b;s<h;bs[e]=++s)e=e*a%n;\r\n\
    \    for(ll s=0,e=t;s<n;){\r\n        e=e*gs%n,s+=h;\r\n        if(bs.count(e)){\r\
    \n            return c+s-bs[e];\r\n        }\r\n    } return -1;\r\n}\r\n\r\n\
    /**\r\n * @brief Primitive Function\r\n */\n#line 5 \"Verify/LC_discrete_logarithm_mod.test.cpp\"\
    \n\r\nint main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        int\
    \ a,b,m;\r\n        cin>>a>>b>>m;\r\n        cout<<ModLog(a,b,m)<<'\\n';\r\n \
    \   }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/primitive.hpp\"\r\
    \n\r\nint main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        int\
    \ a,b,m;\r\n        cin>>a>>b>>m;\r\n        cout<<ModLog(a,b,m)<<'\\n';\r\n \
    \   }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/primitive.hpp
  isVerificationFile: true
  path: Verify/LC_discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_discrete_logarithm_mod.test.cpp
- /verify/Verify/LC_discrete_logarithm_mod.test.cpp.html
title: Verify/LC_discrete_logarithm_mod.test.cpp
---
