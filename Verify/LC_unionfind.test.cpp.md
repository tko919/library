---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/unionfind.hpp
    title: Union Find
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Verify/LC_unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"DataStructure/unionfind.hpp\"\
    \n\r\nstruct UnionFind{\r\n    vector<int> par; int n;\r\n    UnionFind(){}\r\n\
    \    UnionFind(int _n):par(_n,-1),n(_n){}\r\n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\
    \n    bool same(int x,int y){return root(x)==root(y);}\r\n    int size(int x){return\
    \ -par[root(x)];}\r\n    bool unite(int x,int y){\r\n        x=root(x),y=root(y);\
    \ if(x==y)return false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x];\
    \ par[x]=y; n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\
    \n */\n#line 5 \"Verify/LC_unionfind.test.cpp\"\n\r\nint main(){\r\n    int N,Q;\r\
    \n    cin>>N>>Q;\r\n    vector<int> t(Q),u(Q),v(Q);\r\n    rep(i,0,Q)cin>>t[i]>>u[i]>>v[i];\r\
    \n    \r\n    UnionFind uni(N);\r\n    rep(i,0,Q){\r\n        if(t[i]==0){\r\n\
    \            uni.unite(u[i],v[i]);\r\n        }\r\n        else{\r\n         \
    \   cout<<uni.same(u[i],v[i])<<'\\n';\r\n        }\r\n    }\r\n    return 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"DataStructure/unionfind.hpp\"\r\n\r\n\
    int main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<int> t(Q),u(Q),v(Q);\r\
    \n    rep(i,0,Q)cin>>t[i]>>u[i]>>v[i];\r\n    \r\n    UnionFind uni(N);\r\n  \
    \  rep(i,0,Q){\r\n        if(t[i]==0){\r\n            uni.unite(u[i],v[i]);\r\n\
    \        }\r\n        else{\r\n            cout<<uni.same(u[i],v[i])<<'\\n';\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/unionfind.hpp
  isVerificationFile: true
  path: Verify/LC_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_unionfind.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_unionfind.test.cpp
- /verify/Verify/LC_unionfind.test.cpp.html
title: Verify/LC_unionfind.test.cpp
---
