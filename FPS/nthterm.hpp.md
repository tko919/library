---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bostan-Mori Algorithm
    links: []
  bundledCode: "#line 2 \"FPS/nthterm.hpp\"\n\r\ntemplate<typename T>T nth(Poly<T>\
    \ p,Poly<T> q,ll n){\r\n    while(n){\r\n        Poly<T> base(q),np,nq;\r\n  \
    \      for(int i=1;i<(int)q.size();i+=2)base[i]=-base[i];\r\n        p*=base;\
    \ q*=base;\r\n        for(int i=n&1;i<(int)p.size();i+=2)np.emplace_back(p[i]);\r\
    \n        for(int i=0;i<(int)q.size();i+=2)nq.emplace_back(q[i]);\r\n        swap(p,np);\
    \ swap(q,nq);\r\n        n>>=1;\r\n    }\r\n    return p[0]/q[0];\r\n}\r\n\r\n\
    /**\r\n * @brief Bostan-Mori Algorithm\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>T nth(Poly<T> p,Poly<T> q,ll n){\r\
    \n    while(n){\r\n        Poly<T> base(q),np,nq;\r\n        for(int i=1;i<(int)q.size();i+=2)base[i]=-base[i];\r\
    \n        p*=base; q*=base;\r\n        for(int i=n&1;i<(int)p.size();i+=2)np.emplace_back(p[i]);\r\
    \n        for(int i=0;i<(int)q.size();i+=2)nq.emplace_back(q[i]);\r\n        swap(p,np);\
    \ swap(q,nq);\r\n        n>>=1;\r\n    }\r\n    return p[0]/q[0];\r\n}\r\n\r\n\
    /**\r\n * @brief Bostan-Mori Algorithm\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/nthterm.hpp
  requiredBy: []
  timestamp: '2022-02-02 03:30:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: FPS/nthterm.hpp
layout: document
redirect_from:
- /library/FPS/nthterm.hpp
- /library/FPS/nthterm.hpp.html
title: Bostan-Mori Algorithm
---
