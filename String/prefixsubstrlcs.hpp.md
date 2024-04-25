---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_prefix_substring_lcs.test.cpp
    title: Verify/LC_prefix_substring_lcs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Prefix Substring LCS
    links: []
  bundledCode: "#line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct\
    \ BIT{\r\n    int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\
    \n    void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\
    \n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 3 \"String/prefixsubstrlcs.hpp\"\
    \n\ntemplate <typename T> struct PrefixSubstringLCS {\n    using P = pair<int,\
    \ int>;\n    T s, t;\n    int pos;\n    vector<vector<vector<P>>> que;\n    PrefixSubstringLCS()\
    \ {\n    }\n    PrefixSubstringLCS(T &_s, T &_t)\n        : s(_s), t(_t), pos(0),\
    \ que(s.size(), vector(t.size(), vector<P>())) {\n    }\n    void add(int a, int\
    \ b, int c) {\n        if (a == 0 or c == 0) {\n            pos++;\n         \
    \   return;\n        }\n        que[a - 1][c - 1].push_back({b, pos++});\n   \
    \ }\n    vector<int> run() {\n        vector<int> h(t.size()), ret(pos);\n   \
    \     iota(ALL(h), 0);\n        rep(a, 0, s.size()) {\n            int pre = -1;\n\
    \            rep(c, 0, t.size()) {\n                if (s[a] == t[c] or h[c] <\
    \ pre)\n                    swap(h[c], pre);\n            }\n            BIT<int>\
    \ bit(t.size() + 1);\n            rep(c, 0, t.size()) {\n                if (h[c]\
    \ != -1)\n                    bit.add(h[c], 1);\n                for (auto &[b,\
    \ id] : que[a][c]) {\n                    ret[id] = (c - b + 1) - (bit.all - bit.sum(b));\n\
    \                }\n            }\n        }\n        return ret;\n    }\n};\n\
    \n/**\n * @brief Prefix Substring LCS\n */\n"
  code: "#pragma once\n#include \"DataStructure/bit.hpp\"\n\ntemplate <typename T>\
    \ struct PrefixSubstringLCS {\n    using P = pair<int, int>;\n    T s, t;\n  \
    \  int pos;\n    vector<vector<vector<P>>> que;\n    PrefixSubstringLCS() {\n\
    \    }\n    PrefixSubstringLCS(T &_s, T &_t)\n        : s(_s), t(_t), pos(0),\
    \ que(s.size(), vector(t.size(), vector<P>())) {\n    }\n    void add(int a, int\
    \ b, int c) {\n        if (a == 0 or c == 0) {\n            pos++;\n         \
    \   return;\n        }\n        que[a - 1][c - 1].push_back({b, pos++});\n   \
    \ }\n    vector<int> run() {\n        vector<int> h(t.size()), ret(pos);\n   \
    \     iota(ALL(h), 0);\n        rep(a, 0, s.size()) {\n            int pre = -1;\n\
    \            rep(c, 0, t.size()) {\n                if (s[a] == t[c] or h[c] <\
    \ pre)\n                    swap(h[c], pre);\n            }\n            BIT<int>\
    \ bit(t.size() + 1);\n            rep(c, 0, t.size()) {\n                if (h[c]\
    \ != -1)\n                    bit.add(h[c], 1);\n                for (auto &[b,\
    \ id] : que[a][c]) {\n                    ret[id] = (c - b + 1) - (bit.all - bit.sum(b));\n\
    \                }\n            }\n        }\n        return ret;\n    }\n};\n\
    \n/**\n * @brief Prefix Substring LCS\n */"
  dependsOn:
  - DataStructure/bit.hpp
  isVerificationFile: false
  path: String/prefixsubstrlcs.hpp
  requiredBy: []
  timestamp: '2024-01-18 04:47:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_prefix_substring_lcs.test.cpp
documentation_of: String/prefixsubstrlcs.hpp
layout: document
redirect_from:
- /library/String/prefixsubstrlcs.hpp
- /library/String/prefixsubstrlcs.hpp.html
title: Prefix Substring LCS
---
