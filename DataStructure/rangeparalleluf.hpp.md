---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/unionfind.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Range Parallel UnionFind
    links: []
  bundledCode: "#line 2 \"DataStructure/unionfind.hpp\"\n\r\nstruct UnionFind{\r\n\
    \    vector<int> par; int n;\r\n    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\
    \n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    bool unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return\
    \ false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y;\
    \ n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */\n\
    #line 3 \"DataStructure/rangeparalleluf.hpp\"\n\nstruct RangeParallelUF {\n  \
    \  vector<UnionFind> buf;\n    RangeParallelUF(int n) {\n        int lg = topbit(n)\
    \ + 2;\n        buf.resize(lg);\n        rep(i, 0, lg) buf[i] = UnionFind(n);\n\
    \    }\n    template <typename F> void unite(int x, int y, int len, F f) {\n \
    \       if (len == 0)\n            return;\n        if (len == 1) {\n        \
    \    inner(x, y, 0, f);\n            return;\n        }\n        int k = topbit(len\
    \ - 1);\n        inner(x, y, k, f);\n        inner(x + len - (1 << k), y + len\
    \ - (1 << k), k, f);\n    }\n\n  private:\n    template <typename F> void inner(int\
    \ x, int y, int k, F f) {\n        if (k == 0) {\n            int a = buf[0].root(x);\n\
    \            int b = buf[0].root(y);\n            if (a == b)\n              \
    \  return;\n            buf[0].unite(a, b);\n            int c = buf[0].root(x);\n\
    \            f(c, a ^ b ^ c);\n            return;\n        }\n        if (!buf[k].unite(x,\
    \ y))\n            return;\n        inner(x, y, k - 1, f);\n        inner(x +\
    \ (1 << (k - 1)), y + (1 << (k - 1)), k - 1, f);\n    }\n};\n\n/**\n * @brief\
    \ Range Parallel UnionFind\n */\n"
  code: "#pragma once\n#include \"DataStructure/unionfind.hpp\"\n\nstruct RangeParallelUF\
    \ {\n    vector<UnionFind> buf;\n    RangeParallelUF(int n) {\n        int lg\
    \ = topbit(n) + 2;\n        buf.resize(lg);\n        rep(i, 0, lg) buf[i] = UnionFind(n);\n\
    \    }\n    template <typename F> void unite(int x, int y, int len, F f) {\n \
    \       if (len == 0)\n            return;\n        if (len == 1) {\n        \
    \    inner(x, y, 0, f);\n            return;\n        }\n        int k = topbit(len\
    \ - 1);\n        inner(x, y, k, f);\n        inner(x + len - (1 << k), y + len\
    \ - (1 << k), k, f);\n    }\n\n  private:\n    template <typename F> void inner(int\
    \ x, int y, int k, F f) {\n        if (k == 0) {\n            int a = buf[0].root(x);\n\
    \            int b = buf[0].root(y);\n            if (a == b)\n              \
    \  return;\n            buf[0].unite(a, b);\n            int c = buf[0].root(x);\n\
    \            f(c, a ^ b ^ c);\n            return;\n        }\n        if (!buf[k].unite(x,\
    \ y))\n            return;\n        inner(x, y, k - 1, f);\n        inner(x +\
    \ (1 << (k - 1)), y + (1 << (k - 1)), k - 1, f);\n    }\n};\n\n/**\n * @brief\
    \ Range Parallel UnionFind\n */"
  dependsOn:
  - DataStructure/unionfind.hpp
  isVerificationFile: false
  path: DataStructure/rangeparalleluf.hpp
  requiredBy: []
  timestamp: '2024-06-14 02:46:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/rangeparalleluf.hpp
layout: document
redirect_from:
- /library/DataStructure/rangeparalleluf.hpp
- /library/DataStructure/rangeparalleluf.hpp.html
title: Range Parallel UnionFind
---
