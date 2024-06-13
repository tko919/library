---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/scc.hpp
    title: Strongly Connected Components
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Verify/LC_scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define\
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
    \ <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {\r\n    os <<\
    \ \"{\";\r\n    for (int i = 0; i < vec.size(); i++) {\r\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \", \");\r\n    }\r\n    os << \"}\";\r\n \
    \   return os;\r\n}\r\ntemplate <typename T, typename U>\r\nostream &operator<<(ostream\
    \ &os, map<T, U> &map_var) {\r\n    os << \"{\";\r\n    for (auto itr = map_var.begin();\
    \ itr != map_var.end();\r\n         itr++) {\r\n        os << \"(\" << itr->first\
    \ << \", \" << itr->second << \")\";\r\n        itr++;\r\n        if (itr != map_var.end())\r\
    \n            os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n\
    \    return os;\r\n}\r\ntemplate <typename T> ostream &operator<<(ostream &os,\
    \ set<T> &set_var) {\r\n    os << \"{\";\r\n    for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) {\r\n        os << *itr;\r\n        ++itr;\r\n\
    \        if (itr != set_var.end())\r\n            os << \", \";\r\n        itr--;\r\
    \n    }\r\n    os << \"}\";\r\n    return os;\r\n}\n#line 2 \"Graph/scc.hpp\"\n\
    \r\nstruct SCC{\r\n    int n,m,cur;\r\n    vector<vector<int>> g;\r\n    vector<int>\
    \ low,ord,id;\r\n    SCC(int _n=0):n(_n),m(0),cur(0),g(_n),low(_n),ord(_n,-1),id(_n){}\r\
    \n    void resize(int _n){\r\n        n=_n;\r\n        g.resize(n);\r\n      \
    \  low.resize(n);\r\n        ord.resize(n,-1);\r\n        id.resize(n);\r\n  \
    \  }\r\n    void add_edge(int u,int v){g[u].emplace_back(v);}\r\n    void dfs(int\
    \ v,vector<int>& used){\r\n        ord[v]=low[v]=cur++;\r\n        used.emplace_back(v);\r\
    \n        for(auto& nxt:g[v]){\r\n            if(ord[nxt]==-1){\r\n          \
    \      dfs(nxt,used); chmin(low[v],low[nxt]);\r\n            }\r\n           \
    \ else{\r\n                chmin(low[v],ord[nxt]);\r\n            }\r\n      \
    \  }\r\n        if(ord[v]==low[v]){\r\n            while(1){\r\n             \
    \   int add=used.back(); used.pop_back();\r\n                ord[add]=n; id[add]=m;\r\
    \n                if(v==add)break;\r\n            }\r\n            m++;\r\n  \
    \      }\r\n    }\r\n    void run(){\r\n        vector<int> used;\r\n        rep(v,0,n)if(ord[v]==-1)dfs(v,used);\r\
    \n        for(auto& x:id)x=m-1-x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Strongly\
    \ Connected Components\r\n */\n#line 5 \"Verify/LC_scc.test.cpp\"\n\r\nint main(){\r\
    \n    int n,m;\r\n    cin>>n>>m;\r\n    SCC scc(n);\r\n    rep(i,0,m){\r\n   \
    \     int x,y;\r\n        cin>>x>>y;\r\n        scc.add_edge(x,y);\r\n    }\r\n\
    \    scc.run();\r\n    vector g(scc.m,vector<int>());\r\n    rep(i,0,n)g[scc.id[i]].push_back(i);\r\
    \n    cout<<g.size()<<'\\n';\r\n    rep(i,0,g.size()){\r\n        cout<<g[i].size()<<'\
    \ ';\r\n        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\\\
    n':' ');\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include \"\
    Template/template.hpp\"\r\n#include \"Graph/scc.hpp\"\r\n\r\nint main(){\r\n \
    \   int n,m;\r\n    cin>>n>>m;\r\n    SCC scc(n);\r\n    rep(i,0,m){\r\n     \
    \   int x,y;\r\n        cin>>x>>y;\r\n        scc.add_edge(x,y);\r\n    }\r\n\
    \    scc.run();\r\n    vector g(scc.m,vector<int>());\r\n    rep(i,0,n)g[scc.id[i]].push_back(i);\r\
    \n    cout<<g.size()<<'\\n';\r\n    rep(i,0,g.size()){\r\n        cout<<g[i].size()<<'\
    \ ';\r\n        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\\\
    n':' ');\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/scc.hpp
  isVerificationFile: true
  path: Verify/LC_scc.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 02:46:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_scc.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_scc.test.cpp
- /verify/Verify/LC_scc.test.cpp.html
title: Verify/LC_scc.test.cpp
---
