---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Prime Sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: lpf table
    links: []
  bundledCode: "#line 2 \"Math/sieve.hpp\"\n\r\ntemplate<int L=50101010>vector<int>\
    \ sieve(int N){\r\n    bitset<L> isp;\r\n    int n,sq=ceil(sqrt(N));\r\n    for(int\
    \ z=1;z<=5;z+=4){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for(int x=1;x<=sq\
    \ and (n=4*x*x+y*y)<=N;++x){\r\n                isp[n].flip();\r\n           \
    \ }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\n       \
    \         isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n    for(int\
    \ z=2;z<=4;z+=2){\r\n        for(int y=z;y<=sq;y+=6){\r\n            for (int\
    \ x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){\r\n                isp[n].flip();\r\n\
    \            }\r\n            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){\r\
    \n                isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n  \
    \  for(int y=3;y<=sq;y+=6){\r\n        for(int z=1;z<=2;++z){\r\n            for(int\
    \ x=z;x<=sq and (n=4*x*x+y*y)<=N;x+=3){\r\n                isp[n].flip();\r\n\
    \            }\r\n        }\r\n    }\r\n    for(int n=5;n<=sq;++n)if(isp[n]){\r\
    \n        for(int k=n*n;k<=N;k+=n*n){\r\n            isp[k]=false;\r\n       \
    \ }\r\n    }\r\n    isp[2]=isp[3]=true;\r\n\r\n    vector<int> ret;\r\n    for(int\
    \ i=2;i<=N;i++)if(isp[i]){\r\n        ret.push_back(i);\r\n    }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"Math/lpftable.hpp\"\
    \n\nvector<int> lpftable(ll n) {\n    auto ps = sieve(n);\n    vector<int> ret(n\
    \ + 1, -1);\n    reverse(ALL(ps));\n    for (auto &p : ps) {\n        for (ll\
    \ q = p; q <= n; q += p)\n            ret[q] = p;\n    }\n    return ret;\n}\n\
    \n/**\n * @brief lpf table\n */\n"
  code: "#pragma once\n#include \"Math/sieve.hpp\"\n\nvector<int> lpftable(ll n) {\n\
    \    auto ps = sieve(n);\n    vector<int> ret(n + 1, -1);\n    reverse(ALL(ps));\n\
    \    for (auto &p : ps) {\n        for (ll q = p; q <= n; q += p)\n          \
    \  ret[q] = p;\n    }\n    return ret;\n}\n\n/**\n * @brief lpf table\n */"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Math/lpftable.hpp
  requiredBy: []
  timestamp: '2024-12-26 05:48:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/lpftable.hpp
layout: document
redirect_from:
- /library/Math/lpftable.hpp
- /library/Math/lpftable.hpp.html
title: lpf table
---
