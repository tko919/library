---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_zalgorithm.test.cpp
    title: Verify/LC_zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Z-Algorithm
    links: []
  bundledCode: "#line 2 \"String/zalgo.hpp\"\n\r\ntemplate<typename T>vector<int>\
    \ Zalgo(T& s){\r\n   int n=s.size(); vector<int> res(n);\r\n   for(int i=1,j=0;i<n;i++){\r\
    \n      if(i+res[i-j]<j+res[j])res[i]=res[i-j];\r\n      else{\r\n         int\
    \ k=max(0,j+res[j]-i);\r\n         while(i+k<n&&s[k]==s[i+k])k++;\r\n        \
    \ res[i]=k; j=i;\r\n      }\r\n   } res[0]=n; return res;\r\n}\r\n\r\n/**\r\n\
    \ * @brief Z-Algorithm \r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>vector<int> Zalgo(T& s){\r\n   int\
    \ n=s.size(); vector<int> res(n);\r\n   for(int i=1,j=0;i<n;i++){\r\n      if(i+res[i-j]<j+res[j])res[i]=res[i-j];\r\
    \n      else{\r\n         int k=max(0,j+res[j]-i);\r\n         while(i+k<n&&s[k]==s[i+k])k++;\r\
    \n         res[i]=k; j=i;\r\n      }\r\n   } res[0]=n; return res;\r\n}\r\n\r\n\
    /**\r\n * @brief Z-Algorithm \r\n */"
  dependsOn: []
  isVerificationFile: false
  path: String/zalgo.hpp
  requiredBy: []
  timestamp: '2023-01-17 03:12:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_zalgorithm.test.cpp
documentation_of: String/zalgo.hpp
layout: document
redirect_from:
- /library/String/zalgo.hpp
- /library/String/zalgo.hpp.html
title: Z-Algorithm
---
