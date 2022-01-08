---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"Verify/LC_factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Math/miller.hpp\"\n\r\nbool\
    \ Miller(ll n){\r\n    if(n<2 or (n&1)==0)return (n==2);\r\n    ll d=n-1; while((d&1)==0)d>>=1;\r\
    \n    vector<ll> seeds;\r\n    auto MP=[&](ll x,ll t,ll m)->ll{\r\n        ll\
    \ res=1;\r\n        while(t){\r\n            if(t&1)res=(__int128_t(res)*x)%m;\r\
    \n            x=(__int128_t(x)*x)%m; t>>=1;\r\n        } return res;\r\n    };\r\
    \n    if(n<(1<<30))seeds={2, 7, 61};\r\n    else seeds={2, 325, 9375, 28178, 450775,\
    \ 9780504};\r\n    for(auto& x:seeds){\r\n        if(n<=x)break;\r\n        ll\
    \ t=d,y=MP(x,t,n);\r\n        while(t!=n-1 and y!=1 and y!=n-1){\r\n         \
    \   y=(__int128_t(y)*y)%n; t<<=1;\r\n        }\r\n        if(y!=n-1 and (t&1)==0)return\
    \ 0;\r\n    } return 1;\r\n}\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n#line\
    \ 3 \"Math/pollard.hpp\"\n\r\nmt19937 RND(1341398);\r\nvector<ll> Pollard(ll n){\r\
    \n    if(n<=1)return {};\r\n    if(Miller(n))return {n};\r\n    if((n&1)==0){\r\
    \n        vector<ll> v=Pollard(n>>1); v.push_back(2);\r\n        return v;\r\n\
    \    }\r\n    for(ll x=2,y=2,d;;){\r\n        ll c=RND()%(n-2)+2;\r\n        do{\r\
    \n            x=(__int128_t(x)*x+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\
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
  isVerificationFile: true
  path: Verify/LC_factorize.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_factorize.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_factorize.test.cpp
- /verify/Verify/LC_factorize.test.cpp.html
title: Verify/LC_factorize.test.cpp
---
