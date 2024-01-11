---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_enumerate_palindromes.test.cpp
    title: Verify/LC_enumerate_palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Manacher Algorithm
    links: []
  bundledCode: "#line 2 \"String/manacher.hpp\"\n\r\nvector<int> Manacher(const string&\
    \ s){\r\n   string t;\r\n   for(auto& c:s){\r\n      t.push_back(c);\r\n     \
    \ t.push_back('$');\r\n   }\r\n   t.pop_back();\r\n   int i=0,j=0,n=t.size();\
    \ vector<int> res(n);\r\n   while(i<n){\r\n      while(i-j>=0 and i+j<n and t[i-j]==t[i+j])j++;\r\
    \n      res[i]=j;\r\n      int k=1;\r\n      while(i-k>=0 and i+k<n and k+res[i-k]<j){\r\
    \n         res[i+k]=res[i-k]; k++;\r\n      }\r\n      i+=k; j-=k;\r\n   }\r\n\
    \   for(int i=0;i<n;i++){\r\n      if(i&1)res[i]=(res[i]/2)*2;\r\n      else res[i]=((res[i]+1)/2)*2-1;\r\
    \n   }\r\n   return res;\r\n}\r\n\r\n/**\r\n * @brief Manacher Algorithm\r\n */\n"
  code: "#pragma once\r\n\r\nvector<int> Manacher(const string& s){\r\n   string t;\r\
    \n   for(auto& c:s){\r\n      t.push_back(c);\r\n      t.push_back('$');\r\n \
    \  }\r\n   t.pop_back();\r\n   int i=0,j=0,n=t.size(); vector<int> res(n);\r\n\
    \   while(i<n){\r\n      while(i-j>=0 and i+j<n and t[i-j]==t[i+j])j++;\r\n  \
    \    res[i]=j;\r\n      int k=1;\r\n      while(i-k>=0 and i+k<n and k+res[i-k]<j){\r\
    \n         res[i+k]=res[i-k]; k++;\r\n      }\r\n      i+=k; j-=k;\r\n   }\r\n\
    \   for(int i=0;i<n;i++){\r\n      if(i&1)res[i]=(res[i]/2)*2;\r\n      else res[i]=((res[i]+1)/2)*2-1;\r\
    \n   }\r\n   return res;\r\n}\r\n\r\n/**\r\n * @brief Manacher Algorithm\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: String/manacher.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_enumerate_palindromes.test.cpp
documentation_of: String/manacher.hpp
layout: document
redirect_from:
- /library/String/manacher.hpp
- /library/String/manacher.hpp.html
title: Manacher Algorithm
---
