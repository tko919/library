---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_cartesian_tree.test.cpp
    title: Verify/LC_cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Cartesian Tree
    links: []
  bundledCode: "#line 2 \"Algorithm/cartesian.hpp\"\n\r\nvector<int> Cartesian(const\
    \ vector<int>& a){\r\n   const int n=a.size(); vector<int> res(n,-1);\r\n   int\
    \ cur;\r\n   rep(i,1,n){\r\n      cur=i-1;\r\n      if(a[cur]>a[i]){\r\n     \
    \    int pre=cur;\r\n         while(cur!=-1 and a[cur]>a[i])pre=cur,cur=res[cur];\r\
    \n         if(cur==-1){res[i]=-1; res[pre]=i;}\r\n         else{res[i]=cur; res[pre]=i;}\r\
    \n      }\r\n      else res[i]=cur;\r\n   } return res;\r\n}\r\n\r\n/**\r\n *\
    \ @brief Cartesian Tree\r\n */\n"
  code: "#pragma once\r\n\r\nvector<int> Cartesian(const vector<int>& a){\r\n   const\
    \ int n=a.size(); vector<int> res(n,-1);\r\n   int cur;\r\n   rep(i,1,n){\r\n\
    \      cur=i-1;\r\n      if(a[cur]>a[i]){\r\n         int pre=cur;\r\n       \
    \  while(cur!=-1 and a[cur]>a[i])pre=cur,cur=res[cur];\r\n         if(cur==-1){res[i]=-1;\
    \ res[pre]=i;}\r\n         else{res[i]=cur; res[pre]=i;}\r\n      }\r\n      else\
    \ res[i]=cur;\r\n   } return res;\r\n}\r\n\r\n/**\r\n * @brief Cartesian Tree\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/cartesian.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_cartesian_tree.test.cpp
documentation_of: Algorithm/cartesian.hpp
layout: document
redirect_from:
- /library/Algorithm/cartesian.hpp
- /library/Algorithm/cartesian.hpp.html
title: Cartesian Tree
---
