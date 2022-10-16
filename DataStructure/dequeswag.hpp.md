---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Sliding Window Aggregation for deque
    links: []
  bundledCode: "#line 2 \"DataStructure/dequeswag.hpp\"\n\r\ntemplate<typename M,M\
    \ (*f)(M,M),M (*m0)()>struct SWAGdeque{\r\n    stack<M> fval,bval;\r\n    vector<M>\
    \ fsum,bsum;\r\n    SWAGdeque():fsum({m0()}),bsum({m0()}){}\r\n    M fold(){\r\
    \n        return f(fsum.back(),bsum.back());\r\n    }\r\n    void push_front(M\
    \ v){\r\n        fval.push(v);\r\n        fsum.push_back(f(v,fsum.back()));\r\n\
    \    }\r\n    void push_back(M v){\r\n        bval.push(v);\r\n        bsum.push_back(f(bsum.back(),v));\r\
    \n    }\r\n    void pop_front(){\r\n        if(fval.empty()){\r\n            int\
    \ sz=bval.size();\r\n            stack<M> buf;\r\n            rep(_,0,sz/2){\r\
    \n                buf.push(bval.top());\r\n                bval.pop();\r\n   \
    \         }\r\n            rep(_,sz/2,sz){\r\n                fval.push(bval.top());\r\
    \n                fsum.push_back(f(bval.top(),fsum.back()));\r\n             \
    \   bval.pop();\r\n            }\r\n            bsum={m0()};\r\n            while(!buf.empty()){\r\
    \n                bval.push(buf.top());\r\n                bsum.push_back(f(bsum.back(),buf.top()));\r\
    \n                buf.pop();\r\n            }\r\n        }\r\n        fval.pop();\r\
    \n        fsum.pop_back();\r\n    }\r\n    void pop_back(){\r\n        if(bval.empty()){\r\
    \n            int sz=fval.size();\r\n            stack<M> buf;\r\n           \
    \ rep(_,0,sz/2){\r\n                buf.push(fval.top());\r\n                fval.pop();\r\
    \n            }\r\n            rep(_,sz/2,sz){\r\n                bval.push(fval.top());\r\
    \n                bsum.push_back(f(bsum.back(),fval.top()));\r\n             \
    \   fval.pop();\r\n            }\r\n            fsum={m0()};\r\n            while(!buf.empty()){\r\
    \n                fval.push(buf.top());\r\n                fsum.push_back(f(buf.top(),fsum.back()));\r\
    \n                buf.pop();\r\n            }\r\n        }\r\n        bval.pop();\r\
    \n        bsum.pop_back();\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Sliding Window\
    \ Aggregation for deque\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename M,M (*f)(M,M),M (*m0)()>struct SWAGdeque{\r\
    \n    stack<M> fval,bval;\r\n    vector<M> fsum,bsum;\r\n    SWAGdeque():fsum({m0()}),bsum({m0()}){}\r\
    \n    M fold(){\r\n        return f(fsum.back(),bsum.back());\r\n    }\r\n   \
    \ void push_front(M v){\r\n        fval.push(v);\r\n        fsum.push_back(f(v,fsum.back()));\r\
    \n    }\r\n    void push_back(M v){\r\n        bval.push(v);\r\n        bsum.push_back(f(bsum.back(),v));\r\
    \n    }\r\n    void pop_front(){\r\n        if(fval.empty()){\r\n            int\
    \ sz=bval.size();\r\n            stack<M> buf;\r\n            rep(_,0,sz/2){\r\
    \n                buf.push(bval.top());\r\n                bval.pop();\r\n   \
    \         }\r\n            rep(_,sz/2,sz){\r\n                fval.push(bval.top());\r\
    \n                fsum.push_back(f(bval.top(),fsum.back()));\r\n             \
    \   bval.pop();\r\n            }\r\n            bsum={m0()};\r\n            while(!buf.empty()){\r\
    \n                bval.push(buf.top());\r\n                bsum.push_back(f(bsum.back(),buf.top()));\r\
    \n                buf.pop();\r\n            }\r\n        }\r\n        fval.pop();\r\
    \n        fsum.pop_back();\r\n    }\r\n    void pop_back(){\r\n        if(bval.empty()){\r\
    \n            int sz=fval.size();\r\n            stack<M> buf;\r\n           \
    \ rep(_,0,sz/2){\r\n                buf.push(fval.top());\r\n                fval.pop();\r\
    \n            }\r\n            rep(_,sz/2,sz){\r\n                bval.push(fval.top());\r\
    \n                bsum.push_back(f(bsum.back(),fval.top()));\r\n             \
    \   fval.pop();\r\n            }\r\n            fsum={m0()};\r\n            while(!buf.empty()){\r\
    \n                fval.push(buf.top());\r\n                fsum.push_back(f(buf.top(),fsum.back()));\r\
    \n                buf.pop();\r\n            }\r\n        }\r\n        bval.pop();\r\
    \n        bsum.pop_back();\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Sliding Window\
    \ Aggregation for deque\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/dequeswag.hpp
  requiredBy: []
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/dequeswag.hpp
layout: document
redirect_from:
- /library/DataStructure/dequeswag.hpp
- /library/DataStructure/dequeswag.hpp.html
title: Sliding Window Aggregation for deque
---
