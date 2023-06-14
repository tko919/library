---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/floorsum.hpp
    title: Floor Sum
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Verify/LC_sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define\
    \ MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\n#define\
    \ LB(v,x) lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Math/floorsum.hpp\"\
    \n\r\ntemplate<typename T=ll>T FloorSum(ll n,ll a,ll b,ll m){\r\n   //sum_{k=0}^{n-1}\
    \ [(a*k+b)/m]\r\n   T res=0;\r\n   if(a>=m)res+=T(a/m)*n*(n-1)/2,a-=a/m*m;\r\n\
    \   else if(a<0)res-=T((-a+m-1)/m)*n*(n-1)/2,a+=((-a+m-1)/m)*m;\r\n   if(b>=m)res+=(b/m)*n,b-=b/m*m;\r\
    \n   else if(b<0)res-=((-b+m-1)/m)*n,b+=((-b+m-1)/m)*m;\r\n   \r\n   while(1){\r\
    \n      ll y_max=a*n+b;\r\n      if(y_max<m)break;\r\n      n=y_max/m;\r\n   \
    \   b=y_max%m;\r\n      res+=(n*(n-1)/2)*(m/a)+n*(b/a);\r\n      swap(m,a);\r\n\
    \      a=a%m;\r\n      b=b%m;\r\n   }\r\n   return res;\r\n}\r\n\r\n/**\r\n *\
    \ @brief Floor Sum\r\n * @docs docs/floorsum.md\r\n */\n#line 5 \"Verify/LC_sum_of_floor_of_linear.test.cpp\"\
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
  isVerificationFile: true
  path: Verify/LC_sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_sum_of_floor_of_linear.test.cpp
- /verify/Verify/LC_sum_of_floor_of_linear.test.cpp.html
title: Verify/LC_sum_of_floor_of_linear.test.cpp
---
