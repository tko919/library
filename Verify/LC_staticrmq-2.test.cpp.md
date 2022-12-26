---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/disjointsparsetable.hpp
    title: Disjoint Sparse Table
  - icon: ':question:'
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
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"DataStructure/disjointsparsetable.hpp\"\
    \n\r\ntemplate<typename T,T (*f)(T,T)>struct DisjointSparseTable{\r\n    vector<vector<T>>\
    \ buf;\r\n    vector<int> height;\r\n    DisjointSparseTable(const vector<T>&\
    \ a){\r\n        int n=a.size(),LG=0;\r\n        while((1<<LG)<=n)LG++;\r\n  \
    \      buf.assign(LG,vector<T>(n));\r\n        height.assign(1<<LG,0);\r\n   \
    \     rep(i,2,1<<LG)height[i]=height[i>>1]+1;\r\n        rep(i,0,n)buf[0][i]=a[i];\r\
    \n        rep(lg,1,LG){\r\n            int add=1<<lg;\r\n            for(int j=0;j<n;j+=(add<<1)){\r\
    \n                int pos=min(j+add,n);\r\n                buf[lg][pos-1]=a[pos-1];\r\
    \n                for(int k=pos-2;k>=j;k--)buf[lg][k]=f(a[k],buf[lg][k+1]);\r\n\
    \                if(n<=pos)break;\r\n                buf[lg][pos]=a[pos];\r\n\
    \                for(int k=pos+1;k<min(pos+add,n);k++)buf[lg][k]=f(buf[lg][k-1],a[k]);\r\
    \n            }\r\n        }\r\n    }\r\n    T query(int L,int R){\r\n       \
    \ if(L>=--R)return buf[0][L];\r\n        return f(buf[height[L^R]][L],buf[height[L^R]][R]);\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Disjoint Sparse Table\r\n */\n#line 5 \"\
    Verify/LC_staticrmq-2.test.cpp\"\n\r\nint f(int a,int b){return min(a,b);}\r\n\
    \r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\n    vector<int> a(n);\r\n\
    \    rep(i,0,n)cin>>a[i];\r\n\r\n    DisjointSparseTable<int,f> st(a);\r\n   \
    \ while(q--){\r\n        int L,R;\r\n        cin>>L>>R;\r\n        cout<<st.query(L,R)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"DataStructure/disjointsparsetable.hpp\"\
    \r\n\r\nint f(int a,int b){return min(a,b);}\r\n\r\nint main(){\r\n    int n,q;\r\
    \n    cin>>n>>q;\r\n    vector<int> a(n);\r\n    rep(i,0,n)cin>>a[i];\r\n\r\n\
    \    DisjointSparseTable<int,f> st(a);\r\n    while(q--){\r\n        int L,R;\r\
    \n        cin>>L>>R;\r\n        cout<<st.query(L,R)<<'\\n';\r\n    }\r\n    return\
    \ 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/disjointsparsetable.hpp
  isVerificationFile: true
  path: Verify/LC_staticrmq-2.test.cpp
  requiredBy: []
  timestamp: '2022-01-20 19:26:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_staticrmq-2.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_staticrmq-2.test.cpp
- /verify/Verify/LC_staticrmq-2.test.cpp.html
title: Verify/LC_staticrmq-2.test.cpp
---
