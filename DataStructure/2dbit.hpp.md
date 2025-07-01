---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 2D Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate <typename T> struct\
    \ BIT {\r\n    int n;\r\n    T all = 0;\r\n    vector<T> val;\r\n    BIT(int _n\
    \ = 0) : n(_n), val(_n + 10) {}\r\n    void clear() {\r\n        val.assign(n\
    \ + 10, 0);\r\n        all = T();\r\n    }\r\n    void add(int i, T x) {\r\n \
    \       for (i++; i <= n; i += (i & -i))\r\n            val[i] = val[i] + x;\r\
    \n        all += x;\r\n    }\r\n    T sum(int i) {\r\n        i = clamp(i, 0,\
    \ n);\r\n        T res = 0;\r\n        for (; i; i -= (i & -i))\r\n          \
    \  res += val[i];\r\n        return res;\r\n    }\r\n    // [L,R)\r\n    T sum(int\
    \ L, int R) {\r\n        if (L > R)\r\n            return T(0);\r\n        return\
    \ sum(R) - sum(L);\r\n    }\r\n    int lower_bound(T x) {\r\n        int ret =\
    \ 0, len = 1;\r\n        while (2 * len <= n)\r\n            len <<= 1;\r\n  \
    \      for (; len >= 1; len >>= 1) {\r\n            if (ret + len <= n and val[ret\
    \ + len] < x) {\r\n                ret += len;\r\n                x -= val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 3 \"DataStructure/2dbit.hpp\"\n\n\
    template<class T>struct BIT2D{\n    int n; vector<BIT<T>> d;\n    vector<int>\
    \ xs; vector<vector<int>> ys;\n    vector<pair<ll,ll>> p;\n    BIT2D(){}\n   \
    \ void push(ll x,ll y){p.push_back({x,y});}\n    void init(){\n        rep(i,0,p.size())xs.push_back(p[i].first);\n\
    \        sort(ALL(xs)); xs.erase(unique(ALL(xs)),xs.end());\n        n=xs.size()+1;\
    \ ys.resize(n);\n        rep(j,0,p.size()){\n            int s=upper_bound(ALL(xs),p[j].first)-xs.begin();\n\
    \            for(int i=s;i<n;i+=(i&-i))ys[i].push_back(p[j].second);\n       \
    \ }\n        d.resize(n);\n        rep(i,0,n){\n            sort(ALL(ys[i]));\
    \ ys[i].erase(unique(ALL(ys[i])),ys[i].end());\n            d[i]=BIT<T>(ys[i].size()+2);\n\
    \        }\n    }\n    void add(ll x,ll y,T z=1){\n        int s=upper_bound(ALL(xs),x)-xs.begin();\n\
    \        for(int i=s;i<n;i+=(i&-i)){\n            int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();\n\
    \            d[i].add(idx,z);\n        }\n    }\n    T sum(ll x,ll y){\n     \
    \   T res=0;\n        int s=upper_bound(ALL(xs),x)-xs.begin();\n        for(int\
    \ i=s;i;i-=(i&-i)){\n            int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();\n\
    \            res+=d[i].sum(idx+1);\n        }\n        return res;\n    }\n  \
    \  T sum(ll x1,ll y1,ll x2,ll y2){return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);}\n\
    };\n\n/**\n * @brief 2D Binary Indexed Tree\n*/\n"
  code: "#pragma once\n#include \"DataStructure/bit.hpp\"\n\ntemplate<class T>struct\
    \ BIT2D{\n    int n; vector<BIT<T>> d;\n    vector<int> xs; vector<vector<int>>\
    \ ys;\n    vector<pair<ll,ll>> p;\n    BIT2D(){}\n    void push(ll x,ll y){p.push_back({x,y});}\n\
    \    void init(){\n        rep(i,0,p.size())xs.push_back(p[i].first);\n      \
    \  sort(ALL(xs)); xs.erase(unique(ALL(xs)),xs.end());\n        n=xs.size()+1;\
    \ ys.resize(n);\n        rep(j,0,p.size()){\n            int s=upper_bound(ALL(xs),p[j].first)-xs.begin();\n\
    \            for(int i=s;i<n;i+=(i&-i))ys[i].push_back(p[j].second);\n       \
    \ }\n        d.resize(n);\n        rep(i,0,n){\n            sort(ALL(ys[i]));\
    \ ys[i].erase(unique(ALL(ys[i])),ys[i].end());\n            d[i]=BIT<T>(ys[i].size()+2);\n\
    \        }\n    }\n    void add(ll x,ll y,T z=1){\n        int s=upper_bound(ALL(xs),x)-xs.begin();\n\
    \        for(int i=s;i<n;i+=(i&-i)){\n            int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();\n\
    \            d[i].add(idx,z);\n        }\n    }\n    T sum(ll x,ll y){\n     \
    \   T res=0;\n        int s=upper_bound(ALL(xs),x)-xs.begin();\n        for(int\
    \ i=s;i;i-=(i&-i)){\n            int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();\n\
    \            res+=d[i].sum(idx+1);\n        }\n        return res;\n    }\n  \
    \  T sum(ll x1,ll y1,ll x2,ll y2){return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);}\n\
    };\n\n/**\n * @brief 2D Binary Indexed Tree\n*/"
  dependsOn:
  - DataStructure/bit.hpp
  isVerificationFile: false
  path: DataStructure/2dbit.hpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/2dbit.hpp
layout: document
redirect_from:
- /library/DataStructure/2dbit.hpp
- /library/DataStructure/2dbit.hpp.html
title: 2D Binary Indexed Tree
---
