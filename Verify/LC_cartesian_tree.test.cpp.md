---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/cartesian.hpp
    title: Cartesian Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"Verify/LC_cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\n#define\
    \ UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define SZ(v)\
    \ (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\n#define UB(v,x)\
    \ int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long long int;\r\n\
    using ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing u128=__uint128_t;\r\
    \nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate<typename\
    \ T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename\
    \ T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}\r\ntemplate<typename\
    \ T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\
    \ntemplate<typename T,typename U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\
    \ntemplate<typename T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\
    \ntemplate<typename T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n\
    #line 2 \"Algorithm/cartesian.hpp\"\n\r\ntemplate <typename T> vector<int> Cartesian(const\
    \ vector<T> &a) {\r\n    const int n = a.size();\r\n    vector<int> res(n, -1);\r\
    \n    int cur;\r\n    rep(i, 1, n) {\r\n        cur = i - 1;\r\n        if (a[cur]\
    \ > a[i]) {\r\n            int pre = cur;\r\n            while (cur != -1 and\
    \ a[cur] > a[i])\r\n                pre = cur, cur = res[cur];\r\n           \
    \ if (cur == -1) {\r\n                res[i] = -1;\r\n                res[pre]\
    \ = i;\r\n            } else {\r\n                res[i] = cur;\r\n          \
    \      res[pre] = i;\r\n            }\r\n        } else\r\n            res[i]\
    \ = cur;\r\n    }\r\n    return res;\r\n}\r\n\r\n/**\r\n * @brief Cartesian Tree\r\
    \n * @docs docs/cartesian.md\r\n */\n#line 5 \"Verify/LC_cartesian_tree.test.cpp\"\
    \n\r\nint main(){\r\n    int n;\r\n    cin>>n;\r\n    vector<int> a(n);\r\n  \
    \  rep(i,0,n)cin>>a[i];\r\n    auto ret=Cartesian(a);\r\n    rep(i,0,n){\r\n \
    \       if(ret[i]==-1)ret[i]=i;\r\n        cout<<ret[i]<<'\\n';\r\n    }\r\n \
    \   return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\r\n\r\n\
    #include \"Template/template.hpp\"\r\n#include \"Algorithm/cartesian.hpp\"\r\n\
    \r\nint main(){\r\n    int n;\r\n    cin>>n;\r\n    vector<int> a(n);\r\n    rep(i,0,n)cin>>a[i];\r\
    \n    auto ret=Cartesian(a);\r\n    rep(i,0,n){\r\n        if(ret[i]==-1)ret[i]=i;\r\
    \n        cout<<ret[i]<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Algorithm/cartesian.hpp
  isVerificationFile: true
  path: Verify/LC_cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_cartesian_tree.test.cpp
- /verify/Verify/LC_cartesian_tree.test.cpp.html
title: Verify/LC_cartesian_tree.test.cpp
---
