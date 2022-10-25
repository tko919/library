---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/cartesian.hpp
    title: Cartesian Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"Verify/LC_cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Algorithm/cartesian.hpp\"\n\r\nvector<int> Cartesian(const vector<int>&\
    \ a){\r\n   const int n=a.size(); vector<int> res(n,-1);\r\n   int cur;\r\n  \
    \ rep(i,1,n){\r\n      cur=i-1;\r\n      if(a[cur]>a[i]){\r\n         int pre=cur;\r\
    \n         while(cur!=-1 and a[cur]>a[i])pre=cur,cur=res[cur];\r\n         if(cur==-1){res[i]=-1;\
    \ res[pre]=i;}\r\n         else{res[i]=cur; res[pre]=i;}\r\n      }\r\n      else\
    \ res[i]=cur;\r\n   } return res;\r\n}\r\n\r\n/**\r\n * @brief Cartesian Tree\r\
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
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_cartesian_tree.test.cpp
- /verify/Verify/LC_cartesian_tree.test.cpp.html
title: Verify/LC_cartesian_tree.test.cpp
---
