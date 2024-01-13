---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/manacher.hpp
    title: Manacher Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"Verify/LC_enumerate_palindromes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define\
    \ SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v)\
    \ *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
    \n#define UB(v,x) int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long\
    \ long int;\r\nusing ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing\
    \ u128=__uint128_t;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"String/manacher.hpp\"\
    \n\r\nvector<int> Manacher(const string& s){\r\n   string t;\r\n   for(auto& c:s){\r\
    \n      t.push_back(c);\r\n      t.push_back('$');\r\n   }\r\n   t.pop_back();\r\
    \n   int i=0,j=0,n=t.size(); vector<int> res(n);\r\n   while(i<n){\r\n      while(i-j>=0\
    \ and i+j<n and t[i-j]==t[i+j])j++;\r\n      res[i]=j;\r\n      int k=1;\r\n \
    \     while(i-k>=0 and i+k<n and k+res[i-k]<j){\r\n         res[i+k]=res[i-k];\
    \ k++;\r\n      }\r\n      i+=k; j-=k;\r\n   }\r\n   for(int i=0;i<n;i++){\r\n\
    \      if(i&1)res[i]=(res[i]/2)*2;\r\n      else res[i]=((res[i]+1)/2)*2-1;\r\n\
    \   }\r\n   return res;\r\n}\r\n\r\n/**\r\n * @brief Manacher Algorithm\r\n */\n\
    #line 5 \"Verify/LC_enumerate_palindromes.test.cpp\"\n\r\nint main(){\r\n    string\
    \ s;\r\n    cin>>s;\r\n    auto ret=Manacher(s);\r\n    rep(i,0,ret.size())cout<<ret[i]<<'\\\
    n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"String/manacher.hpp\"\
    \r\n\r\nint main(){\r\n    string s;\r\n    cin>>s;\r\n    auto ret=Manacher(s);\r\
    \n    rep(i,0,ret.size())cout<<ret[i]<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - String/manacher.hpp
  isVerificationFile: true
  path: Verify/LC_enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_enumerate_palindromes.test.cpp
- /verify/Verify/LC_enumerate_palindromes.test.cpp.html
title: Verify/LC_enumerate_palindromes.test.cpp
---
