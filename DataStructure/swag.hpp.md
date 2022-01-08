---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_queue_operate_all_composite.test.cpp
    title: Verify/LC_queue_operate_all_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Sliding Window Aggregation
    links: []
  bundledCode: "#line 2 \"DataStructure/swag.hpp\"\n\r\ntemplate<typename M,M (*f)(M,M),M\
    \ (*m0)()>struct SWAG{\r\n   stack<M> fval,bval; vector<M> fsum,bsum;\r\n   SWAG(){}\r\
    \n   M fold(){\r\n      if(fsum.empty()){\r\n         if(bsum.empty())return m0();\r\
    \n         return bsum.back();\r\n      }else{\r\n         if(bsum.empty())return\
    \ fsum.back();\r\n         else return f(fsum.back(),bsum.back());\r\n      }\r\
    \n   }\r\n   void push(M x){\r\n      bval.push(x);\r\n      if(bsum.empty())bsum.push_back(x);\r\
    \n      else{\r\n         M y=f(bsum.back(),x);\r\n         bsum.push_back(y);\r\
    \n      }\r\n   }\r\n   void pop(){\r\n      if(fval.empty()){\r\n         bsum.clear();\r\
    \n         while(!bval.empty()){\r\n            auto x=bval.top(); bval.pop();\r\
    \n            fval.push(x);\r\n            if(fsum.empty())fsum.push_back(x);\r\
    \n            else{\r\n               M y=f(x,fsum.back());\r\n              \
    \ fsum.push_back(y);\r\n            }\r\n         }\r\n      }\r\n      fval.pop();\
    \ fsum.pop_back();\r\n   }\r\n};\r\n\r\n/**\r\n * @brief Sliding Window Aggregation\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,M (*f)(M,M),M (*m0)()>struct SWAG{\r\
    \n   stack<M> fval,bval; vector<M> fsum,bsum;\r\n   SWAG(){}\r\n   M fold(){\r\
    \n      if(fsum.empty()){\r\n         if(bsum.empty())return m0();\r\n       \
    \  return bsum.back();\r\n      }else{\r\n         if(bsum.empty())return fsum.back();\r\
    \n         else return f(fsum.back(),bsum.back());\r\n      }\r\n   }\r\n   void\
    \ push(M x){\r\n      bval.push(x);\r\n      if(bsum.empty())bsum.push_back(x);\r\
    \n      else{\r\n         M y=f(bsum.back(),x);\r\n         bsum.push_back(y);\r\
    \n      }\r\n   }\r\n   void pop(){\r\n      if(fval.empty()){\r\n         bsum.clear();\r\
    \n         while(!bval.empty()){\r\n            auto x=bval.top(); bval.pop();\r\
    \n            fval.push(x);\r\n            if(fsum.empty())fsum.push_back(x);\r\
    \n            else{\r\n               M y=f(x,fsum.back());\r\n              \
    \ fsum.push_back(y);\r\n            }\r\n         }\r\n      }\r\n      fval.pop();\
    \ fsum.pop_back();\r\n   }\r\n};\r\n\r\n/**\r\n * @brief Sliding Window Aggregation\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/swag.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_queue_operate_all_composite.test.cpp
documentation_of: DataStructure/swag.hpp
layout: document
redirect_from:
- /library/DataStructure/swag.hpp
- /library/DataStructure/swag.hpp.html
title: Sliding Window Aggregation
---
