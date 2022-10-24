---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_chromatic_number.test.cpp
    title: Verify/LC_chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Chromatic Number
    links: []
  bundledCode: "#line 2 \"Graph/chromatic.hpp\"\n\r\nstruct Chromatic{\r\n    const\
    \ int n;\r\n    vector<ll> es;\r\n    Chromatic(int _n):n(_n),es(n){}\r\n    void\
    \ add_edge(int u,int v){\r\n        es[u]|=1<<v;\r\n        es[v]|=1<<u;\r\n \
    \   }\r\n    int run(){\r\n        vector<int> dp(1<<n),sign(1<<n);\r\n      \
    \  dp[0]=1;\r\n        rep(mask,0,1<<n){\r\n            if(mask){\r\n        \
    \        int v=__builtin_ctz(mask);\r\n                dp[mask]=dp[mask^(1<<v)]+dp[(mask^(1<<v))&(~es[v])];\r\
    \n            }\r\n            sign[mask]=((n-__builtin_popcountll(mask))&1?-1:1);\r\
    \n        }\r\n        int ret=n;\r\n        auto calc=[&](int md)->void{\r\n\
    \            vector<ll> cur(ALL(sign));\r\n            rep(k,1,ret){\r\n     \
    \           int cnt=0;\r\n                rep(mask,0,1<<n){\r\n              \
    \      cur[mask]=(cur[mask]*dp[mask])%md;\r\n                    if(cur[mask]<0)cur[mask]+=md;\r\
    \n                    cnt=(cnt+cur[mask])%md;\r\n                }\r\n       \
    \         if(cnt!=0){\r\n                    ret=k;\r\n                    break;\r\
    \n                }\r\n            }\r\n        };\r\n        for(auto& md:{998244353,1000000007,1000000011}){\r\
    \n            calc(md);\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Chromatic Number\r\n */\n"
  code: "#pragma once\r\n\r\nstruct Chromatic{\r\n    const int n;\r\n    vector<ll>\
    \ es;\r\n    Chromatic(int _n):n(_n),es(n){}\r\n    void add_edge(int u,int v){\r\
    \n        es[u]|=1<<v;\r\n        es[v]|=1<<u;\r\n    }\r\n    int run(){\r\n\
    \        vector<int> dp(1<<n),sign(1<<n);\r\n        dp[0]=1;\r\n        rep(mask,0,1<<n){\r\
    \n            if(mask){\r\n                int v=__builtin_ctz(mask);\r\n    \
    \            dp[mask]=dp[mask^(1<<v)]+dp[(mask^(1<<v))&(~es[v])];\r\n        \
    \    }\r\n            sign[mask]=((n-__builtin_popcountll(mask))&1?-1:1);\r\n\
    \        }\r\n        int ret=n;\r\n        auto calc=[&](int md)->void{\r\n \
    \           vector<ll> cur(ALL(sign));\r\n            rep(k,1,ret){\r\n      \
    \          int cnt=0;\r\n                rep(mask,0,1<<n){\r\n               \
    \     cur[mask]=(cur[mask]*dp[mask])%md;\r\n                    if(cur[mask]<0)cur[mask]+=md;\r\
    \n                    cnt=(cnt+cur[mask])%md;\r\n                }\r\n       \
    \         if(cnt!=0){\r\n                    ret=k;\r\n                    break;\r\
    \n                }\r\n            }\r\n        };\r\n        for(auto& md:{998244353,1000000007,1000000011}){\r\
    \n            calc(md);\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\
    \r\n/**\r\n * @brief Chromatic Number\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/chromatic.hpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_chromatic_number.test.cpp
documentation_of: Graph/chromatic.hpp
layout: document
redirect_from:
- /library/Graph/chromatic.hpp
- /library/Graph/chromatic.hpp.html
title: Chromatic Number
---
