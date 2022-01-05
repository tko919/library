---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Z-Algorithm
    links: []
  bundledCode: "#line 2 \"String/zalgo.hpp\"\n\r\nvector<int> z_algo(string s){\r\n\
    \   int n=s.size(); vector<int> res(n);\r\n   for(int i=1,j=0;i<n;i++){\r\n  \
    \    if(i+res[i-j]<j+res[j])res[i]=res[i-j];\r\n      else{\r\n         int k=max(0,j+res[j]-i);\r\
    \n         while(i+k<n&&s[k]==s[i+k])k++;\r\n         res[i]=k; j=i;\r\n     \
    \ }\r\n   } res[0]=n; return res;\r\n}\r\n\r\n/**\r\n * @brief Z-Algorithm\r\n\
    \ */\n"
  code: "#pragma once\r\n\r\nvector<int> z_algo(string s){\r\n   int n=s.size(); vector<int>\
    \ res(n);\r\n   for(int i=1,j=0;i<n;i++){\r\n      if(i+res[i-j]<j+res[j])res[i]=res[i-j];\r\
    \n      else{\r\n         int k=max(0,j+res[j]-i);\r\n         while(i+k<n&&s[k]==s[i+k])k++;\r\
    \n         res[i]=k; j=i;\r\n      }\r\n   } res[0]=n; return res;\r\n}\r\n\r\n\
    /**\r\n * @brief Z-Algorithm\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: String/zalgo.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/zalgo.hpp
layout: document
redirect_from:
- /library/String/zalgo.hpp
- /library/String/zalgo.hpp.html
title: Z-Algorithm
---
