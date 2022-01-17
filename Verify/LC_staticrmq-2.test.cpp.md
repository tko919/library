---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/sparsetable.hpp
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Verify/LC_staticrmq-2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"DataStructure/sparsetable.hpp\"\
    \n\r\ntemplate<typename T,T (*f)(T,T)>struct SparseTable{\r\n    vector<vector<T>>\
    \ st;\r\n    vector<int> lgtable;\r\n    SparseTable(const vector<T>& v){\r\n\
    \        int LG=0;\r\n        while((1<<LG)<=(int)v.size())LG++;\r\n        st.assign(LG,vector<T>(1<<LG));\r\
    \n        lgtable.assign(v.size()+1,0);\r\n        rep(i,0,v.size())st[0][i]=v[i];\r\
    \n        rep(lg,1,LG){\r\n            for(int j=0;j+(1<<lg)<=(1<<LG);j++){\r\n\
    \                st[lg][j]=f(st[lg-1][j],st[lg-1][j+(1<<(lg-1))]);\r\n       \
    \     }\r\n        }\r\n        rep(i,2,v.size()+1)lgtable[i]=lgtable[i>>1]+1;\r\
    \n    }\r\n    T query(int L,int R){\r\n        int b=lgtable[R-L];\r\n      \
    \  return f(st[b][L],st[b][R-(1<<b)]);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Sparse Table\r\n */\n#line 5 \"Verify/LC_staticrmq-2.test.cpp\"\n\r\nint f(int\
    \ a,int b){return min(a,b);}\r\n\r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\
    \n    vector<int> a(n);\r\n    rep(i,0,n)cin>>a[i];\r\n\r\n    SparseTable<int,f>\
    \ st(a);\r\n    while(q--){\r\n        int L,R;\r\n        cin>>L>>R;\r\n    \
    \    cout<<st.query(L,R)<<'\\n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"DataStructure/sparsetable.hpp\"\r\n\r\
    \nint f(int a,int b){return min(a,b);}\r\n\r\nint main(){\r\n    int n,q;\r\n\
    \    cin>>n>>q;\r\n    vector<int> a(n);\r\n    rep(i,0,n)cin>>a[i];\r\n\r\n \
    \   SparseTable<int,f> st(a);\r\n    while(q--){\r\n        int L,R;\r\n     \
    \   cin>>L>>R;\r\n        cout<<st.query(L,R)<<'\\n';\r\n    }\r\n    return 0;\r\
    \n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/sparsetable.hpp
  isVerificationFile: true
  path: Verify/LC_staticrmq-2.test.cpp
  requiredBy: []
  timestamp: '2022-01-17 15:26:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_staticrmq-2.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_staticrmq-2.test.cpp
- /verify/Verify/LC_staticrmq-2.test.cpp.html
title: Verify/LC_staticrmq-2.test.cpp
---
