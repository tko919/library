---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Slope Trick
    links: []
  bundledCode: "#line 2 \"DataStructure/slopetrick.hpp\"\n\r\ntemplate<typename T,T\
    \ mx>struct SlopeTrick{\r\n    T mn=0,addL=0,addR=0;\r\n    priority_queue<T>\
    \ L;\r\n    priority_queue<T,vector<T>,greater<T>> R;\r\n    SlopeTrick(){\r\n\
    \        L.push(-mx);\r\n        R.push(mx);\r\n    }\r\n    T getmin(){return\
    \ mn;}\r\n    pair<T,T> argmin(){\r\n        return {L.top()+addL,R.top()+addR};\r\
    \n    }\r\n    void addConst(T a){mn+=a;}\r\n    void addx_a(T a){\r\n       \
    \ mn+=max(T(0),L.top()+addL-a);\r\n        L.push(a-addL);\r\n        R.push(L.top()+addL-addR);\r\
    \n        L.pop();\r\n    }\r\n    void adda_x(T a){\r\n        mn+=max(T(0),a-(R.top()+addR));\r\
    \n        R.push(a-addR);\r\n        L.push(R.top()+addR-addL);\r\n        R.pop();\r\
    \n    }\r\n    void addAbs(T a){\r\n        addx_a(a);\r\n        adda_x(a);\r\
    \n    }\r\n    void chminRight(){\r\n        priority_queue<T,vector<T>,greater<T>>\
    \ nxt;\r\n        nxt.push(mx);\r\n        swap(R,nxt);\r\n        addR=0;\r\n\
    \    }\r\n    void chminLeft(){\r\n        priority_queue<T> nxt;\r\n        nxt.push(-mx);\r\
    \n        swap(L,nxt);\r\n        addL=0;\r\n    }\r\n    void shiftLeft(T a){\r\
    \n        addL+=a;\r\n    }\r\n    void shiftRight(T a){\r\n        addR+=a;\r\
    \n    }\r\n    void shift(T a){\r\n        shiftRight(a);\r\n        shiftLeft(a);\r\
    \n    }\r\n    T eval(T x_0){\r\n        T y=mn;\r\n        while(!L.empty()){\r\
    \n            auto x=L.top();\r\n            L.pop();\r\n            y+=max(T(0),(x+addL)-x_0);\r\
    \n        }\r\n        while(!R.empty()){\r\n            auto x=R.top();\r\n \
    \           R.pop();\r\n            y+=max(T(0),x_0-(x+addR));\r\n        }\r\n\
    \        return y;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Slope Trick\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,T mx>struct SlopeTrick{\r\n    T\
    \ mn=0,addL=0,addR=0;\r\n    priority_queue<T> L;\r\n    priority_queue<T,vector<T>,greater<T>>\
    \ R;\r\n    SlopeTrick(){\r\n        L.push(-mx);\r\n        R.push(mx);\r\n \
    \   }\r\n    T getmin(){return mn;}\r\n    pair<T,T> argmin(){\r\n        return\
    \ {L.top()+addL,R.top()+addR};\r\n    }\r\n    void addConst(T a){mn+=a;}\r\n\
    \    void addx_a(T a){\r\n        mn+=max(T(0),L.top()+addL-a);\r\n        L.push(a-addL);\r\
    \n        R.push(L.top()+addL-addR);\r\n        L.pop();\r\n    }\r\n    void\
    \ adda_x(T a){\r\n        mn+=max(T(0),a-(R.top()+addR));\r\n        R.push(a-addR);\r\
    \n        L.push(R.top()+addR-addL);\r\n        R.pop();\r\n    }\r\n    void\
    \ addAbs(T a){\r\n        addx_a(a);\r\n        adda_x(a);\r\n    }\r\n    void\
    \ chminRight(){\r\n        priority_queue<T,vector<T>,greater<T>> nxt;\r\n   \
    \     nxt.push(mx);\r\n        swap(R,nxt);\r\n        addR=0;\r\n    }\r\n  \
    \  void chminLeft(){\r\n        priority_queue<T> nxt;\r\n        nxt.push(-mx);\r\
    \n        swap(L,nxt);\r\n        addL=0;\r\n    }\r\n    void shiftLeft(T a){\r\
    \n        addL+=a;\r\n    }\r\n    void shiftRight(T a){\r\n        addR+=a;\r\
    \n    }\r\n    void shift(T a){\r\n        shiftRight(a);\r\n        shiftLeft(a);\r\
    \n    }\r\n    T eval(T x_0){\r\n        T y=mn;\r\n        while(!L.empty()){\r\
    \n            auto x=L.top();\r\n            L.pop();\r\n            y+=max(T(0),(x+addL)-x_0);\r\
    \n        }\r\n        while(!R.empty()){\r\n            auto x=R.top();\r\n \
    \           R.pop();\r\n            y+=max(T(0),x_0-(x+addR));\r\n        }\r\n\
    \        return y;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Slope Trick\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/slopetrick.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/slopetrick.hpp
layout: document
redirect_from:
- /library/DataStructure/slopetrick.hpp
- /library/DataStructure/slopetrick.hpp.html
title: Slope Trick
---
