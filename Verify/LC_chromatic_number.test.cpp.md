---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/chromatic.hpp
    title: Chromatic Number
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"Verify/LC_chromatic_number.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/chromatic_number\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Graph/chromatic.hpp\"\n\r\nint Chromatic(vector<vector<int>>&\
    \ a){\r\n    int n=a.size();\r\n    vector<int> es(n);\r\n    rep(i,0,n)rep(j,0,n)if(a[i][j]){\r\
    \n        es[i]|=(1<<j);\r\n    }\r\n    vector<int> dp(1<<n),sign(1<<n);\r\n\
    \    dp[0]=1;\r\n    rep(mask,0,1<<n){\r\n        if(mask){\r\n            int\
    \ v=__builtin_ctz(mask);\r\n            dp[mask]=dp[mask^(1<<v)]+dp[(mask^(1<<v))&(~es[v])];\r\
    \n        }\r\n        sign[mask]=((n-__builtin_popcountll(mask))&1?-1:1);\r\n\
    \    }\r\n    int ret=n;\r\n    auto calc=[&](int md)->void{\r\n        vector<ll>\
    \ cur(ALL(sign));\r\n        rep(k,1,ret){\r\n            int cnt=0;\r\n     \
    \       rep(mask,0,1<<n){\r\n                cur[mask]=(cur[mask]*dp[mask])%md;\r\
    \n                if(cur[mask]<0)cur[mask]+=md;\r\n                cnt=(cnt+cur[mask])%md;\r\
    \n            }\r\n            if(cnt!=0){\r\n                ret=k;\r\n     \
    \           break;\r\n            }\r\n        }\r\n    };\r\n    for(auto& md:{998244353,1000000007,1000000011}){\r\
    \n        calc(md);\r\n    }\r\n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Chromatic\
    \ Number\r\n */\n#line 5 \"Verify/LC_chromatic_number.test.cpp\"\n\r\nint main(){\r\
    \n    int n,m;\r\n    cin>>n>>m;\r\n    vector a(n,vector<int>(n));\r\n    rep(i,0,m){\r\
    \n        int x,y;\r\n        cin>>x>>y;\r\n        a[x][y]=a[y][x]=1;\r\n   \
    \ }\r\n    cout<<Chromatic(a)<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Graph/chromatic.hpp\"\r\n\r\
    \nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    vector a(n,vector<int>(n));\r\
    \n    rep(i,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        a[x][y]=a[y][x]=1;\r\
    \n    }\r\n    cout<<Chromatic(a)<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/chromatic.hpp
  isVerificationFile: true
  path: Verify/LC_chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_chromatic_number.test.cpp
- /verify/Verify/LC_chromatic_number.test.cpp.html
title: Verify/LC_chromatic_number.test.cpp
---
