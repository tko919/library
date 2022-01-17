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
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"DataStructure/sparsetable.hpp\"\n\r\ntemplate<typename T,T\
    \ (*f)(T,T)>struct SparseTable{\r\n    vector<vector<T>> st;\r\n    vector<int>\
    \ lgtable;\r\n    SparseTable(const vector<T>& v){\r\n        int LG=0;\r\n  \
    \      while((1<<LG)<=(int)v.size())LG++;\r\n        st.assign(LG,vector<T>(1<<LG));\r\
    \n        lgtable.assign(v.size()+1,0);\r\n        rep(i,0,v.size())st[0][i]=v[i];\r\
    \n        rep(lg,1,LG){\r\n            for(int j=0;j+(1<<lg)<=(1<<LG);j++){\r\n\
    \                st[lg][j]=f(st[lg-1][j],st[lg-1][j+(1<<(lg-1))]);\r\n       \
    \     }\r\n        }\r\n        rep(i,2,v.size()+1)lgtable[i]=lgtable[i>>1]+1;\r\
    \n    }\r\n    T query(int L,int R){\r\n        int b=lgtable[R-L];\r\n      \
    \  return f(st[b][L],st[b][R-(1<<b)]);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Sparse Table\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T (*f)(T,T)>struct SparseTable{\r\
    \n    vector<vector<T>> st;\r\n    vector<int> lgtable;\r\n    SparseTable(const\
    \ vector<T>& v){\r\n        int LG=0;\r\n        while((1<<LG)<=(int)v.size())LG++;\r\
    \n        st.assign(LG,vector<T>(1<<LG));\r\n        lgtable.assign(v.size()+1,0);\r\
    \n        rep(i,0,v.size())st[0][i]=v[i];\r\n        rep(lg,1,LG){\r\n       \
    \     for(int j=0;j+(1<<lg)<=(1<<LG);j++){\r\n                st[lg][j]=f(st[lg-1][j],st[lg-1][j+(1<<(lg-1))]);\r\
    \n            }\r\n        }\r\n        rep(i,2,v.size()+1)lgtable[i]=lgtable[i>>1]+1;\r\
    \n    }\r\n    T query(int L,int R){\r\n        int b=lgtable[R-L];\r\n      \
    \  return f(st[b][L],st[b][R-(1<<b)]);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Sparse Table\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/sparsetable.hpp
  requiredBy: []
  timestamp: '2022-01-17 15:26:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_staticrmq-2.test.cpp
documentation_of: DataStructure/sparsetable.hpp
layout: document
redirect_from:
- /library/DataStructure/sparsetable.hpp
- /library/DataStructure/sparsetable.hpp.html
title: Sparse Table
---
