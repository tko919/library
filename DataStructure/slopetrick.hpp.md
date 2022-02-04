---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/slopetrick.md
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
    \        return y;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Slope Trick\r\n * @docs\
    \ docs/slopetrick.md\r\n */\n"
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
    \        return y;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Slope Trick\r\n * @docs\
    \ docs/slopetrick.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/slopetrick.hpp
  requiredBy: []
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/slopetrick.hpp
layout: document
redirect_from:
- /library/DataStructure/slopetrick.hpp
- /library/DataStructure/slopetrick.hpp.html
title: Slope Trick
---
## 使い方

`SlopeTrick()`: 空のデータ構造を作成。  
`T getmin()`: 凸関数の最小値。  
`pair<T,T> argmin()`: 凸関数の最小値となる $x$ の閉区間。  
`void addConst(T a)`: $y=a$ を凸関数に加算。  
`void addx_a(T a)`: $y=\max(0,x-a)$ を凸関数に加算。  
`void adda_x(T a)`: $y=\max(0,a-x)$ を凸関数に加算。  
`void addAbs(T a)`: $y=|x-a|$ を凸関数に加算。  
`void chminRight()`: 正の方向に向かって累積最小値を取る。  
`void chminLeft()`: 負の方向に向かって累積最小値を取る。  
`void shiftLeft(T a)`: $g(x)=\max_{t \in [x-a,x]} f(t)$ を計算。  
`void shiftRight(T a)`: $g(x)=\min_{t \in [x-a,x]} f(t)$ を計算。  
`void shift(T a)`: $g(x)=f(x-a)$ を計算。  
`T eval(T x_0)`: $x=x_0$ での値を計算。(破壊的)