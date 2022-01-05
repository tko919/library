---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fast IO
    links: []
  bundledCode: "#line 2 \"Utility/fastio.hpp\"\n\r\ntemplate<typename T=int>inline\
    \ T get(){\r\n   char c=getchar(); bool neg=(c=='-');\r\n   T res=neg?0:c-'0';\
    \ while(isdigit(c=getchar()))res=res*10+(c-'0');\r\n   return neg?-res:res;\r\n\
    }\r\ntemplate<typename T=int>inline void put(T x,char c='\\n'){\r\n   int d[20],i=0;\
    \ if(x<0)putchar('-'),x*=-1;\r\n   do{d[i++]=x%10;}while(x/=10); while(i--)putchar('0'+d[i]);\r\
    \n   putchar(c);\r\n}\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T=int>inline T get(){\r\n   char c=getchar();\
    \ bool neg=(c=='-');\r\n   T res=neg?0:c-'0'; while(isdigit(c=getchar()))res=res*10+(c-'0');\r\
    \n   return neg?-res:res;\r\n}\r\ntemplate<typename T=int>inline void put(T x,char\
    \ c='\\n'){\r\n   int d[20],i=0; if(x<0)putchar('-'),x*=-1;\r\n   do{d[i++]=x%10;}while(x/=10);\
    \ while(i--)putchar('0'+d[i]);\r\n   putchar(c);\r\n}\r\n\r\n/**\r\n * @brief\
    \ Fast IO\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Utility/fastio.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/fastio.hpp
layout: document
redirect_from:
- /library/Utility/fastio.hpp
- /library/Utility/fastio.hpp.html
title: Fast IO
---
