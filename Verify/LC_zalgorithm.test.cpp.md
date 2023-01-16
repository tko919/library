---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: String/zalgo.hpp
    title: Z-Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"Verify/LC_zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"String/zalgo.hpp\"\
    \n\r\ntemplate<typename T>vector<int> Zalgo(T& s){\r\n   int n=s.size(); vector<int>\
    \ res(n);\r\n   for(int i=1,j=0;i<n;i++){\r\n      if(i+res[i-j]<j+res[j])res[i]=res[i-j];\r\
    \n      else{\r\n         int k=max(0,j+res[j]-i);\r\n         while(i+k<n&&s[k]==s[i+k])k++;\r\
    \n         res[i]=k; j=i;\r\n      }\r\n   } res[0]=n; return res;\r\n}\r\n\r\n\
    /**\r\n * @brief Z-Algorithm\r\n */\n#line 5 \"Verify/LC_zalgorithm.test.cpp\"\
    \n\r\nint main(){\r\n    string s;\r\n    cin>>s;\r\n    auto ret=Zalgo(s);\r\n\
    \    rep(i,0,s.size())cout<<ret[i]<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"String/zalgo.hpp\"\r\n\r\nint main(){\r\
    \n    string s;\r\n    cin>>s;\r\n    auto ret=Zalgo(s);\r\n    rep(i,0,s.size())cout<<ret[i]<<'\\\
    n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - String/zalgo.hpp
  isVerificationFile: true
  path: Verify/LC_zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 21:31:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_zalgorithm.test.cpp
- /verify/Verify/LC_zalgorithm.test.cpp.html
title: Verify/LC_zalgorithm.test.cpp
---
