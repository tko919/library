---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/fastdiv.hpp
    title: Math/fastdiv.hpp
  - icon: ':x:'
    path: Math/floorsum.hpp
    title: Floor Sum
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Verify/LC_sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * Fast Division\n\
    */\n#line 3 \"Math/floorsum.hpp\"\n\r\nll FloorSum(ll n,ll a,ll b,ll m){\r\n \
    \  //sum_{k=0}^{n-1} [(a*k+b)/m]\r\n   FastDiv im(m);\r\n   ll res=0;\r\n   if(a>=m)res-=(a/im)*n*(n-1)/2,a-=a/im*m;\r\
    \n   else if(a<0)res+=((-a+m-1)/im)*n*(n-1)/2,a+=((-a+m-1)/im)*m;\r\n   if(b>=m)res-=(b/im)*n,b-=b/im*m;\r\
    \n   else if(b<0)res+=((-b+m-1)/im)*n,b+=((-b+m-1)/im)*m;\r\n   \r\n   while(1){\r\
    \n      ll y_max=a*n+b;\r\n      if(y_max<m)break;\r\n      n=y_max/im;\r\n  \
    \    b=y_max%im;\r\n      res+=(n*(n-1)/2)*(m/a)+n*(b/a);\r\n      swap(m,a);\r\
    \n      a=a%im;\r\n      b=b%im;\r\n   }\r\n   return res;\r\n}\r\n\r\n/**\r\n\
    \ * @brief Floor Sum\r\n * @docs docs/floorsum.md\r\n */\n#line 5 \"Verify/LC_sum_of_floor_of_linear.test.cpp\"\
    \n\r\nint main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        int\
    \ n,m,a,b;\r\n        cin>>n>>m>>a>>b;\r\n        cout<<FloorSum(n,a,b,m)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/floorsum.hpp\"\r\
    \n\r\nint main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        int\
    \ n,m,a,b;\r\n        cin>>n>>m>>a>>b;\r\n        cout<<FloorSum(n,a,b,m)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/floorsum.hpp
  - Math/fastdiv.hpp
  isVerificationFile: true
  path: Verify/LC_sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2022-12-28 03:34:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_sum_of_floor_of_linear.test.cpp
- /verify/Verify/LC_sum_of_floor_of_linear.test.cpp.html
title: Verify/LC_sum_of_floor_of_linear.test.cpp
---
