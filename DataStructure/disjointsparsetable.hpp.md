---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_staticrmq-2.test.cpp
    title: Verify/LC_staticrmq-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Disjoint Sparse Table
    links: []
  bundledCode: "#line 2 \"DataStructure/disjointsparsetable.hpp\"\n\r\ntemplate<typename\
    \ T,T (*f)(T,T)>struct DisjointSparseTable{\r\n    vector<vector<T>> buf;\r\n\
    \    vector<int> height;\r\n    DisjointSparseTable(const vector<T>& a){\r\n \
    \       int n=a.size(),LG=0;\r\n        while((1<<LG)<=n)LG++;\r\n        buf.assign(LG,vector<T>(n));\r\
    \n        height.assign(1<<LG,0);\r\n        rep(i,2,1<<LG)height[i]=height[i>>1]+1;\r\
    \n        rep(i,0,n)buf[0][i]=a[i];\r\n        rep(lg,1,LG){\r\n            int\
    \ add=1<<lg;\r\n            for(int j=0;j<n;j+=(add<<1)){\r\n                int\
    \ pos=min(j+add,n);\r\n                buf[lg][pos-1]=a[pos-1];\r\n          \
    \      for(int k=pos-2;k>=j;k--)buf[lg][k]=f(a[k],buf[lg][k+1]);\r\n         \
    \       if(n<=pos)break;\r\n                buf[lg][pos]=a[pos];\r\n         \
    \       for(int k=pos+1;k<min(pos+add,n);k++)buf[lg][k]=f(buf[lg][k-1],a[k]);\r\
    \n            }\r\n        }\r\n    }\r\n    T query(int L,int R){\r\n       \
    \ if(L>=--R)return buf[0][L];\r\n        return f(buf[height[L^R]][L],buf[height[L^R]][R]);\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Disjoint Sparse Table\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T (*f)(T,T)>struct DisjointSparseTable{\r\
    \n    vector<vector<T>> buf;\r\n    vector<int> height;\r\n    DisjointSparseTable(const\
    \ vector<T>& a){\r\n        int n=a.size(),LG=0;\r\n        while((1<<LG)<=n)LG++;\r\
    \n        buf.assign(LG,vector<T>(n));\r\n        height.assign(1<<LG,0);\r\n\
    \        rep(i,2,1<<LG)height[i]=height[i>>1]+1;\r\n        rep(i,0,n)buf[0][i]=a[i];\r\
    \n        rep(lg,1,LG){\r\n            int add=1<<lg;\r\n            for(int j=0;j<n;j+=(add<<1)){\r\
    \n                int pos=min(j+add,n);\r\n                buf[lg][pos-1]=a[pos-1];\r\
    \n                for(int k=pos-2;k>=j;k--)buf[lg][k]=f(a[k],buf[lg][k+1]);\r\n\
    \                if(n<=pos)break;\r\n                buf[lg][pos]=a[pos];\r\n\
    \                for(int k=pos+1;k<min(pos+add,n);k++)buf[lg][k]=f(buf[lg][k-1],a[k]);\r\
    \n            }\r\n        }\r\n    }\r\n    T query(int L,int R){\r\n       \
    \ if(L>=--R)return buf[0][L];\r\n        return f(buf[height[L^R]][L],buf[height[L^R]][R]);\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Disjoint Sparse Table\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/disjointsparsetable.hpp
  requiredBy: []
  timestamp: '2022-01-20 19:26:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_staticrmq-2.test.cpp
documentation_of: DataStructure/disjointsparsetable.hpp
layout: document
redirect_from:
- /library/DataStructure/disjointsparsetable.hpp
- /library/DataStructure/disjointsparsetable.hpp.html
title: Disjoint Sparse Table
---
