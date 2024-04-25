---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/disjointsparsetable.hpp
    title: Disjoint Sparse Table
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Verify/LC_staticrmq-2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b-1); i >= (int)(a); i--)\r\n#define\
    \ ALL(v) (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\r\n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\
    \n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a\
    \ = b;\r\n        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename\
    \ U> T ceil(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x\
    \ = -x, y = -y;\r\n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate\
    \ <typename T, typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if\
    \ (y < 0)\r\n        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1)\
    \ / y);\r\n}\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
    \n}\r\ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x));\r\n}\r\ntemplate <typename T> int lowbit(T x) {\r\n \
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\n#ifdef LOCAL\r\n#define\
    \ show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\n#else\r\n#define show(...)\
    \ true\r\n#endif\r\ntemplate <typename T> void _show(int i, T name) {\r\n    cerr\
    \ << '\\n';\r\n}\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid\
    \ _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i]\
    \ != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\"\
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\r\ntemplate <class T, class\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os << \"\
    P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\ntemplate\
    \ <typename T, template <class> class C>\r\nostream &operator<<(ostream &os, const\
    \ C<T> &v) {\r\n    os << \"[\";\r\n    for (auto d : v)\r\n        os << d <<\
    \ \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"DataStructure/disjointsparsetable.hpp\"\
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
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_staticrmq-2.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_staticrmq-2.test.cpp
- /verify/Verify/LC_staticrmq-2.test.cpp.html
title: Verify/LC_staticrmq-2.test.cpp
---
