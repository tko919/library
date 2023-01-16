---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':x:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':x:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"Verify/LC_factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Math/miller.hpp\"\
    \n\r\nbool Miller(ll n){\r\n    if(n<2 or (n&1)==0)return (n==2);\r\n    ll d=n-1;\
    \ while((d&1)==0)d>>=1;\r\n    vector<ll> seeds;\r\n    auto MP=[&](ll x,ll t,ll\
    \ m)->ll{\r\n        ll res=1;\r\n        while(t){\r\n            if(t&1)res=(__int128_t(res)*x)%m;\r\
    \n            x=(__int128_t(x)*x)%m; t>>=1;\r\n        } return res;\r\n    };\r\
    \n    if(n<(1<<30))seeds={2, 7, 61};\r\n    else seeds={2, 325, 9375, 28178, 450775,\
    \ 9780504};\r\n    for(auto& x:seeds){\r\n        if(n<=x)break;\r\n        ll\
    \ t=d,y=MP(x,t,n);\r\n        while(t!=n-1 and y!=1 and y!=n-1){\r\n         \
    \   y=(__int128_t(y)*y)%n; t<<=1;\r\n        }\r\n        if(y!=n-1 and (t&1)==0)return\
    \ 0;\r\n    } return 1;\r\n}\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n#line\
    \ 2 \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device rnd;\r\n \
    \   unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\n\
    \    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
    \n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned\
    \ L){\r\n        return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T\
    \ L,T R){\r\n        return get(R-L)+L;\r\n    }\r\n    double uniform(){\r\n\
    \        return double(get())/UINT_MAX;\r\n    }\r\n    string str(int n){\r\n\
    \        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\n        return\
    \ ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter first,Iter last){\r\
    \n        if(first==last)return;\r\n        int len=1;\r\n        for(auto it=first+1;it!=last;it++){\r\
    \n            len++;\r\n            int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\
    \n        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 4 \"Math/pollard.hpp\"\n\r\nRandom genPollard;\r\nvector<ll> Pollard(ll\
    \ n){\r\n    if(n<=1)return {};\r\n    if(Miller(n))return {n};\r\n    if((n&1)==0){\r\
    \n        vector<ll> v=Pollard(n>>1); v.push_back(2);\r\n        return v;\r\n\
    \    }\r\n    for(ll x=2,y=2,d;;){\r\n        ll c=genPollard.get(2LL,n-1);\r\n\
    \        do{\r\n            x=(__int128_t(x)*x+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\
    \n            y=(__int128_t(y)*y+c)%n;\r\n            d=__gcd(x-y+n,n);\r\n  \
    \      }while(d==1);\r\n        if(d<n){\r\n            vector<ll> lb=Pollard(d),rb=Pollard(n/d);\r\
    \n            lb.insert(lb.end(),ALL(rb)); return lb;\r\n        }\r\n    }\r\n\
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 5 \"Verify/LC_factorize.test.cpp\"\
    \n\r\nint main(){\r\n    int q;\r\n    cin>>q;\r\n    while(q--){\r\n        ll\
    \ n;\r\n        cin>>n;\r\n        auto ps=Pollard(n);\r\n        cout<<ps.size()<<'\\\
    n';\r\n        sort(ALL(ps));\r\n        for(auto& p:ps)cout<<p<<'\\n';\r\n  \
    \  }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"Math/pollard.hpp\"\r\n\r\nint main(){\r\
    \n    int q;\r\n    cin>>q;\r\n    while(q--){\r\n        ll n;\r\n        cin>>n;\r\
    \n        auto ps=Pollard(n);\r\n        cout<<ps.size()<<'\\n';\r\n        sort(ALL(ps));\r\
    \n        for(auto& p:ps)cout<<p<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_factorize.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_factorize.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_factorize.test.cpp
- /verify/Verify/LC_factorize.test.cpp.html
title: Verify/LC_factorize.test.cpp
---
